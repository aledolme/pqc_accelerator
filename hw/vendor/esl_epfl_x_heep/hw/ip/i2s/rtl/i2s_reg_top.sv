// Copyright lowRISC contributors.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
//
// Register Top module auto-generated by `reggen`


`include "common_cells/assertions.svh"

module i2s_reg_top #(
    parameter type reg_req_t = logic,
    parameter type reg_rsp_t = logic,
    parameter int AW = 5
) (
    input logic clk_i,
    input logic rst_ni,
    input reg_req_t reg_req_i,
    output reg_rsp_t reg_rsp_o,
    // To HW
    output i2s_reg_pkg::i2s_reg2hw_t reg2hw,  // Write
    input i2s_reg_pkg::i2s_hw2reg_t hw2reg,  // Read


    // Config
    input devmode_i  // If 1, explicit error return for unmapped register access
);

  import i2s_reg_pkg::*;

  localparam int DW = 32;
  localparam int DBW = DW / 8;  // Byte Width

  // register signals
  logic           reg_we;
  logic           reg_re;
  logic [ AW-1:0] reg_addr;
  logic [ DW-1:0] reg_wdata;
  logic [DBW-1:0] reg_be;
  logic [ DW-1:0] reg_rdata;
  logic           reg_error;

  logic addrmiss, wr_err;

  logic [DW-1:0] reg_rdata_next;

  // Below register interface can be changed
  reg_req_t reg_intf_req;
  reg_rsp_t reg_intf_rsp;


  assign reg_intf_req = reg_req_i;
  assign reg_rsp_o = reg_intf_rsp;


  assign reg_we = reg_intf_req.valid & reg_intf_req.write;
  assign reg_re = reg_intf_req.valid & ~reg_intf_req.write;
  assign reg_addr = reg_intf_req.addr;
  assign reg_wdata = reg_intf_req.wdata;
  assign reg_be = reg_intf_req.wstrb;
  assign reg_intf_rsp.rdata = reg_rdata;
  assign reg_intf_rsp.error = reg_error;
  assign reg_intf_rsp.ready = 1'b1;

  assign reg_rdata = reg_rdata_next;
  assign reg_error = (devmode_i & addrmiss) | wr_err;


  // Define SW related signals
  // Format: <reg>_<field>_{wd|we|qs}
  //        or <reg>_{wd|we|qs} if field == 1 or 0
  logic control_en_qs;
  logic control_en_wd;
  logic control_en_we;
  logic control_en_ws_qs;
  logic control_en_ws_wd;
  logic control_en_ws_we;
  logic [1:0] control_en_rx_qs;
  logic [1:0] control_en_rx_wd;
  logic control_en_rx_we;
  logic control_intr_en_qs;
  logic control_intr_en_wd;
  logic control_intr_en_we;
  logic control_en_watermark_qs;
  logic control_en_watermark_wd;
  logic control_en_watermark_we;
  logic control_reset_watermark_qs;
  logic control_reset_watermark_wd;
  logic control_reset_watermark_we;
  logic control_en_io_qs;
  logic control_en_io_wd;
  logic control_en_io_we;
  logic [1:0] control_data_width_qs;
  logic [1:0] control_data_width_wd;
  logic control_data_width_we;
  logic control_rx_start_channel_qs;
  logic control_rx_start_channel_wd;
  logic control_rx_start_channel_we;
  logic control_reset_rx_overflow_qs;
  logic control_reset_rx_overflow_wd;
  logic control_reset_rx_overflow_we;
  logic status_running_qs;
  logic status_running_re;
  logic status_rx_data_ready_qs;
  logic status_rx_data_ready_re;
  logic status_rx_overflow_qs;
  logic status_rx_overflow_re;
  logic [15:0] clkdividx_qs;
  logic [15:0] clkdividx_wd;
  logic clkdividx_we;
  logic [31:0] rxdata_qs;
  logic rxdata_re;
  logic [15:0] watermark_qs;
  logic [15:0] watermark_wd;
  logic watermark_we;
  logic [15:0] waterlevel_qs;
  logic waterlevel_re;

  // Register instances
  // R[control]: V(False)

  //   F[en]: 0:0
  prim_subreg #(
      .DW      (1),
      .SWACCESS("RW"),
      .RESVAL  (1'h0)
  ) u_control_en (
      .clk_i (clk_i),
      .rst_ni(rst_ni),

      // from register interface
      .we(control_en_we),
      .wd(control_en_wd),

      // from internal hardware
      .de(1'b0),
      .d ('0),

      // to internal hardware
      .qe(),
      .q (reg2hw.control.en.q),

      // to register interface (read)
      .qs(control_en_qs)
  );


  //   F[en_ws]: 1:1
  prim_subreg #(
      .DW      (1),
      .SWACCESS("RW"),
      .RESVAL  (1'h0)
  ) u_control_en_ws (
      .clk_i (clk_i),
      .rst_ni(rst_ni),

      // from register interface
      .we(control_en_ws_we),
      .wd(control_en_ws_wd),

      // from internal hardware
      .de(1'b0),
      .d ('0),

      // to internal hardware
      .qe(),
      .q (reg2hw.control.en_ws.q),

      // to register interface (read)
      .qs(control_en_ws_qs)
  );


  //   F[en_rx]: 3:2
  prim_subreg #(
      .DW      (2),
      .SWACCESS("RW"),
      .RESVAL  (2'h0)
  ) u_control_en_rx (
      .clk_i (clk_i),
      .rst_ni(rst_ni),

      // from register interface
      .we(control_en_rx_we),
      .wd(control_en_rx_wd),

      // from internal hardware
      .de(1'b0),
      .d ('0),

      // to internal hardware
      .qe(),
      .q (reg2hw.control.en_rx.q),

      // to register interface (read)
      .qs(control_en_rx_qs)
  );


  //   F[intr_en]: 4:4
  prim_subreg #(
      .DW      (1),
      .SWACCESS("RW"),
      .RESVAL  (1'h0)
  ) u_control_intr_en (
      .clk_i (clk_i),
      .rst_ni(rst_ni),

      // from register interface
      .we(control_intr_en_we),
      .wd(control_intr_en_wd),

      // from internal hardware
      .de(1'b0),
      .d ('0),

      // to internal hardware
      .qe(),
      .q (reg2hw.control.intr_en.q),

      // to register interface (read)
      .qs(control_intr_en_qs)
  );


  //   F[en_watermark]: 5:5
  prim_subreg #(
      .DW      (1),
      .SWACCESS("RW"),
      .RESVAL  (1'h0)
  ) u_control_en_watermark (
      .clk_i (clk_i),
      .rst_ni(rst_ni),

      // from register interface
      .we(control_en_watermark_we),
      .wd(control_en_watermark_wd),

      // from internal hardware
      .de(1'b0),
      .d ('0),

      // to internal hardware
      .qe(),
      .q (reg2hw.control.en_watermark.q),

      // to register interface (read)
      .qs(control_en_watermark_qs)
  );


  //   F[reset_watermark]: 6:6
  prim_subreg #(
      .DW      (1),
      .SWACCESS("RW"),
      .RESVAL  (1'h0)
  ) u_control_reset_watermark (
      .clk_i (clk_i),
      .rst_ni(rst_ni),

      // from register interface
      .we(control_reset_watermark_we),
      .wd(control_reset_watermark_wd),

      // from internal hardware
      .de(hw2reg.control.reset_watermark.de),
      .d (hw2reg.control.reset_watermark.d),

      // to internal hardware
      .qe(),
      .q (reg2hw.control.reset_watermark.q),

      // to register interface (read)
      .qs(control_reset_watermark_qs)
  );


  //   F[en_io]: 7:7
  prim_subreg #(
      .DW      (1),
      .SWACCESS("RW"),
      .RESVAL  (1'h0)
  ) u_control_en_io (
      .clk_i (clk_i),
      .rst_ni(rst_ni),

      // from register interface
      .we(control_en_io_we),
      .wd(control_en_io_wd),

      // from internal hardware
      .de(1'b0),
      .d ('0),

      // to internal hardware
      .qe(),
      .q (reg2hw.control.en_io.q),

      // to register interface (read)
      .qs(control_en_io_qs)
  );


  //   F[data_width]: 9:8
  prim_subreg #(
      .DW      (2),
      .SWACCESS("RW"),
      .RESVAL  (2'h3)
  ) u_control_data_width (
      .clk_i (clk_i),
      .rst_ni(rst_ni),

      // from register interface
      .we(control_data_width_we),
      .wd(control_data_width_wd),

      // from internal hardware
      .de(1'b0),
      .d ('0),

      // to internal hardware
      .qe(),
      .q (reg2hw.control.data_width.q),

      // to register interface (read)
      .qs(control_data_width_qs)
  );


  //   F[rx_start_channel]: 10:10
  prim_subreg #(
      .DW      (1),
      .SWACCESS("RW"),
      .RESVAL  (1'h0)
  ) u_control_rx_start_channel (
      .clk_i (clk_i),
      .rst_ni(rst_ni),

      // from register interface
      .we(control_rx_start_channel_we),
      .wd(control_rx_start_channel_wd),

      // from internal hardware
      .de(1'b0),
      .d ('0),

      // to internal hardware
      .qe(),
      .q (reg2hw.control.rx_start_channel.q),

      // to register interface (read)
      .qs(control_rx_start_channel_qs)
  );


  //   F[reset_rx_overflow]: 11:11
  prim_subreg #(
      .DW      (1),
      .SWACCESS("RW"),
      .RESVAL  (1'h0)
  ) u_control_reset_rx_overflow (
      .clk_i (clk_i),
      .rst_ni(rst_ni),

      // from register interface
      .we(control_reset_rx_overflow_we),
      .wd(control_reset_rx_overflow_wd),

      // from internal hardware
      .de(hw2reg.control.reset_rx_overflow.de),
      .d (hw2reg.control.reset_rx_overflow.d),

      // to internal hardware
      .qe(),
      .q (reg2hw.control.reset_rx_overflow.q),

      // to register interface (read)
      .qs(control_reset_rx_overflow_qs)
  );


  // R[status]: V(True)

  //   F[running]: 0:0
  prim_subreg_ext #(
      .DW(1)
  ) u_status_running (
      .re (status_running_re),
      .we (1'b0),
      .wd ('0),
      .d  (hw2reg.status.running.d),
      .qre(),
      .qe (),
      .q  (),
      .qs (status_running_qs)
  );


  //   F[rx_data_ready]: 1:1
  prim_subreg_ext #(
      .DW(1)
  ) u_status_rx_data_ready (
      .re (status_rx_data_ready_re),
      .we (1'b0),
      .wd ('0),
      .d  (hw2reg.status.rx_data_ready.d),
      .qre(),
      .qe (),
      .q  (),
      .qs (status_rx_data_ready_qs)
  );


  //   F[rx_overflow]: 2:2
  prim_subreg_ext #(
      .DW(1)
  ) u_status_rx_overflow (
      .re (status_rx_overflow_re),
      .we (1'b0),
      .wd ('0),
      .d  (hw2reg.status.rx_overflow.d),
      .qre(),
      .qe (),
      .q  (),
      .qs (status_rx_overflow_qs)
  );


  // R[clkdividx]: V(False)

  prim_subreg #(
      .DW      (16),
      .SWACCESS("RW"),
      .RESVAL  (16'h4)
  ) u_clkdividx (
      .clk_i (clk_i),
      .rst_ni(rst_ni),

      // from register interface
      .we(clkdividx_we),
      .wd(clkdividx_wd),

      // from internal hardware
      .de(1'b0),
      .d ('0),

      // to internal hardware
      .qe(),
      .q (reg2hw.clkdividx.q),

      // to register interface (read)
      .qs(clkdividx_qs)
  );


  // R[rxdata]: V(True)

  prim_subreg_ext #(
      .DW(32)
  ) u_rxdata (
      .re (rxdata_re),
      .we (1'b0),
      .wd ('0),
      .d  (hw2reg.rxdata.d),
      .qre(reg2hw.rxdata.re),
      .qe (),
      .q  (reg2hw.rxdata.q),
      .qs (rxdata_qs)
  );


  // R[watermark]: V(False)

  prim_subreg #(
      .DW      (16),
      .SWACCESS("RW"),
      .RESVAL  (16'h0)
  ) u_watermark (
      .clk_i (clk_i),
      .rst_ni(rst_ni),

      // from register interface
      .we(watermark_we),
      .wd(watermark_wd),

      // from internal hardware
      .de(1'b0),
      .d ('0),

      // to internal hardware
      .qe(),
      .q (reg2hw.watermark.q),

      // to register interface (read)
      .qs(watermark_qs)
  );


  // R[waterlevel]: V(True)

  prim_subreg_ext #(
      .DW(16)
  ) u_waterlevel (
      .re (waterlevel_re),
      .we (1'b0),
      .wd ('0),
      .d  (hw2reg.waterlevel.d),
      .qre(),
      .qe (),
      .q  (),
      .qs (waterlevel_qs)
  );




  logic [5:0] addr_hit;
  always_comb begin
    addr_hit = '0;
    addr_hit[0] = (reg_addr == I2S_CONTROL_OFFSET);
    addr_hit[1] = (reg_addr == I2S_STATUS_OFFSET);
    addr_hit[2] = (reg_addr == I2S_CLKDIVIDX_OFFSET);
    addr_hit[3] = (reg_addr == I2S_RXDATA_OFFSET);
    addr_hit[4] = (reg_addr == I2S_WATERMARK_OFFSET);
    addr_hit[5] = (reg_addr == I2S_WATERLEVEL_OFFSET);
  end

  assign addrmiss = (reg_re || reg_we) ? ~|addr_hit : 1'b0;

  // Check sub-word write is permitted
  always_comb begin
    wr_err = (reg_we &
              ((addr_hit[0] & (|(I2S_PERMIT[0] & ~reg_be))) |
               (addr_hit[1] & (|(I2S_PERMIT[1] & ~reg_be))) |
               (addr_hit[2] & (|(I2S_PERMIT[2] & ~reg_be))) |
               (addr_hit[3] & (|(I2S_PERMIT[3] & ~reg_be))) |
               (addr_hit[4] & (|(I2S_PERMIT[4] & ~reg_be))) |
               (addr_hit[5] & (|(I2S_PERMIT[5] & ~reg_be)))));
  end

  assign control_en_we = addr_hit[0] & reg_we & !reg_error;
  assign control_en_wd = reg_wdata[0];

  assign control_en_ws_we = addr_hit[0] & reg_we & !reg_error;
  assign control_en_ws_wd = reg_wdata[1];

  assign control_en_rx_we = addr_hit[0] & reg_we & !reg_error;
  assign control_en_rx_wd = reg_wdata[3:2];

  assign control_intr_en_we = addr_hit[0] & reg_we & !reg_error;
  assign control_intr_en_wd = reg_wdata[4];

  assign control_en_watermark_we = addr_hit[0] & reg_we & !reg_error;
  assign control_en_watermark_wd = reg_wdata[5];

  assign control_reset_watermark_we = addr_hit[0] & reg_we & !reg_error;
  assign control_reset_watermark_wd = reg_wdata[6];

  assign control_en_io_we = addr_hit[0] & reg_we & !reg_error;
  assign control_en_io_wd = reg_wdata[7];

  assign control_data_width_we = addr_hit[0] & reg_we & !reg_error;
  assign control_data_width_wd = reg_wdata[9:8];

  assign control_rx_start_channel_we = addr_hit[0] & reg_we & !reg_error;
  assign control_rx_start_channel_wd = reg_wdata[10];

  assign control_reset_rx_overflow_we = addr_hit[0] & reg_we & !reg_error;
  assign control_reset_rx_overflow_wd = reg_wdata[11];

  assign status_running_re = addr_hit[1] & reg_re & !reg_error;

  assign status_rx_data_ready_re = addr_hit[1] & reg_re & !reg_error;

  assign status_rx_overflow_re = addr_hit[1] & reg_re & !reg_error;

  assign clkdividx_we = addr_hit[2] & reg_we & !reg_error;
  assign clkdividx_wd = reg_wdata[15:0];

  assign rxdata_re = addr_hit[3] & reg_re & !reg_error;

  assign watermark_we = addr_hit[4] & reg_we & !reg_error;
  assign watermark_wd = reg_wdata[15:0];

  assign waterlevel_re = addr_hit[5] & reg_re & !reg_error;

  // Read data return
  always_comb begin
    reg_rdata_next = '0;
    unique case (1'b1)
      addr_hit[0]: begin
        reg_rdata_next[0]   = control_en_qs;
        reg_rdata_next[1]   = control_en_ws_qs;
        reg_rdata_next[3:2] = control_en_rx_qs;
        reg_rdata_next[4]   = control_intr_en_qs;
        reg_rdata_next[5]   = control_en_watermark_qs;
        reg_rdata_next[6]   = control_reset_watermark_qs;
        reg_rdata_next[7]   = control_en_io_qs;
        reg_rdata_next[9:8] = control_data_width_qs;
        reg_rdata_next[10]  = control_rx_start_channel_qs;
        reg_rdata_next[11]  = control_reset_rx_overflow_qs;
      end

      addr_hit[1]: begin
        reg_rdata_next[0] = status_running_qs;
        reg_rdata_next[1] = status_rx_data_ready_qs;
        reg_rdata_next[2] = status_rx_overflow_qs;
      end

      addr_hit[2]: begin
        reg_rdata_next[15:0] = clkdividx_qs;
      end

      addr_hit[3]: begin
        reg_rdata_next[31:0] = rxdata_qs;
      end

      addr_hit[4]: begin
        reg_rdata_next[15:0] = watermark_qs;
      end

      addr_hit[5]: begin
        reg_rdata_next[15:0] = waterlevel_qs;
      end

      default: begin
        reg_rdata_next = '1;
      end
    endcase
  end

  // Unused signal tieoff

  // wdata / byte enable are not always fully used
  // add a blanket unused statement to handle lint waivers
  logic unused_wdata;
  logic unused_be;
  assign unused_wdata = ^reg_wdata;
  assign unused_be = ^reg_be;

  // Assertions for Register Interface
  `ASSERT(en2addrHit, (reg_we || reg_re) |-> $onehot0(addr_hit))

endmodule

module i2s_reg_top_intf #(
    parameter  int AW = 5,
    localparam int DW = 32
) (
    input logic clk_i,
    input logic rst_ni,
    REG_BUS.in regbus_slave,
    // To HW
    output i2s_reg_pkg::i2s_reg2hw_t reg2hw,  // Write
    input i2s_reg_pkg::i2s_hw2reg_t hw2reg,  // Read
    // Config
    input devmode_i  // If 1, explicit error return for unmapped register access
);
  localparam int unsigned STRB_WIDTH = DW / 8;

  `include "register_interface/typedef.svh"
  `include "register_interface/assign.svh"

  // Define structs for reg_bus
  typedef logic [AW-1:0] addr_t;
  typedef logic [DW-1:0] data_t;
  typedef logic [STRB_WIDTH-1:0] strb_t;
  `REG_BUS_TYPEDEF_ALL(reg_bus, addr_t, data_t, strb_t)

  reg_bus_req_t s_reg_req;
  reg_bus_rsp_t s_reg_rsp;

  // Assign SV interface to structs
  `REG_BUS_ASSIGN_TO_REQ(s_reg_req, regbus_slave)
  `REG_BUS_ASSIGN_FROM_RSP(regbus_slave, s_reg_rsp)



  i2s_reg_top #(
      .reg_req_t(reg_bus_req_t),
      .reg_rsp_t(reg_bus_rsp_t),
      .AW(AW)
  ) i_regs (
      .clk_i,
      .rst_ni,
      .reg_req_i(s_reg_req),
      .reg_rsp_o(s_reg_rsp),
      .reg2hw,  // Write
      .hw2reg,  // Read
      .devmode_i
  );

endmodule


