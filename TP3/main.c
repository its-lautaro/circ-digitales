/*
* main.c
*/
#include "utils.h"

#include "dht11.h"
#include "uart.h"
#include "timer.h"
#include "cli.h"

int main(void)
{
	UARTinit();
	TIMERinit();
	CLIinit();
	
	sei();
	
	while (1)
	{
		if (UART_GetCmdFlag()) //Recibo un comando
		{
			UART_ClearCmdFlag();
			CLI_cmd(UART_ReadBuffer());
			UART_Enable_Rx();
		}

		if ( CLI_GetFlag() && TIMER_GetClkFlag() )
		{
			TIMER_ClearClkFlag();
			UART_sendMsg(DHT11_getMessage());
		}
	
	}
	return 0;
}