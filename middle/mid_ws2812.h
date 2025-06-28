#ifndef _MID_WS2812_H_
#define _MID_WS2812_H_

/*
 * 立创开发板软硬件资料与相关扩展板软硬件资料官网全部开源
 * 开发板官网：www.lckfb.com
 * 技术支持常驻论坛，任何技术问题欢迎随时交流学习
 * 立创论坛：https://oshwhub.com/forum
 * 关注bilibili账号：【立创开发板】，掌握我们的最新动态！
 * 不靠卖板赚钱，以培养中国工程师为己任
 * Change Logs:
 * Date           Author       Notes
 * 2024-07-05     LCKFB-LP    first version
 */

#include "ti_msp_dl_config.h"

 #define WS2812_MAX        30   //彩灯最大个数
 #define WS2812_NUMBERS    3   //彩灯个数

 //用户修改参数区
 //#define WS2812_FREQUENCY
/*
 #define RED               0xff0000                  //红色
 #define GREEN             0x00ff00                  //绿色
 #define BLUE              0x0000ff                  //蓝色
 #define BLACK             0x000000                  //熄灭
 #define WHITE             0xffffff                  //白色
 */
 #define PWM_MAX 					24
 #define LEVEL_1					PWM_MAX/5
 #define LEVEL_0					PWM_MAX*4/5
 
extern unsigned int sign_led;
extern unsigned int TimerCCValueArray[WS2812_MAX*24];

void Ws2812b_WriteBit(unsigned char byte,unsigned char i);
void setLedCount(unsigned char count);//设置彩灯数目，范围0-25.
unsigned char getLedCount();//彩灯数目查询函数
void rgb_SetRGB(unsigned char LedId, unsigned char red, unsigned char green, unsigned char blue);//设置彩灯颜色
void rgb_SendArray(void);//发送彩灯数据
 
void RGB_LED_Reset(void);

#endif
