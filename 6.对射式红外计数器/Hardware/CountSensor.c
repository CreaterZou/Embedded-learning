#include "stm32f10x.h"                  // Device header

uint16_t count;//计数的全局变量

//返回数值函数
uint16_t GetCount()
{
	return count;
}

void CountSensorInit()
{
	//时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	//gpio初始化
	GPIO_InitTypeDef CsStr;
	CsStr.GPIO_Mode=GPIO_Mode_IPU;
	CsStr.GPIO_Pin=GPIO_Pin_14;
	CsStr.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &CsStr);
	//AFIO选择中断引脚
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);
	
	//EXTI配置
	EXTI_InitTypeDef CsExti;
	CsExti.EXTI_Line=EXTI_Line14;
	CsExti.EXTI_LineCmd=ENABLE;
	CsExti.EXTI_Mode=EXTI_Mode_Interrupt;
	CsExti.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&CsExti);
	
	//NVIC分组+初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	
	NVIC_InitTypeDef CsNvic;
	CsNvic.NVIC_IRQChannel=EXTI15_10_IRQn;
	CsNvic.NVIC_IRQChannelCmd=ENABLE;
	CsNvic.NVIC_IRQChannelPreemptionPriority=1;
	CsNvic.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&CsNvic);
	
}

//中断函数配置
void EXTI15_10_IRQHandler()
{
	if(EXTI_GetITStatus(EXTI_Line14)==SET)
	{
		if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14)==0)
		{
			count++;
		}
		 EXTI_ClearITPendingBit(EXTI_Line14);
		
	}
	
}

