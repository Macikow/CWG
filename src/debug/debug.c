/*
 * debug.c
 *
 * Created: 2015-06-06 18:56:54
 *  Author: Macikow
 */ 
#include "debug.h"
#define F_CPU 8000000UL
#include <avr/io.h>
#include <interrupt.h>
#include <stdio.h>


#define ENTER 0x0D
#define BACKSPACE 127
#define COMPARE_CHAR_COUNT 5

void USART_init(void){
	UBRR0L = (unsigned char) 51;
	UBRR0H = (unsigned char) 0x00;
	UCSR0B = ((1<<TXEN0) | (1<<RXEN0) | (1<<RXCIE0));
	sei();
}


ISR(USART_RX_vect){
	cli();
	static unsigned char i;
	char buffer[50];
	char data = UDR0;
	if(i<45){
		if(data == ENTER || data == '\n'){ 
			buffer[i] = '\0';
			printf("\n");
			i=0;
		}
		else if(data==BACKSPACE){
			UDR0= data;
			if(i>0){
				i--;
			}
			else i=0;
			buffer[i] = '\0';
		}
		else{
			buffer[i] = data;
			UDR0 = data;
			i++;
		}
	}
	else{
		printf("przekroczono max ilosc znakow /n/r");
		i=0;
	}
	sei();
}