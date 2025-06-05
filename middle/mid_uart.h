#ifndef _MID_UART_H_
#define _MID_UART_H_

#include "ti_msp_dl_config.h"

#define RECEIVE_DATA_MAX 127
typedef struct
{
	char receive_buffer[RECEIVE_DATA_MAX];
	int receive_data_length;
}UART_DATA_STRUCT;

void uart0_init();
void uart0_send_char(char ch);
void uart0_send_string(char* str);
void uart_clear_data(void);

#endif