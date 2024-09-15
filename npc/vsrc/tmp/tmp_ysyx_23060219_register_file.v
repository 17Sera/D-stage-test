// `include "/home/zhong/ysyx-workbench/npc/vsrc/defines.v"

// module ysyx_23060219_register_file(
//     input  wire           clk,
//     input  wire           rst,
//     input  wire           is_ecall,
//     input  wire           reg_wen,
//     input  wire [4:0]     rs1, //源寄存器1地址，五位的地址位宽，最多可以表示32个寄存器
//     input  wire [4:0]     rs2, //源寄存器2地址
//     input  wire [4:0]     rd, //目标寄存器地址
//     input  wire [31:0] reg_in, //写入寄存器的数据
//     output wire [31:0] src1, //从源寄存器1中读出的数据
//     output wire [31:0] src2 //从源寄存器2中读出的数据
// );

//     integer i;
//     reg[31:0] regs[`BitWidth-1 : 0]; //32个位数为32的寄存器堆
//     wire [31:0] src1_temp;

//     //wire register
//     always @(posedge clk) begin
//         if(rst == `RST_VAL) begin
//             for(i=0; i<`RegNum; i=i+1) begin
//                 regs[i] <= `RegRstVal;  //寄存器堆的寄存器清零
//             end
//         end
//         else if((reg_wen == 1'b1) && (rd != `Reg0)) //寄存器写是能拉高，同时目标寄存器不能不能为0号寄存器，不能向里面写入数据
//             regs[rd] <= reg_in; 
//         else
//             regs[rd] <= regs[rd]; 
//     end

//     //read register
//     assign src1_temp = (rs1 == `Reg0) ? `Reg0_VAL : regs[rs1];
//     assign src1 = (is_ecall == 1'b1) ? regs[`Mcause_gpr] : src1_temp;
//     //assign src1 = (rs1 == `Reg0) ? `Reg0_VAL : regs[rs1]; //判断需要读取的源寄存器1是否是0号寄存器，如果是就直接将0赋值给源寄存器1的读出值
//     assign src2 = (rs2 == `Reg0) ? `Reg0_VAL : regs[rs2]; //判断需要读取的源寄存器2是否是0号寄存器，如果是就直接将0赋值给源寄存器2的读出值
   
// endmodule
