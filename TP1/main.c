/*
 * Alternar Secuencia de LEDs
 * Created: 21/3/2022 14:40:10
 * Author : Adrian y Lautaro
 */ 

/* Inclusión de cabeceras de bibliotecas de código */
#include <avr/io.h> // Definición de Registros del microcontrolador
#define F_CPU 1000000UL // Especifico la frecuencia de reloj del MCU en 16MHz
#include <util/delay.h> // Retardos por software
#include <stdbool.h> // Variables booleanas

int main (void)
{
	/* Setup */
	bool secuencia = true; // La secuencia en ejecucion: false -> secuencia 1, true -> secuencia 2
	bool pulsado = false; // Almacena si el pulsador fue apretado (se usa para reconocer cuando el pulsador es soltado)
	uint8_t etapa = 0; // Cada secuencia puede pensarse como un conjunto de 4 etapas, en la que alternan los pares de leds encendidos
	uint8_t hi; //Los 4 leds mas significativos
	uint8_t lo; //Los 4 leds menos significativos
	DDRC &=~(1<<PC0); // Configura el pin 0 del puerto C como entrada
	PORTC |= (1<<PC0); // Establece un resistor pull up en el pin 0 del puerto C, ya que el pulsador es activo en bajo
	DDRB = 0xFF; // Configura el puerto B como salida
	/* Loop */
	while(1)
	{	
		if (!(PINC & (1<<PC0)) && !pulsado) // Si el pulsador se aprieta (y no estuvo apretado en la iteracion anterior)
		{
			pulsado= true; // almacena que fue pulsado
			_delay_ms(50); // espera a que la entrada del pulsador se estabilice (debounce)
		}
		if ((PINC & (1<<PC0)) && pulsado) // Detecta cuando el pulsador es soltado
		{
			secuencia = !secuencia; //cambia la secuencia a ejecutar
			etapa = 0; //inicializa la secuencia
			pulsado= false; // actualiza la variable
			_delay_ms(50); // espero a que la entrada del pulsador se estabilice (debounce)
		}
		if (secuencia) //secuencia 1
		{
			hi = 0b10000000;
			lo = 0b0001;	
			hi=hi>>etapa;
			lo=lo<<etapa;
			
		}else{ //secuencia 2
			hi = 0b00010000;
			lo = 0b1000;
			hi=hi<<etapa;
			lo=lo>>etapa;
		}
		PORTB=hi + lo; //envío la secuencia correspondiente al puerto b
		_delay_ms(50); //frecuencia maxima de parpadeo percibida por el ojo humano
		etapa++; //paso a la siguiente etapa
		if (etapa==4){
			etapa=0;
		}
	}
	return 0;
}