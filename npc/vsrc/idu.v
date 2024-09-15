`include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"
`define IDU_PKG_WDITH  (5+5+12+1+1+1+2+`ALU_Width+2+`CPU_Width+1+1+3+`CPU_Width+1+1+1+5+1)  //IDU数据包的宽度

module idu(
    // system
    input  wire             clk,
    input  wire             rst,
    // shake hands -----------------------
    input  wire             i_pre_valid,   //来自IFU，代表IFU的数据有效
    output wire             o_pre_ready,   //传递给IFU，代表IDU准备好处理新数据了
    output wire             o_post_valid,  //传递给EXU，代表此时数据包寄存器的数据有效
    input  wire             i_post_ready,  //来自EXU，代表EXU准备好处理新数据了
    // from IFU --------------------------
    input  wire [31:0]      i_idu_pc,       // 来自IFU的PC值
    input  wire [31:0]      i_idu_inst,     // 来自IFU的指令
    // to Register File ------------------
    output wire [4:0]       o_idu_rs_id1,  // 源操作数1的寄存器ID
    output wire [4:0]       o_idu_rs_id2,  // 源操作数2的寄存器ID
    // to CSR Ctrl------------------------
    output wire [`CSR_Bus]  o_idu_csr_rid, // CSR读索引
    output wire             o_idu_csr_ren, // CSR读使能
    output wire             o_idu_is_mret, // 是否为mret指令
    output wire             o_idu_is_ecall, // 是否为ecall指令
    // to EXU------------------------------
    output wire [1:0]       o_idu_csr_type, // CSR操作类型
    output wire [`ALU_Bus]  o_idu_alu_type, // ALU操作类型
    output wire [1:0]       o_idu_num_sel,  // 操作数选择
    output wire [31:0]      o_idu_imm,      // 立即数
    // to LSU------------------------------
    output wire             o_idu_is_load,  // 是否为load加载指令
    output wire             o_idu_is_store, // 是否为store存储指令
    output wire [2:0]       o_idu_func3,    //func3字段
    // to BRU------------------------------
    output wire [31:0]      o_idu_pc,       // 跳转地址
    output wire             o_idu_is_jal,    // 是否为jal跳转指令
    output wire             o_idu_is_jalr,   // 是否为jalr跳转指令
    output wire             o_idu_is_brch,   // 是否为分支指令
    // to WBU------------------------------
    output wire [4:0]       o_idu_rd_id,      // 目的寄存器ID
    output wire             o_idu_gpr_wen     // 通用寄存器写使能
);

    import "DPI-C" function void TRAP(input int station, input byte unit);  //异常处理通过TRAP函数与调试接口交互

    //idu_reg_wen  = i_pre_valid & o_pre_ready
    //o_post_valid = i_pre_valid 延迟一周期
    //o_pre_ready  = ~o_post_valid

    /************ data package ************/
    // to Register File
    wire [4:0]      idu_rs_id1;     //源寄存器1和源寄存器2的ID
    wire [4:0]      idu_rs_id2;
    // to CSR Ctrl
    wire [`CSR_Bus] idu_csr_rid;    //CSR读取索引
    reg             idu_csr_ren;    //CSR读使能信号
    reg             idu_is_mret;    //是否为mret指令
    reg             idu_is_ecall;    //是否为ecall指令
    // to EXU
    reg  [1:0]      idu_csr_type;   //CSR操作类型
    reg  [`ALU_Bus] idu_alu_type;   //ALU操作类型
    reg  [1:0]      idu_num_sel;    //操作数选择
    reg  [31:0]     idu_imm;         //立即数
    // to LSU
    wire            idu_is_load;    //是否为load加载指令
    wire            idu_is_store;    //是否为store存储指令
    wire [2:0]      idu_func3;      //func3字段
    // to BRU
    wire [31:0]     idu_pc;         //跳转地址
    wire            idu_is_jal;     //是否为jal跳转指令
    wire            idu_is_jalr;    //是否为jalr跳转指令
    wire            idu_is_brch;    //是否为分支指令
    // to WEU
    wire [4:0]      idu_rd_id;       //目的寄存器ID
    reg             idu_gpr_wen;     //通用寄存器写使能信号

    // decode  指令解码
    wire [6:0] opcode = i_idu_inst[6:0];
    wire [4:0] rd_id  = i_idu_inst[11:7];
    wire [2:0] func3  = i_idu_inst[14:12];
    wire [4:0] rs_id1 = i_idu_inst[19:15];
    wire [4:0] rs_id2 = i_idu_inst[24:20];
    wire [6:0] func7  = i_idu_inst[31:25];

//----------------------------------------------------------------------------------------------------------

    // to CSR Ctrl  CSR控制信号的生成
    assign idu_csr_rid  = {func7, rs_id2};
    always @(*) begin
        idu_csr_type = `CSR_RW;     //设置CSR操作类型为读写
        idu_csr_ren  = `Disen;       //默认关闭CSR读使能
        idu_is_mret  = `FALSE;
        idu_is_ecall = `FALSE;
        case (opcode)               // 根据opcode分类
            `TYPE_SYS: begin        //  处理系统指令
                case (func3)        // 根据func3分类
                    `INST_E_M: begin    // 判断是否为mret、ecall或ebreak指令
                        if(idu_csr_rid == `INST_MRET)
                            idu_is_mret = `TRUE;
                        else if (idu_csr_rid == `INST_ECALL)
                            idu_is_ecall = `TRUE;
                        else if (idu_csr_rid == `INST_EBREAK)
                            TRAP(`HIT_TRAP, `Unit_IDU1);     // ebreak调用异常处理函数
                        else
                            TRAP(`ABORT, `Unit_IDU2);       //否则，触发错误处理
                    end
                    `INST_CSRRW: begin idu_csr_type = `CSR_RW; idu_csr_ren = `Enable; end    // 处理CSR读写指令
                    `INST_CSRRS: begin idu_csr_type = `CSR_RS; idu_csr_ren = `Enable; end    // 处理CSR读指令
                    default: TRAP(`ABORT, `Unit_IDU3);
                endcase
            end
            `TYPE_R,`TYPE_I,`TYPE_I_LOAD,`TYPE_I_JALR,`TYPE_STORE,`TYPE_B,`TYPE_U_LUI,`TYPE_U_AUIPC,`TYPE_JAL:
                    idu_csr_type = `CSR_Nop;    //对于非系统指令，idu_csr_type设置为CSR_Nop（无操作）
            default:TRAP(`ABORT, `Unit_IDU4);
        endcase
    end

//----------------------------------------------------------------------------------------------------------

    // to EXU and WEU
    assign idu_rd_id = rd_id;       //解码出的目的寄存器ID
    always @(*) begin               // 按opcode分类，分配指令的操作数，写使能，立即数
        idu_num_sel = `RS1_RS2;     //操作数选择
        idu_gpr_wen = `Disen;       //默认关闭通用寄存器写使能
        idu_imm     = `CPU_Width'd0;
        case (opcode)   //根据 opcode 进行分类解码                                  // 生成立即数，使用符号扩展
            `TYPE_R:        begin idu_num_sel = `RS1_RS2;  idu_gpr_wen = `Enable;    idu_imm = `CPU_Width'd0;                                                              end
            `TYPE_I:        begin idu_num_sel = `RS1_IMM;  idu_gpr_wen = `Enable;    idu_imm = {{20{func7[6]}}, func7, rs_id2};                                            end
            `TYPE_I_LOAD:   begin idu_num_sel = `RS1_IMM;  idu_gpr_wen = `Enable;    idu_imm = {{20{func7[6]}}, func7, rs_id2};                                            end
            `TYPE_I_JALR:   begin idu_num_sel = `PC_4;     idu_gpr_wen = `Enable;    idu_imm = `CPU_Width'd0;                                                              end
            `TYPE_STORE:    begin idu_num_sel = `RS1_IMM;  idu_gpr_wen = `Disen;     idu_imm = {{20{func7[6]}}, func7, rd_id};                                             end
            `TYPE_B:        begin idu_num_sel = `RS1_RS2;  idu_gpr_wen = `Disen;     idu_imm = {{20{func7[6]}}, rd_id[0], func7[5:0], rd_id[4:1], 1'b0};                   end
            `TYPE_U_LUI:    begin idu_num_sel = `RS1_IMM;  idu_gpr_wen = `Enable;    idu_imm = {func7, rs_id2, rs_id1, func3, 12'd0};                                      end
            `TYPE_U_AUIPC:  begin idu_num_sel = `PC_IMM;   idu_gpr_wen = `Enable;    idu_imm = {func7, rs_id2, rs_id1, func3, 12'd0};                                      end
            `TYPE_JAL:      begin idu_num_sel = `PC_4;     idu_gpr_wen = `Enable;    idu_imm = {{12{func7[6]}}, rs_id1, func3, rs_id2[0], func7[5:0], rs_id2[4:1], 1'b0};  end                                 
            // idu_gpr_wen: when is INST_CSRRW or INST_CSRRS, idu_gpr_wen equalls to idu_csr_ren logically
            `TYPE_SYS:      begin idu_num_sel = `RS1_RS2;  idu_gpr_wen =  idu_csr_ren; idu_imm = `CPU_Width'd0;                                                              end
            default:        TRAP(`ABORT, `Unit_IDU5);
        endcase
    end

//----------------------------------------------------------------------------------------------------------

    // 生成ALU控制信号
    always @(*) begin
        idu_alu_type = 0;   // 默认ALU操作类型为无操作
        case (opcode)       // 根据opcode分类，分配指令的ALU操作类型
            `TYPE_I_LOAD,`TYPE_I_JALR,`TYPE_STORE,`TYPE_U_LUI,`TYPE_U_AUIPC,`TYPE_JAL:   
                                    idu_alu_type = `ALU_ADD;    
            `TYPE_R: begin
                case (func3)    // 根据func3分类
                    `INST_ADD_SUB:  idu_alu_type = (func7[5] == 1'b0) ? `ALU_ADD : `ALU_SUB;
                    `INST_SLL:      idu_alu_type = `ALU_SLL;
                    `INST_SLT:      idu_alu_type = `ALU_LT;
                    `INST_SLTU:     idu_alu_type = `ALU_LTU;
                    `INST_XOR:      idu_alu_type = `ALU_XOR;
                    `INST_SRL_SRA:  idu_alu_type = (func7[5] == 1'b1) ? `ALU_SRA : `ALU_SRL;
                    `INST_OR:       idu_alu_type = `ALU_OR;
                    `INST_AND:      idu_alu_type = `ALU_AND;
                    default:        TRAP(`ABORT, `Unit_IDU6);
                endcase
            end
            `TYPE_I: begin
                case (func3)
                    `INST_ADDI:     idu_alu_type = `ALU_ADD;
                    `INST_SLLI:     idu_alu_type = `ALU_SLL;
                    `INST_SLTI:     idu_alu_type = `ALU_LT;
                    `INST_SLTIU:    idu_alu_type = `ALU_LTU;
                    `INST_XORI:     idu_alu_type = `ALU_XOR;
                    `INST_SRLAI:    idu_alu_type = (func7[5] == 1'b1) ? `ALU_SRA : `ALU_SRL;
                    `INST_ORI:      idu_alu_type = `ALU_OR;
                    `INST_ANDI:     idu_alu_type = `ALU_AND;
                    default:        TRAP(`ABORT, `Unit_IDU7);
                endcase
            end     
            `TYPE_B: begin
                case (func3)
                    `INST_BEQ:  idu_alu_type = `ALU_EQ;
                    `INST_BNE:  idu_alu_type = `ALU_NE;
                    `INST_BLT:  idu_alu_type = `ALU_LT;
                    `INST_BGE:  idu_alu_type = `ALU_GE;
                    `INST_BLTU: idu_alu_type = `ALU_LTU;
                    `INST_BGEU: idu_alu_type = `ALU_GEU;
                    default:    TRAP(`ABORT, `Unit_IDU8);
                endcase
            end                             
            default: if(opcode != `TYPE_SYS)  TRAP(`ABORT, `Unit_IDU9); 
        endcase
    end

//----------------------------------------------------------------------------------------------------------

    // to Register File 根据指令 给寄存器堆的序号
    assign idu_rs_id1 = (idu_is_ecall == `TRUE) ? `MCASUSE_GPR :  // ecall: src1 = value of a17
                        (opcode == `TYPE_U_LUI) ? 5'd0 : rs_id1;  // lui : rd = x0 + imm
    assign idu_rs_id2 = rs_id2;
    // to LSU指令调度单元
    assign idu_is_load  = (opcode == `TYPE_I_LOAD) ? `TRUE : `FALSE;
    assign idu_is_store = (opcode == `TYPE_STORE)  ? `TRUE : `FALSE;
    // to BRU分支决议单元
    assign idu_pc      = i_idu_pc;
    assign idu_func3   = func3;
    assign idu_is_jal  = (opcode == `TYPE_JAL)    ? `TRUE : `FALSE;
    assign idu_is_jalr = (opcode == `TYPE_I_JALR) ? `TRUE : `FALSE;
    assign idu_is_brch = (opcode == `TYPE_B)      ? `TRUE : `FALSE;

//----------------------------------------------------------------------------------------------------------

    // 数据包寄存器---用于保存解码后的结果
    wire idu_reg_wen  = i_pre_valid & o_pre_ready;   //数据包寄存器的写使能
    reg  [`IDU_PKG_WDITH-1 : 0] idu_valid_data_reg;  

    // 通过时钟和 idu_reg_wen 控制数据包的更新
    always @(posedge clk) begin
        if(rst == 1'b1) 
            idu_valid_data_reg <= 0;
        else if(idu_reg_wen == 1'b1)    //idu_valid_data_reg存储多个字段的组合数据
            idu_valid_data_reg <= { idu_rs_id1, idu_rs_id2, idu_csr_rid, idu_csr_ren, idu_is_mret, 
                                    idu_is_ecall, idu_csr_type, idu_alu_type, idu_num_sel, idu_imm, 
                                    idu_is_load, idu_is_store, idu_func3, idu_pc, idu_is_jal, 
                                    idu_is_jalr, idu_is_brch, idu_rd_id, idu_gpr_wen };
    end
    // 分解为多个输出信号
    assign {o_idu_rs_id1, o_idu_rs_id2, o_idu_csr_rid, o_idu_csr_ren, o_idu_is_mret, 
            o_idu_is_ecall, o_idu_csr_type, o_idu_alu_type, o_idu_num_sel, o_idu_imm, 
            o_idu_is_load, o_idu_is_store, o_idu_func3, o_idu_pc, o_idu_is_jal, 
            o_idu_is_jalr, o_idu_is_brch, o_idu_rd_id, o_idu_gpr_wen } = idu_valid_data_reg;

//----------------------------------------------------------------------------------------------------------

    // 握手信号
    reg post_valid_reg;
    always @(posedge clk) begin
        if(rst == 1'b1) 
            post_valid_reg <= 1'h0;
        else
            post_valid_reg <= i_pre_valid;  //i_pre_valid 表示数据有效时，post_valid_reg 会记录该状态并在下一个时钟周期将其传递给 o_post_valid
    end
    assign o_post_valid = post_valid_reg;
    assign o_pre_ready  = ~o_post_valid;    //表示当前 IDU 是否准备好接收新的数据

//如果 o_post_valid 为低（表示当前数据无效或已处理），则 o_pre_ready 为高，表示可以接收新数据。

// i_pre_valid --> ⌈‾‾‾‾‾⌉ --> o_post_valid
//                 | IDU |
// o_pre_ready <-- ⌊_____⌋ <-- i_post_ready


endmodule

