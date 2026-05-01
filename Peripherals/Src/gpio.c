#include "gpio.h"
#include "stm32f103xb.h"

void GPIO_Init( void )
{
	/* Enable clock for GPIOA and GPIOB */
	RCC->APB2ENR |= ( RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN );

	LCD_DATA_PORT->CRH &= ~( 0x03 << GPIO_CRH_CNF8_Pos  |
						     0x03 << GPIO_CRH_CNF9_Pos  |
						     0x03 << GPIO_CRH_CNF10_Pos |
						     0x03 << GPIO_CRH_CNF11_Pos );

	LCD_CTRL_PORT->CRH &= ~( GPIO_CRH_CNF14 | GPIO_CRH_CNF15 );
							 
	SHT11_DATA_PIN->CRL &= ~(GPIO_CRL_MODE0 | GPIO_CRL_CNF0);
	SHT11_SCK_PIN->CRL  &= ~(GPIO_CRL_MODE1 | GPIO_CRL_CNF1);

	LCD_DATA_PORT->CRH |= ( 0x01 << GPIO_CRH_MODE8_Pos  |
							0x01 << GPIO_CRH_MODE9_Pos  |
							0x01 << GPIO_CRH_MODE10_Pos |
							0x01 << GPIO_CRH_MODE11_Pos );

	LCD_CTRL_PORT->CRH |= ( 0x01 << GPIO_CRH_MODE14_Pos |
							0x01 << GPIO_CRH_MODE15_Pos );

	SHT11_DATA_PIN->CRL |= ( GPIO_CRL_MODE0_1 | GPIO_CRL_CNF0_0 );
    SHT11_SCK_PIN->CRL  |=   GPIO_CRL_MODE1_1;

}