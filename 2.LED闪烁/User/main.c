#include "stm32f10x.h"                  // Device header
#include "Delay.h"


int main(void)
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef asd;
	asd.GPIO_Mode=GPIO_Mode_Out_PP;
	asd.GPIO_Speed=GPIO_Speed_50MHz;
	asd.GPIO_Pin=GPIO_Pin_5;
	GPIO_Init(GPIOA,&asd);
	
	while(1)
	{
		
		GPIO_WriteBit(GPIOA, GPIO_Pin_5,Bit_SET);
		Delay_ms(500);
		GPIO_WriteBit(GPIOA, GPIO_Pin_5,Bit_RESET);
	    Delay_ms(500);

	}
}
	
