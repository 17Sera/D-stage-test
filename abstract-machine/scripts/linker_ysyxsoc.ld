ENTRY(_start)
PHDRS { text PT_LOAD; rodata PT_LOAD; data PT_LOAD; bss PT_LOAD; }   /*定义 ELF 文件的程序头表,若去掉则.text 和 .data 段的加载地址可能无法被识别*/

MEMORY {
  mrom : ORIGIN = 0x20000000, LENGTH = 4K   /* mrom = 0x20000000 ~ 0x20000fff */
  sram : ORIGIN = 0x0f000000, LENGTH = 8K   /* sram = 0x0f000000 ~ 0x0f001fff */
  /* mrom(rx) : ORIGIN = 0x20000000, LENGTH = 4K   mrom = 0x20000000 ~ 0x20000fff (rx)(rxw)会增大text*/ 
  /* sram(rxw) : ORIGIN = 0x0f000000, LENGTH = 8K   sram = 0x0f000000 ~ 0x0f001fff */
}

SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  /* . = _pmem_start + _entry_offset; */
  . = ORIGIN(mrom);     /*用于初始化位置,确保段的地址分配从指定内存区域的起始地址开始*/

  .text : {
    *(entry)
    *(.text*)
    /* _text_end = .; */
  } > mrom : text

  etext = .;
  _etext = .;


  .rodata : {
    *(.rodata*)
    *(.srodata*)
  } > mrom : rodata


  .data : {
    _data_start = .;    /*.data 段运行时起始地址 --- VMA --- SRAM*/
    *(.data*)
    *(.sdata*)
    _data_end = .;      /*.data 段运行时结束地址 --- VMA --- SRAM*/
  } > sram AT> mrom : data


  /* _data_end = ADDR(.bss); */
  _m_data_start = LOADADDR(.data); /* 动态获取 .data 的加载地址（LMA），不依赖 .*/
  edata = .;
  _data = .;


  .bss : {
	  _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    _bss_end = .;
  } > sram : bss


  _heap_start = 0x0f000800;
  /* _heap_start = ALIGN(0x10);     确保堆起始地址对齐到 16 字节 */
  _heap_end = _stack_top;
  /* . =  _heap_start + 0x800;
  _heap_end = .; */ 

  _stack_top = 0x0f001400;    /* 栈顶---堆底 */
  . = _stack_top + 0x0500;
  _stack_pointer = .;


  end = .;
  _end = .;

}
