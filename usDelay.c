/*
 * usDelay.c
 *
 * Simple microsecond delay function
 * using a general purpose timer.
 *
 */

#include "stm32f767xx.h" //change to your MCU

//set such that timer runs at 1Mhz
#define TIM2_PSC 16 

void usDelayInit(void) {

	//enable APB1 bus clock for timer
	RCC->APB1ENR |= (RCC_APB1ENR_TIM2EN);

	//set timer prescaler
	TIM2->PSC = (TIM2_PSC - 1);

	//disable ARPE
	TIM2->CR1 &= ~(TIM_CR1_ARPE);

	//count upwards
	TIM2->CR1 &= ~(TIM_CR1_DIR);

	//enable timer
	TIM2->CR1 |= (TIM_CR1_CEN);

	//trigger update for prescaler to take effect
	TIM2->EGR |= (TIM_EGR_UG);

	//clear update interrupt flag
	TIM2->SR &= ~(TIM_SR_UIF);


}

void usDelay (uint32_t us) {

	//set period to max value
	TIM2->ARR = (0xFFFFF-1);

	//set timer to 0
	TIM2->CNT = 0;

	//delay while timer counts
	while (TIM2->CNT < us);

}

