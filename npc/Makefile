MODULE=ysyx_23060219_top
CSRCS = $(shell find $(abspath ./csrc) -name "*.cpp")
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")		#只会查找 ./vsrc 目录中的.v文件
VSRCS += $(shell find $(abspath ./vsrc/*) -name "*.v")	#递归地查找 ./vsrc 目录下所有子目录中的.v文件
INC_PATH = $(NPC_HOME)/include/			#指定包含文件路径，用-I选项传递给verilator
LIBS = -lreadline   # 链接的库文件 link the <readline> lib
LIBS += -ldl        # 链接的库文件 link the <dlfcn> lib
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
 

# ifdef CONFIG_DIFFTEST
# DIFF_REF_PATH = ./difftest
# DIFF_REF_SO = $(DIFF_REF_PATH)/riscv32-nemu-interpreter-so		## 这里应该要加 /build
# ARGS_DIFF = --diff=$(DIFF_REF_SO)

# .PHONY: $(DIFF_REF_SO)
# $(DIFF_REF_SO):
# 	$(MAKE) -s -C $(DIFF_REF_PATH) 

# endif



.PHONY:gtkw
gtkw: wave.gtkw			#zhong.gtkw
	@echo
	@echo "### WAVES ###"
	gtkwave wave.gtkw


.PHONY:sim
sim: waveform.fst


.PHONY:waves
waves: waveform.fst
	@echo
	@echo "### WAVES ###"
	gtkwave waveform.fst


.PHONY:waveform.fst
waveform.fst: ./obj_dir/V$(MODULE)
	@echo
	@echo "### SIMULATING ###"
	@./obj_dir/V$(MODULE) #+verilator+rand+reset+2



IMG ?=      #loaded by AM Makefile (npc.mk)
override ARGS ?= --log=./log/npc-log.txt
override ARGS += $(ARGS_DIFF)					###
BINARY := ./obj_dir/V$(MODULE)
NEMU_EXEC := $(BINARY) $(ARGS) $(IMG)


.PHONY:run-env
run-env: $(BINARY) $(DIFF_REF_SO)				###


.PHONY:run
run: run-env
	$(NEMU_EXEC)


.PHONY:gdb										###
gdb: run-env
	gdb -s $(BINARY) --args $(NEMU_EXEC)


.PHONY:build
build: $(BINARY)

#This builds our simulation executable from the testbench and the converted sources.
#We tell Make to change the working directory to obj_dir, 
#use the build file named Valu.mk and build the target named Valu
#----------------------------------------------------------------------------------


./obj_dir/V$(MODULE): .zhong.verilate
	@echo
	@echo "### BUILDING SIM ###"
	make -C obj_dir -f V$(MODULE).mk V$(MODULE)


.PHONY:verilate
verilate: .zhong.verilate


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
.zhong.verilate: $(VSRCS) $(CSRCS)
	@echo
	@echo "### VERILATING ###"
	verilator -Wno-STMTDLY -Wno-MODDUP --trace-fst --top-module $(MODULE) -cc $(VSRCS) --exe $(CSRCS) -I$(INC_PATH)
	@echo "LIBS +=$(LIBS)" >> ./obj_dir/V$(MODULE).mk    # to link readline and dlfcn library
# @echo "CXXFLAGS +=$(CXXFLAGS)" >> ./obj_dir/V$(MODULE).mk 
	@touch .zhong.verilate


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
	rm -rf .zhong.*;
	rm -rf ./obj_dir
	rm -rf waveform.fst
	rm ./log/*
