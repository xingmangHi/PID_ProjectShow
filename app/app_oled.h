#ifndef _APP_OLED_H_
#define _APP_OLED_H_

#include "ti_msp_dl_config.h"

extern unsigned char blink_status;

extern uint8_t temp_y_wire; //目标线的y值
extern uint8_t temp_y_point[103];
extern uint8_t line_num;


void oled_show(void);
void oled_init(void);

void OLED_DrawCurPoint(uint16_t height,uint8_t x);
void OLED_ClearLastPoint(uint16_t height,uint8_t x);
	
#endif