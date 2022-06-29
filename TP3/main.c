/*
* main.c
*/
#include "utils.h"

#include "dht11.h"
#include "uart.h"
#include "timer.h"
#include "serialPort.h"

void logicaDeAplicacion(char comando[]);
int comparador(char palabra[]);

char comando[4]; //ON OFF RST

int main(void)
{
	_delay_ms(5000);
	UARTinit(); // se inicializa la UART
	TIMERinit();
	sei(); // habilito las interrupciones
	while (1)
	{
		if (UART_HayComando()) //leo flag UART
		{
			cli();
			strcpy(comando, UART_GetComando()); // recibo y guardo el comando desde la uart
			UART_Set_False_Command_Flag();		// reseteo flag
			logicaDeAplicacion(comando);		// valido y ejecuto el comando
			sei();
		}

		if (TIMER_get_flag_clk()) //leo flag TIMER
		{
			cli();
			TIMER_set_flag_clk(0);
			UART_setMensaje(DHT11_getMessage());
			SerialPort_TX_Interrupt_Enable();
			sei();
		}
	
	}
	return 0;
}

/*Funcion que recibe el comando ingresado por parametro
  y ejecuta la accion correspondiente segun su valor.
*/
void logicaDeAplicacion(char comando[])
{

	int nroComando = comparador(comando);

	switch (nroComando) // evaluo si recibi un comando o un numero invalido
	{
	case 0:
		UART_On();
		break; // se enciende el generador
	case 1:
		UART_Off();
		break; // se apaga el generador
	case 2:
		UART_Reset();
		break; // se resetea el generador
	case 3:
		UART_Print_Error();
		break; // comando invalido
	}
}

/* Recibo el comando y verifico si es "on", "off", "reset"
en caso contrario el comando no es valido
Salidas:
on -> 0
off -> 1
rst -> 2
comando invalido -> 3
*/
// strcmp devuelve 0 si los strings son iguales
int comparador(char comando[])
{
	if (!strcmp(comando, "ON"))
	{
		return 0; // el comando es on
	}
	if (!strcmp(comando, "OFF"))
	{
		return 1; // el comando es off
	}
	if (!strcmp(comando, "RST"))
	{
		return 2; // el comando es rst
	}
	return 3; // comando invalido
}
