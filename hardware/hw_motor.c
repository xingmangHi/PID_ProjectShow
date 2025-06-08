#include "hw_motor.h"

//ÏÞÖÆÊäÈë
static void restrict_pwm_max_value(uint16_t* value)
{
    if(*value > MOTOR_PWM_MAX)
    {
        *value = MOTOR_PWM_MAX;
    }
}
static void set_test(uint16_t dat)
{
	DL_TimerG_setCaptureCompareValue(PWM_TEST_INST,dat,GPIO_PWM_TEST_C1_IDX);
}

static void set_In1(uint16_t dat)
{
		DL_TimerG_setCaptureCompareValue(PWM_MOTOR_1_INST,dat,GPIO_PWM_MOTOR_1_C1_IDX);
}

static void set_In2(uint16_t dat)
{
		DL_TimerG_setCaptureCompareValue(PWM_MOTOR_2_INST,dat,GPIO_PWM_MOTOR_2_C1_IDX);
}

void test_motor(uint16_t value)
{
	restrict_pwm_max_value(&value);
	set_test(value);
}

void set_motor(uint16_t In1_value,uint16_t In2_value)
{
	restrict_pwm_max_value(&In1_value);
	restrict_pwm_max_value(&In2_value);
	
	set_In1(In1_value);
	set_In2(In2_value);
}

void stop_motor(void)
{
	test_motor(MOTOR_PWM_MAX);
	set_motor(0,0);
}