/********************************************************************
 * Copyright (C) 2009, 2012 by Verimag                              *
 * Initial author: Matthieu Moy                                     *
 ********************************************************************/

/*!
  \file hal.h
  \brief Harwdare Abstraction Layer : implementation for MicroBlaze
  ISS.


*/
#ifndef HAL_H
#define HAL_H

#include <stdint.h>
#include <stdio.h>


/* Dummy implementation of abort(): invalid instruction */
#define abort() do {				\
	printf("abort() function called\r\n");  \
	_hw_exception_handler();		\
} while (0)

/* TODO: implement HAL primitives for cross-compilation */
#define hal_read32(a)      ({uint32_t retval;		    \
			retval = *(volatile uint32_t *)(a); \
			retval;});
#define hal_write32(a, d)  *(volatile uint32_t *) (a) = d
#define hal_wait_for_irq() ({})
#define hal_cpu_relax()    ({})

void microblaze_enable_interrupts(void) {
	__asm("ori     r3, r0, 2\n"
	      "mts     rmsr, r3");
}

/* TODO: printf is disabled, for now ... */
#define printf(str) do {				\
	uint32_t compt = 0;				\
	while (str[compt] != '\0') {					\
		hal_write32(UART_BASEADDR + UART_FIFO_WRITE, str[compt]); \
		compt++;						\
	}								\
	} while(0)
#endif /* HAL_H */
