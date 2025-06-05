#include "mid_uart.h"

volatile unsigned char data;
UART_DATA_STRUCT uart_data;

static int uart_limit_length(void)
{
	if(uart_data.receive_data_length >= RECEIVE_DATA_MAX)
	{
		//超限直接清空，报错
		uart_data.receive_data_length = 0;
		return 0;
	}
	return 1;
}

//发送单个字符
void uart0_send_char(char ch)
{
	//等待串口不忙
    while( DL_UART_isBusy(UART_0_INST) == true );
    //发送数据
    DL_UART_Main_transmitData(UART_0_INST, ch);
}

//发送字符串
void uart0_send_string(char* str)
{
    while(*str!=0&&str!=0)
    {
        uart0_send_char(*str++);
    }
}

//开启中断
void uart0_init(void)
{
	NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
	NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
}

//返回接收数据
UART_DATA_STRUCT get_uart_receive_data(void)
{
	return uart_data;
}

void uart_clear_data(void)
{
	//数组清零
	uart_data.receive_data_length = 0;
}

void UART0_IRQHandler(void)
{
	switch( DL_UART_getPendingInterrupt(UART_0_INST))
	{
		case DL_UART_IIDX_RX: //接收中断
			//data = DL_UART_Main_receiveData(UART_0_INST);
			//uart0_send_char(data);
			uart_data.receive_buffer[uart_data.receive_data_length++] = DL_UART_Main_receiveData(UART_0_INST); 
			uart_limit_length();
			//uart0_send_string(uart_data.receive_buffer);
			for(int i = 0 ;i<uart_data.receive_data_length;i++)
			{
				uart0_send_char(uart_data.receive_buffer[i]);
			}
		break;
		default:
			break;
	}
}