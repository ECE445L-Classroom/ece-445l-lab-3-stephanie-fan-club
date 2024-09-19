#include "buttons.h"

#include "../inc/LaunchPad.h"

const uint32_t pin0 = 0x1;
const uint32_t pin4 = 0x10;
const uint32_t portf = 0x20;

int sw1Pressed = 0;

// Init for PF4 and PF0 on board switches
void switchInit(){
	LaunchPad_Init();
}

int switch1Pressed() {
	int positive = GPIO_PORTF_DATA_R & pin4;
	
	if (sw1Pressed) {
		if (positive) sw1Pressed = 0;
	}
	else {
		if (!positive) {
			sw1Pressed = 1;
			return 1;
		}
	}
	
	return 0;
}