#include "gpio.h"

void GPIO_Init( void )
{
	/* Enable clock for GPIOA and GPIOB */
	RCC->APB2ENR |= ( RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN);
	/*----------------------------------------------------------------------------*/

	/* Clear MODE and CNF for LCD data pins */
	GPIOA->CRH &= ~( GPIO_CRH_CNF8  | GPIO_CRH_MODE8  |
					 GPIO_CRH_CNF9  | GPIO_CRH_MODE9  |
					 GPIO_CRH_CNF10 | GPIO_CRH_MODE10 |
					 GPIO_CRH_CNF11 | GPIO_CRH_MODE11  );

	/* Clear MODE and CNF for LCD RS, EN pins */
	GPIOB->CRH &= ~( GPIO_CRH_CNF14 | GPIO_CRH_MODE14 |
	                 GPIO_CRH_CNF15 | GPIO_CRH_MODE15  );

	/* Clear MODE and CNF for error handler */
	GPIOC->CRH &= ~( GPIO_CRH_CNF13 | GPIO_CRH_MODE13 );

	/* Clear MODE and CNF for data and sck sht11 handler */
	GPIOB->CRL &= ~(GPIO_CRL_MODE0 | GPIO_CRL_CNF0 |
	                GPIO_CRL_MODE1 | GPIO_CRL_CNF1 );
	/*----------------------------------------------------------------------------*/

	/* Set LCD data pin to push-pull and medium speed */
	GPIOA->CRH |= ( GPIO_CRH_MODE8_0  |
					GPIO_CRH_MODE9_0  |
					GPIO_CRH_MODE10_0 |
					GPIO_CRH_MODE11_0  );

	/* Set LCD RS, EN pin to push-pull and medium speed */
	GPIOB->CRH |= ( GPIO_CRH_MODE14_0 |
					GPIO_CRH_MODE15_0 );
	
	/* Set error handler pin to push-pull and medium speed */
	GPIOC->CRH |= GPIO_CRH_MODE13_0;

	/* Set SCK pin to push-pull and medium speed */
	/* Set DATA pin to open-drain for in and out pin and medium speed */
	GPIOB->CRL |= ( GPIO_CRL_MODE0_1 | GPIO_CRL_CNF0_0 ); /* DATA Pin*/
    GPIOB->CRL |= GPIO_CRL_MODE1_0; /* SCK Pin */

}