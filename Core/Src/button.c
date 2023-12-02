/*
 * button.c
 *
 *  Created on: Oct 9, 2023
 *      Author: HaHuyen
 */

#include "button.h"

int Keyred0[20] = {NORMAL_STATE};
int Keyred1[20] = {NORMAL_STATE};
int Keyred2[20] = {NORMAL_STATE};
int Keyred3[20] = {NORMAL_STATE};

int Key[20] = {NORMAL_STATE};
int MAX_KEY = 4;
int TimerForKeypress[20] = {200};
int flag_short[20] = {0};
int flag_long[20] = {0};

void readKey(){
	Key[0] = HAL_GPIO_ReadPin(A0_GPIO_Port, A0_Pin); //pedestrian
	Key[1] = HAL_GPIO_ReadPin(A1_GPIO_Port, A1_Pin); // mode
	Key[2] = HAL_GPIO_ReadPin(A2_GPIO_Port, A2_Pin); //time
	Key[3] = HAL_GPIO_ReadPin(A3_GPIO_Port, A3_Pin); //enter
}
void getKeyInput(){
	readKey();
	for(int i = 0; i < MAX_KEY; i++){
		Keyred0[i] = Keyred1[i];
		Keyred1[i] = Keyred2[i];
		Keyred2[i] = Key[i];
		if((Keyred0[i] == Keyred1[i]) && (Keyred1[i] == Keyred2[i])){
			if(Keyred3[i] != Keyred2[i]){
				Keyred3[i] = Keyred2[i];
				if(Keyred2[i] == PRESS_STATE){
					//TODO
					flag_short[i] = 1;
					TimerForKeypress[i] = 200;
				}
			}else{
				TimerForKeypress[i]--;
				if(TimerForKeypress[i] == 0){
					if(Keyred2[i] == PRESS_STATE){
						//TODO
						flag_long[i] = 1;
					}
					TimerForKeypress[i] = 200;
				}
			}
		}else{
			flag_long[i] = 0;
			flag_short[i] = 0;
		}
	}
}

int isButtonPedes(){
	if(flag_short[0]){
		flag_short[0] = 0;
		return 1;
	}
		return 0;
}

int isButtonMode(){
	if(flag_short[1]){
		flag_short[1] = 0;
		return 1;
	}
		return 0;
}

int isModeLongPress(){
	if(flag_long[1]){
		flag_long[1] = 0;
		return 1;
	}
		return 0;
}

int isButtonTime(){
	if(flag_short[2]){
		flag_short[2] = 0;
		return 1;
	}
		return 0;
}

int isButtonEnter(){
	if(flag_short[3]){
		flag_short[3] = 0;
		return 1;
	}
		return 0;
}
