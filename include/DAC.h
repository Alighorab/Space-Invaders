#ifndef DAC_h
#define DAC_h

#include "tm4c123gh6pm.h"

/* **************DAC_Init********************* */
/* Initialize 4-bit DAC  */
/* Input: none */
/* Output: none */
void DAC_Init(void);

/* **************DAC_Out********************* */
/* output to DAC */
/* Input: 4-bit data, 0 to 15  */
/* Output: none */
void DAC_Out(unsigned long data);

#endif
