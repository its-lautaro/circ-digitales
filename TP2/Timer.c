/* timer.c
 *
 * Created: 16/5/2022 13:49:27
 *  Author: Lenovo
 */ 
#include "timer.h"

/************************************************************************
Utiliza el timer 1 de 16bits para lograr interrupciones cada 100ms
Debe contar hasta 1562 con un prescaler de 1024 para este fin,
logrando los 100ms con un error del orden 0.1;
************************************************************************/
void TIMERinit(){
	// Configura el timer1 en modo CTC con prescaler 1024
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1  = 0;  //Inicializa el contador
	TCCR1B |= (1 << WGM12)|(1<<CS10)|(1 << CS12);   // modo CTC, prescaler de 1024
	OCR1A = 0x61A;	// configura el contador de comparacion para 1562
	TIMSK1 |= (1 << OCIE1A);  // habilita interrupción por igualdade de comparación
	sei(); //habilita las interrupciones para el MCU
}