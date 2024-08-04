// module datapath(
//     input               clk         ,
//     input               reset       ,
//     input   [1:0]       ResultSrc   ,
//     input               PCSrc       ,
//     input               ALUSrc      ,
//     input   [2:0]       ALUControl  ,
//     input   [2:0]       ImmSrc      ,
//     input               RegWrite    ,
//     input   [31:0]      Instr       ,
//     input   [31:0]      ReadData    ,
//     output  [31:0]      PC          ,
//     output  [31:0]      ALUResult   ,
//     output  [31:0]      WriteData   ,   //从rs2中读出的值
//     output              Zero
//     );
 
//     wire [6:0] tmp;
//     assign tmp = Instr[6:0];        //Instr[6:0]未被使用 产生warning
//     assign tmp = tmp;


//     wire   [31:0] PCNext, PCPlus4, PCTarget;
//     wire   [31:0] ImmExt;
//     wire   [31:0] SrcA, SrcB;
//     wire   [31:0] Result;
 
 
//     PC  PC_u(
//     .clk               (clk)    ,
//     .rst_n             (reset)  ,
//     .PCNext            (PCNext) ,
//     .PC                (PC)
//     );
//     adder pc_add4(
//     .a              (PC)        ,
//     .b              (32'd4)     ,
//     .y              (PCPlus4)
//     );
//     adder pc_add_immext(
//     .a              (PC)        ,
//     .b              (ImmExt)    ,
//     .y              (PCTarget)
//     );
//     mux2 #(32)  pc_mux(                 //最左的选择器 输出PCNext
//     .d0             (PCPlus4)   ,
//     .d1             (PCTarget)  ,
//     .s              (PCSrc)     ,       //下一个PC值的选择信号
//     .y              (PCNext)            //下一个PC的具体值
//     );
// //  register file logic
//     regfile register_files(
//     .clk            (clk)           ,
//     .rst_n          (reset)         ,
//     .A1             (Instr[19:15])  ,   //rs1 序号
//     .A2             (Instr[24:20])  ,   //rs2 序号
//     .A3             (Instr[11:7])   ,   //rd  目标寄存器序号
//     .WD3            (Result)        ,   ////rd 目标寄存器 写入的值
//     .WE3            (RegWrite)      ,   //寄存器的写使能信号
//     .RD1            (SrcA)          ,   //从rs1中读出的值
//     .RD2            (WriteData)         //从rs2中读出的值
//     );
//     extend  imm_ext(
//     .instr          (Instr[31:7])   , 
//     .immsrc         (ImmSrc)        ,
//     .immext         (ImmExt)        
//     );
//     //ALU logic
//      mux2 #(32)   select_alu_target(
//      .d0            (WriteData)     ,   //从rs2中读出的值
//      .d1            (ImmExt)        , 
//      .s             (ALUSrc)        ,   //选择alu计算的另一个值  是rs2寄存器还是immext
//      .y             (SrcB)              //最终选到的值
//      );
//      alu    alu_u(
//      .ALUControl    (ALUControl)    ,
//      .SrcA          (SrcA)          ,      
//      .SrcB          (SrcB)          ,      
//      .Zero          (Zero)          ,      
//      .ALUResult     (ALUResult)
//      );
//      mux3 #(32) resultmux(              //最右边的选择器 选择最后写入寄存器的值
//      .d0            (ALUResult)     ,   //ResultSrc = 00         
//      .d1            (ReadData)      ,   //ResultSrc = 01 
//      .d2            (PCPlus4)       ,   //ResultSrc = 10
//      .d3            (PCTarget)      ,   //ResultSrc = 11    PC + immext
//      .s             (ResultSrc)     ,
//      .y             (Result)        
//      );
    
// endmodule
