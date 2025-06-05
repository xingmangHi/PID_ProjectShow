#include "hw_motor.h"
#include "hw_encoder.h"

#include "mid_pid.h"

//每脉冲角度 k / 360/20000
#define DEGREES_PER_PLUSE 0.018f
//脉冲20ms扫描转速度（转/分）   k / 1000/20 /20000 
#define SPEED_PER_SPEED 0.0025f

PID angle_pid;
PID speed_pid;

uint8_t pid_mode = 1;

/** PID计算
* @param pid PID结构体
* @param target 目标值
* @param current 当前值
* @return 经过pid运算后的结果
*/
float pid_compute(PID* pid,float target,float current)
{
	pid->target = target;
	pid->last_error = pid->error;  //保存前一个误差
	pid->error = target - current; //计算新的误差
	
	float pout = pid->error;			 //比例项参数，即误差
	pid->integrate += pid->error;	 //积分项参数，累计和
	float dout = pid->error - pid->last_error; //微分项参数，本质是差的除法
	
	//积分限幅
	if(pid->integrate > pid->max_integrate) pid->integrate = pid->max_integrate;
	else if (pid->integrate < -pid->max_integrate) pid->integrate = -pid->max_integrate;

	pid->output = (pid->kp * pout) + (pid->ki * pid->integrate) + (pid->kd * dout);
	
	//输出限幅
	if(pid->output > pid->max_output) pid->output = pid->max_output;
	else if(pid->output < -pid->max_output) pid->output  = -pid->max_output;
	
	return pid->output;
}

void pid_init(PID* pid,float p ,float i ,float d,float maxI,float maxOut,int target)
{
	pid->kp = p;
	pid->ki = i;
	pid->kd = d;
	pid->error = 0;
	pid->max_integrate = maxI;
	pid->max_output = maxOut;
	pid->target = target;
}
/** pid定速
* @param terget_speed 
* @return 对应PID结构体的地址（用不上貌似）
*/
PID motor_speed_control(int target_speed)
{
	int speed;
	speed = pid_compute(&speed_pid,target_speed, get_encoder_count());
	
	if(speed > 0)
	{
		//set_motor(0,speed);
		test_motor(speed);
	}
	else if(speed < 0)
	{
		speed = -speed;
		//set_motor(speed,0);
		test_motor(MOTOR_PWM_MAX); //由于只做了一个pwm，只能强制减速
	}
	return speed_pid;
}

/** pid定距
* 定距 即 定角度
* 编码器线数为500，所以电机经过减速器旋转一圈编码器脉冲数为（500*2）*20 = 20000
* 每脉冲角度 360/20000
* 指定角度的脉冲数 = 目标角度 / 每脉冲角度 
* @param target_angle 目标角度
* @return 对应PID结构体的地址（用不上貌似）
*/
PID motor_angle_control(int target_angle)
{
	int PWM,target_pluses;
	target_pluses = target_angle / DEGREES_PER_PLUSE; //将角度换算成目标脉冲数
	PWM = pid_compute(&angle_pid,target_pluses,motor_encoder.temp_count);
	if(PWM>0)
	{
		test_motor(PWM);
		//set_motor(0,PWM);
	}
	else if(PWM<0)
	{
		PWM = -PWM;
		stop_motor();
		//set_motor(PWM,0);
	}
	return angle_pid;
}
	


