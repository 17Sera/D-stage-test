// `include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"

// module SRAM (
//     input  wire             clk,
//     input  wire             rst,
//     /*------------ 读地址 ------------*/
//     input  reg  [31:0]      i_araddr,   // 接收地址
//     input  reg              i_arvalid,  // 接收地址有效信号
//     output wire             o_arready,  // SRAM准备好接收地址
//     /*------------ 读数据 ------------*/
//     output reg  [31:0]      o_rdata,    // 返回所需数据
//     output reg              o_rresp,    // 悬空
//     output reg              o_rvalid,   // 返回数据有效信号
//     input  wire             i_rready,   // 接收方准备好接收数据
//     /*------------ 写地址 ------------*/
//     input  wire [31:0]      i_awaddr,   //下面都悬空
//     input  wire             i_awvalid,
//     output wire             o_awready,
//     /*------------ 写数据 ------------*/
//     input  wire [31:0]      i_wdata, 
//     input  wire [7:0]       i_wstrb,    
//     input  wire             i_wvalid,
//     output wire             o_wready,
//     /*------------ 写回复 ------------*/
//     output reg              o_bresp,
//     output reg              o_bvalid,
//     input  wire             i_bready
// );
//     import "DPI-C" function int  dmem_read(input int i_araddr); //用于利用从软件读取指令、数据
//     import "DPI-C" function void pmem_write(input int i_awaddr, input int i_wdata, input byte wmask); //用于将数据写入软件

//     reg [31:0] read_data_buffer;
//     reg        ar_ready, aw_ready, w_ready, b_valid, r_valid;

//     reg [7:0] lfsr;     //模拟内存操作的延时
//     reg [3:0] delay_counter;
//     wire lfsr_out = lfsr[0];    //获取lfsr的最低位作为伪随机序列的当前输出值

//     //延时
//     always@(posedge clk or posedge rst) begin
//         if(rst) begin
//             lfsr <= 8'hff;
//         end 
//         else begin
//             lfsr <= {lfsr[6:0], lfsr[7] ^ lfsr[5]}; //LFSR的更新规则
//         end
//     end


//     //读操作延时测试
//     reg valid_issued; // 标记是否已发出o_rvalid
//     always @(posedge clk or posedge rst) begin
//         if (rst) begin
//             o_arready <= 1'b1;  // 初始状态可以接收地址
//             o_rvalid <= 1'b0;   // 初始状态没有有效的数据可以被读取
//             delay_counter <= 0;
//             valid_issued <= 1'b0; // 初始状态，没有正在处理的有效数据请求
//         end 
        
//         else begin
//             if (i_arvalid && o_arready) begin   // 握手---表示可以接收新的地址
//                 o_arready <= 1'b0;  //接收地址的ready重新拉低，防止再次读取新地址，直到当前的数据处理完成
//                 o_rdata <= dmem_read(i_araddr); //从模拟的内存中读取数据

//                 delay_counter <= lfsr_out ? 4'd5 : 4'd10; // 初始化延迟计数器

//                 valid_issued <= 1'b1; // 表示有一个有效的数据请求正在处理中
//             end 
//             else if (valid_issued) begin
//                 if (delay_counter > 0) begin
//                     delay_counter <= delay_counter - 1; // 递减延迟计数器，模拟数据读取延时
//                 end 
//                 else begin  //delay_counter=0，表示延迟结束
//                     if (!o_rvalid) begin
//                         o_rvalid <= 1'b1; // 在延迟结束后拉高o_rvalid，表示数据现在可以被接收方读取
//                     end
//                     // 当收到i_rready时，握手传递数据，准备重置状态
//                     if (i_rready) begin
//                         o_arready <= 1'b1; // 拉高o_arready---表示可以接收新的地址
//                         o_rvalid <= 1'b0;  // 拉低o_rvalid---表示下一个数据未准备好---防止误读数据
//                         valid_issued <= 1'b0; // 重置标记，表示没有正在处理的有效数据
//                     end
//                 end
//             end
//         end
//     end



// endmodule



//==================================================================================

`include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"

module SRAM (
    input  wire             clk,
    input  wire             rst,
    /************ 读地址 ************/
    input  reg  [31:0]   i_araddr,
    input  reg              i_arvalid, //写使能
    output wire             o_arready,
    /************ 读数据 ************/
    output reg  [31:0]   o_rdata,
    output reg              o_rresp,
    output reg              o_rvalid,
    input  wire             i_rready,
    /************ 写地址 ************/
    input  reg  [31:0]   i_awaddr,
    input  reg              i_awvalid,
    output wire             o_awready,
    /************ 写数据 ************/
    input  reg [31:0]    i_wdata, 
    input  reg [7:0]        i_wstrb,  // 写字节使能  写掩码
    input  reg              i_wvalid,
    output wire             o_wready,
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
                //$display("%x\n",o_rdata);
                o_rvalid <= 1'b1;
            end 
            else if (i_rready /*&& o_rvalid*/) begin
                o_arready <= 1'b1;
                o_rvalid <= 1'b0;
            end
        end
    end

    //读操作延时测试
    // reg valid_issued; // 标记是否已发出o_rvalid
    // always @(posedge clk or posedge rst) begin
    //     if (rst) begin
    //         o_arready <= 1'b1;
    //         o_rvalid <= 1'b0;
    //         delay_counter <= 0;
    //         valid_issued <= 1'b0; // 初始状态未发出有效信号
    //     end else begin
    //         if (i_arvalid && o_arready) begin
    //             o_arready <= 1'b0;
    //             o_rdata <= dmem_read(i_araddr);
    //             delay_counter <= lfsr_out ? 4'd5 : 4'd10; // 初始化延迟计数器
    //             valid_issued <= 1'b1; // 标记已发出请求
    //         end else if (valid_issued) begin
    //             if (delay_counter > 0) begin
    //                 delay_counter <= delay_counter - 1; // 递减延迟计数器
    //             end else begin
    //                 if (!o_rvalid) begin
    //                     o_rvalid <= 1'b1; // 在延迟结束后拉高o_rvalid
    //                 end

    //                 // 当收到i_rready时，准备重置状态
    //                 if (i_rready) begin
    //                     o_arready <= 1'b1; // 拉高o_arready
    //                     o_rvalid <= 1'b0; // 拉低o_rvalid
    //                     valid_issued <= 1'b0; // 重置标记
    //                 end
    //             end
    //         end
    //     end
    // end


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
                o_wready <= 1'b1;
                o_awready <= 1'b0;
            end
            // if(o_wready) begin
            //     o_wready <= 0;
            // end
        end
    end



    // // 读操作
    // reg [`CPU_Bus] inst;
    // assign o_arready = ar_ready;

    // always@(posedge clk or posedge rst) begin
    //     if(rst) begin
    //         ar_ready <= 1'b1;
    //     end else begin
    //         if(i_arvalid && ar_ready) begin
    //             inst <= dmem_read(i_araddr);
    //             ar_ready <= 1'b0;
    //             delay_counter <= lfsr_out ? 4'd5 : 4'd10;
    //         end
    //         if(delay_counter == 4'b0 && i_rready) begin
    //             o_rvalid <= 1'b1;
    //             o_rdata <= inst;
    //             ar_ready <= 1'b1;
    //         end else begin
    //             delay_counter <= delay_counter - 1;
    //         end
    //     end
    // end

    // always@(posedge clk or posedge rst) begin
    //     if(rst) begin
    //         ar_ready <= 1'b1;
    //     end else begin
    //         if(i_arvalid && ar_ready) begin
    //             inst <= dmem_read(i_araddr);
    //             ar_ready <= 1'b0;
    //         end
    //         if(!ar_ready) begin
    //             o_rvalid <= 1'b1;
    //             o_rdata <= inst;
    //             ar_ready <= 1'b1;
    //         end
    //     end
    // end


    // //读地址握手
    // always @(posedge clk or posedge reset) begin
    //     if (reset) begin
    //         ar_ready <= 1'b0;
    //         delay_counter <= 4'b0;
    //     end else begin
    //         if (i_arvalid && !ar_ready) begin
    //             delay_counter <= lfsr_out ? 4'd5 : 4'd10; // delays
    //             ar_ready <= 1'b1;
    //         end else if (r_valid && i_rready) begin
    //             if (delay_counter == 4'd0) begin
    //                 ar_ready <= 1'b0;
    //             end else begin
    //                 delay_counter <= delay_counter - 1;
    //             end
    //         end
    //     end
    // end
    // assign o_arready = ar_ready; 


    // always @(posedge clk or posedge reset) begin
    //     if (reset) begin
    //         r_valid <= 1'b0;
    //         o_rdata <= 32'b0;
    //         o_rresp <= 2'b0;
    //         read_data_buffer <= 32'b0;
    //     end else begin
    //         if (i_arvalid && ar_ready) begin
    //             read_data_buffer <= dmem_read(i_araddr);
    //             r_valid <= 1'b1;
    //             o_rresp <= 2'b0;
    //         end
    //         if (i_rready && r_valid) begin
    //             if (delay_counter == 4'd0) begin
    //                 o_rdata <= read_data_buffer;
    //                 r_valid <= 1'b0;
    //             end
    //         end
    //     end
    // end
    // assign o_rvalid = r_valid;

    // // 写地址握手
    // always @(posedge clk or posedge reset) begin
    //     if (reset) begin
    //         aw_ready <= 1'b0;
    //         delay_counter <= 4'b0;
    //     end else begin
    //         if (i_awvalid && !aw_ready) begin
    //             delay_counter <= lfsr_out ? 4'd5 : 4'd10; // delays
    //             aw_ready <= 1'b1;
    //         end else if (b_valid) begin
    //             if (delay_counter == 4'd0) begin
    //                 aw_ready <= 1'b0;
    //             end else begin
    //                 delay_counter <= delay_counter - 1;
    //             end
    //         end
    //     end
    // end
    // assign o_awready = aw_ready;

    // // 写数据握手
    // always @(posedge clk or posedge reset) begin
    //     if (reset) begin
    //         w_ready <= 1'b0;
    //         delay_counter <= 4'b0;
    //     end else begin
    //         if (i_wvalid && !w_ready) begin
    //             delay_counter <= lfsr_out ? 4'd5 : 4'd10; // delays
    //             w_ready <= 1'b1;
    //         end else if (b_valid) begin
    //             if (delay_counter == 4'd0) begin
    //                 w_ready <= 1'b0;
    //             end else begin
    //                 delay_counter <= delay_counter - 1;
    //             end
    //         end
    //     end
    // end
    // assign o_wready = w_ready;

    // // 写数据处理
    // always @(posedge clk or posedge reset) begin
    //     if (reset) begin
    //         b_valid <= 1'b0;
    //     end else begin
    //         if (i_awvalid && aw_ready && i_wvalid && w_ready) begin
    //             // Write to memory
    //             pmem_write(i_awaddr, i_wdata, i_wstrb);
    //             b_valid <= 1'b1;
    //         end
    //         if (b_valid) begin
    //             b_valid <= 1'b0;
    //         end
    //     end
    // end
    // assign o_bresp = 1'b0;
    // assign o_bvalid = 1'b0;

endmodule