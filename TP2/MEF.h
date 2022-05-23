/*
 * MEF.h
 *
 * Created: 21/5/2022 13:46:40
 *  Author: Lautaro
 */ 


#ifndef MEF_H_
#define MEF_H_

#include "lcd.h"
#include "keypad.h"
#include "utils.h"
#include "reloj.h"

/************************************************************************/
/* Estados de la maquina de estados
MOSTRAR: estado inicial, envia el valor de la fecha actual al display
YEAR: parpadea el campo correspondiente al año y permite incrementarlo o decrementarlo
MNTH: idem con el campo correspondiente al mes
DAY: idem con el campo correspondiente al dia
HOUR: idem con el campo correspondiente a la hora
MIN: idem con el campo correspondiente a los minutos
SEC: idem con el campo correspondiente a los segundos.

En cualquiera de los estados, confirmar el valor ingresado transiciona al siguiente.
Con excepcion del estado SEC que trancisiona al estado inicial y actualiza el valor de la fecha y hora.

En cualquiera de los estados cancelar descarta los valores ingresados y devuelve al estado inicial.

Confirmar: Tecla 'A'
Incrementar campo: Tecla 'B'
Decremetar campo: Tecla 'C'
Cancelar: Tecla 'D'
/************************************************************************/
typedef enum{MOSTRAR,YEAR,MNTH,DAY,HOUR,MIN,SEC}state;

void MEFinit();
void MEFupdate();
void actualizarLCD();

#endif /* MEF_H_ */