#ifndef UART_H

#define UART_H
#define F_CPU 16000000UL // Defining the CPU Frequency
#include <avr/io.h>      // Contains all the I/O Register Macros
#include <util/delay.h>  // Generates a Blocking Delay
#include <string.h>
#include "serialPort.h"
#include "dht11.h"
#include "timer.h"

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