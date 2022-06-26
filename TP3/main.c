

#include <stdio.h>
#include "dht11.h"
#include "uart.h"

int main()
{
	UARTinit();

	char *hum = "";
	char *temp = "";

	while (1)
	{
		uint8_t response = DHT11_read_data(hum, temp);
		UART_TransmitString(hum);
		UART_TransmitString("\n");
		UART_TransmitString(temp);
		_delay_ms(50);
	}
	return 0;
}