#include <stdio.h>
#include "FreeRTOSTasks.h"

#include "sense.h"
#include "sht11.h"
#include "hd44780.h"

void vSenseHumidity( void *pvParameters )
{
	( void )pvParameters;
	char     num_str[12UL] = {0};
	uint32_t ret           = 0x00U;
	SHT11_SendCommand(SHT11_MEASURE_HUMIDITY);
    ret = SHT11_ReadData();
    if (ret == 0xffffU)
    {
      LCD_ExecuteCommand(CLEAN_DISPLAY);
      LCD_PrintString("SHT11 ERR");
    }
    else
    {
      sprintf(num_str, "%lu", ret);
      LCD_ExecuteCommand(LCD_1ST_LINE + 8);
      LCD_PrintString(num_str);
    }
}

void vSenseTemperature( void *pvParameters )
{
	( void )pvParameters;
	char     num_str[12UL] = {0};
	uint32_t ret           = 0x00U;
	SHT11_SendCommand( SHT11_MEASURE_TEMPERATURE );
    ret = SHT11_ReadData();
    if (ret == 0xffffU)
    {
      LCD_ExecuteCommand( CLEAN_DISPLAY );
      LCD_PrintString( "SHT11 ERR" );
    }
    else
    {
      sprintf( num_str, "%lu", ret );
      LCD_ExecuteCommand( LCD_1ST_LINE + 8 );
      LCD_PrintString( num_str );
    }

}