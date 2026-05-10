/*
 * error.h
 *
 * Contains the type definition for error_t.
 */

#ifndef COMMON_ERROR_H_
#define COMMON_ERROR_H_

#include "FreeRTOSTasks.h"

#define errorEVENT_BLINK_NUMBER ( 0x03UL )
#define errorEVENT_BLINK_DELAY  ( 0x64UL )

/**
 * Enumeration of error constants (to be expanded as required).
 */
typedef enum
{
  OK,
  FAIL,
  TIMEOUT,
  INVALID_PARAM,

  TOTAL_ERROR_TYPE
} ErrorStatus_t;

void vErrorHandlerSendMessage( ErrorStatus_t error );
void vErrorHandlerSendMessageFromIsr( ErrorStatus_t error );
void vErrorHandlerSendTask( ErrorStatus_t error );

#endif /* COMMON_ERROR_H_ */
