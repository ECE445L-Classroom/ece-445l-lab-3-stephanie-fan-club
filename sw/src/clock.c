#include "clock.h"


uint32_t seconds, refreshScreen;

void secondsInc(void){
	seconds++;
	refreshScreen = 1;
}

void clockinit(void){
	seconds = 0;
	refreshScreen = 0;
	Timer0A_Init(&secondsInc,80000000,0);
}

void clockdisplay(void){
	uint32_t hour, min, sec;
	
	sec = (seconds % 60);
	if(seconds >= 60) 
		min = seconds / 60;
	if(seconds >= 360)
		hour = seconds / 360;
	
	char timeyay[9];
	sprintf(timeyay, "%02d:%02d:%02d", hour, min, sec);
	
	
	ST7735_SetCursor(10,7);
	ST7735_DrawString(7,7,timeyay,ST7735_BLUE);
	
}