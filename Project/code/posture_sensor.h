#ifndef _POSTURE_SENSOR_H
#define _POSTURE_SENSOR_H

void posture_sensor_init(void);
void posture_sensor_get_data(void);
float posture_sensor_get_acc_x(void);
float posture_sensor_get_acc_y(void);
float posture_sensor_get_acc_z(void);
float posture_sensor_get_gyro_x(void);
float posture_sensor_get_gyro_y(void);
float posture_sensor_get_gyro_z(void);

#endif