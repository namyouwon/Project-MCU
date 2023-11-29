/*
 * buzzer.c
 *
 *  Created on: Nov 27, 2023
 *      Author: HaHuyen
 */

#include "buzzer.h"

uint8_t duty_cycle = 0;

void buzzer_init(){
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}

void buzzer_SetVolume(uint8_t _duty_cycle){
	duty_cycle = _duty_cycle;
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1,duty_cycle);
}
