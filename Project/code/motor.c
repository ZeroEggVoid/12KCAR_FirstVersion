
#include "zf_common_headfile.h"

//函数作用：初始化电机
//使用示例：Motor_PWM_Init();
void Motor_PWM_Init(void)
{
	gpio_init(DIR_L, GPO, GPIO_HIGH, GPO_PUSH_PULL);                            // GPIO 初始化为输出 默认上拉输出高
    pwm_init(PWM_L, 17000, 0);                                                  // PWM 通道初始化频率 17KHz 占空比初始为 0

    gpio_init(DIR_R, GPO, GPIO_HIGH, GPO_PUSH_PULL);                            // GPIO 初始化为输出 默认上拉输出高
    pwm_init(PWM_R, 17000, 0);                                                  // PWM 通道初始化频率 17KHz 占空比初始为 0                                  
}

//函数作用：调整左右电机占空比/转速
//使用示例：Motor_Out(30，30); 
//PS：该函数有限幅(极值设定)，如果想提速到头文件调整。
void Motor_Out(int8 left_duty,int8 right_duty)
{
    if(left_duty >= 0)                                                           // 左侧正转
    {
		left_duty = left_duty >= MAX_DUTY ? MAX_DUTY: left_duty;				 // 限幅
        gpio_set_level(DIR_L, GPIO_HIGH);                                        // DIR输出高电平
        pwm_set_duty(PWM_L, left_duty * (PWM_DUTY_MAX / 100));                   // 计算占空比                                
    }
	else                                                                         // 左侧反转
    {
	    left_duty = (-left_duty) >= MAX_DUTY ? MAX_DUTY: (-left_duty);
        gpio_set_level(DIR_L, GPIO_LOW);                                         // DIR输出低电平
        pwm_set_duty(PWM_L, left_duty * (PWM_DUTY_MAX / 100));                   // 计算占空比
	}
	if(right_duty >= 0) 
	{
		right_duty = right_duty >= MAX_DUTY ? MAX_DUTY: right_duty;
        gpio_set_level(DIR_R, GPIO_HIGH);                                         // DIR输出高电平
        pwm_set_duty(PWM_R, right_duty * (PWM_DUTY_MAX / 100));                   // 计算占空比
	}		
	else
	{
		right_duty = (-right_duty) >= MAX_DUTY ? MAX_DUTY: (-right_duty);
        gpio_set_level(DIR_R, GPIO_LOW);                                          // DIR输出低电平
        pwm_set_duty(PWM_R, right_duty * (PWM_DUTY_MAX / 100)); 				  // 计算占空比
    }
}







