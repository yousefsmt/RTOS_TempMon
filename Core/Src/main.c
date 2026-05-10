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
#endif // DEBUG

#define mainWAITE_STATE ( 0x00U ) /* True latency for HSI (8MHz) SYSCLK clock */

void vStartupTask( void *pvParameters );
/*---------------------------------------------------------------------------*/
int main( void )
{
	FLASH_ConfigWaitState( mainWAITE_STATE );

	RCC_Init();

	SystemCoreClockUpdate();

	GPIO_Init();

	/*---------------------------------------------------------------------------*/
	BaseType_t xReturned;

	xReturned = xTaskCreate( vStartupTask, "StartUp", STARTUP_STACK_SIZE, NULL, STARTUP_STACK_PRIORITY, NULL );
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

	xReturned = xTaskCreate( vSenseTemperature, "Temp", SENSE_TEMPERATURE_STACK_SIZE, NULL, SENSE_TEMPERATURE_STACK_PRIORITY, NULL );
	configASSERT ( xReturned == pdPASS );

	xReturned = xTaskCreate( vSenseHumidity, "Hum", SENSE_HUMIDITY_STACK_SIZE, NULL, SENSE_HUMIDITY_STACK_PRIORITY, NULL );
	configASSERT ( xReturned == pdPASS );

	vTaskDelete( NULL );
}