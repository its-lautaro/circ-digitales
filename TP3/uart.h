#ifndef UART_H

#define UART_H

#include <string.h>

void UARTinit();

void UART_TransmitPolling(uint8_t DataByte);

void UART_TransmitString(char *);

uint8_t UART_HayComando();
void UART_Set_False_Command_Flag();
char *UART_GetComando();
void UART_Set_Frecuencia(int f);
void UART_On();
void UART_Off();
void UART_Reset();
void UART_Print_Error();

#endif