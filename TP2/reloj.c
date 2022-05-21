/*
 * reloj.c
 *
 * 
 * Created: 15/5/2022 18:58:42
 * Author: Adrian Barral, Lautaro La Vecchia
 */ 

#include "reloj.h"

//si bien el año es mostrado con dos cifras, consideramos necesario almacenarlo completo
//para un calculo preciso del año bisiesto
fecha actual;

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
Luego, si se esta editando la fecha, tambien actualiza la variable temporal 'modificada'
exceptuando los campos que ya se hayan modificado y se esten modificando en ese momento.

Para esto ultimo se basa en el estado actual de la MEF, pasado por argumento.
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

void RELOJsetTime(fecha new){
	actual=new;
}

fecha RELOJgetTime(){
	return actual;
}