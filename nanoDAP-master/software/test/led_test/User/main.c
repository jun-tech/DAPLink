//#include "stm32f10x.h"

//void delay_ms(uint32_t count)
//{
//	uint32_t i, x;
//	for(; count != 0; count--) {
//		for(i = 1000; i != 0; i--) {
//			for(x = 72; x != 0; x--) {
//			}
//		}
//	}
//}

//void gpio_init()
//{
//		GPIO_InitTypeDef gpio;

//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//		gpio.GPIO_Pin = GPIO_Pin_All;	
//		gpio.GPIO_Mode = GPIO_Mode_Out_PP;   
//		gpio.GPIO_Speed = GPIO_Speed_50MHz; 
//		GPIO_Init(GPIOA, &gpio);

//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
//		gpio.GPIO_Pin = GPIO_Pin_All;	
//		gpio.GPIO_Mode = GPIO_Mode_Out_PP;   
//		gpio.GPIO_Speed = GPIO_Speed_50MHz; 
//		GPIO_Init(GPIOB, &gpio);

//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
//		gpio.GPIO_Pin = GPIO_Pin_All;	
//		gpio.GPIO_Mode = GPIO_Mode_Out_PP;   
//		gpio.GPIO_Speed = GPIO_Speed_50MHz; 
//		GPIO_Init(GPIOC, &gpio);
//}

//void gpio_on()
//{
//	GPIO_SetBits(GPIOA, GPIO_Pin_All);
//	GPIO_SetBits(GPIOB, GPIO_Pin_All);
//	GPIO_SetBits(GPIOC, GPIO_Pin_All);
//}

//void gpio_off()
//{
//	GPIO_ResetBits(GPIOA, GPIO_Pin_All);
//	GPIO_ResetBits(GPIOB, GPIO_Pin_All);
//	GPIO_ResetBits(GPIOC, GPIO_Pin_All);
//}

//const static char array[60 * 1024] = {1, 2, 3};

//int main(void)
//{	
//	int i = 0;
//	
//	gpio_init();
//	
//	while (1) {
//		gpio_on();
//		delay_ms(10);

//        
//		gpio_off();
//		delay_ms(10);
//		//delay_ms(array[(i++) % sizeof(array)]);
//		
//		
//	}

//	return 0;
//}



#include "stm32f10x.h"
#include "led.h"
#include "delay.h"

#include <stdio.h>  
  
#define ITM_Port8(n)    (*((volatile unsigned char *)(0xE0000000+4*n)))  
#define ITM_Port16(n)   (*((volatile unsigned short*)(0xE0000000+4*n)))  
#define ITM_Port32(n)   (*((volatile unsigned long *)(0xE0000000+4*n)))  
#define DEMCR           (*((volatile unsigned long *)(0xE000EDFC)))  
#define TRCENA          0x01000000  
  
  
//半主机模式必须定义这个  
struct __FILE  
{  
    int handle;  
};  
FILE __stdout;  
FILE __stdin;  
  
int fputc(int ch, FILE *f)  
{  
    if (DEMCR & TRCENA)  
    {  
        while (ITM_Port32(0) == 0);  
  
        ITM_Port8(0) = ch;  
    }  
    return(ch);  
}  

int  main()
{
	LED_Init(); //LED初始化
	
while(1)
	{
		GPIO_ResetBits(GPIOC, GPIO_Pin_13); 	//LED点亮
		delay_ms(300); //亮灯大约1秒
		GPIO_SetBits(GPIOC,GPIO_Pin_13);		//LED熄灭
		delay_ms(300); //熄灭灯大约1秒
		
		printf("Hello world！\r\n");
	}   
}


