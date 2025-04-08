#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Pwm.h"

uint8_t i;
	
int main(void)
{
	
	OLED_Init();
	PwmInit();
	
	while(1)
	{
		for(i=0;i<=100;i++)
		{
			SetCCR(i);
			Delay_ms(10);
		}
		for(i=0;i<=100;i++)
		{
			SetCCR(100-i);
			Delay_ms(10);
		}
		
	}
}
	
