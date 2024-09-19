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

void screenInit(enum initRFlags option){
	ST7735_InitR(option);
}


