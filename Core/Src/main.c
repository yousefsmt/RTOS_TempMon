#include "flash.h"
#include "rcc.h"
#include "gpio.h"

#define WAITE_STATE (0x00U) /* True latency for HSI (8MHz) SYSCLK clock */

int main( void )
{
	FLASH_ConfigWaitState( WAITE_STATE );

	RCC_Init();

	SystemCoreClockUpdate();

	GPIO_Init();

	while (1)
	{
		
	}
	
}