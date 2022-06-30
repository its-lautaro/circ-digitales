/*
 * cli.c
 *
 */ 

#include "uart.h"
#include "timer.h"
#include "dht11.h"
#include "cli.h"

static volatile uint8_t flag = 0;
static char bienvenida[] = "Bienvenido\rON: para encender, OFF para apagar, RST para reiniciar\r";
static char invalido[] = "Comando invalido\r";

void CLIinit(){
	UART_sendMsg(bienvenida);
}


uint8_t CLI_GetFlag(){
	return flag;
};

void CLI_cmd(char comando[])
{

	int nroComando = comparador(comando);

	switch (nroComando) // evaluo si recibi un comando o un numero invalido
	{
		case 0: //on
			flag=1;
			UART_sendMsg(DHT11_getMessage());
			TIMER_Enable();
		break;
		case 1: //off
			flag=0;
			UART_sendMsg("\rOff\r");
			TIMER_Disable();
		break; 
		case 2: //reset
			UART_sendMsg(bienvenida);		
		break;
		case 3: //comando invalido
			UART_sendMsg(invalido);
		break;
	}
}

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
