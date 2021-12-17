/*
 * FreeRTOSLap1.c
 *
 * Created: 15/12/2021 04:43:04 م
 * Author : mohamed khaled
 * this simple program to protrizing atmega32 using free RTOS  
 */ 

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"  
#define  F_CPU 1000000UL 
#include "util/delay.h"    
#define  Task1Periority 2 
#define  Task2Periority 1 





// This function to initialize the system 
void InitFun (void) {
	DDRC = 0xFF ;  
	
}  

void LED1 (void *PTR1); 
void LED2 (void *PTR1); 


int main(void)
{ 
	InitFun();
    xTaskCreate(LED1,"led1",85, NULL , Task1Periority , NULL);	
	xTaskCreate(LED2,"led2",85, NULL , Task2Periority , NULL);
	
	vTaskStartScheduler(); 
	return 0;
     
}



void LED1 (void *PTR1){
	
	
	for (;;)
	{  
		PORTC = (1<<0); 
		_delay_ms(1000);  
		vTaskDelay(1000); 
		
	}
	
	
} 


void LED2 (void *PTR1){
	
	
	for (;;)
	{
		PORTC = (1<<1);
		//_delay_ms(1000);
		vTaskDelay(2000);
		
	}
	
	
}