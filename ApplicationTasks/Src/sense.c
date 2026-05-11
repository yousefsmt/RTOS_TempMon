#include "FreeRTOSTasks.h"

#include "sense.h"
#include "sht11.h"
#include "hd44780.h"

#include "queue.h"

#define senseTOTAL_MESSAGE ( 10 )
#define senseSIZE_MESSAGE  sizeof( SenseMeas_t )

static QueueHandle_t queue_handler = NULL;

extern int snprintf( char *buf, unsigned int count, const char *format, ... );

/*--------------------------------------------------------------------------------------------*/
static inline float calculate_humidity( uint32_t value )
{
	const float c1 = -4.0f;
	const float c2 = 0.0405f;
	const float c3 = -2.5f * (1e-6);

	float so = ( float )value;
	float ret = c1 + (c2*so) + (c3*(so*so));

	return ret;
}
/*--------------------------------------------------------------------------------------------*/

static inline float calculate_temperature( uint32_t value )
{
	const float d1 = -39.66f;
	const float d2 = 0.01f;

	float so  = ( float )value;
	float ret = d1 + (d2*so);

	return ret;
}
/*--------------------------------------------------------------------------------------------*/

void vSenseMeasurement( void *pvParameters )
{
	LOG ( "SenseHumidity\n\r" );

	SenseMeas_t measure = {.humidity    = 0.0f,
						   .temperature = 0.0f };
	uint32_t    value   = 0x00U;

	while ( 1 )
	{
		SHT11_SendCommand( SHT11_MEASURE_HUMIDITY );
		value = SHT11_ReadData();
		measure.humidity = calculate_humidity( value );
		SHT11_SendCommand( SHT11_MEASURE_TEMPERATURE );
		value = SHT11_ReadData();
		measure.temperature = calculate_temperature( value );
		if (xQueueSend( queue_handler, &measure, portMAX_DELAY ) != pdTRUE)
		{
			LOG ( "SensingFailed\n\r" );
		}
		vTaskDelay( pdMS_TO_TICKS(500) );
	}
}
/*--------------------------------------------------------------------------------------------*/

void vSenseLCDShow( void *pvParameters )
{
	LOG ( "SenseLCD\n\r" );

	SenseMeas_t measure = {.humidity    = 0.0f,
						   .temperature = 0.0f };
	char buffer[12] = {0};

	while ( 1 )
	{
		if (xQueueReceive(queue_handler, &measure, portMAX_DELAY) == pdTRUE)
		{

			snprintf(buffer, 12, "%f", measure.temperature);
			LCD_ExecuteCommand(LCD_1ST_LINE + 7);
			LCD_PrintString(buffer);

			snprintf(buffer, 12, "%f", measure.humidity);
			LCD_ExecuteCommand(LCD_2ND_LINE + 10);
			LCD_PrintString(buffer);
		}
	}
}
/*--------------------------------------------------------------------------------------------*/

void vSenseStartSensing( void *pvParameters )
{
	LOG( "StartSensing\n\r" );

	queue_handler = xQueueCreate( ( UBaseType_t )senseTOTAL_MESSAGE, senseSIZE_MESSAGE );
	if (queue_handler == NULL)
	{
		LOG( "QueueFailed\n\r" );
		while (1)
		{
		}
	}

	LCD_ExecuteCommand( CLEAN_DISPLAY );

	LCD_ExecuteCommand(LCD_1ST_LINE + 0x01U);
	LCD_PrintString("Temp: ");

	LCD_ExecuteCommand(LCD_2ND_LINE + 0x01U);
	LCD_PrintString("Humidity: ");

	BaseType_t xReturned;

	xReturned = xTaskCreate( vSenseMeasurement, "Hum", tasksSENSE_MEASURE_STACK_SIZE, NULL, tasksSENSE_MEASURE_STACK_PRIORITY, NULL );
	configASSERT ( xReturned == pdPASS );

	xReturned = xTaskCreate( vSenseLCDShow, "LCD", tasksSENSE_LCD_STACK_SIZE, NULL, tasksSENSE_LCD_STACK_PRIORITY, NULL );
	configASSERT ( xReturned == pdPASS );

	vTaskDelete( NULL );
}
/*--------------------------------------------------------------------------------------------*/