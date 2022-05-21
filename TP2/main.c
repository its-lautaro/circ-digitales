/*
 * TP2.c
 *
 * Created: 12/5/2022 14:00:39
 * Author : Adrian Barral, Lautaro La Vecchia
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include "reloj.h"
#include "timer.h"
#include "MEF.h"

volatile uint8_t flagMEF=1;
volatile uint8_t flagClk=0;



int main(void)
{
	RELOJinit();
	MEFinit();
	TIMERinit();
	while (1)
	{
		if(flagClk){
			flagClk=0;
			RELOJupdate(&flagClk);
		}
		if(flagMEF){
			flagMEF=0;
			MEFupdate();
		}
	}
}

// interrupción por igualdad de comparación en TIMER1 cada 100ms
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