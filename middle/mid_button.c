#include "string.h"
#include "mid_button.h"

#define ENUM_TO_STR(e) (#e)

typedef enum
{
    USER_BUTTON_UP = 0,
    USER_BUTTON_DOWN,
    USER_BUTTON_LEFT,
    USER_BUTTON_RIGHT,
    USER_BUTTON_MAX //最后一位总是MAX
} user_button_t;

/*
static char *enum_event_string[] = {
    ENUM_TO_STR(FLEX_BTN_PRESS_DOWN),
    ENUM_TO_STR(FLEX_BTN_PRESS_CLICK),
    ENUM_TO_STR(FLEX_BTN_PRESS_DOUBLE_CLICK),
    ENUM_TO_STR(FLEX_BTN_PRESS_REPEAT_CLICK),
    ENUM_TO_STR(FLEX_BTN_PRESS_SHORT_START),
    ENUM_TO_STR(FLEX_BTN_PRESS_SHORT_UP),
    ENUM_TO_STR(FLEX_BTN_PRESS_LONG_START),
    ENUM_TO_STR(FLEX_BTN_PRESS_LONG_UP),
    ENUM_TO_STR(FLEX_BTN_PRESS_LONG_HOLD),
    ENUM_TO_STR(FLEX_BTN_PRESS_LONG_HOLD_UP),
    ENUM_TO_STR(FLEX_BTN_PRESS_MAX),
    ENUM_TO_STR(FLEX_BTN_PRESS_NONE),
};

static char *enum_btn_id_string[] = {
    ENUM_TO_STR(USER_BUTTON_UP),
    ENUM_TO_STR(USER_BUTTON_DOWN),
    ENUM_TO_STR(USER_BUTTON_LEFT),
    ENUM_TO_STR(USER_BUTTON_RIGHT),
    ENUM_TO_STR(USER_BUTTON_MAX),
};
*/
static flex_button_t user_button[USER_BUTTON_MAX];

static uint8_t button_up_read(void* arg) {return key_scan().up;}
static uint8_t button_down_read(void* arg) {return key_scan().down;}
static uint8_t button_left_read(void* arg) {return key_scan().left;}
static uint8_t button_right_read(void* arg) {return key_scan().right;}


void user_button_init(void)
{
    int i;
    
    memset(&user_button[0], 0x0, sizeof(user_button));

    user_button[USER_BUTTON_UP].usr_button_read = button_up_read; //按键读取回调函数
    user_button[USER_BUTTON_UP].cb = (flex_button_response_callback)btn_up_cb; //按键事件回调函数

    user_button[USER_BUTTON_DOWN].usr_button_read = button_down_read; //按键读取回调函数
    user_button[USER_BUTTON_DOWN].cb = (flex_button_response_callback)btn_down_cb; //按键事件回调函数

    user_button[USER_BUTTON_LEFT].usr_button_read = button_left_read; //按键读取回调函数
    user_button[USER_BUTTON_LEFT].cb = (flex_button_response_callback)btn_left_cb; //按键事件回调函数

    user_button[USER_BUTTON_RIGHT].usr_button_read = button_right_read; //按键读取回调函数
    user_button[USER_BUTTON_RIGHT].cb = (flex_button_response_callback)btn_right_cb; //按键事件回调函数



    for (i = 0; i < USER_BUTTON_MAX; i ++)
    {
        user_button[i].id = i;
        user_button[i].pressed_logic_level = 0;
        user_button[i].short_press_start_tick = FLEX_MS_TO_SCAN_CNT(500);
        user_button[i].long_press_start_tick = FLEX_MS_TO_SCAN_CNT(1500);
        user_button[i].long_hold_start_tick = FLEX_MS_TO_SCAN_CNT(3000);

        flex_button_register(&user_button[i]);
    }
}

#ifdef FINSH_USING_MSH
INIT_APP_EXPORT(flex_button_main);
#endif
