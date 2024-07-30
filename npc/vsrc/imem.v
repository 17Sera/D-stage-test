// module imem(
//     input       [31:0]      A,      //address    PC
//     output      [31:0]      RD
//     );

//     reg  [31:0]  ROM [0:255];

//     // initial begin
//     //    $readmemh("/home/zhong/ysyx-workbench/npc/riscvtest.txt",ROM); 
//     // end


//     assign ROM[A[9:2]] = 32'b000000000001_11000_000_11001_0010011; //ADDI $25 $24 32'h00000001
//     assign RD = ROM[A[9:2] ];            //assign rom_addr=pc_out[9:2];

//     //assign RD = 32'b000000000101_00000_000_00001_0010011;    //addi x1 x0 5


//     wire [7:0]     tmp   = A[9:2] ;        //tmp可以查看instr_mem的address 01 02 03……
//     wire [1:0]     tmp_1 = A[1:0]  ;        //不然会显示A[1:0]没有用上，warning
//     wire [21:0]    tmp_2 = A[31:10];
//     assign tmp_1 = tmp_1;                   //tmp没有被使用会warning\
//     assign tmp_2 = tmp_2;
//     assign tmp   = tmp  ;

// endmodule

