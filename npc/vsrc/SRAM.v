// `include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"

// module SRAM (
//     input  wire             clk,
//     input  wire             rst,
//     /************ 读地址 ************/
//     input  wire [31:0]      i_araddr,
//     input  wire             i_arvalid, //写使能
//     output wire             o_arready,
//     /************ 读数据 ************/
//     output reg  [31:0]      o_rdata,
//     input  wire [2:0]       i_rstrb,  //读字节使能  读掩码
//     output reg              o_rresp,
//     output reg              o_rvalid,
//     input  wire             i_rready,
//     /************ 写地址 ************/
//     input  wire [31:0]      i_awaddr,
//     input  wire             i_awvalid,
//     output wire             o_awready,
//     /************ 写数据 ************/
//     input  wire [31:0]      i_wdata, 
//     input  wire [7:0]       i_wstrb,  // 写字节使能  写掩码
//     input  wire             i_wvalid,
//     output wire             o_wready,
//     /************ 写回复 ************/
//     output reg              o_bresp,
//     output reg              o_bvalid,
//     input  wire             i_bready
//     /************ 仲裁器 ************/
//     // input  wire             req_master1,
//     // input  wire             req_master2,
//     // output reg              grant_master1,
//     // output reg              grant_master2
// );

//     import "DPI-C" function int  pmem_read(input int i_araddr, input int num); //用于利用从软件读取指令、数据
//     import "DPI-C" function void pmem_write(input int i_awaddr, input int i_wdata, input byte wmask); //用于将数据写入软件
//     import "DPI-C" function void ebreak(input int station, input int inst, input byte unit); //指令终止

//     // 内部信号定义
//     reg [31:0] read_data_buffer;
//     reg [31:0] rdata_temp;
//     reg        ar_ready, aw_ready, w_ready, b_valid, r_valid;

//     // 仲裁器实例化
//     // arbitr arb (
//     //     .clk(clk),
//     //     .rst(reset),
//     //     .req_master1(req_master1),
//     //     .req_master2(req_master2),
//     //     .grant_master1(grant_master1),
//     //     .grant_master2(grant_master2),
//     //     .grant_slave()
//     // );

//     // 读地址握手
//     always @(posedge clk or rst) begin
//         if (rst) begin
//             ar_ready <= 1'b0;
//         end else begin
//             if ((i_arvalid && !ar_ready))
//                 ar_ready <= 1'b1;
//             else if (r_valid && i_rready)
//                 ar_ready <= 1'b0;
//         end
//     end
//     assign o_arready = ar_ready;

//     // 写地址握手
//     always @(posedge clk or rst) begin
//         if (rst) begin
//             aw_ready <= 1'b0;
//         end else begin
//             if ((i_awvalid && !aw_ready))
//                 aw_ready <= 1'b1;
//             else if (w_ready && i_bready)
//                 aw_ready <= 1'b0;
//         end
//     end
//     assign o_awready = aw_ready;

//     // 写数据握手
//     always @(posedge clk or rst) begin
//         if (rst) begin
//             w_ready <= 1'b0;
//         end else begin
//             if ((i_wvalid && !w_ready))
//                 w_ready <= 1'b1;
//             else if (b_valid && i_bready)
//                 w_ready <= 1'b0;
//         end
//     end
//     assign o_wready = w_ready;

//     always @(*) begin
//         if(i_arvalid) begin //有读数据请求时
//             rdata_temp = pmem_read(i_araddr, 32'hdead000d);
//         end else begin
//             rdata_temp = 32'heae;
//         end
//     end

//     // 读数据处理
//     always @(posedge clk or rst) begin
//         if (rst) begin
//             r_valid <= 1'b0;
//             o_rdata <= 32'b0;
//             o_rresp <= 1'b0;
//             read_data_buffer <= 32'b0;
//         end else begin
//             if ((i_arvalid && ar_ready)) begin
//                 // 从内存中读取数据
//                 case(i_rstrb)
//                     `LoadBU:  read_data_buffer <= {24'd0, rdata_temp[7:0]};
//                     `LoadHU:  read_data_buffer <= {16'd0, rdata_temp[15:0]};
//                     `LoadB:   read_data_buffer <= {{24{rdata_temp[7]}}, rdata_temp[7:0]};
//                     `LoadH:   read_data_buffer <= {{16{rdata_temp[15]}}, rdata_temp[15:0]};
//                     `LoadW:   read_data_buffer <= rdata_temp;
//                     default:  begin
//                                 o_rdata <= 32'hdead0005;
//                                 ebreak(`ABORT, 32'hdead0006, `Unit_MEM);
//                     end
//                 endcase
//                 //read_data_buffer <= memory[i_araddr[7:0]];
//                 r_valid <= 1'b1;
//                 o_rresp <= 1'b0; // 假设无错误响应
//             end
//             if (i_rready && r_valid) begin
//                 o_rdata <= read_data_buffer;
//                 r_valid <= 1'b0;
//             end
//         end
//     end
//     assign o_rvalid = r_valid;

//     // 写数据处理
//     always @(posedge clk or rst) begin
//         if (rst) begin
//             b_valid <= 1'b0;
//             o_bresp <= 1'b0;
//         end else begin
//             if ((i_wvalid && w_ready)) begin
//                 // 写操作时应用掩码i_wstrb
//                 pmem_write(i_awaddr, i_wdata, i_wstrb);
//                 b_valid <= 1'b1;
//                 o_bresp <= 1'b0; // 假设无错误响应
//             end
//             if (b_valid && i_bready) begin
//                 b_valid <= 1'b0;
//             end
//         end
//     end
//     assign o_bvalid = b_valid;

// endmodule


