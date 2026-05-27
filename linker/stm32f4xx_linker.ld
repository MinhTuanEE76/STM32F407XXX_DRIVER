/* ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
    SRAM  (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

_estack = ORIGIN(SRAM) + LENGTH(SRAM);

SECTIONS
{
    .text :
    {
        _stext = .;
        KEEP(*(.isr_vector))
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
        _etext = .;

    } > FLASH

    _la_data = LOADADDR(.data);

    .data :
    {
        _sdata = .;

        *(.data*)

        . = ALIGN(4);

        _edata = .;

    } > SRAM AT > FLASH

    .bss :
    {
        _sbss = .;

        *(.bss*)
        *(COMMON)

        . = ALIGN(4);

        _ebss = .;

    } > SRAM
} */



ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
    SRAM  (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

_estack = ORIGIN(SRAM) + LENGTH(SRAM);


_Min_Heap_Size  = 0x400;   /* 1 KB */
_Min_Stack_Size = 0x1000;  /* 4 KB */


SECTIONS
{
    .isr_vector :
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
        . = ALIGN(4);

    } > FLASH

    .text :
    {
        . = ALIGN(4);

        _stext = .;

        *(.text*)
        *(.rodata*)

        *(.glue_7)
        *(.glue_7t)

        KEEP(*(.init))
        KEEP(*(.fini))

        . = ALIGN(4);

        _etext = .;

    } > FLASH

    .preinit_array :
    {
        . = ALIGN(4);
        KEEP(*(.preinit_array*))
        . = ALIGN(4);

    } > FLASH

    .init_array :
    {
        . = ALIGN(4);
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array*))
        . = ALIGN(4);

    } > FLASH

    .fini_array :
    {
        . = ALIGN(4);
        KEEP(*(SORT(.fini_array.*)))
        KEEP(*(.fini_array*))
        . = ALIGN(4);

    } > FLASH

    
    _la_data = LOADADDR(.data);

    .data :
    {
        . = ALIGN(4);

        _sdata = .;

        *(.data*)

        . = ALIGN(4);

        _edata = .;

    } > SRAM AT > FLASH

    .bss :
    {
        . = ALIGN(4);

        _sbss = .;

        *(.bss*)
        *(COMMON)

        . = ALIGN(4);

        _ebss = .;

    } > SRAM

    
    ._user_heap_stack :
    {
        . = ALIGN(8);

        PROVIDE(end = .);
        PROVIDE(_end = .);

        . = . + _Min_Heap_Size;
        . = . + _Min_Stack_Size;

        . = ALIGN(8);

    } > SRAM

      
    /DISCARD/ :
    {
        *(.note*)
        *(.comment*)
    }
}