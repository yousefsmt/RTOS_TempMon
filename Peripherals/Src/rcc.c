#include "rcc.h"
#include "stm32f103xb.h"

/**
 * @brief Initialize and configure the Reset and Clock Control (RCC) peripheral
 * @param none
 * @return none
 * 
 * This function sets up the system clock
 */
void RCC_Init( void )
{
	/* Use double-word aligned memory */
	SCB->CCR |= SCB_CCR_STKALIGN_Msk;

	RCC->CR |= RCC_CR_HSION;
	while ((RCC->CR & RCC_CR_HSIRDY) == 0)
	{
		__NOP();
	}

	/* Switch SYSCLK to HSI first (safe fallback) */
    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_HSI;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI)
	{
		__NOP();
	}

	/* PLL Off, HSE Off */
	RCC->CR &= ~( RCC_CR_PLLON | RCC_CR_HSEON | RCC_CR_CSSON );
	while ( ( RCC->CR & ( RCC_CR_PLLRDY | RCC_CR_HSERDY ) ) != 0)
	{
		__NOP();
	}

	RCC->CFGR &= ~( RCC_CFGR_MCO | RCC_CFGR_USBPRE | RCC_CFGR_PLLMULL |
					RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLSRC | RCC_CFGR_ADCPRE |
					RCC_CFGR_PPRE2 | RCC_CFGR_PPRE1 | RCC_CFGR_HPRE );
}