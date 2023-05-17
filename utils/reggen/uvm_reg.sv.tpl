// Copyright lowRISC contributors.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

// UVM Registers auto-generated by `reggen` containing data structure
##
##
## We use functions from uvm_reg_base.sv.tpl to define
## per-device-interface code.
##
<%namespace file="uvm_reg_base.sv.tpl" import="*"/>\
##
##
${make_ral_pkg(dv_base_names, block.regwidth, reg_block_path, rb, esc_if_name)}
