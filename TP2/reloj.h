/*
 * reloj.h
 *
 * Created: 16/5/2022 00:52:41
 *  Author: Lenovo
 */ 


#ifndef RELOJ_H_
#define RELOJ_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "lcd.h"
#include "keypad.h"

void RELOJinit();
uint8_t leap(uint8_t );
uint8_t maximo(uint8_t ,uint8_t );
void actualizarFecha();
void actualizarLCD();
void RELOJupdate(volatile uint8_t*);

#endif /* RELOJ_H_ */