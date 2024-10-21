`include "/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_defines.v"

module ysyx_23060219_arbiter (
    input  wire             clk,
    input  wire             rst,
    // to IFU  
    /*---------------- 读地址 ----------------*/
    input  reg [`CPU_Bus]   i_ifu_araddr,  
    input  reg              i_ifu_arvalid,
    output reg              i_ifu_arready,
    input  reg  [3:0]       i_ifu_arid,      //以下悬空
    input  reg  [7:0]       i_ifu_arlen,
    input  reg  [2:0]       i_ifu_arsize,
    input  reg  [1:0]       i_ifu_arburst,
    /*---------------- 读数据 ----------------*/
    output reg  [`CPU_Bus]  o_ifu_rdata,   
    output reg  [1:0]       o_ifu_rresp,
    input  reg              i_ifu_rready,
    output reg              o_ifu_rvalid,
    output reg              o_ifu_rlast,     //0
    output reg  [3:0]       o_ifu_rid,       //0
    /*---------------- 写地址 ----------------*/
    input  reg  [`CPU_Bus]  i_ifu_awaddr,
    input  reg              i_ifu_awvalid,
    output reg              o_ifu_awready,
    input  reg  [3:0]       i_ifu_awid,      //以下悬空
    input  reg  [7:0]       i_ifu_awlen,
    input  reg  [2:0]       i_ifu_awsize,
    input  reg  [1:0]       i_ifu_awburst,
    /*---------------- 写数据 ----------------*/
    input  reg  [`CPU_Bus]  i_ifu_wdata,    
    input  reg  [3:0]       i_ifu_wstrb,
    input  reg              i_ifu_wvalid,
    output reg              o_ifu_wready,
    input  reg              i_ifu_wlast,     //悬空
    /*---------------- 写回复 ----------------*/
    output reg  [1:0]       o_ifu_bresp,
    output reg              o_ifu_bvalid,
    input  wire             i_ifu_bready,
    output wire [3:0]       o_ifu_bid,        //0

    // to LSU  
    /*---------------- 读地址 ----------------*/
    input  reg [`CPU_Bus]   i_lsu_araddr,  
    input  reg              i_lsu_arvalid,
    output reg              o_lsu_arready,
    input  reg  [3:0]       i_lsu_arid,      //以下悬空
    input  reg  [7:0]       i_lsu_arlen,
    input  reg  [2:0]       i_lsu_arsize,
    input  reg  [1:0]       i_lsu_arburst,
    /*---------------- 读数据 ----------------*/
    output reg [`CPU_Bus]   o_lsu_rdata,    
    output reg  [1:0]       o_lsu_rresp,
    input  reg              i_lsu_rready,
    output reg              o_lsu_rvalid,
    output reg              o_lsu_rlast,     //0
    output reg  [3:0]       o_lsu_rid,       //0
    /*---------------- 写地址 ----------------*/
    input  wire [`CPU_Bus]  i_lsu_awaddr,   
    input  wire             i_lsu_awvalid,
    output wire             o_lsu_awready,
    input  reg  [3:0]       i_lsu_awid,      //以下悬空
    input  reg  [7:0]       i_lsu_awlen,
    input  reg  [2:0]       i_lsu_awsize,
    input  reg  [1:0]       i_lsu_awburst,
    /*---------------- 写数据 ----------------*/
    input  wire [`CPU_Bus]  i_lsu_wdata,    
    input  wire [3:0]       i_lsu_wstrb,
    input  wire             i_lsu_wvalid,
    output wire             o_lsu_wready,
    input  reg              i_lsu_wlast,     //悬空
    /*---------------- 写回复 ----------------*/
    output reg  [1:0]       o_lsu_bresp,   
    output reg              o_lsu_bvalid,
    input  wire             i_lsu_bready,
    output wire [3:0]       o_lsu_bid,        //0

    // from SRAM  
    /*---------------- 读地址 ----------------*/
    output  reg [`CPU_Bus]  io_master_araddr,    
    output  reg             io_master_arvalid,
    input   reg             io_master_arready,
    output  reg  [3:0]      io_master_arid,     //0 ###
    output  reg  [7:0]      io_master_arlen,
    output  reg  [2:0]      io_master_arsize,
    output  reg  [1:0]      io_master_arburst,
    /*---------------- 读数据 ----------------*/
    input  reg [`CPU_Bus]   io_master_rdata,     
    input  reg  [1:0]       io_master_rresp,
    input  reg              io_master_rvalid,
    output reg              io_master_rready,
    input  reg              io_master_rlast,    //悬空 ###
    input  reg  [3:0]       io_master_rid,
    /*---------------- 写地址 ----------------*/
    output  wire [`CPU_Bus] io_master_awaddr,    
    output  wire            io_master_awvalid,
    input   wire            io_master_awready,
    output  wire [3:0]      io_master_awid,     // ###
    output  wire [7:0]      io_master_awlen,
    output  wire [2:0]      io_master_awsize,
    output  wire [1:0]      io_master_awburst,
    /*---------------- 写数据 ----------------*/
    output wire [`CPU_Bus]  io_master_wdata,     
    output wire [3:0]       io_master_wstrb,
    output wire             io_master_wvalid,
    input  wire             io_master_wready,
    output wire             io_master_wlast,    //0 ###
    /*---------------- 写回复 ----------------*/
    input  reg  [1:0]       io_master_bresp,    
    input  reg              io_master_bvalid,
    output wire             io_master_bready,
    input  reg  [3:0]       io_master_bid,

    // from UART  
    /*---------------- 读地址 ----------------*/
    output reg [`CPU_Bus]   o_uart_araddr,    
    output reg              o_uart_arvalid,
    input  reg              i_uart_arready,
    output reg  [3:0]       o_uart_arid,     //0 ###
    output reg  [7:0]       o_uart_arlen,
    output reg  [2:0]       o_uart_arsize,
    output reg  [1:0]       o_uart_arburst,
    /*---------------- 读数据 ----------------*/
    input  reg [`CPU_Bus]   i_uart_rdata,     
    input  reg  [1:0]       i_uart_rresp,
    input  reg              i_uart_rvalid,
    output reg              o_uart_rready,
    input  reg              i_uart_rlast,    //悬空 ###
    input  reg  [3:0]       i_uart_rid,
    /*---------------- 写地址 ----------------*/
    output wire [`CPU_Bus]  o_uart_awaddr,    
    output wire             o_uart_awvalid,
    input  wire             i_uart_awready,
    output wire [3:0]       o_uart_awid,     // 0 ###
    output wire [7:0]       o_uart_awlen,
    output wire [2:0]       o_uart_awsize,
    output wire [1:0]       o_uart_awburst,
    /*---------------- 写数据 ----------------*/
    output wire [`CPU_Bus]  o_uart_wdata,     
    output wire [3:0]       o_uart_wstrb,
    output wire             o_uart_wvalid,
    input  wire             i_uart_wready,
    output wire             o_uart_wlast,    //0 ###
    /*---------------- 写回复 ----------------*/
    input  reg  [1:0]       i_uart_bresp,    
    input  reg              i_uart_bvalid,
    output wire             o_uart_bready,
    input  reg  [3:0]       i_uart_bid,

    // from CLINT  
    /*---------------- 读地址 ----------------*/
    output reg [`CPU_Bus]   o_clint_araddr,    
    output reg              o_clint_arvalid,
    input  reg              i_clint_arready,
    output reg  [3:0]       o_clint_arid,     //0 ###
    output reg  [7:0]       o_clint_arlen,
    output reg  [2:0]       o_clint_arsize,
    output reg  [1:0]       o_clint_arburst,
    /*---------------- 读数据 ----------------*/
    input  reg [`CPU_Bus]   i_clint_rdata,     
    input  reg   [1:0]      i_clint_rresp,
    input  reg              i_clint_rvalid,
    output reg              o_clint_rready,
    input  reg              i_clint_rlast,    //悬空 ###
    input  reg  [3:0]       i_clint_rid,
    /*---------------- 写地址 ----------------*/
    output wire [`CPU_Bus]  o_clint_awaddr,    
    output wire             o_clint_awvalid,
    input  wire             i_clint_awready,
    output wire [3:0]       o_clint_awid,     // 0 ###
    output wire [7:0]       o_clint_awlen,
    output wire [2:0]       o_clint_awsize,
    output wire [1:0]       o_clint_awburst,
    /*---------------- 写数据 ----------------*/
    output wire [`CPU_Bus]  o_clint_wdata,     
    output wire [7:0]       o_clint_wstrb,
    output wire             o_clint_wvalid,
    input  wire             i_clint_wready,
    output wire             o_clint_wlast,    //0 ###
    /*---------------- 写回复 ----------------*/
    input  reg              i_clint_bresp,    
    input  reg              i_clint_bvalid,
    output wire             o_clint_bready,
    input  reg  [3:0]       i_clint_bid
);

/*---------- output set 0 ---------- */
    assign o_ifu_rlast = 0;
    assign o_ifu_rid = 0;
    assign o_ifu_bid = 0;

    assign o_lsu_rlast = 0;
    assign o_lsu_rid = 0;
    assign o_lsu_bid = 0;

    assign io_master_arid = 0;
    assign io_master_arlen = 0;
    assign io_master_arsize = 0;
    assign io_master_arburst = 0;
    assign io_master_awid = 0;
    assign io_master_awlen = 0;
    assign io_master_awsize = 0;
    assign io_master_awburst = 0;
    assign io_master_wlast = 0;

    assign o_uart_arid = 0;
    assign o_uart_arlen = 0;
    assign o_uart_arsize = 0;
    assign o_uart_arburst = 0;
    assign o_uart_awid = 0;
    assign o_uart_awlen = 0;
    assign o_uart_awsize = 0;
    assign o_uart_awburst = 0;
    assign o_uart_wlast = 0;

    assign o_clint_arid = 0;
    assign o_clint_arlen = 0;
    assign o_clint_arsize = 0;
    assign o_clint_arburst = 0;
    assign o_clint_awid = 0;
    assign o_clint_awlen = 0;
    assign o_clint_awsize = 0;
    assign o_clint_awburst = 0;
    assign o_clint_wlast = 0;

    assign io_master_bready = 1'b1;
/*----------------------------------*/

    reg [1:0] pririty_arb, pririty_arb_use;
    // reg [1:0] pririty_arb;
    reg ifu_request_granted;
    reg lsu_request_granted, lsu_request_granted_tmp_1, lsu_request_granted_tmp_2 ;
    reg uart_request_granted;

    // Read Address and Valid Signals
    assign io_master_araddr = (ifu_request_granted) ? i_ifu_araddr : i_lsu_araddr;
    assign io_master_arvalid = (ifu_request_granted) ? i_ifu_arvalid : i_lsu_arvalid;
    assign io_master_rready = (ifu_request_granted) ? i_ifu_rready : i_lsu_rready;

    assign i_ifu_arready = (ifu_request_granted && io_master_arready);

    assign o_lsu_arready = (lsu_request_granted && io_master_arready);
    
    assign o_ifu_rdata = (ifu_request_granted && io_master_rvalid) ? io_master_rdata : 0;
    assign o_lsu_rdata = (lsu_request_granted && io_master_rvalid) ? io_master_rdata : 0;

    //assign o_ifu_rresp = (ifu_request_granted && io_master_rresp) ? 0 : 0;
    //assign o_lsu_rresp = (lsu_request_granted && io_master_rresp) ? 0 : 0;

    assign o_ifu_rvalid = (ifu_request_granted) ? io_master_rvalid : 0;
    assign o_lsu_rvalid = (lsu_request_granted) ? io_master_rvalid : 0; 

    // Write Address, Data, and Control Signals
    assign io_master_awaddr = (lsu_request_granted && !uart_request_granted) ? i_lsu_awaddr : 0;
    assign io_master_awvalid = (lsu_request_granted && !uart_request_granted) ? i_lsu_awvalid : 0;
    assign io_master_wdata = (lsu_request_granted && !uart_request_granted) ? i_lsu_wdata : 0;
    assign io_master_wstrb = (lsu_request_granted && !uart_request_granted) ? i_lsu_wstrb : 0;
    assign io_master_wvalid = (lsu_request_granted && !uart_request_granted) ? i_lsu_wvalid : 0;

    // //assign o_ifu_awready = (ifu_request_granted) ? io_master_awready : 0;
    assign o_lsu_awready = ((lsu_request_granted || uart_request_granted) && io_master_awready);

    // //assign o_ifu_wready = (ifu_request_granted && io_master_wready);
    assign o_lsu_wready = ((lsu_request_granted || uart_request_granted) && io_master_wready);

    assign o_uart_awaddr = (lsu_request_granted && uart_request_granted) ? i_lsu_awaddr : 0;
    assign o_uart_awvalid = (lsu_request_granted && uart_request_granted) ? i_lsu_awvalid : 0;
    assign o_uart_wdata = (lsu_request_granted && uart_request_granted) ? i_lsu_wdata : 0;
    assign o_uart_wstrb = (lsu_request_granted && uart_request_granted) ? i_lsu_wstrb : 0;
    assign o_uart_wvalid = (lsu_request_granted && uart_request_granted) ? i_lsu_wvalid : 0;

    // Pririty Logic
    always @(*) begin
        if ((i_ifu_arvalid && !i_lsu_arvalid) | (i_ifu_awvalid && !i_lsu_awvalid)) begin
            pririty_arb = 2'b01; // IFU Pririty
        end else if(((!i_ifu_arvalid && i_lsu_arvalid) | (!i_ifu_awvalid && i_lsu_awvalid)) && (i_lsu_awaddr == 32'ha00003f8)) begin    //串口内存地址
            pririty_arb = 2'b11;
        end else if ((!i_ifu_arvalid && i_lsu_arvalid) | (!i_ifu_awvalid && i_lsu_awvalid)) begin
            pririty_arb = 2'b10; // LSU Pririty
        end 
        // else if ((i_ifu_arvalid && i_lsu_arvalid) | (i_ifu_awvalid && i_lsu_awvalid)) begin
        //     pririty_arb = 2'b11; // Both Requests
        // end 
        else begin
            pririty_arb = 2'b00; // No Requests
        end
    end

    always @(posedge clk) begin     // lsu_request_granted 延时一周期
        if (rst) begin
            lsu_request_granted <= 1'b0;
            // lsu_request_granted_tmp_1 <= 1'b0;
            lsu_request_granted_tmp_2 <= 1'b0;
        end
        else begin
            lsu_request_granted_tmp_2 <= lsu_request_granted_tmp_1;
            lsu_request_granted <= lsu_request_granted_tmp_2;
        end
    end

    always @(posedge clk) begin     // pririty_arb 延时一周期
        if (rst) begin
            pririty_arb_use <= 2'b0;
        end
        else begin
            pririty_arb_use <= pririty_arb;
        end
    end

    always @(*) begin
        // case (pririty_arb)
        case (pririty_arb_use)
            2'b01: begin
                ifu_request_granted = 1'b1;
                uart_request_granted = 0;
                lsu_request_granted_tmp_1 = 1'b0;
            end
            2'b10: begin
                ifu_request_granted = 1'b0;
                uart_request_granted = 0;
                lsu_request_granted_tmp_1 = 1'b1;
            end
            2'b11: begin
                ifu_request_granted = 1'b0;
                uart_request_granted = 1;
                lsu_request_granted_tmp_1 = 1'b1;
            end
            default: begin
                ifu_request_granted = 1'b0;
                uart_request_granted = 0;
                lsu_request_granted_tmp_1 = 1'b0;
            end
        endcase
    end

endmodule
