#include "hw_gpio_it.h"
#include "hw_encoder.h"
#include "mid_encoder.h"

//�������Ͱ����ж�

void gpio_encoder_init(void)
{
	//���ж�
	//NVIC_ClearPendingIRQ(MOTOR_INT_IRQN); 
	NVIC_EnableIRQ(MOTOR_INT_IRQN);
}

//GPIO�жϴ���
void GROUP1_IRQHandler(void)
{
	unsigned long gpio_status;
	
	//����������ж�
	gpio_status = DL_GPIO_getEnabledInterruptStatus(MOTOR_PORT,MOTOR_MOTOR_A_PIN|MOTOR_MOTOR_B_PIN);
	if((gpio_status & MOTOR_MOTOR_A_PIN)==MOTOR_MOTOR_A_PIN)
	{
		if(!DL_GPIO_readPins(MOTOR_PORT,MOTOR_MOTOR_B_PIN))
		{
			motor_encoder.temp_count++;
		}
		else
		{
			motor_encoder.temp_count--;
		}
	}
	else if((gpio_status & MOTOR_MOTOR_B_PIN) == MOTOR_MOTOR_B_PIN)
	{
		if(!DL_GPIO_readPins(MOTOR_PORT,MOTOR_MOTOR_A_PIN))
		{
			motor_encoder.temp_count--;
		}
		else
		{
			motor_encoder.temp_count++;
		}
	}
	//���״̬
	DL_GPIO_clearInterruptStatus(MOTOR_PORT,MOTOR_MOTOR_A_PIN|MOTOR_MOTOR_B_PIN);
}
