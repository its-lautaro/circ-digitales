

#include <stdio.h>
#include "dht11.h"
#include "uart.h"
#include <avr/interrupt.h>
void logicaDeAplicacion(char comando[]);
int comparador(char palabra[]);

char comando[10];

int main(void)
{

	UARTinit(); // se inicializa la UART
	// Timer1_Init(); // se inicializa el timer
	char hum[5];
	char temp[5];

	sei(); // habilito las interrupciones
	while (1)
	{
		/*
		DHT11_read_data(hum, temp);
		UART_TransmitString(hum);
		UART_TransmitString("\r");
		UART_TransmitString(temp);
		UART_TransmitString("\r");
		*/
		if (UART_HayComando()) // chequea comando_flag, 1-> hay comando, 0-> todavia no hay comando
		{
			strcpy(comando, UART_GetComando()); // recibo el comando desde la uart y lo copio en el string comando
			UART_Set_False_Command_Flag();		// pongo el flag comando_flag en 0 porque ya lei del buffer
			logicaDeAplicacion(comando);		// valido y ejecuto el comando
		}
	}
	return 0;
}

/*Funcion que recibe el comando ingresado por parametro
  y ejecuta la accion correspondiente segun su valor.
*/
void logicaDeAplicacion(char comando[])
{

	int nro = atoi(comando); // convierto el string a integer

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
