module imem(
    input       [31:0]      A,
    output      [31:0]      RD
    );

    reg  [31:0]  ROM [0:255];
    wire [23:0] tmp;

    //wire [31:0] A_tmp;

    initial begin
       $readmemh("/home/zhong/ysyx-workbench/npc/riscvtest.txt",ROM); 
    end

    //assign RD = ROM[A[31:2]]; 

    assign ROM[A[7:0]] = 32'b000000000001_11000_000_11001_0010011; //ADDI $25 $24 32'h00000001

    assign RD = ROM[A[7:0]]; 

    //assign RD = 32'b000000000101_00000_000_00001_0010011;    //addi x1 x0 5

    assign tmp =  A[31:8];       //不然会显示A[1:0]没有用上，warning
    assign tmp = tmp;       //tmp没有被使用会warning

endmodule


// module ysyx_23060219_instr_mem(
//   input [7:0] addr,
//   output [31:0] instr
// );

// 	wire [31:0] rom [255:0];
//   assign instr = rom[addr];

//   assign instr = 32'b00000000010100000000000010010011;    //addi x1 x0 5


// endmodule
//----------------------------------------------------------------------------------
