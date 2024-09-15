// `include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"

// module arbiter (
//     input  wire             clk,
//     input  wire             rst,
    
//     // IFU 接口  --------------------------------------------------
//     input  wire [31:0]      i_ifu_araddr,   //读地址
//     input  wire             i_ifu_arvalid,
//     output wire             o_ifu_arready,
//     output reg  [31:0]      o_ifu_rdata,    //读数据
//     input  wire [2:0]       i_ifu_rstrb,
//     output reg              o_ifu_rresp,    //读回复
//     input  wire             i_ifu_rready,
//     output reg              o_ifu_rvalid,
//     input  wire [31:0]      i_ifu_awaddr,   //写地址
//     input  wire             i_ifu_awvalid,
//     output wire             o_ifu_awready,
//     input  wire [31:0]      i_ifu_wdata,    //写数据
//     input  wire [7:0]       i_ifu_wstrb,
//     input  wire             i_ifu_wvalid,
//     output wire             o_ifu_wready,
//     output reg              o_ifu_bresp,   //写回复
//     output reg              o_ifu_bvalid,
//     input  wire             i_ifu_bready,
    
//     // LSU 接口  --------------------------------------------------
//     input  wire [31:0]      i_lsu_araddr,   //读地址
//     input  wire             i_lsu_arvalid,
//     output wire             o_lsu_arready,
//     output reg  [31:0]      o_lsu_rdata,    //读数据
//     input  wire [2:0]       i_lsu_rstrb,    // delete
//     output reg              o_lsu_rresp,    //读回复
//     input  wire             i_lsu_rready,
//     output reg              o_lsu_rvalid,
//     input  wire [31:0]      i_lsu_awaddr,   //写地址
//     input  wire             i_lsu_awvalid,
//     output wire             o_lsu_awready,
//     input  wire [31:0]      i_lsu_wdata,    //写数据
//     input  wire [7:0]       i_lsu_wstrb,    // 写掩码
//     input  wire             i_lsu_wvalid,
//     output wire             o_lsu_wready,
//     output reg              o_lsu_bresp,   //写回复
//     output reg              o_lsu_bvalid,
//     input  wire             i_lsu_bready,
    
//     // SRAM 接口  --------------------------------------------------
//     output wire [31:0]      o_sram_araddr,   //读地址
//     output wire             o_sram_arvalid,
//     input  wire             i_sram_arready,
//     input  reg  [31:0]      i_sram_rdata,    //读数据
//     output wire [2:0]       o_sram_rstrb,    // delete
//     input  reg              i_sram_rresp,    //读回复
//     input  reg              i_sram_rvalid,
//     output wire             o_sram_rready,
//     output wire [31:0]      o_sram_awaddr,   //写地址
//     output wire             o_sram_awvalid,
//     input  wire             i_sram_awready,
//     output wire [31:0]      o_sram_wdata,    //写数据
//     output wire [7:0]       o_sram_wstrb,    // 写掩码
//     output wire             o_sram_wvalid,
//     input  wire             i_sram_wready,
//     input  reg              i_sram_bresp,   //写回复
//     input  reg              i_sram_bvalid,
//     output wire             o_sram_bready
// );

//     reg [1:0] priority_ifu_lsu;
//     reg ifu_request_granted;
//     reg lsu_request_granted;

//     // Read Address and Valid Signals  判断sram连ifu还是lsu
//     assign o_sram_araddr =  (ifu_request_granted) ? i_ifu_araddr  : i_lsu_araddr;   // 读地址
//     assign o_sram_arvalid = (ifu_request_granted) ? i_ifu_arvalid : i_lsu_arvalid;
//     assign o_sram_rstrb =   (ifu_request_granted) ? i_ifu_rstrb   : i_lsu_rstrb;    // delete
//     assign o_sram_rready =  (ifu_request_granted) ? i_ifu_rready  : i_lsu_rready;

//     assign o_ifu_arready =  (ifu_request_granted && i_sram_arready);    ///
//     assign o_lsu_arready =  (lsu_request_granted && i_sram_arready);    ///
    
//     assign o_ifu_rdata   =  (ifu_request_granted && i_sram_rvalid) ? i_sram_rdata : 0;
//     assign o_lsu_rdata   =  (lsu_request_granted && i_sram_rvalid) ? i_sram_rdata : 0;

//     assign o_ifu_rresp   =  (ifu_request_granted && i_sram_rresp) ? 0 : 0;
//     assign o_lsu_rresp   =  (lsu_request_granted && i_sram_rresp) ? 0 : 0;

//     assign o_ifu_rvalid  =  (ifu_request_granted) ? i_sram_rvalid : 0;
//     assign o_lsu_rvalid  =  (lsu_request_granted) ? i_sram_rvalid : 0; 

//     // Write Address, Data, and Control Signals
//     assign o_sram_awaddr =  (ifu_request_granted) ? i_ifu_awaddr  : i_lsu_awaddr;
//     assign o_sram_awvalid = (ifu_request_granted) ? i_ifu_awvalid : i_lsu_awvalid;
//     assign o_sram_wdata  =  (ifu_request_granted) ? i_ifu_wdata   : i_lsu_wdata;
//     assign o_sram_wstrb  =  (ifu_request_granted) ? i_ifu_wstrb   : i_lsu_wstrb;
//     assign o_sram_wvalid =  (ifu_request_granted) ? i_ifu_wvalid  : i_lsu_wvalid;

//     assign o_ifu_awready = (ifu_request_granted) ? i_sram_awready : 0;
//     assign o_lsu_awready = (lsu_request_granted) ? i_sram_awready : 0;

//     assign o_ifu_wready  = (ifu_request_granted && i_sram_wready);
//     assign o_lsu_wready  = (lsu_request_granted && i_sram_wready);

//     assign o_ifu_bresp   = (ifu_request_granted && i_sram_bvalid) ? 0 : 0;
//     assign o_ifu_bvalid  = (ifu_request_granted && i_sram_bvalid);
//     assign o_lsu_bresp   = (lsu_request_granted && i_sram_bvalid) ? 0 : 0;
//     assign o_lsu_bvalid  = (lsu_request_granted && i_sram_bvalid);

//     // Write Response Ready
//     assign o_sram_bready = (ifu_request_granted || lsu_request_granted);

//     // Priority Logic
//     always @(*) begin
//         if ((i_ifu_arvalid && !i_lsu_arvalid) | (i_ifu_awvalid && !i_lsu_awvalid)) begin
//             priority_ifu_lsu = 2'b01; // IFU Priority
//         end else if ((!i_ifu_arvalid && i_lsu_arvalid) | (!i_ifu_awvalid && i_lsu_awvalid)) begin
//             priority_ifu_lsu = 2'b10; // LSU Priority
//         end else if ((i_ifu_arvalid && i_lsu_arvalid) | (i_ifu_awvalid && i_lsu_awvalid)) begin
//             priority_ifu_lsu = 2'b11; // Both Requests
//         end else begin
//             priority_ifu_lsu = 2'b00; // No Requests
//         end
//     end

//     // Grant Logic
//     always @(*) begin
//         case (priority_ifu_lsu)
//             2'b01: begin
//                 ifu_request_granted = 1'b1;
//                 lsu_request_granted = 1'b0;
//             end
//             2'b10: begin
//                 ifu_request_granted = 1'b0;
//                 lsu_request_granted = 1'b1;
//             end
//             2'b11: begin
//                 ifu_request_granted = 1'b1; // Assume IFU Priority
//                 lsu_request_granted = 1'b0;
//             end
//             default: begin
//                 ifu_request_granted = 1'b0;
//                 lsu_request_granted = 1'b0;
//             end
//         endcase
//     end

// endmodule
