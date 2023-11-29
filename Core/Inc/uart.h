/*
 * uart.h
 *
 *  Created on: Nov 20, 2023
 *      Author: HaHuyen
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "main.h"
#include "stdio.h"
#include "string.h"
#include "software_timer.h"
#include "usart.h"

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void sendString(uint8_t* str);
void sendNum(uint8_t num);
void send7seg(uint8_t phase1, uint8_t phase2);
void sendManual(uint8_t temp);


#endif /* INC_UART_H_ */
