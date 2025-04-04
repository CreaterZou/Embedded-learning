#include "stm32f10x.h"                  // Device header
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//开启APB2的时钟
	
	//GPIO配置
	
	GPIO_InitTypeDef GPIOStruct;
	GPIOStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIOStruct.GPIO_Pin=GPIO_Pin_5;
	GPIOStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIOStruct);
	
	//写入高电平
	GPIO_SetBits(GPIOA, GPIO_Pin_5);
	//写入低电平
	//GPIO_ResetBits(GPIOA, GPIO_Pin_5);


	while(1)
	{
		
	}
}
	
