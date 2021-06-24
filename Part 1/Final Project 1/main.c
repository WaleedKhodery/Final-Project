
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "CPU_CONFIGURATION.h"
#include "SPI.h"
#include "SPI_CONFIG.h"
#include "UART.h"
#include "UART_CONFIG.h"
#include "DIO.h"
#include "DIO_CONFIG.h"
#include "util/delay.h"
#define F_CPU 16000000UL

int main(void)
{
	SPI_INIT();
	SPI_SLAVESELECT(0);
	UART_Init();

	DIO_SetPin_Direction(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);
	DIO_SetPin_Direction(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);

	Uint8t data;
	while (1)
	{
		data = UART_Receive();
		SPI_TRANSMIT(data);
		_delay_ms(150);
	}

	return 0;
}

