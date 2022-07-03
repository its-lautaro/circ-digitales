#ifndef UART_H

#define UART_H

#define USART_BAUDRATE 9600 // Desired Baud Rate
#define BAUD_PRESCALER (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

#define ASYNCHRONOUS (0 << UMSEL00) // USART Mode Selection

#define DISABLED (0 << UPM00)
#define PARITY_MODE DISABLED // USART Parity Bit Selection

#define ONE_BIT (0 << USBS0)
#define STOP_BIT ONE_BIT // USART Stop Bit Selection

#define EIGHT_BIT (3 << UCSZ00)
#define DATA_BIT EIGHT_BIT // USART Data Bit Selection

#include "utils.h"

void UARTinit();
void UART_sendMsg(char *msg);
char *UART_ReadBuffer();
uint8_t UART_GetCmdFlag();
void UART_ClearCmdFlag();
void UART_Disable_Rx();
void UART_Enable_Rx();
void UART_Disable_Tx();
void UART_Enable_Tx();

#endif