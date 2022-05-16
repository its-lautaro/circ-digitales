/*
 * keypad.h
 * 
 * Created: 12/5/2022 14:04:01
 * Author: Adrian Barral, Lautaro La Vecchia
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
	
void KEYPADinit();
uint8_t KEYPAD_Scan(uint8_t *);
uint8_t KEYPAD_update(uint8_t *);

#endif /* KEYPAD_H_ */

