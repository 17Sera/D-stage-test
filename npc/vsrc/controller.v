module controller(        //ysyx_23060219_idu
  input       [6:0]       op          ,   //Instr[6:0]
  input       [2:0]       funct3      ,   //Instr[14:12]
  input                   funct7b5    ,   //Instr[30]
  input                   Zero        ,
  output      [1:0]       ResultSrc   ,
  output                  MemWrite    ,
  output                  PCSrc       , 
  output                  ALUSrc      ,
  output                  RegWrite    , 
  //output                  Jump        ,   //////////////
  output      [1:0]       ImmSrc      ,
  output      [2:0]       ALUControl
  );

  // wire define
    wire [1:0]     ALUOp;
    wire           Branch,Jump;     ///////////
    wire           PC_select;

maindec maindec_u(
  .op                  (op)           ,     
  .ResultSrc           (ResultSrc)    ,
  .MemWrite            (MemWrite)     ,
  .Branch              (Branch)       ,
  .ALUSrc              (ALUSrc)       ,
  .RegWrite            (RegWrite)     ,
  .Jump                (Jump)         ,
  .ImmSrc              (ImmSrc)       ,
  .ALUOp               (ALUOp)        
    );

aludec  aludec_u(
  .opb5                (op[5])         ,     
  .funct3              (funct3)       ,
  .funct7b5            (funct7b5)     ,
  .ALUOp               (ALUOp)        ,
  .ALUControl          (ALUControl)   
    );
     

  assign PC_select = Branch & Zero | Jump;      //是否跳转

  assign PCSrc = PC_select;
                      
                      
endmodule                      
