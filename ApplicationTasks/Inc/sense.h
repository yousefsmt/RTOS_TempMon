/*
 * error.h
 *
 * Contains the type definition for error_t.
 */

#ifndef APPLICATION_TASKS_SENSE_H_
#define APPLICATION_TASKS_SENSE_H_

typedef struct
{
	float temperature;
	float humidity;
}SenseMeas_t;

void vSenseHumidity( void *pvParameters );
void vSenseTemperature( void *pvParameters );
void vSenseLCDShow( void *pvParameters );
void vSenseStartSensing( void *pvParameters );

#endif /* APPLICATION_TASKS_SENSE_H_ */
