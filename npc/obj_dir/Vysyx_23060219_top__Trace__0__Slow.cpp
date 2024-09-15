// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_23060219_top__Syms.h"


VL_ATTR_COLD void Vysyx_23060219_top___024root__trace_init_sub__TOP__0(Vysyx_23060219_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+279,"clk", false,-1);
    tracep->declBit(c+280,"rst", false,-1);
    tracep->pushNamePrefix("ysyx_23060219_top ");
    tracep->declBit(c+279,"clk", false,-1);
    tracep->declBit(c+280,"rst", false,-1);
    tracep->declBus(c+19,"clk_cnt", false,-1, 2,0);
    tracep->declBit(c+20,"w_ifu_valid", false,-1);
    tracep->declBus(c+21,"w_ifu_pc", false,-1, 31,0);
    tracep->declBus(c+22,"w_ifu_inst", false,-1, 31,0);
    tracep->declBit(c+23,"w_idu_ready", false,-1);
    tracep->declBit(c+24,"w_idu_valid", false,-1);
    tracep->declBus(c+25,"w_idu_rs_id1", false,-1, 4,0);
    tracep->declBus(c+26,"w_idu_rs_id2", false,-1, 4,0);
    tracep->declBus(c+27,"w_idu_csr_rid", false,-1, 11,0);
    tracep->declBit(c+28,"w_idu_csr_ren", false,-1);
    tracep->declBit(c+29,"w_idu_is_mret", false,-1);
    tracep->declBit(c+30,"w_idu_is_ecall", false,-1);
    tracep->declBus(c+31,"w_idu_csr_type", false,-1, 1,0);
    tracep->declBus(c+32,"w_idu_alu_type", false,-1, 3,0);
    tracep->declBus(c+33,"w_idu_num_sel", false,-1, 1,0);
    tracep->declBus(c+34,"w_idu_imm", false,-1, 31,0);
    tracep->declBit(c+35,"w_idu_is_load", false,-1);
    tracep->declBit(c+36,"w_idu_is_store", false,-1);
    tracep->declBus(c+37,"w_idu_func3", false,-1, 2,0);
    tracep->declBus(c+38,"w_idu_pc", false,-1, 31,0);
    tracep->declBit(c+39,"w_idu_is_jal", false,-1);
    tracep->declBit(c+40,"w_idu_is_jalr", false,-1);
    tracep->declBit(c+41,"w_idu_is_brch", false,-1);
    tracep->declBus(c+42,"w_idu_rd_id", false,-1, 4,0);
    tracep->declBit(c+43,"w_idu_gpr_wen", false,-1);
    tracep->declBit(c+44,"w_exu_ready", false,-1);
    tracep->declBit(c+45,"w_exu_valid", false,-1);
    tracep->declBus(c+46,"w_exu_exu_res", false,-1, 31,0);
    tracep->declBit(c+47,"w_exu_is_load", false,-1);
    tracep->declBit(c+48,"w_exu_is_store", false,-1);
    tracep->declBus(c+49,"w_exu_func3", false,-1, 2,0);
    tracep->declBus(c+50,"w_exu_rs1", false,-1, 31,0);
    tracep->declBus(c+51,"w_exu_rs2", false,-1, 31,0);
    tracep->declBus(c+52,"w_exu_csr_npc", false,-1, 31,0);
    tracep->declBit(c+53,"w_exu_is_mret", false,-1);
    tracep->declBit(c+54,"w_exu_is_ecall", false,-1);
    tracep->declBus(c+55,"w_exu_imm", false,-1, 31,0);
    tracep->declBus(c+56,"w_exu_pc", false,-1, 31,0);
    tracep->declBit(c+57,"w_exu_is_jal", false,-1);
    tracep->declBit(c+58,"w_exu_is_jalr", false,-1);
    tracep->declBit(c+59,"w_exu_brch", false,-1);
    tracep->declBus(c+60,"w_exu_rd_id", false,-1, 4,0);
    tracep->declBit(c+61,"w_exu_gpr_wen", false,-1);
    tracep->declBus(c+62,"w_exu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+63,"w_exu_csr_rd", false,-1, 31,0);
    tracep->declBit(c+64,"w_exu_csr_wen", false,-1);
    tracep->declBit(c+65,"w_lsu_ready", false,-1);
    tracep->declBit(c+66,"w_lsu_valid", false,-1);
    tracep->declBus(c+67,"w_lsu_imm", false,-1, 31,0);
    tracep->declBus(c+68,"w_lsu_pc", false,-1, 31,0);
    tracep->declBus(c+69,"w_lsu_rs1", false,-1, 31,0);
    tracep->declBit(c+70,"w_lsu_is_jal", false,-1);
    tracep->declBit(c+71,"w_lsu_is_jalr", false,-1);
    tracep->declBit(c+72,"w_lsu_brch", false,-1);
    tracep->declBus(c+73,"w_lsu_csr_npc", false,-1, 31,0);
    tracep->declBit(c+74,"w_lsu_is_ejump", false,-1);
    tracep->declBus(c+75,"w_lsu_rd", false,-1, 31,0);
    tracep->declBus(c+76,"w_lsu_rd_id", false,-1, 4,0);
    tracep->declBit(c+77,"w_lsu_gpr_wen", false,-1);
    tracep->declBit(c+78,"w_lsu_csr_wen", false,-1);
    tracep->declBit(c+79,"w_lsu_is_mret", false,-1);
    tracep->declBit(c+80,"w_lsu_is_ecall", false,-1);
    tracep->declBus(c+81,"w_lsu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+82,"w_lsu_csr_rd", false,-1, 31,0);
    tracep->declBit(c+20,"w_wbu_ready", false,-1);
    tracep->declBit(c+83,"w_wbu_cycle_end", false,-1);
    tracep->declBit(c+84,"w_wbu_npc_wen", false,-1);
    tracep->declBus(c+75,"w_wbu_rd", false,-1, 31,0);
    tracep->declBus(c+76,"w_wbu_rd_id", false,-1, 4,0);
    tracep->declBit(c+85,"w_wbu_gpr_wen", false,-1);
    tracep->declBus(c+69,"w_wbu_mcause_in", false,-1, 31,0);
    tracep->declBus(c+68,"w_wbu_mepc_in", false,-1, 31,0);
    tracep->declBit(c+78,"w_wbu_csr_wen", false,-1);
    tracep->declBus(c+81,"w_wbu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+82,"w_wbu_csr_rd", false,-1, 31,0);
    tracep->declBus(c+86,"w_bru_npc", false,-1, 31,0);
    tracep->declBus(c+87,"w_rf_rs1", false,-1, 31,0);
    tracep->declBus(c+88,"w_rf_rs2", false,-1, 31,0);
    tracep->declBus(c+89,"w_cc_csr_src", false,-1, 31,0);
    tracep->declBus(c+90,"w_cc_csr_npc", false,-1, 31,0);
    tracep->pushNamePrefix("bru_inst ");
    tracep->declBit(c+279,"clk", false,-1);
    tracep->declBit(c+280,"rst", false,-1);
    tracep->declBus(c+68,"i_bru_pc", false,-1, 31,0);
    tracep->declBus(c+67,"i_bru_imm", false,-1, 31,0);
    tracep->declBit(c+70,"i_bru_is_jal", false,-1);
    tracep->declBit(c+71,"i_bru_is_jalr", false,-1);
    tracep->declBit(c+72,"i_bru_brch", false,-1);
    tracep->declBit(c+74,"i_bru_ejump", false,-1);
    tracep->declBus(c+73,"i_bru_csr_npc", false,-1, 31,0);
    tracep->declBus(c+69,"i_bru_rs1", false,-1, 31,0);
    tracep->declBit(c+84,"i_bru_npc_wen", false,-1);
    tracep->declBus(c+86,"o_bru_npc", false,-1, 31,0);
    tracep->declBus(c+91,"pc_jorb", false,-1, 31,0);
    tracep->declBus(c+92,"npc_t1", false,-1, 31,0);
    tracep->declBus(c+93,"npc_t2", false,-1, 31,0);
    tracep->declBus(c+281,"temp", false,-1, 31,0);
    tracep->declBus(c+86,"npc_reg", false,-1, 31,0);
    tracep->pushNamePrefix("mux1 ");
    tracep->declBus(c+282,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+283,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+284,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+91,"out", false,-1, 31,0);
    tracep->declBus(c+71,"key", false,-1, 0,0);
    tracep->declArray(c+94,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+282,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+283,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+284,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+285,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+91,"out", false,-1, 31,0);
    tracep->declBus(c+71,"key", false,-1, 0,0);
    tracep->declBus(c+286,"default_out", false,-1, 31,0);
    tracep->declArray(c+94,"lut", false,-1, 65,0);
    tracep->declBus(c+287,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+97+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+101+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+103,"lut_out", false,-1, 31,0);
    tracep->declBit(c+104,"hit", false,-1);
    tracep->declBus(c+288,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("mux2 ");
    tracep->declBus(c+282,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+283,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+284,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+92,"out", false,-1, 31,0);
    tracep->declBus(c+105,"key", false,-1, 0,0);
    tracep->declArray(c+106,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+282,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+283,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+284,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+285,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+92,"out", false,-1, 31,0);
    tracep->declBus(c+105,"key", false,-1, 0,0);
    tracep->declBus(c+286,"default_out", false,-1, 31,0);
    tracep->declArray(c+106,"lut", false,-1, 65,0);
    tracep->declBus(c+287,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+109+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+3+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+113+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+115,"lut_out", false,-1, 31,0);
    tracep->declBit(c+116,"hit", false,-1);
    tracep->declBus(c+288,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("mux3 ");
    tracep->declBus(c+282,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+283,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+284,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+93,"out", false,-1, 31,0);
    tracep->declBus(c+74,"key", false,-1, 0,0);
    tracep->declArray(c+117,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+282,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+283,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+284,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+285,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+93,"out", false,-1, 31,0);
    tracep->declBus(c+74,"key", false,-1, 0,0);
    tracep->declBus(c+286,"default_out", false,-1, 31,0);
    tracep->declArray(c+117,"lut", false,-1, 65,0);
    tracep->declBus(c+287,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+120+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+5+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+124+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+126,"lut_out", false,-1, 31,0);
    tracep->declBit(c+127,"hit", false,-1);
    tracep->declBus(c+288,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("csr_ctrl_inst ");
    tracep->declBit(c+279,"clk", false,-1);
    tracep->declBit(c+280,"rst", false,-1);
    tracep->declBit(c+28,"i_ccu_csr_ren", false,-1);
    tracep->declBus(c+27,"i_ccu_csr_rid", false,-1, 11,0);
    tracep->declBit(c+29,"i_ccu_is_mret", false,-1);
    tracep->declBit(c+30,"i_ccu_is_ecall", false,-1);
    tracep->declBit(c+78,"i_ccu_csr_wen", false,-1);
    tracep->declBus(c+81,"i_ccu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+82,"i_ccu_csr_rd", false,-1, 31,0);
    tracep->declBus(c+69,"i_ccu_macuse_in", false,-1, 31,0);
    tracep->declBus(c+68,"i_ccu_mepc_in", false,-1, 31,0);
    tracep->declBus(c+89,"o_exu_csr_src", false,-1, 31,0);
    tracep->declBus(c+90,"o_exu_csr_npc", false,-1, 31,0);
    tracep->declBus(c+128,"mstatus", false,-1, 31,0);
    tracep->declBus(c+129,"mtvec", false,-1, 31,0);
    tracep->declBus(c+130,"mepc", false,-1, 31,0);
    tracep->declBus(c+131,"mcause", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("exu_inst ");
    tracep->declBit(c+279,"clk", false,-1);
    tracep->declBit(c+280,"rst", false,-1);
    tracep->declBit(c+24,"i_pre_valid", false,-1);
    tracep->declBit(c+44,"o_pre_ready", false,-1);
    tracep->declBit(c+45,"o_post_valid", false,-1);
    tracep->declBit(c+65,"i_post_ready", false,-1);
    tracep->declBus(c+38,"i_exu_pc", false,-1, 31,0);
    tracep->declBus(c+32,"i_exu_alu_type", false,-1, 3,0);
    tracep->declBus(c+33,"i_exu_num_sel", false,-1, 1,0);
    tracep->declBus(c+34,"i_exu_imm", false,-1, 31,0);
    tracep->declBit(c+39,"i_exu_is_jal", false,-1);
    tracep->declBit(c+40,"i_exu_is_jalr", false,-1);
    tracep->declBit(c+41,"i_exu_is_brch", false,-1);
    tracep->declBit(c+35,"i_exu_is_load", false,-1);
    tracep->declBit(c+36,"i_exu_is_store", false,-1);
    tracep->declBus(c+37,"i_exu_func3", false,-1, 2,0);
    tracep->declBus(c+42,"i_exu_rd_id", false,-1, 4,0);
    tracep->declBit(c+43,"i_exu_gpr_wen", false,-1);
    tracep->declBus(c+31,"i_exu_csr_type", false,-1, 1,0);
    tracep->declBus(c+27,"i_exu_csr_rid", false,-1, 11,0);
    tracep->declBit(c+28,"i_exu_csr_ren", false,-1);
    tracep->declBit(c+29,"i_exu_is_mret", false,-1);
    tracep->declBit(c+30,"i_exu_is_ecall", false,-1);
    tracep->declBus(c+87,"i_exu_rs1", false,-1, 31,0);
    tracep->declBus(c+88,"i_exu_rs2", false,-1, 31,0);
    tracep->declBus(c+89,"i_exu_csr_src", false,-1, 31,0);
    tracep->declBus(c+90,"i_exu_csr_npc", false,-1, 31,0);
    tracep->declBus(c+46,"o_exu_exu_res", false,-1, 31,0);
    tracep->declBit(c+47,"o_exu_is_load", false,-1);
    tracep->declBit(c+48,"o_exu_is_store", false,-1);
    tracep->declBus(c+49,"o_exu_func3", false,-1, 2,0);
    tracep->declBus(c+50,"o_exu_rs1", false,-1, 31,0);
    tracep->declBus(c+51,"o_exu_rs2", false,-1, 31,0);
    tracep->declBus(c+52,"o_exu_csr_npc", false,-1, 31,0);
    tracep->declBit(c+53,"o_exu_is_mret", false,-1);
    tracep->declBit(c+54,"o_exu_is_ecall", false,-1);
    tracep->declBus(c+55,"o_exu_imm", false,-1, 31,0);
    tracep->declBus(c+56,"o_exu_pc", false,-1, 31,0);
    tracep->declBit(c+57,"o_exu_is_jal", false,-1);
    tracep->declBit(c+58,"o_exu_is_jalr", false,-1);
    tracep->declBit(c+59,"o_exu_brch", false,-1);
    tracep->declBus(c+60,"o_exu_rd_id", false,-1, 4,0);
    tracep->declBit(c+61,"o_exu_gpr_wen", false,-1);
    tracep->declBus(c+62,"o_exu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+63,"o_exu_csr_rd", false,-1, 31,0);
    tracep->declBit(c+64,"o_exu_csr_wen", false,-1);
    tracep->declBus(c+132,"exu_exu_res", false,-1, 31,0);
    tracep->declBit(c+35,"exu_is_load", false,-1);
    tracep->declBit(c+36,"exu_is_store", false,-1);
    tracep->declBus(c+37,"exu_func3", false,-1, 2,0);
    tracep->declBus(c+87,"exu_rs1", false,-1, 31,0);
    tracep->declBus(c+88,"exu_rs2", false,-1, 31,0);
    tracep->declBus(c+90,"exu_csr_npc", false,-1, 31,0);
    tracep->declBit(c+29,"exu_is_mret", false,-1);
    tracep->declBit(c+30,"exu_is_ecall", false,-1);
    tracep->declBus(c+34,"exu_imm", false,-1, 31,0);
    tracep->declBus(c+38,"exu_pc", false,-1, 31,0);
    tracep->declBit(c+39,"exu_is_jal", false,-1);
    tracep->declBit(c+40,"exu_is_jalr", false,-1);
    tracep->declBit(c+133,"exu_brch", false,-1);
    tracep->declBus(c+42,"exu_rd_id", false,-1, 4,0);
    tracep->declBit(c+43,"exu_gpr_wen", false,-1);
    tracep->declBus(c+27,"exu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+134,"exu_csr_rd", false,-1, 31,0);
    tracep->declBit(c+28,"exu_csr_wen", false,-1);
    tracep->declBus(c+135,"exu_alu_res", false,-1, 31,0);
    tracep->declBus(c+136,"num1", false,-1, 31,0);
    tracep->declBus(c+137,"num2", false,-1, 31,0);
    tracep->declBus(c+138,"num2_cplm", false,-1, 31,0);
    tracep->declBit(c+139,"exu_reg_wen", false,-1);
    tracep->declArray(c+140,"exu_valid_data_reg", false,-1, 252,0);
    tracep->declBit(c+45,"post_valid_reg", false,-1);
    tracep->pushNamePrefix("mux1 ");
    tracep->declBus(c+289,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+282,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+284,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+136,"out", false,-1, 31,0);
    tracep->declBus(c+33,"key", false,-1, 1,0);
    tracep->declArray(c+148,"lut", false,-1, 135,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+289,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+282,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+284,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+285,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+136,"out", false,-1, 31,0);
    tracep->declBus(c+33,"key", false,-1, 1,0);
    tracep->declBus(c+286,"default_out", false,-1, 31,0);
    tracep->declArray(c+148,"lut", false,-1, 135,0);
    tracep->declBus(c+290,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+153+i*2,"pair_list", true,(i+0), 33,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+7+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+161+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+165,"lut_out", false,-1, 31,0);
    tracep->declBit(c+166,"hit", false,-1);
    tracep->declBus(c+291,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("mux2 ");
    tracep->declBus(c+289,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+282,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+284,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+137,"out", false,-1, 31,0);
    tracep->declBus(c+33,"key", false,-1, 1,0);
    tracep->declArray(c+167,"lut", false,-1, 135,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+289,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+282,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+284,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+285,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+137,"out", false,-1, 31,0);
    tracep->declBus(c+33,"key", false,-1, 1,0);
    tracep->declBus(c+286,"default_out", false,-1, 31,0);
    tracep->declArray(c+167,"lut", false,-1, 135,0);
    tracep->declBus(c+290,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+172+i*2,"pair_list", true,(i+0), 33,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+11+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+180+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+184,"lut_out", false,-1, 31,0);
    tracep->declBit(c+185,"hit", false,-1);
    tracep->declBus(c+291,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("mux3 ");
    tracep->declBus(c+289,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+282,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+284,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+134,"out", false,-1, 31,0);
    tracep->declBus(c+31,"key", false,-1, 1,0);
    tracep->declArray(c+186,"lut", false,-1, 135,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+289,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+282,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+284,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+285,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+134,"out", false,-1, 31,0);
    tracep->declBus(c+31,"key", false,-1, 1,0);
    tracep->declBus(c+286,"default_out", false,-1, 31,0);
    tracep->declArray(c+186,"lut", false,-1, 135,0);
    tracep->declBus(c+290,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+191+i*2,"pair_list", true,(i+0), 33,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+15+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+199+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+203,"lut_out", false,-1, 31,0);
    tracep->declBit(c+204,"hit", false,-1);
    tracep->declBus(c+291,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("idu_inst ");
    tracep->declBit(c+279,"clk", false,-1);
    tracep->declBit(c+280,"rst", false,-1);
    tracep->declBit(c+20,"i_pre_valid", false,-1);
    tracep->declBit(c+23,"o_pre_ready", false,-1);
    tracep->declBit(c+24,"o_post_valid", false,-1);
    tracep->declBit(c+44,"i_post_ready", false,-1);
    tracep->declBus(c+21,"i_idu_pc", false,-1, 31,0);
    tracep->declBus(c+22,"i_idu_inst", false,-1, 31,0);
    tracep->declBus(c+25,"o_idu_rs_id1", false,-1, 4,0);
    tracep->declBus(c+26,"o_idu_rs_id2", false,-1, 4,0);
    tracep->declBus(c+27,"o_idu_csr_rid", false,-1, 11,0);
    tracep->declBit(c+28,"o_idu_csr_ren", false,-1);
    tracep->declBit(c+29,"o_idu_is_mret", false,-1);
    tracep->declBit(c+30,"o_idu_is_ecall", false,-1);
    tracep->declBus(c+31,"o_idu_csr_type", false,-1, 1,0);
    tracep->declBus(c+32,"o_idu_alu_type", false,-1, 3,0);
    tracep->declBus(c+33,"o_idu_num_sel", false,-1, 1,0);
    tracep->declBus(c+34,"o_idu_imm", false,-1, 31,0);
    tracep->declBit(c+35,"o_idu_is_load", false,-1);
    tracep->declBit(c+36,"o_idu_is_store", false,-1);
    tracep->declBus(c+37,"o_idu_func3", false,-1, 2,0);
    tracep->declBus(c+38,"o_idu_pc", false,-1, 31,0);
    tracep->declBit(c+39,"o_idu_is_jal", false,-1);
    tracep->declBit(c+40,"o_idu_is_jalr", false,-1);
    tracep->declBit(c+41,"o_idu_is_brch", false,-1);
    tracep->declBus(c+42,"o_idu_rd_id", false,-1, 4,0);
    tracep->declBit(c+43,"o_idu_gpr_wen", false,-1);
    tracep->declBus(c+205,"idu_rs_id1", false,-1, 4,0);
    tracep->declBus(c+206,"idu_rs_id2", false,-1, 4,0);
    tracep->declBus(c+207,"idu_csr_rid", false,-1, 11,0);
    tracep->declBit(c+208,"idu_csr_ren", false,-1);
    tracep->declBit(c+209,"idu_is_mret", false,-1);
    tracep->declBit(c+210,"idu_is_ecall", false,-1);
    tracep->declBus(c+211,"idu_csr_type", false,-1, 1,0);
    tracep->declBus(c+212,"idu_alu_type", false,-1, 3,0);
    tracep->declBus(c+213,"idu_num_sel", false,-1, 1,0);
    tracep->declBus(c+214,"idu_imm", false,-1, 31,0);
    tracep->declBit(c+215,"idu_is_load", false,-1);
    tracep->declBit(c+216,"idu_is_store", false,-1);
    tracep->declBus(c+217,"idu_func3", false,-1, 2,0);
    tracep->declBus(c+21,"idu_pc", false,-1, 31,0);
    tracep->declBit(c+218,"idu_is_jal", false,-1);
    tracep->declBit(c+219,"idu_is_jalr", false,-1);
    tracep->declBit(c+220,"idu_is_brch", false,-1);
    tracep->declBus(c+221,"idu_rd_id", false,-1, 4,0);
    tracep->declBit(c+222,"idu_gpr_wen", false,-1);
    tracep->declBus(c+223,"opcode", false,-1, 6,0);
    tracep->declBus(c+221,"rd_id", false,-1, 4,0);
    tracep->declBus(c+217,"func3", false,-1, 2,0);
    tracep->declBus(c+224,"rs_id1", false,-1, 4,0);
    tracep->declBus(c+206,"rs_id2", false,-1, 4,0);
    tracep->declBus(c+225,"func7", false,-1, 6,0);
    tracep->declBit(c+226,"idu_reg_wen", false,-1);
    tracep->declArray(c+227,"idu_valid_data_reg", false,-1, 110,0);
    tracep->declBit(c+24,"post_valid_reg", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ifu_inst ");
    tracep->declBit(c+279,"clk", false,-1);
    tracep->declBit(c+280,"rst", false,-1);
    tracep->declBit(c+83,"i_cycle_end", false,-1);
    tracep->declBit(c+20,"o_post_valid", false,-1);
    tracep->declBit(c+23,"i_post_ready", false,-1);
    tracep->declBus(c+86,"i_ifu_npc", false,-1, 31,0);
    tracep->declBus(c+21,"o_ifu_pc", false,-1, 31,0);
    tracep->declBus(c+22,"o_ifu_inst", false,-1, 31,0);
    tracep->declBus(c+231,"ifu_inst", false,-1, 31,0);
    tracep->declQuad(c+232,"ifu_valid_data_reg", false,-1, 63,0);
    tracep->declBit(c+83,"ifu_reg_wen", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("lsu_inst ");
    tracep->declBit(c+279,"clk", false,-1);
    tracep->declBit(c+280,"rst", false,-1);
    tracep->declBit(c+45,"i_pre_valid", false,-1);
    tracep->declBit(c+65,"o_pre_ready", false,-1);
    tracep->declBit(c+66,"o_post_valid", false,-1);
    tracep->declBit(c+20,"i_post_ready", false,-1);
    tracep->declBus(c+56,"i_lsu_pc", false,-1, 31,0);
    tracep->declBit(c+47,"i_lsu_is_load", false,-1);
    tracep->declBit(c+48,"i_lsu_is_store", false,-1);
    tracep->declBus(c+49,"i_lsu_func3", false,-1, 2,0);
    tracep->declBus(c+55,"i_lsu_imm", false,-1, 31,0);
    tracep->declBit(c+57,"i_lsu_is_jal", false,-1);
    tracep->declBit(c+58,"i_lsu_is_jalr", false,-1);
    tracep->declBit(c+59,"i_lsu_brch", false,-1);
    tracep->declBus(c+60,"i_lsu_rd_id", false,-1, 4,0);
    tracep->declBit(c+61,"i_lsu_gpr_wen", false,-1);
    tracep->declBus(c+50,"i_lsu_rs1", false,-1, 31,0);
    tracep->declBus(c+51,"i_lsu_rs2", false,-1, 31,0);
    tracep->declBus(c+52,"i_lsu_csr_npc", false,-1, 31,0);
    tracep->declBus(c+62,"i_lsu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+63,"i_lsu_csr_rd", false,-1, 31,0);
    tracep->declBit(c+64,"i_lsu_csr_wen", false,-1);
    tracep->declBit(c+53,"i_lsu_is_mret", false,-1);
    tracep->declBit(c+54,"i_lsu_is_ecall", false,-1);
    tracep->declBus(c+46,"i_lsu_exu_res", false,-1, 31,0);
    tracep->declBus(c+67,"o_lsu_imm", false,-1, 31,0);
    tracep->declBus(c+68,"o_lsu_pc", false,-1, 31,0);
    tracep->declBus(c+69,"o_lsu_rs1", false,-1, 31,0);
    tracep->declBit(c+70,"o_lsu_is_jal", false,-1);
    tracep->declBit(c+71,"o_lsu_is_jalr", false,-1);
    tracep->declBit(c+72,"o_lsu_brch", false,-1);
    tracep->declBus(c+73,"o_lsu_csr_npc", false,-1, 31,0);
    tracep->declBit(c+74,"o_lsu_is_ejump", false,-1);
    tracep->declBus(c+75,"o_lsu_rd", false,-1, 31,0);
    tracep->declBus(c+76,"o_lsu_rd_id", false,-1, 4,0);
    tracep->declBit(c+77,"o_lsu_gpr_wen", false,-1);
    tracep->declBit(c+78,"o_lsu_csr_wen", false,-1);
    tracep->declBit(c+79,"o_lsu_is_mret", false,-1);
    tracep->declBit(c+80,"o_lsu_is_ecall", false,-1);
    tracep->declBus(c+81,"o_lsu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+82,"o_lsu_csr_rd", false,-1, 31,0);
    tracep->declBus(c+55,"lsu_imm", false,-1, 31,0);
    tracep->declBus(c+56,"lsu_pc", false,-1, 31,0);
    tracep->declBus(c+50,"lsu_rs1", false,-1, 31,0);
    tracep->declBit(c+57,"lsu_is_jal", false,-1);
    tracep->declBit(c+58,"lsu_is_jalr", false,-1);
    tracep->declBit(c+59,"lsu_brch", false,-1);
    tracep->declBus(c+52,"lsu_csr_npc", false,-1, 31,0);
    tracep->declBit(c+234,"lsu_is_ejump", false,-1);
    tracep->declBus(c+292,"lsu_rd", false,-1, 31,0);
    tracep->declBus(c+60,"lsu_rd_id", false,-1, 4,0);
    tracep->declBit(c+61,"lsu_gpr_wen", false,-1);
    tracep->declBit(c+64,"lsu_csr_wen", false,-1);
    tracep->declBit(c+53,"lsu_is_mret", false,-1);
    tracep->declBit(c+54,"lsu_is_ecall", false,-1);
    tracep->declBus(c+62,"lsu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+63,"lsu_csr_rd", false,-1, 31,0);
    tracep->declBus(c+46,"dmem_raddr", false,-1, 31,0);
    tracep->declBus(c+235,"dmem_rdata_t", false,-1, 31,0);
    tracep->declBus(c+236,"dmem_rdata", false,-1, 31,0);
    tracep->declBus(c+46,"dmem_waddr", false,-1, 31,0);
    tracep->declBus(c+51,"dmem_wdata", false,-1, 31,0);
    tracep->declBus(c+237,"wmask", false,-1, 7,0);
    tracep->declBit(c+238,"lsu_reg_wen", false,-1);
    tracep->declArray(c+239,"lsu_valid_data_reg", false,-1, 184,0);
    tracep->declBit(c+66,"post_valid_reg", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("register_file_inst ");
    tracep->declBit(c+279,"clk", false,-1);
    tracep->declBit(c+280,"rst", false,-1);
    tracep->declBit(c+85,"i_rf_gpr_wen", false,-1);
    tracep->declBus(c+76,"i_rf_rd_id", false,-1, 4,0);
    tracep->declBus(c+75,"i_rf_rd", false,-1, 31,0);
    tracep->declBus(c+25,"i_rf_rs_id1", false,-1, 4,0);
    tracep->declBus(c+26,"i_rf_rs_id2", false,-1, 4,0);
    tracep->declBus(c+87,"o_rf_rs1", false,-1, 31,0);
    tracep->declBus(c+88,"o_rf_rs2", false,-1, 31,0);
    tracep->declBus(c+245,"i", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+246+i*1,"regs", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("wbu_inst ");
    tracep->declBit(c+279,"clk", false,-1);
    tracep->declBit(c+280,"rst", false,-1);
    tracep->declBit(c+66,"i_pre_valid", false,-1);
    tracep->declBit(c+20,"o_pre_ready", false,-1);
    tracep->declBit(c+83,"o_cycle_end", false,-1);
    tracep->declBus(c+68,"i_wbu_pc", false,-1, 31,0);
    tracep->declBus(c+76,"i_wbu_rd_id", false,-1, 4,0);
    tracep->declBit(c+77,"i_wbu_gpr_wen", false,-1);
    tracep->declBus(c+69,"i_wbu_rs1", false,-1, 31,0);
    tracep->declBit(c+79,"i_wbu_is_mret", false,-1);
    tracep->declBit(c+80,"i_wbu_is_ecall", false,-1);
    tracep->declBus(c+81,"i_wbu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+82,"i_wbu_csr_rd", false,-1, 31,0);
    tracep->declBit(c+78,"i_wbu_csr_wen", false,-1);
    tracep->declBus(c+75,"i_wbu_rd", false,-1, 31,0);
    tracep->declBit(c+84,"o_wbu_npc_wen", false,-1);
    tracep->declBus(c+75,"o_wbu_rd", false,-1, 31,0);
    tracep->declBus(c+76,"o_wbu_rd_id", false,-1, 4,0);
    tracep->declBit(c+85,"o_wbu_gpr_wen", false,-1);
    tracep->declBus(c+69,"o_wbu_mcause_in", false,-1, 31,0);
    tracep->declBus(c+68,"o_wbu_mepc_in", false,-1, 31,0);
    tracep->declBit(c+78,"o_wbu_csr_wen", false,-1);
    tracep->declBus(c+81,"o_wbu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+82,"o_wbu_csr_rd", false,-1, 31,0);
    tracep->declBit(c+278,"pre_valid_reg", false,-1);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vysyx_23060219_top___024root__trace_init_top(Vysyx_23060219_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root__trace_init_top\n"); );
    // Body
    Vysyx_23060219_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vysyx_23060219_top___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_23060219_top___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_23060219_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vysyx_23060219_top___024root__trace_register(Vysyx_23060219_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vysyx_23060219_top___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vysyx_23060219_top___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vysyx_23060219_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vysyx_23060219_top___024root__trace_full_sub_0(Vysyx_23060219_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vysyx_23060219_top___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root__trace_full_top_0\n"); );
    // Init
    Vysyx_23060219_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_23060219_top___024root*>(voidSelf);
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vysyx_23060219_top___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vysyx_23060219_top___024root__trace_full_sub_0(Vysyx_23060219_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<3>/*95:0*/ __Vtemp_hdef3b0b3__0;
    VlWide<3>/*95:0*/ __Vtemp_hc0107ab8__0;
    VlWide<3>/*95:0*/ __Vtemp_heed9c555__0;
    VlWide<5>/*159:0*/ __Vtemp_h37e5707f__0;
    VlWide<5>/*159:0*/ __Vtemp_h56ffa0b7__0;
    VlWide<5>/*159:0*/ __Vtemp_h8324a3cc__0;
    // Body
    bufp->fullBit(oldp+1,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+2,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__key_list[1]));
    bufp->fullBit(oldp+3,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+4,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__key_list[1]));
    bufp->fullBit(oldp+5,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+6,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__key_list[1]));
    bufp->fullCData(oldp+7,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[0]),2);
    bufp->fullCData(oldp+8,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[1]),2);
    bufp->fullCData(oldp+9,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[2]),2);
    bufp->fullCData(oldp+10,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[3]),2);
    bufp->fullCData(oldp+11,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[0]),2);
    bufp->fullCData(oldp+12,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[1]),2);
    bufp->fullCData(oldp+13,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[2]),2);
    bufp->fullCData(oldp+14,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[3]),2);
    bufp->fullCData(oldp+15,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[0]),2);
    bufp->fullCData(oldp+16,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[1]),2);
    bufp->fullCData(oldp+17,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[2]),2);
    bufp->fullCData(oldp+18,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[3]),2);
    bufp->fullCData(oldp+19,(vlSelf->ysyx_23060219_top__DOT__clk_cnt),3);
    bufp->fullBit(oldp+20,((1U & (~ (IData)(vlSelf->ysyx_23060219_top__DOT__w_wbu_cycle_end)))));
    bufp->fullIData(oldp+21,((IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                      >> 0x20U))),32);
    bufp->fullIData(oldp+22,((IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)),32);
    bufp->fullBit(oldp+23,((1U & (~ (IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__post_valid_reg)))));
    bufp->fullBit(oldp+24,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__post_valid_reg));
    bufp->fullCData(oldp+25,((0x1fU & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                                       >> 0xaU))),5);
    bufp->fullCData(oldp+26,((0x1fU & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                                       >> 5U))),5);
    bufp->fullSData(oldp+27,((0xfffU & ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                                         << 7U) | (
                                                   vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                                   >> 0x19U)))),12);
    bufp->fullBit(oldp+28,((1U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                  >> 0x18U))));
    bufp->fullBit(oldp+29,((1U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                  >> 0x17U))));
    bufp->fullBit(oldp+30,((1U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                  >> 0x16U))));
    bufp->fullCData(oldp+31,((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                    >> 0x14U))),2);
    bufp->fullCData(oldp+32,((0xfU & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                      >> 0x10U))),4);
    bufp->fullCData(oldp+33,((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                    >> 0xeU))),2);
    bufp->fullIData(oldp+34,(((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                               << 0x12U) | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                            >> 0xeU))),32);
    bufp->fullBit(oldp+35,((1U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                  >> 0xdU))));
    bufp->fullBit(oldp+36,((1U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                  >> 0xcU))));
    bufp->fullCData(oldp+37,((7U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                    >> 9U))),3);
    bufp->fullIData(oldp+38,(((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                               << 0x17U) | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                            >> 9U))),32);
    bufp->fullBit(oldp+39,((1U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                  >> 8U))));
    bufp->fullBit(oldp+40,((1U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                  >> 7U))));
    bufp->fullBit(oldp+41,((1U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                  >> 6U))));
    bufp->fullCData(oldp+42,((0x1fU & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                       >> 1U))),5);
    bufp->fullBit(oldp+43,((1U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U])));
    bufp->fullBit(oldp+44,((1U & (~ (IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__post_valid_reg)))));
    bufp->fullBit(oldp+45,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__post_valid_reg));
    bufp->fullIData(oldp+46,(((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[7U] 
                               << 3U) | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                         >> 0x1dU))),32);
    bufp->fullBit(oldp+47,((1U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                  >> 0x1cU))));
    bufp->fullBit(oldp+48,((1U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                  >> 0x1bU))));
    bufp->fullCData(oldp+49,((7U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                    >> 0x18U))),3);
    bufp->fullIData(oldp+50,(((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                               << 8U) | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[5U] 
                                         >> 0x18U))),32);
    bufp->fullIData(oldp+51,(((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[5U] 
                               << 8U) | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[4U] 
                                         >> 0x18U))),32);
    bufp->fullIData(oldp+52,(((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[4U] 
                               << 8U) | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                         >> 0x18U))),32);
    bufp->fullBit(oldp+53,((1U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                  >> 0x17U))));
    bufp->fullBit(oldp+54,((1U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                  >> 0x16U))));
    bufp->fullIData(oldp+55,(((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                               << 0xaU) | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
                                           >> 0x16U))),32);
    bufp->fullIData(oldp+56,(((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
                               << 0xaU) | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                           >> 0x16U))),32);
    bufp->fullBit(oldp+57,((1U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                  >> 0x15U))));
    bufp->fullBit(oldp+58,((1U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                  >> 0x14U))));
    bufp->fullBit(oldp+59,((1U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                  >> 0x13U))));
    bufp->fullCData(oldp+60,((0x1fU & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                       >> 0xeU))),5);
    bufp->fullBit(oldp+61,((1U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                  >> 0xdU))));
    bufp->fullSData(oldp+62,((0xfffU & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                        >> 1U))),12);
    bufp->fullIData(oldp+63,(((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                               << 0x1fU) | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[0U] 
                                            >> 1U))),32);
    bufp->fullBit(oldp+64,((1U & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[0U])));
    bufp->fullBit(oldp+65,((1U & (~ (IData)(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg)))));
    bufp->fullBit(oldp+66,(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg));
    bufp->fullIData(oldp+67,(((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                               << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                         >> 0x19U))),32);
    bufp->fullIData(oldp+68,(((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                               << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                         >> 0x19U))),32);
    bufp->fullIData(oldp+69,(((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                               << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                         >> 0x19U))),32);
    bufp->fullBit(oldp+70,((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                  >> 0x18U))));
    bufp->fullBit(oldp+71,((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                  >> 0x17U))));
    bufp->fullBit(oldp+72,((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                  >> 0x16U))));
    bufp->fullIData(oldp+73,(((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                               << 0xaU) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                           >> 0x16U))),32);
    bufp->fullBit(oldp+74,((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                  >> 0x15U))));
    bufp->fullIData(oldp+75,(((0x10000000U & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U])
                               ? vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata
                               : ((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[7U] 
                                   << 3U) | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                             >> 0x1dU)))),32);
    bufp->fullCData(oldp+76,((0x1fU & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                       >> 0x10U))),5);
    bufp->fullBit(oldp+77,((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                  >> 0xfU))));
    bufp->fullBit(oldp+78,((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                  >> 0xeU))));
    bufp->fullBit(oldp+79,((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                  >> 0xdU))));
    bufp->fullBit(oldp+80,((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                  >> 0xcU))));
    bufp->fullSData(oldp+81,((0xfffU & vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U])),12);
    bufp->fullIData(oldp+82,(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[0U]),32);
    bufp->fullBit(oldp+83,(vlSelf->ysyx_23060219_top__DOT__w_wbu_cycle_end));
    bufp->fullBit(oldp+84,(vlSelf->ysyx_23060219_top__DOT__w_wbu_npc_wen));
    bufp->fullBit(oldp+85,(((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                             >> 0xfU) & (IData)(vlSelf->ysyx_23060219_top__DOT__w_wbu_npc_wen))));
    bufp->fullIData(oldp+86,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_reg),32);
    bufp->fullIData(oldp+87,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1),32);
    bufp->fullIData(oldp+88,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs2),32);
    bufp->fullIData(oldp+89,(vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src),32);
    bufp->fullIData(oldp+90,(((0x800000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                               ? vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mepc
                               : ((0x400000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                                   ? vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mtvec
                                   : 0xdead005aU))),32);
    bufp->fullIData(oldp+91,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__pc_jorb),32);
    bufp->fullIData(oldp+92,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_t1),32);
    bufp->fullIData(oldp+93,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_t2),32);
    __Vtemp_hdef3b0b3__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(
                                                          (0xfffffffeU 
                                                           & (((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                                                                << 7U) 
                                                               | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                                                  >> 0x19U)) 
                                                              + 
                                                              ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                                                << 7U) 
                                                               | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                                                  >> 0x19U))))))));
    __Vtemp_hdef3b0b3__0[1U] = (((((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                                    << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                              >> 0x19U)) 
                                  + ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                      << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                                >> 0x19U))) 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(
                                                                      (0xfffffffeU 
                                                                       & (((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                                                                            << 7U) 
                                                                           | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                                                              >> 0x19U)) 
                                                                          + 
                                                                          ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                                                            << 7U) 
                                                                           | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                                                              >> 0x19U))))))) 
                                                   >> 0x20U)));
    __Vtemp_hdef3b0b3__0[2U] = ((((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                                   << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                             >> 0x19U)) 
                                 + ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                     << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                               >> 0x19U))) 
                                >> 0x1fU);
    bufp->fullWData(oldp+94,(__Vtemp_hdef3b0b3__0),66);
    bufp->fullQData(oldp+97,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+99,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+101,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+102,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+103,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+104,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+105,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT____Vcellinp__mux2____pinNumber2));
    __Vtemp_hc0107ab8__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__pc_jorb))));
    __Vtemp_hc0107ab8__0[1U] = ((((IData)(4U) + ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                                  << 7U) 
                                                 | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                                    >> 0x19U))) 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__pc_jorb))) 
                                                   >> 0x20U)));
    __Vtemp_hc0107ab8__0[2U] = (((IData)(4U) + ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                                 << 7U) 
                                                | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                                   >> 0x19U))) 
                                >> 0x1fU);
    bufp->fullWData(oldp+106,(__Vtemp_hc0107ab8__0),66);
    bufp->fullQData(oldp+109,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+111,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+113,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+114,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+115,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+116,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__hit));
    __Vtemp_heed9c555__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(
                                                          ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                                            << 0xaU) 
                                                           | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                                              >> 0x16U))))));
    __Vtemp_heed9c555__0[1U] = ((vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_t1 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(
                                                                      ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                                                        << 0xaU) 
                                                                       | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                                                          >> 0x16U))))) 
                                                   >> 0x20U)));
    __Vtemp_heed9c555__0[2U] = (vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_t1 
                                >> 0x1fU);
    bufp->fullWData(oldp+117,(__Vtemp_heed9c555__0),66);
    bufp->fullQData(oldp+120,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+122,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+124,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+125,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+126,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+127,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+128,(vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mstatus),32);
    bufp->fullIData(oldp+129,(vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mtvec),32);
    bufp->fullIData(oldp+130,(vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mepc),32);
    bufp->fullIData(oldp+131,(vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mcause),32);
    bufp->fullIData(oldp+132,(((0x1000000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                                ? vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src
                                : vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_alu_res)),32);
    bufp->fullBit(oldp+133,((1U & ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                    >> 6U) & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_alu_res))));
    bufp->fullIData(oldp+134,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_csr_rd),32);
    bufp->fullIData(oldp+135,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_alu_res),32);
    bufp->fullIData(oldp+136,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num1),32);
    bufp->fullIData(oldp+137,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2),32);
    bufp->fullIData(oldp+138,(((IData)(1U) + (~ vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2))),32);
    bufp->fullBit(oldp+139,(((~ (IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__post_valid_reg)) 
                             & (IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__post_valid_reg))));
    bufp->fullWData(oldp+140,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg),253);
    __Vtemp_h37e5707f__0[0U] = (IData)((0x300000000ULL 
                                        | (QData)((IData)(
                                                          ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                            << 0x17U) 
                                                           | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                              >> 9U))))));
    __Vtemp_h37e5707f__0[1U] = ((0xfffffffcU & ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                 << 0x19U) 
                                                | (0x1fffffcU 
                                                   & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                      >> 7U)))) 
                                | (IData)(((0x300000000ULL 
                                            | (QData)((IData)(
                                                              ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                                << 0x17U) 
                                                               | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                                  >> 9U))))) 
                                           >> 0x20U)));
    __Vtemp_h37e5707f__0[2U] = (8U | ((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1 
                                       << 4U) | (3U 
                                                 & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                    >> 7U))));
    __Vtemp_h37e5707f__0[3U] = (0x10U | ((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1 
                                          << 6U) | 
                                         (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1 
                                          >> 0x1cU)));
    __Vtemp_h37e5707f__0[4U] = (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1 
                                >> 0x1aU);
    bufp->fullWData(oldp+148,(__Vtemp_h37e5707f__0),136);
    bufp->fullQData(oldp+153,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[0]),34);
    bufp->fullQData(oldp+155,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[1]),34);
    bufp->fullQData(oldp+157,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[2]),34);
    bufp->fullQData(oldp+159,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[3]),34);
    bufp->fullIData(oldp+161,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+162,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+163,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+164,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+165,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+166,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__hit));
    __Vtemp_h56ffa0b7__0[0U] = 4U;
    __Vtemp_h56ffa0b7__0[1U] = (3U | (0xfffffffcU & 
                                      ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                        << 0x14U) | 
                                       (0xffffcU & 
                                        (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                         >> 0xcU)))));
    __Vtemp_h56ffa0b7__0[2U] = (8U | ((0xfffffff0U 
                                       & ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                           << 0x16U) 
                                          | (0x3ffff0U 
                                             & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                >> 0xaU)))) 
                                      | (3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                               >> 0xcU))));
    __Vtemp_h56ffa0b7__0[3U] = (0x10U | ((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs2 
                                          << 6U) | 
                                         (0xfU & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                                  >> 0xaU))));
    __Vtemp_h56ffa0b7__0[4U] = (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs2 
                                >> 0x1aU);
    bufp->fullWData(oldp+167,(__Vtemp_h56ffa0b7__0),136);
    bufp->fullQData(oldp+172,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[0]),34);
    bufp->fullQData(oldp+174,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[1]),34);
    bufp->fullQData(oldp+176,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[2]),34);
    bufp->fullQData(oldp+178,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[3]),34);
    bufp->fullIData(oldp+180,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+181,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+182,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+183,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+184,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+185,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__hit));
    __Vtemp_h8324a3cc__0[0U] = (IData)((0x300000000ULL 
                                        | (QData)((IData)(
                                                          ((~ vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src) 
                                                           & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1)))));
    __Vtemp_h8324a3cc__0[1U] = (((vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src 
                                  | vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1) 
                                 << 2U) | (IData)((
                                                   (0x300000000ULL 
                                                    | (QData)((IData)(
                                                                      ((~ vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src) 
                                                                       & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1)))) 
                                                   >> 0x20U)));
    __Vtemp_h8324a3cc__0[2U] = (8U | ((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1 
                                       << 4U) | ((vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src 
                                                  | vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1) 
                                                 >> 0x1eU)));
    __Vtemp_h8324a3cc__0[3U] = (0x10U | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1 
                                         >> 0x1cU));
    __Vtemp_h8324a3cc__0[4U] = 0U;
    bufp->fullWData(oldp+186,(__Vtemp_h8324a3cc__0),136);
    bufp->fullQData(oldp+191,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[0]),34);
    bufp->fullQData(oldp+193,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[1]),34);
    bufp->fullQData(oldp+195,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[2]),34);
    bufp->fullQData(oldp+197,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[3]),34);
    bufp->fullIData(oldp+199,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+200,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+201,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+202,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+203,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+204,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+205,(((IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_is_ecall)
                                ? 0xfU : ((0x37U == 
                                           (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))
                                           ? 0U : (0x1fU 
                                                   & (IData)(
                                                             (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                              >> 0xfU)))))),5);
    bufp->fullCData(oldp+206,((0x1fU & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                >> 0x14U)))),5);
    bufp->fullSData(oldp+207,((0xfffU & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                 >> 0x14U)))),12);
    bufp->fullBit(oldp+208,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_ren));
    bufp->fullBit(oldp+209,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_is_mret));
    bufp->fullBit(oldp+210,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_is_ecall));
    bufp->fullCData(oldp+211,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_type),2);
    bufp->fullCData(oldp+212,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_alu_type),4);
    bufp->fullCData(oldp+213,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_num_sel),2);
    bufp->fullIData(oldp+214,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_imm),32);
    bufp->fullBit(oldp+215,((3U == (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
    bufp->fullBit(oldp+216,((0x23U == (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
    bufp->fullCData(oldp+217,((7U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                             >> 0xcU)))),3);
    bufp->fullBit(oldp+218,((0x6fU == (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
    bufp->fullBit(oldp+219,((0x67U == (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
    bufp->fullBit(oldp+220,((0x63U == (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
    bufp->fullCData(oldp+221,((0x1fU & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                >> 7U)))),5);
    bufp->fullBit(oldp+222,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_gpr_wen));
    bufp->fullCData(oldp+223,((0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))),7);
    bufp->fullCData(oldp+224,((0x1fU & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                >> 0xfU)))),5);
    bufp->fullCData(oldp+225,((0x7fU & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                >> 0x19U)))),7);
    bufp->fullBit(oldp+226,((1U & ((~ (IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__post_valid_reg)) 
                                   & (~ (IData)(vlSelf->ysyx_23060219_top__DOT__w_wbu_cycle_end))))));
    bufp->fullWData(oldp+227,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg),111);
    bufp->fullIData(oldp+231,(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_inst),32);
    bufp->fullQData(oldp+232,(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg),64);
    bufp->fullBit(oldp+234,((IData)((0U != (0xc00000U 
                                            & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U])))));
    bufp->fullIData(oldp+235,(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata_t),32);
    bufp->fullIData(oldp+236,(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata),32);
    bufp->fullCData(oldp+237,(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__wmask),8);
    bufp->fullBit(oldp+238,(((~ (IData)(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg)) 
                             & (IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__post_valid_reg))));
    bufp->fullWData(oldp+239,(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg),185);
    bufp->fullIData(oldp+245,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__i),32);
    bufp->fullIData(oldp+246,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0]),32);
    bufp->fullIData(oldp+247,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[1]),32);
    bufp->fullIData(oldp+248,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[2]),32);
    bufp->fullIData(oldp+249,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[3]),32);
    bufp->fullIData(oldp+250,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[4]),32);
    bufp->fullIData(oldp+251,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[5]),32);
    bufp->fullIData(oldp+252,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[6]),32);
    bufp->fullIData(oldp+253,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[7]),32);
    bufp->fullIData(oldp+254,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[8]),32);
    bufp->fullIData(oldp+255,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[9]),32);
    bufp->fullIData(oldp+256,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[10]),32);
    bufp->fullIData(oldp+257,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[11]),32);
    bufp->fullIData(oldp+258,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[12]),32);
    bufp->fullIData(oldp+259,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[13]),32);
    bufp->fullIData(oldp+260,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[14]),32);
    bufp->fullIData(oldp+261,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[15]),32);
    bufp->fullIData(oldp+262,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[16]),32);
    bufp->fullIData(oldp+263,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[17]),32);
    bufp->fullIData(oldp+264,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[18]),32);
    bufp->fullIData(oldp+265,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[19]),32);
    bufp->fullIData(oldp+266,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[20]),32);
    bufp->fullIData(oldp+267,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[21]),32);
    bufp->fullIData(oldp+268,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[22]),32);
    bufp->fullIData(oldp+269,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[23]),32);
    bufp->fullIData(oldp+270,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[24]),32);
    bufp->fullIData(oldp+271,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[25]),32);
    bufp->fullIData(oldp+272,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[26]),32);
    bufp->fullIData(oldp+273,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[27]),32);
    bufp->fullIData(oldp+274,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[28]),32);
    bufp->fullIData(oldp+275,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[29]),32);
    bufp->fullIData(oldp+276,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[30]),32);
    bufp->fullIData(oldp+277,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[31]),32);
    bufp->fullBit(oldp+278,(vlSelf->ysyx_23060219_top__DOT__wbu_inst__DOT__pre_valid_reg));
    bufp->fullBit(oldp+279,(vlSelf->clk));
    bufp->fullBit(oldp+280,(vlSelf->rst));
    bufp->fullIData(oldp+281,(0xfffffffeU),32);
    bufp->fullIData(oldp+282,(2U),32);
    bufp->fullIData(oldp+283,(1U),32);
    bufp->fullIData(oldp+284,(0x20U),32);
    bufp->fullIData(oldp+285,(0U),32);
    bufp->fullIData(oldp+286,(0U),32);
    bufp->fullIData(oldp+287,(0x21U),32);
    bufp->fullIData(oldp+288,(2U),32);
    bufp->fullIData(oldp+289,(4U),32);
    bufp->fullIData(oldp+290,(0x22U),32);
    bufp->fullIData(oldp+291,(4U),32);
    bufp->fullIData(oldp+292,(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_rd),32);
}
