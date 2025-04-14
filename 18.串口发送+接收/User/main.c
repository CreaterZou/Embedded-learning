#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

uint8_t RxData;	

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
		if (Serial_GetRxFlag() == 1)			//检查串口接收数据的标志位
		{
			RxData = Serial_GetRxData();		//获取串口接收的数据
			Serial_SendByte(RxData);			//串口将收到的数据回传回去，用于测试
			OLED_ShowHexNum(1, 8, RxData, 2);	//显示串口接收的数据
		}
	}
}
	
