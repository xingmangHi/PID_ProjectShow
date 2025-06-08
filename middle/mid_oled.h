
#ifndef __OLED_H
#define __OLED_H			  	 

#include "ti_msp_dl_config.h"
#include "stdlib.h"	    	


#define OLED_MODE 0
#define SIZE 16
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	    						  
//-----------------OLED�˿ڶ���----------------  					   
#define OLED_SCL_Clr() DL_GPIO_clearPins(OLED_B_PORT,OLED_B_SPI_SCK_PIN)//SCL
#define OLED_SCL_Set() DL_GPIO_setPins(OLED_B_PORT,OLED_B_SPI_SCK_PIN)

#define OLED_SDA_Clr() DL_GPIO_clearPins(OLED_A_PORT,OLED_A_SPI_PICO_PIN)//SDA
#define OLED_SDA_Set() DL_GPIO_setPins(OLED_A_PORT,OLED_A_SPI_PICO_PIN)

#define OLED_RES_Clr() DL_GPIO_clearPins(OLED_B_PORT,OLED_B_SPI_PIN1_PIN)//RES
#define OLED_RES_Set() DL_GPIO_setPins(OLED_B_PORT,OLED_B_SPI_PIN1_PIN)

#define OLED_DC_Clr() DL_GPIO_clearPins(OLED_B_PORT,OLED_B_SPI_PIN2_PIN)//DC
#define OLED_DC_Set() DL_GPIO_setPins(OLED_B_PORT,OLED_B_SPI_PIN2_PIN)

#define OLED_CS_Clr() DL_GPIO_clearPins(OLED_A_PORT,OLED_A_SPI_PICO_PIN)//CS
#define OLED_CS_Set() DL_GPIO_setPins(OLED_A_PORT,OLED_A_SPI_PICO_PIN)

 		     
#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����


#ifndef u8
#define u8 unsigned char
#endif

#ifndef u16
#define u16 unsigned int 
#endif

#ifndef u32
#define u32 unsigned long
#endif



void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
void OLED_WR_Byte(u8 dat,u8 mode);
void OLED_DisPlay_On(void);
void OLED_DisPlay_Off(void);
void OLED_Refresh(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_DrawLine(u8 x1,u8 y1,u8 x2,u8 y2,u8 mode);
void OLED_DrawCircle(u8 x,u8 y,u8 r);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size1,u8 mode);
void OLED_ShowChar6x8(u8 x,u8 y,u8 chr,u8 mode);
void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 size1,u8 mode);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size1,u8 mode);
void OLED_ShowChinese(u8 x,u8 y,u8 num,u8 size1,u8 mode);
void OLED_ScrollDisplay(u8 num,u8 space,u8 mode);
void OLED_ShowPicture(u8 x,u8 y,u8 sizex,u8 sizey,u8 BMP[],u8 mode);
void OLED_Init(void);

#endif  
	 



