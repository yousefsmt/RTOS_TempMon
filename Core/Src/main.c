#include "FreeRTOSTasks.h"

#include "flash.h"
#include "rcc.h"
#include "gpio.h"

#include "sense.h"

#ifdef DEBUG
	#include "usart.h"
	extern int printf(const char *format, ...);
	#define LOG( msg... ) printf( msg );
#else
	#define LOG( msg... ) ;
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
	#endif /* DEBUG */

	LOG( "Peripherals Init" );
	/*---------------------------------------------------------------------------*/
	BaseType_t xReturned;

	xReturned = xTaskCreate( vStartupTask, "StartUp", tasksSTARTUP_STACK_SIZE, NULL, tasksSTARTUP_STACK_PRIORITY, NULL );
	configASSERT ( xReturned == pdPASS );

	/*---------------------------------------------------------------------------*/

	vTaskStartScheduler();

	for ( ;; )

	return 0;
}
/*---------------------------------------------------------------------------*/
void vStartupTask( void *pvParameters )
{
	( void )pvParameters;

	BaseType_t xReturned;

	xReturned = xTaskCreate( vSenseStartSensing, "Sense", tasksSENSE_START_STACK_SIZE, NULL, tasksSENSE_START_STACK_PRIORITY, NULL );
	configASSERT ( xReturned == pdPASS );

	LOG( "StartUp Done" );

	vTaskDelete( NULL );
}