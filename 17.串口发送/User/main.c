#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

int main(void)
{
	OLED_Init();
	SerialInit();
	
	
	Serial_SendByte(0x41);				//串口发送一个字节数据0x41
	
	//uint8_t MyArray[] = {0x42, 0x43, 0x44, 0x45};	//定义数组
	//Serial_SendArray(MyArray, 4);		//串口发送一个数组
	
	//Serial_SendString("\r\nNum1=");		//串口发送字符串
	
	//Serial_SendNumber(111, 3);			//串口发送数字
	while(1)
	{
		
	}
}
	
