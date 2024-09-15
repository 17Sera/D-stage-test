// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_23060219_top__Syms.h"


void Vysyx_23060219_top___024root__trace_chg_sub_0(Vysyx_23060219_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vysyx_23060219_top___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root__trace_chg_top_0\n"); );
    // Init
    Vysyx_23060219_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_23060219_top___024root*>(voidSelf);
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vysyx_23060219_top___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vysyx_23060219_top___024root__trace_chg_sub_0(Vysyx_23060219_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<3>/*95:0*/ __Vtemp_hdef3b0b3__0;
    VlWide<3>/*95:0*/ __Vtemp_hc0107ab8__0;
    VlWide<3>/*95:0*/ __Vtemp_heed9c555__0;
    VlWide<5>/*159:0*/ __Vtemp_h37e5707f__0;
    VlWide<5>/*159:0*/ __Vtemp_h56ffa0b7__0;
    VlWide<5>/*159:0*/ __Vtemp_h8324a3cc__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgBit(oldp+0,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+1,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__key_list[1]));
        bufp->chgBit(oldp+2,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+3,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__key_list[1]));
        bufp->chgBit(oldp+4,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+5,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__key_list[1]));
        bufp->chgCData(oldp+6,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[0]),2);
        bufp->chgCData(oldp+7,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[1]),2);
        bufp->chgCData(oldp+8,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[2]),2);
        bufp->chgCData(oldp+9,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[3]),2);
        bufp->chgCData(oldp+10,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[0]),2);
        bufp->chgCData(oldp+11,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[1]),2);
        bufp->chgCData(oldp+12,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[2]),2);
        bufp->chgCData(oldp+13,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[3]),2);
        bufp->chgCData(oldp+14,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[0]),2);
        bufp->chgCData(oldp+15,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[1]),2);
        bufp->chgCData(oldp+16,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[2]),2);
        bufp->chgCData(oldp+17,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[3]),2);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+18,(vlSelf->ysyx_23060219_top__DOT__clk_cnt),3);
        bufp->chgBit(oldp+19,((1U & (~ (IData)(vlSelf->ysyx_23060219_top__DOT__w_wbu_cycle_end)))));
        bufp->chgIData(oldp+20,((IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                         >> 0x20U))),32);
        bufp->chgIData(oldp+21,((IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)),32);
        bufp->chgBit(oldp+22,((1U & (~ (IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__post_valid_reg)))));
        bufp->chgBit(oldp+23,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__post_valid_reg));
        bufp->chgCData(oldp+24,((0x1fU & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                                          >> 0xaU))),5);
        bufp->chgCData(oldp+25,((0x1fU & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                                          >> 5U))),5);
        bufp->chgSData(oldp+26,((0xfffU & ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                                            << 7U) 
                                           | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                              >> 0x19U)))),12);
        bufp->chgBit(oldp+27,((1U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                     >> 0x18U))));
        bufp->chgBit(oldp+28,((1U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                     >> 0x17U))));
        bufp->chgBit(oldp+29,((1U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                     >> 0x16U))));
        bufp->chgCData(oldp+30,((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                       >> 0x14U))),2);
        bufp->chgCData(oldp+31,((0xfU & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                         >> 0x10U))),4);
        bufp->chgCData(oldp+32,((3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                       >> 0xeU))),2);
        bufp->chgIData(oldp+33,(((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                  << 0x12U) | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                               >> 0xeU))),32);
        bufp->chgBit(oldp+34,((1U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                     >> 0xdU))));
        bufp->chgBit(oldp+35,((1U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                     >> 0xcU))));
        bufp->chgCData(oldp+36,((7U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                       >> 9U))),3);
        bufp->chgIData(oldp+37,(((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                  << 0x17U) | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                               >> 9U))),32);
        bufp->chgBit(oldp+38,((1U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                     >> 8U))));
        bufp->chgBit(oldp+39,((1U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                     >> 7U))));
        bufp->chgBit(oldp+40,((1U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                     >> 6U))));
        bufp->chgCData(oldp+41,((0x1fU & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                          >> 1U))),5);
        bufp->chgBit(oldp+42,((1U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U])));
        bufp->chgBit(oldp+43,((1U & (~ (IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__post_valid_reg)))));
        bufp->chgBit(oldp+44,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__post_valid_reg));
        bufp->chgIData(oldp+45,(((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[7U] 
                                  << 3U) | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                            >> 0x1dU))),32);
        bufp->chgBit(oldp+46,((1U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                     >> 0x1cU))));
        bufp->chgBit(oldp+47,((1U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                     >> 0x1bU))));
        bufp->chgCData(oldp+48,((7U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                       >> 0x18U))),3);
        bufp->chgIData(oldp+49,(((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                  << 8U) | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[5U] 
                                            >> 0x18U))),32);
        bufp->chgIData(oldp+50,(((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[5U] 
                                  << 8U) | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[4U] 
                                            >> 0x18U))),32);
        bufp->chgIData(oldp+51,(((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[4U] 
                                  << 8U) | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                            >> 0x18U))),32);
        bufp->chgBit(oldp+52,((1U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                     >> 0x17U))));
        bufp->chgBit(oldp+53,((1U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                     >> 0x16U))));
        bufp->chgIData(oldp+54,(((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                  << 0xaU) | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
                                              >> 0x16U))),32);
        bufp->chgIData(oldp+55,(((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
                                  << 0xaU) | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                              >> 0x16U))),32);
        bufp->chgBit(oldp+56,((1U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                     >> 0x15U))));
        bufp->chgBit(oldp+57,((1U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                     >> 0x14U))));
        bufp->chgBit(oldp+58,((1U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                     >> 0x13U))));
        bufp->chgCData(oldp+59,((0x1fU & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                          >> 0xeU))),5);
        bufp->chgBit(oldp+60,((1U & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                     >> 0xdU))));
        bufp->chgSData(oldp+61,((0xfffU & (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                           >> 1U))),12);
        bufp->chgIData(oldp+62,(((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                  << 0x1fU) | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[0U] 
                                               >> 1U))),32);
        bufp->chgBit(oldp+63,((1U & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[0U])));
        bufp->chgBit(oldp+64,((1U & (~ (IData)(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg)))));
        bufp->chgBit(oldp+65,(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg));
        bufp->chgIData(oldp+66,(((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                                  << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                            >> 0x19U))),32);
        bufp->chgIData(oldp+67,(((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                  << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                            >> 0x19U))),32);
        bufp->chgIData(oldp+68,(((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                  << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                            >> 0x19U))),32);
        bufp->chgBit(oldp+69,((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                     >> 0x18U))));
        bufp->chgBit(oldp+70,((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                     >> 0x17U))));
        bufp->chgBit(oldp+71,((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                     >> 0x16U))));
        bufp->chgIData(oldp+72,(((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                  << 0xaU) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                              >> 0x16U))),32);
        bufp->chgBit(oldp+73,((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                     >> 0x15U))));
        bufp->chgIData(oldp+74,(((0x10000000U & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U])
                                  ? vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata
                                  : ((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[7U] 
                                      << 3U) | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                                >> 0x1dU)))),32);
        bufp->chgCData(oldp+75,((0x1fU & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                          >> 0x10U))),5);
        bufp->chgBit(oldp+76,((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                     >> 0xfU))));
        bufp->chgBit(oldp+77,((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                     >> 0xeU))));
        bufp->chgBit(oldp+78,((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                     >> 0xdU))));
        bufp->chgBit(oldp+79,((1U & (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                     >> 0xcU))));
        bufp->chgSData(oldp+80,((0xfffU & vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U])),12);
        bufp->chgIData(oldp+81,(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[0U]),32);
        bufp->chgBit(oldp+82,(vlSelf->ysyx_23060219_top__DOT__w_wbu_cycle_end));
        bufp->chgBit(oldp+83,(vlSelf->ysyx_23060219_top__DOT__w_wbu_npc_wen));
        bufp->chgBit(oldp+84,(((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                >> 0xfU) & (IData)(vlSelf->ysyx_23060219_top__DOT__w_wbu_npc_wen))));
        bufp->chgIData(oldp+85,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_reg),32);
        bufp->chgIData(oldp+86,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1),32);
        bufp->chgIData(oldp+87,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs2),32);
        bufp->chgIData(oldp+88,(vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src),32);
        bufp->chgIData(oldp+89,(((0x800000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                                  ? vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mepc
                                  : ((0x400000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                                      ? vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mtvec
                                      : 0xdead005aU))),32);
        bufp->chgIData(oldp+90,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__pc_jorb),32);
        bufp->chgIData(oldp+91,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_t1),32);
        bufp->chgIData(oldp+92,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_t2),32);
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
                                          << 7U) | 
                                         (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                          >> 0x19U))) 
                                     << 1U) | (IData)(
                                                      ((0x100000000ULL 
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
                                         << 7U) | (
                                                   vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                                   >> 0x19U))) 
                                    >> 0x1fU);
        bufp->chgWData(oldp+93,(__Vtemp_hdef3b0b3__0),66);
        bufp->chgQData(oldp+96,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+98,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+100,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+101,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+102,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+103,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__hit));
        bufp->chgBit(oldp+104,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT____Vcellinp__mux2____pinNumber2));
        __Vtemp_hc0107ab8__0[0U] = (IData)((0x100000000ULL 
                                            | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__pc_jorb))));
        __Vtemp_hc0107ab8__0[1U] = ((((IData)(4U) + 
                                      ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                        << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                                  >> 0x19U))) 
                                     << 1U) | (IData)(
                                                      ((0x100000000ULL 
                                                        | (QData)((IData)(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__pc_jorb))) 
                                                       >> 0x20U)));
        __Vtemp_hc0107ab8__0[2U] = (((IData)(4U) + 
                                     ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                       << 7U) | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                                 >> 0x19U))) 
                                    >> 0x1fU);
        bufp->chgWData(oldp+105,(__Vtemp_hc0107ab8__0),66);
        bufp->chgQData(oldp+108,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+110,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+112,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+113,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+114,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+115,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__hit));
        __Vtemp_heed9c555__0[0U] = (IData)((0x100000000ULL 
                                            | (QData)((IData)(
                                                              ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                                                << 0xaU) 
                                                               | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                                                  >> 0x16U))))));
        __Vtemp_heed9c555__0[1U] = ((vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_t1 
                                     << 1U) | (IData)(
                                                      ((0x100000000ULL 
                                                        | (QData)((IData)(
                                                                          ((vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                                                            << 0xaU) 
                                                                           | (vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                                                              >> 0x16U))))) 
                                                       >> 0x20U)));
        __Vtemp_heed9c555__0[2U] = (vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__npc_t1 
                                    >> 0x1fU);
        bufp->chgWData(oldp+116,(__Vtemp_heed9c555__0),66);
        bufp->chgQData(oldp+119,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+121,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+123,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+124,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+125,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+126,(vlSelf->ysyx_23060219_top__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__hit));
        bufp->chgIData(oldp+127,(vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mstatus),32);
        bufp->chgIData(oldp+128,(vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mtvec),32);
        bufp->chgIData(oldp+129,(vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mepc),32);
        bufp->chgIData(oldp+130,(vlSelf->ysyx_23060219_top__DOT__csr_ctrl_inst__DOT__mcause),32);
        bufp->chgIData(oldp+131,(((0x1000000U & vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                                   ? vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src
                                   : vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_alu_res)),32);
        bufp->chgBit(oldp+132,((1U & ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                       >> 6U) & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_alu_res))));
        bufp->chgIData(oldp+133,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_csr_rd),32);
        bufp->chgIData(oldp+134,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_alu_res),32);
        bufp->chgIData(oldp+135,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num1),32);
        bufp->chgIData(oldp+136,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2),32);
        bufp->chgIData(oldp+137,(((IData)(1U) + (~ vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__num2))),32);
        bufp->chgBit(oldp+138,(((~ (IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__post_valid_reg)) 
                                & (IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__post_valid_reg))));
        bufp->chgWData(oldp+139,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg),253);
        __Vtemp_h37e5707f__0[0U] = (IData)((0x300000000ULL 
                                            | (QData)((IData)(
                                                              ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                                << 0x17U) 
                                                               | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                                  >> 9U))))));
        __Vtemp_h37e5707f__0[1U] = ((0xfffffffcU & 
                                     ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                       << 0x19U) | 
                                      (0x1fffffcU & 
                                       (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                        >> 7U)))) | (IData)(
                                                            ((0x300000000ULL 
                                                              | (QData)((IData)(
                                                                                ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                                                << 0x17U) 
                                                                                | (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                                                >> 9U))))) 
                                                             >> 0x20U)));
        __Vtemp_h37e5707f__0[2U] = (8U | ((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1 
                                           << 4U) | 
                                          (3U & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                 >> 7U))));
        __Vtemp_h37e5707f__0[3U] = (0x10U | ((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1 
                                              << 6U) 
                                             | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1 
                                                >> 0x1cU)));
        __Vtemp_h37e5707f__0[4U] = (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1 
                                    >> 0x1aU);
        bufp->chgWData(oldp+147,(__Vtemp_h37e5707f__0),136);
        bufp->chgQData(oldp+152,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[0]),34);
        bufp->chgQData(oldp+154,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[1]),34);
        bufp->chgQData(oldp+156,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[2]),34);
        bufp->chgQData(oldp+158,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[3]),34);
        bufp->chgIData(oldp+160,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+161,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+162,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+163,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+164,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+165,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__hit));
        __Vtemp_h56ffa0b7__0[0U] = 4U;
        __Vtemp_h56ffa0b7__0[1U] = (3U | (0xfffffffcU 
                                          & ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                              << 0x14U) 
                                             | (0xffffcU 
                                                & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                   >> 0xcU)))));
        __Vtemp_h56ffa0b7__0[2U] = (8U | ((0xfffffff0U 
                                           & ((vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                               << 0x16U) 
                                              | (0x3ffff0U 
                                                 & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                    >> 0xaU)))) 
                                          | (3U & (
                                                   vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                                   >> 0xcU))));
        __Vtemp_h56ffa0b7__0[3U] = (0x10U | ((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs2 
                                              << 6U) 
                                             | (0xfU 
                                                & (vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                                   >> 0xaU))));
        __Vtemp_h56ffa0b7__0[4U] = (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs2 
                                    >> 0x1aU);
        bufp->chgWData(oldp+166,(__Vtemp_h56ffa0b7__0),136);
        bufp->chgQData(oldp+171,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[0]),34);
        bufp->chgQData(oldp+173,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[1]),34);
        bufp->chgQData(oldp+175,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[2]),34);
        bufp->chgQData(oldp+177,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[3]),34);
        bufp->chgIData(oldp+179,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+180,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+181,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+182,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+183,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+184,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__hit));
        __Vtemp_h8324a3cc__0[0U] = (IData)((0x300000000ULL 
                                            | (QData)((IData)(
                                                              ((~ vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src) 
                                                               & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1)))));
        __Vtemp_h8324a3cc__0[1U] = (((vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src 
                                      | vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1) 
                                     << 2U) | (IData)(
                                                      ((0x300000000ULL 
                                                        | (QData)((IData)(
                                                                          ((~ vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src) 
                                                                           & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1)))) 
                                                       >> 0x20U)));
        __Vtemp_h8324a3cc__0[2U] = (8U | ((vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1 
                                           << 4U) | 
                                          ((vlSelf->ysyx_23060219_top__DOT__w_cc_csr_src 
                                            | vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1) 
                                           >> 0x1eU)));
        __Vtemp_h8324a3cc__0[3U] = (0x10U | (vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_rs1 
                                             >> 0x1cU));
        __Vtemp_h8324a3cc__0[4U] = 0U;
        bufp->chgWData(oldp+185,(__Vtemp_h8324a3cc__0),136);
        bufp->chgQData(oldp+190,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[0]),34);
        bufp->chgQData(oldp+192,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[1]),34);
        bufp->chgQData(oldp+194,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[2]),34);
        bufp->chgQData(oldp+196,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[3]),34);
        bufp->chgIData(oldp+198,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+199,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+200,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+201,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+202,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+203,(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__hit));
        bufp->chgCData(oldp+204,(((IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_is_ecall)
                                   ? 0xfU : ((0x37U 
                                              == (0x7fU 
                                                  & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))
                                              ? 0U : 
                                             (0x1fU 
                                              & (IData)(
                                                        (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                         >> 0xfU)))))),5);
        bufp->chgCData(oldp+205,((0x1fU & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                   >> 0x14U)))),5);
        bufp->chgSData(oldp+206,((0xfffU & (IData)(
                                                   (vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                    >> 0x14U)))),12);
        bufp->chgBit(oldp+207,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_ren));
        bufp->chgBit(oldp+208,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_is_mret));
        bufp->chgBit(oldp+209,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_is_ecall));
        bufp->chgCData(oldp+210,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_csr_type),2);
        bufp->chgCData(oldp+211,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_alu_type),4);
        bufp->chgCData(oldp+212,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_num_sel),2);
        bufp->chgIData(oldp+213,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_imm),32);
        bufp->chgBit(oldp+214,((3U == (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
        bufp->chgBit(oldp+215,((0x23U == (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
        bufp->chgCData(oldp+216,((7U & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                >> 0xcU)))),3);
        bufp->chgBit(oldp+217,((0x6fU == (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
        bufp->chgBit(oldp+218,((0x67U == (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
        bufp->chgBit(oldp+219,((0x63U == (0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
        bufp->chgCData(oldp+220,((0x1fU & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                   >> 7U)))),5);
        bufp->chgBit(oldp+221,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_gpr_wen));
        bufp->chgCData(oldp+222,((0x7fU & (IData)(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg))),7);
        bufp->chgCData(oldp+223,((0x1fU & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                   >> 0xfU)))),5);
        bufp->chgCData(oldp+224,((0x7fU & (IData)((vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                   >> 0x19U)))),7);
        bufp->chgBit(oldp+225,((1U & ((~ (IData)(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__post_valid_reg)) 
                                      & (~ (IData)(vlSelf->ysyx_23060219_top__DOT__w_wbu_cycle_end))))));
        bufp->chgWData(oldp+226,(vlSelf->ysyx_23060219_top__DOT__idu_inst__DOT__idu_valid_data_reg),111);
        bufp->chgIData(oldp+230,(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_inst),32);
        bufp->chgQData(oldp+231,(vlSelf->ysyx_23060219_top__DOT__ifu_inst__DOT__ifu_valid_data_reg),64);
        bufp->chgBit(oldp+233,((IData)((0U != (0xc00000U 
                                               & vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__exu_valid_data_reg[3U])))));
        bufp->chgIData(oldp+234,(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata_t),32);
        bufp->chgIData(oldp+235,(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__dmem_rdata),32);
        bufp->chgCData(oldp+236,(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__wmask),8);
        bufp->chgBit(oldp+237,(((~ (IData)(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__post_valid_reg)) 
                                & (IData)(vlSelf->ysyx_23060219_top__DOT__exu_inst__DOT__post_valid_reg))));
        bufp->chgWData(oldp+238,(vlSelf->ysyx_23060219_top__DOT__lsu_inst__DOT__lsu_valid_data_reg),185);
        bufp->chgIData(oldp+244,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__i),32);
        bufp->chgIData(oldp+245,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[0]),32);
        bufp->chgIData(oldp+246,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[1]),32);
        bufp->chgIData(oldp+247,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[2]),32);
        bufp->chgIData(oldp+248,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[3]),32);
        bufp->chgIData(oldp+249,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[4]),32);
        bufp->chgIData(oldp+250,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[5]),32);
        bufp->chgIData(oldp+251,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[6]),32);
        bufp->chgIData(oldp+252,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[7]),32);
        bufp->chgIData(oldp+253,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[8]),32);
        bufp->chgIData(oldp+254,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[9]),32);
        bufp->chgIData(oldp+255,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[10]),32);
        bufp->chgIData(oldp+256,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[11]),32);
        bufp->chgIData(oldp+257,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[12]),32);
        bufp->chgIData(oldp+258,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[13]),32);
        bufp->chgIData(oldp+259,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[14]),32);
        bufp->chgIData(oldp+260,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[15]),32);
        bufp->chgIData(oldp+261,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[16]),32);
        bufp->chgIData(oldp+262,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[17]),32);
        bufp->chgIData(oldp+263,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[18]),32);
        bufp->chgIData(oldp+264,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[19]),32);
        bufp->chgIData(oldp+265,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[20]),32);
        bufp->chgIData(oldp+266,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[21]),32);
        bufp->chgIData(oldp+267,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[22]),32);
        bufp->chgIData(oldp+268,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[23]),32);
        bufp->chgIData(oldp+269,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[24]),32);
        bufp->chgIData(oldp+270,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[25]),32);
        bufp->chgIData(oldp+271,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[26]),32);
        bufp->chgIData(oldp+272,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[27]),32);
        bufp->chgIData(oldp+273,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[28]),32);
        bufp->chgIData(oldp+274,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[29]),32);
        bufp->chgIData(oldp+275,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[30]),32);
        bufp->chgIData(oldp+276,(vlSelf->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[31]),32);
        bufp->chgBit(oldp+277,(vlSelf->ysyx_23060219_top__DOT__wbu_inst__DOT__pre_valid_reg));
    }
    bufp->chgBit(oldp+278,(vlSelf->clk));
    bufp->chgBit(oldp+279,(vlSelf->rst));
}

void Vysyx_23060219_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060219_top___024root__trace_cleanup\n"); );
    // Init
    Vysyx_23060219_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_23060219_top___024root*>(voidSelf);
    Vysyx_23060219_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
