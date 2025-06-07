#include "mid_pid.h"
#include "mid_encoder.h"

#include "app_motor.h"
#include "app_oled.h"


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
			if(pid_mode) motor_speed_control(speed_pid.target);
			else  motor_angle_control(angle_pid.target);
			break;
	}
	
}
