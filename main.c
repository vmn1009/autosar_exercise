#include "stm32f10x.h"

void config(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitTypeDef LED;
	LED.GPIO_Mode = GPIO_Mode_Out_PP;
	LED.GPIO_Pin = GPIO_Pin_13;
	LED.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &LED);
	GPIO_Init(GPIOC, &LED);
}

void delay(void){
	uint32_t i;
	for(i = 0; i < 10000000; i++);
}
int count = 0;
int main(void){
	config();
	while(1){
	count++;
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		delay();
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
		delay();
	}
	
}