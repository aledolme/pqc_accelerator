// Generated register defines for pdm2pcm

// Copyright information found in source file:
// Copyright 2022 EPFL

// Licensing information found in source file:
// 
// SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1

#ifndef _PDM2PCM_REG_DEFS_
#define _PDM2PCM_REG_DEFS_

#ifdef __cplusplus
extern "C" {
#endif
// Register width
#define PDM2PCM_PARAM_REG_WIDTH 32

// Control register
#define PDM2PCM_CLKDIVIDX_REG_OFFSET 0x0
#define PDM2PCM_CLKDIVIDX_COUNT_MASK 0xffff
#define PDM2PCM_CLKDIVIDX_COUNT_OFFSET 0
#define PDM2PCM_CLKDIVIDX_COUNT_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_CLKDIVIDX_COUNT_MASK, .index = PDM2PCM_CLKDIVIDX_COUNT_OFFSET })

// Control register
#define PDM2PCM_CONTROL_REG_OFFSET 0x4
#define PDM2PCM_CONTROL_ENABL_BIT 0
#define PDM2PCM_CONTROL_CLEAR_BIT 1

// Status register
#define PDM2PCM_STATUS_REG_OFFSET 0x8
#define PDM2PCM_STATUS_EMPTY_BIT 0
#define PDM2PCM_STATUS_REACH_BIT 1
#define PDM2PCM_STATUS_FULLL_BIT 2

// Number of signal taps stored into the FIFO to assert the FILLD bit in the
// STATUS register.
#define PDM2PCM_REACHCOUNT_REG_OFFSET 0xc
#define PDM2PCM_REACHCOUNT_COUNT_MASK 0x3f
#define PDM2PCM_REACHCOUNT_COUNT_OFFSET 0
#define PDM2PCM_REACHCOUNT_COUNT_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_REACHCOUNT_COUNT_MASK, .index = PDM2PCM_REACHCOUNT_COUNT_OFFSET })

// Samples count after which to decimate in the CIC filter.
#define PDM2PCM_DECIMCIC_REG_OFFSET 0x10
#define PDM2PCM_DECIMCIC_COUNT_MASK 0xf
#define PDM2PCM_DECIMCIC_COUNT_OFFSET 0
#define PDM2PCM_DECIMCIC_COUNT_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_DECIMCIC_COUNT_MASK, .index = PDM2PCM_DECIMCIC_COUNT_OFFSET })

// Samples count after which to decimate after the first halfband filter.
#define PDM2PCM_DECIMHB1_REG_OFFSET 0x14
#define PDM2PCM_DECIMHB1_COUNT_MASK 0x1f
#define PDM2PCM_DECIMHB1_COUNT_OFFSET 0
#define PDM2PCM_DECIMHB1_COUNT_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_DECIMHB1_COUNT_MASK, .index = PDM2PCM_DECIMHB1_COUNT_OFFSET })

// Samples count after which to decimate after the second halfband filter.
#define PDM2PCM_DECIMHB2_REG_OFFSET 0x18
#define PDM2PCM_DECIMHB2_COUNT_MASK 0x3f
#define PDM2PCM_DECIMHB2_COUNT_OFFSET 0
#define PDM2PCM_DECIMHB2_COUNT_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_DECIMHB2_COUNT_MASK, .index = PDM2PCM_DECIMHB2_COUNT_OFFSET })

// Filter HB1 coefficient 0
#define PDM2PCM_HB1COEF00_REG_OFFSET 0x1c
#define PDM2PCM_HB1COEF00_COEFF_MASK 0x3ffff
#define PDM2PCM_HB1COEF00_COEFF_OFFSET 0
#define PDM2PCM_HB1COEF00_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_HB1COEF00_COEFF_MASK, .index = PDM2PCM_HB1COEF00_COEFF_OFFSET })

// Filter HB1 coefficient 1
#define PDM2PCM_HB1COEF01_REG_OFFSET 0x20
#define PDM2PCM_HB1COEF01_COEFF_MASK 0x3ffff
#define PDM2PCM_HB1COEF01_COEFF_OFFSET 0
#define PDM2PCM_HB1COEF01_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_HB1COEF01_COEFF_MASK, .index = PDM2PCM_HB1COEF01_COEFF_OFFSET })

// Filter HB1 coefficient 2
#define PDM2PCM_HB1COEF02_REG_OFFSET 0x24
#define PDM2PCM_HB1COEF02_COEFF_MASK 0x3ffff
#define PDM2PCM_HB1COEF02_COEFF_OFFSET 0
#define PDM2PCM_HB1COEF02_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_HB1COEF02_COEFF_MASK, .index = PDM2PCM_HB1COEF02_COEFF_OFFSET })

// Filter HB1 coefficient 3
#define PDM2PCM_HB1COEF03_REG_OFFSET 0x28
#define PDM2PCM_HB1COEF03_COEFF_MASK 0x3ffff
#define PDM2PCM_HB1COEF03_COEFF_OFFSET 0
#define PDM2PCM_HB1COEF03_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_HB1COEF03_COEFF_MASK, .index = PDM2PCM_HB1COEF03_COEFF_OFFSET })

// Filter HB2 coefficient 0
#define PDM2PCM_HB2COEF00_REG_OFFSET 0x2c
#define PDM2PCM_HB2COEF00_COEFF_MASK 0x3ffff
#define PDM2PCM_HB2COEF00_COEFF_OFFSET 0
#define PDM2PCM_HB2COEF00_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_HB2COEF00_COEFF_MASK, .index = PDM2PCM_HB2COEF00_COEFF_OFFSET })

// Filter HB2 coefficient 1
#define PDM2PCM_HB2COEF01_REG_OFFSET 0x30
#define PDM2PCM_HB2COEF01_COEFF_MASK 0x3ffff
#define PDM2PCM_HB2COEF01_COEFF_OFFSET 0
#define PDM2PCM_HB2COEF01_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_HB2COEF01_COEFF_MASK, .index = PDM2PCM_HB2COEF01_COEFF_OFFSET })

// Filter HB2 coefficient 2
#define PDM2PCM_HB2COEF02_REG_OFFSET 0x34
#define PDM2PCM_HB2COEF02_COEFF_MASK 0x3ffff
#define PDM2PCM_HB2COEF02_COEFF_OFFSET 0
#define PDM2PCM_HB2COEF02_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_HB2COEF02_COEFF_MASK, .index = PDM2PCM_HB2COEF02_COEFF_OFFSET })

// Filter HB2 coefficient 3
#define PDM2PCM_HB2COEF03_REG_OFFSET 0x38
#define PDM2PCM_HB2COEF03_COEFF_MASK 0x3ffff
#define PDM2PCM_HB2COEF03_COEFF_OFFSET 0
#define PDM2PCM_HB2COEF03_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_HB2COEF03_COEFF_MASK, .index = PDM2PCM_HB2COEF03_COEFF_OFFSET })

// Filter HB2 coefficient 4
#define PDM2PCM_HB2COEF04_REG_OFFSET 0x3c
#define PDM2PCM_HB2COEF04_COEFF_MASK 0x3ffff
#define PDM2PCM_HB2COEF04_COEFF_OFFSET 0
#define PDM2PCM_HB2COEF04_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_HB2COEF04_COEFF_MASK, .index = PDM2PCM_HB2COEF04_COEFF_OFFSET })

// Filter HB2 coefficient 5
#define PDM2PCM_HB2COEF05_REG_OFFSET 0x40
#define PDM2PCM_HB2COEF05_COEFF_MASK 0x3ffff
#define PDM2PCM_HB2COEF05_COEFF_OFFSET 0
#define PDM2PCM_HB2COEF05_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_HB2COEF05_COEFF_MASK, .index = PDM2PCM_HB2COEF05_COEFF_OFFSET })

// Filter HB2 coefficient 6
#define PDM2PCM_HB2COEF06_REG_OFFSET 0x44
#define PDM2PCM_HB2COEF06_COEFF_MASK 0x3ffff
#define PDM2PCM_HB2COEF06_COEFF_OFFSET 0
#define PDM2PCM_HB2COEF06_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_HB2COEF06_COEFF_MASK, .index = PDM2PCM_HB2COEF06_COEFF_OFFSET })

// Filter FIR coefficient 0
#define PDM2PCM_FIRCOEF00_REG_OFFSET 0x48
#define PDM2PCM_FIRCOEF00_COEFF_MASK 0x3ffff
#define PDM2PCM_FIRCOEF00_COEFF_OFFSET 0
#define PDM2PCM_FIRCOEF00_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_FIRCOEF00_COEFF_MASK, .index = PDM2PCM_FIRCOEF00_COEFF_OFFSET })

// Filter FIR coefficient 1
#define PDM2PCM_FIRCOEF01_REG_OFFSET 0x4c
#define PDM2PCM_FIRCOEF01_COEFF_MASK 0x3ffff
#define PDM2PCM_FIRCOEF01_COEFF_OFFSET 0
#define PDM2PCM_FIRCOEF01_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_FIRCOEF01_COEFF_MASK, .index = PDM2PCM_FIRCOEF01_COEFF_OFFSET })

// Filter FIR coefficient 2
#define PDM2PCM_FIRCOEF02_REG_OFFSET 0x50
#define PDM2PCM_FIRCOEF02_COEFF_MASK 0x3ffff
#define PDM2PCM_FIRCOEF02_COEFF_OFFSET 0
#define PDM2PCM_FIRCOEF02_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_FIRCOEF02_COEFF_MASK, .index = PDM2PCM_FIRCOEF02_COEFF_OFFSET })

// Filter FIR coefficient 3
#define PDM2PCM_FIRCOEF03_REG_OFFSET 0x54
#define PDM2PCM_FIRCOEF03_COEFF_MASK 0x3ffff
#define PDM2PCM_FIRCOEF03_COEFF_OFFSET 0
#define PDM2PCM_FIRCOEF03_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_FIRCOEF03_COEFF_MASK, .index = PDM2PCM_FIRCOEF03_COEFF_OFFSET })

// Filter FIR coefficient 4
#define PDM2PCM_FIRCOEF04_REG_OFFSET 0x58
#define PDM2PCM_FIRCOEF04_COEFF_MASK 0x3ffff
#define PDM2PCM_FIRCOEF04_COEFF_OFFSET 0
#define PDM2PCM_FIRCOEF04_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_FIRCOEF04_COEFF_MASK, .index = PDM2PCM_FIRCOEF04_COEFF_OFFSET })

// Filter FIR coefficient 5
#define PDM2PCM_FIRCOEF05_REG_OFFSET 0x5c
#define PDM2PCM_FIRCOEF05_COEFF_MASK 0x3ffff
#define PDM2PCM_FIRCOEF05_COEFF_OFFSET 0
#define PDM2PCM_FIRCOEF05_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_FIRCOEF05_COEFF_MASK, .index = PDM2PCM_FIRCOEF05_COEFF_OFFSET })

// Filter FIR coefficient 6
#define PDM2PCM_FIRCOEF06_REG_OFFSET 0x60
#define PDM2PCM_FIRCOEF06_COEFF_MASK 0x3ffff
#define PDM2PCM_FIRCOEF06_COEFF_OFFSET 0
#define PDM2PCM_FIRCOEF06_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_FIRCOEF06_COEFF_MASK, .index = PDM2PCM_FIRCOEF06_COEFF_OFFSET })

// Filter FIR coefficient 7
#define PDM2PCM_FIRCOEF07_REG_OFFSET 0x64
#define PDM2PCM_FIRCOEF07_COEFF_MASK 0x3ffff
#define PDM2PCM_FIRCOEF07_COEFF_OFFSET 0
#define PDM2PCM_FIRCOEF07_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_FIRCOEF07_COEFF_MASK, .index = PDM2PCM_FIRCOEF07_COEFF_OFFSET })

// Filter FIR coefficient 8
#define PDM2PCM_FIRCOEF08_REG_OFFSET 0x68
#define PDM2PCM_FIRCOEF08_COEFF_MASK 0x3ffff
#define PDM2PCM_FIRCOEF08_COEFF_OFFSET 0
#define PDM2PCM_FIRCOEF08_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_FIRCOEF08_COEFF_MASK, .index = PDM2PCM_FIRCOEF08_COEFF_OFFSET })

// Filter FIR coefficient 9
#define PDM2PCM_FIRCOEF09_REG_OFFSET 0x6c
#define PDM2PCM_FIRCOEF09_COEFF_MASK 0x3ffff
#define PDM2PCM_FIRCOEF09_COEFF_OFFSET 0
#define PDM2PCM_FIRCOEF09_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_FIRCOEF09_COEFF_MASK, .index = PDM2PCM_FIRCOEF09_COEFF_OFFSET })

// Filter FIR coefficient 10
#define PDM2PCM_FIRCOEF10_REG_OFFSET 0x70
#define PDM2PCM_FIRCOEF10_COEFF_MASK 0x3ffff
#define PDM2PCM_FIRCOEF10_COEFF_OFFSET 0
#define PDM2PCM_FIRCOEF10_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_FIRCOEF10_COEFF_MASK, .index = PDM2PCM_FIRCOEF10_COEFF_OFFSET })

// Filter FIR coefficient 11
#define PDM2PCM_FIRCOEF11_REG_OFFSET 0x74
#define PDM2PCM_FIRCOEF11_COEFF_MASK 0x3ffff
#define PDM2PCM_FIRCOEF11_COEFF_OFFSET 0
#define PDM2PCM_FIRCOEF11_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_FIRCOEF11_COEFF_MASK, .index = PDM2PCM_FIRCOEF11_COEFF_OFFSET })

// Filter FIR coefficient 12
#define PDM2PCM_FIRCOEF12_REG_OFFSET 0x78
#define PDM2PCM_FIRCOEF12_COEFF_MASK 0x3ffff
#define PDM2PCM_FIRCOEF12_COEFF_OFFSET 0
#define PDM2PCM_FIRCOEF12_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_FIRCOEF12_COEFF_MASK, .index = PDM2PCM_FIRCOEF12_COEFF_OFFSET })

// Filter FIR coefficient 13
#define PDM2PCM_FIRCOEF13_REG_OFFSET 0x7c
#define PDM2PCM_FIRCOEF13_COEFF_MASK 0x3ffff
#define PDM2PCM_FIRCOEF13_COEFF_OFFSET 0
#define PDM2PCM_FIRCOEF13_COEFF_FIELD \
  ((bitfield_field32_t) { .mask = PDM2PCM_FIRCOEF13_COEFF_MASK, .index = PDM2PCM_FIRCOEF13_COEFF_OFFSET })

// Memory area: PCM Receive data
#define PDM2PCM_RXDATA_REG_OFFSET 0x80
#define PDM2PCM_RXDATA_SIZE_WORDS 1
#define PDM2PCM_RXDATA_SIZE_BYTES 4
#ifdef __cplusplus
}  // extern "C"
#endif
#endif  // _PDM2PCM_REG_DEFS_
// End generated register defines for pdm2pcm