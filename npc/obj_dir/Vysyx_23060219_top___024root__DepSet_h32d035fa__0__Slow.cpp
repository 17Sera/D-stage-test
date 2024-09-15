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
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__key_list[0U] = 1U;
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__key_list[1U] = 0U;
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__key_list[0U] = 1U;
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__key_list[1U] = 0U;
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__key_list[0U] = 1U;
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__key_list[1U] = 0U;
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[0U] = 3U;
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[1U] = 2U;
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[2U] = 1U;
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[3U] = 0U;
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[0U] = 3U;
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[1U] = 2U;
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[2U] = 1U;
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[3U] = 0U;
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[0U] = 4U;
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[0U] = 0x300000004ULL;
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[0U] = 3U;
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[1U] = 2U;
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[2U] = 1U;
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[3U] = 0U;
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[3U] = 0U;
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[3U] = 0ULL;
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
                VL_FATAL_MT("/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_top.v", 3, "", "Settle region did not converge.");
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

void Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(IData/*31:0*/ station, CData/*7:0*/ unit);
void Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__ifu_inst__DOT__imem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &imem_read__Vfuncrtn);
void Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__lsu_inst__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask);

VL_ATTR_COLD void Vysyx_23060219_top___024root___stl_sequent__TOP__0(Vysyx_23060219_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_alu_type = 0U;
    if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                       >> 6U)))) {
        if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                           >> 5U)))) {
            if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                               >> 4U)))) {
                if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
                }
            } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                      >> 3U)))) {
                if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                   >> 2U)))) {
                    if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                       >> 1U)))) {
                        if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                            vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_alu_type = 0U;
                        } else if ((0x73U != (0x7fU 
                                              & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
                        }
                    } else if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
                    }
                } else if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
                }
            } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                      >> 2U)))) {
                if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                   >> 1U)))) {
                    if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                        vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_alu_type = 0U;
                    } else if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
                    }
                } else if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
                }
            } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                      >> 1U)))) {
                if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                    if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                       >> 0xeU)))) {
                        vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_alu_type 
                            = ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                              >> 0xdU)))
                                ? ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                  >> 0xcU)))
                                    ? 0xdU : 0xcU) : 
                               ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                               >> 0xcU)))
                                 ? 0xbU : 0xaU));
                    } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                              >> 0xdU)))) {
                        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 7U);
                    } else {
                        vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_alu_type 
                            = ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                              >> 0xcU)))
                                ? 9U : 8U);
                    }
                } else if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
                }
            } else if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
            }
        } else if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
        }
    } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                              >> 5U)))) {
        if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                           >> 4U)))) {
            if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                               >> 3U)))) {
                if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
                }
            } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                      >> 2U)))) {
                if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                   >> 1U)))) {
                    if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                        vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_alu_type = 0U;
                    } else if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
                    }
                } else if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
                }
            } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                      >> 1U)))) {
                if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_alu_type 
                        = ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                          >> 0xeU)))
                            ? ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                              >> 0xdU)))
                                ? ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                  >> 0xcU)))
                                    ? 7U : 6U) : ((1U 
                                                   & (IData)(
                                                             (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                              >> 0xcU)))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(
                                                              (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                               >> 0x1eU)))
                                                    ? 5U
                                                    : 4U)
                                                   : 3U))
                            : ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                              >> 0xdU)))
                                ? ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                  >> 0xcU)))
                                    ? 0xcU : 0xaU) : 
                               ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                               >> 0xcU)))
                                 ? 2U : ((1U & (IData)(
                                                       (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                        >> 0x1eU)))
                                          ? 1U : 0U))));
                } else if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
                }
            } else if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
            }
        } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                  >> 3U)))) {
            if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
            }
        } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                  >> 2U)))) {
            if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
            }
        } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                  >> 1U)))) {
            if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_alu_type = 0U;
            } else if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
            }
        } else if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
        }
    } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                              >> 4U)))) {
        if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                           >> 3U)))) {
            if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
            }
        } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                  >> 2U)))) {
            if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                               >> 1U)))) {
                if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_alu_type = 0U;
                } else if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
                }
            } else if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
            }
        } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                  >> 1U)))) {
            if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_alu_type 
                    = ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                      >> 0xeU))) ? 
                       ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                       >> 0xdU))) ? 
                        ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                        >> 0xcU))) ? 7U
                          : 6U) : ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                  >> 0xcU)))
                                    ? ((1U & (IData)(
                                                     (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                      >> 0x1eU)))
                                        ? 5U : 4U) : 3U))
                        : ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                          >> 0xdU)))
                            ? ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                              >> 0xcU)))
                                ? 0xcU : 0xaU) : ((1U 
                                                   & (IData)(
                                                             (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                              >> 0xcU)))
                                                   ? 2U
                                                   : 0U)));
            } else if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
            }
        } else if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
        }
    } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                              >> 3U)))) {
        if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
        }
    } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                              >> 2U)))) {
        if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
        }
    } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                              >> 1U)))) {
        if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
            vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_alu_type = 0U;
        } else if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
        }
    } else if ((0x73U != (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))) {
        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 8U);
    }
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__hit 
        = ((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                  >> 0xeU)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__hit) 
           | ((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                     >> 0xeU)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__hit) 
           | ((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                     >> 0xeU)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__hit) 
           | ((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                     >> 0xeU)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__hit 
        = ((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                  >> 0xeU)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__hit) 
           | ((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                     >> 0xeU)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__hit) 
           | ((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                     >> 0xeU)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__hit) 
           | ((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                     >> 0xeU)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__hit 
        = ((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                  >> 0x14U)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__hit) 
           | ((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                     >> 0x14U)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__hit) 
           | ((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                     >> 0x14U)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__hit) 
           | ((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                     >> 0x14U)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata = 0U;
    if ((0x10000000U & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U])) {
        if ((0x4000000U & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U])) {
            if ((0x2000000U & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U])) {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 0xaU);
            } else {
                vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata 
                    = ((0x1000000U & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U])
                        ? (0xffffU & vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata_t)
                        : (0xffU & vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata_t));
            }
        } else if ((0x2000000U & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U])) {
            if ((0x1000000U & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U])) {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 0xaU);
            } else {
                vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata 
                    = vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata_t;
            }
        } else {
            vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata 
                = ((0x1000000U & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U])
                    ? (((- (IData)((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata_t 
                                          >> 0xfU)))) 
                        << 0x10U) | (0xffffU & vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata_t))
                    : (((- (IData)((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata_t 
                                          >> 7U)))) 
                        << 8U) | (0xffU & vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata_t)));
        }
    }
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__hit 
        = ((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                  >> 0x17U)) == vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__hit) 
           | ((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                     >> 0x17U)) == vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__hit 
        = ((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                  >> 0x15U)) == vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__hit) 
           | ((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                     >> 0x15U)) == vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__w_wbu_npc_wen = 
        ((~ (IData)(vlSelf->ysyx_23060219_top__DOT__wbu_inst__DOT__pre_valid_reg)) 
         & (IData)(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg));
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)((0xfffffffeU 
                                             & (((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                                                  << 7U) 
                                                 | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                                    >> 0x19U)) 
                                                + (
                                                   (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                                    << 7U) 
                                                   | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                                      >> 0x19U)))))));
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)((((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                             << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                       >> 0x19U)) + 
                           ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                             << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                       >> 0x19U)))));
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(((IData)(4U) + ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                           << 7U) | 
                                          (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                           >> 0x19U)))));
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)(((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                              << 0xaU) 
                                             | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                                >> 0x16U)))));
    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__ifu_inst__DOT__imem_read_TOP(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_reg, vlSelf->__Vfunc_ysyx_23060219_top__DOT__ifu_inst__DOT__imem_read__0__Vfuncout);
    vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_inst 
        = vlSelf->__Vfunc_ysyx_23060219_top__DOT__ifu_inst__DOT__imem_read__0__Vfuncout;
    if ((0x8000000U & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U])) {
        if ((0U == (7U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                          >> 0x18U)))) {
            vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__wmask = 1U;
        } else if ((1U == (7U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                 >> 0x18U)))) {
            vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__wmask = 3U;
        } else if ((2U == (7U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                 >> 0x18U)))) {
            vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__wmask = 0xfU;
        } else {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 0xbU);
        }
    }
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[1U] 
        = (0x200000000ULL | (QData)((IData)(((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                              << 0x12U) 
                                             | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                >> 0xeU)))));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[2U] 
        = (0x100000000ULL | (QData)((IData)(((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                              << 0x12U) 
                                             | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                >> 0xeU)))));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[0U] 
        = (0x300000000ULL | (QData)((IData)(((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                              << 0x17U) 
                                             | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                >> 9U)))));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[1U] 
        = (0x200000000ULL | (QData)((IData)(((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                              << 0x17U) 
                                             | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                >> 9U)))));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs2 
        = vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs
        [(0x1fU & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                   >> 5U))];
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__data_list[0U] 
        = ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
            << 0xaU) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                        >> 0x16U));
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT____VdfgExtracted_ha4c8ba42__0 
        = (((- (IData)((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                      >> 0x1fU))))) 
            << 0xcU) | (0xfffU & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                          >> 0x14U))));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[2U] 
        = vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs
        [(0x1fU & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                   >> 0xaU))];
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[1U] 
        = ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
            << 0x12U) | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                         >> 0xeU));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[2U] 
        = ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
            << 0x12U) | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                         >> 0xeU));
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_type = 1U;
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_ren = 0U;
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_is_mret = 0U;
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_is_ecall = 0U;
    if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                       >> 6U)))) {
        if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                           >> 5U)))) {
            if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                               >> 4U)))) {
                if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                   >> 3U)))) {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 3U);
                } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                          >> 2U)))) {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 3U);
                } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                          >> 1U)))) {
                    if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                        if ((0U == (7U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                  >> 0xcU))))) {
                            if ((0x302U == (0xfffU 
                                            & (IData)(
                                                      (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                       >> 0x14U))))) {
                                vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_is_mret = 1U;
                            } else if ((0U == (0xfffU 
                                               & (IData)(
                                                         (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                          >> 0x14U))))) {
                                vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_is_ecall = 1U;
                            } else if ((1U == (0xfffU 
                                               & (IData)(
                                                         (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                          >> 0x14U))))) {
                                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(1U, 0U);
                            } else {
                                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 1U);
                            }
                        } else if ((1U == (7U & (IData)(
                                                        (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                         >> 0xcU))))) {
                            vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_type = 1U;
                            vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_ren = 1U;
                        } else if ((2U == (7U & (IData)(
                                                        (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                         >> 0xcU))))) {
                            vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_type = 2U;
                            vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_ren = 1U;
                        } else {
                            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 2U);
                        }
                    } else {
                        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 3U);
                    }
                } else {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 3U);
                }
            } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                      >> 3U)))) {
                if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                   >> 2U)))) {
                    if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                       >> 1U)))) {
                        if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                            vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_type = 0U;
                        } else {
                            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 3U);
                        }
                    } else {
                        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 3U);
                    }
                } else {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 3U);
                }
            } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                      >> 1U)))) {
                if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_type = 0U;
                } else {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 3U);
                }
            } else {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 3U);
            }
        } else {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 3U);
        }
    } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                              >> 4U)))) {
        if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                           >> 3U)))) {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 3U);
        } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                  >> 1U)))) {
            if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_type = 0U;
            } else {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 3U);
            }
        } else {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 3U);
        }
    } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                              >> 3U)))) {
        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 3U);
    } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                              >> 2U)))) {
        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 3U);
    } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                              >> 1U)))) {
        if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
            vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_type = 0U;
        } else {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 3U);
        }
    } else {
        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 3U);
    }
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[0U] 
        = ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
            << 0x17U) | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                         >> 9U));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[1U] 
        = ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
            << 0x17U) | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                         >> 9U));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[3U] 
        = vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs
        [(0x1fU & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                   >> 5U))];
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[2U] 
        = vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs
        [(0x1fU & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                   >> 0xaU))];
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[3U] 
        = vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs
        [(0x1fU & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                   >> 0xaU))];
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__data_list[1U] 
        = ((IData)(4U) + ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                           << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                     >> 0x19U)));
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT____Vcellinp__mux2____pinNumber2 
        = (IData)((0U != (0x1c00000U & vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U])));
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__data_list[0U] 
        = (0xfffffffeU & (((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                            << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                      >> 0x19U)) + 
                          ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                            << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                      >> 0x19U))));
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__data_list[1U] 
        = (((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
             << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                       >> 0x19U)) + ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                      << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                                >> 0x19U)));
    if ((0x1000000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])) {
        if ((0x300U == (0xfffU & ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                                   << 7U) | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                             >> 0x19U))))) {
            vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src 
                = vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mstatus;
        } else if ((0x305U == (0xfffU & ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                                          << 7U) | 
                                         (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                          >> 0x19U))))) {
            vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src 
                = vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mtvec;
        } else if ((0x341U == (0xfffU & ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                                          << 7U) | 
                                         (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                          >> 0x19U))))) {
            vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src 
                = vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mepc;
        } else if ((0x342U == (0xfffU & ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                                          << 7U) | 
                                         (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                          >> 0x19U))))) {
            vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src 
                = vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mcause;
        } else {
            vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src = 0xdead001cU;
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 0xdU);
        }
    }
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1 
        = vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs
        [(0x1fU & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                   >> 0xaU))];
    if ((0x8000000U & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U])) {
        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__lsu_inst__DOT__pmem_write_TOP(
                                                                                ((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[7U] 
                                                                                << 3U) 
                                                                                | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                                                                >> 0x1dU)), 
                                                                                ((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[5U] 
                                                                                << 8U) 
                                                                                | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[4U] 
                                                                                >> 0x18U)), (IData)(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__wmask));
    }
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[3U] 
        = (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs2));
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_num_sel = 0U;
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_gpr_wen = 0U;
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_imm = 0U;
    if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                       >> 6U)))) {
        if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                           >> 5U)))) {
            if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                               >> 4U)))) {
                if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                   >> 3U)))) {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
                } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                          >> 2U)))) {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
                } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                          >> 1U)))) {
                    if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                        vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_num_sel = 0U;
                        vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_gpr_wen 
                            = vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_ren;
                        vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_imm = 0U;
                    } else {
                        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
                    }
                } else {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
                }
            } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                      >> 3U)))) {
                if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                   >> 2U)))) {
                    if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                       >> 1U)))) {
                        if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                            vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_num_sel = 3U;
                            vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_gpr_wen = 1U;
                            vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_imm 
                                = (((- (IData)((1U 
                                                & (IData)(
                                                          (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                           >> 0x1fU))))) 
                                    << 0x14U) | ((0xff000U 
                                                  & ((IData)(
                                                             (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                              >> 0xcU)) 
                                                     << 0xcU)) 
                                                 | ((0x800U 
                                                     & ((IData)(
                                                                (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                                 >> 0x14U)) 
                                                        << 0xbU)) 
                                                    | (0x7feU 
                                                       & ((IData)(
                                                                  (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                                   >> 0x15U)) 
                                                          << 1U)))));
                        } else {
                            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
                        }
                    } else {
                        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
                    }
                } else {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
                }
            } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                      >> 2U)))) {
                if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                   >> 1U)))) {
                    if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                        vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_num_sel = 3U;
                        vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_gpr_wen = 1U;
                        vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_imm = 0U;
                    } else {
                        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
                    }
                } else {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
                }
            } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                      >> 1U)))) {
                if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_num_sel = 0U;
                    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_gpr_wen = 0U;
                    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_imm 
                        = (((- (IData)((1U & (IData)(
                                                     (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                      >> 0x1fU))))) 
                            << 0xcU) | ((0x800U & ((IData)(
                                                           (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                            >> 7U)) 
                                                   << 0xbU)) 
                                        | ((0x7e0U 
                                            & ((IData)(
                                                       (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                        >> 0x19U)) 
                                               << 5U)) 
                                           | (0x1eU 
                                              & ((IData)(
                                                         (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                          >> 8U)) 
                                                 << 1U)))));
                } else {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
                }
            } else {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
            }
        } else {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
        }
    } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                              >> 5U)))) {
        if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                           >> 4U)))) {
            if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                               >> 3U)))) {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
            } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                      >> 2U)))) {
                if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                   >> 1U)))) {
                    if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                        vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_num_sel = 1U;
                        vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_gpr_wen = 1U;
                        vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_imm 
                            = ((IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                        >> 0xcU)) << 0xcU);
                    } else {
                        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
                    }
                } else {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
                }
            } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                      >> 1U)))) {
                if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_num_sel = 0U;
                    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_gpr_wen = 1U;
                    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_imm = 0U;
                } else {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
                }
            } else {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
            }
        } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                  >> 3U)))) {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
        } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                  >> 2U)))) {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
        } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                  >> 1U)))) {
            if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_num_sel = 1U;
                vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_gpr_wen = 0U;
                vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_imm 
                    = (((- (IData)((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                  >> 0x1fU))))) 
                        << 0xcU) | ((0xfe0U & ((IData)(
                                                       (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                        >> 0x19U)) 
                                               << 5U)) 
                                    | (0x1fU & (IData)(
                                                       (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                        >> 7U)))));
            } else {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
            }
        } else {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
        }
    } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                              >> 4U)))) {
        if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                           >> 3U)))) {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
        } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                  >> 2U)))) {
            if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                               >> 1U)))) {
                if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_num_sel = 2U;
                    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_gpr_wen = 1U;
                    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_imm 
                        = ((IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                    >> 0xcU)) << 0xcU);
                } else {
                    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
                }
            } else {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
            }
        } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                  >> 1U)))) {
            if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
                vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_num_sel = 1U;
                vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_gpr_wen = 1U;
                vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_imm 
                    = vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT____VdfgExtracted_ha4c8ba42__0;
            } else {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
            }
        } else {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
        }
    } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                              >> 3U)))) {
        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
    } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                              >> 2U)))) {
        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
    } else if ((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                              >> 1U)))) {
        if ((1U & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) {
            vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_num_sel = 1U;
            vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_gpr_wen = 1U;
            vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_imm 
                = vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT____VdfgExtracted_ha4c8ba42__0;
        } else {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
        }
    } else {
        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 4U);
    }
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__lut_out 
        = ((- (IData)(((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                              >> 0xeU)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__lut_out 
           | ((- (IData)(((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                 >> 0xeU)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__lut_out 
           | ((- (IData)(((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                 >> 0xeU)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__lut_out 
           | ((- (IData)(((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                 >> 0xeU)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2 
        = vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__lut_out;
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__lut_out 
        = ((- (IData)(((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                              >> 0xeU)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__lut_out 
           | ((- (IData)(((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                 >> 0xeU)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__lut_out 
           | ((- (IData)(((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                 >> 0xeU)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__lut_out 
           | ((- (IData)(((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                 >> 0xeU)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num1 
        = vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__lut_out;
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT____Vcellinp__mux2____pinNumber2) 
           == vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT____Vcellinp__mux2____pinNumber2) 
              == vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__lut_out 
        = ((- (IData)(((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                              >> 0x17U)) == vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__lut_out 
           | ((- (IData)(((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                 >> 0x17U)) == vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__pc_jorb 
        = vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__lut_out;
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[2U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1)));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[2U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1)));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[3U] 
        = (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[0U] 
        = (0x300000000ULL | (QData)((IData)(((~ vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src) 
                                             & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1))));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[1U] 
        = (0x200000000ULL | (QData)((IData)((vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src 
                                             | vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1))));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[0U] 
        = ((~ vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src) 
           & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1);
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[1U] 
        = (vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src 
           | vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1);
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_alu_res = 0U;
    if ((0x80000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])) {
        if ((0x40000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])) {
            if ((0x20000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])) {
                Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 9U);
            } else {
                vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_alu_res 
                    = ((0x10000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                        ? (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num1 
                           >= vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2)
                        : (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num1 
                           < vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2));
            }
        } else {
            vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_alu_res 
                = ((0x20000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                    ? ((0x10000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                        ? VL_GTES_III(32, vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num1, vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2)
                        : VL_LTS_III(32, vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num1, vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2))
                    : ((0x10000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                        ? (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num1 
                           != vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2)
                        : (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num1 
                           == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2)));
        }
    } else {
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_alu_res 
            = ((0x40000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                ? ((0x20000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                    ? ((0x10000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                        ? (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num1 
                           & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2)
                        : (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num1 
                           | vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2))
                    : ((0x10000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                        ? VL_SHIFTRS_III(32,32,5, vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num1, 
                                         (0x1fU & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2))
                        : (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num1 
                           >> (0x1fU & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2))))
                : ((0x20000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                    ? ((0x10000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                        ? (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num1 
                           ^ vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2)
                        : (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num1 
                           << (0x1fU & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2)))
                    : ((0x10000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                        ? ((IData)(1U) + (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num1 
                                          + (~ vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2)))
                        : (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num1 
                           + vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2))));
    }
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__pc_jorb)));
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__data_list[0U] 
        = vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__pc_jorb;
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__lut_out 
        = ((- (IData)(((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                              >> 0x14U)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__lut_out 
           | ((- (IData)(((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                 >> 0x14U)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__lut_out 
           | ((- (IData)(((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                 >> 0x14U)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__lut_out 
           | ((- (IData)(((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                 >> 0x14U)) == vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_csr_rd 
        = vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__lut_out;
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT____Vcellinp__mux2____pinNumber2) 
                       == vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT____Vcellinp__mux2____pinNumber2) 
                          == vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_t1 
        = vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__lut_out;
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_t1));
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__data_list[1U] 
        = vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_t1;
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__lut_out 
        = ((- (IData)(((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                              >> 0x15U)) == vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__lut_out 
           | ((- (IData)(((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                 >> 0x15U)) == vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_t2 
        = vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__lut_out;
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
    vlSelf->ysyx_23060219_top__DOT__clk_cnt = VL_RAND_RESET_I(3);
    vlSelf->ysyx_23060219_top__DOT__w_wbu_cycle_end = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__w_wbu_npc_wen = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_inst = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg = VL_RAND_RESET_Q(64);
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_ren = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_is_mret = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_is_ecall = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_type = VL_RAND_RESET_I(2);
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_alu_type = VL_RAND_RESET_I(4);
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_num_sel = VL_RAND_RESET_I(2);
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_imm = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_gpr_wen = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(111, vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg);
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__post_valid_reg = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT____VdfgExtracted_ha4c8ba42__0 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs2 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_csr_rd = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_alu_res = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num1 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2 = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(253, vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg);
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__post_valid_reg = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(34);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(2);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(34);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(2);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(34);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(2);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_rd = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata_t = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__wmask = VL_RAND_RESET_I(8);
    VL_RAND_RESET_W(185, vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg);
    vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__wbu_inst__DOT__pre_valid_reg = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__pc_jorb = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_t1 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_t2 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT____Vcellinp__mux2____pinNumber2 = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_reg = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(33);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(33);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(33);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mstatus = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mtvec = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mepc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mcause = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_ysyx_23060219_top__DOT__ifu_inst__DOT__imem_read__0__Vfuncout = 0;
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
