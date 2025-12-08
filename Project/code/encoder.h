#ifndef _ENCODER_H
#define _ENCODER_H

#define ENCODER_L                 	(TIM0_ENCOEDER)                         // 正交编码器对应使用的编码器接口 这里使用QTIMER1的ENCOEDER1
#define ENCODER_DIR_L              	(IO_P35)            				 	// 设置左侧方向引脚
#define ENCODER_PULSE_L            	(TIM0_ENCOEDER_P34)            			// 设置左侧脉冲引脚

#define ENCODER_R                 	(TIM3_ENCOEDER)                         // 带方向编码器对应使用的编码器接口 这里使用QTIMER1的ENCOEDER2
#define ENCODER_DIR_R           	(IO_P53)             					// 设置右侧方向引脚
#define ENCODER_PULSE_R       		(TIM3_ENCOEDER_P04)            			// 设置右侧脉冲引脚

void Encoder_Init(void);
float Encoder_Left_Get(void);
float Encoder_Right_Get(void);

#endif