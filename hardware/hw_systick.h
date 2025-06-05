#ifndef _HW_SYSTICK_H_
#define _HW_SYSTICK_H_

#include "ti_msp_dl_config.h"

extern volatile uint32_t delay_times;


void delay_ms(uint32_t ms);
	
#endif