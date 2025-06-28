#ifndef _HW_DMA_H_
#define _HW_DMA_H_

#include "ti_msp_dl_config.h"

extern volatile bool gChannel0InterruptTaken;

void dma_init(void);

#endif