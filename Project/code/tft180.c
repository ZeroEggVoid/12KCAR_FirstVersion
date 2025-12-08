#include "zf_common_headfile.h"

void LCD_Init(void)
{
	tft180_init();
	tft180_clear(RGB565_WHITE);										//清屏
}

void LCD_Disp(void)
{
	tft180_show_string (0,16*0,"Encoder_Left:");                   
	tft180_show_int16 (0,16*1,Encoder_Left_Get());                  //显示左编码器转速
	tft180_show_string (0,16*2,"Encoder_Right:");
	tft180_show_int16 (0,16*3,Encoder_Right_Get());                 //显示右编码器转速

}