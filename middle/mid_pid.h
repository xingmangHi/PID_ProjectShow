#ifndef _MID_PID_H_
#define _MID_PID_H_

typedef struct
{
    float kp,ki,kd;  						//������̬����
    float integrate;						//������
    float error,last_error;			//��ǰһ�����
    float max_integrate;				//�����޷�
    float output,max_output;		//���������޷�
    int target;									//Ŀ��
}PID;

extern PID angle_pid;
extern PID speed_pid;
extern unsigned char pid_mode;

void pid_init(PID* pid,float p ,float i ,float d,float maxI,float maxOut,int target);
float pid_compute(PID* PID,float target,float current);
PID motor_speed_control(int target_speed);
PID motor_angle_control(int target_angle);

#endif 