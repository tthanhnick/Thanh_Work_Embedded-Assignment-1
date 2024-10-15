#include "header.h"

 void SetOrClearBit(unsigned int *address, unsigned char position, unsigned char action)
{
	if (action == SET_BIT)
	{
		*address |= (1U<<position);
	}
	else
	{
		*address &= ~(1U<<position);
	}
	return;
}

 void SetOrClearMultiBit(unsigned int *address, unsigned char position, unsigned int mask, unsigned char action)
{
	if (action == SET_BIT)
	{
		*address |= (mask<<position);
	}
	else
	{
		*address &= ~(mask<<position);
	}
	return;
}

void Gpio_Init(unsigned int pccPort)
{
	SetOrClearBit((unsigned int*) pccPort, CLOCK_GATE_CONTROL, SET_BIT);
}

void Gpio_SetMode(unsigned int port, unsigned int portPin, unsigned int gpioPort,  unsigned int gpioPin, unsigned int directStatus, unsigned int irqStatus)
{
	SetOrClearMultiBit((unsigned int*) (port + portPin), MUX, GPIO_MODE, SET_BIT); //GPIO Mode
	
	if (directStatus == DIRECT_OUTPUT)
	{
		SetOrClearBit((unsigned int*) (gpioPort + PDDR), gpioPin, SET_BIT); // Direction setting
	}
	else
	{
		SetOrClearBit((unsigned int*) (gpioPort + PDDR), gpioPin, CLEAR_BIT); // Direction setting
	}
	
	if (irqStatus == ISQ_ENABLE)
	{
		SetOrClearMultiBit((unsigned int*) (port + portPin), IRQC, INTERRUPT_BOTH_EDGE, SET_BIT); // Interrupt Request
		SetOrClearBit((unsigned int*) NVIC_INTERRUPT, 29u, SET_BIT);
	}
	else
	{
		SetOrClearMultiBit((unsigned int*) (port + portPin), IRQC, INTERRUPT_BOTH_EDGE, CLEAR_BIT); // Interrupt Request
		SetOrClearBit((unsigned int*) NVIC_INTERRUPT, 29u, CLEAR_BIT);
	}
}

void Gpio_WriteChannel(unsigned int gpioPort, unsigned int gpioPin, unsigned int outputLevel)
{
	unsigned int state = ((*(unsigned int*)(gpioPort+PDIR)) & (1 << gpioPin));
	if (state)
	{
		SetOrClearBit((unsigned int*) (gpioPort + PDDR), gpioPin, SET_BIT); // Direction setting to Output
		if (outputLevel == LEVEL_HIGH)
		{
			SetOrClearBit((unsigned int*) (gpioPort+PDOR), gpioPin, SET_BIT);
		}
		else
		{
			SetOrClearBit((unsigned int*) (gpioPort+PDOR), gpioPin, CLEAR_BIT);
		}
	}
}

unsigned int Gpio_ReadChannel(unsigned int gpioPort, unsigned int gpioPin)
{
	unsigned int state = ((*(unsigned int*) (gpioPort + PDOR)) & (1 << gpioPin));
	if (state)
	{
		SetOrClearBit((unsigned int*) (gpioPort + PDDR), gpioPin, CLEAR_BIT); // Direction setting to Input
		unsigned int level = ((*(unsigned int*) (gpioPort + PDIR)) & (1 << gpioPin));
		return level;
	}
	else
	{
		return 0;
	}
}

