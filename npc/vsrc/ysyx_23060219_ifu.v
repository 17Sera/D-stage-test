// without SRAM version

// `include "/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_defines.v"
// `define IFU_PKG_WDITH  (`CPU_Width+`CPU_Width)

// module ifu(
//     // system
//     input  wire            clk,
//     input  wire            rst,
//     // shake hands握手                    //IFU收到WBU的完成信号i_cycle_end后再取下一条指令
//     input  wire            i_cycle_end,   //输入信号，指示一个指令周期的结束，置位于第5时钟周期---线w_wbu_cycle_end连接上WBU的o_cycle_end信号---WBU输入给IFU
//     output wire            o_post_valid,  //输出信号，表示IFU数据包有效，传递给IDU---线w_ifu_valid连接上IDU的i_pre_valid信号---IFU输入给IDU
//     input  wire            i_post_ready,  //输入信号，来自IDU，表示IDU准备好处理新数据---IDU输入给IFU
//     // from BRU
//     input  wire [31:0]     i_ifu_npc,     //输入信号，来自BRU模块，表示下一条指令的PC值----线w_bru_npc连接上BRU的o_bru_npc信号
//     // to IDU
//     output wire [31:0]     o_ifu_pc,      //输出信号，传递给IDU的当前PC值---线w_ifu_pc连接上IDU的i_idu_pc信号
//     output wire [31:0]     o_ifu_inst     //输出信号，传递给IDU的当前指令---线w_ifu_inst连接上IDU的i_idu_inst信号
// );

//     import "DPI-C" function int  imem_read(input int raddr);    // 从raddr读取指令存储器中的指令

//     // ⌈‾‾‾‾‾⌉ -->i_cycle_end --> ⌈‾‾‾‾‾⌉ --> o_post_valid-->i_pre_valid --> ⌈‾‾‾‾‾⌉ --> o_post_valid --> i_pre_valid -->⌈‾‾‾‾‾⌉ --> o_post_valid --> i_pre_valid -->⌈‾‾‾‾‾⌉ --> o_post_valid --> i_pre_valid -->⌈‾‾‾‾‾⌉   
//     // | WBU |                   | IFU |                                   | IDU |                                     | EXU |                                    | LSU |                                    | WBU |
//     // ⌊_____⌋                    ⌊_____⌋ <-- i_post_ready<-- o_pre_ready <--⌊_____⌋<-- i_post_ready <-- o_pre_ready <-- ⌊_____⌋<-- i_post_ready <-- o_pre_ready <-- ⌊_____⌋<-- i_post_ready <-- o_pre_ready <-- ⌊_____⌋                            

// // data package
//     wire [31:0]                 ifu_inst = imem_read(i_ifu_npc);    // 调用 imem_read 函数从指令存储器中读取 i_ifu_npc 地址上的指令
//     reg  [`IFU_PKG_WDITH-1 : 0] ifu_valid_data_reg;                 //保存有效的数据包，包括 PC 和指令
//     wire                        ifu_reg_wen  = i_cycle_end;         //数据包寄存器的写使能，表示指令周期结束，允许写入新的指令和PC值


// // 数据包寄存器更新
//     always @(posedge clk) begin
//         if(rst == 1'b1) 
//             ifu_valid_data_reg <= 0;
//         else if(ifu_reg_wen == 1'b1)
//             ifu_valid_data_reg <= {i_ifu_npc, ifu_inst};    // 保存了下一个指令和下一个PC
//     end


// // 输出数据包 to IDU
//     assign {o_ifu_pc, o_ifu_inst} = ifu_valid_data_reg;     // 将数据包中的PC和指令输出给IDU
    

// // 握手shake hands
//     assign o_post_valid = ~i_cycle_end;     // 当 i_cycle_end 为 0 时数据包是有效的
//     //当 i_cycle_end 为 1 时，指令周期结束，数据包的有效性也结束，确保数据在周期结束时不会被错误地处理
//     //当 i_cycle_end 为0时，说明指令周期尚未结束，数据包仍然有效，此时 o_post_valid 输出1


// endmodule

//======================================================================================================
//add arbiter

`include "/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_defines.v"
`define IFU_PKG_WDITH  (`CPU_Width+`CPU_Width)

module ysyx_23060219_ifu(
    // system
    input  wire             clk,
    input  wire             rst,
    // shake hands
    input  wire             i_cycle_end,   //指示一个指令周期的结束，置位于第5时钟周期
    output wire             o_post_valid,  //传递给IDU，代表此时数据包寄存器的数据有效
    input  wire             i_post_ready,  //来自IDU，代表IDU准备好处理新数据
    // from BRU
    input  wire [`CPU_Bus]  i_ifu_npc,
    // to IDU
    output reg  [`CPU_Bus]  o_ifu_pc,
    output reg  [`CPU_Bus]  o_ifu_inst,

    // to SRAM
    /*---------------- 读地址 ----------------*/
    output  reg  [31:0]     o_araddr,
    output  reg             o_arvalid, //写使能
    input   reg             i_arready,
    output  reg  [3:0]      o_arid,     //0 ###
    output  reg  [7:0]      o_arlen,
    output  reg  [2:0]      o_arsize,
    output  reg  [1:0]      o_arburst,
    /*---------------- 读数据 ----------------*/
    input   reg  [31:0]     i_rdata,
    input   reg  [1:0]      i_rresp,    //
    input   reg             i_rvalid,
    output  reg             o_rready,
    input   reg             i_rlast,    //悬空 ###
    input   reg  [3:0]      i_rid,
    /*---------------- 写地址 ----------------*/
    output  wire [31:0]     o_awaddr,
    output  wire            o_awvalid,
    input   wire            i_awready,
    output  wire [3:0]      o_awid,     // ###
    output  wire [7:0]      o_awlen,
    output  wire [2:0]      o_awsize,
    output  wire [1:0]      o_awburst,
    /*---------------- 写数据 ----------------*/
    output  wire [31:0]     o_wdata, 
    output  wire [3:0]      o_wstrb,    // 写字节使能  写掩码
    output  wire            o_wvalid,
    input   wire            i_wready,
    output  wire            o_wlast,    //0 ###
    /*---------------- 写回复 ----------------*/
    input   reg  [1:0]      i_bresp,
    input   reg             i_bvalid,
    output  wire            o_bready,
    input   reg  [3:0]      i_bid
);

/*-------------- output set 0 --------------- */
    assign o_arid = 0;
    assign o_arlen = 0;
    assign o_arsize = 0;
    assign o_arburst = 0;

    assign o_awid = 0;
    assign o_awlen = 0;
    assign o_awsize = 0;
    assign o_awburst = 0;

    assign o_wlast = 0;
/*-------------------------------------------*/

    reg temp;
    reg [31:0] o_ifu_inst_temp, o_ifu_pc_temp;
    reg [2:0] arvalid_counter;
    always@(posedge clk or posedge rst) begin
        if(rst) begin
            o_rready <= 1;
            temp <= 0;
            //arvalid_counter <= 0;
        end else begin
            if(i_cycle_end) begin
                o_araddr <= i_ifu_npc;
                o_arvalid <= 1;
                o_rready <= 1'b0;
                temp <= 0;
            end
            if(i_rvalid) begin
                o_ifu_inst <= i_rdata;
                o_ifu_pc <= o_araddr;
                o_rready <= 1'b1;
                o_arvalid <= 0;
                temp <= 1;
            end
        end
    end


    assign o_post_valid = temp;/*~i_rvalid& && temp;*/


endmodule

