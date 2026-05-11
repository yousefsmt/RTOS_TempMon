#ifndef FREERTOS_TASKS_H
#define FREERTOS_TASKS_H

#include "FreeRTOS.h"
#include "task.h"

#define tasksSTARTUP_STACK_SIZE               ( 128 )
#define tasksSTARTUP_STACK_PRIORITY           (configMAX_PRIORITIES - 1 )

#define tasksSENSE_START_STACK_SIZE           ( 128 )
#define tasksSENSE_START_STACK_PRIORITY       (configMAX_PRIORITIES - 1 )

#define tasksERROR_HANDLER_STACK_SIZE         ( 128 )
#define tasksERROR_HANDLER_STACK_PRIORITY     ( configMAX_PRIORITIES - 2 )

#define tasksSENSE_HUMIDITY_STACK_SIZE        ( 128 )
#define tasksSENSE_HUMIDITY_STACK_PRIORITY    ( configMAX_PRIORITIES - 3 )

#define tasksSENSE_TEMPERATURE_STACK_SIZE     ( 128 )
#define tasksSENSE_TEMPERATURE_STACK_PRIORITY ( configMAX_PRIORITIES - 3 )

#define tasksSENSE_LCD_STACK_SIZE             ( 128 )
#define tasksSENSE_LCD_STACK_PRIORITY         ( configMAX_PRIORITIES - 4 )

#endif /* FREERTOS_TASKS_H */