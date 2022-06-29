#ifndef UART_H

#define UART_H

#include "serialPort.h"
#include "dht11.h"
#include "timer.h"

#define USART_BAUDRATE 9600 // Desired Baud Rate
#define BAUD_PRESCALER (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

#define ASYNCHRONOUS (0 << UMSEL00) // USART Mode Selection

#define DISABLED (0 << UPM00)
#define PARITY_MODE DISABLED // USART Parity Bit Selection

#define ONE_BIT (0 << USBS0)
#define STOP_BIT ONE_BIT // USART Stop Bit Selection

#define EIGHT_BIT (3 << UCSZ00)
#define DATA_BIT EIGHT_BIT // USART Data Bit Selection

void UARTinit();
uint8_t UART_HayComando();
void UART_Set_False_Command_Flag();
char *UART_GetComando();
void UART_On();
void UART_Off();
void UART_Reset();
void UART_Print_Error();
void UART_setMensaje(char *);
#endif