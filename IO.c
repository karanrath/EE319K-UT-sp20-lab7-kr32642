// IO.c
// This software configures the switch and LED
// You are allowed to use any switch and any LED, 
// although the Lab suggests the SW1 switch PF4 and Red LED PF1
// Runs on LM4F120 or TM4C123
// Program written by: put your names here
// Date Created: March 30, 2018
// Last Modified:  change this or look silly
// Lab number: 7


#include "../inc/tm4c123gh6pm.h"
#include <stdint.h>
extern void Delay1ms(uint32_t n);
//------------IO_Init------------
// Initialize GPIO Port for a switch and an LED
// Input: none
// Output: none
volatile uint32_t delay;
void IO_Init(void) {
 // --UUU-- Code to initialize PF4 and PF2
	
		SYSCTL_RCGCGPIO_R |= 0x20; 
		delay = 150;
		GPIO_PORTF_DIR_R |= 0x04;
		//GPIO_PORTF_DIR_R &= ~(0x10);
		GPIO_PORTF_DEN_R |= 0x14;
		GPIO_PORTF_PUR_R |= 0x10;
}

//------------IO_HeartBeat------------
// Toggle the output state of the  LED.
// Input: none
// Output: none

void IO_HeartBeat(void) {
		 uint32_t i=0; // --UUU-- PF2 is heartbeat
		if(i!=500000){
		i++;
		}
		else{
			 GPIO_PORTF_DATA_R ^= 0x04;
		i=0;
		}
}


//------------IO_Touch------------
// wait for release and press of the switch
// Delay to debounce the switch
// Input: none
// Output: none
//uint32_t count;
void IO_Touch(void) {
 // --UUU-- wait for release; delay for 20ms; and then wait for press
	uint32_t PF4;
	if((PF4=GPIO_PORTF_DATA_R & 0x10)== 0x10){
	while(PF4==0x10){
			PF4= GPIO_PORTF_DATA_R & 0x10;
		}
	}
		Delay1ms(20);
		while(PF4!=0x10){
			PF4= GPIO_PORTF_DATA_R & 0x10;
		}
}  

