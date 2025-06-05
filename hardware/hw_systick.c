#include "hw_systick.h"

volatile uint32_t delay_times = 0;

void delay_10_us(uint32_t us)
{
	delay_times = us;
	while(delay_times!=0);
}

void delay_ms(uint32_t ms)
{
	for(int i = 0;i<100;i++)
	{
		delay_times = ms;
		while(delay_times!=0);
	}
}



void SysTick_Handler(void)
{
	if(delay_times != 0)
	{
		delay_times--;
	}
}