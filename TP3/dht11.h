#ifndef DHT11_H
#define DHT11_H
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

uint8_t DHT11_read_data(char *, char *);
char *DHT11_getMessage();

#endif
