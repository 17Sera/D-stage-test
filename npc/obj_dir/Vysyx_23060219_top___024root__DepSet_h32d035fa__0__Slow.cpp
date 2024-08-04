// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_23060219_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_23060219_top___024root.h"

VL_ATTR_COLD void Vysyx_23060219_top___024root___eval_static(Vysyx_23060219_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vysyx_23060219_top___024root___eval_initial__TOP(Vysyx_23060219_top___024root* vlSelf);

VL_ATTR_COLD void Vysyx_23060219_top___024root___eval_initial(Vysyx_23060219_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root___eval_initial\n"); );
    // Body
    Vysyx_23060219_top___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vysyx_23060219_top___024root___eval_initial__TOP(Vysyx_23060219_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list[0U] = 1U;
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list[1U] = 0U;
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list[0U] = 1U;
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list[1U] = 0U;
    vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__key_list[0U] = 1U;
    vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__key_list[1U] = 0U;
    vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__key_list[0U] = 1U;
    vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__key_list[1U] = 0U;
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list[0U] = 3U;
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list[1U] = 2U;
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list[2U] = 1U;
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list[3U] = 0U;
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__data_list[0U] = 0xdeadbeafU;
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__pair_list[0U] = 0x3deadbeafULL;
}

VL_ATTR_COLD void Vysyx_23060219_top___024root___eval_final(Vysyx_23060219_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vysyx_23060219_top___024root___eval_triggers__stl(Vysyx_23060219_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060219_top___024root___dump_triggers__stl(Vysyx_23060219_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vysyx_23060219_top___024root___eval_stl(Vysyx_23060219_top___024root* vlSelf);

VL_ATTR_COLD void Vysyx_23060219_top___024root___eval_settle(Vysyx_23060219_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vysyx_23060219_top___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vysyx_23060219_top___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_top.v", 48, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vysyx_23060219_top___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060219_top___024root___dump_triggers__stl(Vysyx_23060219_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn);
void Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(IData/*31:0*/ station, IData/*31:0*/ inst, CData/*7:0*/ unit);
void Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask);

VL_ATTR_COLD void Vysyx_23060219_top___024root___stl_sequent__TOP__0(Vysyx_23060219_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(((IData)(4U) + vlSelf->ysyx_23060219_top__DOT__pc)));
    vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__pc));
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__pair_list[3U] 
        = (QData)((IData)(((IData)(4U) + vlSelf->ysyx_23060219_top__DOT__pc)));
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__data_list[3U] 
        = ((IData)(4U) + vlSelf->ysyx_23060219_top__DOT__pc);
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list[1U] 
        = ((IData)(4U) + vlSelf->ysyx_23060219_top__DOT__pc);
    vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__data_list[1U] 
        = vlSelf->ysyx_23060219_top__DOT__pc;
    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__pmem_read_TOP(vlSelf->ysyx_23060219_top__DOT__pc, vlSelf->__Vfunc_ysyx_23060219_top__DOT__mem_inst__DOT__pmem_read__0__Vfuncout);
    vlSelf->ysyx_23060219_top__DOT__inst = vlSelf->__Vfunc_ysyx_23060219_top__DOT__mem_inst__DOT__pmem_read__0__Vfuncout;
    if ((0U == (0x1fU & (vlSelf->ysyx_23060219_top__DOT__inst 
                         >> 0xfU)))) {
        vlSelf->ysyx_23060219_top__DOT__src1 = 0U;
        vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__data_list[0U] = 0U;
    } else {
        vlSelf->ysyx_23060219_top__DOT__src1 = vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs
            [(0x1fU & (vlSelf->ysyx_23060219_top__DOT__inst 
                       >> 0xfU))];
        vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__data_list[0U] 
            = vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs
            [(0x1fU & (vlSelf->ysyx_23060219_top__DOT__inst 
                       >> 0xfU))];
    }
    if ((0U == (0x1fU & (vlSelf->ysyx_23060219_top__DOT__inst 
                         >> 0x14U)))) {
        vlSelf->ysyx_23060219_top__DOT__src2 = 0U;
        vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__data_list[1U] = 0U;
    } else {
        vlSelf->ysyx_23060219_top__DOT__src2 = vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs
            [(0x1fU & (vlSelf->ysyx_23060219_top__DOT__inst 
                       >> 0x14U))];
        vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__data_list[1U] 
            = vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs
            [(0x1fU & (vlSelf->ysyx_23060219_top__DOT__inst 
                       >> 0x14U))];
    }
    if ((0x40U & vlSelf->ysyx_23060219_top__DOT__inst)) {
        if ((0x20U & vlSelf->ysyx_23060219_top__DOT__inst)) {
            if ((0x10U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                if ((8U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
                } else if ((4U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
                } else if ((2U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                    if ((1U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                        if ((1U == (vlSelf->ysyx_23060219_top__DOT__inst 
                                    >> 0x14U))) {
                            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(1U, vlSelf->ysyx_23060219_top__DOT__inst, 0xaU);
                        } else {
                            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xbU);
                        }
                    } else {
                        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
                    }
                } else {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
                }
            } else if ((8U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                if ((4U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                    if ((2U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                        if ((1U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                            vlSelf->ysyx_23060219_top__DOT__IType = 6U;
                            vlSelf->ysyx_23060219_top__DOT__aluc = 0U;
                            vlSelf->ysyx_23060219_top__DOT__reg_wen = 1U;
                            vlSelf->ysyx_23060219_top__DOT__mem_wen = 0U;
                            vlSelf->ysyx_23060219_top__DOT__mem_ren = 0U;
                            vlSelf->ysyx_23060219_top__DOT__wmask = 0xfU;
                            vlSelf->ysyx_23060219_top__DOT__rmask = 0U;
                            vlSelf->ysyx_23060219_top__DOT__m1 = 0U;
                            vlSelf->ysyx_23060219_top__DOT__m2 = 1U;
                            vlSelf->ysyx_23060219_top__DOT__m3 = 1U;
                            vlSelf->ysyx_23060219_top__DOT__m4 = 0U;
                            vlSelf->ysyx_23060219_top__DOT__m5 = 0U;
                        } else {
                            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
                        }
                    } else {
                        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
                    }
                } else {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
                }
            } else if ((4U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                if ((2U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                    if ((1U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                        vlSelf->ysyx_23060219_top__DOT__IType = 2U;
                        vlSelf->ysyx_23060219_top__DOT__aluc = 0xfU;
                        vlSelf->ysyx_23060219_top__DOT__reg_wen = 1U;
                        vlSelf->ysyx_23060219_top__DOT__mem_wen = 0U;
                        vlSelf->ysyx_23060219_top__DOT__mem_ren = 0U;
                        vlSelf->ysyx_23060219_top__DOT__wmask = 0xfU;
                        vlSelf->ysyx_23060219_top__DOT__rmask = 0U;
                        vlSelf->ysyx_23060219_top__DOT__m1 = 0U;
                        vlSelf->ysyx_23060219_top__DOT__m2 = 1U;
                        vlSelf->ysyx_23060219_top__DOT__m3 = 1U;
                        vlSelf->ysyx_23060219_top__DOT__m4 = 1U;
                        vlSelf->ysyx_23060219_top__DOT__m5 = 0U;
                    } else {
                        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
                    }
                } else {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
                }
            } else if ((2U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                if ((1U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                    vlSelf->ysyx_23060219_top__DOT__IType = 5U;
                    vlSelf->ysyx_23060219_top__DOT__reg_wen = 0U;
                    vlSelf->ysyx_23060219_top__DOT__mem_wen = 0U;
                    vlSelf->ysyx_23060219_top__DOT__mem_ren = 0U;
                    vlSelf->ysyx_23060219_top__DOT__wmask = 0xfU;
                    vlSelf->ysyx_23060219_top__DOT__rmask = 0U;
                    vlSelf->ysyx_23060219_top__DOT__m1 = 1U;
                    vlSelf->ysyx_23060219_top__DOT__m2 = 0U;
                    vlSelf->ysyx_23060219_top__DOT__m3 = 0U;
                    vlSelf->ysyx_23060219_top__DOT__m4 = 1U;
                    vlSelf->ysyx_23060219_top__DOT__m5 = 2U;
                    if ((0x4000U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                        vlSelf->ysyx_23060219_top__DOT__aluc 
                            = ((0x2000U & vlSelf->ysyx_23060219_top__DOT__inst)
                                ? ((0x1000U & vlSelf->ysyx_23060219_top__DOT__inst)
                                    ? 0xdU : 0xcU) : 
                               ((0x1000U & vlSelf->ysyx_23060219_top__DOT__inst)
                                 ? 0xbU : 0xaU));
                    } else if ((0x2000U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 9U);
                    } else {
                        vlSelf->ysyx_23060219_top__DOT__aluc 
                            = ((0x1000U & vlSelf->ysyx_23060219_top__DOT__inst)
                                ? 9U : 8U);
                    }
                } else {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
                }
            } else {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
            }
        } else {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
        }
    } else if ((0x20U & vlSelf->ysyx_23060219_top__DOT__inst)) {
        if ((0x10U & vlSelf->ysyx_23060219_top__DOT__inst)) {
            if ((8U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
            } else if ((4U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                if ((2U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                    if ((1U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                        vlSelf->ysyx_23060219_top__DOT__IType = 4U;
                        vlSelf->ysyx_23060219_top__DOT__aluc = 0xeU;
                        vlSelf->ysyx_23060219_top__DOT__reg_wen = 1U;
                        vlSelf->ysyx_23060219_top__DOT__mem_wen = 0U;
                        vlSelf->ysyx_23060219_top__DOT__mem_ren = 0U;
                        vlSelf->ysyx_23060219_top__DOT__wmask = 0xfU;
                        vlSelf->ysyx_23060219_top__DOT__rmask = 0U;
                        vlSelf->ysyx_23060219_top__DOT__m1 = 0U;
                        vlSelf->ysyx_23060219_top__DOT__m2 = 0U;
                        vlSelf->ysyx_23060219_top__DOT__m3 = 1U;
                        vlSelf->ysyx_23060219_top__DOT__m4 = 1U;
                        vlSelf->ysyx_23060219_top__DOT__m5 = 2U;
                    } else {
                        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
                    }
                } else {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
                }
            } else if ((2U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                if ((1U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                    vlSelf->ysyx_23060219_top__DOT__IType = 1U;
                    vlSelf->ysyx_23060219_top__DOT__reg_wen = 1U;
                    vlSelf->ysyx_23060219_top__DOT__mem_wen = 0U;
                    vlSelf->ysyx_23060219_top__DOT__mem_ren = 0U;
                    vlSelf->ysyx_23060219_top__DOT__wmask = 0xfU;
                    vlSelf->ysyx_23060219_top__DOT__rmask = 0U;
                    vlSelf->ysyx_23060219_top__DOT__m1 = 0U;
                    vlSelf->ysyx_23060219_top__DOT__m2 = 0U;
                    vlSelf->ysyx_23060219_top__DOT__m3 = 0U;
                    vlSelf->ysyx_23060219_top__DOT__m4 = 1U;
                    vlSelf->ysyx_23060219_top__DOT__m5 = 2U;
                    if ((0U == (vlSelf->ysyx_23060219_top__DOT__inst 
                                >> 0x19U))) {
                        vlSelf->ysyx_23060219_top__DOT__aluc 
                            = ((0x4000U & vlSelf->ysyx_23060219_top__DOT__inst)
                                ? ((0x2000U & vlSelf->ysyx_23060219_top__DOT__inst)
                                    ? ((0x1000U & vlSelf->ysyx_23060219_top__DOT__inst)
                                        ? 7U : 6U) : 
                                   ((0x1000U & vlSelf->ysyx_23060219_top__DOT__inst)
                                     ? 4U : 3U)) : 
                               ((0x2000U & vlSelf->ysyx_23060219_top__DOT__inst)
                                 ? ((0x1000U & vlSelf->ysyx_23060219_top__DOT__inst)
                                     ? 0xcU : 0xaU)
                                 : ((0x1000U & vlSelf->ysyx_23060219_top__DOT__inst)
                                     ? 2U : 0U)));
                    } else if ((0x20U == (vlSelf->ysyx_23060219_top__DOT__inst 
                                          >> 0x19U))) {
                        if ((0U == (7U & (vlSelf->ysyx_23060219_top__DOT__inst 
                                          >> 0xcU)))) {
                            vlSelf->ysyx_23060219_top__DOT__aluc = 1U;
                        } else if ((5U == (7U & (vlSelf->ysyx_23060219_top__DOT__inst 
                                                 >> 0xcU)))) {
                            vlSelf->ysyx_23060219_top__DOT__aluc = 5U;
                        } else {
                            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 3U);
                        }
                    } else {
                        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 4U);
                    }
                } else {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
                }
            } else {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
            }
        } else if ((8U & vlSelf->ysyx_23060219_top__DOT__inst)) {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
        } else if ((4U & vlSelf->ysyx_23060219_top__DOT__inst)) {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
        } else if ((2U & vlSelf->ysyx_23060219_top__DOT__inst)) {
            if ((1U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                vlSelf->ysyx_23060219_top__DOT__IType = 3U;
                vlSelf->ysyx_23060219_top__DOT__aluc = 0U;
                vlSelf->ysyx_23060219_top__DOT__reg_wen = 0U;
                vlSelf->ysyx_23060219_top__DOT__mem_wen = 1U;
                vlSelf->ysyx_23060219_top__DOT__mem_ren = 0U;
                vlSelf->ysyx_23060219_top__DOT__rmask = 0U;
                vlSelf->ysyx_23060219_top__DOT__m1 = 0U;
                vlSelf->ysyx_23060219_top__DOT__m2 = 0U;
                vlSelf->ysyx_23060219_top__DOT__m3 = 1U;
                vlSelf->ysyx_23060219_top__DOT__m4 = 1U;
                vlSelf->ysyx_23060219_top__DOT__m5 = 1U;
                if ((0U == (7U & (vlSelf->ysyx_23060219_top__DOT__inst 
                                  >> 0xcU)))) {
                    vlSelf->ysyx_23060219_top__DOT__wmask = 1U;
                } else if ((1U == (7U & (vlSelf->ysyx_23060219_top__DOT__inst 
                                         >> 0xcU)))) {
                    vlSelf->ysyx_23060219_top__DOT__wmask = 3U;
                } else if ((2U == (7U & (vlSelf->ysyx_23060219_top__DOT__inst 
                                         >> 0xcU)))) {
                    vlSelf->ysyx_23060219_top__DOT__wmask = 0xfU;
                } else {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 8U);
                }
            } else {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
            }
        } else {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
        }
    } else if ((0x10U & vlSelf->ysyx_23060219_top__DOT__inst)) {
        if ((8U & vlSelf->ysyx_23060219_top__DOT__inst)) {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
        } else if ((4U & vlSelf->ysyx_23060219_top__DOT__inst)) {
            if ((2U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                if ((1U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                    vlSelf->ysyx_23060219_top__DOT__IType = 4U;
                    vlSelf->ysyx_23060219_top__DOT__aluc = 0U;
                    vlSelf->ysyx_23060219_top__DOT__reg_wen = 1U;
                    vlSelf->ysyx_23060219_top__DOT__mem_wen = 0U;
                    vlSelf->ysyx_23060219_top__DOT__mem_ren = 0U;
                    vlSelf->ysyx_23060219_top__DOT__wmask = 0xfU;
                    vlSelf->ysyx_23060219_top__DOT__rmask = 0U;
                    vlSelf->ysyx_23060219_top__DOT__m1 = 0U;
                    vlSelf->ysyx_23060219_top__DOT__m2 = 0U;
                    vlSelf->ysyx_23060219_top__DOT__m3 = 1U;
                    vlSelf->ysyx_23060219_top__DOT__m4 = 0U;
                    vlSelf->ysyx_23060219_top__DOT__m5 = 2U;
                } else {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
                }
            } else {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
            }
        } else if ((2U & vlSelf->ysyx_23060219_top__DOT__inst)) {
            if ((1U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                vlSelf->ysyx_23060219_top__DOT__IType = 2U;
                vlSelf->ysyx_23060219_top__DOT__reg_wen = 1U;
                vlSelf->ysyx_23060219_top__DOT__mem_wen = 0U;
                vlSelf->ysyx_23060219_top__DOT__mem_ren = 0U;
                vlSelf->ysyx_23060219_top__DOT__wmask = 0xfU;
                vlSelf->ysyx_23060219_top__DOT__rmask = 0U;
                vlSelf->ysyx_23060219_top__DOT__m1 = 0U;
                vlSelf->ysyx_23060219_top__DOT__m2 = 0U;
                vlSelf->ysyx_23060219_top__DOT__m3 = 1U;
                vlSelf->ysyx_23060219_top__DOT__m4 = 1U;
                vlSelf->ysyx_23060219_top__DOT__m5 = 2U;
                if ((0x4000U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                    if ((0x2000U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                        if ((0x1000U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                            vlSelf->ysyx_23060219_top__DOT__aluc = 7U;
                        } else {
                            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 6U);
                        }
                    } else if ((0x1000U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                        if ((0U == (vlSelf->ysyx_23060219_top__DOT__inst 
                                    >> 0x19U))) {
                            vlSelf->ysyx_23060219_top__DOT__aluc = 4U;
                        } else if ((0x20U == (vlSelf->ysyx_23060219_top__DOT__inst 
                                              >> 0x19U))) {
                            vlSelf->ysyx_23060219_top__DOT__aluc = 5U;
                        } else {
                            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 5U);
                        }
                    } else {
                        vlSelf->ysyx_23060219_top__DOT__aluc = 3U;
                    }
                } else if ((0x2000U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                    if ((0x1000U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                        vlSelf->ysyx_23060219_top__DOT__aluc = 0xcU;
                    } else {
                        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 6U);
                    }
                } else {
                    vlSelf->ysyx_23060219_top__DOT__aluc 
                        = ((0x1000U & vlSelf->ysyx_23060219_top__DOT__inst)
                            ? 2U : 0U);
                }
            } else {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
            }
        } else {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
        }
    } else if ((8U & vlSelf->ysyx_23060219_top__DOT__inst)) {
        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
    } else if ((4U & vlSelf->ysyx_23060219_top__DOT__inst)) {
        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
    } else if ((2U & vlSelf->ysyx_23060219_top__DOT__inst)) {
        if ((1U & vlSelf->ysyx_23060219_top__DOT__inst)) {
            vlSelf->ysyx_23060219_top__DOT__IType = 2U;
            vlSelf->ysyx_23060219_top__DOT__aluc = 0U;
            vlSelf->ysyx_23060219_top__DOT__reg_wen = 1U;
            vlSelf->ysyx_23060219_top__DOT__mem_wen = 0U;
            vlSelf->ysyx_23060219_top__DOT__mem_ren = 1U;
            vlSelf->ysyx_23060219_top__DOT__wmask = 0xfU;
            vlSelf->ysyx_23060219_top__DOT__m1 = 0U;
            vlSelf->ysyx_23060219_top__DOT__m2 = 0U;
            vlSelf->ysyx_23060219_top__DOT__m3 = 1U;
            vlSelf->ysyx_23060219_top__DOT__m4 = 1U;
            vlSelf->ysyx_23060219_top__DOT__m5 = 1U;
            if ((0x4000U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                if ((0x2000U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 7U);
                } else {
                    vlSelf->ysyx_23060219_top__DOT__rmask 
                        = ((0x1000U & vlSelf->ysyx_23060219_top__DOT__inst)
                            ? 2U : 1U);
                }
            } else if ((0x2000U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                if ((0x1000U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 7U);
                } else {
                    vlSelf->ysyx_23060219_top__DOT__rmask = 0U;
                }
            } else if ((0x1000U & vlSelf->ysyx_23060219_top__DOT__inst)) {
                vlSelf->ysyx_23060219_top__DOT__rmask = 4U;
            } else {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 7U);
            }
        } else {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
        }
    } else {
        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->ysyx_23060219_top__DOT__inst, 0xcU);
    }
    vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__src1)));
    vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__src2));
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__m5) 
           == vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ysyx_23060219_top__DOT__m5) 
              == vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ysyx_23060219_top__DOT__m5) 
              == vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ysyx_23060219_top__DOT__m5) 
              == vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__m2) 
           == vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ysyx_23060219_top__DOT__m2) 
              == vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__m3) 
           == vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ysyx_23060219_top__DOT__m3) 
              == vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__m4) 
           == vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ysyx_23060219_top__DOT__m4) 
              == vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->ysyx_23060219_top__DOT__m4) 
                       == vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->ysyx_23060219_top__DOT__m4) 
                          == vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__num1 = vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__lut_out;
    if ((4U & (IData)(vlSelf->ysyx_23060219_top__DOT__IType))) {
        if ((2U & (IData)(vlSelf->ysyx_23060219_top__DOT__IType))) {
            if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__IType))) {
                vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12 = 0U;
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeafbeafU, 0xdU);
            } else {
                vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12 = 0U;
            }
        } else {
            vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12 
                = ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__IType))
                    ? ((0x800U & (vlSelf->ysyx_23060219_top__DOT__inst 
                                  >> 0x14U)) | ((0x400U 
                                                 & (vlSelf->ysyx_23060219_top__DOT__inst 
                                                    << 3U)) 
                                                | ((0x3f0U 
                                                    & (vlSelf->ysyx_23060219_top__DOT__inst 
                                                       >> 0x15U)) 
                                                   | (0xfU 
                                                      & (vlSelf->ysyx_23060219_top__DOT__inst 
                                                         >> 8U)))))
                    : 0U);
        }
    } else if ((2U & (IData)(vlSelf->ysyx_23060219_top__DOT__IType))) {
        vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12 
            = (0xfffU & ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__IType))
                          ? ((0xfe0U & (vlSelf->ysyx_23060219_top__DOT__inst 
                                        >> 0x14U)) 
                             | (0x1fU & (vlSelf->ysyx_23060219_top__DOT__inst 
                                         >> 7U))) : 
                         (vlSelf->ysyx_23060219_top__DOT__inst 
                          >> 0x14U)));
    } else if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__IType))) {
        vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12 = 0U;
    } else {
        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeafbeafU, 0xdU);
        vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12 = 0U;
    }
    if ((4U & (IData)(vlSelf->ysyx_23060219_top__DOT__IType))) {
        if ((2U & (IData)(vlSelf->ysyx_23060219_top__DOT__IType))) {
            if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__IType))) {
                vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_20 = 0U;
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeafbeafU, 0xeU);
            } else {
                vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_20 
                    = ((0x80000U & (vlSelf->ysyx_23060219_top__DOT__inst 
                                    >> 0xcU)) | ((0x7c000U 
                                                  & (vlSelf->ysyx_23060219_top__DOT__inst 
                                                     >> 1U)) 
                                                 | ((0x3800U 
                                                     & (vlSelf->ysyx_23060219_top__DOT__inst 
                                                        >> 1U)) 
                                                    | ((0x400U 
                                                        & (vlSelf->ysyx_23060219_top__DOT__inst 
                                                           >> 0xaU)) 
                                                       | (0x3ffU 
                                                          & (vlSelf->ysyx_23060219_top__DOT__inst 
                                                             >> 0x15U))))));
            }
        } else {
            vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_20 
                = ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__IType))
                    ? 0U : (vlSelf->ysyx_23060219_top__DOT__inst 
                            >> 0xcU));
        }
    } else if ((2U & (IData)(vlSelf->ysyx_23060219_top__DOT__IType))) {
        vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_20 = 0U;
    } else if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__IType))) {
        vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_20 = 0U;
    } else {
        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeafbeafU, 0xeU);
        vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_20 = 0U;
    }
    vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12_to_32 
        = (((- (IData)((1U & ((IData)(vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12) 
                              >> 0xbU)))) << 0xcU) 
           | (IData)(vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12));
    vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_20_to_32 
        = (((- (IData)((1U & (vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_20 
                              >> 0x13U)))) << 0x14U) 
           | vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_20);
    if ((4U & (IData)(vlSelf->ysyx_23060219_top__DOT__IType))) {
        if ((2U & (IData)(vlSelf->ysyx_23060219_top__DOT__IType))) {
            if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__IType))) {
                vlSelf->ysyx_23060219_top__DOT__imm32 = 0xdeafbeafU;
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeafbeafU, 0xfU);
            } else {
                vlSelf->ysyx_23060219_top__DOT__imm32 
                    = (vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_20_to_32 
                       << 1U);
            }
        } else {
            vlSelf->ysyx_23060219_top__DOT__imm32 = 
                ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__IType))
                  ? (vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12_to_32 
                     << 1U) : (vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_20_to_32 
                               << 0xcU));
        }
    } else if ((2U & (IData)(vlSelf->ysyx_23060219_top__DOT__IType))) {
        vlSelf->ysyx_23060219_top__DOT__imm32 = vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12_to_32;
    } else if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__IType))) {
        vlSelf->ysyx_23060219_top__DOT__imm32 = vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12_to_32;
    } else {
        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeafbeafU, 0xfU);
        vlSelf->ysyx_23060219_top__DOT__imm32 = 0xdeafbeafU;
    }
    vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__imm32)));
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)((vlSelf->ysyx_23060219_top__DOT__imm32 
                                             + vlSelf->ysyx_23060219_top__DOT__pc))));
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__data_list[0U] 
        = (vlSelf->ysyx_23060219_top__DOT__imm32 + vlSelf->ysyx_23060219_top__DOT__pc);
    vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__data_list[0U] 
        = vlSelf->ysyx_23060219_top__DOT__imm32;
    vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->ysyx_23060219_top__DOT__m3) 
                       == vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->ysyx_23060219_top__DOT__m3) 
                          == vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__num2 = vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__lut_out;
    if ((0x10U & (IData)(vlSelf->ysyx_23060219_top__DOT__aluc))) {
        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeafbeafU, 0U);
        vlSelf->ysyx_23060219_top__DOT__result = 0U;
    } else {
        vlSelf->ysyx_23060219_top__DOT__result = ((8U 
                                                   & (IData)(vlSelf->ysyx_23060219_top__DOT__aluc))
                                                   ? 
                                                  ((4U 
                                                    & (IData)(vlSelf->ysyx_23060219_top__DOT__aluc))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelf->ysyx_23060219_top__DOT__aluc))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_23060219_top__DOT__aluc))
                                                      ? 
                                                     (0xfffffffeU 
                                                      & (vlSelf->ysyx_23060219_top__DOT__num1 
                                                         + vlSelf->ysyx_23060219_top__DOT__num2))
                                                      : vlSelf->ysyx_23060219_top__DOT__num2)
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_23060219_top__DOT__aluc))
                                                      ? 
                                                     (vlSelf->ysyx_23060219_top__DOT__num1 
                                                      >= vlSelf->ysyx_23060219_top__DOT__num2)
                                                      : 
                                                     (vlSelf->ysyx_23060219_top__DOT__num1 
                                                      < vlSelf->ysyx_23060219_top__DOT__num2)))
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelf->ysyx_23060219_top__DOT__aluc))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_23060219_top__DOT__aluc))
                                                      ? 
                                                     VL_GTES_III(32, vlSelf->ysyx_23060219_top__DOT__num1, vlSelf->ysyx_23060219_top__DOT__num2)
                                                      : 
                                                     VL_LTS_III(32, vlSelf->ysyx_23060219_top__DOT__num1, vlSelf->ysyx_23060219_top__DOT__num2))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_23060219_top__DOT__aluc))
                                                      ? 
                                                     (vlSelf->ysyx_23060219_top__DOT__num1 
                                                      != vlSelf->ysyx_23060219_top__DOT__num2)
                                                      : 
                                                     (vlSelf->ysyx_23060219_top__DOT__num1 
                                                      == vlSelf->ysyx_23060219_top__DOT__num2))))
                                                   : 
                                                  ((4U 
                                                    & (IData)(vlSelf->ysyx_23060219_top__DOT__aluc))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelf->ysyx_23060219_top__DOT__aluc))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_23060219_top__DOT__aluc))
                                                      ? 
                                                     (vlSelf->ysyx_23060219_top__DOT__num1 
                                                      & vlSelf->ysyx_23060219_top__DOT__num2)
                                                      : 
                                                     (vlSelf->ysyx_23060219_top__DOT__num1 
                                                      | vlSelf->ysyx_23060219_top__DOT__num2))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_23060219_top__DOT__aluc))
                                                      ? 
                                                     ((0x1fU 
                                                       >= 
                                                       (0x1fU 
                                                        & vlSelf->ysyx_23060219_top__DOT__num2))
                                                       ? 
                                                      VL_SHIFTRS_III(32,32,32, vlSelf->ysyx_23060219_top__DOT__num1, 
                                                                     (0x1fU 
                                                                      & vlSelf->ysyx_23060219_top__DOT__num2))
                                                       : 
                                                      (- 
                                                       (vlSelf->ysyx_23060219_top__DOT__num1 
                                                        >> 0x1fU)))
                                                      : 
                                                     ((0x1fU 
                                                       >= 
                                                       (0x1fU 
                                                        & vlSelf->ysyx_23060219_top__DOT__num2))
                                                       ? 
                                                      (vlSelf->ysyx_23060219_top__DOT__num1 
                                                       >> 
                                                       (0x1fU 
                                                        & vlSelf->ysyx_23060219_top__DOT__num2))
                                                       : 0U)))
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelf->ysyx_23060219_top__DOT__aluc))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_23060219_top__DOT__aluc))
                                                      ? 
                                                     (vlSelf->ysyx_23060219_top__DOT__num1 
                                                      ^ vlSelf->ysyx_23060219_top__DOT__num2)
                                                      : 
                                                     ((0x1fU 
                                                       >= vlSelf->ysyx_23060219_top__DOT__num2)
                                                       ? 
                                                      (vlSelf->ysyx_23060219_top__DOT__num1 
                                                       << vlSelf->ysyx_23060219_top__DOT__num2)
                                                       : 0U))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_23060219_top__DOT__aluc))
                                                      ? 
                                                     ((IData)(1U) 
                                                      + 
                                                      (vlSelf->ysyx_23060219_top__DOT__num1 
                                                       + 
                                                       (~ vlSelf->ysyx_23060219_top__DOT__num2)))
                                                      : 
                                                     (vlSelf->ysyx_23060219_top__DOT__num1 
                                                      + vlSelf->ysyx_23060219_top__DOT__num2)))));
    }
    if (vlSelf->ysyx_23060219_top__DOT__mem_wen) {
        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__pmem_write_TOP(vlSelf->ysyx_23060219_top__DOT__result, vlSelf->ysyx_23060219_top__DOT__src2, (IData)(vlSelf->ysyx_23060219_top__DOT__wmask));
    }
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__result)));
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__pair_list[1U] 
        = (0x200000000ULL | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__result)));
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__data_list[1U] 
        = vlSelf->ysyx_23060219_top__DOT__result;
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT____Vcellinp__i1____pinNumber2 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__m1) 
           & vlSelf->ysyx_23060219_top__DOT__result);
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list[0U] 
        = vlSelf->ysyx_23060219_top__DOT__result;
    if (vlSelf->ysyx_23060219_top__DOT__mem_ren) {
        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__pmem_read_TOP(vlSelf->ysyx_23060219_top__DOT__result, vlSelf->__Vfunc_ysyx_23060219_top__DOT__mem_inst__DOT__pmem_read__2__Vfuncout);
        vlSelf->ysyx_23060219_top__DOT__mem_inst__DOT__rdata_temp 
            = vlSelf->__Vfunc_ysyx_23060219_top__DOT__mem_inst__DOT__pmem_read__2__Vfuncout;
    } else {
        vlSelf->ysyx_23060219_top__DOT__mem_inst__DOT__rdata_temp = 0xeaeU;
    }
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT____Vcellinp__i1____pinNumber2) 
           == vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT____Vcellinp__i1____pinNumber2) 
              == vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->ysyx_23060219_top__DOT__m2) 
                       == vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->ysyx_23060219_top__DOT__m2) 
                          == vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__npc_temp 
        = vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__lut_out;
    if ((4U & (IData)(vlSelf->ysyx_23060219_top__DOT__rmask))) {
        if ((2U & (IData)(vlSelf->ysyx_23060219_top__DOT__rmask))) {
            vlSelf->ysyx_23060219_top__DOT__mem_rdata = 0xdeadbeafU;
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeafbeafU, 1U);
        } else if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__rmask))) {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeafbeafU, 1U);
            vlSelf->ysyx_23060219_top__DOT__mem_rdata = 0xdeadbeafU;
        } else {
            vlSelf->ysyx_23060219_top__DOT__mem_rdata 
                = (((- (IData)((1U & (vlSelf->ysyx_23060219_top__DOT__mem_inst__DOT__rdata_temp 
                                      >> 0xfU)))) << 0x10U) 
                   | (0xffffU & vlSelf->ysyx_23060219_top__DOT__mem_inst__DOT__rdata_temp));
        }
    } else if ((2U & (IData)(vlSelf->ysyx_23060219_top__DOT__rmask))) {
        if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__rmask))) {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeafbeafU, 1U);
            vlSelf->ysyx_23060219_top__DOT__mem_rdata = 0xdeadbeafU;
        } else {
            vlSelf->ysyx_23060219_top__DOT__mem_rdata 
                = (0xffffU & vlSelf->ysyx_23060219_top__DOT__mem_inst__DOT__rdata_temp);
        }
    } else {
        vlSelf->ysyx_23060219_top__DOT__mem_rdata = 
            ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__rmask))
              ? (0xffU & vlSelf->ysyx_23060219_top__DOT__mem_inst__DOT__rdata_temp)
              : vlSelf->ysyx_23060219_top__DOT__mem_inst__DOT__rdata_temp);
    }
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__npc_temp));
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__data_list[1U] 
        = vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__npc_temp;
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__pair_list[2U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__mem_rdata)));
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__data_list[2U] 
        = vlSelf->ysyx_23060219_top__DOT__mem_rdata;
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT____Vcellinp__i1____pinNumber2) 
                       == vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT____Vcellinp__i1____pinNumber2) 
                          == vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__npc 
        = vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__lut_out;
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->ysyx_23060219_top__DOT__m5) 
                       == vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->ysyx_23060219_top__DOT__m5) 
                          == vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->ysyx_23060219_top__DOT__m5) 
                          == vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->ysyx_23060219_top__DOT__m5) 
                          == vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->ysyx_23060219_top__DOT__reg_in = vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__lut_out;
}

VL_ATTR_COLD void Vysyx_23060219_top___024root___eval_stl(Vysyx_23060219_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vysyx_23060219_top___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060219_top___024root___dump_triggers__act(Vysyx_23060219_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060219_top___024root___dump_triggers__nba(Vysyx_23060219_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_23060219_top___024root___ctor_var_reset(Vysyx_23060219_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__inst = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__IType = VL_RAND_RESET_I(3);
    vlSelf->ysyx_23060219_top__DOT__reg_wen = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__mem_wen = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__mem_ren = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__wmask = VL_RAND_RESET_I(8);
    vlSelf->ysyx_23060219_top__DOT__rmask = VL_RAND_RESET_I(3);
    vlSelf->ysyx_23060219_top__DOT__m1 = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__m2 = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__m3 = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__m4 = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__m5 = VL_RAND_RESET_I(2);
    vlSelf->ysyx_23060219_top__DOT__aluc = VL_RAND_RESET_I(5);
    vlSelf->ysyx_23060219_top__DOT__result = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__reg_in = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__src1 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__src2 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__imm32 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__num1 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__num2 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__mem_rdata = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__npc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__npc_temp = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT____Vcellinp__i1____pinNumber2 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(33);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i1__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(33);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__PC_inst__DOT__i2__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__mem_inst__DOT__rdata_temp = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12 = VL_RAND_RESET_I(12);
    vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_20 = VL_RAND_RESET_I(20);
    vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_12_to_32 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__imm_extend_inst__DOT__imm_20_to_32 = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(33);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__i3__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(33);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__i4__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(34);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(2);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__i5__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_ysyx_23060219_top__DOT__mem_inst__DOT__pmem_read__0__Vfuncout = 0;
    vlSelf->__Vfunc_ysyx_23060219_top__DOT__mem_inst__DOT__pmem_read__2__Vfuncout = 0;
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
