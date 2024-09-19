#ifndef CLOCK_H
#define CLOCK_H
#include <stdio.h>
#include <stdint.h>
#include "../inc/ST7735.h"
#include "../inc/Timer0A.h"

extern uint32_t seconds, refreshScreen;\
void clockinit(void);
void clockdisplay(void);

#endif