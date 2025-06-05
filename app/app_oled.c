#include "hw_systick.h"
#include "hw_encoder.h"

#include "mid_encoder.h"
#include "mid_oled.h"
#include "mid_pid.h"

#include "app_oled.h"

unsigned char blink_status = 0;
uint32_t temp;

void oled_init(void)
{
		OLED_Init();
		OLED_Clear();
}

uint32_t ABS_num(long long num)
{
	if(num > 0) return (uint32_t)num;
	if(num < 0 ) return (uint32_t)-num;
	return 0;
}

void oled_show(void)
{
		// 编码器位数显示
    //temp = (uint32_t)encoder_old_num;
		//OLED_ShowString(2,10,(uint8_t*)"num",8,1);
		//OLED_ShowNum(30,10,temp,1,8,1);
		// 数字显示	
		//temp = ABS_num(encoder_num);
		//OLED_ShowNum(2,0,temp,5,8,1);
		temp = ABS_num(motor_encoder.count);
		OLED_ShowNum(30,0,temp,6,8,1);
		
		//pid参数显示
	
		OLED_ShowChar(0,50,'P',8,1);
		OLED_ShowNum(8,50,(pid_mode ? speed_pid.kp : angle_pid.kp),2,8,1);
		OLED_ShowChar(20,50,'.',8,1);
		OLED_ShowNum(25,50,(pid_mode ? speed_pid.kp : angle_pid.kp)*10,1,8,1);
	
		OLED_ShowChar(42,50,'I',8,1);
		OLED_ShowNum(50,50,(pid_mode ? speed_pid.ki : angle_pid.ki),2,8,1);
		OLED_ShowChar(62,50,'.',8,1);
		OLED_ShowNum(67,50,(pid_mode ? speed_pid.ki : angle_pid.ki)*10,1,8,1);
	
		OLED_ShowChar(85,50,'D',8,1);
		OLED_ShowNum(93,50,(pid_mode ? speed_pid.kd : angle_pid.kd),2,8,1);
		OLED_ShowChar(105,50,'.',8,1);
		OLED_ShowNum(110,50,(pid_mode ? speed_pid.kd : angle_pid.kd)*10,1,8,1);

		//目标值
		OLED_ShowChar(15,40,'S',8,1);
		OLED_ShowNum(25,40,(speed_pid.target),3,8,1);
		OLED_ShowChar(70,40,'A',8,1);
		OLED_ShowNum(80,40,angle_pid.target,3,8,1);

		OLED_Refresh();
		delay_ms(250);

		//闪烁
		switch(blink_status)
		{
			case 1:
				OLED_ShowString(8,50,(uint8_t*)"    ",8,1);
				break;
			case 2:
				OLED_ShowString(50,50,(uint8_t*)"    ",8,1);
				break;
			case 3:
				OLED_ShowString(93,50,(uint8_t*)"    ",8,1);
				break;
			case 4:
				OLED_ShowString(25,40,(uint8_t*)"   ",8,1);
				break;
			case 5:
				OLED_ShowString(80,40,(uint8_t*)"   ",8,1);
				break;
			default:break;
		}

		OLED_Refresh();
		delay_ms(250);
}
