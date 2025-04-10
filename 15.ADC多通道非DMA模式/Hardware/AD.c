#include "stm32f10x.h"                  // Device header

void AdInit()
{
	//开启时钟
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);

	//设置ADC时钟分频
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	//GPIO初始化
	GPIO_InitTypeDef GpioStu;
	GpioStu.GPIO_Mode=GPIO_Mode_AIN;
	GpioStu.GPIO_Pin=GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GpioStu.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GpioStu);
	//规则组通道引入
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);
	//ADC初始化
	ADC_InitTypeDef AdcStu;
	AdcStu.ADC_ContinuousConvMode=DISABLE;
	AdcStu.ADC_DataAlign=ADC_DataAlign_Right;
	AdcStu.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;
	AdcStu.ADC_Mode=ADC_Mode_Independent;
	AdcStu.ADC_NbrOfChannel=1;
	AdcStu.ADC_ScanConvMode=DISABLE;
	ADC_Init(ADC1, &AdcStu);
	//ADC使能
	 ADC_Cmd(ADC1, ENABLE);
	//ADC校准
	ADC_ResetCalibration(ADC1);
	while(ADC_GetResetCalibrationStatus(ADC1)==SET);
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1)==SET);
		
}


//获取ADC转换的值

uint16_t AdGetValue(uint8_t channel)
{
	ADC_RegularChannelConfig(ADC1, channel, 1, ADC_SampleTime_55Cycles5);
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC)==RESET);
	return ADC_GetConversionValue(ADC1);
}

