/*
 * display_7_seg.c
 *
 *  Created on: Oct 14, 2023
 *      Author: ACER
 */


#include "display_7_seg.h"
#include "main.h"
#include "global.h"

void updateBuffer(int time1, int time2){
	led7seg_buffer[0]=time1/10;
	led7seg_buffer[1]=time1%10;
	led7seg_buffer[2]=time2/10;
	led7seg_buffer[3]=time2%10;
}
void updateLight(){
	  if(light1Time<=0){
		  if(light1Mode==0){
			  light1Mode=2;
			  light1Time=light_duration[2];
		  }
		  else if(light1Mode==1){
			  light1Mode=0;
			  light1Time=light_duration[0];
		  }
		  else if(light1Mode==2){
			  light1Mode=1;
			  light1Time=light_duration[1];
		  }
	  }
	  if(light2Time<=0){
		  if(light2Mode==0){
			  light2Mode=2;
			  light2Time=light_duration[2];
		  }
		  else if(light2Mode==1){
			  light2Mode=0;
			  light2Time=light_duration[0];
		  }
		  else if(light2Mode==2){
			  light2Mode=1;
			  light2Time=light_duration[1];
		  }
	  }
}
void displayLight(){
	  if(light1Mode==0){
		  HAL_GPIO_WritePin(YELLOW_A_GPIO_Port, YELLOW_A_Pin, SET);
		  HAL_GPIO_WritePin(GREEN_A_GPIO_Port, GREEN_A_Pin, SET);
		  HAL_GPIO_WritePin(RED_A_GPIO_Port, RED_A_Pin, RESET);
	  }
	  else if(light1Mode==1){
		  HAL_GPIO_WritePin(RED_A_GPIO_Port, RED_A_Pin, SET);
		  HAL_GPIO_WritePin(GREEN_A_GPIO_Port, GREEN_A_Pin, SET);
		  HAL_GPIO_WritePin(YELLOW_A_GPIO_Port, YELLOW_A_Pin, RESET);
	  }
	  else if(light1Mode==2){
		  HAL_GPIO_WritePin(RED_A_GPIO_Port, RED_A_Pin, SET);
		  HAL_GPIO_WritePin(YELLOW_A_GPIO_Port, YELLOW_A_Pin, SET);
		  HAL_GPIO_WritePin(GREEN_A_GPIO_Port, GREEN_A_Pin, RESET);
	  }

	  if(light2Mode==0){
		  HAL_GPIO_WritePin(YELLOW_B_GPIO_Port, YELLOW_B_Pin, SET);
		  HAL_GPIO_WritePin(GREEN_B_GPIO_Port, GREEN_B_Pin, SET);
		  HAL_GPIO_WritePin(RED_B_GPIO_Port, RED_B_Pin, RESET);
	  }
	  else if(light2Mode==1){
		  HAL_GPIO_WritePin(RED_B_GPIO_Port, RED_B_Pin, SET);
		  HAL_GPIO_WritePin(GREEN_B_GPIO_Port, GREEN_B_Pin, SET);
		  HAL_GPIO_WritePin(YELLOW_B_GPIO_Port, YELLOW_B_Pin, RESET);
	  }
	  else if(light2Mode==2){
		  HAL_GPIO_WritePin(RED_B_GPIO_Port, RED_B_Pin, SET);
		  HAL_GPIO_WritePin(YELLOW_B_GPIO_Port, YELLOW_B_Pin, SET);
		  HAL_GPIO_WritePin(GREEN_B_GPIO_Port, GREEN_B_Pin, RESET);
	  }
}

void display7SEG(){
	  if(timer2_flag){
		  display7SEG_A(led7seg_buffer[indexLed]);
		  display7SEG_B(led7seg_buffer[indexLed+2]);
		  HAL_GPIO_TogglePin(GPIOA, EN_MODE_0_Pin);
		  HAL_GPIO_TogglePin(GPIOA, EN_MODE_1_Pin);
		  HAL_GPIO_TogglePin(GPIOA, EN_VALUE_0_Pin);
		  HAL_GPIO_TogglePin(GPIOA, EN_VALUE_1_Pin);
		  indexLed++;
		  if(indexLed>1)	indexLed=0;
		  setTimer2(25);
	  }
}


void display7SEG_A(int num){
	switch ( num ) {
	 	 case 0:
	 		 HAL_GPIO_WritePin ( GPIOB , LED7A_0_Pin | LED7A_1_Pin |LED7A_2_Pin | LED7A_3_Pin | LED7A_4_Pin | LED7A_5_Pin ,GPIO_PIN_RESET ) ;
	 		 HAL_GPIO_WritePin ( GPIOB , LED7A_6_Pin , GPIO_PIN_SET ) ;
	 		 break ;
	 	 case 1:
	 		 HAL_GPIO_WritePin ( GPIOB , LED7A_1_Pin | LED7A_2_Pin , GPIO_PIN_RESET ) ;
	 		 HAL_GPIO_WritePin ( GPIOB , LED7A_0_Pin | LED7A_3_Pin |LED7A_4_Pin | LED7A_5_Pin | LED7A_6_Pin , GPIO_PIN_SET ) ;
	 		 break ;
	 	 case 2:
	 		 HAL_GPIO_WritePin ( GPIOB , LED7A_0_Pin | LED7A_1_Pin |LED7A_3_Pin | LED7A_4_Pin | LED7A_6_Pin , GPIO_PIN_RESET ) ;
	 		 HAL_GPIO_WritePin ( GPIOB , LED7A_2_Pin | LED7A_5_Pin ,GPIO_PIN_SET ) ;
	 		 break ;
	 	 case 3:
			HAL_GPIO_WritePin ( GPIOB , LED7A_0_Pin | LED7A_1_Pin |LED7A_2_Pin | LED7A_3_Pin | LED7A_6_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( GPIOB , LED7A_4_Pin | LED7A_5_Pin ,GPIO_PIN_SET ) ;
			break ;
	 	 case 4:
	 		 HAL_GPIO_WritePin ( GPIOB , LED7A_1_Pin | LED7A_2_Pin |LED7A_5_Pin | LED7A_6_Pin , GPIO_PIN_RESET ) ;
	 		 HAL_GPIO_WritePin ( GPIOB , LED7A_0_Pin | LED7A_3_Pin |LED7A_4_Pin , GPIO_PIN_SET ) ;
	 		 break ;
	 	 case 5:
	 		 HAL_GPIO_WritePin ( GPIOB , LED7A_0_Pin | LED7A_2_Pin |LED7A_3_Pin | LED7A_5_Pin | LED7A_6_Pin , GPIO_PIN_RESET ) ;
	 		 HAL_GPIO_WritePin ( GPIOB , LED7A_1_Pin | LED7A_4_Pin ,GPIO_PIN_SET ) ;
	 		 break ;
	 	 case 6:
	 		 HAL_GPIO_WritePin ( GPIOB , LED7A_0_Pin | LED7A_2_Pin |LED7A_3_Pin | LED7A_4_Pin | LED7A_5_Pin | LED7A_6_Pin ,GPIO_PIN_RESET ) ;
	 		 HAL_GPIO_WritePin ( GPIOB , LED7A_1_Pin , GPIO_PIN_SET ) ;
	 		 break ;
	 	 case 7:
	 		 HAL_GPIO_WritePin ( GPIOB , LED7A_0_Pin | LED7A_1_Pin |LED7A_2_Pin , GPIO_PIN_RESET ) ;
	 		 HAL_GPIO_WritePin ( GPIOB , LED7A_3_Pin | LED7A_4_Pin |LED7A_5_Pin | LED7A_6_Pin , GPIO_PIN_SET ) ;
	 		 break ;
	 	 case 8:
	 		 HAL_GPIO_WritePin ( GPIOB , LED7A_0_Pin | LED7A_1_Pin |LED7A_2_Pin | LED7A_3_Pin | LED7A_4_Pin | LED7A_5_Pin | LED7A_6_Pin ,GPIO_PIN_RESET ) ;
	 		 break ;
	 	 case 9:
	 		 HAL_GPIO_WritePin ( GPIOB , LED7A_0_Pin | LED7A_1_Pin |LED7A_2_Pin | LED7A_3_Pin | LED7A_5_Pin | LED7A_6_Pin ,GPIO_PIN_RESET ) ;
	 		 HAL_GPIO_WritePin ( GPIOB , LED7A_4_Pin , GPIO_PIN_SET ) ;
	 		 break ;
	 }
}
void init7SEG_A(){
	HAL_GPIO_WritePin ( GPIOB , LED7A_0_Pin | LED7A_1_Pin |LED7A_2_Pin | LED7A_3_Pin | LED7A_4_Pin | LED7A_5_Pin | LED7A_6_Pin ,GPIO_PIN_SET ) ;
}

void display7SEG_B(int num){
	switch ( num ) {
	 	 case 0:
	 		 HAL_GPIO_WritePin ( GPIOB , LED7B_0_Pin | LED7B_1_Pin |LED7B_2_Pin | LED7B_3_Pin | LED7B_4_Pin | LED7B_5_Pin ,GPIO_PIN_RESET ) ;
	 		 HAL_GPIO_WritePin ( GPIOB , LED7B_6_Pin , GPIO_PIN_SET ) ;
	 		 break ;
	 	 case 1:
	 		 HAL_GPIO_WritePin ( GPIOB , LED7B_1_Pin | LED7B_2_Pin , GPIO_PIN_RESET ) ;
	 		 HAL_GPIO_WritePin ( GPIOB , LED7B_0_Pin | LED7B_3_Pin |LED7B_4_Pin | LED7B_5_Pin | LED7B_6_Pin , GPIO_PIN_SET ) ;
	 		 break ;
	 	 case 2:
	 		 HAL_GPIO_WritePin ( GPIOB , LED7B_0_Pin | LED7B_1_Pin |LED7B_3_Pin | LED7B_4_Pin | LED7B_6_Pin , GPIO_PIN_RESET ) ;
	 		 HAL_GPIO_WritePin ( GPIOB , LED7B_2_Pin | LED7B_5_Pin ,GPIO_PIN_SET ) ;
	 		 break ;
	 	 case 3:
			HAL_GPIO_WritePin ( GPIOB , LED7B_0_Pin | LED7B_1_Pin |LED7B_2_Pin | LED7B_3_Pin | LED7B_6_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( GPIOB , LED7B_4_Pin | LED7B_5_Pin ,GPIO_PIN_SET ) ;
			break ;
	 	 case 4:
	 		 HAL_GPIO_WritePin ( GPIOB , LED7B_1_Pin | LED7B_2_Pin |LED7B_5_Pin | LED7B_6_Pin , GPIO_PIN_RESET ) ;
	 		 HAL_GPIO_WritePin ( GPIOB , LED7B_0_Pin | LED7B_3_Pin |LED7B_4_Pin , GPIO_PIN_SET ) ;
	 		 break ;
	 	 case 5:
	 		 HAL_GPIO_WritePin ( GPIOB , LED7B_0_Pin | LED7B_2_Pin |LED7B_3_Pin | LED7B_5_Pin | LED7B_6_Pin , GPIO_PIN_RESET ) ;
	 		 HAL_GPIO_WritePin ( GPIOB , LED7B_1_Pin | LED7B_4_Pin ,GPIO_PIN_SET ) ;
	 		 break ;
	 	 case 6:
	 		 HAL_GPIO_WritePin ( GPIOB , LED7B_0_Pin | LED7B_2_Pin |LED7B_3_Pin | LED7B_4_Pin | LED7B_5_Pin | LED7B_6_Pin ,GPIO_PIN_RESET ) ;
	 		 HAL_GPIO_WritePin ( GPIOB , LED7B_1_Pin , GPIO_PIN_SET ) ;
	 		 break ;
	 	 case 7:
	 		 HAL_GPIO_WritePin ( GPIOB , LED7B_0_Pin | LED7B_1_Pin |LED7B_2_Pin , GPIO_PIN_RESET ) ;
	 		 HAL_GPIO_WritePin ( GPIOB , LED7B_3_Pin | LED7B_4_Pin |LED7B_5_Pin | LED7B_6_Pin , GPIO_PIN_SET ) ;
	 		 break ;
	 	 case 8:
	 		 HAL_GPIO_WritePin ( GPIOB , LED7B_0_Pin | LED7B_1_Pin |LED7B_2_Pin | LED7B_3_Pin | LED7B_4_Pin | LED7B_5_Pin | LED7B_6_Pin ,GPIO_PIN_RESET ) ;
	 		 break ;
	 	 case 9:
	 		 HAL_GPIO_WritePin ( GPIOB , LED7B_0_Pin | LED7B_1_Pin |LED7B_2_Pin | LED7B_3_Pin | LED7B_5_Pin | LED7B_6_Pin ,GPIO_PIN_RESET ) ;
	 		 HAL_GPIO_WritePin ( GPIOB , LED7B_4_Pin , GPIO_PIN_SET ) ;
	 		 break ;
	 }
}
void init7SEG_B(){
	HAL_GPIO_WritePin ( GPIOB , LED7B_0_Pin | LED7B_1_Pin |LED7B_2_Pin | LED7B_3_Pin | LED7B_4_Pin | LED7B_5_Pin | LED7B_6_Pin ,GPIO_PIN_SET ) ;
}
