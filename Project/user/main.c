// CheckAgain
#include "zf_common_headfile.h"

void main()
{
	clock_init(SYSTEM_CLOCK_30M);
	debug_init();
	Motor_PWM_Init();
	Servo_PWM_Init();
	Encoder_Init();
	LCD_Init();

	while (1)
	{
		Motor_Out(10, 10);
		Turn_Angle(90);
		LCD_Disp();
	}
}
