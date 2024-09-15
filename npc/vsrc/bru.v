`include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"

module bru(     //Branch Resolution Unit 处理和决策分支指令 决定下一条指令的地址
    // system
    input  wire             clk,
    input  wire             rst,
    //from IFU
    input  wire [31:0]      i_bru_pc,
    //from LSU
    input  wire [31:0]      i_bru_imm,
    input  wire             i_bru_is_jal,
    input  wire             i_bru_is_jalr,
    input  wire             i_bru_brch,
    input  wire             i_bru_ejump,
    input  wire [31:0]      i_bru_csr_npc,
    // from Register File
    input  wire [31:0]      i_bru_rs1,
    // from WBU
    input  wire             i_bru_npc_wen,
    // to IFU
    output wire [31:0]      o_bru_npc
);
    
    wire [31:0] pc_jorb;
    wire [31:0] npc_t1, npc_t2;
    wire [31:0]  temp = {{(`CPU_Width - 1){1'b1}}, 1'b0};  //for example, CPU_Width = 32，then temp = 0xfffe
    
    MuxKey #(2, 1, `CPU_Width) mux1(pc_jorb, i_bru_is_jalr, {
        `FALSE, i_bru_pc + i_bru_imm,               // jal or branch instruction
        `TRUE,  (i_bru_rs1 + i_bru_imm) & temp}     // jalr
    );

    MuxKey #(2, 1, `CPU_Width) mux2(npc_t1, (i_bru_is_jalr | i_bru_is_jal | i_bru_brch), {
        `FALSE, i_bru_pc + `CPU_Width'h4,           // pc + 4        
        `TRUE,  pc_jorb}                            // jalr or jal or branch instruction
    );

    MuxKey #(2, 1, `CPU_Width) mux3(npc_t2, (i_bru_ejump), {
        `FALSE, npc_t1,             // pc + 4        
        `TRUE,  i_bru_csr_npc}      // mret or ecall
    );

    reg [31:0] npc_reg;
    always @(posedge clk) begin
        if(rst == 1'b1) 
            npc_reg <= `RESET_VECTOR;
        else if(i_bru_npc_wen == 1'b1)
            npc_reg <= npc_t2;
    end
    assign o_bru_npc = npc_reg;

endmodule
