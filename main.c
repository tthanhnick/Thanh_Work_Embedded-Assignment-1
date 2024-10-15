#include "header.h"

int main(void)
{
	//Signal is set to pin
	Gpio_Init(PCC_PORTA);
	Gpio_SetMode(PORTA, PORT_PCR0, GPIOA,  0, DIRECT_INPUT, ISQ_DISABLE);
	Gpio_WriteChannel(GPIOA, 0, LEVEL_HIGH);
		
	//Signal is get successfully
	Gpio_Init(PCC_PORTB);
	Gpio_SetMode(PORTB, PORT_PCR2, GPIOB,  2, DIRECT_OUTPUT, ISQ_DISABLE);
	Gpio_ReadChannel(GPIOB, 2);
	
	while(1)
	{
		
	}
}

