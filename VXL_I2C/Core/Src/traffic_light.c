/*
 * traffic_light.c
 *
 *  Created on: Nov 11, 2024
 *      Author: lenovo
 */

#include "traffic_light.h"

void red1_green2() {
	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_SET);
}
void red1_yellow2() {
	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_RESET);
}
void green1_red2() {
	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_SET);
}
void yellow1_red2() {
	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_SET);
}
