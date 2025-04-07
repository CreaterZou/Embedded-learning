#include "stm32f10x.h"                  // Device header

 void TimerInit()
 {
	 //开启时钟
	 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	 
	 //时钟源选择
	 TIM_InternalClockConfig(TIM2);
	 
	 //时基单元初始化
	 TIM_TimeBaseInitTypeDef TimerStu;
	 TimerStu.TIM_ClockDivision=TIM_CKD_DIV1;
	 TimerStu.TIM_CounterMode=TIM_CounterMode_Up;
	 TimerStu.TIM_Period=10000-1;
	 TimerStu.TIM_Prescaler=7200-1;
	 TimerStu.TIM_RepetitionCounter=0;
	 TIM_TimeBaseInit(TIM2, &TimerStu);
	 
	 //中断输出配置
	 
	 TIM_ClearFlag(TIM2, TIM_FLAG_Update);//先清除一下标志位 防止开始就进中断了
	 TIM_ITConfig(TIM2, TIM_IT_Update,ENABLE);
	 
	 //NVIC配置
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	 
	 NVIC_InitTypeDef TimerNvic;
	 TimerNvic.NVIC_IRQChannel=TIM2_IRQn;
	 TimerNvic.NVIC_IRQChannelCmd=ENABLE;
	 TimerNvic.NVIC_IRQChannelPreemptionPriority=2;
	 TimerNvic.NVIC_IRQChannelSubPriority=1;
	 NVIC_Init(&TimerNvic);
	 
	 //Timer使能
	 TIM_Cmd(TIM2, ENABLE);
 
 }
 
 
 //定时器中断函数
 //中断写到哪里都可以  写到main里面了
 
 
 
 
 
 