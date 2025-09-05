#ifndef __delay_H
#define __delay_H
#include "stm32f10x.h"
#include "FreeRTOS.h"
#include "semphr.h"
void delay_us(uint32_t us);
void delay_ms(uint32_t ms);
void delay_s(uint32_t s);
void delay_Init(void);
#endif
