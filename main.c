#include "main.h" // definition of structures

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//RCC AHB1 peripheral clock register (RCC_AHB1ENR)////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define GPIOAEN		(1U<<0)
#define GPIOBEN		(1U<<1)
#define GPIOCEN		(1U<<2)
#define GPIODEN		(1U<<3)
#define GPIOEEN		(1U<<4)
#define GPIOFEN		(1U<<5)
#define GPIOGEN		(1U<<6)
#define GPIOHEN		(1U<<7)
#define GPIOIEN		(1U<<8)
#define GPIOJEN		(1U<<9)
#define GPIOKEN		(1U<<10)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//GPIO port output data register (GPIOx_ODR)//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define PIN0		(1U<<0)
#define PIN1		(1U<<1)
#define PIN2		(1U<<2)
#define PIN3		(1U<<3)
#define PIN4		(1U<<4)
#define PIN5		(1U<<5)
#define PIN6		(1U<<6)
#define PIN7		(1U<<7)
#define PIN8		(1U<<8)
#define PIN9		(1U<<9)
#define PIN10		(1U<<10)
#define PIN11		(1U<<11)
#define PIN12		(1U<<12)
#define PIN13		(1U<<13)
#define PIN14		(1U<<14)
#define PIN15		(1U<<15)


int main(void)
{
	RCC->AHB1ENR |=GPIOAEN; // activate RCC

	/* GPIO PortA pin 5 is set to output mode (0x01)*/
	GPIOA->MODER |=(1U<<10); // register 10 is set as high
	GPIOA->MODER &=~(1U<<11);	// register 11 is set as low

	GPIOA->MODER |=(1U<<12); // register 12 is set as high
	GPIOA->MODER &=~(1U<<13);	// register 13 is set as low

	while (1)
	{
		GPIOA->ODR ^= PIN5; // alternatively, you can use BSSRH and BSSRL registers to set and reset output registers.
		//GPIOA->BSRRH ^= PIN6;
	}
}
