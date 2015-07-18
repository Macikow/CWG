/*
 * measure.c
 *
 * Created: 2015-06-06 18:56:15
 *  Author: Macikow
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

void ampInit(void);

#define AMP_POWER_SWITCH_PORT PORTB
#define AMP_ON (AMP_POWER_SWITCH_PORT &= (0 << 7))
#define AMP_OFF (AMP_POWER_SWITCH_PORT |= (1 << 7))

#define AMP_PORT PORTD
#define AMP1_ON (AMP_PORT &= (0 << 7))
#define AMP2_ON (AMP_PORT &= (0 << 6))
#define AMP3_ON (AMP_PORT &= (0 << 5))
#define AMP4_ON (AMP_PORT &= (0 << 4))


#define AMP1_OFF (AMP_PORT |= (1 << 7))
#define AMP2_OFF (AMP_PORT |= (1 << 6))
#define AMP3_OFF (AMP_PORT |= (1 << 5))
#define AMP4_OFF (AMP_PORT |= (1 << 4))


void ampInit(void){
	DDRB |= 0xC0;
	DDRD |= 0xf0;
	PORTD =0x00;
	DDRC = 0x00;
	PORTC = 0x00;
	//AMP_ON;
}