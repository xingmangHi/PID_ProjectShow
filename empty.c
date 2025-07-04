/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ti_msp_dl_config.h"

#include "hw_gpio_it.h"
#include "hw_systick.h"
#include "hw_timer.h"
#include "hw_motor.h"
#include "hw_dma.h"

#include "mid_uart.h"
#include "mid_oled.h"
#include "mid_button.h"
#include "mid_pid.h"
#include "mid_ws2812.h"

#include "app_oled.h"
#include "app_motor.h"


int main(void)
{
    SYSCFG_DL_init();
		//uart0_init(); //����
		//oled_init();  //��Ļ
		//gpio_encoder_init();  //�������ж�
		//user_button_init();
		//pid_init(&speed_pid,0.6,0.1,0,500,500,100);
		//pid_init(&angle_pid,0.5,1,0.2,500,500,180);
	
		//timer_init();  //ɨ��
		//stop_motor();
		dma_init();
		int i = 0;
	
    while (1) {
			//oled_show();
			//motor_update();
		  for( i = 0; i < 2; i++ )
          {
            rgb_SetRGB(i,255,0,0);
          }
				rgb_SendArray();
       delay_ms(3000);
		}
}
