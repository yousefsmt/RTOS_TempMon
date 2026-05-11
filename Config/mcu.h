#ifndef CONFIG_MCU_H_
#define CONFIG_MCU_H_

#include "stm32f1xx.h"

#ifdef DEBUG
	extern int printf(const char *format, ...);
	#define LOG( msg... ) printf( msg );
#else
	#define LOG( msg... ) ;
#endif /* DEBUG */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#endif /* CONFIG_MCU_H_ */