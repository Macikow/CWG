/*
 * nRF.c
 *
 * Created: 2015-06-17 20:38:19
 *  Author: Macikow
 */ 
#include "../spi/spi.h"
#include <stdio.h>

#define R_REGISTER 0x00
#define W_REGISTER 0x20
#define EMPTY_MEESAGE 0xff
void nRF_WriteRegister(unsigned char nAddress, unsigned char nData);
unsigned char nRF_ReadRegister(unsigned char nAddress);



void nRF_WriteRegister(unsigned char nAddress, unsigned char nData){
	
	SPI_MasterTransmit(nAddress | W_REGISTER);
}
unsigned char nRF_ReadRegister(unsigned char nAddress){
	SPI_MasterTransmit(nAddress | R_REGISTER);
	SPI_MasterTransmit(EMPTY_MEESAGE);
	return SPI_MasterRead();
}