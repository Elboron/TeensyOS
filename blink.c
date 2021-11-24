#include "blink.h"

void setup() {
	/* LED 13 = GPIO_B0_03 -> see screenshot */
	/* SW_MUX_CTL_REGISTER = 0x401f 8148 */
	uint32_t* IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_03 = (uint32_t*)0x401f8148;


	/* Configure IOMUXC to GPIO 
	write sw_mux_ctl_pad_<output>.mux_mode, <GPIO_MUX_MODE */
	*IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_03 = 0x00000005;
	
	/* GPIO register offsets -> p. 961 */
	uint32_t* GPIO2_REGISTER = (uint32_t*)(0x401b8000 + 0x4000);
	uint32_t* GPIO2_DR_REGISTER = (uint32_t*)((uint32_t)GPIO2_REGISTER + 0x4);

	/* Set GDIR = 1  for output*/
	*GPIO2_DR_REGISTER = 0x00000001;

	/* Write otput to DR */
	*GPIO2_REGISTER = 0x00000001;

}
