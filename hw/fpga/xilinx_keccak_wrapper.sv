
module xilinx_keccak_x_heep_top_wrapper
  import obi_pkg::*;
  import reg_pkg::*;
#( 
   parameter COREV_PULP           = 0,
    parameter FPU                  = 0,
    parameter ZFINX                = 0,
    parameter X_EXT                = 0,  // eXtension interface in cv32e40x
    parameter CLK_LED_COUNT_LENGTH = 27
) (

    inout logic        clk_i,
    inout logic        rst_i,

    //visibility signals
    output logic       rst_led,
    output logic       clk_led,
    output logic       clk_out,

    inout logic        boot_select_i,
    inout logic        execute_from_flash_i,

    inout logic        jtag_tck_i,
    inout logic        jtag_tms_i,
    inout logic        jtag_trst_ni,
    inout logic        jtag_tdi_i,
    inout logic        jtag_tdo_o,

    inout logic        uart_rx_i,
    inout logic        uart_tx_o,

    inout logic [19:0] gpio_io,

    output logic       exit_value_o,
    inout logic        exit_valid_o,

    inout logic [3:0]  spi_flash_sd_io,
    inout logic        spi_flash_csb_o,
    inout logic        spi_flash_sck_o,

    inout logic [3:0]  spi_sd_io,
    inout logic        spi_csb_o,
    inout logic        spi_sck_o,

    inout logic        spi2_sd_0_io,
    inout logic        spi2_sd_1_io,
    inout logic        spi2_sd_2_io,
    inout logic        spi2_sd_3_io,
    inout logic [1:0]  spi2_csb_o,
    inout logic        spi2_sck_o,

   
    inout logic        i2c_scl_io,
    inout logic        i2c_sda_io,
   
    inout logic        pdm2pcm_clk_io,
    inout logic        pdm2pcm_pdm_io,

    inout logic        i2s_sck_io,
    inout logic        i2s_ws_io,
    inout logic        i2s_sd_io

);

  wire                               clk_gen;
  logic [                      31:0] exit_value;
  wire                               rst_n;
  logic [CLK_LED_COUNT_LENGTH - 1:0] clk_count;
  logic [19:0] 		     gpio;
		     
  // low active reset
  assign rst_n   = !rst_i;

  // reset LED for debugging
  assign rst_led = rst_n;

  // counter to blink an LED
  assign clk_led = clk_count[CLK_LED_COUNT_LENGTH-1];

  always_ff @(posedge clk_gen or negedge rst_n) begin : clk_count_process
    if (!rst_n) begin
      clk_count <= '0;
    end else begin
      clk_count <= clk_count + 1;
    end
  end

  // clock output for debugging
  assign clk_out = clk_gen;

  xilinx_clk_wizard_wrapper xilinx_clk_wizard_wrapper_i (
      .clk_125MHz(clk_i),
      .clk_out1_0(clk_gen)
  );

  // gpio assign
   assign gpio[29:0] = gpio_io;
   assign gpio[31] = i2c_scl_io;
   assign gpio[30] = i2c_sda_io;
     
  keccak_x_heep_top  #(
      .COREV_PULP(COREV_PULP),
      .FPU(FPU),
      .ZFINX(ZFINX)
  ) keccak_x_heep_top_i (
      .clk_i(clk_gen),
      .rst_ni(rst_n),
      .boot_select_i(boot_select_i),
      .execute_from_flash_i(execute_from_flash_i),
      .jtag_tck_i(jtag_tck_i),
      .jtag_tms_i(jtag_tms_i),
      .jtag_trst_ni(jtag_trst_ni),
      .jtag_tdi_i(jtag_tdi_i),
      .jtag_tdo_o(jtag_tdo_o),
      .uart_rx_i(uart_rx_i),
      .uart_tx_o(uart_tx_o),
      .gpio_io(gpio),
      .spi_flash_sd_io(spi_flash_sd_io),
      .spi_flash_csb_io(spi_flash_csb_o),
      .spi_flash_sck_io(spi_flash_sck_o),
      .spi_sd_io(spi_sd_io),
      .spi_csb_io(spi_csb_o),
      .spi_sck_io(spi_sck_o),
      .i2c_scl_io,
      .i2c_sda_io,			 
      .spi2_sd_0_io(spi2_sd_0_io),
      .spi2_sd_1_io(spi2_sd_1_io),
      .spi2_sd_2_io(spi2_sd_2_io),
      .spi2_sd_3_io(spi2_sd_3_io),
      .spi2_cs_0_io(spi2_csb_o[0]),
      .spi2_cs_1_io(spi2_csb_o[1]),
      .spi2_sck_io(spi2_sck_o),
      .pdm2pcm_clk_io,
      .pdm2pcm_pdm_io,
      .i2s_sck_io(i2s_sck_io),
      .i2s_ws_io(i2s_ws_io),
      .i2s_sd_io(i2s_sd_io),
      .external_subsystem_powergate_switch_o(),
      .external_subsystem_powergate_switch_ack_i(),
      .external_subsystem_powergate_iso_o(),
      //.external_subsystem_rst_no(),
      .exit_value_o(exit_value),
      .exit_valid_o(exit_valid_o)
  );

  assign exit_value_o = exit_value[0];


endmodule
