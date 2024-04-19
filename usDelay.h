/*
 * usDelay.h
 *
 * Simple microsecond delay function
 * using a general purpose timer.
 *
 */

#ifndef INC_USDELAY_H_
#define INC_USDELAY_H_

#include <stdint.h>

void usDelayInit(void);
void usDelay(uint32_t us);


#endif /* INC_USDELAY_H_ */
