#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Encoder.h"


int16_t num;

int main(void)
{
	OLED_Init();
	EncoderInit();
	//静态字符串  不动的放在外面 节约性能
	OLED_ShowString(1,1,"num:");
	while(1)
	{
		num+=GetEnCount();
		OLED_ShowSignedNum(1,5,num,5);
	}
}
	
