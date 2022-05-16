/*
 * reloj.c
 *
 * 
 * Created: 15/5/2022 18:58:42
 * Author: Adrian Barral, Lautaro La Vecchia
 */ 

#include "reloj.h"

typedef enum{MOSTRAR,YEAR,MNTH,DAY,HOUR,MIN,SEC}state;

typedef struct
{
	unsigned long year;
	uint8_t mnth;
	uint8_t day;
	uint8_t hour;
	uint8_t min;
	uint8_t sec;
} fecha;

state estado;

//si bien el año es mostrado con dos cifras, consideramos necesario almacenarlo completo
//para un calculo preciso del año bisiesto
fecha actual={1999,12,31,23,59,55};

//variable para almacenar la fecha que ingresa el usuario de manera temporal
//hasta que esta es confirmada	
fecha modificada;

uint8_t pkey;
uint8_t pkey_event;
bool blink=false;

void RELOJinit(){
	LCDinit();
	LCDclr();
	LCDhome();
	KEYPADinit();
	estado=MOSTRAR;
}

/************************************************************************
	Calcula los cantidad de dias de febrero teniendo en cuenta años
		bisiestos, bajo la regla de que estos son:
			>divisibles por 4 y no por 100
						o
			>divisibles por 4, por 100 y por 400
************************************************************************/
uint8_t leap(uint8_t year){
	if (!(year%4)){
		if(year%100){
			return 29;
		}
		else if (!(year%400)){
			return 29;
		}
	}
	return 28;
}

/************************************************************************
Calcula la maxima cant. de dias de cada mes dependiendo del año y la retorna.

		Funciona asumiendo que solo los dias pares tienen 30 dias,
		luego corrige para febrero teniendo en cuenta años bisiestos.	                                            
************************************************************************/
uint8_t maximo(uint8_t month,uint8_t year){
	if(!(month % 2)){
		if (month!=2){
			return 30;
		}else{
			return leap(year);
		}
	}
	return 31;
}

/************************************************************************
Actualiza todos los campos de la fecha actual, teniendo en cuenta los limites de cada rango
Luego, si se esta editando la fecha, tambien actualiza la variable temporal 'modificada'
exceptuando los campos que ya se hayan modificado y se esten modificando en ese momento.

Para esto ultimo se basa en el estado actual de la MEF, pasado por argumento.
************************************************************************/
void actualizarFecha(){
	if(++actual.sec == 60){
		actual.sec=0;
		if (++actual.min == 60){
			actual.min=0;
			if(++actual.hour == 24){
				actual.hour = 0;
				if(++actual.day > maximo(actual.mnth,actual.year)){
					actual.day=1;
					if(++actual.mnth == 13){
						actual.year++;
						actual.mnth=1;
					}
				}
			}
		}
	}
	switch(estado){
		case YEAR:
			modificada.mnth=actual.mnth;
			modificada.day=actual.day;
			modificada.hour=actual.hour;
			modificada.min=actual.min;
			modificada.sec=actual.sec;
		break;
		case MNTH:
			modificada.day=actual.day;
			modificada.hour=actual.hour;
			modificada.min=actual.min;
			modificada.sec=actual.sec;
		break;
		case DAY:
			modificada.hour=actual.hour;
			modificada.min=actual.min;
			modificada.sec=actual.sec;
		break;
		case HOUR:
			modificada.min=actual.min;
			modificada.sec=actual.sec;
		break;
		case MIN:
			modificada.sec=actual.sec;
		break;
		default: break;
	}
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
	switch(estado){
		case MOSTRAR:
			LCDescribeDato(actual.year,2);
			LCDsendChar('/');
			LCDescribeDato(actual.mnth,2);
			LCDsendChar('/');
			LCDescribeDato(actual.day,2);
			LCDGotoXY(0,1);
			LCDescribeDato(actual.hour,2);
			LCDsendChar(':');
			LCDescribeDato(actual.min,2);
			LCDsendChar(':');
			LCDescribeDato(actual.sec,2);
		break;
		case YEAR:
			if(blink){
				LCDsendChar(' ');
				LCDsendChar(' ');
			}else{
				LCDescribeDato(modificada.year,2);
			}
			LCDsendChar('/');
			LCDescribeDato(actual.mnth,2);
			LCDsendChar('/');
			LCDescribeDato(actual.day,2);
			LCDGotoXY(0,1);
			LCDescribeDato(actual.hour,2);
			LCDsendChar(':');
			LCDescribeDato(actual.min,2);
			LCDsendChar(':');
			LCDescribeDato(actual.sec,2);
		break;
		case MNTH:
			LCDescribeDato(modificada.year,2);
			LCDsendChar('/');
			if(blink){
				LCDsendChar(' ');
				LCDsendChar(' ');
				}else{
				LCDescribeDato(modificada.mnth,2);
			}
			LCDsendChar('/');
			LCDescribeDato(actual.day,2);
			LCDGotoXY(0,1);
			LCDescribeDato(actual.hour,2);
			LCDsendChar(':');
			LCDescribeDato(actual.min,2);
			LCDsendChar(':');
			LCDescribeDato(actual.sec,2);
		break;
		case DAY:
			LCDescribeDato(modificada.year,2);
			LCDsendChar('/');
			LCDescribeDato(modificada.mnth,2);
			LCDsendChar('/');
			if(blink){
				LCDsendChar(' ');
				LCDsendChar(' ');
				}else{
					LCDescribeDato(modificada.day,2);
			}
			LCDGotoXY(0,1);
			LCDescribeDato(actual.hour,2);
			LCDsendChar(':');
			LCDescribeDato(actual.min,2);
			LCDsendChar(':');
			LCDescribeDato(actual.sec,2);
		break;
		case HOUR:
			LCDescribeDato(modificada.year,2);
			LCDsendChar('/');
			LCDescribeDato(modificada.mnth,2);
			LCDsendChar('/');
			LCDescribeDato(modificada.day,2);
			LCDGotoXY(0,1);
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
		break;
		case MIN:
			LCDescribeDato(modificada.year,2);
			LCDsendChar('/');
			LCDescribeDato(modificada.mnth,2);
			LCDsendChar('/');
			LCDescribeDato(modificada.day,2);
			LCDGotoXY(0,1);
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
		break;
		case SEC:
			LCDescribeDato(modificada.year,2);
			LCDsendChar('/');
			LCDescribeDato(modificada.mnth,2);
			LCDsendChar('/');
			LCDescribeDato(modificada.day,2);
			LCDGotoXY(0,1);
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
		break;
	}
}

void RELOJupdate(volatile uint8_t* flag){
	if (*flag){
		*flag=0;
		if (estado!=MOSTRAR){
			blink=!blink;
		}
		actualizarFecha(estado);
		actualizarLCD(estado);
	}
	if(KEYPAD_update(&pkey)){
		switch(estado){
			case MOSTRAR:
				if(pkey=='A'){
					modificada=actual;
					estado=YEAR;
				}
			break;
			case YEAR:
				switch(pkey){
					case 'A':
						estado=MNTH;
					break;
					case 'B':
						modificada.year++;
						actualizarLCD();
					break;
					case 'C':
						modificada.year--;
						actualizarLCD();
					break;
					case 'D':
						estado=MOSTRAR;
						actualizarLCD();
					break;
				}
			break;
			case MNTH:
				switch(pkey){
					case 'A':
						estado=DAY;
					break;
					case 'B':
						if (++modificada.mnth==13) modificada.mnth=1;
						actualizarLCD();
					break;
					case 'C':
						if (--modificada.mnth==0) modificada.mnth=12;
						actualizarLCD();
					break;
					case 'D':
						estado=MOSTRAR;
						actualizarLCD();
					break;
				}
			break;
			case DAY:
				switch(pkey){
					case 'A':
						estado=HOUR;
					break;
					case 'B':
						if (++modificada.day==(maximo(modificada.mnth,modificada.year)+1)) modificada.day=1;
						actualizarLCD();
					break;
					case 'C':
						if (--modificada.day==0) modificada.day=maximo(modificada.mnth,modificada.year);
						actualizarLCD();
					break;
					case 'D':
						estado=MOSTRAR;
						actualizarLCD();
					break;
				}
			break;
			case HOUR:
				switch(pkey){
					case 'A':
						estado=MIN;
					break;
					case 'B':
						if (++modificada.hour==24) modificada.hour=0;
						actualizarLCD();
					break;
					case 'C':
						if (modificada.hour--==0) modificada.hour=23;
						actualizarLCD();
					break;
					case 'D':
						estado=MOSTRAR;
						actualizarLCD();
					break;
				}
			break;
			case MIN:
			switch(pkey){
				case 'A':
					estado=SEC;
				break;
				case 'B':
					if (++modificada.min==60) modificada.min=0;
					actualizarLCD();
				break;
				case 'C':
					if (modificada.min--==0) modificada.min=59;
					actualizarLCD();
				break;
				case 'D':
					estado=MOSTRAR;
					actualizarLCD();
				break;
			}
			break;
			case SEC:
			switch(pkey){
				case 'A':
					actual=modificada;
					estado=MOSTRAR;
					actualizarLCD();
				break;
				case 'B':
					if (++modificada.sec==60) modificada.sec=0;
					actualizarLCD();
				break;
				case 'C':
					if (modificada.sec--==0) modificada.sec=59;
					actualizarLCD();
				break;
				case 'D':
					estado=MOSTRAR;
					actualizarLCD();
				break;
			}
			break;
		}	
	}
}	