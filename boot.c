#include <stdint.h>
#include "blink.h"

extern unsigned long _flashimagelength;

__attribute__ ((section(".boot_data"), used))
/* Boot data p. 262 */
uint32_t boot_data[] = {
	0x60000000,	// Address of the image
	(uint32_t)&_flashimagelength,	// Length of the image
	0x00000000	// Plugin Flag
};

int startup() {
	setup();
	while (1);
}

/* Image Vector Table p. 262 */
__attribute__ ((section(".ivt"), used))
uint32_t image_vector_table[] = {
	0x432000D1,	// Header
	(uint32_t)startup,	// Entry
	0x00000000,	// Reserved
	0x00000000,	// DCD-Address
	(uint32_t)boot_data,	// Boot Data
	(uint32_t)image_vector_table,	// Self
	0x00000000,	// CSF
	0x00000000	// Reserved
};

__attribute__ ((section(".flash_config"), used))
/* FlexSPI Nor config p. 230 */
uint32_t serial_nor_config[] = {
	/* memCfg => FlexSPI Configuration Block p.226 */
	0x42464346,	// Tag
	0x56010000,	// Version
	0x00000000,	// Reserved
	0x00030301,	// columnAddressWidth, csSetupTime, csHoldTime, readSampleClk
	0x00000000,	// waitTimeCfgCommands, Reserved, deviceModeCfgEnable
	0x00000000,	// deviceModeSeq
	0x00000000,	// deviceModeArg
	0x00000000,	// Reserved, configCmdEnable
	0x00000000, 	// cfgCmdSeqs_1
	0x00000000, 	// cfgCmdSeqs_2
	0x00000000, 	// cfgCmdSeqs_3
	0x00000000,	// Reserved
	0x00000000,	// cfgCmdArgs_1
	0x00000000,	// cfgCmdArgs_2
	0x00000000,	// cfgCmdArgs_3
	0x00000000,	// Reserved
	0x00000000,	// controllerMiscOptions
	0x00010401,	// lutCustomSeqEnable, serialClkFreq, sFlashPadType, deviceTyp
	0x00000000,	// Reserved
	0x00000000,	// Reserved
	0x00800000,	// sflashA1Size
	0x00000000,	// sflashA2Size
	0x00000000,	// sflashB1Size
	0x00000000,	// sflashB2Size
	0x00000000,	// csPadSettingOverride
	0x00000000,	// sclkPadSettingOverride
	0x00000000,	// dataPadSettingOverride
	0x00000000,	// dqsPadSettingOverride
	0x00000000,	// timeoutInMs
	0x00000000,	// commandInterval
	0x00000000,	// dataValidTime
	0x00000000,	// busyBitPolarity, busyOffset
	0x00000000,	// lookupTable[0] -> Read
	0x00000000,	// lookupTable[1] -> ReadStatus
	0x00000000,	// lookupTable[2] -> Reserved
	0x00000000,	// lookupTable[3] -> WriteEnable
	0x00000000,	// lookupTable[4] -> Reserved
	0x00000000,	// lookupTable[5] -> EraseSector
	0x00000000,	// lookupTable[6] -> Reserved
	0x00000000,	// lookupTable[7] -> Reserved
	0x00000000,	// lookupTable[8] -> Reserved
	0x00000000,	// lookupTable[9] -> PageProgram
	0x00000000,	// lookupTable[10] -> Reserved
	0x00000000,	// lookupTable[11] -> ChipErase
	0x00000000,	// lookupTable[12] -> Reserved
	0x00000000,	// lookupTable[13] -> Reserved
	0x00000000,	// lookupTable[14] -> Reserved
	0x00000000,	// lookupTable[15] -> Dummy
	0x00000000,	// lookupTable[16]
	0x00000000,	// lookupTable[17]
	0x00000000,	// lookupTable[18]
	0x00000000,	// lookupTable[19]
	0x00000000,	// lookupTable[20]
	0x00000000,	// lookupTable[21]
	0x00000000,	// lookupTable[22]
	0x00000000,	// lookupTable[23]
	0x00000000,	// lookupTable[24]
	0x00000000,	// lookupTable[25]
	0x00000000,	// lookupTable[26]
	0x00000000,	// lookupTable[27]
	0x00000000,	// lookupTable[28]
	0x00000000,	// lookupTable[29]
	0x00000000,	// lookupTable[30]
	0x00000000,	// lookupTable[31]
	0x00000000,	// lookupTable[32]
	0x00000000,	// lookupTable[33]
	0x00000000,	// lookupTable[34]
	0x00000000,	// lookupTable[35]
	0x00000000,	// lookupTable[36]
	0x00000000,	// lookupTable[37]
	0x00000000,	// lookupTable[38]
	0x00000000,	// lookupTable[39]
	0x00000000,	// lookupTable[40]
	0x00000000,	// lookupTable[41]
	0x00000000,	// lookupTable[42]
	0x00000000,	// lookupTable[43]
	0x00000000,	// lookupTable[44]
	0x00000000,	// lookupTable[45]
	0x00000000,	// lookupTable[46]
	0x00000000,	// lookupTable[47]
	0x00000000,	// lookupTable[48]
	0x00000000,	// lookupTable[49]
	0x00000000,	// lookupTable[50]
	0x00000000,	// lookupTable[51]
	0x00000000,	// lookupTable[52]
	0x00000000,	// lookupTable[53]
	0x00000000,	// lookupTable[54]
	0x00000000,	// lookupTable[55]
	0x00000000,	// lookupTable[56]
	0x00000000,	// lookupTable[57]
	0x00000000,	// lookupTable[58]
	0x00000000,	// lookupTable[59]
	0x00000000,	// lookupTable[60]
	0x00000000,	// lookupTable[61]
	0x00000000,	// lookupTable[62]
	0x00000000,	// lookupTable[63]
	0x00000000,	// Reserved
	0x00000000,	// Reserved
	0x00000000,	// Reserved
	0x00000000,	// Reserved

	/* Serial NOR Configuration Block p. 230 */
	1024,		// pageSize
	4096,		// sectorSize
	0x00000000,	// ipCmdSerialClkFreq
	0x00000000,	// Reserved
	0x00000000,	// Reserved
	0x00000000,	// Reserved
	0x00000000,	// Reserved
	0x00000000,	// Reserved
	0x00000000,	// Reserved
	0x00000000,	// Reserved
	0x00000000,	// Reserved
	0x00000000,	// Reserved
	0x00000000,	// Reserved
	0x00000000,	// Reserved
	0x00000000,	// Reserved
	0x00000000,	// Reserved
};
