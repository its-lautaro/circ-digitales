/*
 * utils.h
 *
 * Created: 21/5/2022 13:31:25
 *  Author: Lautaro
 */ 


#ifndef UTILS_H_
#define UTILS_H_
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/************************************************************************/
/* Modelo de la fecha y hora. Si bien el año es mostrado con dos digitos,
internamente se almacena el año completo para poder realizar los
calculos para años bisiestos de manera precisa*/
/************************************************************************/
typedef struct
{
	unsigned long year;
	uint8_t mnth;
	uint8_t day;
	uint8_t hour;
	uint8_t min;
	uint8_t sec;
} fecha;

uint8_t leap(uint8_t);
uint8_t maximo(uint8_t,uint8_t);

#endif /* UTILS_H_ */