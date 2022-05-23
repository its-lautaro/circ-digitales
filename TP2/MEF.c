/*
 * MEF.c
 *
 * Maquina de estado finito para modelar el funcionamiento del reloj. La MEF lee el teclado y permite modificar todos los campos de la fecha y hora.
 * Tiene en cuenta años bisiestos.
 
 * Created: 21/5/2022 13:21:49
 * Author: Adrian Barral, La Vecchia Lautaro
 */ 

#include "MEF.h"

state estado;

uint8_t pkey;
uint8_t pkey_event;

uint8_t count=10;
bool blink=false;

fecha modificada;

/************************************************************************/
/*Inicializa la mef inicializando el display y el teclado 4x4. Setea el
estado inicial*/
/************************************************************************/
void MEFinit(){
	LCDinit();
	LCDclr();
	LCDhome();
	KEYPADinit();
	estado=MOSTRAR;
}

/************************************************************************/
/* La actualizacion de la MEF consiste en leer las entradas (el teclado 4x4)
y en funcion de los estados realizar la transicion correspondiente.
Se trata de una maquina de Mealy.
                                                                    */
/************************************************************************/
void MEFupdate(){
	switch (estado){
		case MOSTRAR: count=10;
		break;
		default: count--;
			if (!count){
				 blink=!blink;
				 count=10;
			}
			break;
	}
	//lee las entradas
	if(KEYPAD_update(&pkey)){
		switch(estado){
			case MOSTRAR:
			if(pkey=='A'){
				modificada.year=RELOJgetTime().year;
				estado=YEAR;
			}
			break;
			case YEAR:
			switch(pkey){
				case 'A':
				modificada.mnth=RELOJgetTime().mnth;
				estado=MNTH;
				break;
				case 'B':
				modificada.year++;
				break;
				case 'C':
				modificada.year--;
				break;
				case 'D':
				estado=MOSTRAR;
				break;
			}
			break;
			case MNTH:
			switch(pkey){
				case 'A':
				modificada.day=RELOJgetTime().day;
				//me aseguro de que la fecha sea valida antes de confirmar
				if (modificada.day > maximo(modificada.mnth,modificada.year)) modificada.day=maximo(modificada.mnth,modificada.year);
				estado=DAY;
				break;
				case 'B':
				if (++modificada.mnth==13) modificada.mnth=1;
				break;
				case 'C':
				if (--modificada.mnth==0) modificada.mnth=12;
				break;
				case 'D':
				estado=MOSTRAR;
				break;
			}
			break;
			case DAY:
			switch(pkey){
				case 'A':
				modificada.hour=RELOJgetTime().hour;
				estado=HOUR;
				break;
				case 'B':
				if (++modificada.day>(maximo(modificada.mnth,modificada.year))) modificada.day=1;
				break;
				case 'C':
				if (--modificada.day==0) modificada.day=maximo(modificada.mnth,modificada.year);
				break;
				case 'D':
				estado=MOSTRAR;
				break;
			}
			break;
			case HOUR:
			switch(pkey){
				case 'A':
				modificada.min=RELOJgetTime().min;
				estado=MIN;
				break;
				case 'B':
				if (++modificada.hour==24) modificada.hour=0;
				break;
				case 'C':
				if (--modificada.hour<0) modificada.hour=23;
				break;
				case 'D':
				estado=MOSTRAR;
				break;
			}
			break;
			case MIN:
			switch(pkey){
				case 'A':
				modificada.sec=RELOJgetTime().sec;
				estado=SEC;
				break;
				case 'B':
				if (++modificada.min==60) modificada.min=0;
				break;
				case 'C':
				if (modificada.min--==0) modificada.min=59;
				break;
				case 'D':
				estado=MOSTRAR;
				break;
			}
			break;
			case SEC:
			switch(pkey){
				case 'A':
				RELOJsetTime(modificada);
				estado=MOSTRAR;
				break;
				case 'B':
				if (++modificada.sec==60) modificada.sec=0;
				break;
				case 'C':
				if (modificada.sec--==0) modificada.sec=59;
				break;
				case 'D':
				estado=MOSTRAR;
				break;
			}
			break;
		}
	}
	//actualiza las salidas
	actualizarLCD();
}

/************************************************************************
Actualiza la pantalla dependiendo del estado actual de la MEF.
Si el usuario se encuentra modificando algun campo, ademas de actualizarse
debe parpadear.

		Parpadea 1 vez por segundo. Esto se interpreta como:
	mostrar el campo q se esta modificando durante 1 segundo,
	apagarlo durante 1 segundo.
************************************************************************/

void actualizarLCD(){
	LCDclr();
	LCDGotoXY(0,0);
	fecha actual=RELOJgetTime();
	
	switch(estado){
		case MOSTRAR:
			LCDescribeDato(actual.hour,2);
			LCDsendChar(':');
			LCDescribeDato(actual.min,2);
			LCDsendChar(':');
			LCDescribeDato(actual.sec,2);
			
			LCDGotoXY(0,1);
			
			LCDescribeDato(actual.day,2);
			LCDsendChar('/');
			LCDescribeDato(actual.mnth,2);
			LCDsendChar('/');
			LCDescribeDato(actual.year,2);			
		break;
		case YEAR:
			LCDescribeDato(actual.hour,2);
			LCDsendChar(':');
			LCDescribeDato(actual.min,2);
			LCDsendChar(':');
			LCDescribeDato(actual.sec,2);
			
			LCDGotoXY(0,1);
			
			LCDescribeDato(actual.day,2);
			LCDsendChar('/');
			LCDescribeDato(actual.mnth,2);
			LCDsendChar('/');
			if(blink){
				LCDsendChar(' ');
				LCDsendChar(' ');
				}else{
				LCDescribeDato(modificada.year,2);
			}
		break;
		case MNTH:
			LCDescribeDato(actual.hour,2);
			LCDsendChar(':');
			LCDescribeDato(actual.min,2);
			LCDsendChar(':');
			LCDescribeDato(actual.sec,2);
			
			LCDGotoXY(0,1);
			
			LCDescribeDato(actual.day,2);
			LCDsendChar('/');
			if(blink){
				LCDsendChar(' ');
				LCDsendChar(' ');
				}else{
				LCDescribeDato(modificada.mnth,2);
			}
			LCDsendChar('/');
			LCDescribeDato(modificada.year,2);
		break;
		case DAY:
			LCDescribeDato(actual.hour,2);
			LCDsendChar(':');
			LCDescribeDato(actual.min,2);
			LCDsendChar(':');
			LCDescribeDato(actual.sec,2);
			
			LCDGotoXY(0,1);
			
			if(blink){
				LCDsendChar(' ');
				LCDsendChar(' ');
				}else{
				LCDescribeDato(modificada.day,2);
			}
			LCDsendChar('/');
			LCDescribeDato(modificada.mnth,2);
			LCDsendChar('/');
			LCDescribeDato(modificada.year,2);
		break;
		case HOUR:
			if(blink){
				LCDsendChar(' ');
				LCDsendChar(' ');
				}else{
				LCDescribeDato(modificada.hour,2);
			}
			LCDsendChar(':');
			LCDescribeDato(actual.min,2);
			LCDsendChar(':');
			LCDescribeDato(actual.sec,2);
			
			LCDGotoXY(0,1);
			
			LCDescribeDato(modificada.day,2);
			LCDsendChar('/');
			LCDescribeDato(modificada.mnth,2);
			LCDsendChar('/');
			LCDescribeDato(modificada.year,2);
		break;
		case MIN:
			LCDescribeDato(modificada.hour,2);
			LCDsendChar(':');
			if(blink){
				LCDsendChar(' ');
				LCDsendChar(' ');
				}else{
				LCDescribeDato(modificada.min,2);
			}
			LCDsendChar(':');
			LCDescribeDato(actual.sec,2);
			
			LCDGotoXY(0,1);
			
			LCDescribeDato(modificada.day,2);
			LCDsendChar('/');
			LCDescribeDato(modificada.mnth,2);
			LCDsendChar('/');
			LCDescribeDato(modificada.year,2);
		break;
		case SEC:
			LCDescribeDato(modificada.hour,2);
			LCDsendChar(':');
			LCDescribeDato(modificada.min,2);
			LCDsendChar(':');
			if(blink){
				LCDsendChar(' ');
				LCDsendChar(' ');
				}else{
				LCDescribeDato(modificada.sec,2);
			}
			
			
			LCDGotoXY(0,1);
			
			LCDescribeDato(modificada.day,2);
			LCDsendChar('/');
			LCDescribeDato(modificada.mnth,2);
			LCDsendChar('/');
			LCDescribeDato(modificada.year,2);
		break;
	}
}