#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Pwm.h"
#include "motor.h"

uint8_t i;
	
int main(void)
{
	
	OLED_Init();
	motorInit();
	
	while(1)
	{
		motorSetSpeed(-50);
	}
}
	
