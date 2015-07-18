/*
 * spi.c
 *
 * Created: 2015-06-17 20:47:36
 *  Author: Macikow
 */ 
#include <avr/io.h>
#define DD_MOSI 3
#define DD_MISO 4
#define DD_SCK 5
#define DD_CSN 0
#define PIN_CSN 0
#define CSN_HIGH (PORTB |= (1<<PIN_CSN)) 	
#define CSN_LOW	 (PORTB &= ~(1<<PIN_CSN)) 	


/************************************************************************/
/* inicjacja SPI 
	Wyjœcia SS nie u¿ywam
	jako wyjœcia enable u¿ywam CSN na PB0                                                              */
/************************************************************************/
void SPI_MasterInit(void){
	DDRB |= (1<<DD_MOSI) | (1<<DD_SCK) | (1<<DD_CSN);
	SPCR |= (1<<SPE) | (1<<MSTR) | (1<<SPR1) ;
	CSN_HIGH; // high when idle
}
void SPI_MasterTransmit(unsigned char data){
	//CSN_LOW;
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	//CSN_HIGH;
}
unsigned char SPI_MasterRead(void){
	return SPDR;
}
void SPI_CSNHigh(void){
	CSN_HIGH;
}
void SPI_CSNLow(void){
	CSN_LOW;
}