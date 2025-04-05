#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void)
{
	// 光敏 1是遮光     蜂鸣器低电平响应
	//蜂鸣器初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef feng;
	feng.GPIO_Mode=GPIO_Mode_Out_PP;
	feng.GPIO_Pin=GPIO_Pin_7;
	feng.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&feng);
	
	//光敏初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef guang;
	guang.GPIO_Mode=GPIO_Mode_IPD;
	guang.GPIO_Pin=GPIO_Pin_1;
	guang.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&guang);
	
	
	
	
	
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)==1)
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_7);
		}
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)==0)
		{
			GPIO_SetBits(GPIOA,GPIO_Pin_7);
		}
	}
}
	
