#include "flash.h"
#include "rcc.h"

#define WAITE_STATE (0x00U)

int main()
{
	FLASH_ConfigWaitState(WAITE_STATE);

	RCC_Init();
}