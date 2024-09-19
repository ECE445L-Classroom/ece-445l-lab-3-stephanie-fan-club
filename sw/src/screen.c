// hardware connections
// **********ST7735 TFT and SDC*******************
// ST7735
// Backlight (pin 10) 	+3.3 V
// MISO (pin 9) 				unconnected
// SCK (pin 8) 					PA2
// MOSI (pin 7) 				PA5
// TFT_CS (pin 6) 			PA3
// CARD_CS (pin 5) 			unconnected
// Data/Command (pin 4) PA6
// RESET (pin 3) 				PA7
// VCC (pin 2) 					+3.3 V
// Gnd (pin 1) 					ground

#include "screen.h"
#include "inc/UART.h"

void drawSomething() {
	for (int i=0; i < 20; i++) {
		ST7735_DrawPixel(50 + i, 50 + i, ST7735_BLUE);
	}
	
}



void drawLine(int16_t x, int16_t y, int16_t length, uint32_t angleSteps) {
	int16_t px, py;
	
	// point relative to center of circle
	// fixed point scale = 1/1024
	int32_t rx, ry;
	int32_t tempx, tempy;

	
	
	for (uint32_t l=0; l < length; l++) {
		rx = 0;
		ry = l << 10;
	
		for (uint32_t i=0; i < angleSteps; i++) {
			// apply rotation matrix to make next point
			tempx = (1023 * rx + 45*ry) >> 10;
			tempy = (-45*rx + 1023 * ry) >> 10;
			rx = tempx;
			ry = tempy;
		}
		// draw current point
		px = x + (rx >> 10);
		py = y + (ry >> 10);
		ST7735_DrawPixel(px, py, ST7735_BLUE);
	
	}
}

void drawCircle(int16_t x, int16_t y, int32_t radius, uint32_t steps) {
	// point in screen coordinates, not fixed point
	int16_t px, py;
	
	// point relative to center of circle
	// fixed point scale = 1/1024
	int32_t rx, ry;
	int32_t tempx, tempy;

	rx = 0;
	ry = radius << 10;
	
	for (uint32_t i=0; i < steps; i++) {	
		// draw current point
		px = x + (rx >> 10);
		py = y + (ry >> 10);
		ST7735_DrawPixel(px, py, ST7735_BLUE);
	

		// apply rotation matrix to make next point
		tempx = (1023 * rx + 45*ry) >> 10;
		tempy = (-45*rx + 1023 * ry) >> 10;
		rx = tempx;
		ry = tempy;
	}

}

// separate function becuase if statement makes computation heavier
void drawArc(int16_t x, int16_t y, int32_t radius, uint32_t steps, uint32_t startStep, uint8_t startUp) {
	// point in screen coordinates, not fixed point
	int16_t px, py;
	
	// point relative to center of circle
	// fixed point scale = 1/1024
	int32_t rx, ry;
	int32_t tempx, tempy;

	rx = 0;
	ry = radius << 10;
	if (startUp) ry *= -1;
	
	for (uint32_t i=0; i < steps; i++) {	
		if (i >= startStep) {
			// draw current point
			px = x + (rx >> 10);
			py = y + (ry >> 10);
			ST7735_DrawPixel(px, py, ST7735_BLUE);
		}

		// apply rotation matrix to make next point
		tempx = (1023 * rx + 45*ry) >> 10;
		tempy = (-45*rx + 1023 * ry) >> 10;
		rx = tempx;
		ry = tempy;
	}

}

void drawClock() {
	drawCircle(60, 90, 50, 150);
	drawLine(60, 90, 40, 60);
	drawLine(60, 90, 20, 120);
}

void drawSnowman() {
	drawCircle(64, 120, 30, 150); // lower body
	drawCircle(64, 70, 20, 150); // upper body
	drawCircle(64, 35, 15, 150); // head
	
	drawLine(44, 70, 30, 120); // left arm
	drawLine(84, 70, 30, 300); // right arm
	
	// sunglasses
	drawCircle(64, 32, 3, 150); // left shade
	drawCircle(72, 32, 3, 150); // right shade
	drawLine(69, 32, 3, 100); // glasses frame
	
	// smug king smile
	drawArc(69, 40, 4, 100, 50, 1); // mouth
	drawLine(70, 28, 10, 50); // right eyebrow
	drawLine(65, 28, 10, 100); // left eyebrow
	
	// nose
	drawLine(90, 40, 20, 100);
	drawLine(90, 40, 20, 105); 
	
	// buttons
	drawCircle(64, 60, 5, 150);
	drawCircle(64, 80, 5, 150);
	drawCircle(64, 100, 5, 150);
	drawCircle(64, 120, 5, 150);
	
	ST7735_DrawString(1, 0, "Smug But Sad Snowman", ST7735_BLUE);
	ST7735_DrawString(5, 1, "By Kanaan Macias", ST7735_BLUE);
	
}

void showMenu() {
	ST7735_DrawString(4, 2, "Display Clock", ST7735_BLUE);
	ST7735_DrawString(4, 4, "Set Time", ST7735_BLUE);
	ST7735_DrawString(4, 6, "Set Timer", ST7735_BLUE);
	ST7735_DrawString(4, 8, "Start Timer", ST7735_BLUE);
	
	const int index = 0;
	const int row = 2 + index * 2;
	
	// Select arrow
	ST7735_DrawString(1, row, "->", ST7735_BLUE);
}

void screenInit(enum initRFlags option){
	ST7735_InitR(option);
}


