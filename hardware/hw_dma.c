#include "hw_dma.h"
#include "mid_ws2812.h"

volatile bool gChannel0InterruptTaken = false;

void dma_init(void)
{
	NVIC_EnableIRQ(DMA_INT_IRQn);
	DL_DMA_setSrcAddr(DMA,DMA_WS2812_CHAN_ID,(uint32_t)TimerCCValueArray); //源地址，
	DL_DMA_setDestAddr(DMA,DMA_WS2812_CHAN_ID,(TIMA1->COUNTERREGS.CC_01[0])); //目标地址，定时器比较值
	DL_DMA_setTransferSize(DMA,DMA_WS2812_CHAN_ID,1); //设置传输大小
	DL_DMA_enableChannel(DMA,DMA_WS2812_CHAN_ID); //开启通道
}

void DMA_IRQHandler(void)
{
	gChannel0InterruptTaken = true;
	NVIC_ClearPendingIRQ(DMA_INT_IRQn);
}