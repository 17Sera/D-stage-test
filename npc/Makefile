all:

TOPNAME = example	
VSRC = $(shell find $(./vsrc) -name "*.v")
CSRC = $(shell find $(./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")

VERIARG = -Wall --trace --cc --exe --build

sim:$(CSRC) $(VSRC)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!

	verilator $(VERIARG) \
		-top $(TOPNAME) \
		$^ 
		
	./obj_dir/Vexample
	gtkwave wave.vcd

	rm -rf obj_dir
	rm wave.vcd
	
include ../Makefile
