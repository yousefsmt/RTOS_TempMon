#include "FreeRTOSTasks.h"

#include "flash.h"
#include "rcc.h"
#include "gpio.h"

#define WAITE_STATE (0x00U) /* True latency for HSI (8MHz) SYSCLK clock */

void StartTask( void *param );

int main( void )
{
	FLASH_ConfigWaitState( WAITE_STATE );

	RCC_Init();

	SystemCoreClockUpdate();

	GPIO_Init();

	( void )xTaskCreate(StartTask, "Task1", STARTUP_STACK_SIZE, NULL, STARTUP_STACK_PRIORITY, NULL);

	return 0;
}

void StartTask( void *param )
{
	( void )param;

	while (1)
	{
		GPIOB->BSRR |= GPIO_BSRR_BS15;
		vTaskDelay(pdMS_TO_TICKS(500));

		GPIOB->BRR |= GPIO_BRR_BR15;
		vTaskDelay(pdMS_TO_TICKS(500));
	}
}