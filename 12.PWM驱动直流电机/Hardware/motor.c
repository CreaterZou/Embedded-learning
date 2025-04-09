#include "stm32f10x.h"                  // Device header
#include "Pwm.h"

void motorInit()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef motorStu;
	motorStu.GPIO_Mode=GPIO_Mode_Out_PP;
	motorStu.GPIO_Pin=GPIO_Pin_4 | GPIO_Pin_5;
	motorStu.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&motorStu);
	
	PwmInit();
}

//速度设置函数
void motorSetSpeed(int8_t	speed)
{
	if(speed>=0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_4);
		GPIO_ResetBits(GPIOA,GPIO_Pin_5);
		SetCCR(speed);
	}
	else
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);
		GPIO_SetBits(GPIOA,GPIO_Pin_5);
		SetCCR(-speed);
	}
}



