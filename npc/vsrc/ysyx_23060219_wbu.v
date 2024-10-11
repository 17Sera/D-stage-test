
`include "/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_defines.v"

module ysyx_23060219_wbu(
    // system
    input  wire             clk,
    input  wire             rst,
    // shake hands
    input  reg              i_pre_valid,   //来自LSU，代表LSU的数据有效
    output wire             o_pre_ready,   //传递给LSU，代表WBU准备好处理新数据了
    output reg              o_cycle_end,   //传递给IFU，代表一个指令周期的结束，置位于第5时钟周期
    // from IFU
    input  wire [`CPU_Bus]  i_wbu_pc,
    // from IDU
    input  wire [4:0]       i_wbu_rd_id,
    input  wire             i_wbu_gpr_wen,  
    // from Register File
    input  wire [31:0]      i_wbu_rs1,
    // from CSR Ctrl
    input  wire             i_wbu_is_mret,
    input  wire             i_wbu_is_ecall,
    input  wire [`CSR_Bus]  i_wbu_csr_wid,
    input  wire [31:0]      i_wbu_csr_rd,
    input  wire             i_wbu_csr_wen,
    // from LSU
    input  wire [31:0]      i_wbu_rd,
    // to BRU
    output wire             o_wbu_npc_wen,
    // to Register File
    output wire [31:0]      o_wbu_rd,
    output wire [4:0]       o_wbu_rd_id,
    output wire             o_wbu_gpr_wen,
    // to CSR Ctrl
    output wire [31:0]      o_wbu_mcause_in,
    output wire [31:0]      o_wbu_mepc_in,
    output wire             o_wbu_csr_wen,  
    output wire [`CSR_Bus]  o_wbu_csr_wid,
    output wire [31:0]      o_wbu_csr_rd
);

    reg pre_valid_reg;
    always @(posedge clk) begin
        if(rst == 1'b1) 
            pre_valid_reg <= 1'b0;
        else
            pre_valid_reg <= i_pre_valid;
    end

    reg delay_cycle_end_1, delay_cycle_end_2, delay_cycle_end_3;
    reg delay_cycle_end_4, delay_cycle_end_5; // 新增两个寄存器
    reg delay_cycle_end_6, delay_cycle_end_7, delay_cycle_end_8;
    reg delay_cycle_end_9, delay_cycle_end_10;


always @(posedge clk) begin
    if (rst == 1'b1) 
        delay_cycle_end_1 <= 1'b0;
    else 
        delay_cycle_end_1 <= i_pre_valid & ~pre_valid_reg;
end

always @(posedge clk) begin
    if (rst == 1'b1) 
        delay_cycle_end_2 <= 1'b0;
    else 
        delay_cycle_end_2 <= delay_cycle_end_1;
end

always @(posedge clk) begin
    if (rst == 1'b1) 
        delay_cycle_end_3 <= 1'b0;
    else 
        delay_cycle_end_3 <= delay_cycle_end_2;
end

always @(posedge clk) begin
    if (rst == 1'b1) 
        delay_cycle_end_4 <= 1'b0;
    else 
        delay_cycle_end_4 <= delay_cycle_end_3;
end

always @(posedge clk) begin
    if (rst == 1'b1) 
        delay_cycle_end_5 <= 1'b0;
    else 
        delay_cycle_end_5 <= delay_cycle_end_4;
end

always @(posedge clk) begin
    if (rst == 1'b1) 
        delay_cycle_end_6 <= 1'b0;
    else 
        delay_cycle_end_6 <= delay_cycle_end_5;
end

always @(posedge clk) begin
    if (rst == 1'b1) 
        delay_cycle_end_7 <= 1'b0;
    else 
        delay_cycle_end_7 <= delay_cycle_end_6;
end

always @(posedge clk) begin
    if (rst == 1'b1) 
        delay_cycle_end_8 <= 1'b0;
    else 
        delay_cycle_end_8 <= delay_cycle_end_7;
end

always @(posedge clk) begin
    if (rst == 1'b1) 
        delay_cycle_end_9 <= 1'b0;
    else 
        delay_cycle_end_9 <= delay_cycle_end_8;
end

always @(posedge clk) begin
    if (rst == 1'b1) 
        delay_cycle_end_10 <= 1'b0;
    else 
        delay_cycle_end_10 <= delay_cycle_end_9;
end


always @(posedge clk) begin
    if (rst == 1'b1) 
        o_cycle_end <= 1'b1;
    else 
        o_cycle_end <= delay_cycle_end_8; // 使用第五个延迟信号
        o_wbu_npc_wen <= delay_cycle_end_7;
end


    // to IFU
    assign o_pre_ready     = ~o_cycle_end;

    // to Register File
    assign o_wbu_rd        = i_wbu_rd;
    assign o_wbu_rd_id     = i_wbu_rd_id;
    assign o_wbu_gpr_wen   = i_wbu_gpr_wen & o_wbu_npc_wen;    //只有效一周期，防止反复写入gpr
    // to CSR Ctrl
    assign o_wbu_mcause_in = i_wbu_rs1;
    assign o_wbu_mepc_in   = i_wbu_pc;
    assign o_wbu_csr_wen   = i_wbu_csr_wen;
    assign o_wbu_csr_wid   = i_wbu_csr_wid;
    assign o_wbu_csr_rd    = i_wbu_csr_rd;

endmodule

//=======================================================================================================

// // // // 都可

// `include "/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_defines.v"

// module wbu(
//     // system
//     input  wire            clk,
//     input  wire            rst,
//     // shake hands
//     input  wire            i_pre_valid,   //来自LSU，代表LSU的数据有效
//     output wire            o_pre_ready,   //传递给LSU，代表WBU准备好处理新数据了
//     output reg             o_cycle_end,   //传递给IFU，代表一个指令周期的结束，置位于第5时钟周期
//     // from IFU
//     input  wire [31:0]     i_wbu_pc ,   //来自IFU，代表当前指令的PC
//     // from IDU
//     input  wire [4:0]      i_wbu_rd_id,     //来自IDU，代表当前指令的rd
//     input  wire            i_wbu_gpr_wen,   //来自IDU，代表当前指令的gpr写入使能
//     // from Register File
//     input  wire [31:0]     i_wbu_rs1,       
//     // from CSR Ctrl
//     input  wire            i_wbu_is_mret,   
//     input  wire            i_wbu_is_ecall,
//     input  wire [`CSR_Bus] i_wbu_csr_wid,   //来自CSR Ctrl，代表当前指令的csr写入id
//     input  wire [31:0]     i_wbu_csr_rd,    //来自CSR Ctrl，代表当前指令的csr读取值
//     input  wire            i_wbu_csr_wen,   //来自CSR Ctrl，代表当前指令的csr写入使能
//     // from LSU
//     input  wire [31:0]     i_wbu_rd,        //来自LSU，代表当前指令的rd
//     // to BRU
//     output wire            o_wbu_npc_wen,   //传递给BRU，代表写入npc_reg
//     // to Register File
//     output wire [31:0]     o_wbu_rd,        //传递给Register File，代表当前指令的rd
//     output wire [4:0]      o_wbu_rd_id,     
//     output wire            o_wbu_gpr_wen,   //传递给Register File，代表当前指令的gpr写入使能
//     // to CSR Ctrl
//     output wire [31:0]     o_wbu_mcause_in, //传递给CSR Ctrl，代表当前指令的mcause写入值
//     output wire [31:0]     o_wbu_mepc_in,   //传递给CSR Ctrl，代表当前指令的mepc写入值
//     output wire            o_wbu_csr_wen,   //传递给CSR Ctrl，代表当前指令的csr写入使能
//     output wire [`CSR_Bus] o_wbu_csr_wid,   //传递给CSR Ctrl，代表当前指令的csr写入id
//     output wire [31:0]     o_wbu_csr_rd     //传递给CSR Ctrl，代表当前指令的csr读取值
// );

//     reg pre_valid_reg;
//     always @(posedge clk) begin
//         if(rst == 1'b1) 
//             pre_valid_reg <= 1'b0;
//         else
//             pre_valid_reg <= i_pre_valid;   
//     end
   
//     always @(posedge clk) begin
//         if(rst == 1'b1) 
//             o_cycle_end <= 1'b1;
//         else
//             o_cycle_end <= i_pre_valid & ~pre_valid_reg;
//     end

//     // to IFU
//     assign o_pre_ready     = ~o_cycle_end;
//     // to BRU
//     assign o_wbu_npc_wen   = i_pre_valid & ~pre_valid_reg;    //只有效一周期，防止反复写入npc_reg
//     // to Register File
//     assign o_wbu_rd        = i_wbu_rd;
//     assign o_wbu_rd_id     = i_wbu_rd_id;
//     assign o_wbu_gpr_wen   = i_wbu_gpr_wen & o_wbu_npc_wen;    //只有效一周期，防止反复写入gpr
//     // to CSR Ctrl
//     assign o_wbu_mcause_in = i_wbu_rs1;
//     assign o_wbu_mepc_in   = i_wbu_pc;
//     assign o_wbu_csr_wen   = i_wbu_csr_wen;
//     assign o_wbu_csr_wid   = i_wbu_csr_wid;
//     assign o_wbu_csr_rd    = i_wbu_csr_rd;

// endmodule