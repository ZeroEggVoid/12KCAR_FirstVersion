#ifndef _POSTURE_SENSOR_H
#define _POSTURE_SENSOR_H

#include "zf_device_icm20602.h"

#define POSTURE_SENSOR_ICM20602
#define POSTURE_SENSOR_ICM20602_TRANSITION_FACTOR_ACC    16384.0f    // 加速度计转换系数(2g档位)
#define POSTURE_SENSOR_ICM20602_TRANSITION_FACTOR_GYRO   16.4f       // 陀螺仪转换系数(2000dps档位)
#define POSTURE_SENSOR_ICM20602_USE_INTERFACE        SOFT_SPI    // 使用的软件 SPI 接口
#define POSTURE_SENSOR_ICM20602_SPI_SCK_PIN      (P40)       // 软件 SPI SCK 引脚
#define POSTURE_SENSOR_ICM20602_SPI_MOSI_PIN     (P41)       // 软件 SPI MOSI 引脚
#define POSTURE_SENSOR_ICM20602_SPI_MISO_PIN     (P42)       // 软件 SPI MISO 引脚
#define POSTURE_SENSOR_ICM20602_SPI_CS_PIN       (P43)       // 软件 SPI CS 引脚
#define POSTURE_SENSOR_ICM20602_SOFT_IIC_DELAY      (0)         // 软件 IIC 的时钟延时周期 数值越小 IIC 通信速率越快
#define POSTURE_SENSOR_ICM20602_IIC_SCL_PIN     (IO_P40)    // 软件 IIC SCL 引脚
#define POSTURE_SENSOR_ICM20602_IIC_SDA_PIN     (IO_P41)    // 软件 IIC SDA 引脚
#define POSTURE_SENSOR_ICM20602_ACC_SAMPLE_DEFAULT     ( ICM20602_ACC_SAMPLE_SGN_8G )          // 在这设置默认的 加速度计 初始化量程
#define POSTURE_SENSOR_ICM20602_GYRO_SAMPLE_DEFAULT    ( ICM20602_GYRO_SAMPLE_SGN_2000DPS )    // 在这设置默认的 陀螺仪   初始化量程
#define POSTURE_SENSOR_ICM20602_TIMEOUT_COUNT      ( 0x00FF )                                  // ICM20602 超时计数
#define posture_sensor_icm20602_acc_transition(acc_value)      ((float)(acc_value) / POSTURE_SENSOR_ICM20602_TRANSITION_FACTOR_ACC)
#define posture_sensor_icm20602_gyro_transition(gyro_value)    ((float)(gyro_value) / POSTURE_SENSOR_ICM20602_TRANSITION_FACTOR_GYRO)
#define POSTURE_SENSOR_ICM20602_SPI_SPEED          ((uint32)10 * 1000 * 1000U)      // 硬件 SPI 速率 
#define POSTURE_SENSOR_ICM20602_SPI                SPI_0                            // 硬件 SPI 号  
#define POSTURE_SENSOR_ICM20602_SPI_SPC_PIN            SPI0_CH3_SCLK_P43                // 硬件 SPI SCK 引脚
#define POSTURE_SENSOR_ICM20602_SPI_SDI_PIN            SPI0_CH3_MOSI_P40                // 硬件 SPI MOSI 引脚
#define POSTURE_SENSOR_ICM20602_SPI_SDO_PIN            SPI0_CH3_MISO_P41                // 硬件 SPI MISO 引脚
#define POSTURE_SENSOR_ICM20602_CS_PIN             (IO_P42)                         // CS 片选引脚
#define POSTURE_SENSOR_ICM20602_CS(x)              ((x) ? (gpio_high(POSTURE_SENSOR_ICM20602_CS_PIN)): (gpio_low(POSTURE_SENSOR_ICM20602_CS_PIN)))

void posture_sensor_init(void);
void posture_sensor_get_data(void);
float posture_sensor_get_acc_x(void);
float posture_sensor_get_acc_y(void);
float posture_sensor_get_acc_z(void);
float posture_sensor_get_gyro_x(void);
float posture_sensor_get_gyro_y(void);
float posture_sensor_get_gyro_z(void);

#endif