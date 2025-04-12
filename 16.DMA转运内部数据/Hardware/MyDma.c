#include "stm32f10x.h"                  // Device header

uint16_t DmaSize;

void DmaInit(uint32_t AddA, uint32_t AddB, uint16_t size)
{
	
	DmaSize=size;
	
	//开启时钟
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	//DMA初始化
	DMA_InitTypeDef DMAStu;
	DMAStu.DMA_BufferSize=size;
	DMAStu.DMA_DIR=DMA_DIR_PeripheralSRC;
	DMAStu.DMA_M2M=DMA_M2M_Enable;
	DMAStu.DMA_MemoryBaseAddr=AddB;
	DMAStu.DMA_MemoryDataSize=DMA_MemoryDataSize_Byte;
	DMAStu.DMA_MemoryInc=DMA_MemoryInc_Enable;
	DMAStu.DMA_Mode=DMA_Mode_Normal;
	DMAStu.DMA_PeripheralBaseAddr=AddA;
	DMAStu.DMA_PeripheralDataSize=DMA_PeripheralDataSize_Byte;
	DMAStu.DMA_PeripheralInc=DMA_PeripheralInc_Enable;
	DMAStu.DMA_Priority=DMA_Priority_Medium;
	DMA_Init(DMA1_Channel1, &DMAStu);
	
	//DMA使能
	DMA_Cmd(DMA1_Channel1,ENABLE);
}


void DmaTran()
{
	DMA_Cmd(DMA1_Channel1,DISABLE);//先失能  再写入计数器
	DMA_SetCurrDataCounter(DMA1_Channel1,DmaSize); 
	DMA_Cmd(DMA1_Channel1,ENABLE);//使能 开始转运
	
	while(DMA_GetFlagStatus(DMA1_FLAG_TC1)==RESET);
	DMA_ClearFlag(DMA1_FLAG_TC1);
		
}






