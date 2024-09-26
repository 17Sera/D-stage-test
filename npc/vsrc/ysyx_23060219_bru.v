// // 都可
// `include "/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_defines.v"

// module bru(
//     // system
//     input  wire            clk,
//     input  wire            rst,
//     // from IFU
//     input  wire [`CPU_Bus] i_bru_pc,
//     // from LSU
//     input  wire [`CPU_Bus] i_bru_imm,
//     input  wire            i_bru_is_jal,
//     input  wire            i_bru_is_jalr,
//     input  wire            i_bru_brch,
//     input  wire            i_bru_ejump,
//     input  wire [`CPU_Bus] i_bru_csr_npc,
//     // from Register File
//     input  wire [31:0]     i_bru_rs1,
//     // from WBU
//     input  wire            i_bru_npc_wen,
//     // to IFU
//     output wire [`CPU_Bus] o_bru_npc
// );
    
//     wire [`CPU_Bus] pc_jorb;
//     wire [`CPU_Bus] npc_t1, npc_t2;
//     wire [31:0]  temp = {{(`CPU_Width - 1){1'b1}}, 1'b0};  //for example, CPU_Width = 32，then temp = 0xfffe
    
//     ysyx_23060219_MuxKey #(2, 1, `CPU_Width) mux1(pc_jorb, i_bru_is_jalr, {   // 单独判断 jalr
//         `FALSE, i_bru_pc + i_bru_imm,               // jal or branch instruction
//         `TRUE,  (i_bru_rs1 + i_bru_imm) & temp}     // jalr
//     );

//     ysyx_23060219_MuxKey #(2, 1, `CPU_Width) mux2(npc_t1, (i_bru_is_jalr | i_bru_is_jal | i_bru_brch), {  //是否是跳转
//         `FALSE, i_bru_pc + `CPU_Width'h4,           // pc + 4        
//         `TRUE,  pc_jorb}                            // jalr pr jal or branch instruction 全部跳转指令
//     );

//     ysyx_23060219_MuxKey #(2, 1, `CPU_Width) mux3(npc_t2, (i_bru_ejump), {
//         `FALSE, npc_t1,             // pc + 4 或其他跳转指令        
//         `TRUE,  i_bru_csr_npc}      // mret or ecall
//     );

//     reg [`CPU_Bus] npc_reg;
//     always @(posedge clk) begin
//         if(rst == 1'b1) 
//             npc_reg <= `RESET_VECTOR;
//         else if(i_bru_npc_wen == 1'b1)
//             npc_reg <= npc_t2;
//     end
    
//     assign o_bru_npc = npc_reg;

// endmodule

//=======================================================================================================================
// add arbiter

`include "/home/zhong/ysyx-workbench/npc/vsrc/ysyx_23060219_defines.v"

module ysyx_23060219_bru(
    // system
    input  wire            clk,
    input  wire            rst,
    // from from from from IFU
    input  wire [`CPU_Bus] i_bru_pc,
    // from from from LSU
    input  wire [`CPU_Bus] i_bru_imm,
    input  wire            i_bru_is_jal,
    input  wire            i_bru_is_jalr,
    input  wire            i_bru_brch,
    input  wire            i_bru_ejump,
    input  wire [`CPU_Bus] i_bru_csr_npc,
    // from from from Register File
    input  wire [31:0]  i_bru_rs1,
    // from WBU
    input  wire            i_bru_npc_wen,
    // to IFU
    output wire [`CPU_Bus] o_bru_npc
);
    
    wire [`CPU_Bus] pc_jorb;
    wire [`CPU_Bus] npc_t1, npc_t2;
    wire [31:0]  temp = {{(`CPU_Width - 1){1'b1}}, 1'b0};  //for example, CPU_Width = 32，then temp = 0xfffe
    
    ysyx_23060219_MuxKey #(2, 1, `CPU_Width) mux1(pc_jorb, i_bru_is_jalr, {
        `FALSE, i_bru_pc + i_bru_imm,               // jal or branch instruction
        `TRUE,  (i_bru_rs1 + i_bru_imm) & temp}     // jalr
    );

    ysyx_23060219_MuxKey #(2, 1, `CPU_Width) mux2(npc_t1, (i_bru_is_jalr | i_bru_is_jal | i_bru_brch), {
        `FALSE, i_bru_pc + `CPU_Width'h4,           // pc + 4        
        `TRUE,  pc_jorb}                            // jalr pr jal or branch instruction
    );

    ysyx_23060219_MuxKey #(2, 1, `CPU_Width) mux3(npc_t2, (i_bru_ejump), {
        `FALSE, npc_t1,             // pc + 4        
        `TRUE,  i_bru_csr_npc}      // mret or ecall
    );

    reg [`CPU_Bus] npc_reg;
    always @(posedge clk) begin
        if(rst == 1'b1) 
            npc_reg <= `RESET_VECTOR;
        else if(i_bru_npc_wen == 1'b1)
            npc_reg <= npc_t2;
    end
    
    assign o_bru_npc = npc_reg;

endmodule
