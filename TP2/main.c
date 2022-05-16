/*
 * TP2.c
 *
 * Created: 12/5/2022 14:00:39
 * Author : Adrian Barral, Lautaro La Vecchia
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#define F_CPU 16000000L
#include <util/delay.h>
#include "reloj.h"
#include "timer.h"

volatile uint8_t flagMEF=1;
volatile uint8_t flagClk=0;



int main(void)
{
	RELOJinit();
	TIMERinit();
	while (1)
	{
		if(flagMEF){
			flagMEF=0;
			RELOJupdate(&flagClk);
		}
		
	}
}

// interrupción por igualdad de comparación en TIMER1
ISR(TIMER1_COMPA_vect)
{
	static uint8_t count=0;
	flagMEF=1;
	count++;
	//1 segundo
	if(count==10){
		count=0;
		flagClk=1;
	}
}