MEMORY {
	ITCM(rwx) : ORIGIN = 0x00000000, LENGTH = 512K
	DTCM(rwx) : ORIGIN = 0x20000000, LENGTH = 512K
	RAM(rwx) : ORIGIN = 0x20200000, LENGTH = 512K
	FLASH(rwx) : ORIGIN = 0x60000000, LENGTH = 7936K
}

ENTRY(image_vector_table)

SECTIONS
{
	.boot_structures : {
		KEEP(*(.flash_config))
		FILL(0xFF)
		. = ORIGIN(FLASH) + 0x1000;
		KEEP(*(.ivt))
		KEEP(*(.boot_data))
		. = ALIGN(1024);
	} > FLASH

	.text : {
		KEEP(*(.boot))
		. = ALIGN(4);
		*(.text)
	} >FLASH

	.data : {
		*(.data)
		_flash_end = .;
	} > DTCM AT> FLASH


	_flashimagelength = _flash_end - ORIGIN(FLASH);
}
