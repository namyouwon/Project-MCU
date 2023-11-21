/*
 * fsm.c
 *
 *  Created on: Oct 28, 2023
 *      Author: ACER
 */

#include "fsm.h"


  void counterRun(){
	  if(timer1_flag){
		  light1Time--;
		  light2Time--;
		  setTimer1(100);
	  }
  }

void fsm_run(){
	  switch(status){
	  case INIT:
		  status=MODE_1;
		  setTimer1(1);
		  setTimer2(1);
		  HAL_GPIO_WritePin(EN_MODE_0_GPIO_Port, EN_MODE_0_Pin, RESET);
		  HAL_GPIO_WritePin(EN_MODE_1_GPIO_Port, EN_MODE_1_Pin, SET);
		  HAL_GPIO_WritePin(EN_VALUE_0_GPIO_Port, EN_VALUE_0_Pin, RESET);
		  HAL_GPIO_WritePin(EN_VALUE_1_GPIO_Port, EN_VALUE_1_Pin, SET);
	  case MODE_1:
		  status=MODE_1;
		  counterRun();
		  updateLight();
		  updateBuffer(light1Time,light2Time);
		  display7SEG();
		  displayLight();
		  if(isButton1Pressed()){
			  status=MODE_2;
			  HAL_GPIO_WritePin(GPIOA, RED_A_Pin|YELLOW_A_Pin|GREEN_A_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(GPIOA, RED_B_Pin|YELLOW_B_Pin|GREEN_B_Pin, GPIO_PIN_SET);
			  updateBuffer(MODE_2, light_duration[0]);
			  setTimer1(50);
			  setTimer2(50);
		  }
		  break;
	  case MODE_2:
		  display7SEG();
		  if(timer1_flag){
			  HAL_GPIO_TogglePin(GPIOA, RED_A_Pin);
			  HAL_GPIO_TogglePin(GPIOA, RED_B_Pin);
			  setTimer1(50);
		  }
		  if(isButton1Pressed()){
			  status=MODE_3;
			  HAL_GPIO_WritePin(GPIOA, RED_A_Pin|YELLOW_A_Pin|GREEN_A_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(GPIOA, RED_B_Pin|YELLOW_B_Pin|GREEN_B_Pin, GPIO_PIN_SET);
			  updateBuffer(MODE_3, light_duration[1]);
			  setTimer1(50);
			  setTimer2(50);
			  light_duration[0]=light_unsaved_duration[0];
		  }
		  else if(isButton2Pressed()){
			  light_duration[0]++;
			  if(light_duration[0]>99)
				  light_duration[0]=1;
			  updateBuffer(MODE_2, light_duration[0]);
		  }
		  else if(isButton3Pressed()){
			  light_unsaved_duration[0]=light_duration[0];
		  }
		  break;
	  case MODE_3:
		  display7SEG();
		  if(timer1_flag){
			  HAL_GPIO_TogglePin(GPIOA, YELLOW_A_Pin);
			  HAL_GPIO_TogglePin(GPIOA, YELLOW_B_Pin);
			  setTimer1(50);
		  }
		  if(isButton1Pressed()){
			  status=MODE_4;
			  HAL_GPIO_WritePin(GPIOA, RED_A_Pin|YELLOW_A_Pin|GREEN_A_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(GPIOA, RED_B_Pin|YELLOW_B_Pin|GREEN_B_Pin, GPIO_PIN_SET);
			  updateBuffer(MODE_4, light_duration[2]);
			  setTimer1(50);
			  setTimer2(50);
			  light_duration[1]=light_unsaved_duration[1];
		  }
		  else if(isButton2Pressed()){
			  light_duration[1]++;
			  if(light_duration[1]>99)
				  light_duration[1]=1;
			  updateBuffer(MODE_3, light_duration[1]);
		  }
		  else if(isButton3Pressed()){
			  light_unsaved_duration[1]=light_duration[1];
		  }
		  break;
	  case MODE_4:
		  display7SEG();
		  if(timer1_flag){
			  HAL_GPIO_TogglePin(GPIOA, GREEN_A_Pin);
			  HAL_GPIO_TogglePin(GPIOA, GREEN_B_Pin);
			  setTimer1(50);
		  }
		  if(isButton1Pressed()){
			  status=MODE_1;
			  HAL_GPIO_WritePin(GPIOA, RED_A_Pin|YELLOW_A_Pin|GREEN_A_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(GPIOA, RED_B_Pin|YELLOW_B_Pin|GREEN_B_Pin, GPIO_PIN_SET);
			  updateBuffer(light_duration[0], light_duration[2]);
			  light1Time=light_duration[0];
			  light2Time=light_duration[2];
			  light1Mode=0;
			  light2Mode=2;
			  setTimer1(1);
			  setTimer2(1);
			  light_duration[2]=light_unsaved_duration[2];
		  }
		  else if(isButton2Pressed()){
			  light_duration[2]++;
			  if(light_duration[2]>99)
				  light_duration[2]=1;
			  updateBuffer(MODE_4, light_duration[2]);
		  }
		  else if(isButton3Pressed()){
			  light_unsaved_duration[2]=light_duration[2];
		  }
		  break;
	  }
}
