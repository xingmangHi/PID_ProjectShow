#include "hw_systick.h"
#include "hw_encoder.h"
#include "hw_motor.h"

#include "mid_encoder.h"
#include "mid_oled.h"
#include "mid_pid.h"

#include "app_oled.h"

unsigned char blink_status = 0;
uint32_t temp;
uint8_t temp_y_wire=10; //目标线的y值
uint8_t temp_y_point[103];

uint8_t line_num = 18; 

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

static void OLED_DrawWire(uint16_t height)
{
	uint8_t y = height ; 
	//划定显示范围，10-30
	if(pid_mode) y = height*20/(MOTOR_PWM_MAX+1)+10;
	else y = height*20/360+10;
	
	if(y>30) y = 30;
	else if(y<10) y = 10;
	
	if(y != temp_y_wire){
		OLED_ShowString(0,(temp_y_wire-5),(uint8_t*)"                     ",8,1);
		temp_y_wire = y;
	}
		
	OLED_ShowChar(5,y-4,'T',8,1);
	OLED_DrawLine(18,y,120,y,1); //参考线	
}

void OLED_DrawCurPoint(uint16_t height,uint8_t x)
{
	uint8_t y = height ; 
	//划定显示范围，10-30
	if(pid_mode) y = height*20/(MOTOR_PWM_MAX+1)+10;
	else y = height*20/360+10;
	
	OLED_DrawPoint(x,y,1);
}
void OLED_ClearLastPoint(uint16_t height,uint8_t x)
{
	uint8_t y = height ; 
	//划定显示范围，10-30
	if(pid_mode) y = height*20/(MOTOR_PWM_MAX+1)+10;
	else y = height*20/360+10;
	
	OLED_DrawPoint(x,y,0);
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
		//temp = ABS_num(motor_encoder.temp_count);
		//OLED_ShowNum(30,0,temp,6,8,1);
		
	
	
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
	
		//目标值线
		OLED_DrawWire(pid_mode?speed_pid.target:angle_pid.target);
		
		OLED_Refresh();
		
		//闪烁
		if(blink_status)
		{
		delay_ms(250);
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
		
		//PID线显示
		/*
		uint16_t dat;
		if(pid_mode) dat = get_encoder_count()*SPEED_PER_SPEED;
		else dat = motor_encoder.temp_count*DEGREES_PER_PLUSE;
		for(line_num = 18;line_num<120;line_num++)
		{
			OLED_ClearLastPoint(temp_y_point[line_num-18],line_num); //清除上一个
			temp_y_point[line_num-18] = dat; //记录这一个
			OLED_DrawCurPoint(dat,line_num);
			OLED_Refresh();
		}
		*/
		
}

