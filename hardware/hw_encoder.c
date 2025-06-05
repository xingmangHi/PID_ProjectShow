#include "hw_encoder.h"

volatile ENCODER_RES motor_encoder;
ENCODER_10 encoder_10;

void motor_encoder_init(void)
{
	motor_encoder.count = 0;
	motor_encoder.temp_count = 0;
	motor_encoder.dir = FOWARD;
}

int get_encoder_count(void)
{
	return motor_encoder.count;
}
ENCODER_DIR get_encoder_dir(void)
{
	return motor_encoder.dir;
}


//���������ݸ���
//��� 20ms ����һ��
void encoder_update(void)
{
	//����ٶȼ�Ϊ count/2 /20*1000 * ������
	motor_encoder.count = motor_encoder.temp_count;
	
	//ȷ������
	motor_encoder.dir = (motor_encoder.count >=0) ? FOWARD :REVERSAL;
	
	motor_encoder.temp_count = 0;
}


//�ж϶�ȡ���������������ʲ���ɨ��ķ�ʽ��ȡ����
ENCODER_10 mdr_scan(void)
{
	ENCODER_10 encoder;
	encoder.signed_bit = DL_GPIO_readPins(MDR_PORT,MDR_MDR_2_PIN) >0 ? 1 : 0 ;
	encoder.mid_bit = DL_GPIO_readPins(MDR_PORT,MDR_MDR_1_PIN) >0 ? 1 : 0;
	encoder.height_bit = DL_GPIO_readPins(MDR_PORT,MDR_MDR_3_PIN) >0 ? 1 : 0;
	encoder.low_bit = DL_GPIO_readPins(MDR_PORT,MDR_MDR_4_PIN) >0 ? 1 : 0;
	return encoder;
}
	