#include "FreeRTOSConfig.h"
#include "FreeRTOSTasks.h"
#include "mcu.h"


static void Startup( void *arg );
// static void StartupTask( void *param );

int main()
{
	SystemCoreClockUpdate();

	Startup(NULL);

	vTaskStartScheduler();

	while (1)
	{

	}
	
}

static void Startup( void *arg )
{
	configASSERT(pdPASS == xTaskCreate(Startup, "Task1", STARTUP_STACK_SIZE, NULL, STARTUP_STACK_PRIORITY, NULL));


}

// static void StartupTask( void *param )
// {
// 	vTaskDelete(NULL);

// }