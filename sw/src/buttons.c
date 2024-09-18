#include "buttons.h"


void switchInit(){
	const uint32_t portf = 0x20;
	const uint32_t pin0 = 0x1;
	const uint32_t pin4 = 0x10;
	
	SYSCTL_RCGCGPIO_R |= portf; //activate portf
	while(!(SYSCTL_RCGCGPIO_R&portf)){}; // sets clock then waits for it
	
	GPIO_PORTF_DIR_R &= ~(pin4|pin0);
	GPIO_PORTF_DEN_R |= (pin4|pin0);		
}