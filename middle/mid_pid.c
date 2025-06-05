#include "hw_motor.h"
#include "hw_encoder.h"

#include "mid_pid.h"

//ÿ����Ƕ� k / 360/20000
#define DEGREES_PER_PLUSE 0.018f
//����20msɨ��ת�ٶȣ�ת/�֣�   k / 1000/20 /20000 
#define SPEED_PER_SPEED 0.0025f

PID angle_pid;
PID speed_pid;

uint8_t pid_mode = 1;

/** PID����
* @param pid PID�ṹ��
* @param target Ŀ��ֵ
* @param current ��ǰֵ
* @return ����pid�����Ľ��
*/
float pid_compute(PID* pid,float target,float current)
{
	pid->target = target;
	pid->last_error = pid->error;  //����ǰһ�����
	pid->error = target - current; //�����µ����
	
	float pout = pid->error;			 //����������������
	pid->integrate += pid->error;	 //������������ۼƺ�
	float dout = pid->error - pid->last_error; //΢��������������ǲ�ĳ���
	
	//�����޷�
	if(pid->integrate > pid->max_integrate) pid->integrate = pid->max_integrate;
	else if (pid->integrate < -pid->max_integrate) pid->integrate = -pid->max_integrate;

	pid->output = (pid->kp * pout) + (pid->ki * pid->integrate) + (pid->kd * dout);
	
	//����޷�
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
/** pid����
* @param terget_speed 
* @return ��ӦPID�ṹ��ĵ�ַ���ò���ò�ƣ�
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
		test_motor(MOTOR_PWM_MAX); //����ֻ����һ��pwm��ֻ��ǿ�Ƽ���
	}
	return speed_pid;
}

/** pid����
* ���� �� ���Ƕ�
* ����������Ϊ500�����Ե��������������תһȦ������������Ϊ��500*2��*20 = 20000
* ÿ����Ƕ� 360/20000
* ָ���Ƕȵ������� = Ŀ��Ƕ� / ÿ����Ƕ� 
* @param target_angle Ŀ��Ƕ�
* @return ��ӦPID�ṹ��ĵ�ַ���ò���ò�ƣ�
*/
PID motor_angle_control(int target_angle)
{
	int PWM,target_pluses;
	target_pluses = target_angle / DEGREES_PER_PLUSE; //���ǶȻ����Ŀ��������
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
	


