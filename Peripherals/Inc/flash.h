#ifndef PERIPHERALS_FLASH_H_
#define PERIPHERALS_FLASH_H_

#include "mcu.h"

/**
 * @brief Initialize and configure prefetch buffer
 * @param none
 * @return none
 * 
 * This function sets up the prefetch buffer and latency between CPU and Flash memory, with wait state setting.
 */
void FLASH_ConfigWaitState( uint32_t latency );

#endif /* PERIPHERALS_FLASH_H_ */