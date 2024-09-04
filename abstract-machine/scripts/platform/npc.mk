# AM_SRCS := riscv/npc/start.S \
#            riscv/npc/trm.c \
#            riscv/npc/ioe.c \
#            riscv/npc/timer.c \
#            riscv/npc/input.c \
#            riscv/npc/cte.c \
#            riscv/npc/trap.S \
#            platform/dummy/vme.c \
#            platform/dummy/mpe.c
# #   riscv/npc/gpu.c \   

# CFLAGS    += -fdata-sections -ffunction-sections
# LDFLAGS   += -T $(AM_HOME)/scripts/linker.ld \
# 			             --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
# LDFLAGS   += --gc-sections -e _start

# ######################
# NPCFLAGS += -l $(shell dirname $(IMAGE).elf)/npc-log.txt
# NPCFLAGS += -e $(IMAGE).elf            #开启解析elf文件功能

# # --------- not used --------------
# # NPCFLAGS += -b
# #NPCFLAGS += -d
# # NPCFLAGS += -i

# #按monitor定义的顺序排  d在i前面
# #NPCFLAGS += -l ./log/npc-log.txt
# #CFLAGS += -I$(AM_HOME)/am/src/riscv
# # ----------------------------------

# CFLAGS += -DMAINARGS=\"$(mainargs)\"

# .PHONY: $(AM_HOME)/am/src/riscv/npc/trm.c

# image: $(IMAGE).elf
# 	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
# 	@echo + OBJCOPY "->" $(IMAGE_REL).bin
# 	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

# #####################

# run: image
# #	$(MAKE) -C $(NPC_HOME) ISA=$(ISA) run ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin ELF=$(IMAGE).elf
# 	$(MAKE) -C $(NPC_HOME) ISA=$(ISA) run ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin

#  gdb: image
# 	$(MAKE) -C $(NPC_HOME) ISA=$(ISA) gdb ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin
# //====================================================================================================

AM_SRCS := riscv/npc/start.S \
           riscv/npc/trm.c \
           riscv/npc/ioe.c \
           riscv/npc/timer.c \
           riscv/npc/input.c \
           riscv/npc/cte.c \
           riscv/npc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(AM_HOME)/scripts/linker.ld \
						 --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
##
NPCFLAGS += -l $(shell dirname $(IMAGE).elf)/npc-log.txt
# NPCFLAGS += -l ./log/npc-log.txt
NPCFLAGS += -e $(IMAGE).elf
NPCFLAGS += -b


CFLAGS += -DMAINARGS=\"$(mainargs)\"
.PHONY: $(AM_HOME)/am/src/riscv/npc/trm.c

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin
##
run: image
	$(MAKE) -C $(NPC_HOME) ISA=$(ISA) run ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin

gdb: image
	$(MAKE) -C $(NPC_HOME) ISA=$(ISA) gdb ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin