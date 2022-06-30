/*
 * cli.h
 *
 * Created: 29/6/2022 22:50:26
 *  Author: Lenovo
 */ 


#ifndef CLI_H_
#define CLI_H_

#include "utils.h"

void CLIinit();
uint8_t CLI_GetFlag();
void CLI_cmd(char*);
int comparador(char*);

#endif /* CLI_H_ */