

#include <stdio.h>
#include "dht11.h"
#include "uart.h"

int main(){
	 UARTinit();
	 
	 while (1){
		 UART_TransmitPolling('H');
		 _delay_ms(50);
	 }
	 return 0;
}