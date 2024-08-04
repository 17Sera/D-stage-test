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
        CData/*2:0*/ ysyx_23060219_top__DOT__IType;
        CData/*0:0*/ ysyx_23060219_top__DOT__reg_wen;
        CData/*0:0*/ ysyx_23060219_top__DOT__mem_wen;
        CData/*0:0*/ ysyx_23060219_top__DOT__mem_ren;
        CData/*7:0*/ ysyx_23060219_top__DOT__wmask;
        CData/*2:0*/ ysyx_23060219_top__DOT__rmask;
        CData/*0:0*/ ysyx_23060219_top__DOT__m1;
        CData/*0:0*/ ysyx_23060219_top__DOT__m2;
        CData/*0:0*/ ysyx_23060219_top__DOT__m3;
        CData/*0:0*/ ysyx_23060219_top__DOT__m4;
        CData/*1:0*/ ysyx_23060219_top__DOT__m5;
        CData/*4:0*/ ysyx_23060219_top__DOT__aluc;
        CData/*0:0*/ ysyx_23060219_top__DOT__PC_inst__DOT____Vcellinp__i1____pinNumber2;
        CData/*0:0*/ ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__hit;
        CData/*0:0*/ ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__hit;
        CData/*0:0*/ ysyx_23060219_top__DOT__i3__DOT__i0__DOT__hit;
        CData/*0:0*/ ysyx_23060219_top__DOT__i4__DOT__i0__DOT__hit;
        CData/*0:0*/ ysyx_23060219_top__DOT__i5__DOT__i0__DOT__hit;
        CData/*0:0*/ __Vtrigrprev__TOP__clk;
        CData/*0:0*/ __VactContinue;
        SData/*11:0*/ ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12;
        IData/*31:0*/ ysyx_23060219_top__DOT__inst;
        IData/*31:0*/ ysyx_23060219_top__DOT__pc;
        IData/*31:0*/ ysyx_23060219_top__DOT__result;
        IData/*31:0*/ ysyx_23060219_top__DOT__reg_in;
        IData/*31:0*/ ysyx_23060219_top__DOT__src1;
        IData/*31:0*/ ysyx_23060219_top__DOT__src2;
        IData/*31:0*/ ysyx_23060219_top__DOT__imm32;
        IData/*31:0*/ ysyx_23060219_top__DOT__num1;
        IData/*31:0*/ ysyx_23060219_top__DOT__num2;
        IData/*31:0*/ ysyx_23060219_top__DOT__mem_rdata;
        IData/*31:0*/ ysyx_23060219_top__DOT__PC_inst__DOT__npc;
        IData/*31:0*/ ysyx_23060219_top__DOT__PC_inst__DOT__npc_temp;
        IData/*31:0*/ ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__lut_out;
        IData/*31:0*/ ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__lut_out;
        IData/*31:0*/ ysyx_23060219_top__DOT__mem_inst__DOT__rdata_temp;
        IData/*31:0*/ ysyx_23060219_top__DOT__register_file_inst__DOT__i;
        IData/*19:0*/ ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_20;
        IData/*31:0*/ ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12_to_32;
        IData/*31:0*/ ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_20_to_32;
        IData/*31:0*/ ysyx_23060219_top__DOT__i3__DOT__i0__DOT__lut_out;
        IData/*31:0*/ ysyx_23060219_top__DOT__i4__DOT__i0__DOT__lut_out;
        IData/*31:0*/ ysyx_23060219_top__DOT__i5__DOT__i0__DOT__lut_out;
        IData/*31:0*/ __Vfunc_ysyx_23060219_top__DOT__mem_inst__DOT__pmem_read__0__Vfuncout;
        IData/*31:0*/ __Vfunc_ysyx_23060219_top__DOT__mem_inst__DOT__pmem_read__2__Vfuncout;
        IData/*31:0*/ __VstlIterCount;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<QData/*32:0*/, 2> ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*0:0*/, 2> ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 2> ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__data_list;
        VlUnpacked<QData/*32:0*/, 2> ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*0:0*/, 2> ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 2> ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list;
        VlUnpacked<IData/*31:0*/, 32> ysyx_23060219_top__DOT__register_file_inst__DOT__regs;
        VlUnpacked<QData/*32:0*/, 2> ysyx_23060219_top__DOT__i3__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*0:0*/, 2> ysyx_23060219_top__DOT__i3__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 2> ysyx_23060219_top__DOT__i3__DOT__i0__DOT__data_list;
        VlUnpacked<QData/*32:0*/, 2> ysyx_23060219_top__DOT__i4__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*0:0*/, 2> ysyx_23060219_top__DOT__i4__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 2> ysyx_23060219_top__DOT__i4__DOT__i0__DOT__data_list;
        VlUnpacked<QData/*33:0*/, 4> ysyx_23060219_top__DOT__i5__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*1:0*/, 4> ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list;
    };
    struct {
        VlUnpacked<IData/*31:0*/, 4> ysyx_23060219_top__DOT__i5__DOT__i0__DOT__data_list;
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
