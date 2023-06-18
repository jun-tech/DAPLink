#include "stm32f10x.h"
#include "delay.h"

void delay_ms(uint16_t time)
{
	uint16_t i = 0;
	while(time--)
	{
		i = 10000;
		while(i--);
	}
}


