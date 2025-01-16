`include "/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_defines.v"

module ysyx_23060219_arbiter (
    input  wire             clock,
    input  wire             reset,
    
    // IFU 接口--------------------------------------------------
    input  reg              i_ifu_req,

    input  reg [`CPU_Bus]   i_ifu_araddr,   //读地址
    input  reg              i_ifu_arvalid,
    output reg              o_ifu_arready,
    output reg  [`CPU_Bus]  o_ifu_rdata,    //读数据
    output reg  [1:0]       o_ifu_rresp,
    input  reg              i_ifu_rready,
    output reg              o_ifu_rvalid,
    input  reg  [`CPU_Bus]  i_ifu_awaddr,   //写地址
    input  reg              i_ifu_awvalid,
    output reg              o_ifu_awready,
    input  reg  [`CPU_Bus]  i_ifu_wdata,    //写数据
    input  reg  [3:0]       i_ifu_wstrb,
    input  reg              i_ifu_wvalid,
    output reg              o_ifu_wready,
    output reg  [1:0]       o_ifu_bresp,   //写回复
    output reg              o_ifu_bvalid,
    input  wire             i_ifu_bready,
    
    // LSU 接口--------------------------------------------------
    input  reg              i_lsu_req,

    input  reg [`CPU_Bus]   i_lsu_araddr,   //读地址
    input  reg              i_lsu_arvalid,
    output reg              o_lsu_arready,
    output reg [`CPU_Bus]   o_lsu_rdata,    //读数据
    output reg [1:0]        o_lsu_rresp,
    input  reg              i_lsu_rready,
    output reg              o_lsu_rvalid,
    input  wire [`CPU_Bus]  i_lsu_awaddr,   //写地址
    input  wire             i_lsu_awvalid,
    output wire             o_lsu_awready,
    input  wire [`CPU_Bus]  i_lsu_wdata,    //写数据
    input  wire [3:0]       i_lsu_wstrb,
    input  wire             i_lsu_wvalid,
    output wire             o_lsu_wready,
    output reg  [1:0]       o_lsu_bresp,   //写回复
    output reg              o_lsu_bvalid,
    input  wire             i_lsu_bready,
    
    // SOC 接口--------------------------------------------------
    input    wire         io_master_awready, 
    output   wire         io_master_awvalid, 
    output   wire [31:0]  io_master_awaddr, 
    output   wire [3:0]   io_master_awid, 
    output   wire [7:0]   io_master_awlen, 
    output   wire [2:0]   io_master_awsize,
    output   wire [1:0]   io_master_awburst,

    input    wire         io_master_wready, 
    output   wire         io_master_wvalid, 
    output   wire [31:0]  io_master_wdata,  
    output   wire [3:0]   io_master_wstrb, 
    output   wire         io_master_wlast, 

    output   wire         io_master_bready, 
    input    wire         io_master_bvalid, 
    input    wire [1:0]   io_master_bresp, 
    input    wire [3:0]   io_master_bid,

    input    wire         io_master_arready, 
    output   wire         io_master_arvalid, 
    output   wire [31:0]  io_master_araddr, 
    output   wire [3:0]   io_master_arid, 
    output   wire [7:0]   io_master_arlen, 
    output   wire [2:0]   io_master_arsize,
    output   wire [1:0]   io_master_arburst,

    output   wire         io_master_rready, 
    input    wire         io_master_rvalid, 
    input    wire [1:0]   io_master_rresp, 
    input    wire [31:0]  io_master_rdata, 
    input    wire         io_master_rlast, 
    input    wire [3:0]   io_master_rid

    // SRAM 接口--------------------------------------------------
    // output reg [`CPU_Bus]   o_sram_araddr,   //读地址
    // output reg              o_sram_arvalid,
    // input  reg              i_sram_arready,
    // input  reg [`CPU_Bus]   i_sram_rdata,    //读数据
    // input  reg              i_sram_rresp,
    // input  reg              i_sram_rvalid,
    // output reg              o_sram_rready,
    // output wire [`CPU_Bus]  o_sram_awaddr,   //写地址
    // output wire             o_sram_awvalid,
    // input  wire             i_sram_awready,
    // output wire [`CPU_Bus]  o_sram_wdata,    //写数据
    // output wire [3:0]       o_sram_wstrb,
    // output wire             o_sram_wvalid,
    // input  wire             i_sram_wready,
    // input  reg              i_sram_bresp,   //写回复
    // input  reg              i_sram_bvalid,
    // output wire             o_sram_bready,

    // UART 接口--------------------------------------------------
    // output reg [`CPU_Bus]   o_uart_araddr,   //读地址
    // output reg              o_uart_arvalid,
    // input  reg              i_uart_arready,
    // input  reg [`CPU_Bus]   i_uart_rdata,    //读数据
    // input  reg              i_uart_rresp,
    // input  reg              i_uart_rvalid,
    // output reg              o_uart_rready,
    // output wire [`CPU_Bus]  o_uart_awaddr,   //写地址
    // output wire             o_uart_awvalid,
    // input  wire             i_uart_awready,
    // output wire [`CPU_Bus]  o_uart_wdata,    //写数据
    // output wire [3:0]       o_uart_wstrb,
    // output wire             o_uart_wvalid,
    // input  wire             i_uart_wready,
    // input  reg              i_uart_bresp,   //写回复
    // input  reg              i_uart_bvalid,
    // output wire             o_uart_bready

    // // CLINT 接口--------------------------------------------------
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

    assign io_master_bready = 1;

    reg select_ifu;
    reg select_lsu;

    always@(*) begin
        select_ifu = i_ifu_req & ~i_lsu_req;
        select_lsu = ~i_ifu_req & i_lsu_req;
    end

    always@(*) begin
        o_ifu_arready = 0;
        o_ifu_rdata = 32'b0;
        o_ifu_rvalid = 0;

        o_lsu_arready = 0;
        o_lsu_rdata = 32'b0;
        o_lsu_rvalid = 0;
        o_lsu_awready = 0;
        o_lsu_wready = 0;

        io_master_awvalid = 0;
        io_master_awaddr = 32'b0;
        io_master_wvalid = 0;
        io_master_wdata = 32'b0;
        io_master_wstrb = 4'b0;
        io_master_arvalid = 0;
        io_master_araddr = 32'b0;
        io_master_rready = 1;


        if(select_ifu) begin
            o_ifu_arready = io_master_arready;
            o_ifu_rdata = io_master_rdata;
            o_ifu_rvalid = io_master_rvalid;

            io_master_awvalid = i_ifu_awvalid;
            io_master_awaddr = i_ifu_awaddr;
            io_master_wvalid = i_ifu_wvalid;
            io_master_wdata = i_ifu_wdata;
            io_master_wstrb = i_ifu_wstrb;
            io_master_arvalid = i_ifu_arvalid;
            io_master_araddr = i_ifu_araddr;
            io_master_rready = i_ifu_rready;
        end
        else if(select_lsu) begin
            o_lsu_arready = io_master_arready;
            o_lsu_rdata = io_master_rdata;
            o_lsu_rvalid = io_master_rvalid;
            o_lsu_awready = io_master_awready;
            o_lsu_wready = io_master_wready;

            io_master_awvalid = i_lsu_awvalid;
            io_master_awaddr = i_lsu_awaddr;
            io_master_wvalid = i_lsu_wvalid;
            io_master_wdata = i_lsu_wdata;
            io_master_wstrb = i_lsu_wstrb;
            io_master_arvalid = i_lsu_arvalid;
            io_master_araddr = i_lsu_araddr;
            io_master_rready = i_lsu_rready;
        end
    end



endmodule
