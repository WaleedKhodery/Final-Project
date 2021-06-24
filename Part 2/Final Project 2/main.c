
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

	DIO_SetPin_Direction(DIO_PORTC,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_SetPin_Direction(DIO_PORTC,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_SetPin_Direction(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);

	Uint8t Data_in;

	while(1)
	{
		SPI_RECEIVE(&Data_in);
		
		if (Data_in =='1')
		{
			CLR_BIT(PORTC,DIO_PIN2);
			CLR_BIT(PORTC,DIO_PIN1);
			SET_BIT(PORTC,DIO_PIN0);

		}
		else if(Data_in =='2')
		{
			CLR_BIT(PORTC,DIO_PIN0);
			CLR_BIT(PORTC,DIO_PIN2);
			SET_BIT(PORTC,DIO_PIN1);
		}
		else if(Data_in =='3')
		{
			CLR_BIT(PORTC,DIO_PIN0);
			CLR_BIT(PORTC,DIO_PIN1);
			SET_BIT(PORTC,DIO_PIN2);
		}
	}

	return 0;
}
