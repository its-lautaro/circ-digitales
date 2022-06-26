

#include <stdio.h>
#include "dht11.h"
#include "uart.h"

int main()
{
	UARTinit();
	char hum [5];
	char temp [5];
	
	while (1)
	{
		DHT11_read_data(hum,temp);
		UART_TransmitString(hum);
		UART_TransmitString("\r");
		UART_TransmitString(temp);
		UART_TransmitString("\r");
	}
	return 0;
}