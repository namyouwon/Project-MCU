/*
 * button.h
 *
 *  Created on: Oct 9, 2023
 *      Author: HaHuyen
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET //1
#define PRESS_STATE GPIO_PIN_RESET //0

void getKeyInput();
int isButtonMode();
int isButtonTime();
int isButtonEnter();

#endif /* INC_BUTTON_H_ */
