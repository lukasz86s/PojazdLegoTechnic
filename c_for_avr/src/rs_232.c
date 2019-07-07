/*
 * rs_232.c
 *
 *  Created on: 24 maj 2018
 *      Author: fet
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../head/rs_232.h"
void USART_Init(uint16_t baud){
	//ustawienie predkosci
	UBRRH = (uint8_t)(baud>>8);
	UBRRL = (uint8_t)baud;
	// za³aczenie nadajnika , odbiornika i przerwan odbioru
    UCSRB = (1<<RXEN)| (1<<TXEN)|(1<<RXCIE);
    // ustawienie farmatu ramki 8 bit danych .  1 bit stopu brak bitów parzystosci
    UCSRC = (1<<URSEL) | (3<<UCSZ0);


}

// funkcja nadawania
void USART_transmition (char data){
	//czekaj a¿ bufor nadawczy bêdzie pusty
	while (!(UCSRA & (1<< UDRE) ) );
	// za³aduj dane
	UDR = data;
}
//funkcja odbioru
unsigned char USART_receive(void){

	// czekaj a¿ dane bed¹ odebrane

	while(!(UCSRA & (1<<RXC)) );
	// zwróc odebrany bajt
	return UDR;


}

ISR(USART_RXC_vect){

	data = UDR ;
}

