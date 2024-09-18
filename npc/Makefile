# MODULE=ysyx_23060219_top
# CSRCS = $(shell find $(abspath ./csrc) -name "*.cpp")
# VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")		#只会查找 ./vsrc 目录中的.v文件
# VSRCS += $(shell find $(abspath ./vsrc/*) -name "*.v")	#递归地查找 ./vsrc 目录下所有子目录中的.v文件
# INC_PATH = $(NPC_HOME)/include/			#指定包含文件路径，用-I选项传递给verilator
# LIBS = -lreadline   # 链接的库文件 link the <readline> lib
# LIBS += -ldl        # 链接的库文件 link the <dlfcn> lib
# LIBS += $(shell llvm-config-11 --libs)		#确保程序能够链接到 LLVM 的核心库和支持库
# CXXFLAGS += $(shell llvm-config-11 --cxxflags) -fPIE


# # ifdef CONFIG_DIFFTEST			#差分测试的路径			###有这个会报错 ref_so_file为空 difftest.cpp报错
# DIFF_REF_PATH = $(NEMU_HOME)
# DIFF_REF_SO = $(DIFF_REF_PATH)/build/riscv32-nemu-interpreter-so	#动态链接库
# ARGS_DIFF = --diff=$(DIFF_REF_SO)

# # .PHONY: $(DIFF_REF_SO)			## 有这步会报错，不能再编译nemu，只要手动编译nemu生成了动态库就可以了，运行nemu的话会报错（正常的）
# # $(DIFF_REF_SO):
# # 	$(MAKE) -s -C $(DIFF_REF_PATH) 

# # endif
 

# .PHONY:gtkw
# gtkw: wave.gtkw			#zhong.gtkw
# 	@echo
# 	@echo "### WAVES ###"
# 	gtkwave wave.gtkw


# .PHONY:sim
# sim: waveform.fst


# .PHONY:waves
# waves: waveform.fst
# 	@echo
# 	@echo "### WAVES ###"
# 	gtkwave waveform.fst


# .PHONY:waveform.fst
# waveform.fst: ./obj_dir/V$(MODULE)
# 	@echo
# 	@echo "### SIMULATING ###"
# 	@./obj_dir/V$(MODULE) #+verilator+rand+reset+2



# IMG ?=      #loaded by AM Makefile (npc.mk)
# override ARGS ?= --log=./log/npc-log.txt
# override ARGS += $(ARGS_DIFF)					###
# BINARY := ./obj_dir/V$(MODULE)
# NEMU_EXEC := $(BINARY) $(ARGS) $(IMG)


# .PHONY:run-env
# run-env: $(BINARY) $(DIFF_REF_SO)				###


# .PHONY:run
# run: run-env
# 	$(NEMU_EXEC)


# .PHONY:gdb										###
# gdb: run-env
# 	gdb -s $(BINARY) --args $(NEMU_EXEC)


# .PHONY:build
# build: $(BINARY)

# #----------------------------------------------------------------------------------

# ./obj_dir/V$(MODULE): .zhong.verilate
# 	@echo
# 	@echo "### BUILDING SIM ###"
# 	make -C obj_dir -f V$(MODULE).mk V$(MODULE)


# .PHONY:verilate
# verilate: .zhong.verilate


# # # --------------------------------------------------------------------------------
# # # 将 .v 源文件转换为 C++ 代码，并生成用于构建模拟执行文件的构建文件
# # # 使用 -Wall 选项启用所有 C++ 编译错误
# # # 使用 --trace 选项启用波形跟踪功能
# # # 使用 -cc .v 将 .v 模块转换为 C++ 代码
# # # 使用 --exe tb_alu.cpp 告诉 Verilator tb_alu.cpp 是我们的 C++ 测试平台
# # # -Wno-STMTDLY 避免弹出所有warning
# # # -Wno-MODDUP 避免“Duplicate declaration”报错
# # # --top-module $(MODULE) 确定底层模块，否则会将$(VSRCS)中的第一个文件前缀当成顶层模块
# #----------------------------------------------------------------------------------
# .zhong.verilate: $(VSRCS) $(CSRCS)
# 	@echo
# 	@echo "### VERILATING ###"
# 	verilator -Wno-STMTDLY -Wno-MODDUP --trace-fst --top-module $(MODULE) -cc $(VSRCS) --exe $(CSRCS) -I$(INC_PATH)
# 	@echo "LIBS +=$(LIBS)" >> ./obj_dir/V$(MODULE).mk    # to link readline and dlfcn library
# # @echo "CXXFLAGS +=$(CXXFLAGS)" >> ./obj_dir/V$(MODULE).mk 
# 	@touch .zhong.verilate


# # #make lint目标调用 Verilator 并使用 --lint-only 选项，可以快速解析.v文件并检查问题
# # #用于进行lint检查，检查Verilog的语法问题
# #----------------------------------------------------------------------------------
# .PHONY:lint
# lint: $(MODULE).v
# 	#-lint-only- 告诉 Verilator 进行 lint 但不生成任何仿真输出
# 	verilator --lint-only $(MODULE).v


# .PHONY: clean
# clean:
# 	rm -rf .zhong.*;
# 	rm -rf ./obj_dir
# 	rm -rf waveform.fst
# 	rm ./log/*

# ==================================================================================

MODULE=ysyx_23060219_top
CSRCS = $(shell find $(abspath ./csrc) -name "*.cpp")
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
VSRCS += $(shell find $(abspath ./vsrc/*) -name "*.v")
INC_PATH = $(NPC_HOME)/include/
LIBS = -lreadline   # link the <readline> lib
LIBS += -ldl        # link the <dlfcn> lib
LIBS += $(shell llvm-config-11 --libs)
CXXFLAGS += $(shell llvm-config-11 --cxxflags) -fPIE


# ifdef CONFIG_DIFFTEST			#差分测试的路径			###有这个会报错 ref_so_file为空 difftest.cpp报错
DIFF_REF_PATH = $(NEMU_HOME)
DIFF_REF_SO = $(DIFF_REF_PATH)/build/riscv32-nemu-interpreter-so	#动态链接库
ARGS_DIFF = --diff=$(DIFF_REF_SO)

# .PHONY: $(DIFF_REF_SO)			## 有这步会报错，不能再编译nemu，只要手动编译nemu生成了动态库就可以了，运行nemu的话会报错（正常的）
# $(DIFF_REF_SO):
# 	$(MAKE) -s -C $(DIFF_REF_PATH) 

# endif


.PHONY:gtkw
gtkw: wave.gtkw
	@echo
	@echo "### WAVES ###"
	gtkwave wave.gtkw


.PHONY:sim
sim: waveform.vcd


.PHONY:waves
waves: waveform.vcd
	@echo
	@echo "### WAVES ###"
	gtkwave waveform.vcd


.PHONY:waveform.vcd
waveform.vcd: ./obj_dir/V$(MODULE)
	@echo
	@echo "### SIMULATING ###"
	@./obj_dir/V$(MODULE) #+verilator+rand+reset+2



IMG ?=      #loaded by AM Makefile (npc.mk)
override ARGS ?= --log=./log/npc-log.txt
ifdef CONFIG_DIFFTEST						###
override ARGS += $(ARGS_DIFF)
# ARGS += $(ARGS_DIFF)
endif
BINARY := ./obj_dir/V$(MODULE)
NEMU_EXEC := $(BINARY) $(ARGS) $(IMG)


.PHONY:run-env
ifdef CONFIG_DIFFTEST						###
run-env: $(BINARY) $(DIFF_REF_SO)
else
run-env: $(BINARY) #$(DIFF_REF_SO)
endif

.PHONY:run
run: run-env
	$(NEMU_EXEC)

.PHONY:gdb
gdb: run-env
	gdb -s $(BINARY) --args $(NEMU_EXEC)


.PHONY:build
build: $(BINARY)

#This builds our simulation executable from the testbench and the converted sources.
#We tell Make to change the working directory to obj_dir, 
#use the build file named Valu.mk and build the target named Valu
#----------------------------------------------------------------------------------
./obj_dir/V$(MODULE): .stamp.verilate
	@echo
	@echo "### BUILDING SIM ###"
	make -C obj_dir -f V$(MODULE).mk V$(MODULE)


.PHONY:verilate
verilate: .stamp.verilate


#This converts our .v source to C++ and generates build files 
#for building the simulation executable. 
#We use -Wall to enable all C++ errors, 
#--trace to enable waveform tracing, 
#-cc .v to convert our .v module to C++, 
#and --exe tb_alu.cpp to tell Verilator which file is our C++ testbench.
# -Wno-STMTDLY 避免弹出所有warning
# -Wno-MODDUP 避免“Duplicate declaration”报错
# --top-module $(MODULE) 确定底层模块，否则会将$(VSRCS)中的第一个文件前缀当成顶层模块
#----------------------------------------------------------------------------------
.stamp.verilate: $(VSRCS) $(CSRCS)
	@echo
	@echo "### VERILATING ###"
	verilator -Wno-STMTDLY -Wno-MODDUP --trace --top-module $(MODULE) -cc $(VSRCS) --exe $(CSRCS) -I$(INC_PATH)
	@echo "LIBS +=$(LIBS)" >> ./obj_dir/V$(MODULE).mk    # to link readline and dlfcn library
# @echo "CXXFLAGS +=$(CXXFLAGS)" >> ./obj_dir/V$(MODULE).mk 
	@touch .stamp.verilate


#Note that there is an aditional make lint target, 
#which calls Verilator with --lint-only. 
#This is useful to quickly parse your Verilog/SystemVerilog source files 
#and check for problems. 
#This can be used to check over your sources even if you’re not using Verilator for simulating.
#----------------------------------------------------------------------------------
.PHONY:lint
lint: $(MODULE).v
	#-lint-only- 告诉 Verilator 进行 lint 但不生成任何仿真输出
	verilator --lint-only $(MODULE).v


.PHONY: clean
clean:
	rm -rf .stamp.*;
	rm -rf ./obj_dir
	rm -rf waveform.vcd
	rm ./log/*

