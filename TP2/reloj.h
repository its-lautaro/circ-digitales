/*
 * reloj.h
 *
 * Created: 16/5/2022 00:52:41
 *  Author: Lenovo
 */ 


#ifndef RELOJ_H_
#define RELOJ_H_

#include "utils.h"

void RELOJinit();
void RELOJupdate();
fecha RELOJgetTime();
void RELOJsetTime(fecha);

#endif /* RELOJ_H_ */