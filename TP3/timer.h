/*
 * timer.h
 *
 * Created: 16/5/2022 15:40:18
 *  Author: Lenovo
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <avr/interrupt.h>
void TIMERinit(void);
void TIMER_Enable(void);
void TIMER_Disable(void);
uint8_t TIMER_get_flag_clk(void);
void TIMER_set_flag_clk(uint8_t);
void TIMER_clearCount();
#endif /* TIMER_H_ */