
//该模块用于调整舵机的反应速度与方向

#include "zf_common_headfile.h"

//函数作用：初始化servo_control舵机模块的PWM
//使用示例：Servo_PWM_Init()
void Servo_PWM_Init(void)
{
	pwm_init(SERVO_PWM, SERVO_FREQ, 0);
}

//函数作用：用舵机控制车辆左右转，0左1右。若要使舵机正向.
//使用示例：Turn_Angle(30,0)左转度
void Turn_Angle(float angle)
{
	angle += ADJ_ERROR;
	pwm_set_duty(SERVO_PWM, (uint32)SERVO_DUTY(angle));
}


