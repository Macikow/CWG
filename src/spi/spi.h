/*
 * spi.h
 *
 * Created: 2015-06-17 20:47:46
 *  Author: Macikow
 */ 


#ifndef SPI_H_
#define SPI_H_

void SPI_MasterInit(void);
void SPI_MasterTransmit(unsigned char data);
unsigned char SPI_MasterRead(void);
void SPI_CSNHigh(void);
void SPI_CSNLow(void);


#endif /* SPI_H_ */