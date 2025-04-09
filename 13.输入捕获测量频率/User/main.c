#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Pwm.h"
#include "Ic.h"

uint8_t i;
	
int main(void)
{
	
	OLED_Init();
	PwmInit();
	IcInit();
	
	SetPsc(720-1);
	SetCCR(50);
	
	while(1)
	{
	
		
		OLED_ShowNum(1,6,GetFreq(),5);
	}
}
	
