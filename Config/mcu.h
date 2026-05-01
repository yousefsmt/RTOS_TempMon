#ifndef __MCU_H
#define __MCU_H

#include "stm32f1xx.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#endif /* __MCU_H */