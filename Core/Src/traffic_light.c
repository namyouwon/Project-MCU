/*
 * traffic_light.c
 *
 *  Created on: Oct 9, 2023
 *      Author: HaHuyen
 */

#include "traffic_light.h"

#define MANUAL_INIT			1
#define MANUAL_RED			2
#define MANUAL_GREEN		4
#define MANUAL_YELLOW		3

#define 	INIT			100
#define		PHASE_2_GREEN 	101 //Phase 1 red
#define		PHASE_2_YELLOW 	102 //Phase 1 red
#define  	PHASE_1_GREEN 	103 //Phase 2 red
#define 	PHASE_1_YELLOW	104 //Phase 2 red

#define TUNING_RED			10
#define TUNING_GREEN		11
#define TUNING_YELLOW		12

#define AUTOMATIC			15
#define MANUAL				16

uint8_t status_automation = INIT;
uint8_t count_red = 5;
uint8_t count_yellow = 2;
uint8_t count_green = 3;
uint8_t counter_normal = 0;
uint8_t num1 = 0, num2 = 0;

uint8_t status_manual = MANUAL_INIT;
uint8_t count_buffer = 0;

uint8_t flag_tuning = 0;
uint8_t count_tuning = 20;
uint8_t flag_color = 0;
uint8_t tog = 0;

uint8_t status_traffic  = AUTOMATIC;

void Phase1_GreenOn(){
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_SET);
}
void Phase1_RedOn(){
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
}
void Phase1_YellowOn(){
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
}

void Phase2_GreenOn(){
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_SET);
}
void Phase2_RedOn(){
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_RESET);
}
void Phase2_YellowOn(){
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_RESET);
}

void Pedes_GreenOn(){
	HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, GPIO_PIN_SET);
}
void Pedes_RedOn(){
	HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, GPIO_PIN_RESET);
}
void Pedes_YellowOn(){
	HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, GPIO_PIN_RESET);
}

void Pedes_Off(){
	HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, GPIO_PIN_RESET);
}
void Blink_Green(){
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_TogglePin(D7_GPIO_Port, D7_Pin);
}
void Blink_Red(){
	HAL_GPIO_TogglePin(D2_GPIO_Port, D2_Pin);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_RESET);
}
void Blink_Yellow(){
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_TogglePin(D6_GPIO_Port, D6_Pin);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_RESET);
}


void normal_trafic(){
	switch (status_automation){
	case INIT:
		counter_normal = count_green;
		num1 = count_red;
		num2 = count_green;
		status_automation = PHASE_2_GREEN;
		break;
	case PHASE_2_GREEN:
		counter_normal--;
		Phase2_GreenOn();
		Phase1_RedOn();
		flag_color = TUNING_GREEN;
		if (counter_normal <= 0){
			counter_normal = count_yellow;
			num1--;
			num2 = count_yellow;
			status_automation = PHASE_2_YELLOW;
			Phase2_YellowOn();
			Phase1_RedOn();
			flag_color = TUNING_YELLOW;
		}
		else{
			num1--;
			num2--;
		}
		break;
	case PHASE_2_YELLOW:
		counter_normal--;
		Phase2_YellowOn();
		Phase1_RedOn();
		flag_color = TUNING_YELLOW;
		if (counter_normal <= 0) {
			counter_normal = count_green;
			status_automation = PHASE_1_GREEN;
			num1 = count_green;
			num2 = count_red;
			Phase1_GreenOn();
			Phase2_RedOn();
			flag_color = TUNING_RED;
		}
		else{
			num1--;
			num2--;
		}
	break;
	case PHASE_1_GREEN:
		counter_normal--;
		Phase1_GreenOn();
		Phase2_RedOn();
		flag_color = TUNING_RED;
		if (counter_normal <= 0) {
			counter_normal = count_yellow;
			status_automation = PHASE_1_YELLOW;
			num1 = count_yellow;
			num2--;
			Phase1_YellowOn();
			Phase2_RedOn();
		}
		else{
			num1--;
			num2--;
		}
	break;
	case PHASE_1_YELLOW:
		counter_normal--;
		Phase1_YellowOn();
		Phase2_RedOn();
		flag_color = TUNING_RED;
		if (counter_normal <= 0) {
			counter_normal = count_green;
			status_automation = PHASE_2_GREEN;
			num1 = count_red;
			num2 = count_green;
			Phase2_GreenOn();
			Phase1_RedOn();
			flag_color = TUNING_GREEN;
		}
		else{
			num1--;
			num2--;
		}
	break;
	default:
		status_automation = INIT;
		break;
	}
	if(flag_tuning){
		count_tuning--;
	}
}

void manual_trafic(){
	switch (status_manual){
	case MANUAL_INIT:
		status_manual = MANUAL_RED;
		count_buffer = count_red;
	case MANUAL_RED:
		if(timer2_flag){
			setTimer2(50);
			Blink_Red();
		}
		if(isButtonMode()){
			status_manual = MANUAL_YELLOW;
			count_buffer = count_yellow;
		}
		if(isButtonTime()){
			count_buffer++;
		}
		if(isButtonEnter()){
			count_red = count_buffer;
			sendString("!Save count red#");
			if(count_red < count_green)
				count_yellow = count_green - count_red;
			else{
				count_green = count_red - count_yellow;
			}
			count_tuning = 2*(count_green + count_red + count_yellow);
		}

		break;
	case MANUAL_YELLOW:
		if(timer2_flag){
			setTimer2(50);
			Blink_Yellow();
		}
		if(isButtonMode()){
			status_manual = MANUAL_GREEN;
			count_buffer = count_green;
		}
		if(isButtonTime()){
			count_buffer++;
		}
		if(isButtonEnter()){
			count_yellow = count_buffer;
			sendString("!Save count yellow#");
			if(count_red < count_green)
				count_red = count_green - count_yellow;
			else{
				count_green = count_red - count_yellow;
			}
			count_tuning = 2*(count_green + count_red + count_yellow);
		}
		break;
	case MANUAL_GREEN:
		if(timer2_flag){
			setTimer2(50);
			Blink_Green();
		}
		if(isButtonMode()){
			status_manual = MANUAL_RED;
			count_buffer = count_red;
		}
		if(isButtonTime()){
			count_buffer++;
		}
		if(isButtonEnter()){
			count_green = count_buffer;
			sendString("!Save count green#");
			if(count_red < count_green)
				count_red = count_green - count_yellow;
			else{
				count_yellow = count_red - count_green;
			}
			count_tuning = 2*(count_green + count_red + count_yellow);
		}
		break;
	default:
		status_manual = MANUAL_INIT;
	}
}

void tuning_traffic(){ //person walking on phase1
	if(isButtonPedes()){
		flag_tuning = 1;
		count_tuning = 2*(count_green + count_red + count_yellow);
	}
	if(count_tuning <= 0){
		flag_tuning = 0;
		Pedes_Off();
		buzzer_SetVolume(0);
		count_tuning = 2*(count_green + count_red + count_yellow);
	}
	if(flag_tuning){
		switch(flag_color){
			case TUNING_GREEN:
				Pedes_GreenOn();
				if(counter_normal <= 3){
					if(timer3_flag){
						setTimer1(10*counter_normal);
						tog = 1 - tog;
						buzzer_SetVolume(50*tog);
					}
				}
				break;
			case TUNING_RED:
				Pedes_RedOn();
				buzzer_SetVolume(0);
				break;
			case TUNING_YELLOW:
				Pedes_YellowOn();
				buzzer_SetVolume(0);
				break;
		}
	}
}

void traffic_light(){
	switch(status_traffic){
	case AUTOMATIC:
		if(timer1_flag){
			setTimer1(100);
			normal_trafic();
			send7seg(num1, num2);
		}
		if(isModeLongPress()){
			status_traffic = MANUAL;
		}
		tuning_traffic();
		//send uart 2 phase counter
		break;
	case MANUAL:
		manual_trafic();
		if(timer1_flag){
			setTimer1(100);
			sendManual(count_buffer);
		}
		if(isModeLongPress()){
			status_traffic = AUTOMATIC;
		}
		//send temp or ?????
		break;
	default:
		status_traffic = AUTOMATIC;
	}
}


