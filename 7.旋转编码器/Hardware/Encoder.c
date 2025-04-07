#include "stm32f10x.h"                  // Device header

//旋转编码器增量
int16_t EnCount;

void EncoderInit()
{
	//开启时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	//GPIO初始化
	GPIO_InitTypeDef EncoderStu;
	EncoderStu.GPIO_Mode=GPIO_Mode_IPU;
	EncoderStu.GPIO_Pin=GPIO_Pin_0 | GPIO_Pin_1;
	EncoderStu.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB , &EncoderStu);
	
	//AFIO选择中断引脚
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource0);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource1);

	//EXTI配置
	EXTI_InitTypeDef EnExti;
	EnExti.EXTI_Line=EXTI_Line0;
	EnExti.EXTI_LineCmd=ENABLE;
	EnExti.EXTI_Mode=EXTI_Mode_Interrupt;
	EnExti.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EnExti);
	
	EXTI_InitTypeDef EnExti1;
	EnExti1.EXTI_Line=EXTI_Line1;
	EnExti1.EXTI_LineCmd=ENABLE;
	EnExti1.EXTI_Mode=EXTI_Mode_Interrupt;
	EnExti1.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EnExti1);
	//NVIC分组  以及初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef EnNvic0;
	EnNvic0.NVIC_IRQChannel=EXTI0_IRQn;
	EnNvic0.NVIC_IRQChannelCmd=ENABLE;
	EnNvic0.NVIC_IRQChannelPreemptionPriority=1;
	EnNvic0.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&EnNvic0);
	
	
    NVIC_InitTypeDef EnNvic1;
	EnNvic1.NVIC_IRQChannel=EXTI1_IRQn;
	EnNvic1.NVIC_IRQChannelCmd=ENABLE;
	EnNvic1.NVIC_IRQChannelPreemptionPriority=1;
	EnNvic1.NVIC_IRQChannelSubPriority=2;
	NVIC_Init(&EnNvic1);
}


//获取增量
uint16_t GetEnCount()
{
	int16_t temp;
	temp=EnCount;
	EnCount=0;
	return temp;
}



//两个中断函数
void EXTI0_IRQHandler()
{
	if(EXTI_GetITStatus(EXTI_Line0)==SET)
	{
		if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0)==0)
		{
			if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)==0)
			{
				EnCount--;//定义反转
			}
		}
		EXTI_ClearITPendingBit(EXTI_Line0);

	}
}

void EXTI1_IRQHandler()
{
	if(EXTI_GetITStatus(EXTI_Line1)==SET)
	{
		if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)==0)
		{
			if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0)==0)
			{
				EnCount++;
			}
		}
		EXTI_ClearITPendingBit(EXTI_Line1);

	}
}














