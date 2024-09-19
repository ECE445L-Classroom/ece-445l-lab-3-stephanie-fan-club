#ifndef BUTTONS_H
#define BUTTONS_H

#include <stdio.h>
#include <stdint.h>
#include "../inc/ST7735.h"
#include "../inc/PLL.h"
#include "../inc/tm4c123gh6pm.h"

void switchInit();
int switch1Pressed();
int switch2Pressed();

#endif
