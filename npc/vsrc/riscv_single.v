module riscv_single(
    input               clk,
    input               reset,
    input       [31:0]  Instr, 
    input       [31:0]  ReadData,
    output      [31:0]  PC,
    output      [31:0]  ALUResult,      //DataAdr
    output      [31:0]  WriteData,      //从rs2中读出的值
    output              MemWrite              
    );
    
    wire        ALUSrc, RegWrite, Zero, PCSrc;
    wire [1:0]  ResultSrc, ImmSrc;
    wire [2:0]  ALUControl;
    
controller controller_u(
    .op                     (Instr[6:0])     ,               
    .funct3                 (Instr[14:12])   ,
    .funct7b5               (Instr[30])      ,
    .Zero                   (Zero)           ,
    .ResultSrc              (ResultSrc)      ,
    .MemWrite               (MemWrite)       ,
    .PCSrc                  (PCSrc)          ,
    .ALUSrc                 (ALUSrc)         ,
    .RegWrite               (RegWrite)       ,
    //.Jump                   (Jump)           ,        /////////
    .ImmSrc                 (ImmSrc)         ,
    .ALUControl             (ALUControl)     
    
    );
datapath datapath_u(
    .clk                    (clk)            ,                          
    .reset                  (reset)          ,
    .ResultSrc              (ResultSrc)      ,
    .PCSrc                  (PCSrc)          ,
    .ALUSrc                 (ALUSrc)         ,
    .ALUControl             (ALUControl)     ,
    .ImmSrc                 (ImmSrc)         ,
    .RegWrite               (RegWrite)       ,
    .Instr                  (Instr)          ,
    .ReadData               (ReadData)       ,
    .PC                     (PC)             ,
    .ALUResult              (ALUResult)      ,
    .WriteData              (WriteData)      ,  //从rs2中读出的值
    .Zero                   (Zero)           
    );
    
    
endmodule
