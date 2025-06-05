#ifndef _HW_WS2812_H_
#define _HW_WS2812_H_

#include "ti_msp_dl_config.h"

#define RGB_MAX 30
#define RGB_NUM 30

#define RGB_PIN_L() DL_GPIO_clearPins(WS2812_PORT,WS2812_LED_PIN_PIN)
#define RGB_PIN_H() DL_GPIO_setPins(WS2812_PORT,WS2812_LED_PIN_PIN)

#define RED          0xff0000 //红色
#define GREEN        0x00ff00 //绿色
#define BLUE         0x0000ff //蓝色
#define WHITE        0xffffff //白色
#define BLACK        0x000000 //黑色

void WS2812_WriteByte(uint8_t byte);


#endif