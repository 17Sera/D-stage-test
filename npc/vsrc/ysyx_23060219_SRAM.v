`include "/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_defines.v"

module ysyx_23060219_SRAM (
    input  wire             clk,
    input  wire             rst,
    /*---------------- 读地址 ----------------*/
    input  reg  [31:0]      io_slave_araddr,
    input  reg              io_slave_arvalid,   //写使能
    output reg              io_slave_arready,
    input  reg  [3:0]       io_slave_arid,      //以下悬空
    input  reg  [7:0]       io_slave_arlen,
    input  reg  [2:0]       io_slave_arsize,
    input  reg  [1:0]       io_slave_arburst,
    /*---------------- 读数据 ----------------*/
    output reg  [31:0]      io_slave_rdata,
    output reg  [1:0]       io_slave_rresp,     //0
    output reg              io_slave_rvalid,
    input  reg              io_slave_rready,
    output reg              io_slave_rlast,     //0
    output reg  [3:0]       io_slave_rid,       //0
    /*---------------- 写地址 ----------------*/
    input  reg  [31:0]      io_slave_awaddr,
    input  reg              io_slave_awvalid,
    output reg              io_slave_awready,
    input  reg  [3:0]       io_slave_awid,      //以下悬空
    input  reg  [7:0]       io_slave_awlen,
    input  reg  [2:0]       io_slave_awsize,
    input  reg  [1:0]       io_slave_awburst,
    /*---------------- 写数据 ----------------*/
    input  reg  [31:0]      io_slave_wdata, 
    input  reg  [3:0]       io_slave_wstrb,     //写字节使能  写掩码
    input  reg              io_slave_wvalid,
    output reg              io_slave_wready,
    input  reg              io_slave_wlast,     //悬空
    /*---------------- 写回复 ----------------*/
    output reg  [1:0]       io_slave_bresp,
    output reg              io_slave_bvalid,
    input  wire             io_slave_bready,
    output wire [3:0]       io_slave_bid        //0
);

    import "DPI-C" function int  dmem_read(input int io_slave_araddr); //用于利用从软件读取指令、数据
    import "DPI-C" function void pmem_write(input int io_slave_awaddr, input int io_slave_wdata, input byte wmask); //用于将数据写入软件

/*---------- output set 0 ---------- */
    assign io_slave_rresp = 0;
    assign io_slave_rlast = 0;
    assign io_slave_rid = 0;
    assign io_slave_bid = 0;
/*----------------------------------*/


    reg [31:0] read_data_buffer;
    reg        ar_ready, aw_ready, w_ready, b_valid, r_valid;

    reg [7:0] lfsr;
    reg [3:0] delay_counter;
    wire lfsr_out = lfsr[0];

    //延时
    always@(posedge clk or posedge rst) begin
        if(rst) begin
            lfsr <= 8'hff;
        end else begin
            lfsr <= {lfsr[6:0], lfsr[7] ^ lfsr[5]};
        end
    end


    // 读操作（无问题）
    always@(posedge clk or posedge rst) begin
        if(rst) begin
            io_slave_arready <= 1'b1;
            io_slave_rvalid <= 1'b0;
        end else begin
            if(io_slave_arvalid && io_slave_arready) begin
                io_slave_arready <= 1'b0;
                io_slave_rdata <= dmem_read(io_slave_araddr);
                //$display("AAA: %08x %08x\n",io_slave_araddr, io_slave_rdata);
                io_slave_rvalid <= 1'b1;
            end 
            else if (io_slave_rready /*&& io_slave_rvalid*/) begin
                io_slave_arready <= 1'b1;
                io_slave_rvalid <= 1'b0;
            end
        end
    end

    //读操作延时测试
    reg valid_issued; // 标记是否已发出o_rvalid
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            io_slave_arready <= 1'b1;
            io_slave_rvalid <= 1'b0;
            delay_counter <= 0;
            valid_issued <= 1'b0; // 初始状态未发出有效信号
        end else begin
            if (io_slave_arvalid && io_slave_arready) begin
                io_slave_arready <= 1'b0;
                io_slave_rdata <= dmem_read(io_slave_araddr);
                delay_counter <= lfsr_out ? 4'd5 : 4'd10; // 初始化延迟计数器
                valid_issued <= 1'b1; // 标记已发出请求
            end else if (valid_issued) begin
                if (delay_counter > 0) begin
                    delay_counter <= delay_counter - 1; // 递减延迟计数器
                end else begin
                    if (!io_slave_rvalid) begin
                        io_slave_rvalid <= 1'b1; // 在延迟结束后拉高o_rvalid
                    end

                    // 当收到i_rready时，准备重置状态
                    if (io_slave_rready) begin
                        io_slave_arready <= 1'b1; // 拉高o_arready
                        io_slave_rvalid <= 1'b0; // 拉低o_rvalid
                        valid_issued <= 1'b0; // 重置标记
                    end
                end
            end
        end
    end


    //写操作
    reg [31:0] waddr_temp;
    //reg write_in_progress;
    always@(posedge clk or posedge rst) begin
        if(rst) begin
            io_slave_awready <= 1'b0;
            io_slave_wready <= 1'b1;
        end else begin
            if(io_slave_awvalid && !io_slave_awready) begin
                io_slave_awready <= 1'b1;
                waddr_temp <= io_slave_awaddr;
                io_slave_wready <= 0;
                //io_slave_awready <= 1;
            end
            if(io_slave_wvalid && io_slave_awready) begin
                pmem_write(waddr_temp, io_slave_wdata, {4'b0,io_slave_wstrb});
                //$display("AAA: %x %x %x\n",waddr_temp, io_slave_wdata, io_slave_wstrb);
                io_slave_wready <= 1'b1;
                io_slave_awready <= 1'b0;
            end
        end
    end




endmodule
