#include "hw_encoder.h"

#include "mid_pid.h"
#include "mid_encoder.h"

#include "app_motor.h"
#include "app_oled.h"

uint16_t dat;

void motor_update(void)
{
	switch(blink_status)
	{
		case 1:
			//先乘后除，保证大小和类型
			if(pid_mode) speed_pid.kp = encoder_num / 10.0;
			else angle_pid.kp = encoder_num / 10.0;
			break;
		case 2:
			if(pid_mode) speed_pid.ki = encoder_num / 10.0;
			else angle_pid.ki = encoder_num / 10.0;
			break;
		case 3:
			if(pid_mode) speed_pid.kd = encoder_num / 10.0;
			else angle_pid.kd = encoder_num / 10.0;
			break;
		case 4:
			speed_pid.target = encoder_num;	
			break;
		case 5:
			angle_pid.target = encoder_num;
			break;
		default:
			if(pid_mode)
			{
				dat = get_encoder_count()*SPEED_PER_SPEED;
				motor_speed_control(speed_pid.target);
			}
			else
			{
				dat = motor_encoder.temp_count*DEGREES_PER_PLUSE;
				motor_angle_control(angle_pid.target);
			}
			OLED_ClearLastPoint(temp_y_point[line_num-18],line_num); //清除上一个
			temp_y_point[line_num-18] = dat; //记录这一个
			OLED_DrawCurPoint(dat,line_num);
			if(++line_num > 120) line_num = 18;
			break;
	}
	
}
