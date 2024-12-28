/*
 * button.c
 *
 *  Created on: Nov 11, 2024
 *      Author: lenovo
 */

#include "button.h"
#include "global.h"

int keyReg0 = GPIO_PIN_RESET;
int keyReg1 = GPIO_PIN_RESET;
int keyReg2 = GPIO_PIN_RESET;
int keyReg3 = GPIO_PIN_RESET;

int key0Reg0 = GPIO_PIN_RESET;
int key0Reg1 = GPIO_PIN_RESET;
int key0Reg2 = GPIO_PIN_RESET;
int key0Reg3 = GPIO_PIN_RESET;

int key1Reg0 = GPIO_PIN_RESET;
int key1Reg1 = GPIO_PIN_RESET;
int key1Reg2 = GPIO_PIN_RESET;
int key1Reg3 = GPIO_PIN_RESET;

int key2Reg0 = GPIO_PIN_RESET;
int key2Reg1 = GPIO_PIN_RESET;
int key2Reg2 = GPIO_PIN_RESET;
int key2Reg3 = GPIO_PIN_RESET;

int buttonFlag = 0;
int b0Flag = 0;
int b1Flag = 0;
int b2Flag = 0;

int timeForKeyPress = 2000;

int isButtonPressed() {
	if(buttonFlag == 1){
		buttonFlag = 0;
		return 1;
	} else return 0;
}
int isB0Pressed() {
	if(b0Flag == 1) {
		b0Flag = 0;
		return 1;
	} else return 0;
}
int isB1Pressed() {
	if(b1Flag == 1) {
		b1Flag = 0;
		return 1;
	} else return 0;
}
int isB2Pressed() {
	if(b2Flag == 1) {
		b2Flag = 0;
		return 1;
	} else return 0;
}
void subKeyProcess() {
	//TODO
	buttonFlag = 1;
}

void subKey0Process() {
	b0Flag = 1;
}

void subKey1Process() {
	b1Flag = 1;
}

void subKey2Process() {
	b2Flag = 1;
}

void getKeyInput() {
	keyReg0 = keyReg1;
	keyReg1 = keyReg2;
	keyReg2 = HAL_GPIO_ReadPin(BUTTON_GPIO_Port, BUTTON_Pin);
	if((keyReg0 == keyReg1) && (keyReg1 == keyReg2)) {
		if(keyReg3 != keyReg2) {
			keyReg3 = keyReg2;
			if(keyReg2 == PRESSED_STATE) {
				//TODO
				subKeyProcess();
				timeForKeyPress = 2000;
			}
		} else {
			timeForKeyPress--;
			if(timeForKeyPress == 0) {
				//TODO
				if (keyReg2 == PRESSED_STATE) {
					subKeyProcess();
				}
				timeForKeyPress = 2000;
			}
		}
	}

	//BUTTON 0 debounce
	key0Reg0 = key0Reg1;
	key0Reg1 = key0Reg2;
	key0Reg2 = HAL_GPIO_ReadPin(B0_GPIO_Port, B0_Pin);
	if((key0Reg0 == key0Reg1) && (key0Reg1 == key0Reg2)) {
		if(key0Reg3 != key0Reg2) {
			key0Reg3 = key0Reg2;
			if(key0Reg2 == PRESSED_STATE) {
				//TODO
				subKey0Process();
				timeForKeyPress = 2000;
			}
		} else {
			timeForKeyPress--;
			if(timeForKeyPress == 0) {
				//TODO
				if (key0Reg2 == PRESSED_STATE) {
					subKey0Process();
				}
				timeForKeyPress = 2000;
			}
		}
	}

	//BUTTON 1 debounce
	key1Reg0 = key1Reg1;
	key1Reg1 = key1Reg2;
	key1Reg2 = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
	if((key1Reg0 == key1Reg1) && (key1Reg1 == key1Reg2)) {
		if(key1Reg3 != key1Reg2) {
			key1Reg3 = key1Reg2;
			if(key1Reg2 == PRESSED_STATE) {
				//TODO
				subKey1Process();
				timeForKeyPress = 2000;
			}
		} else {
			timeForKeyPress--;
			if(timeForKeyPress == 0) {
				//TODO
				if (key1Reg2 == PRESSED_STATE) {
					subKey1Process();
				}
				timeForKeyPress = 2000;
			}
		}
	}

	//BUTTON 2 debounce
	key2Reg0 = key2Reg1;
	key2Reg1 = key2Reg2;
	key2Reg2 = HAL_GPIO_ReadPin(B2_GPIO_Port, B2_Pin);
	if((key2Reg0 == key2Reg1) && (key2Reg1 == key2Reg2)) {
		if(key2Reg3 != key2Reg2) {
			key2Reg3 = key2Reg2;
			if(key2Reg2 == PRESSED_STATE) {
				//TODO
				subKey2Process();
				timeForKeyPress = 2000;
			}
		} else {
			timeForKeyPress--;
			if(timeForKeyPress == 0) {
				//TODO
				if (key2Reg2 == PRESSED_STATE) {
					subKey1Process();
				}
				timeForKeyPress = 2000;
			}
		}
	}
}
