// `include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"

// module ysyx_23060219_csr_regs(
//     input clk,
//     input rst,
//     input csr_wen,
//     input is_ecall,
//     input [11:0] csr,
//     input [2:0] funct3,
//     input [31:0] src1,
//     input [31:0] pc,
//     output reg [31:0] csr_val,
//     output wire [31:0] csr_npc
// );

//     import "DPI-C" function void ebreak(input int station, input int inst, input byte uint);

//     reg [31:0] mepc;
//     reg [31:0] mcause;
//     reg [31:0] mtvec;
//     reg [31:0] mstatus;
//     reg [31:0] csr_write;

//     assign csr_write = (funct3[1] == 1'b0) ? src1 : (src1 | csr_val); //判定是csrrw还是csrrs指令

//     assign csr_npc = (csr[1] == 1'b0) ? mtvec : mepc; //判断是否进入异常中断入口，执行ecall指令时进入mtvec异常中断入口（地址）

//     //assign mtvec = 32'h305;

//     //csr write
//     always@(posedge clk) begin
//         if(rst == `RST_VAL) begin
//             mepc    <= `RegRstVal;
//             mtvec   <= `RegRstVal;
//             mcause  <= `RegRstVal;
//             mstatus <= `RegRstVal;
//         end
//         else if(is_ecall) begin
//             mepc <= pc;
//             mcause <= csr_write;
//         end
//         else if(csr_wen) begin
//             case (csr)
//                 12'h341: mepc    <= csr_write;
//                 12'h342: mcause  <= csr_write;
//                 12'h300: mstatus <= csr_write;
//                 12'h305: mtvec   <= csr_write;
//                 default: begin
//                     ebreak(`ABORT, 32'hdead000a, `Unit_CR);
//                 end
//             endcase
//         end
//     end

//     //csr read
//     always@(*) begin
//         case (csr)
//             12'h341: csr_val = mepc;
//             12'h342: csr_val = mcause;
//             12'h300: csr_val = mstatus;
//             12'h305: csr_val = mtvec;
//             default:   csr_val = 32'hdead000b;
//         endcase
//     end

// endmodule