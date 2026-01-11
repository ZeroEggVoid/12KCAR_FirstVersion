// forth check
#include "zf_common_headfile.h"

float acc_x;
float gyro_x;
void main()
{
	clock_init(SYSTEM_CLOCK_30M);
	debug_init();
	Motor_PWM_Init();
	Servo_PWM_Init();
	Encoder_Init();
	LCD_Init();
	posture_sensor_init();

	while (1)
	{
		Motor_Out(10, 10);
		Turn_Angle(90);
		LCD_Disp();
		posture_sensor_get_data();
	}
}
