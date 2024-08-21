`include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"

module ysyx_23060219_control_unit(
    input  wire [31:0]          inst,
    output wire [4:0]           rd_11_7,    //拆分指令inst
    output wire [4:0]           rs1_19_15,
    output wire [4:0]           rs2_24_20,
    output wire [2:0]           fun3_14_12,
    output wire [6:0]           fun7_31_25,
    output reg  [`TYPE_BUS]     IType,      //inst type   2:0
    output reg  [`Aluc_width]   aluc,       //alu control   4:0
    output reg                  is_ecall,
    output reg                  csr_wen,
    output reg                  reg_wen,    //RegFile 写使能
    output reg                  mem_wen,    //mem  写使能
    output reg                  mem_ren,    //mem  读使能
    output reg  [7:0]           wmask,      //mem  写掩码
    output reg  [2:0]           rmask,      //mem  读掩码
    output reg                  m1, 
    output reg  [1:0]           m2,  
    output reg                  m3,  
    output reg                  m4,
    output reg  [1:0]           m5 
);

    import "DPI-C" function void ebreak(input int station, input int inst, input byte unit);
    import "DPI-C" function void etrace(input int inst);

    wire [6:0] opcode_6_0 = inst[6:0];      //拆分指令inst
    assign rd_11_7        = inst[11:7];
    assign rs1_19_15      = inst[19:15];
    assign rs2_24_20      = inst[24:20];
    assign fun3_14_12     = inst[14:12];  
    assign fun7_31_25     = inst[31:25];  

    always @(*) begin
        case(opcode_6_0)    //按opcode分类
            `INST_TYPE_R: begin             // 写入R指令信息    两个寄存器之间的操作
                IType   = `INST_R;          //指令类型为R
                is_ecall = `FALSE;          //////////
                csr_wen  = `WDisen;         //////////
                reg_wen = `WEnable;         // 1'b1
                mem_wen = `WDisen;          // 1'b0
                mem_ren = `WDisen;   
                wmask   = `WWord;          // don't care      
                rmask   = `LoadW;          // don't care      
                m1      = `MUX1_NBpc;      // not bump inst / is bump inst
                m2      = `MUX2_PCadd4;    // MUX2_result / MUX2_PCadd4
                m3      = `MUX3_src2;      // MUX3_src2 / MUX3_imm32
                m4      = `MUX4_src1;      // MUX4_src1 / MUX4_pc
                m5      = `MUX5_result;    // 写进寄存器的是 MUX5_PCadd4、MUX5_memdat、MUX5_result、MUX5_IDLE
                if(fun7_31_25 == 7'b000_0000) begin     //R指令基础上 按fun7分类
                    case (fun3_14_12)                   //再按fun3分类 
                        `INST_ADD:  aluc = `ADD;
                        `INST_SLL:  aluc = `SLL;
                        `INST_SLTU: aluc = `LTU;        //还要进一步分成SLTU和BLTU
                        `INST_XOR:  aluc = `XOR;
                        `INST_SRL:  aluc = `SRL;
                        `INST_OR:   aluc = `OR;
                        `INST_AND:  aluc = `AND;
                        `INST_SLT:  aluc = `LT;
                        default:    ebreak(`ABORT, inst, `Unit_CU1); 
                    endcase                
                end else if(fun7_31_25 == 7'b010_0000) begin
                    case (fun3_14_12)
                        `INST_SUB: aluc = `SUB;
                        `INST_SRA: aluc = `SRA;
                        default:   ebreak(`ABORT, inst, `Unit_CU2); 
                    endcase  
                end else begin
                    ebreak(`ABORT, inst, `Unit_CU3); 
                end
            end
            `INST_TYPE_I: begin
                IType   = `INST_I;
                is_ecall = `FALSE;          //////
                csr_wen  = `WDisen;         /////
                reg_wen = `WEnable;   
                mem_wen = `WDisen;   
                mem_ren = `WDisen;   
                wmask   = `WWord;          // don't care      
                rmask   = `LoadW;          // don't care      
                m1      = `MUX1_NBpc;
                m2      = `MUX2_PCadd4;
                m3      = `MUX3_imm32;
                m4      = `MUX4_src1;
                m5      = `MUX5_result;
                case (fun3_14_12)
                    `INST_ADDI:  aluc = `ADD;
                    `INST_SLTIU: aluc = `LTU;
                    `INST_SLTI:  aluc = `LT;            ////////////
                    `INST_ORI:   aluc = `OR;
                    `INST_XORI:  aluc = `XOR;
                    `INST_ANDI:  aluc = `AND;
                    `INST_SLLI:  aluc = `SLLI;
                    `INST_SRLAI:begin 
                                    case (fun7_31_25)
                                        7'b000_0000: aluc = `SRL;
                                        7'b010_0000: aluc = `SRA;
                                        default: ebreak(`ABORT, inst, `Unit_CU4);
                                    endcase
                                end 
                     default:     ebreak(`ABORT, inst, `Unit_CU5);
                endcase
            end          
            `INST_TYPE_L: begin
                IType   = `INST_I; 
                aluc    = `ADD;
                is_ecall = `FALSE;          ////////
                csr_wen  = `WDisen;         ///////
                reg_wen = `WEnable;   
                mem_wen = `WDisen;   
                mem_ren = `WEnable;   
                wmask   = `WWord;          // don't care      
                m1      = `MUX1_NBpc;
                m2      = `MUX2_PCadd4;
                m3      = `MUX3_imm32;
                m4      = `MUX4_src1;
                m5      = `MUX5_memdat;
                case (fun3_14_12)
                    `INST_LB:  rmask = `LoadB;
                    `INST_LH:  rmask = `LoadH;
                    `INST_LW:  rmask = `LoadW;
                    `INST_LBU: rmask = `LoadBU;
                    `INST_LHU: rmask = `LoadHU;
                    default:  ebreak(`ABORT, inst, `Unit_CU6);
                endcase
            end
            `INST_TYPE_S: begin
                IType   = `INST_S;   
                aluc    = `ADD;
                is_ecall = `FALSE;          ////////
                csr_wen  = `WDisen;         ////////
                reg_wen = `WDisen;   
                mem_wen = `WEnable;   
                mem_ren = `WDisen;   
                rmask   = `LoadW;          // don't care      
                m1      = `MUX1_NBpc;
                m2      = `MUX2_PCadd4;
                m3      = `MUX3_imm32;
                m4      = `MUX4_src1;
                m5      = `MUX5_memdat;
                case (fun3_14_12)
                    `INST_SB: wmask = `WByte;
                    `INST_SH: wmask = `WHalf;
                    `INST_SW: wmask = `WWord;
                    default:  ebreak(`ABORT, inst, `Unit_CU7);
                endcase
            end
            `INST_TYPE_B: begin
                IType   = `INST_B;   
                is_ecall = `FALSE;          ///////////
                csr_wen  = `WDisen;         //////////
                reg_wen = `WDisen;   
                mem_wen = `WDisen;   
                mem_ren = `WDisen;   
                wmask   = `WWord;            // don't care 
                rmask   = `LoadW;            // don't care  
                m1      = `MUX1_Bpc;
                m2      = `MUX2_PCadd4;      // don't care
                m3      = `MUX3_src2;
                m4      = `MUX4_src1;
                m5      = `MUX5_result;      // don't care
                case (fun3_14_12)
                    `INST_BEQ:  aluc = `EQ;
                    `INST_BNE:  aluc = `NE;
                    `INST_BLT:  aluc = `LT;
                    `INST_BGE:  aluc = `GE;
                    `INST_BLTU: aluc = `LTU;
                    `INST_BGEU: aluc = `GEU;
                    default:   ebreak(`ABORT, inst, `Unit_CU8);
                endcase
            end
            `INST_TYPE_LUI: begin
                IType   = `INST_U;   
                aluc    = `ADD_LUI;
                is_ecall = `FALSE;          ////////////
                csr_wen  = `WDisen;         ///////////
                reg_wen = `WEnable;   
                mem_wen = `WDisen;   
                mem_ren = `WDisen;   
                wmask   = `WWord;          // don't care   
                rmask   = `LoadW;          // don't care   
                m1      = `MUX1_NBpc;
                m2      = `MUX2_PCadd4;
                m3      = `MUX3_imm32;
                m4      = `MUX4_src1;      // don't care   
                m5      = `MUX5_result;
            end
            `INST_TYPE_AUIPC: begin
                IType   = `INST_U;   
                aluc    = `ADD;
                is_ecall = `FALSE;          //////////
                csr_wen  = `WDisen;         /////////
                reg_wen = `WEnable;   
                mem_wen = `WDisen;   
                mem_ren = `WDisen;   
                wmask   = `WWord;          // don't care      
                rmask   = `LoadW;          // don't care      
                m1      = `MUX1_NBpc;
                m2      = `MUX2_PCadd4;
                m3      = `MUX3_imm32;
                m4      = `MUX4_pc;
                m5      = `MUX5_result;
            end
            `INST_TYPE_JALR: begin
                IType   = `INST_I;   
                aluc    = `ADD_JALR;
                is_ecall = `FALSE;          //////////
                csr_wen  = `WDisen;         //////////
                reg_wen = `WEnable;   
                mem_wen = `WDisen;   
                mem_ren = `WDisen;   
                wmask   = `WWord;          // don't care      
                rmask   = `LoadW;          // don't care      
                m1      = `MUX1_NBpc;
                m2      = `MUX2_result;
                m3      = `MUX3_imm32;
                m4      = `MUX4_src1;
                m5      = `MUX5_PCadd4;
            end            
            `INST_TYPE_JAL: begin
                IType   = `INST_J;   
                aluc    = `ADD;
                is_ecall = `FALSE;          //////////
                csr_wen  = `WDisen;         //////////
                reg_wen = `WEnable;   
                mem_wen = `WDisen;   
                mem_ren = `WDisen;   
                wmask   = `WWord;          // don't care      
                rmask   = `LoadW;          // don't care      
                m1      = `MUX1_NBpc;
                m2      = `MUX2_result;
                m3      = `MUX3_imm32;
                m4      = `MUX4_pc;
                m5      = `MUX5_PCadd4;
            end
            `INST_TYPE_E: begin
                IType    = `INST_I;         // don't care   
                aluc     = `ADD;            // don't care   
                mem_wen  = `WDisen;   
                mem_ren  = `WDisen;   
                wmask    = `WWord;          // don't care      
                rmask    = `LoadW;          // don't care      
                m1       = `MUX1_NBpc;
                m3       = `MUX3_imm32;     // don't care   
                m4       = `MUX4_pc;        // don't care   
                m5       = `MUX5_CsrVal;    // 将寄存器csr中的值写入寄存器rd 
                case (fun3_14_12)
                    `INST_CSRRW, `INST_CSRRS: begin
                            is_ecall = `FALSE;   
                            csr_wen  = `WEnable;   
                            reg_wen  = `WEnable;   
                            m2       = `MUX2_PCadd4;
                        end
                    default: begin
                        case ({fun7_31_25, rs2_24_20})
                            `INST_MRET:   begin
                                is_ecall = `FALSE;   
                                csr_wen  = `WDisen;   
                                reg_wen  = `WDisen; 
                                m2       = `MUX2_CsrNpc;        // 将PC设置为CSR[mepc]
                            end
                            `INST_ECALL:  begin
                                is_ecall = `TRUE;   
                                csr_wen  = `WEnable;   
                                reg_wen  = `WEnable;                                  
                                m2       = `MUX2_CsrNpc;
                                `ifdef CONFIG_ETRACE
                                    etrace(32'hdeadeeee);
                                `endif 
                            end
                            `INST_EBREAK: ebreak(`HIT_TRAP, inst, `Unit_CU9);
                            default:      ebreak(`ABORT, inst, `Unit_CU10);
                        endcase
                    end
                endcase

            end


            default: ebreak(`ABORT, inst, `Unit_CU11);
        endcase
    end

endmodule
