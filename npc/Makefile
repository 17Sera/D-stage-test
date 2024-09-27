# MODULE=ysyx_23060219								#####
MODULE = ysyxSoCFull
CSRCS = $(shell find $(abspath ./csrc) -name "*.cpp")
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")		#只会查找 ./vsrc 目录中的.v文件
### VSRCS += $(shell find $(abspath ./vsrc/*) -name "*.v")	#递归地查找 ./vsrc 目录下所有子目录中的.v文件
VSRCS += $(shell find $(abspath ../ysyxSoC/build) -name "*.v")		#只会查找 ./vsrc 目录中的.v文件
VSRCS += $(shell find $(abspath ../ysyxSoC/perip/*) -name "*.v")	#递归地查找 ./ysyxSoC/perip 目录下所有子目录中的.v文件		#####

YSYXSOC_PATH = $(NPC_HOME)/../ysyxSoC
YSYXSOC_PERIP_PATH = $(YSYXSOC_PATH)/perip
YSYXSOC_UART_PATH = $(YSYXSOC_PERIP_PATH)/uart16550/rtl/
YSYXSOC_SPI_PATH = $(YSYXSOC_PERIP_PATH)/spi/rtl/

INC_PATH = $(NPC_HOME)/include/			#指定包含文件路径，用-I选项传递给verilator
LIBS = -lreadline   # 链接的库文件 link the <readline> lib
LIBS += -ldl        # 链接的库文件 link the <dlfcn> lib
LIBS += $(shell llvm-config-11 --libs)		#确保程序能够链接到 LLVM 的核心库和支持库
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
ifdef CONFIG_DIFFTEST							###
override ARGS += $(ARGS_DIFF)					###
endif
BINARY := ./obj_dir/V$(MODULE)
NEMU_EXEC := $(BINARY) $(ARGS) $(IMG)


# .PHONY:run-env
# run-env: $(BINARY) $(DIFF_REF_SO)				###
.PHONY:run-env
ifdef CONFIG_DIFFTEST							###
run-env: $(BINARY) $(DIFF_REF_SO)
else
run-env: $(BINARY) #$(DIFF_REF_SO)
endif


.PHONY:run
run: run-env
	$(NEMU_EXEC)


.PHONY:gdb										###
gdb: run-env
	gdb -s $(BINARY) --args $(NEMU_EXEC)


.PHONY:build
build: $(BINARY)

#----------------------------------------------------------------------------------

./obj_dir/V$(MODULE): .zhong.verilate
	@echo
	@echo "### BUILDING SIM ###"
	make -C obj_dir -f V$(MODULE).mk V$(MODULE)


.PHONY:verilate
verilate: .zhong.verilate


# # --------------------------------------------------------------------------------
# # 将 .v 源文件转换为 C++ 代码，并生成用于构建模拟执行文件的构建文件
# # 使用 -Wall 选项启用所有 C++ 编译错误
# # 使用 --trace 选项启用波形跟踪功能
# # 使用 -cc .v 将 .v 模块转换为 C++ 代码
# # 使用 --exe tb_alu.cpp 告诉 Verilator tb_alu.cpp 是我们的 C++ 测试平台
# # -Wno-STMTDLY 避免弹出所有warning
# # -Wno-MODDUP 避免“Duplicate declaration”报错
# # --top-module $(MODULE) 确定底层模块，否则会将$(VSRCS)中的第一个文件前缀当成顶层模块
#----------------------------------------------------------------------------------						#####
.zhong.verilate: $(VSRCS) $(CSRCS)	#####
	@echo
	@echo "### VERILATING ###"
	verilator -Wno-STMTDLY -Wno-MODDUP --trace-fst --timescale "1ns/1ns" --no-timing --top-module $(MODULE) -cc $(VSRCS) --exe $(CSRCS) -I$(INC_PATH) -I$(YSYXSOC_UART_PATH) -I$(YSYXSOC_SPI_PATH) --prof-c --prof-cfuncs --prof-exec --autoflush
	@echo "LIBS +=$(LIBS)" >> ./obj_dir/V$(MODULE).mk    # to link readline and dlfcn library
# @echo "CXXFLAGS +=$(CXXFLAGS)" >> ./obj_dir/V$(MODULE).mk 
	@touch .zhong.verilate


# #make lint目标调用 Verilator 并使用 --lint-only 选项，可以快速解析.v文件并检查问题
# #用于进行lint检查，检查Verilog的语法问题
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

# ==================================================================================

# MODULE=ysyx_23060219
# CSRCS = $(shell find $(abspath ./csrc) -name "*.cpp")
# VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
# VSRCS += $(shell find $(abspath ./vsrc/*) -name "*.v")
# INC_PATH = $(NPC_HOME)/include/
# LIBS = -lreadline   # link the <readline> lib
# LIBS += -ldl        # link the <dlfcn> lib
# LIBS += $(shell llvm-config-11 --libs)
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
# gtkw: wave.gtkw
# 	@echo
# 	@echo "### WAVES ###"
# 	gtkwave wave.gtkw


# .PHONY:sim
# sim: waveform.vcd


# .PHONY:waves
# waves: waveform.vcd
# 	@echo
# 	@echo "### WAVES ###"
# 	gtkwave waveform.vcd


# .PHONY:waveform.vcd
# waveform.vcd: ./obj_dir/V$(MODULE)
# 	@echo
# 	@echo "### SIMULATING ###"
# 	@./obj_dir/V$(MODULE) #+verilator+rand+reset+2



# IMG ?=      #loaded by AM Makefile (npc.mk)
# override ARGS ?= --log=./log/npc-log.txt
# ifdef CONFIG_DIFFTEST						###
# override ARGS += $(ARGS_DIFF)
# # ARGS += $(ARGS_DIFF)
# endif
# BINARY := ./obj_dir/V$(MODULE)
# NEMU_EXEC := $(BINARY) $(ARGS) $(IMG)


# .PHONY:run-env
# ifdef CONFIG_DIFFTEST						###
# run-env: $(BINARY) $(DIFF_REF_SO)
# else
# run-env: $(BINARY) #$(DIFF_REF_SO)
# endif

# .PHONY:run
# run: run-env
# 	$(NEMU_EXEC)

# .PHONY:gdb
# gdb: run-env
# 	gdb -s $(BINARY) --args $(NEMU_EXEC)


# .PHONY:build
# build: $(BINARY)

# #----------------------------------------------------------------------------------
# ./obj_dir/V$(MODULE): .stamp.verilate
# 	@echo
# 	@echo "### BUILDING SIM ###"
# 	make -C obj_dir -f V$(MODULE).mk V$(MODULE)


# .PHONY:verilate
# verilate: .stamp.verilate


# # -Wno-STMTDLY 避免弹出所有warning
# # -Wno-MODDUP 避免“Duplicate declaration”报错
# # --top-module $(MODULE) 确定底层模块，否则会将$(VSRCS)中的第一个文件前缀当成顶层模块
# #----------------------------------------------------------------------------------
# .stamp.verilate: $(VSRCS) $(CSRCS)
# 	@echo
# 	@echo "### VERILATING ###"
# 	verilator -Wno-STMTDLY -Wno-MODDUP --trace --top-module $(MODULE) -cc $(VSRCS) --exe $(CSRCS) -I$(INC_PATH)
# 	@echo "LIBS +=$(LIBS)" >> ./obj_dir/V$(MODULE).mk    # to link readline and dlfcn library
# # @echo "CXXFLAGS +=$(CXXFLAGS)" >> ./obj_dir/V$(MODULE).mk 
# 	@touch .stamp.verilate


# #----------------------------------------------------------------------------------
# .PHONY:lint
# lint: $(MODULE).v
# 	#-lint-only- 告诉 Verilator 进行 lint 但不生成任何仿真输出
# 	verilator --lint-only $(MODULE).v


# .PHONY: clean
# clean:
# 	rm -rf .stamp.*;
# 	rm -rf ./obj_dir
# 	rm -rf waveform.vcd
# 	rm ./log/*

