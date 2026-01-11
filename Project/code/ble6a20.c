
#include "zf_common_headfile.h"

uint8 data_buffer[32];
uint8 data_read[32];
uint8 data_len;

void Fault_Detect(void)
{
    gpio_init(IO_P52, GPO, GPIO_HIGH, GPO_PUSH_PULL); // ��ʼ�� LED1 ��� Ĭ�ϸߵ�ƽ �������ģʽ
    while (ble6a20_init())                            // �ж��Ƿ�ͨ����ʼ��
    {
        gpio_toggle_level(IO_P52); // ��ת LED ���������ƽ ���� LED ����
        system_delay_ms(100);      // ����ʱ�������Ʊ�ʾ�쳣
    }
    ble6a20_send_byte('\r');
    ble6a20_send_byte('\n');
    ble6a20_send_string("JUST DO IT.\r\n"); // ��ʼ������ ���������Ϣ
}

void Parm_Fb(void)
{
    ble6a20_send_string("JUST DO IT.\r\n");
}
