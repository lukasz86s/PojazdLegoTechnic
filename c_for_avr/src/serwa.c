/*
 * serwa.c
 *
 *  Created on: 30 lis 2016
 *      Author: fet
 */
#include "../head/serwa.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>


void serwa_int (void){
	DDRB |= serwo1|serwo2|serwo3|serwo4|serwo5;				// ustawienie jako wyjscia linni sterujacych
	PORTB &= ~(serwo1|serwo2|serwo3|serwo4|serwo5);			// ustawienie stanu niskiego na linniach sterujacych

	// ustawienia timera
	TCCR2|= (1<<WGM21);				// tryb CTC
	TCCR2|= (1<<CS20);				// preskaler 1
	OCR2=220;						//dodatkowy podzia³ przez 50 dla 1ms
	TIMSK|=(1<<OCIE2);				// zezwolenie na przerwania

	start_licznika=3;
	ms_ct = 0;
}

ISR(TIMER2_COMP_vect){
	static u16 cnt, krok;

	if(cnt <= pwm1)PORTB|= serwo1; else PORTB &= ~ serwo1;
	if(cnt <= pwm2)PORTB|= serwo2; else PORTB &= ~ serwo2;
	if(cnt <= pwm3)PORTB|= serwo3; else PORTB &= ~ serwo3;
	//if(cnt <= pwm4)PORTB|= serwo4; else PORTB &= ~ serwo4;
	//if(cnt <= pwm5)PORTB|= serwo5; else PORTB &= ~ serwo5;
	if(cnt>999)cnt=0;
	if(start_licznika == 1 ){
		krok++;
		if(krok ==licznik){
			if(ms_ct <40)ms_ct++;
			else start_licznika = 3;
			krok=0;
		}		//100 tykniec = 2ms;

	}
	if(start_licznika == 2 ){
		krok++;
		if(krok ==licznik){
			if(ms_ct>0 )ms_ct--;
			else start_licznika = 3;
			krok=0;
		}
	}

	cnt++;
}
