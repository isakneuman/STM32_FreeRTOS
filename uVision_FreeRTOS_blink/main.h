#ifndef _MAIN
#define _MAIN

#include "FreeRTOS.h"
#include "stm32f10x.h"
#include "task.h"

void init_led_PC13(void);
void blink(void *pvParameters);
int main(void);
void create_Task(void);
#endif
