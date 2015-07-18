/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
 /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#define F_CPU 8000000UL
#include <asf.h>
#include <util/delay.h>
#include "../debug/debug.h"
#include "../measure/measure.h"
#include "../picopower/picopower.h"
#include "../spi/spi.h"
#include "../nRF/nRF.h"
#include <stdio.h>

#define PORT_LED PORTD
#define PIN_LED 3
static int uart_putchar(char c, FILE *stream);
static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL,_FDEV_SETUP_WRITE);

static int uart_putchar(char c, FILE *stream)
{
	if (c == '\n') uart_putchar('\r', stream);
	loop_until_bit_is_set(UCSR0A, UDRE0);
	UDR0 = c;
	return 0;
}


int main (void)
{
	// Insert system clock initialization code here (sysclk_init()).
	USART_init();
	stdout = &mystdout;
	DDRD=0x08;
	ampInit();
	board_init();
	SPI_MasterInit();
	printf(MT_CLS);
	printf("Rozpoczêcie programu");
	while(1){
		PORT_LED |= (1<<PIN_LED);
		
		_delay_ms(500);
		PORT_LED &= ~(1<<PIN_LED);
		_delay_ms(500);
	}

	// Insert application code here, after the board has been initialized.
}
