// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_23060219_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_23060219_top___024root.h"

void Vysyx_23060219_top___024root___eval_act(Vysyx_23060219_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root___eval_act\n"); );
}

void Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &dmem_read__Vfuncrtn);
void Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(IData/*31:0*/ station, CData/*7:0*/ unit);
void Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__lsu_inst__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask);
void Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__ifu_inst__DOT__imem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &imem_read__Vfuncrtn);

VL_INLINE_OPT void Vysyx_23060219_top___024root___nba_sequent__TOP__0(Vysyx_23060219_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vfunc_ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_read__80__Vfuncout;
    __Vfunc_ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_read__80__Vfuncout = 0;
    VlWide<8>/*252:0*/ __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg;
    VL_ZERO_W(253, __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg);
    CData/*0:0*/ __Vdly__ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg;
    __Vdly__ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_23060219_top__DOT__register_file_inst__DOT__regs__v0;
    __Vdlyvset__ysyx_23060219_top__DOT__register_file_inst__DOT__regs__v0 = 0;
    CData/*4:0*/ __Vdlyvdim0__ysyx_23060219_top__DOT__register_file_inst__DOT__regs__v32;
    __Vdlyvdim0__ysyx_23060219_top__DOT__register_file_inst__DOT__regs__v32 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_23060219_top__DOT__register_file_inst__DOT__regs__v32;
    __Vdlyvval__ysyx_23060219_top__DOT__register_file_inst__DOT__regs__v32 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_23060219_top__DOT__register_file_inst__DOT__regs__v32;
    __Vdlyvset__ysyx_23060219_top__DOT__register_file_inst__DOT__regs__v32 = 0;
    VlWide<4>/*127:0*/ __Vtemp_h09fb980c__0;
    VlWide<3>/*95:0*/ __Vtemp_h20a9cc37__0;
    VlWide<3>/*95:0*/ __Vtemp_h14bca065__0;
    // Body
    __Vdly__ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg 
        = vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg;
    __Vdlyvset__ysyx_23060219_top__DOT__register_file_inst__DOT__regs__v0 = 0U;
    __Vdlyvset__ysyx_23060219_top__DOT__register_file_inst__DOT__regs__v32 = 0U;
    __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[0U] 
        = vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[0U];
    __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
        = vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U];
    __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
        = vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[2U];
    __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
        = vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U];
    __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[4U] 
        = vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[4U];
    __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[5U] 
        = vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[5U];
    __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
        = vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U];
    __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[7U] 
        = vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[7U];
    __Vdly__ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg 
        = ((~ (IData)(vlSelf->rst)) & (IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__post_valid_reg));
    if (vlSelf->rst) {
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__i = 0x20U;
        vlSelf->ysyx_23060219_top__DOT__clk_cnt = 0U;
        __Vdlyvset__ysyx_23060219_top__DOT__register_file_inst__DOT__regs__v0 = 1U;
        __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[0U] = 0U;
        __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] = 0U;
        __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[2U] = 0U;
        __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U] = 0U;
        __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[4U] = 0U;
        __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[5U] = 0U;
        __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] = 0U;
        __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[7U] = 0U;
    } else {
        vlSelf->ysyx_23060219_top__DOT__clk_cnt = (
                                                   (5U 
                                                    == (IData)(vlSelf->ysyx_23060219_top__DOT__clk_cnt))
                                                    ? 1U
                                                    : 
                                                   (7U 
                                                    & ((IData)(1U) 
                                                       + (IData)(vlSelf->ysyx_23060219_top__DOT__clk_cnt))));
        __Vdlyvval__ysyx_23060219_top__DOT__register_file_inst__DOT__regs__v32 
            = ((((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                  >> 0xfU) & (IData)(vlSelf->ysyx_23060219_top__DOT__w_wbu_npc_wen)) 
                & (0U != (0x1fU & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                   >> 0x10U)))) ? (
                                                   (0x10000000U 
                                                    & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U])
                                                    ? vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata
                                                    : 
                                                   ((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[7U] 
                                                     << 3U) 
                                                    | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                                       >> 0x1dU)))
                : vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs
               [(0x1fU & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                          >> 0x10U))]);
        __Vdlyvset__ysyx_23060219_top__DOT__register_file_inst__DOT__regs__v32 = 1U;
        __Vdlyvdim0__ysyx_23060219_top__DOT__register_file_inst__DOT__regs__v32 
            = (0x1fU & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                        >> 0x10U));
        if (((~ (IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__post_valid_reg)) 
             & (IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__post_valid_reg))) {
            __Vtemp_h09fb980c__0[0U] = (IData)((((QData)((IData)(
                                                                 (1U 
                                                                  & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                                     >> 8U)))) 
                                                 << 0x35U) 
                                                | (((QData)((IData)(
                                                                    (1U 
                                                                     & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                                        >> 7U)))) 
                                                    << 0x34U) 
                                                   | (((QData)((IData)(
                                                                       (1U 
                                                                        & ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                                            >> 6U) 
                                                                           & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_alu_res)))) 
                                                       << 0x33U) 
                                                      | (((QData)((IData)(
                                                                          (0x1fU 
                                                                           & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                                              >> 1U)))) 
                                                          << 0x2eU) 
                                                         | (((QData)((IData)(
                                                                             (1U 
                                                                              & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U]))) 
                                                             << 0x2dU) 
                                                            | (((QData)((IData)(
                                                                                (0xfffU 
                                                                                & ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                                                                                << 7U) 
                                                                                | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                                                                >> 0x19U))))) 
                                                                << 0x21U) 
                                                               | (((QData)((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_csr_rd)) 
                                                                   << 1U) 
                                                                  | (QData)((IData)(
                                                                                (1U 
                                                                                & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                                                                >> 0x18U))))))))))));
            __Vtemp_h09fb980c__0[1U] = (((IData)((((QData)((IData)(
                                                                   ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                                                     << 0x12U) 
                                                                    | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                                       >> 0xeU)))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                                      << 0x17U) 
                                                                     | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                                        >> 9U)))))) 
                                         << 0x16U) 
                                        | (IData)((
                                                   (((QData)((IData)(
                                                                     (1U 
                                                                      & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                                         >> 8U)))) 
                                                     << 0x35U) 
                                                    | (((QData)((IData)(
                                                                        (1U 
                                                                         & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                                            >> 7U)))) 
                                                        << 0x34U) 
                                                       | (((QData)((IData)(
                                                                           (1U 
                                                                            & ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                                                >> 6U) 
                                                                               & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_alu_res)))) 
                                                           << 0x33U) 
                                                          | (((QData)((IData)(
                                                                              (0x1fU 
                                                                               & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                                                >> 1U)))) 
                                                              << 0x2eU) 
                                                             | (((QData)((IData)(
                                                                                (1U 
                                                                                & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U]))) 
                                                                 << 0x2dU) 
                                                                | (((QData)((IData)(
                                                                                (0xfffU 
                                                                                & ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                                                                                << 7U) 
                                                                                | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                                                                >> 0x19U))))) 
                                                                    << 0x21U) 
                                                                   | (((QData)((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_csr_rd)) 
                                                                       << 1U) 
                                                                      | (QData)((IData)(
                                                                                (1U 
                                                                                & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                                                                >> 0x18U))))))))))) 
                                                   >> 0x20U)));
            __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[0U] 
                = __Vtemp_h09fb980c__0[0U];
            __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                = __Vtemp_h09fb980c__0[1U];
            __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
                = (((IData)((((QData)((IData)(((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                                << 0x12U) 
                                               | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                  >> 0xeU)))) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                            << 0x17U) 
                                                           | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                              >> 9U)))))) 
                    >> 0xaU) | ((IData)(((((QData)((IData)(
                                                           ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                                             << 0x12U) 
                                                            | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                               >> 0xeU)))) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                              << 0x17U) 
                                                             | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                                >> 9U))))) 
                                         >> 0x20U)) 
                                << 0x16U));
            __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                = ((((0x800000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                      ? vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mepc
                      : ((0x400000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                          ? vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mtvec
                          : 0xdead005aU)) << 0x18U) 
                   | ((0x800000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U]) 
                      | ((0x400000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U]) 
                         | ((IData)(((((QData)((IData)(
                                                       ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                                         << 0x12U) 
                                                        | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                           >> 0xeU)))) 
                                       << 0x20U) | (QData)((IData)(
                                                                   ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                                     << 0x17U) 
                                                                    | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                                       >> 9U))))) 
                                     >> 0x20U)) >> 0xaU))));
            __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[4U] 
                = ((((0x800000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                      ? vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mepc
                      : ((0x400000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                          ? vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mtvec
                          : 0xdead005aU)) >> 8U) | 
                   ((IData)((((QData)((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1)) 
                              << 0x20U) | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs2)))) 
                    << 0x18U));
            __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[5U] 
                = (((IData)((((QData)((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1)) 
                              << 0x20U) | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs2)))) 
                    >> 8U) | ((IData)(((((QData)((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1)) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs2))) 
                                       >> 0x20U)) << 0x18U));
            __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                = ((((0x1000000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                      ? vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src
                      : vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_alu_res) 
                    << 0x1dU) | ((0x10000000U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                 << 0xfU)) 
                                 | ((0x8000000U & (
                                                   vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                   << 0xfU)) 
                                    | ((0x7000000U 
                                        & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                           << 0xfU)) 
                                       | ((IData)((
                                                   (((QData)((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1)) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs2))) 
                                                   >> 0x20U)) 
                                          >> 8U)))));
            __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[7U] 
                = (((0x1000000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                     ? vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src
                     : vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_alu_res) 
                   >> 3U);
        }
    }
    if ((0x10000000U & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U])) {
        Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_read_TOP(
                                                                                ((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[7U] 
                                                                                << 3U) 
                                                                                | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                                                                >> 0x1dU)), __Vfunc_ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_read__80__Vfuncout);
        vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata_t 
            = __Vfunc_ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_read__80__Vfuncout;
    } else {
        vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata_t = 1U;
    }
    if (__Vdlyvset__ysyx_23060219_top__DOT__register_file_inst__DOT__regs__v0) {
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[1U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[2U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[3U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[4U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[5U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[6U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[7U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[8U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[9U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0xaU] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0xbU] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0xcU] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0xdU] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0xeU] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0xfU] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0x10U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0x11U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0x12U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0x13U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0x14U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0x15U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0x16U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0x17U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0x18U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0x19U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0x1aU] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0x1bU] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0x1cU] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0x1dU] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0x1eU] = 0U;
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0x1fU] = 0U;
    }
    if (__Vdlyvset__ysyx_23060219_top__DOT__register_file_inst__DOT__regs__v32) {
        vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[__Vdlyvdim0__ysyx_23060219_top__DOT__register_file_inst__DOT__regs__v32] 
            = __Vdlyvval__ysyx_23060219_top__DOT__register_file_inst__DOT__regs__v32;
    }
    if (vlSelf->rst) {
        vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mstatus = 0U;
        vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mtvec = 0U;
        vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mepc = 0U;
        vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mcause = 0U;
    } else if ((0x400000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])) {
        vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mcause 
            = ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                          >> 0x19U));
        vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mepc 
            = ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                          >> 0x19U));
    } else if ((0x4000U & vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U])) {
        if ((0x300U == (0xfffU & vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U]))) {
            vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mstatus 
                = vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[0U];
        } else if ((0x305U == (0xfffU & vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U]))) {
            vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mtvec 
                = vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[0U];
        } else if ((0x341U == (0xfffU & vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U]))) {
            vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mepc 
                = vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[0U];
        } else if ((0x342U == (0xfffU & vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U]))) {
            vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mcause 
                = vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[0U];
        } else {
            Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__idu_inst__DOT__TRAP_TOP(2U, 0xcU);
        }
    }
    if (vlSelf->rst) {
        vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[0U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[0U] 
            = __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[0U];
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
            = __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U];
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
            = __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[2U];
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
            = __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U];
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[4U] 
            = __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[4U];
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[5U] 
            = __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[5U];
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
            = __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U];
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[7U] 
            = __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[7U];
        vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata = 0U;
        vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] = 0U;
        vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] = 0U;
    } else {
        if (((~ (IData)(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg)) 
             & (IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__post_valid_reg))) {
            __Vtemp_h20a9cc37__0[0U] = (IData)((((QData)((IData)(
                                                                 (0U 
                                                                  != 
                                                                  (0xc00000U 
                                                                   & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U])))) 
                                                 << 0x35U) 
                                                | (((QData)((IData)(
                                                                    (0x1fU 
                                                                     & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                                                        >> 0xeU)))) 
                                                    << 0x30U) 
                                                   | (((QData)((IData)(
                                                                       (1U 
                                                                        & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                                                           >> 0xdU)))) 
                                                       << 0x2fU) 
                                                      | (((QData)((IData)(
                                                                          (1U 
                                                                           & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[0U]))) 
                                                          << 0x2eU) 
                                                         | (((QData)((IData)(
                                                                             (1U 
                                                                              & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                                                                >> 0x17U)))) 
                                                             << 0x2dU) 
                                                            | (((QData)((IData)(
                                                                                (1U 
                                                                                & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                                                                >> 0x16U)))) 
                                                                << 0x2cU) 
                                                               | (0xfffffffffffULL 
                                                                  & (((QData)((IData)(
                                                                                vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U])) 
                                                                      << 0x1fU) 
                                                                     | ((QData)((IData)(
                                                                                vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[0U])) 
                                                                        >> 1U))))))))));
            __Vtemp_h20a9cc37__0[1U] = ((0xffc00000U 
                                         & ((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[4U] 
                                             << 0x1eU) 
                                            | (0x3fc00000U 
                                               & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                                  >> 2U)))) 
                                        | (IData)((
                                                   (((QData)((IData)(
                                                                     (0U 
                                                                      != 
                                                                      (0xc00000U 
                                                                       & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U])))) 
                                                     << 0x35U) 
                                                    | (((QData)((IData)(
                                                                        (0x1fU 
                                                                         & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                                                            >> 0xeU)))) 
                                                        << 0x30U) 
                                                       | (((QData)((IData)(
                                                                           (1U 
                                                                            & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                                                               >> 0xdU)))) 
                                                           << 0x2fU) 
                                                          | (((QData)((IData)(
                                                                              (1U 
                                                                               & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[0U]))) 
                                                              << 0x2eU) 
                                                             | (((QData)((IData)(
                                                                                (1U 
                                                                                & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                                                                >> 0x17U)))) 
                                                                 << 0x2dU) 
                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                                                                >> 0x16U)))) 
                                                                    << 0x2cU) 
                                                                   | (0xfffffffffffULL 
                                                                      & (((QData)((IData)(
                                                                                vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U])) 
                                                                          << 0x1fU) 
                                                                         | ((QData)((IData)(
                                                                                vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[0U])) 
                                                                            >> 1U))))))))) 
                                                   >> 0x20U)));
            vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[0U] 
                = __Vtemp_h20a9cc37__0[0U];
            vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                = __Vtemp_h20a9cc37__0[1U];
            vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                = ((0xfe000000U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[5U] 
                                   << 1U)) | ((0x1000000U 
                                               & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                                  << 3U)) 
                                              | ((0x800000U 
                                                  & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                                     << 3U)) 
                                                 | ((0x400000U 
                                                     & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                                        << 3U)) 
                                                    | (0x3fffffU 
                                                       & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[4U] 
                                                          >> 2U))))));
            vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                = (((0x1fffffeU & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                   << 1U)) | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[5U] 
                                              >> 0x1fU)) 
                   | ((IData)((((QData)((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U])) 
                                << 0x2aU) | (((QData)((IData)(
                                                              vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[2U])) 
                                              << 0xaU) 
                                             | ((QData)((IData)(
                                                                vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U])) 
                                                >> 0x16U)))) 
                      << 0x19U));
            vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                = (((IData)((((QData)((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U])) 
                              << 0x2aU) | (((QData)((IData)(
                                                            vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[2U])) 
                                            << 0xaU) 
                                           | ((QData)((IData)(
                                                              vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U])) 
                                              >> 0x16U)))) 
                    >> 7U) | ((IData)(((((QData)((IData)(
                                                         vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U])) 
                                         << 0x2aU) 
                                        | (((QData)((IData)(
                                                            vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[2U])) 
                                            << 0xaU) 
                                           | ((QData)((IData)(
                                                              vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U])) 
                                              >> 0x16U))) 
                                       >> 0x20U)) << 0x19U));
            vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                = ((IData)(((((QData)((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U])) 
                              << 0x2aU) | (((QData)((IData)(
                                                            vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[2U])) 
                                            << 0xaU) 
                                           | ((QData)((IData)(
                                                              vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U])) 
                                              >> 0x16U))) 
                            >> 0x20U)) >> 7U);
        }
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[0U] 
            = __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[0U];
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
            = __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U];
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
            = __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[2U];
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
            = __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U];
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[4U] 
            = __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[4U];
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[5U] 
            = __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[5U];
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
            = __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U];
        vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[7U] 
            = __Vdly__ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[7U];
        vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata = 0U;
        if ((1U & ((~ (IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__post_valid_reg)) 
                   & (~ (IData)(vlSelf->ysyx_23060219_top__DOT__w_wbu_cycle_end))))) {
            __Vtemp_h14bca065__0[0U] = (IData)((((QData)((IData)(
                                                                 (3U 
                                                                  == 
                                                                  (0x7fU 
                                                                   & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))))) 
                                                 << 0x2dU) 
                                                | (((QData)((IData)(
                                                                    (0x23U 
                                                                     == 
                                                                     (0x7fU 
                                                                      & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))))) 
                                                    << 0x2cU) 
                                                   | (((QData)((IData)(
                                                                       (7U 
                                                                        & (IData)(
                                                                                (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                                                >> 0xcU))))) 
                                                       << 0x29U) 
                                                      | (((QData)((IData)(
                                                                          (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                                           >> 0x20U))) 
                                                          << 9U) 
                                                         | (QData)((IData)(
                                                                           (((0x6fU 
                                                                              == 
                                                                              (0x7fU 
                                                                               & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) 
                                                                             << 8U) 
                                                                            | (((0x67U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) 
                                                                                << 7U) 
                                                                               | (((0x63U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) 
                                                                                << 6U) 
                                                                                | ((0x3eU 
                                                                                & ((IData)(
                                                                                (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                                                >> 7U)) 
                                                                                << 1U)) 
                                                                                | (IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_gpr_wen))))))))))));
            __Vtemp_h14bca065__0[1U] = ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_imm 
                                         << 0xeU) | (IData)(
                                                            ((((QData)((IData)(
                                                                               (3U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))))) 
                                                               << 0x2dU) 
                                                              | (((QData)((IData)(
                                                                                (0x23U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))))) 
                                                                  << 0x2cU) 
                                                                 | (((QData)((IData)(
                                                                                (7U 
                                                                                & (IData)(
                                                                                (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                                                >> 0xcU))))) 
                                                                     << 0x29U) 
                                                                    | (((QData)((IData)(
                                                                                (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                                                >> 0x20U))) 
                                                                        << 9U) 
                                                                       | (QData)((IData)(
                                                                                (((0x6fU 
                                                                                == 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) 
                                                                                << 8U) 
                                                                                | (((0x67U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) 
                                                                                << 7U) 
                                                                                | (((0x63U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))) 
                                                                                << 6U) 
                                                                                | ((0x3eU 
                                                                                & ((IData)(
                                                                                (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                                                >> 7U)) 
                                                                                << 1U)) 
                                                                                | (IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_gpr_wen))))))))))) 
                                                             >> 0x20U)));
            vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                = __Vtemp_h14bca065__0[0U];
            vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                = __Vtemp_h14bca065__0[1U];
            vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                = (((IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                             >> 0x14U)) << 0x19U) | 
                   (((IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_ren) 
                     << 0x18U) | (((IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_is_mret) 
                                   << 0x17U) | (((IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_is_ecall) 
                                                 << 0x16U) 
                                                | (((IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_type) 
                                                    << 0x14U) 
                                                   | (((IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_alu_type) 
                                                       << 0x10U) 
                                                      | (((IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_num_sel) 
                                                          << 0xeU) 
                                                         | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_imm 
                                                            >> 0x12U))))))));
            vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                = ((((IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_is_ecall)
                      ? 0xfU : ((0x37U == (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))
                                 ? 0U : (0x1fU & (IData)(
                                                         (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                          >> 0xfU))))) 
                    << 0xaU) | ((0x3e0U & ((IData)(
                                                   (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                    >> 0x14U)) 
                                           << 5U)) 
                                | (0x1fU & ((IData)(
                                                    (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                     >> 0x14U)) 
                                            >> 7U))));
        }
    }
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
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__data_list[0U] 
        = ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
            << 0xaU) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                        >> 0x16U));
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
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__post_valid_reg 
        = ((~ (IData)(vlSelf->rst)) & (IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__post_valid_reg));
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
    if (vlSelf->rst) {
        vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg = 0ULL;
    } else if (vlSelf->ysyx_23060219_top__DOT__w_wbu_cycle_end) {
        vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
            = (((QData)((IData)(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_reg)) 
                << 0x20U) | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_inst)));
    }
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
    vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[3U] 
        = (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs2));
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
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__pc_jorb)));
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__data_list[0U] 
        = vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__pc_jorb;
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__post_valid_reg 
        = (1U & ((~ (IData)(vlSelf->rst)) & (~ (IData)(vlSelf->ysyx_23060219_top__DOT__w_wbu_cycle_end))));
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
    vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT____VdfgExtracted_ha4c8ba42__0 
        = (((- (IData)((1U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                      >> 0x1fU))))) 
            << 0xcU) | (0xfffU & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                          >> 0x14U))));
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
    if (vlSelf->rst) {
        vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_reg = 0x80000000U;
    } else if (vlSelf->ysyx_23060219_top__DOT__w_wbu_npc_wen) {
        vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_reg 
            = vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_t2;
    }
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
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_t1));
    vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__data_list[1U] 
        = vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_t1;
    vlSelf->ysyx_23060219_top__DOT__w_wbu_cycle_end 
        = ((IData)(vlSelf->rst) | ((IData)(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg) 
                                   & (~ (IData)(vlSelf->ysyx_23060219_top__DOT__wbu_inst__DOT__pre_valid_reg))));
    Vysyx_23060219_top___024root____Vdpiimwrap_ysyx_23060219_top__DOT__ifu_inst__DOT__imem_read_TOP(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_reg, vlSelf->__Vfunc_ysyx_23060219_top__DOT__ifu_inst__DOT__imem_read__0__Vfuncout);
    vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_inst 
        = vlSelf->__Vfunc_ysyx_23060219_top__DOT__ifu_inst__DOT__imem_read__0__Vfuncout;
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
    vlSelf->ysyx_23060219_top__DOT__wbu_inst__DOT__pre_valid_reg 
        = ((~ (IData)(vlSelf->rst)) & (IData)(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg));
    vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg 
        = __Vdly__ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg;
    vlSelf->ysyx_23060219_top__DOT__w_wbu_npc_wen = 
        ((~ (IData)(vlSelf->ysyx_23060219_top__DOT__wbu_inst__DOT__pre_valid_reg)) 
         & (IData)(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg));
}

void Vysyx_23060219_top___024root___eval_nba(Vysyx_23060219_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vysyx_23060219_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vysyx_23060219_top___024root___eval_triggers__act(Vysyx_23060219_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060219_top___024root___dump_triggers__act(Vysyx_23060219_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060219_top___024root___dump_triggers__nba(Vysyx_23060219_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_23060219_top___024root___eval(Vysyx_23060219_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vysyx_23060219_top___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vysyx_23060219_top___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_top.v", 3, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vysyx_23060219_top___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vysyx_23060219_top___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_top.v", 3, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vysyx_23060219_top___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vysyx_23060219_top___024root___eval_debug_assertions(Vysyx_23060219_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
