/*
 * global.h
 *
 *  Created on: Oct 28, 2023
 *      Author: ACER
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "display_7_seg.h"

#define INIT			0
#define MODE_1			1
#define MODE_2			2
#define MODE_3			3
#define MODE_4			4

extern int status;
extern int light_unsaved_duration[3];
extern int light_duration[3];
extern int led7seg_buffer[4];
extern int light1Mode;
extern int light2Mode;
extern int indexLed;
extern int light1Time;
extern int light2Time;

#endif /* INC_GLOBAL_H_ */
