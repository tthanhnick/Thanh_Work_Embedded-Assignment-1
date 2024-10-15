#define SET_BIT 1U
#define CLEAR_BIT 0U

#define PCC_PORTA (0x40065000u + 0x124u) //Peripheral Clock PORT A
#define PCC_PORTB (0x40065000u + 0x128u) //Peripheral Clock PORT B 
#define PCC_PORTC (0x40065000u + 0x12Cu) //Peripheral Clock PORT C 
#define PCC_PORTD (0x40065000u + 0x130u) //Peripheral Clock PORT D 

#define CLOCK_GATE_CONTROL 30U

#define PORTA (0x40049000u) // PORT A
#define PORTB (0x4004A000u) // PORT B
#define PORTC (0x4004B000u) // PORT C 
#define PORTD (0x4004C000u) // PORT D

#define PORT_PCR0 (0x0u)
#define PORT_PCR1 (0x4u)
#define PORT_PCR2 (0x8u)
#define PORT_PCR3 (0xCu)
#define PORT_PCR4 (0x10u)
#define PORT_PCR5 (0x14u)
#define PORT_PCR6 (0x18u)
#define PORT_PCR7 (0x1Cu)
#define PORT_PCR8 (0x20u)
#define PORT_PCR9 (0x24u)
#define PORT_PCR10 (0x28u)
#define PORT_PCR11 (0x2Cu)
#define PORT_PCR12 (0x30u)
#define PORT_PCR13 (0x34u)
#define PORT_PCR14 (0x38u)
#define PORT_PCR15 (0x3Cu)
#define PORT_PCR16 (0x40u)
#define PORT_PCR17 (0x44u)
#define PORT_PCR18 (0x48u)
#define PORT_PCR19 (0x4Cu)
#define PORT_PCR20 (0x50u)
#define PORT_PCR21 (0x54u)
#define PORT_PCR22 (0x58u)
#define PORT_PCR23 (0x5Cu)
#define PORT_PCR24 (0x60u)
#define PORT_PCR25 (0x64u)
#define PORT_PCR26 (0x68u)
#define PORT_PCR27 (0x6Cu)
#define PORT_PCR28 (0x70u)
#define PORT_PCR29 (0x74u)
#define PORT_PCR30 (0x78u)
#define PORT_PCR31 (0x7Cu)

#define MUX 8u
#define GPIO_MODE 1u
#define DIRECT_INPUT 0u
#define DIRECT_OUTPUT 1u

#define ISQ_ENABLE 1u
#define ISQ_DISABLE 0u
#define IRQC 16u
#define INTERRUPT_BOTH_EDGE 11u
#define NVIC_INTERRUPT (0xE000E100u + 4*1) // NVIC Interrupt 

#define GPIOA (0x400FF000u)
#define GPIOB (0x400FF040u)
#define GPIOC (0x400FF080u)
#define GPIOD (0x400FF0C0u)
#define GPIOE (0x400FF100u)

#define PDDR 0x14u
#define PDOR 0x0u
#define PDIR 0x10u

#define LEVEL_HIGH 1
#define LEVEL_LOW 0

void SetOrClearBit(unsigned int *address, unsigned char position, unsigned char action);
void SetOrClearMultiBit(unsigned int *address, unsigned char position, unsigned int mask, unsigned char action);

void Gpio_Init(unsigned int pccPort);
void Gpio_SetMode(unsigned int port, unsigned int portPin, unsigned int gpioPort,  unsigned int gpioPin, unsigned int directStatus, unsigned int irqStatus);
void Gpio_WriteChannel(unsigned int gpioPort, unsigned int gpioPin, unsigned int outputLevel);
unsigned int Gpio_ReadChannel(unsigned int gpioPort, unsigned int gpioPin);
