#ifndef _HW_MOTOR_H_
#define _HW_MOTOR_H_

#include "ti_msp_dl_config.h"

#define MOTOR_PWM_MAX 499

void test_motor(uint16_t value);
void set_motor(uint16_t In1_value,uint16_t In2_value);
void stop_motor(void);

#endif 