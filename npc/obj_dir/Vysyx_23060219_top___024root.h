// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_23060219_top.h for the primary calling header

#ifndef VERILATED_VYSYX_23060219_TOP___024ROOT_H_
#define VERILATED_VYSYX_23060219_TOP___024ROOT_H_  // guard

#include "verilated.h"

class Vysyx_23060219_top__Syms;

class Vysyx_23060219_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        CData/*2:0*/ ysyx_23060219_top__DOT__clk_cnt;
        CData/*0:0*/ ysyx_23060219_top__DOT__w_wbu_cycle_end;
        CData/*0:0*/ ysyx_23060219_top__DOT__w_wbu_npc_wen;
        CData/*0:0*/ ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_ren;
        CData/*0:0*/ ysyx_23060219_top__DOT__idu_inst__DOT__idu_is_mret;
        CData/*0:0*/ ysyx_23060219_top__DOT__idu_inst__DOT__idu_is_ecall;
        CData/*1:0*/ ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_type;
        CData/*3:0*/ ysyx_23060219_top__DOT__idu_inst__DOT__idu_alu_type;
        CData/*1:0*/ ysyx_23060219_top__DOT__idu_inst__DOT__idu_num_sel;
        CData/*0:0*/ ysyx_23060219_top__DOT__idu_inst__DOT__idu_gpr_wen;
        CData/*0:0*/ ysyx_23060219_top__DOT__idu_inst__DOT__post_valid_reg;
        CData/*0:0*/ ysyx_23060219_top__DOT__exu_inst__DOT__post_valid_reg;
        CData/*0:0*/ ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__hit;
        CData/*0:0*/ ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__hit;
        CData/*0:0*/ ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__hit;
        CData/*7:0*/ ysyx_23060219_top__DOT__lsu_inst__DOT__wmask;
        CData/*0:0*/ ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg;
        CData/*0:0*/ ysyx_23060219_top__DOT__wbu_inst__DOT__pre_valid_reg;
        CData/*0:0*/ ysyx_23060219_top__DOT__bru_inst__DOT____Vcellinp__mux2____pinNumber2;
        CData/*0:0*/ ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__hit;
        CData/*0:0*/ ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__hit;
        CData/*0:0*/ ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__hit;
        CData/*0:0*/ __Vtrigrprev__TOP__clk;
        CData/*0:0*/ __VactContinue;
        IData/*31:0*/ ysyx_23060219_top__DOT__w_cc_csr_src;
        IData/*31:0*/ ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_inst;
        IData/*31:0*/ ysyx_23060219_top__DOT__idu_inst__DOT__idu_imm;
        VlWide<4>/*110:0*/ ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg;
        IData/*31:0*/ ysyx_23060219_top__DOT__idu_inst__DOT____VdfgExtracted_ha4c8ba42__0;
        IData/*31:0*/ ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1;
        IData/*31:0*/ ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs2;
        IData/*31:0*/ ysyx_23060219_top__DOT__exu_inst__DOT__exu_csr_rd;
        IData/*31:0*/ ysyx_23060219_top__DOT__exu_inst__DOT__exu_alu_res;
        IData/*31:0*/ ysyx_23060219_top__DOT__exu_inst__DOT__num1;
        IData/*31:0*/ ysyx_23060219_top__DOT__exu_inst__DOT__num2;
        VlWide<8>/*252:0*/ ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg;
        IData/*31:0*/ ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__lut_out;
        IData/*31:0*/ ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__lut_out;
        IData/*31:0*/ ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__lut_out;
        IData/*31:0*/ ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_rd;
        IData/*31:0*/ ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata_t;
        IData/*31:0*/ ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata;
        VlWide<6>/*184:0*/ ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg;
        IData/*31:0*/ ysyx_23060219_top__DOT__bru_inst__DOT__pc_jorb;
        IData/*31:0*/ ysyx_23060219_top__DOT__bru_inst__DOT__npc_t1;
        IData/*31:0*/ ysyx_23060219_top__DOT__bru_inst__DOT__npc_t2;
        IData/*31:0*/ ysyx_23060219_top__DOT__bru_inst__DOT__npc_reg;
        IData/*31:0*/ ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__lut_out;
        IData/*31:0*/ ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__lut_out;
        IData/*31:0*/ ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__lut_out;
        IData/*31:0*/ ysyx_23060219_top__DOT__register_file_inst__DOT__i;
        IData/*31:0*/ ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mstatus;
        IData/*31:0*/ ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mtvec;
        IData/*31:0*/ ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mepc;
        IData/*31:0*/ ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mcause;
        IData/*31:0*/ __Vfunc_ysyx_23060219_top__DOT__ifu_inst__DOT__imem_read__0__Vfuncout;
        IData/*31:0*/ __VstlIterCount;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg;
        VlUnpacked<QData/*33:0*/, 4> ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*1:0*/, 4> ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 4> ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list;
    };
    struct {
        VlUnpacked<QData/*33:0*/, 4> ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*1:0*/, 4> ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 4> ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list;
        VlUnpacked<QData/*33:0*/, 4> ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*1:0*/, 4> ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 4> ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list;
        VlUnpacked<QData/*32:0*/, 2> ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*0:0*/, 2> ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 2> ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__data_list;
        VlUnpacked<QData/*32:0*/, 2> ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*0:0*/, 2> ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 2> ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__data_list;
        VlUnpacked<QData/*32:0*/, 2> ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*0:0*/, 2> ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 2> ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__data_list;
        VlUnpacked<IData/*31:0*/, 32> ysyx_23060219_top__DOT__register_file_inst__DOT__regs;
        VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vysyx_23060219_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vysyx_23060219_top___024root(Vysyx_23060219_top__Syms* symsp, const char* v__name);
    ~Vysyx_23060219_top___024root();
    VL_UNCOPYABLE(Vysyx_23060219_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
