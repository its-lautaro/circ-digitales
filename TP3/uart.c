/* UART.c
*
* Author: lau
*
*/

#include "dht11.h"
#include <avr/interrupt.h>
void UARTinit(){
		cli();
		/* Configuración del USART como UART */

		// USART como UART
		UCSR0C &=~ (1<<UMSEL00);
		UCSR0C &=~ (1<<UMSEL01);

		// Paridad desactivada
		UCSR0C &=~ (1<<UPM00);
		UCSR0C &=~ (1<<UPM01);

		// Stops = 1
		UCSR0C &=~ (1<<USBS0);

		// Datos de 8 bits
		UCSR0C |=  (1<<UCSZ00);
		UCSR0C |=  (1<<UCSZ01);
		UCSR0B &=~ (1<<UCSZ02);
		
		// Calculo del baudrate
		UCSR0A |= (1<<U2X0);
		UBRR0 = (F_CPU/8/9600) - 1;

		UCSR0B |= (1<<TXEN0);
		UCSR0B |= (1<<RXEN0);

		UCSR0B |= (1<<RXCIE0);

		sei();
}

void UARTsendString(char* str){
    while(!(UCSR0A &(1<<UDRE0))){}; //esperar que el buffer este listo para transmitir
	UDR0 = 0b00010000;
}