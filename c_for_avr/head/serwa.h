/*
 * serwa.h
 *
 *  Created on: 30 lis 2016
 *      Author: fet
 */

#ifndef STEROWANIE_RAMIENIA_SERWA_SERWA_SERWA_H_
#define STEROWANIE_RAMIENIA_SERWA_SERWA_SERWA_H_

#include <avr/io.h>
//porty steruj¹ce
#define serwo1 (1<<PB1)
#define serwo2 (1<<PB2)
#define serwo3 (1<<PB3)
#define serwo4 (1<<PB4)
#define serwo5 (1<<PB5)
// ustawienie podstway czasu
#define ms_time 15 // wstaw wartosc milisekud ktora ma byc odliczana max 5ms
#define licznik ms_time*50




typedef uint8_t u08;
typedef uint16_t u16;

volatile u16 pwm1,pwm2,pwm3;//;,pwm4,pwm5;	//sterowanie serwem z przedzia³u 50-100 karzdy kork oko³o 3,6stopnia
volatile u08 start_licznika,ms_ct;
void serwa_int (void);

#endif /* STEROWANIE_RAMIENIA_SERWA_SERWA_SERWA_H_ */
