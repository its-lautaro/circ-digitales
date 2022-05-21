/*
 * utils.c
 *
 * Created: 21/5/2022 13:31:41
 *  Author: Lautaro
 */ 

#include "utils.h"

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