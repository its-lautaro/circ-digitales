/*
 * TP3.c
 *
 * Created: 23/6/2022 21:17:17
 * Author : USUARIO
 */ 

#include <avr/io.h>

#include "dht11.h"
#include "uart.h"




int main(void){
  char prueba[5]="hola\n";
  UARTinit();
  UARTsendString(prueba);
  while (1){
	  UARTsendString(prueba);
  }
}

