# STM32_usDelay
Simple, bare-metal microsecond delay functionality for STM32 MCUs using a general purpose timer. 
Allows for accurate microsecond delays, compared to HAL_Delay()'s 1ms resolution. 

## Usage
* Include "usDelay.h" in your main.c
* Initialize usDelay using usDelayInit()
* Use usDelay() to create microsecond delays
## Demo
```c
#include "usDelay.h"

int main(void) {

	usDelayInit();

	while (1) {

    usDelay(100);
		//...
	}
}
```
## Dependencies
* CMSIS for register definitions
