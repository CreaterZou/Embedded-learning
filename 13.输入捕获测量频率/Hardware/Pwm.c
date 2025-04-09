#include "stm32f10x.h"                  // Device header

void PwmInit()
{
	//定时器和GPIO时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	//GPIO初始化
	GPIO_InitTypeDef PwmGpio;
	PwmGpio.GPIO_Mode=GPIO_Mode_AF_PP;
	PwmGpio.GPIO_Pin=GPIO_Pin_0;
	PwmGpio.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &PwmGpio);
	
	//配置时钟源
	TIM_InternalClockConfig(TIM2);
	
	
	//时基单元初始化
	TIM_TimeBaseInitTypeDef TimerStu;
	TimerStu.TIM_ClockDivision=TIM_CKD_DIV1;
	TimerStu.TIM_CounterMode=TIM_CounterMode_Up;
	TimerStu.TIM_Period=100-1;
	TimerStu.TIM_Prescaler=720-1;
	TimerStu.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2, &TimerStu);
	
	
	//输出比较初始化
	TIM_OCInitTypeDef TimerOCStu;
	TIM_OCStructInit(&TimerOCStu);
	
	TimerOCStu.TIM_OCMode=TIM_OCMode_PWM1;
	TimerOCStu.TIM_OutputState=TIM_OutputState_Enable;
	TimerOCStu.TIM_Pulse=0;
	TimerOCStu.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OC1Init(TIM2, &TimerOCStu);
	//Tim使能
	TIM_Cmd(TIM2, ENABLE);
	
	
}

//设置CCR的值  从而确定占空比

void SetCCR(uint16_t tempccr)
{
	TIM_SetCompare1(TIM2, tempccr);
}

//单独设置预分频器的值

void SetPsc(uint16_t PscTemp)
{
	TIM_PrescalerConfig(TIM2, PscTemp,TIM_PSCReloadMode_Immediate);
}



