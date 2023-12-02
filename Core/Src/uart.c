/*
 * uart.c
 *
 *  Created on: Nov 20, 2023
 *      Author: HaHuyen
 */

#include "uart.h"

//UART_HandleTypeDef huart2;

unsigned char temp = 0;
uint8_t msg[100];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart->Instance == USART2){
		HAL_UART_Transmit(&huart2, &temp, 1, 200);
		HAL_UART_Receive_IT(&huart2, &temp, 1);
	}
}

void sendString(uint8_t* str){
	HAL_UART_Transmit(&huart2, (void*)msg, sprintf((void*)msg,"%s",str), 10);
}

void sendNum(uint8_t num) {
    char number[3];
    sprintf(number, "%.2d", num);
    HAL_UART_Transmit(&huart2, (uint8_t*)number, strlen(number), 10);
}

void send7seg(uint8_t phase1, uint8_t phase2){
	sendString("!Phase 1: ");
	sendNum(phase1);
	sendString("; Phase 2: ");
	sendNum(phase2);
	sendString("#\r\n");
//	HAL_UART_Transmit(&huart2, (uint8_t*) "#\r\n", 3, 100);
}

void sendManual(uint8_t temp){
	sendString("!Temporary value: ");
	sendNum(temp);
	sendString("#\r\n");
}
