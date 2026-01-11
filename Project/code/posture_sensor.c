#include "zf_device_icm20602.h"

// 函数作用：姿态传感器初始化
// 使用示例: posture_sensor_init();
void posture_sensor_init(void)
{
    while(icm20602_init())
    {
        printf("posture sensor init error.\r\n");
        system_delay_ms(100);
    }
    printf("posture sensor init success.\r\n");
}

// 函数作用：获取姿态传感器数据
// 使用示例: posture_sensor_get_data();
void posture_sensor_get_data(void)
{
    icm20602_get_acc();
    icm20602_get_gyro();
}

// 函数作用：获取x轴上姿态传感器加速度数据，单位g(m/s^2)
// 使用示例: acc_x = posture_sensor_get_acc_x();
float posture_sensor_get_acc_x(void)
{
    return icm20602_acc_transition(icm20602_acc_x);
}

// 函数作用：获取y轴上姿态传感器加速度数据，单位g(m/s^2)
// 使用示例: acc_y = posture_sensor_get_acc_y();
float posture_sensor_get_acc_y(void)
{
    return icm20602_acc_transition(icm20602_acc_y);
}

// 函数作用：获取z轴上姿态传感器加速度数据，单位g(m/s^2)
// 使用示例: acc_z = posture_sensor_get_acc_z();
float posture_sensor_get_acc_z(void)
{
    return icm20602_acc_transition(icm20602_acc_z);
}

// 函数作用：获取x轴上姿态传感器陀螺仪数据，单位°/s
// 使用示例: gyro_x = posture_sensor_get_gyro_x();
float posture_sensor_get_gyro_x(void)
{
    return icm20602_gyro_transition(icm20602_gyro_x);
}

// 函数作用：获取y轴上姿态传感器陀螺仪数据，单位°/s
// 使用示例: gyro_y = posture_sensor_get_gyro_y();
float posture_sensor_get_gyro_y(void)
{
    return icm20602_gyro_transition(icm20602_gyro_y);
}

// 函数作用：获取z轴上姿态传感器陀螺仪数据，单位°/s
// 使用示例: gyro_z = posture_sensor_get_gyro_z();
float posture_sensor_get_gyro_z(void)
{
    return icm20602_gyro_transition(icm20602_gyro_z);
}