#ifndef UART_H

#define UART_H

#include <string.h>

void UARTinit();

void UART_TransmitPolling(uint8_t DataByte);

void UART_TransmitString(char *);

#endif