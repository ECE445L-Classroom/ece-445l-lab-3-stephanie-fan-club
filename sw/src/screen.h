#ifndef SCREEN_H
#define SCREEN_H

#include "inc\ST7735.h"

void screenInit(enum initRFlags option);

void drawCircle(int16_t x, int16_t y, int32_t radius, uint32_t steps);
void drawArc(int16_t x, int16_t y, int32_t radius, uint32_t steps, uint32_t startStep, uint8_t startUp);
void showMenu();
void drawClock();
void drawSnowman();

void drawLine(int16_t x, int16_t y, int16_t length, uint32_t angleSteps);
#endif
