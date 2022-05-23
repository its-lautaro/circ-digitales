/*
 * reloj.c
 *
 * 
 * Created: 15/5/2022 18:58:42
 * Author: Adrian Barral, Lautaro La Vecchia
 */ 

#include "reloj.h"

fecha actual;
/************************************************************************/
/* Inicializa el reloj configurando una fecha en tiempo de compilacion*/
/************************************************************************/
void RELOJinit(){
	actual.day=31;
	actual.mnth=12;
	actual.year=1999;
	
	actual.hour=23;
	actual.min=59;
	actual.sec=55;
}

/************************************************************************
Actualiza todos los campos de la fecha actual, teniendo en cuenta los limites de cada rango
************************************************************************/
void RELOJupdate(){
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
}
/************************************************************************/
/* Actualiza el valor de la fecha al valor pasado por argumento.*/
/************************************************************************/
void RELOJsetTime(fecha new){
	actual=new;
}
/************************************************************************/
/* Devuele el valor actual de la fecha*/
/************************************************************************/
fecha RELOJgetTime(){
	return actual;
}