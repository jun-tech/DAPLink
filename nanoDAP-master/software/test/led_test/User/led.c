#include "stm32f10x.h"
#include "led.h"

void LED_Init(void)
{	
	
		//2.���ýṹ��	
	GPIO_InitTypeDef led_init;
	//1.�򿪿���GPIOC��ʱ��(APB2)
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	

	led_init.GPIO_Pin   = GPIO_Pin_13;      //GPIOC13����
	led_init.GPIO_Mode  = GPIO_Mode_Out_PP; //�������	
	led_init.GPIO_Speed = GPIO_Speed_10MHz; //10MHz
	
	//3.�Գ�Ա���г�ʼ��
	GPIO_Init(GPIOC, &led_init);
}

