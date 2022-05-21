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

typedef enum{MOSTRAR,YEAR,MNTH,DAY,HOUR,MIN,SEC}state;

void MEFinit();
void MEFupdate();
void actualizarLCD();

#endif /* MEF_H_ */