#include "FreeRTOSTasks.h"

#include "flash.h"
#include "rcc.h"
#include "gpio.h"

#include "sense.h"

#ifdef DEBUG
	#include "usart.h"
#endif /* DEBUG */

#define mainWAITE_STATE ( 0x00U ) /* True latency for HSI (8MHz) SYSCLK clock */

void vStartupTask( void *pvParameters );

/*---------------------------------------------------------------------------*/
int main( void )
{
	FLASH_ConfigWaitState( mainWAITE_STATE );

	RCC_Init();

	SystemCoreClockUpdate();

	GPIO_Init();

	#ifdef DEBUG
		const uint32_t baud_rate = 115200U;
		USART_Init( baud_rate );
		LOG( "Peripherals Init\n\r" );
		BaseType_t xReturned;
	
		xReturned = xTaskCreate( vStartupTask, "StartUp", tasksSTARTUP_STACK_SIZE, NULL, tasksSTARTUP_STACK_PRIORITY, NULL );
		configASSERT ( xReturned == pdPASS );
	#else
		( void )xTaskCreate( vStartupTask, "StartUp", tasksSTARTUP_STACK_SIZE, NULL, tasksSTARTUP_STACK_PRIORITY, NULL );
	#endif /* DEBUG */

	vTaskStartScheduler();

	for ( ;; )

	return 0;
}

/*---------------------------------------------------------------------------*/
void vStartupTask( void *pvParameters )
{
	( void )pvParameters;

	#ifdef DEBUG
		BaseType_t xReturned;

		xReturned = xTaskCreate( vSenseStartSensing, "Sense", tasksSTARTUP_STACK_SIZE, NULL, tasksSTARTUP_STACK_PRIORITY, NULL );
		configASSERT ( xReturned == pdPASS );
	#else
		( void )xTaskCreate( vSenseStartSensing, "Sense", tasksSTARTUP_STACK_SIZE, NULL, tasksSTARTUP_STACK_PRIORITY, NULL );
	#endif /* DEBUG */

	LOG( "StartUpDone\n\r" );

	vTaskDelete( NULL );
}
/*--------------------------------------------------------------------------------------------*/