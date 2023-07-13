#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "keccak_x_heep.h"
#include "core_v_mini_mcu.h"
#include "keccak_driver.h"
#include "keccak_ctrl_auto.h"
#include "keccak_data_auto.h"

#include "stats.h"

// To manage interrupt
#include "csr.h"
#include "rv_plic.h"
#include "rv_plic_regs.h"
#include "rv_plic_structs.h"
#include "hart.h"

// To manage DMA
#include "dma.h"

#define KECCAK_BUSY 0
#define DATA_SIZE 50

// Interrupt controller variables
plic_result_t plic_res;

// Own defined ext interrupt handler
void handler_irq_ext(uint32_t id){
  printf("D\n");
}

  
void KeccakF1600_StatePermute(uint32_t Din[50], uint32_t Dout[50])
{
  uint32_t volatile *Din_reg_start = (uint32_t*)KECCAK_DIN_START_ADDR;
  uint32_t volatile *ctrl_reg = (uint32_t*)KECCAK_CTRL_START_ADDR;
  uint32_t volatile *status_reg = (uint32_t*)KECCAK_STATUS_START_ADDR;
  uint32_t current_status;
  uint32_t volatile *Dout_reg_start = (uint32_t*)KECCAK_DOUT_START_ADDR;
  
  // Performance regs variables
  unsigned int instr, cycles, ldstall, jrstall, imstall;
  
  // DMA variables 
  static uint32_t Din_4B[DATA_SIZE] __attribute__ ((aligned (4))) ;
  //static uint32_t copied_data_4B[DATA_SIZE] __attribute__ ((aligned (4))) = { 0 };
  static uint32_t Dout_4B[DATA_SIZE] __attribute__ ((aligned (4))) = { 0 };

  uint32_t* ext_addr_4B_PTR = (uint32_t*)KECCAK_DIN_START_ADDR;
  uint32_t* copied_data_4B = (uint32_t*)KECCAK_DIN_START_ADDR;
  uint32_t* ext_copied_data_4B;
  int32_t errors = 0;

  for (int i=0; i<DATA_SIZE; i++){
    Din_4B[i]=Din[i];
   } 

  // In ext_copied_data_4B stored the values copied in DMA transaction
  ext_copied_data_4B = &ext_addr_4B_PTR[DATA_SIZE+1];
 
//La prima transizione DMA è par passare Din nei registri interni di Keccak, la seconda sarò per leggerli


  // Keccak accelerator send interrupt on ext_intr line 0
  printf("Interrupt id : %d\n", EXT_INTR_0);
  printf("Init the PLIC...");
  plic_res = plic_Init();

  if (plic_res != kPlicOk) {
      return -1;
  }
  
  // Set Keccak priority to 1 (target threshold is by default 0) to trigger an interrupt to the target (the processor)
    plic_res = plic_irq_set_priority(EXT_INTR_0, 1);
    if (plic_res == kPlicOk) {
        printf("Success\n");
    } else {
        printf("fail\n;");
    }

  // Enable the interrupt in reg 0 
  printf("Enable Keccak interrupt...");
  plic_res = plic_irq_set_enabled(EXT_INTR_0, kPlicToggleEnabled);
  if (plic_res == kPlicOk) {
      printf("Success\n");
  } else {
      printf("Fail\n;");
  }

  // Enable interrupt on processor side
  // Enable global interrupt for machine-level interrupts
  CSR_SET_BITS(CSR_REG_MSTATUS, 0x8);
  // Set mie.MEIE bit to one to enable machine-level external interrupts
  const uint32_t mask = 1 << 11;//IRQ_EXT_ENABLE_OFFSET;
  CSR_SET_BITS(CSR_REG_MIE, mask);

  // Starting the performance counter
  printf("!\n");
  CSR_WRITE(CSR_REG_MCYCLE, 0);

  printf("!\n");   

  // The DMA is initialized (i.e. Any current transaction is cleaned.)
  dma_init(NULL);
    
  dma_config_flags_t res;

  printf("tgt_stc ptr: %04x, copied_data_ptr : %04x\n", Din_4B, copied_data_4B);
  //
  

  // First DMA transaction consist on loading Din in Keccak register file
    
  dma_target_t tgt_src = {
                              .ptr        = Din_4B,
                              .inc_du     = 1,
                              .size_du    = DATA_SIZE,
                              .trig       = DMA_TRIG_MEMORY,
                              .type       = DMA_DATA_TYPE_WORD,
                              };
  dma_target_t tgt_dst = {
                              .ptr        = copied_data_4B,
                              .inc_du     = 1,
                              .size_du    = DATA_SIZE,
                              .trig       = DMA_TRIG_MEMORY,
                              };

  dma_target_t tgt_addr = {
                              .ptr        = ext_addr_4B_PTR,
                              .inc_du     = 1,
                              .size_du    = DATA_SIZE,
                              .trig       = DMA_TRIG_MEMORY,
                              };

  dma_trans_t trans = {
                              .src        = &tgt_src,
                              .dst        = &tgt_dst,
                              .src_addr   = &tgt_addr,
                              .mode       = DMA_TRANS_MODE_SINGLE,
                              .win_du     = 0,
                              .end        = DMA_TRANS_END_INTR,
                              };
  // Create a target pointing at the buffer to be copied. Whole WORDs, no skippings, in memory, no environment.  

  printf("\n\n=====================================\n\n");
  printf("    TESTING ADDRESS MODE IN KECCAK  ");
  printf("\n\n=====================================\n\n");

  res = dma_validate_transaction( &trans, DMA_ENABLE_REALIGN, DMA_PERFORM_CHECKS_INTEGRITY );
  printf("tran: %u \t%s\n", res, res == DMA_CONFIG_OK ?  "Ok!" : "Error!");
  res = dma_load_transaction(&trans);
  printf("load: %u \t%s\n", res, res == DMA_CONFIG_OK ?  "Ok!" : "Error!");
  res = dma_launch(&trans);
  printf("laun: %u \t%s\n", res, res == DMA_CONFIG_OK ?  "Ok!" : "Error!");

  while( ! dma_is_ready()) {
      // disable_interrupts
      // this does not prevent waking up the core as this is controlled by the MIP register
      CSR_SET_BITS(CSR_REG_MSTATUS, 0x0);
      if ( dma_is_ready() == 0 ) {
          wait_for_interrupt();
          //from here we wake up even if we did not jump to the ISR
      }
      CSR_SET_BITS(CSR_REG_MSTATUS, 0x8);
  }


  printf(">> Finished transaction. \n\r");

  //for(uint32_t i = 0; i < trans.size_b >> 2; i++ ) {
  //    if ( copied_data_4B[i] != Din_4B[i] ) {
  //        printf("ERROR [%d]: %04x != %04x\n\r", i, ext_copied_data_4B[i], Din_4B[i]);
  //        errors++;
  //    }
  //}
  
  //if (errors == 0) {
  //    printf("DMA address mode in external memory success.\n\r");
  //} else {
  //    printf("DMA address mode in external memory failure: %d errors out of %d bytes checked\n\r", errors, trans.size_b );
  //    return EXIT_FAILURE;
  //}

  //for (int i = 0; i<50; i++)
  //{
  //   Din_reg_start[i] = Din[i];
  //}
  
  //printf("!\n");
  asm volatile ("": : : "memory");
  *ctrl_reg = 1 << KECCAK_CTRL_CTRL_START_BIT;
  asm volatile ("": : : "memory");
  *ctrl_reg = 0 << KECCAK_CTRL_CTRL_START_BIT;
  printf("!\n");
  // Busy waiting till the Keccak has finished permutation
  //do {
  //  printf(".\n");
  //	  current_status = (*status_reg)&(1<<KECCAK_STATUS_STATUS_BIT);
  //} while ( current_status == KECCAK_BUSY);

  // Wait till keccak is done
  while(plic_intr_flag==0) {
      wait_for_interrupt();
  }
  printf("Keccak finished...\r\n");
  printf("!\n");
  for (volatile int i = 0; i<DATA_SIZE; i++){
     Dout[i] = Dout_reg_start[i];	
  }
  printf("!\n");
  // stop the HW counter used for monitoring
  CSR_READ(CSR_REG_MCYCLE, &cycles);
  printf("Number of clock cycles : %d\n", cycles);
  //printf("Number of instructions : %d\nNumber of clock cycles: %d\nCPI: %f%f\n",instr_cnt, cycles_cnt, (float) instr_cnt/cycles_cnt);
  
}



