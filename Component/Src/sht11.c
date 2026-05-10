#include "FreeRTOSTasks.h"
#include "sht11.h"

static const TickType_t xDelay1ms = pdMS_TO_TICKS(1);

void SHT11_StartTransmission(void)
{
    SHT11_DataOut();    

    SHT11_DATA_HIGH();
    SHT11_SCK_LOW();
	vTaskDelay( xDelay1ms );

    SHT11_SCK_HIGH();
	vTaskDelay( xDelay1ms );

    SHT11_DATA_LOW();
	vTaskDelay( xDelay1ms );

    SHT11_SCK_LOW();
	vTaskDelay( xDelay1ms );

    SHT11_SCK_HIGH();
	vTaskDelay( xDelay1ms );

    SHT11_DATA_HIGH();
	vTaskDelay( xDelay1ms );

    SHT11_SCK_LOW();
	vTaskDelay( xDelay1ms );
}

static uint8_t SHT11_ReadByte(uint8_t ack)
{
    uint8_t data = 0;

    SHT11_DataIn();   // ensure input

    for (int i = 0; i < 8; i++)
    {
        data <<= 1;

        SHT11_SCK_HIGH();
		vTaskDelay( xDelay1ms );

        data |= SHT11_DATA_READ();

        SHT11_SCK_LOW();
		vTaskDelay( xDelay1ms );
    }

    // ACK phase
    SHT11_DataOut();

    if (ack == SHT11_ACK)
        SHT11_DATA_LOW();
    else
        SHT11_DATA_HIGH();

	vTaskDelay( xDelay1ms );

    SHT11_SCK_HIGH();
	vTaskDelay( xDelay1ms );
    SHT11_SCK_LOW();
	vTaskDelay( xDelay1ms );

    SHT11_DATA_HIGH();   // release line
    SHT11_DataIn();

    return data;
}

uint32_t SHT11_ReadData(void)
{
    uint32_t timeout = 250000; // ~250ms

    SHT11_DataIn();

    while (SHT11_DATA_READ() && timeout--)
	{
		vTaskDelay( xDelay1ms );
	}

    if (timeout == 0)
	{
        return 0xFFFF;
	}

    uint32_t msb = SHT11_ReadByte(SHT11_ACK);
    uint32_t lsb = SHT11_ReadByte(SHT11_NACK);

    return (msb << 8) | lsb;
}

void SHT11_SendCommand(uint32_t cmd)
{
    SHT11_StartTransmission();
    SHT11_DataOut();

    for (int idx = 7; idx >= 0; idx--)
    {
        if (cmd & (1U << idx))
            SHT11_DATA_HIGH();
        else
            SHT11_DATA_LOW();

		vTaskDelay( xDelay1ms );

        SHT11_SCK_HIGH();
		vTaskDelay( xDelay1ms );
        SHT11_SCK_LOW();
		vTaskDelay( xDelay1ms );
    }

    // Release DATA for ACK
    SHT11_DATA_HIGH();
    SHT11_DataIn();

	vTaskDelay( xDelay1ms );

    // ACK clock
    SHT11_SCK_HIGH();
	vTaskDelay( xDelay1ms );

    if ((SHT11_DATA_PIN->IDR & SHT11_DATA_BIT) == SHT11_NACK)
    {
        // LCD_ExecuteCommand(CLEAN_DISPLAY);
        // LCD_PrintString("error cmd");
    }

    SHT11_SCK_LOW();
	vTaskDelay( xDelay1ms );
}

void SHT11_DataIn()
{
    SHT11_DATA_RESET_PIN();
    SHT11_DATA_IN();
}

void SHT11_DataOut()
{
    SHT11_DATA_RESET_PIN();
    SHT11_DATA_OUT();
}