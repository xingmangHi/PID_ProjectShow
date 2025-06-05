#ifndef _MID_BUTTON_H_
#define _MID_BUTTON_H_

#include "flexible_button.h"
#include "hw_key.h"
#include "app_key_task.h"

void set_app_key_currnet_mode(char mode);
char get_app_key_currnet_mode(void);

void user_button_init(void);

#endif