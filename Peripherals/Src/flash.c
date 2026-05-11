#include "flash.h"

void FLASH_ConfigWaitState( uint32_t wait_state )
{
	/* Reset flash access control register to the default value */
	FLASH->ACR &= ~( FLASH_ACR_PRFTBE | FLASH_ACR_HLFCYA | FLASH_ACR_LATENCY );

	/**
	* Enable prefetch buffer and latency for specific SYSCLK
	* 0  < SYSCLK < 24 MHz = 0x00;
	* 24 < SYSCLK < 48 MHz = 0x01;
	* 48 < SYSCLK < 72 MHz = 0x02;
	*/
	FLASH->ACR |= FLASH_ACR_PRFTBE;
	FLASH->ACR |= ( wait_state << FLASH_ACR_LATENCY_Pos );
}
/*--------------------------------------------------------------------------------------------*/