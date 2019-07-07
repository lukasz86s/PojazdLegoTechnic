/*
 * rs_232.h
 *
 *  Created on: 24 maj 2018
 *      Author: fet
 */

#ifndef RS_232_H_


#define RS_232_H_


#define UART_BAUND 9600 // podanie predkosci trasmisji
// obliczenie parametru dla danej predkosci
#define _UBRR ((F_CPU+UART_BAUND * 8UL) / (16UL * UART_BAUND)-1)  // dla UX2 = 0
//#define _URB ((F_CPU+UART_BAUND * 4UL) / ( 8UL * UART_BAUND)-1)	 // dla UX2 = 1

 volatile char data;
volatile char data1;


void USART_Init(uint16_t baud);
void USART_transmition (char data);
unsigned char USART_receive (void);




#endif /* RS_232_H_ */
