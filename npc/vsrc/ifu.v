`include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"
`define IFU_PKG_WDITH  (`CPU_Width+`CPU_Width)

module ifu(
    // system
    input  wire            clk,
    input  wire            rst,
    // shake hands握手                    //IFU收到WBU的完成信号i_cycle_end后再取下一条指令
    input  wire            i_cycle_end,   //输入信号，指示一个指令周期的结束，置位于第5时钟周期---线w_wbu_cycle_end连接上WBU的o_cycle_end信号---WBU输入给IFU
    output wire            o_post_valid,  //输出信号，表示IFU数据包有效，传递给IDU---线w_ifu_valid连接上IDU的i_pre_valid信号---IFU输入给IDU
    input  wire            i_post_ready,  //输入信号，来自IDU，表示IDU准备好处理新数据---IDU输入给IFU
    // from BRU
    input  wire [31:0]     i_ifu_npc,     //输入信号，来自BRU模块，表示下一条指令的PC值----线w_bru_npc连接上BRU的o_bru_npc信号
    // to IDU
    output wire [31:0]     o_ifu_pc,      //输出信号，传递给IDU的当前PC值---线w_ifu_pc连接上IDU的i_idu_pc信号
    output wire [31:0]     o_ifu_inst     //输出信号，传递给IDU的当前指令---线w_ifu_inst连接上IDU的i_idu_inst信号
);

    import "DPI-C" function int  imem_read(input int raddr);    // 从raddr读取指令存储器中的指令

    // ⌈‾‾‾‾‾⌉ -->i_cycle_end --> ⌈‾‾‾‾‾⌉ --> o_post_valid-->i_pre_valid --> ⌈‾‾‾‾‾⌉ --> o_post_valid --> i_pre_valid -->⌈‾‾‾‾‾⌉ --> o_post_valid --> i_pre_valid -->⌈‾‾‾‾‾⌉ --> o_post_valid --> i_pre_valid -->⌈‾‾‾‾‾⌉   
    // | WBU |                   | IFU |                                   | IDU |                                     | EXU |                                    | LSU |                                    | WBU |
    // ⌊_____⌋                    ⌊_____⌋ <-- i_post_ready<-- o_pre_ready <--⌊_____⌋<-- i_post_ready <-- o_pre_ready <-- ⌊_____⌋<-- i_post_ready <-- o_pre_ready <-- ⌊_____⌋<-- i_post_ready <-- o_pre_ready <-- ⌊_____⌋                            

// data package
    wire [31:0]                 ifu_inst = imem_read(i_ifu_npc);    // 调用 imem_read 函数从指令存储器中读取 i_ifu_npc 地址上的指令
    reg  [`IFU_PKG_WDITH-1 : 0] ifu_valid_data_reg;                 //保存有效的数据包，包括 PC 和指令
    wire                        ifu_reg_wen  = i_cycle_end;         //数据包寄存器的写使能，表示指令周期结束，允许写入新的指令和PC值


// 数据包寄存器更新
    always @(posedge clk) begin
        if(rst == 1'b1) 
            ifu_valid_data_reg <= 0;
        else if(ifu_reg_wen == 1'b1)
            ifu_valid_data_reg <= {i_ifu_npc, ifu_inst};    // 保存了下一个指令和下一个PC
    end


// 输出数据包 to IDU
    assign {o_ifu_pc, o_ifu_inst} = ifu_valid_data_reg;     // 将数据包中的PC和指令输出给IDU
    

// 握手shake hands
    assign o_post_valid = ~i_cycle_end;     // 当 i_cycle_end 为 0 时数据包是有效的
    //当 i_cycle_end 为 1 时，指令周期结束，数据包的有效性也结束，确保数据在周期结束时不会被错误地处理
    //当 i_cycle_end 为0时，说明指令周期尚未结束，数据包仍然有效，此时 o_post_valid 输出1


endmodule

//======================================================================================================

// `include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"
// `define IFU_PKG_WDITH  (`CPU_Width+`CPU_Width)

// module ifu(
//     // system
//     input  wire            clk,
//     input  wire            rst,
//     // shake hands握手                    //IFU收到WBU的完成信号i_cycle_end后再取下一条指令
//     input  wire            i_cycle_end,   //输入信号，指示一个指令周期的结束，置位于第5时钟周期---线w_wbu_cycle_end连接上WBU的o_cycle_end信号---WBU输入给IFU
//     output wire            o_post_valid,  //输出信号，表示IFU数据包有效，传递给IDU---线w_ifu_valid连接上IDU的i_pre_valid信号---IFU输入给IDU
//     input  wire            i_post_ready,  //输入信号，来自IDU，表示IDU准备好处理新数据---IDU输入给IFU
//     // from BRU ----- to imem read
//     input  wire [31:0]     i_ifu_npc,     //输入信号，来自BRU模块，表示下一条指令的PC值----线w_bru_npc连接上BRU的o_bru_npc信号
//     // to IDU
//     output wire [31:0]     o_ifu_pc,      //输出信号，传递给IDU的当前PC值---线w_ifu_pc连接上IDU的i_idu_pc信号
//     output wire [31:0]     o_ifu_inst     //输出信号，传递给IDU的当前指令---线w_ifu_inst连接上IDU的i_idu_inst信号
//     // 连接 SRAM 取出指令----------------------------------------------------------------------------------------
//     output reg  [31:0]      o_sram_araddr,  //读地址 ----- 给 sram 传入 i_ifu_npc
//     output reg              o_sram_arvalid,
//     input  wire             i_sram_arready,
//     input  reg  [31:0]      i_sram_rdata,  //读数据 ----- 读指令
//     input  reg              i_sram_rresp,  //读回复, 表示是否读正确
//     input  reg              i_sram_rvalid,
//     output wire             o_sram_rready,
//     // IFU的AW, W和B三个通道的握手信号均置为0
//     output wire [31:0]      o_sram_awaddr,  //写地址
//     output wire             o_sram_awvalid,
//     input  wire             i_sram_awready,
//     output wire [31:0]      o_sram_wdata,   //写数据
//     output wire [7:0]       o_sram_wstrb,   //写掩码
//     output wire             o_sram_wvalid,
//     input  wire             i_sram_wready,
//     input  reg              i_sram_bresp,   //写回复  是否写正确  需要握手
//     input  reg              i_sram_bvalid,
//     output wire             o_sram_bready
// );

// // data package
//     //wire [31:0]                 ifu_inst = imem_read(i_ifu_npc);    // 调用 imem_read 函数从指令存储器中读取 i_ifu_npc 地址上的指令
//     reg  [`IFU_PKG_WDITH-1 : 0] ifu_valid_data_reg;                 //保存有效的数据包，包括 PC 和指令
//     wire                        ifu_reg_wen  = i_cycle_end;         //数据包寄存器的写使能，表示指令周期结束，允许写入新的指令和PC值
//     reg [1:0] state, next_state;


// // IFU 的 state
// always @(*) begin
//         case (state)
//             `IDLE_IFU:  if (i_ifu_npc != 32'b0) next_state = `READ_IFU;    //空闲状态idle
//                     else next_state = `IDLE_IFU;
//             `READ_IFU:  if (i_sram_arready)    next_state = `WAIT_IFU;
//                     else next_state = `READ_IFU;
//             `WAIT_IFU:  if (i_sram_rvalid)     next_state = `IDLE_IFU;
//                     else                       next_state = `WAIT_IFU;
//             default: next_state = `IDLE_IFU;
//         endcase
//     end


// // IFU的AW, W和B三个通道的握手信号均置为0
//     always @(*) begin
//         o_sram_araddr  = i_ifu_npc;
//         o_sram_arvalid = (state == `READ_IFU);
//         o_sram_rready  = (state == `WAIT_IFU);
//         // 默认状态下不进行写操作
//         o_sram_awaddr  = 32'b0;
//         o_sram_awvalid = 1'b0;
//         o_sram_wdata   = 32'b0;
//         o_sram_wstrb   = `WWord;
//         o_sram_wvalid  = 1'b0;
//         o_sram_bready  = 1'b0;
//     end


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
