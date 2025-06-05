#ifndef _HW_ENCODER_H_
#define _HW_ENCODER_H_

#include "ti_msp_dl_config.h"

typedef enum {
	FOWARD, //正向
	REVERSAL //反向
} ENCODER_DIR;

typedef struct {
	volatile long long temp_count; //保存实时计数值
	int count; //根据定时器时间更新计数值
	ENCODER_DIR dir; //旋转方向
}ENCODER_RES;

extern volatile ENCODER_RES motor_encoder;

typedef struct{
	unsigned char signed_bit:1; //编码器标志位
	unsigned char mid_bit:1; //第1位
	unsigned char height_bit:1; //第2位
	unsigned char low_bit:1; //第0位
}ENCODER_10;

extern ENCODER_10 encoder_10;


void motor_encoder_init(void);
int get_encoder_count(void);
ENCODER_DIR get_encoder_dir(void);
void encoder_update(void);
ENCODER_10 mdr_scan(void);

#endif