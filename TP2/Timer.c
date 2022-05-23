/* timer.c
 *
 * Created: 16/5/2022 13:49:27
 *  Author: Lenovo
 */ 
#include "timer.h"

/************************************************************************
Utiliza el timer 1 de 16bits para lograr interrupciones cada 100ms
Debe contar hasta 25.000 con un prescaler de 64 para este fin,
logrando interrupciones precisas de 100ms;
************************************************************************/
void TIMERinit(){
	// Configura el timer1 en modo CTC con prescaler 64
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1  = 0;  //Inicializa el contador
	TCCR1B |= (1 << WGM12)|(1<<CS11)|(1 << CS10);   // modo CTC, prescaler de 64
	OCR1A = 0x61A8;	// configura el contador de comparacion para 25.000
	TIMSK1 |= (1 << OCIE1A);  // habilita interrupción por igualdad de comparación
	sei(); //habilita las interrupciones para el MCU
}