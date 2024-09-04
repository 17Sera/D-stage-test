`include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"

module control( //控制 + 译码
    input  wire [`RegBus]   inst,
    output wire [4:0]       rd_11_7,
    output wire [4:0]       rs1_19_15,
    output wire [4:0]       rs2_24_20,
    output wire [2:0]       fun3_14_12,
    output wire [6:0]       fun7_31_25,
    output reg  [`TYPE_BUS] IType,      //inst type
    output reg  [`AlucBus]  aluc,       //alu operation typp
    output reg              is_ecall,
    output reg              csr_wen,
    output reg              reg_wen,    //RegFile write enable
    output reg              mem_wen,    //mem write enable
    output reg              mem_ren,    //mem read  enable
    output reg  [7:0]       wmask,      //mem write mask
    output reg  [2:0]       rmask,      //mem read  mask
    output reg              m1,         //mux1 sel
    output reg  [1:0]       m2,         //mux2 sel
    output reg              m3,         //mux3 sel
    output reg              m4,         //mux4 sel
    output reg  [1:0]       m5          //mux5 sel
);

    import "DPI-C" function void ebreak(input int station, input int inst, input byte unit);
    import "DPI-C" function void etrace(input int inst); //用于触发异常中断，以及追踪自陷操作

    //以R型指令为标准去分割
    wire [6:0] opcode_6_0 = inst[6:0];
    assign rd_11_7        = inst[11:7];
    assign rs1_19_15      = inst[19:15];
    assign rs2_24_20      = inst[24:20];
    assign fun3_14_12     = inst[14:12]; 
    assign fun7_31_25     = inst[31:25]; 

    always @(*) begin
        case(opcode_6_0)
            `INST_TYPE_R: begin //R型指令操作
                IType   = `INST_R;
                is_ecall = `FALSE;   
                csr_wen  = `WDisen;    
                reg_wen = `WEnable;   
                mem_wen = `WDisen;  //关闭数据存储器的写使能 
                mem_ren = `WDisen;  //关闭数据存储器的读使能
                wmask   = `WWord;          // don't care   //R型指令不用管   
                rmask   = `LoadW;          // don't care   //R型指令不用管
                m1      = `MUX1_NBpc;   //0
                m2      = `MUX2_PCadd4; //0
                m3      = `MUX3_src2;   //0
                m4      = `MUX4_src1;   //1
                m5      = `MUX5_result; //2
                if(fun7_31_25 == 7'b000_0000) begin
                    case (fun3_14_12)
                        `INST_ADD:  aluc = `ADD; //加法运算
                        `INST_SLL:  aluc = `SLL; //逻辑左移运算
                        `INST_SLT:  aluc = `LT; //小于置一
                        `INST_SLTU: aluc = `LTU; //无符号小于运算
                        `INST_XOR:  aluc = `XOR; //异或运算
                        `INST_SRL:  aluc = `SRL; //逻辑右移运算
                        `INST_OR:   aluc = `OR;  //或运算
                        `INST_AND:  aluc = `AND; //与运算
                        default:    ebreak(`ABORT, inst, `Unit_CU1); //zhong
                    endcase                
                end else if(fun7_31_25 == 7'b010_0000) begin
                    case (fun3_14_12)
                        `INST_SUB: aluc = `SUB; //减法运算
                        `INST_SRA: aluc = `SRA; //算术右移运算
                        default:   ebreak(`ABORT, inst, `Unit_CU2); //zhong
                    endcase  
                end else begin
                    ebreak(`ABORT, inst, `Unit_CU3);  //zhong
                end
            end
            `INST_TYPE_I: begin
                IType   = `INST_I;
                is_ecall = `FALSE;   
                csr_wen  = `WDisen;    
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
                    `INST_SLTI:  aluc = `LT;
                    `INST_SLTIU: aluc = `LTU;
                    `INST_XORI:  aluc = `XOR;
                    `INST_ORI:   aluc = `OR;
                    `INST_ANDI:  aluc = `AND;
                    // `INST_SLLI:  aluc = `SLL;
                    `INST_SLLI:  aluc = `SLLI;
                    `INST_SRLAI:begin 
                                    case (fun7_31_25)
                                        7'b000_0000: aluc = `SRL;
                                        7'b010_0000: aluc = `SRA;
                                        default: ebreak(`ABORT, inst, `Unit_CU4);  //zhong
                                    endcase
                                end 
                     default:     ebreak(`ABORT, inst, `Unit_CU5);  //zhong
                endcase
            end          
            `INST_TYPE_L: begin
                IType   = `INST_I; 
                aluc    = `ADD;
                is_ecall = `FALSE;   
                csr_wen  = `WDisen;   
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
                    default:  ebreak(`ABORT, inst, `Unit_CU6);  //zhong
                endcase
            end
            `INST_TYPE_S: begin
                IType   = `INST_S;   
                aluc    = `ADD;
                is_ecall = `FALSE;   
                csr_wen  = `WDisen; 
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
                    default:  ebreak(`ABORT, inst, `Unit_CU7);  //zhong
                endcase
            end
            `INST_TYPE_B: begin
                IType   = `INST_B;
                is_ecall = `FALSE;   
                csr_wen  = `WDisen;    
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
                    default:   ebreak(`ABORT, inst, `Unit_CU8);  //zhong
                endcase
            end
            `INST_TYPE_LUI: begin
                IType   = `INST_U;   
                aluc    = `ADD_LUI;
                is_ecall = `FALSE;   
                csr_wen  = `WDisen; 
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
                is_ecall = `FALSE;   
                csr_wen  = `WDisen; 
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
                is_ecall = `FALSE;   
                csr_wen  = `WDisen; 
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
                is_ecall = `FALSE;   
                csr_wen  = `WDisen;
                reg_wen = `WEnable;   
                mem_wen = `WDisen;   
                mem_ren = `WDisen;   
                wmask   = `WWord;          // don't care      
                rmask   = `LoadW;          // don't care      
                m1      = `MUX1_NBpc; //0
                m2      = `MUX2_result; //2
                m3      = `MUX3_imm32; //1
                m4      = `MUX4_pc; //0
                m5      = `MUX5_PCadd4; //0
            end
            `INST_TYPE_E: begin
                IType   = `INST_I;
                aluc    = `ADD;    //don't care
                mem_wen = `WDisen; //don't care
                mem_ren = `WDisen; //don't care
                wmask   = `WWord;  //don't care
                rmask   = `LoadW;  //don't care
                m1      = `MUX1_NBpc;
                m3      = `MUX3_imm32; //don't care
                m4      = `MUX4_pc;    //don't care
                m5      = `MUX5_CsrVal; //选择将状态控制寄存器的值读入寄存器堆
                case (fun3_14_12)
                    `INST_CSRRW, `INST_CSRRS: begin
                        is_ecall = `FALSE;
                        csr_wen  = `WEnable;
                        reg_wen  = `WEnable;
                        m2       = `MUX2_PCadd4;
                    end
                    default: begin
                        case({fun7_31_25, rs2_24_20})
                            `INST_MRET: begin  //mret指令不需要往寄存器读写数据，只需要更新pc即可
                                is_ecall = `FALSE;
                                csr_wen  = `WDisen;
                                reg_wen  = `WDisen;
                                m2       = `MUX2_CsrNpc;
                            end
                            `INST_ECALL: begin
                                is_ecall = `TRUE;
                                csr_wen  = `WEnable;
                                reg_wen  = `WEnable;
                                m2       = `MUX2_CsrNpc;
                                etrace(32'hdeadeeee);
                            end
                            `INST_EBREAK: ebreak(`HIT_TRAP, inst, `Unit_CU9);
                            default: ebreak(`ABORT, inst, `Unit_CU10);
                        endcase
                    end
                endcase
            end
            default: ebreak(`ABORT, inst, `Unit_CU11);
        endcase
    end
endmodule
