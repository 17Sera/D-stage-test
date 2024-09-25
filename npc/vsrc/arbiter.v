`include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"

module arbiter (
    input  wire             clk,
    input  wire             rst,
    
    // IFU 接口
    input  reg [`CPU_Bus]   i_ifu_araddr,   //读地址
    input  reg              i_ifu_arvalid,
    output reg              o_ifu_arready,
    output reg  [`CPU_Bus]  o_ifu_rdata,    //读数据
    output reg              o_ifu_rresp,
    input  reg              i_ifu_rready,
    output reg              o_ifu_rvalid,
    input  reg  [`CPU_Bus]  i_ifu_awaddr,   //写地址
    input  reg              i_ifu_awvalid,
    output reg              o_ifu_awready,
    input  reg  [`CPU_Bus]  i_ifu_wdata,    //写数据
    input  reg  [7:0]       i_ifu_wstrb,
    input  reg              i_ifu_wvalid,
    output reg              o_ifu_wready,
    output reg              o_ifu_bresp,   //写回复
    output reg              o_ifu_bvalid,
    input  wire             i_ifu_bready,
    
    // LSU 接口
    input  reg [`CPU_Bus]   i_lsu_araddr,   //读地址
    input  reg              i_lsu_arvalid,
    output reg              o_lsu_arready,
    output reg [`CPU_Bus]   o_lsu_rdata,    //读数据
    output reg              o_lsu_rresp,
    input  reg              i_lsu_rready,
    output reg              o_lsu_rvalid,
    input  wire [`CPU_Bus]  i_lsu_awaddr,   //写地址
    input  wire             i_lsu_awvalid,
    output wire             o_lsu_awready,
    input  wire [`CPU_Bus]  i_lsu_wdata,    //写数据
    input  wire [7:0]       i_lsu_wstrb,
    input  wire             i_lsu_wvalid,
    output wire             o_lsu_wready,
    output reg              o_lsu_bresp,   //写回复
    output reg              o_lsu_bvalid,
    input  wire             i_lsu_bready,
    
    // SRAM 接口
    output reg [`CPU_Bus]   o_sram_araddr,   //读地址
    output reg              o_sram_arvalid,
    input  reg              i_sram_arready,
    input  reg [`CPU_Bus]   i_sram_rdata,    //读数据
    input  reg              i_sram_rresp,
    input  reg              i_sram_rvalid,
    output reg              o_sram_rready,
    output wire [`CPU_Bus]  o_sram_awaddr,   //写地址
    output wire             o_sram_awvalid,
    input  wire             i_sram_awready,
    output wire [`CPU_Bus]  o_sram_wdata,    //写数据
    output wire [7:0]       o_sram_wstrb,
    output wire             o_sram_wvalid,
    input  wire             i_sram_wready,
    input  reg              i_sram_bresp,   //写回复
    input  reg              i_sram_bvalid,
    output wire             o_sram_bready,

    // UART 接口
    output reg [`CPU_Bus]   o_uart_araddr,   //读地址
    output reg              o_uart_arvalid,
    input  reg              i_uart_arready,
    input  reg [`CPU_Bus]   i_uart_rdata,    //读数据
    input  reg              i_uart_rresp,
    input  reg              i_uart_rvalid,
    output reg              o_uart_rready,
    output wire [`CPU_Bus]  o_uart_awaddr,   //写地址
    output wire             o_uart_awvalid,
    input  wire             i_uart_awready,
    output wire [`CPU_Bus]  o_uart_wdata,    //写数据
    output wire [7:0]       o_uart_wstrb,
    output wire             o_uart_wvalid,
    input  wire             i_uart_wready,
    input  reg              i_uart_bresp,   //写回复
    input  reg              i_uart_bvalid,
    output wire             o_uart_bready

    // // CLINT 接口
    // output reg [`CPU_Bus]   o_clint_araddr,   //读地址
    // output reg              o_clint_arvalid,
    // input  reg              i_clint_arready,
    // input  reg [`CPU_Bus]   i_clint_rdata,    //读数据
    // input  reg              i_clint_rresp,
    // input  reg              i_clint_rvalid,
    // output reg              o_clint_rready,
    // output wire [`CPU_Bus]  o_clint_awaddr,   //写地址
    // output wire             o_clint_awvalid,
    // input  wire             i_clint_awready,
    // output wire [`CPU_Bus]  o_clint_wdata,    //写数据
    // output wire [7:0]       o_clint_wstrb,
    // output wire             o_clint_wvalid,
    // input  wire             i_clint_wready,
    // input  reg              i_clint_bresp,   //写回复
    // input  reg              i_clint_bvalid,
    // output wire             o_clint_bready
);
    // reg IFU, LSU;
    // always@(posedge rst)begin
    //     IFU <= 0; LSU <= 0;
    // end
    // // 读操作
    // always@(*) begin
    //     if(i_ifu_arvalid && !i_lsu_arvalid) begin
    //         o_sram_araddr = i_ifu_araddr;
    //         o_sram_arvalid = i_ifu_arvalid;
    //         o_sram_rready = i_ifu_rready;
    //         IFU = 1;
    //     end
    //     if(i_sram_rvalid && IFU) begin
    //         o_ifu_rdata = i_sram_rdata;
    //         o_ifu_rvalid = i_sram_rvalid;
    //     end
    //     if(i_ifu_rready && IFU) begin
    //         o_sram_rready = i_ifu_rready;
    //         o_sram_arvalid = i_ifu_arvalid;
    //         IFU = 0;
    //     end
    // end

    // // 写操作
    // always@(*) begin
    //     if(i_lsu_awvalid && !i_ifu_awvalid) begin
    //         o_sram_awvalid = i_lsu_awvalid;
    //         o_sram_awaddr = i_lsu_awaddr;
    //         LSU = 1;
    //     end
    //     if(i_sram_awready && LSU) begin
    //         o_lsu_awready = i_sram_awready;
    //     end
    //     if(i_lsu_wvalid && LSU) begin
    //         o_sram_wvalid = i_lsu_wvalid;
    //         o_sram_wdata = i_lsu_wdata;
    //         o_sram_wstrb = i_lsu_wstrb;
    //     end
    //     if(i_sram_wready && LSU) begin
    //         o_lsu_wready = i_sram_wready;
    //     end
    // end


// Register to hold the current priority
//reg [1:0] priority_arb;

// Grant Logic - 组合逻辑
// always @(*) begin
//     // 默认赋值为0
//     ifu_request_granted = 1'b0;
//     lsu_request_granted = 1'b0;

//     // 优先级仲裁逻辑
//     if (i_ifu_arvalid || i_ifu_awvalid) begin
//         ifu_request_granted = 1'b1; // IFU优先级
//     end else if (i_lsu_arvalid || i_lsu_awvalid) begin
//         lsu_request_granted = 1'b1; // LSU优先级
//     end

//     // 当两个请求同时存在，IFU优先级高
//     if (i_ifu_arvalid || i_ifu_awvalid) begin
//         if ((i_lsu_arvalid || i_lsu_awvalid)) begin
//             ifu_request_granted = 1'b1; // Assume IFU优先级
//             lsu_request_granted = 1'b0;
//         end
//     end
// end

// // Address, Valid and Control Signals Assignment
// assign o_sram_araddr = (ifu_request_granted) ? i_ifu_araddr : i_lsu_araddr;
// assign o_sram_arvalid = (ifu_request_granted) ? i_ifu_arvalid : i_lsu_arvalid;
// assign o_sram_rready = (ifu_request_granted) ? i_ifu_rready : i_lsu_rready;

// assign o_ifu_arready = (ifu_request_granted && i_sram_arready);
// assign o_lsu_arready = (lsu_request_granted && i_sram_arready);

// assign o_ifu_rdata = (ifu_request_granted && i_sram_rvalid) ? i_sram_rdata : 0;
// assign o_lsu_rdata = (lsu_request_granted && i_sram_rvalid) ? i_sram_rdata : 0;

// assign o_ifu_rvalid = (ifu_request_granted) ? i_sram_rvalid : 0;
// assign o_lsu_rvalid = (lsu_request_granted) ? i_sram_rvalid : 0;

// assign o_sram_awaddr = (ifu_request_granted) ? i_ifu_awaddr : i_lsu_awaddr;
// assign o_sram_awvalid = (ifu_request_granted) ? i_ifu_awvalid : i_lsu_awvalid;
// assign o_sram_wdata = (ifu_request_granted) ? i_ifu_wdata : i_lsu_wdata;
// assign o_sram_wstrb = (ifu_request_granted) ? i_ifu_wstrb : i_lsu_wstrb;
// assign o_sram_wvalid = (ifu_request_granted) ? i_ifu_wvalid : i_lsu_wvalid;

// assign o_ifu_awready = (ifu_request_granted) ? i_sram_awready : 0;
// assign o_lsu_awready = (lsu_request_granted) ? i_sram_awready : 0;

// assign o_ifu_wready = (ifu_request_granted && i_sram_wready);
// assign o_lsu_wready = (lsu_request_granted && i_sram_wready);

// // Write Response Ready
// assign o_sram_bready = (ifu_request_granted || lsu_request_granted);


    reg [1:0] priority_arb;
    reg ifu_request_granted;
    reg lsu_request_granted;
    reg uart_request_granted;

    // Read Address and Valid Signals
    assign o_sram_araddr = (ifu_request_granted) ? i_ifu_araddr : i_lsu_araddr;
    assign o_sram_arvalid = (ifu_request_granted) ? i_ifu_arvalid : i_lsu_arvalid;
    assign o_sram_rready = (ifu_request_granted) ? i_ifu_rready : i_lsu_rready;

    assign o_ifu_arready = (ifu_request_granted && i_sram_arready);

    assign o_lsu_arready = (lsu_request_granted && i_sram_arready);
    
    assign o_ifu_rdata = (ifu_request_granted && i_sram_rvalid) ? i_sram_rdata : 0;
    assign o_lsu_rdata = (lsu_request_granted && i_sram_rvalid) ? i_sram_rdata : 0;

    //assign o_ifu_rresp = (ifu_request_granted && i_sram_rresp) ? 0 : 0;
    //assign o_lsu_rresp = (lsu_request_granted && i_sram_rresp) ? 0 : 0;

    assign o_ifu_rvalid = (ifu_request_granted) ? i_sram_rvalid : 0;
    assign o_lsu_rvalid = (lsu_request_granted) ? i_sram_rvalid : 0; 

    // Write Address, Data, and Control Signals
    assign o_sram_awaddr = (lsu_request_granted && !uart_request_granted) ? i_lsu_awaddr : 0;
    assign o_sram_awvalid = (lsu_request_granted && !uart_request_granted) ? i_lsu_awvalid : 0;
    assign o_sram_wdata = (lsu_request_granted && !uart_request_granted) ? i_lsu_wdata : 0;
    assign o_sram_wstrb = (lsu_request_granted && !uart_request_granted) ? i_lsu_wstrb : 0;
    assign o_sram_wvalid = (lsu_request_granted && !uart_request_granted) ? i_lsu_wvalid : 0;

    // //assign o_ifu_awready = (ifu_request_granted) ? i_sram_awready : 0;
    assign o_lsu_awready = ((lsu_request_granted || uart_request_granted) && i_sram_awready);

    // //assign o_ifu_wready = (ifu_request_granted && i_sram_wready);
    assign o_lsu_wready = ((lsu_request_granted || uart_request_granted) && i_sram_wready);



    assign o_uart_awaddr = (lsu_request_granted && uart_request_granted) ? i_lsu_awaddr : 0;
    assign o_uart_awvalid = (lsu_request_granted && uart_request_granted) ? i_lsu_awvalid : 0;
    assign o_uart_wdata = (lsu_request_granted && uart_request_granted) ? i_lsu_wdata : 0;
    assign o_uart_wstrb = (lsu_request_granted && uart_request_granted) ? i_lsu_wstrb : 0;
    assign o_uart_wvalid = (lsu_request_granted && uart_request_granted) ? i_lsu_wvalid : 0;

    assign o_lsu_awready = ((lsu_request_granted || uart_request_granted) && i_sram_awready);

    assign o_lsu_wready = ((lsu_request_granted || uart_request_granted) && i_sram_wready);

    // Priority Logic
    always @(*) begin
        if ((i_ifu_arvalid && !i_lsu_arvalid) | (i_ifu_awvalid && !i_lsu_awvalid)) begin
            priority_arb = 2'b01; // IFU Priority
        end else if(((!i_ifu_arvalid && i_lsu_arvalid) | (!i_ifu_awvalid && i_lsu_awvalid)) && (i_lsu_araddr == 32'ha00003f8)) begin
            priority_arb = 2'b11;
        end else if ((!i_ifu_arvalid && i_lsu_arvalid) | (!i_ifu_awvalid && i_lsu_awvalid)) begin
            priority_arb = 2'b10; // LSU Priority
        end 
        // else if ((i_ifu_arvalid && i_lsu_arvalid) | (i_ifu_awvalid && i_lsu_awvalid)) begin
        //     priority_arb = 2'b11; // Both Requests
        // end 
        else begin
            priority_arb = 2'b00; // No Requests
        end
    end

    // Grant Logic
    always @(*) begin
        case (priority_arb)
            2'b01: begin
                ifu_request_granted = 1'b1;
                uart_request_granted = 0;
                lsu_request_granted = 1'b0;
            end
            2'b10: begin
                ifu_request_granted = 1'b0;
                uart_request_granted = 0;
                lsu_request_granted = 1'b1;
            end
            2'b11: begin
                ifu_request_granted = 1'b0;
                uart_request_granted = 1;
                lsu_request_granted = 1'b1;
            end
            default: begin
                ifu_request_granted = 1'b0;
                uart_request_granted = 0;
                lsu_request_granted = 1'b0;
            end
        endcase
    end

endmodule
