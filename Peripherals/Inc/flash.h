#ifndef __FLASH_H
#define __FLASH_H

#include "mcu.h"

/**
 * @brief Initialize and configure prefetch buffer
 * @param none
 * @return none
 * 
 * This function sets up the prefetch buffer and latency between CPU and Flash memory, with wait state setting.
 */
void FLASH_ConfigWaitState( uint32_t latency );

#endif /* __FLASH_H */