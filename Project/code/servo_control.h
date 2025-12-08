#ifndef _SERVO_CONTROL_H
#define _SERVO_CONTROL_H

#define SERVO_PWM               (PWMB_CH1_P74)                         // 定义主板上舵机对应引脚
#define SERVO_FREQ              (100 )                                           // 定义主板上舵机频率  请务必注意范围 50-300

#define SERVO_L_MAX             (80 )                                           // 定义主板上舵机活动范围 角度
#define SERVO_R_MAX             (100)                                           // 定义主板上舵机活动范围 角度

// ------------------ 舵机占空比计算方式 ------------------
#define SERVO_DUTY(x)         ((float)PWM_DUTY_MAX / (1000.0 / (float)SERVO_FREQ) * (0.5 + (float)(x) / 90.0))
//PWM_DUTY_MAX / (1000.0 / SERVO_FREQ)表示将pwm占空比平均分配到一个周期的每一毫秒
//(0.5 + (x) / 90.0)表示角度对应的毫秒值

#define ADJ_ERROR                (0 )					                      //不要轻易更改，此为这辆车的正向校准参数

#if ((SERVO_FREQ < 50) || (SERVO_FREQ > 300))
    #error "SERVO_MOTOR_FREQ ERROE!"
#endif

void Servo_PWM_Init(void);
void Turn_Angle(float angle);


#endif