#ifndef __GPIO_H
#define __GPIO_H

#include "mcu.h"

/**
 * @brief Initialize and configure the GPIO peripheral
 * @param none
 * @return none
 * 
 * Enable APB2 clock for GPIOA, GPIOB with HSI
 */
void GPIO_Init( void );

#endif /* __GPIO_H */