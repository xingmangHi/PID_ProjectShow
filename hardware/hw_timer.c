#include "hw_timer.h"
#include "hw_encoder.h"
#include "mid_encoder.h"
#include "mid_button.h"
#include "mid_pid.h"
#include "mid_ws2812.h"

void timer_init(void)
{
	NVIC_ClearPendingIRQ(TIMER_SCAN_INST_INT_IRQN);
	NVIC_EnableIRQ(TIMER_SCAN_INST_INT_IRQN);
}

void TIMER_SCAN_INST_IRQHandler(void)
{
    switch(DL_TimerA_getPendingInterrupt(TIMER_SCAN_INST))
		{
			case DL_TIMER_IIDX_ZERO: 
				//Ðý×ª±àÂëÆ÷
				encoder_10 = mdr_scan();
				encoder_num_update();
				//°´¼ü
				flex_button_scan();
				//µç»ú±àÂëÆ÷
				if(pid_mode) encoder_update();
			break;
			default:
				break;
		}

}