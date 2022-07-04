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
	UART_Init();
	TIMER_init();
	CLI_Init();

	sei();

	while (1)
	{
		if (UART_GetCmdFlag()) // Recibo un comando
		{
			UART_ClearCmdFlag();
			CLI_cmd(UART_ReadBuffer());
			UART_Enable_Rx();
		}

		if (CLI_GetCommandFlag() && TIMER_GetClkFlag())
		{
			TIMER_ClearClkFlag();
			UART_SendMsg(DHT11_getMessage());
		}
	}
	return 0;
}