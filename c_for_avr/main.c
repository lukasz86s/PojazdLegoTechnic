/*
 * main.c
 *
 *  Created on: 26 sie 2018
 *      Author: fet
 */
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "head/rs_232.h"
#include "head/serwa.h"

#define POZYCJA0 84
#define TOLERANCE 2
#define UP 1
#define DOWN 2
 uint8_t skret =3,jazda = 0,biegi = 0 ;
 enum{stop,kierunek1,kierunek2,stop_funkcji};
void pwmStep(volatile uint16_t *kanal,uint8_t kierunek);
void powrot (volatile uint16_t *kanal);
int main (void){

	serwa_int ();
	USART_Init(_UBRR);
	pwm1=1000;
	//zezwolenie na przerwania
sei();
pwm3 = POZYCJA0;
pwm1=0;
serwa_int ();
	while(1){
		switch(data){

		case 'A':skret =kierunek1;
		break;
		case 'a':skret =stop;
		break;

		case 'D':skret =kierunek2;
		break;
		case 'd':skret =stop;
		break;

		case 'W': jazda =kierunek1;
		break;
		case 'w': jazda =stop;
		break;
		case 'S': jazda =kierunek2;
		break;
		case 's': jazda =stop;
		break;
		case 'H': biegi = 1;
		break;
		case 'L': biegi = 2;
		}
		//jazda

		if(jazda== kierunek1){
			PORTB|=(1<<PB4);
			PORTB&=~(1<<PB5);
			jazda =stop_funkcji;
		}
		else if(jazda == kierunek2){
			PORTB|=(1<<PB5);
			PORTB&=~(1<<PB4);
			jazda = stop_funkcji;
		}
		else if(jazda == stop)PORTB&= ~((1<<PB4)|(1<<PB5)),stop_funkcji;

		//obrót

		if(skret== kierunek1)pwmStep(&pwm3,DOWN);
		else if(skret == kierunek2)pwmStep(&pwm3,UP);
		else if(skret == stop)powrot(&pwm3);//

		//biegi

		if(biegi == 1)pwm1 = 1000,biegi = stop_funkcji;
		if(biegi == 2)pwm1 = 300 ,biegi = stop_funkcji;






}

}
void pwmStep(volatile uint16_t *kanal,uint8_t kierunek){


		start_licznika = 1;
		if((kierunek == UP)&&(*kanal>=POZYCJA0)){

		*kanal = (POZYCJA0+ms_ct);
		}

		else if((kierunek== DOWN)&&(*kanal<=POZYCJA0)){
			*kanal = (POZYCJA0-ms_ct);

		}

		//else powrot(kanal);				// odjac to obrót bedzie sie zatrzymywal
										//po skontrowaniu w przewny kierunek





	}
void powrot (volatile uint16_t *kanal){
	start_licznika = 2;
	if(*kanal>=(POZYCJA0 + TOLERANCE))*kanal = (POZYCJA0+ms_ct);
	else if(*kanal<=(POZYCJA0 - TOLERANCE))*kanal = (POZYCJA0-ms_ct);
	else {
		*kanal = POZYCJA0;
		ms_ct = 0;
		start_licznika = 3;
	}
}

