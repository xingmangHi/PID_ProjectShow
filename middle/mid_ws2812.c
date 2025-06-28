/*
 * 立创开发板软硬件资料与相关扩展板软硬件资料官网全部开源
 * 开发板官网：www.lckfb.com
 * 技术支持常驻论坛，任何技术问题欢迎随时交流学习
 * 立创论坛：https://oshwhub.com/forum
 * 关注bilibili账号：【立创开发板】，掌握我们的最新动态！
 * 不靠卖板赚钱，以培养中国工程师为己任
 * Change Logs:
 * Date           Author       Notes
 * 2025-06-27     YC       another version
 */
#include "hw_systick.h"
#include "hw_dma.h"
#include "mid_ws2812.h"
#include "stdio.h"
#include "math.h"
 
 
unsigned int  ledsCount   = WS2812_NUMBERS;   //定义实际彩灯默认个数
unsigned int  nbLedsBytes = WS2812_NUMBERS*3; //定义实际彩灯颜色数据个数

unsigned int TimerCCValueArray[WS2812_MAX*24]; //DMA传输源数组,每位储存定时器比较捕获值

static void ws2812_enable(void)
{
	DL_TimerA_setCaptureCompareValue(PWM_WS2812_INST,PWM_MAX,GPIO_PWM_WS2812_C0_IDX); //先拉低
	delay_ms(2);

	
	gChannel0InterruptTaken = false;
	DL_DMA_startTransfer(DMA,DMA_WS2812_CHAN_ID); //打开DMA传输
	
	NVIC_ClearPendingIRQ(PWM_WS2812_INST_INT_IRQN);
	NVIC_EnableIRQ(PWM_WS2812_INST_INT_IRQN); //打开中断
}
static void ws2812_disable(void)
{
	DL_TimerA_setCaptureCompareValue(PWM_WS2812_INST,PWM_MAX,GPIO_PWM_WS2812_C0_IDX);
	NVIC_DisableIRQ(PWM_WS2812_INST_INT_IRQN);
}


 /******************************************************************
  * 函 数 名 称：rgb_SetColor
  * 函 数 说 明：设置彩灯颜色
  * 函 数 形 参：LedId控制的第几个灯  color颜色数据
  * 函 数 返 回：无
  * 作       者：YC
  * 备       注：
 ******************************************************************/
//WS2812编码顺序为GRB
static void rgb_SetColor(unsigned char LedId, unsigned long color)
 {
     if( LedId > ledsCount )
     {
         return;    //to avoid overflow
     }
		 for(unsigned char i=8;i<32;i++)
		 {
			 TimerCCValueArray[LedId*24+i-8] = (color<<i)&0x800000 ? LEVEL_1 : LEVEL_0; //计算每一位
		 }
 }
 
 /******************************************************************
  * 函 数 名 称：rgb_SetRGB
  * 函 数 说 明：设置彩灯颜色(三原色设置)
  * 函 数 形 参：LedId控制的第几个灯 red红色数据  green绿色数据  blue蓝色数据
  * 函 数 返 回：无
  * 作       者：LC
  * 备       注：无
 ******************************************************************/
 void rgb_SetRGB(unsigned char LedId, unsigned char red, unsigned char green, unsigned char blue)
 {
	 unsigned long Color=red<<8|green<<16|blue; //24位数，long为32位，高8位为0
     rgb_SetColor(LedId,Color);
 }
 
 
 /******************************************************************
  * 函 数 名 称：RGB_LED_Reset
  * 函 数 说 明：复位ws2812
  * 函 数 形 参：无
  * 函 数 返 回：无
  * 作       者：LC
  * 备       注：低电平280us以上
 ******************************************************************/
 void RGB_LED_Reset(void)
 {
		DL_TimerA_setCaptureCompareValue(PWM_WS2812_INST,PWM_MAX,GPIO_PWM_WS2812_C0_IDX);
	 delay_10_us(28);
 }
 
void rgb_SendArray(void)
{
	ws2812_enable();
}
 
 
void PWM_WS2812_INST_IRQHandler(void)
 {
	 switch(DL_TimerA_getPendingInterrupt(PWM_WS2812_INST))
		{
			case DL_TIMER_IIDX_ZERO: //定时器溢出中断

				break;
			case DL_TIMER_IIDX_CC0_DN: //比较中断
				//if(gChannel0InterruptTaken == true) //在DMA传输完成后传输
				//{
					gChannel0InterruptTaken = false;
					DL_DMA_startTransfer(DMA,DMA_WS2812_CHAN_ID);
					
				//}
				break;
			default:
				break;
			
		}
}