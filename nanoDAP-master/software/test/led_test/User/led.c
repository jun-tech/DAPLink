#include "stm32f10x.h"
#include "led.h"

void LED_Init(void)
{	
	
		//2.配置结构体	
	GPIO_InitTypeDef led_init;
	//1.打开控制GPIOC的时钟(APB2)
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	

	led_init.GPIO_Pin   = GPIO_Pin_13;      //GPIOC13引脚
	led_init.GPIO_Mode  = GPIO_Mode_Out_PP; //推挽输出	
	led_init.GPIO_Speed = GPIO_Speed_10MHz; //10MHz
	
	//3.对成员进行初始化
	GPIO_Init(GPIOC, &led_init);
}

