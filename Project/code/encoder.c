#include "zf_common_headfile.h"

// 函数作用：初始化编码器
// 使用示例: Encoder_Init();
void Encoder_Init(void)
{
    encoder_dir_init(ENCODER_L, ENCODER_DIR_L, ENCODER_PULSE_L);   	// 初始化编码器模块与引脚 带方向增量编码器模式
    encoder_dir_init(ENCODER_R, ENCODER_DIR_R, ENCODER_PULSE_R);    // 初始化编码器模块与引脚 带方向增量编码器模式
}

// 函数作用：获取左侧电机编码器转速
// 使用示例: Encoder_left = Encoder_Left_Get();
float Encoder_Left_Get(void)
{
	static int temp0 = 0,temp1 = 0,temp2 = 0;	       // 均值滤波
	temp1 = temp0;
	temp2 = temp1;
	if(ENCODER_DIR_L)
		temp0 = -encoder_get_count(ENCODER_L);                  // 获取编码器计数
	else
		temp0 = encoder_get_count(ENCODER_L);                  // 获取编码器计数
	temp0 = temp0*0.4 + temp1*0.3 + temp2*0.3;
	encoder_clear_count(ENCODER_L);                        // 清空编码器计数
	return temp0;                     		
}

// 函数作用：获取右侧电机编码器转速
// 使用示例: Encoder_Right = Encoder_Right_Get();
float Encoder_Right_Get(void)
{
	static int temp0 = 0,temp1 = 0,temp2 = 0;	       // 均值滤波
	temp1 = temp0;
	temp2 = temp1;
	if(ENCODER_DIR_R)
		temp0 = encoder_get_count(ENCODER_R);                  // 获取编码器计数
	else
		temp0 = -encoder_get_count(ENCODER_R);
	temp0 = temp0*0.4 + temp1*0.3 + temp2*0.3;
	encoder_clear_count(ENCODER_R);                        // 清空编码器计数
	return temp0;
}
     



