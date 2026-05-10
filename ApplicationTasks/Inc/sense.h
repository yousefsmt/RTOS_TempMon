/*
 * error.h
 *
 * Contains the type definition for error_t.
 */

#ifndef APPLICATION_TASKS_SENSE_H_
#define APPLICATION_TASKS_SENSE_H_

static const TickType_t xDelay1ms = pdMS_TO_TICKS(1);

void vSenseHumidity( void *pvParameters );
void vSenseTemperature( void *pvParameters );

#endif /* APPLICATION_TASKS_SENSE_H_ */
