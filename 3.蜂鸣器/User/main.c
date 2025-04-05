#include "stm32f10x.h"                  // Device header
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef FengS;
	FengS.GPIO_Mode=GPIO_Mode_Out_PP;
	FengS.GPIO_Pin=GPIO_Pin_1;
	FengS.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&FengS);
	
	while(1)
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_1);
		
	}
}
	
