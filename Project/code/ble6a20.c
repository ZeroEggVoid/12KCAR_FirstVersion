
#include "zf_common_headfile.h"


uint8 data_buffer[32];
uint8 data_read[32];
uint8 data_len;
		
void Fault_Detect(void)
{
	gpio_init(IO_P52, GPO, GPIO_HIGH, GPO_PUSH_PULL);                             // 初始化 LED1 输出 默认高电平 推挽输出模式
    while(ble6a20_init())                                                       // 判断是否通过初始化
    {
        gpio_toggle_level(IO_P52);                                                // 翻转 LED 引脚输出电平 控制 LED 亮灭
        system_delay_ms(100);                                                   // 短延时快速闪灯表示异常
    }
    ble6a20_send_byte('\r');
    ble6a20_send_byte('\n');
    ble6a20_send_string("JUST DO IT.\r\n");                    // 初始化正常 输出测试信息
}


void Parm_Fb(void)
{
	ble6a20_send_string("JUST DO IT.\r\n");

}

