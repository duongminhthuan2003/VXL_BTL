/*
 * button.h
 *
 *  Created on: Nov 11, 2024
 *      Author: lenovo
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int b0Flag;

int isButtonPressed();
int isB0Pressed();
int isB1Pressed();
int isB2Pressed();

void getKeyInput();

#endif /* INC_BUTTON_H_ */
