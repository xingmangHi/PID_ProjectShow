#ifndef _MID_PID_H_
#define _MID_PID_H_

typedef struct
{
    float kp,ki,kd;  						//三个静态参数
    float integrate;						//积分项
    float error,last_error;			//误差，前一个误差
    float max_integrate;				//积分限幅
    float output,max_output;		//输出，输出限幅
    int target;									//目标
}PID;

extern PID angle_pid;
extern PID speed_pid;
extern unsigned char pid_mode;

void pid_init(PID* pid,float p ,float i ,float d,float maxI,float maxOut,int target);
float pid_compute(PID* PID,float target,float current);
PID motor_speed_control(int target_speed);
PID motor_angle_control(int target_angle);

#endif 