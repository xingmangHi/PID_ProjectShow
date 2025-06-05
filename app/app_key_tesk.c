#include "hw_motor.h"

#include "mid_oled.h"
#include "mid_encoder.h"
#include "mid_pid.h"

#include "app_key_task.h"
#include "app_oled.h"

static char current_mode;
static int motor_status = 0;

void set_app_key_currnet_mode(char mode)
{
    current_mode = mode;
}
char get_app_key_currnet_mode(void)
{
    return current_mode;
}

void btn_up_cb(void *arg)
{
	
	flex_button_t *btn = (flex_button_t *)arg;
    switch(btn->event)
    {
        case FLEX_BTN_PRESS_CLICK: // 单击事件
						//OLED_ShowNum(0,20,1,1,8,1);
            break;
				case FLEX_BTN_PRESS_LONG_START:
						if(blink_status == 0)
						{
							if(pid_mode)
							{
							blink_status = 4;
							encoder_num = speed_pid.target;
							}
							else 
							{
								blink_status = 5;
								encoder_num = angle_pid.target;
							}
						}
						else blink_status = 0;
						break;
        case FLEX_BTN_PRESS_LONG_HOLD:  //长按保持
						//OLED_ShowString(0,20,(uint8_t*)"1A",8,1);
            break;
        case FLEX_BTN_PRESS_LONG_HOLD_UP: // 长按保持后抬起
						//OLED_ShowString(0,20,(uint8_t*)"1AS",8,1);
            break;
        default: break;
    }
}
void btn_down_cb(void *arg)
{
	flex_button_t *btn = (flex_button_t *)arg;
    switch(btn->event)
    {
        case FLEX_BTN_PRESS_CLICK: // 单击事件
					
						//OLED_ShowNum(8,20,2,1,8,1);
            break;
        case FLEX_BTN_PRESS_LONG_START:  //长按开始
						if(blink_status == 0)
						{
							blink_status = 1;
							if(pid_mode) encoder_num = speed_pid.kp*10;
							else encoder_num = angle_pid.kp *10;
						}
						else blink_status = 0;
						//OLED_ShowString(8,20,(uint8_t*)" ",8,1);
            break;
        case FLEX_BTN_PRESS_LONG_HOLD_UP: // 长按保持后抬起
						
            break;
        default: break;
    }
}
void btn_left_cb(void *arg)
{
	flex_button_t *btn = (flex_button_t *)arg;
    switch(btn->event)
    {
        case FLEX_BTN_PRESS_CLICK:
						//OLED_ShowNum(16,20,3,1,8,1);
            //set_app_key_currnet_mode(!get_app_key_currnet_mode());
            break;
        case FLEX_BTN_PRESS_LONG_START:
						//OLED_ShowString(16,20,(uint8_t*)" ",8,1);
						if(blink_status != 0)
						{
							blink_status--;
							switch(blink_status)
							{
								//等于0不用额外处理
								case 1:
									if(pid_mode) encoder_num = speed_pid.kp * 10;
									else encoder_num = angle_pid.kp * 10;
									break;
								case 2:
									if(pid_mode) encoder_num = speed_pid.ki * 10;
									else encoder_num = angle_pid.ki * 10;
									break;
								case 3:
									blink_status = 0;
									break;
								case 4:
									pid_mode = 1;
									encoder_num = speed_pid.target;
									break;
							}
						}	
            break;
        default: break;
    }
}
void btn_right_cb(void *arg)
{
	flex_button_t *btn = (flex_button_t *)arg;
    switch(btn->event)
    {
        case FLEX_BTN_PRESS_CLICK:
						//OLED_ShowNum(24,20,4,1,8,1);
            //set_app_key_currnet_mode(!get_app_key_currnet_mode());
            break;
				case FLEX_BTN_PRESS_LONG_START:
						if(blink_status != 0)
						{
							blink_status++;
							switch(blink_status)
							{
								case 2:
									if(pid_mode) encoder_num = speed_pid.ki * 10;
									else encoder_num = angle_pid.ki * 10;
									break;
								case 3:
									if(pid_mode) encoder_num = speed_pid.kd * 10;
									else encoder_num = angle_pid.kd * 10;
									break;
								case 4:
									blink_status = 0;
									break;
								case 5:
									pid_mode = 0;
									encoder_num = angle_pid.target;
									break;
								case 6:
									blink_status = 0;
									break;
							}								
						}	
						break;
        case FLEX_BTN_PRESS_LONG_HOLD:
						//OLED_ShowString(24,20,(uint8_t*)" ",8,1);

            break;
				case FLEX_BTN_PRESS_LONG_HOLD_UP:
					
					break;
        default: break;
    }
}
