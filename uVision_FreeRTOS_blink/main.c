#include "main.h"

int main(void){
	
	init_led_PC13();
	create_Task();
}

void create_Task(void){
	xTaskCreate(blink,"blinker",configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);
	vTaskStartScheduler();
}

void init_led_PC13(void){
	RCC->APB2ENR	|=	RCC_APB2ENR_IOPCEN;
	
	// MODE: 10 output 2 MHz
	GPIOC->CRH		&=	~GPIO_CRH_MODE13_0;
	GPIOC->CRH		|=	GPIO_CRH_MODE13_1;
	
	// CNF: 00 output push pull
	GPIOC->CRH		&=	~GPIO_CRH_CNF13;
}

void blink(void *pvParameters){
	while(1){
		GPIOC->BSRR	=	GPIO_BSRR_BS13;
		vTaskDelay(500);
		GPIOC->BRR	=	GPIO_BRR_BR13;
		vTaskDelay(500);
	}
}
