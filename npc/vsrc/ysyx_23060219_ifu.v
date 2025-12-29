// `include "/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_defines.v"
// `define IFU_PKG_WDITH  (`CPU_Width+`CPU_Width)

// module ysyx_23060219_ifu(
//     input  wire             clk,
//     input  wire             rst,
//     // shake hands
//     input  wire             i_cycle_end,   //指示一个指令周期的结束
//     output wire             o_post_valid,  //传递给IDU，代表此时数据包寄存器的数据有效
//     input  wire             i_post_ready,  //来自IDU，代表IDU准备好处理新数据
//     // from BRU
//     input  wire [`CPU_Bus]  i_ifu_npc,
//     // to IDU
//     output reg  [`CPU_Bus]  o_ifu_pc,
//     output reg  [`CPU_Bus]  o_ifu_inst,

//     output reg              o_ifu_req,

//     // to RAM
//     /*---------------- 读地址 ----------------*/
//     output  reg  [31:0]     o_araddr,
//     output  reg             o_arvalid, 
//     input   reg             i_arready,  
//     // output  reg  [3:0]      o_arid,     
//     // output  reg  [7:0]      o_arlen,
//     // output  reg  [2:0]      o_arsize,
//     // output  reg  [1:0]      o_arburst,
//     /*---------------- 读数据 ----------------*/
//     input   reg  [31:0]     i_rdata,    // 读指令
//     input   reg  [1:0]      i_rresp,    
//     input   reg             i_rvalid,  
//     output  reg             o_rready,
//     // input   reg             i_rlast,    
//     // input   reg  [3:0]      i_rid,
//     /*---------------- 写地址 ----------------*/
//     output  wire [31:0]     o_awaddr,
//     output  wire            o_awvalid,
//     input   wire            i_awready,
//     // output  wire [3:0]      o_awid,    
//     // output  wire [7:0]      o_awlen,
//     // output  wire [2:0]      o_awsize,
//     // output  wire [1:0]      o_awburst,
//     /*---------------- 写数据 ----------------*/
//     output  wire [31:0]     o_wdata, 
//     output  wire [3:0]      o_wstrb,    
//     output  wire            o_wvalid,
//     input   wire            i_wready,
//     // output  wire            o_wlast,    
//     /*---------------- 写回复 ----------------*/
//     input   reg  [1:0]      i_bresp,
//     input   reg             i_bvalid,
//     output  wire            o_bready
//     // input   reg  [3:0]      i_bid
// );

//     reg   temp_post_valid;

//     always@(posedge clk or posedge rst) begin
//         if(rst) begin
//             o_rready  <= 0;
//             o_arvalid <= 0;
//             o_ifu_req <= 0;
//             temp_post_valid <= 0;
//         end else begin
//             if( i_cycle_end ) begin     // 指令周期结束
//                 o_araddr  <=  i_ifu_npc;
//                 o_arvalid <=  1;
//                 o_ifu_req <=  1;
//                 temp_post_valid <= 0;
//             end
//             if( o_arvalid && i_arready ) begin
//                 o_rready  <=  1;
//                 o_arvalid <=  0;
//             end
//             if( i_rvalid && o_rready )   begin      // 指令有效
//                 o_ifu_inst <=  i_rdata;
//                 o_ifu_pc   <=  o_araddr;
//                 o_rready   <=  0;
//                 o_ifu_req  <=  0;
//                 temp_post_valid <= 1;
//             end
//         end
//     end


//     assign o_post_valid = temp_post_valid;


// endmodule
