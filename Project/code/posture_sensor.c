#include "zf_common_headfile.h"

// �������ã���̬��������ʼ��
// ʹ��ʾ��: posture_sensor_init();
void posture_sensor_init(void)
{
    while (icm20602_init())
    {
        printf("posture sensor init error.\r\n");
        system_delay_ms(100);
    }
    printf("posture sensor init success.\r\n");
}

// �������ã���ȡ��̬����������
// ʹ��ʾ��: posture_sensor_get_data();
void posture_sensor_get_data(void)
{
    icm20602_get_acc();
    icm20602_get_gyro();
}

// �������ã���ȡx������̬���������ٶ����ݣ���λg(m/s^2)
// ʹ��ʾ��: acc_x = posture_sensor_get_acc_x();
float posture_sensor_get_acc_x(void)
{
    return icm20602_acc_transition(icm20602_acc_x);
}

// �������ã���ȡy������̬���������ٶ����ݣ���λg(m/s^2)
// ʹ��ʾ��: acc_y = posture_sensor_get_acc_y();
float posture_sensor_get_acc_y(void)
{
    return icm20602_acc_transition(icm20602_acc_y);
}

// �������ã���ȡz������̬���������ٶ����ݣ���λg(m/s^2)
// ʹ��ʾ��: acc_z = posture_sensor_get_acc_z();
float posture_sensor_get_acc_z(void)
{
    return icm20602_acc_transition(icm20602_acc_z);
}

// �������ã���ȡx������̬���������������ݣ���λ��/s
// ʹ��ʾ��: gyro_x = posture_sensor_get_gyro_x();
float posture_sensor_get_gyro_x(void)
{
    return icm20602_gyro_transition(icm20602_gyro_x);
}

// �������ã���ȡy������̬���������������ݣ���λ��/s
// ʹ��ʾ��: gyro_y = posture_sensor_get_gyro_y();
float posture_sensor_get_gyro_y(void)
{
    return icm20602_gyro_transition(icm20602_gyro_y);
}

// �������ã���ȡz������̬���������������ݣ���λ��/s
// ʹ��ʾ��: gyro_z = posture_sensor_get_gyro_z();
float posture_sensor_get_gyro_z(void)
{
    return icm20602_gyro_transition(icm20602_gyro_z);
}
