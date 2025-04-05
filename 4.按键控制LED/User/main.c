#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	//按键GPIO的初始化
	GPIO_InitTypeDef anjian;
	anjian.GPIO_Mode=GPIO_Mode_IPU;
	anjian.GPIO_Pin=GPIO_Pin_1;
	anjian.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &anjian);
	
	//Led初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef led;
	led.GPIO_Mode=GPIO_Mode_Out_PP;
	led.GPIO_Pin=GPIO_Pin_6;
	led.GPIO_Speed=GPIO_Speed_50MHz;
	
    GPIO_Init(GPIOA, &led);
	
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0)
		{
			Delay_ms(20);
			while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0);
			Delay_ms(20);
			
			
			GPIO_SetBits(GPIOA, GPIO_Pin_6);
		}
		
	}
}
	
