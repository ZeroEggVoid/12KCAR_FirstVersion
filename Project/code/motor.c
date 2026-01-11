
#include "zf_common_headfile.h"

// �������ã���ʼ�����
// ʹ��ʾ����Motor_PWM_Init();
void Motor_PWM_Init(void)
{
    gpio_init(DIR_L, GPO, GPIO_HIGH, GPO_PUSH_PULL); // GPIO ��ʼ��Ϊ��� Ĭ�����������
    pwm_init(PWM_L, 17000, 0);                       // PWM ͨ����ʼ��Ƶ�� 17KHz ռ�ձȳ�ʼΪ 0

    gpio_init(DIR_R, GPO, GPIO_HIGH, GPO_PUSH_PULL); // GPIO ��ʼ��Ϊ��� Ĭ�����������
    pwm_init(PWM_R, 17000, 0);                       // PWM ͨ����ʼ��Ƶ�� 17KHz ռ�ձȳ�ʼΪ 0
}

// �������ã��������ҵ��ռ�ձ�/ת��
// ʹ��ʾ����Motor_Out(30��30);
// PS���ú������޷�(��ֵ�趨)����������ٵ�ͷ�ļ�������
void Motor_Out(int8 left_duty, int8 right_duty)
{
    if (left_duty >= 0) // �����ת
    {
        left_duty = left_duty >= MAX_DUTY ? MAX_DUTY : left_duty; // �޷�
        gpio_set_level(DIR_L, GPIO_HIGH);                         // DIR����ߵ�ƽ
        pwm_set_duty(PWM_L, left_duty * (PWM_DUTY_MAX / 100));    // ����ռ�ձ�
    }
    else // ��෴ת
    {
        left_duty = (-left_duty) >= MAX_DUTY ? MAX_DUTY : (-left_duty);
        gpio_set_level(DIR_L, GPIO_LOW);                       // DIR����͵�ƽ
        pwm_set_duty(PWM_L, left_duty * (PWM_DUTY_MAX / 100)); // ����ռ�ձ�
    }
    if (right_duty >= 0)
    {
        right_duty = right_duty >= MAX_DUTY ? MAX_DUTY : right_duty;
        gpio_set_level(DIR_R, GPIO_HIGH);                       // DIR����ߵ�ƽ
        pwm_set_duty(PWM_R, right_duty * (PWM_DUTY_MAX / 100)); // ����ռ�ձ�
    }
    else
    {
        right_duty = (-right_duty) >= MAX_DUTY ? MAX_DUTY : (-right_duty);
        gpio_set_level(DIR_R, GPIO_LOW);                        // DIR����͵�ƽ
        pwm_set_duty(PWM_R, right_duty * (PWM_DUTY_MAX / 100)); // ����ռ�ձ�
    }
}
