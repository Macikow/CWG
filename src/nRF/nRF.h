/*
 * nRF.h
 *
 * Created: 2015-06-17 21:56:47
 *  Author: Macikow
 */ 


#ifndef NRF_H_
#define NRF_H_


void nRF_WriteRegister(unsigned char nAddress, unsigned char nData);
unsigned char nRF_ReadRegister(unsigned char nAddress);


#endif /* NRF_H_ */