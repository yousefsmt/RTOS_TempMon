#ifndef PERIPHERALS_GPIO_H_
#define PERIPHERALS_GPIO_H_

#include "mcu.h"

/**
 * @brief Initialize and configure the GPIO peripheral
 * @param none
 * @return none
 * 
 * Enable APB2 clock for GPIOA, GPIOB with HSI
 */
void GPIO_Init( void );

#endif /* PERIPHERALS_GPIO_H_ */