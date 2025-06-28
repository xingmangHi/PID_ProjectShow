#include "hw_dma.h"
#include "mid_ws2812.h"

volatile bool gChannel0InterruptTaken = false;

void dma_init(void)
{
	NVIC_EnableIRQ(DMA_INT_IRQn);
	DL_DMA_setSrcAddr(DMA,DMA_WS2812_CHAN_ID,(uint32_t)TimerCCValueArray); //Դ��ַ��
	DL_DMA_setDestAddr(DMA,DMA_WS2812_CHAN_ID,(TIMA1->COUNTERREGS.CC_01[0])); //Ŀ���ַ����ʱ���Ƚ�ֵ
	DL_DMA_setTransferSize(DMA,DMA_WS2812_CHAN_ID,1); //���ô����С
	DL_DMA_enableChannel(DMA,DMA_WS2812_CHAN_ID); //����ͨ��
}

void DMA_IRQHandler(void)
{
	gChannel0InterruptTaken = true;
	NVIC_ClearPendingIRQ(DMA_INT_IRQn);
}