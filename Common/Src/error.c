#include <stdbool.h>

#include "error.h"

#include "gpio.h"
#include "queue.h"

static QueueHandle_t queue_handler                  = NULL;
static uint32_t      error_counts[TOTAL_ERROR_TYPE] = {0};
static bool          blink_activate                 = false;


static void vErrorLedBlink( void )
{
	if ( blink_activate == false )
	{
		blink_activate = true;
		for ( uint32_t i = 0; i < errorEVENT_BLINK_NUMBER; i++ )
		{
			GPIOC->BSRR = GPIO_BSRR_BS13;
			vTaskDelay( pdMS_TO_TICKS(errorEVENT_BLINK_DELAY) );

			GPIOC->BRR = GPIO_BRR_BR13;
			vTaskDelay( pdMS_TO_TICKS(errorEVENT_BLINK_DELAY) );
		}

		GPIOC->BSRR = GPIO_BSRR_BS13;
		blink_activate = false;
	}
}

void vErrorHandlerSendMessage( ErrorStatus_t error )
{

}

void vErrorHandlerSendMessageFromIsr( ErrorStatus_t error )
{

}

void vErrorHandlerSendTask( ErrorStatus_t error )
{

}

void vApplicationStackOverflowHook( TaskHandle_t xTask, char * pcTaskName )
{

}