#ifndef SCREEN_H
#define SCREEN_H

#include "inc\ST7735.h"

void screenInit(enum initRFlags option);
void drawSomething();
void drawCircle(int16_t x, int16_t y, int32_t radius, uint32_t steps);

#endif
