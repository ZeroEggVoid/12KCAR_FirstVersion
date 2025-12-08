#ifndef _MOTOR_H
#define _MOTOR_H

#define MAX_DUTY            (50 )                                               // 最大 MAX_DUTY% 占空比
#define DIR_L               (IO_P64 )                                           // 左电机接口
#define PWM_L               (PWMA_CH4P_P66)                                     // 左电机pwm波接口

#define DIR_R               (IO_P60 )                                           // 右电机接口
#define PWM_R               (PWMA_CH2P_P62)                                     // 右电机pwm波

void Motor_PWM_Init(void);
void Motor_Out(int8 left_duty,int8 right_duty);

#endif