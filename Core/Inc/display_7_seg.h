/*
 * display_7_seg.h
 *
 *  Created on: Oct 14, 2023
 *      Author: ACER
 */

#ifndef INC_DISPLAY_7_SEG_H_
#define INC_DISPLAY_7_SEG_H_


void updateBuffer(int time1,int time2);
void updateLight();
void displayLight();
void display7SEG();


void display7SEG_A(int num);
void init7SEG_A();

void display7SEG_B(int num);
void init7SEG_B();

#endif /* INC_DISPLAY_7_SEG_H_ */
