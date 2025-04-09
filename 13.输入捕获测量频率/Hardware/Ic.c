#include "stm32f10x.h"                  // Device header

void IcInit()
{
	//开启时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	//GPIO初始化
	GPIO_InitTypeDef GPIOStu;
	GPIOStu.GPIO_Mode=GPIO_Mode_IPU;
	GPIOStu.GPIO_Pin=GPIO_Pin_6;
	GPIOStu.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIOStu);
	
	//配置时钟源
	TIM_InternalClockConfig(TIM3);
	
	//时基单元初始化
	TIM_TimeBaseInitTypeDef tim3stu;
	tim3stu.TIM_ClockDivision=TIM_CKD_DIV1;
	tim3stu.TIM_CounterMode=TIM_CounterMode_Up;
	tim3stu.TIM_Period=65535-1;
	tim3stu.TIM_Prescaler=72-1;
	tim3stu.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM3, &tim3stu);
	
	//输入捕获初始化
	TIM_ICInitTypeDef Icstu;
	Icstu.TIM_Channel=TIM_Channel_1;
	Icstu.TIM_ICFilter=0xF;
	Icstu.TIM_ICPolarity=TIM_ICPolarity_Rising;
	Icstu.TIM_ICPrescaler=TIM_ICPSC_DIV1;
	Icstu.TIM_ICSelection=TIM_ICSelection_DirectTI;
	TIM_ICInit(TIM3, &Icstu);
	
	//触发源 从模式
	TIM_SelectInputTrigger(TIM3, TIM_TS_TI1FP1);
	TIM_SelectSlaveMode(TIM3,TIM_SlaveMode_Reset);
	
	TIM_Cmd(TIM3,ENABLE);
	

}

//获取输入捕获频率

uint32_t GetFreq()
{
	return 1000000/(TIM_GetCapture1(TIM3)+1);
}


