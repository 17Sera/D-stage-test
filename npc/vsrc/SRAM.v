`include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"

module SRAM (
    input  wire             clk,
    input  wire             rst,
    /************ 读地址 ************/
    input  reg  [31:0]   i_araddr,
    input  reg              i_arvalid, //写使能
    output reg              o_arready,
    /************ 读数据 ************/
    output reg  [31:0]   o_rdata,
    output reg              o_rresp,
    output reg              o_rvalid,
    input  reg              i_rready,
    /************ 写地址 ************/
    input  reg  [31:0]   i_awaddr,
    input  reg              i_awvalid,
    output reg              o_awready,
    /************ 写数据 ************/
    input  reg [31:0]    i_wdata, 
    input  reg [7:0]        i_wstrb,  // 写字节使能  写掩码
    input  reg              i_wvalid,
    output reg              o_wready,
    /************ 写回复 ************/
    output reg              o_bresp,
    output reg              o_bvalid,
    input  wire             i_bready
);
    import "DPI-C" function int  dmem_read(input int i_araddr); //用于利用从软件读取指令、数据
    import "DPI-C" function void pmem_write(input int i_awaddr, input int i_wdata, input byte wmask); //用于将数据写入软件

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
            o_arready <= 1'b1;
            o_rvalid <= 1'b0;
        end else begin
            if(i_arvalid && o_arready) begin
                o_arready <= 1'b0;
                o_rdata <= dmem_read(i_araddr);
                //$display("AAA: %08x %08x\n",i_araddr, o_rdata);
                o_rvalid <= 1'b1;
            end 
            else if (i_rready /*&& o_rvalid*/) begin
                o_arready <= 1'b1;
                o_rvalid <= 1'b0;
            end
        end
    end

    //读操作延时测试
    reg valid_issued; // 标记是否已发出o_rvalid
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            o_arready <= 1'b1;
            o_rvalid <= 1'b0;
            delay_counter <= 0;
            valid_issued <= 1'b0; // 初始状态未发出有效信号
        end else begin
            if (i_arvalid && o_arready) begin
                o_arready <= 1'b0;
                o_rdata <= dmem_read(i_araddr);
                delay_counter <= lfsr_out ? 4'd5 : 4'd10; // 初始化延迟计数器
                valid_issued <= 1'b1; // 标记已发出请求
            end else if (valid_issued) begin
                if (delay_counter > 0) begin
                    delay_counter <= delay_counter - 1; // 递减延迟计数器
                end else begin
                    if (!o_rvalid) begin
                        o_rvalid <= 1'b1; // 在延迟结束后拉高o_rvalid
                    end

                    // 当收到i_rready时，准备重置状态
                    if (i_rready) begin
                        o_arready <= 1'b1; // 拉高o_arready
                        o_rvalid <= 1'b0; // 拉低o_rvalid
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
            o_awready <= 1'b0;
            o_wready <= 1'b1;
        end else begin
            if(i_awvalid && !o_awready) begin
                o_awready <= 1'b1;
                waddr_temp <= i_awaddr;
                o_wready <= 0;
                //o_awready <= 1;
            end
            if(i_wvalid && o_awready) begin
                pmem_write(waddr_temp, i_wdata, i_wstrb);
                //$display("AAA: %x %x %x\n",waddr_temp, i_wdata, i_wstrb);
                o_wready <= 1'b1;
                o_awready <= 1'b0;
            end
        end
    end




endmodule
