/*
 * fsm_manual.c
 *
 *  Created on: Nov 13, 2024
 *      Author: lenovo
 */

#include "fsm_manual.h"
#include <stdio.h>

int tempRed, tempYellow, tempGreen;
char buffer[16];

void fsm_manual(){
		switch(status){
			case INIT_SET:
		    	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_RESET);
		    	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_RESET);

		    	HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_RESET);
		    	HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_RESET);

				tempRed = time_red;
				tempYellow = time_yellow;
				tempGreen = time_green;

				setTimer1(1000);
				lcd_clear_display();

			    lcd_goto_XY(0, 0);
			    lcd_send_string("Mode: 2");

				status = R_SET;
				break;

			case R_SET:
				HAL_Delay(30);
				HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_SET);

				HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_SET);

				lcd_clear_display();

			    lcd_goto_XY(1, 8);
				sprintf(buffer, "%d", tempRed);
			    lcd_send_string(buffer);

			    lcd_goto_XY(0, 0);
			    lcd_send_string("Mode: 2 - Red");


				if(isB1Pressed() == 1) {
					tempRed++;
					if(tempRed>=100) tempRed = 0;
			        lcd_clear_display();

				    lcd_goto_XY(1, 8);
					sprintf(buffer, "%d", tempRed);
				    lcd_send_string(buffer);

				    lcd_goto_XY(0, 0);
				    lcd_send_string("Mode: 2 - Red");
				}

				if(isButtonPressed() == 1) {
					tempRed--;
					if(tempRed<0) tempRed = 99;
			        lcd_clear_display();

				    lcd_goto_XY(1, 8);
					sprintf(buffer, "%d", tempRed);
				    lcd_send_string(buffer);

				    lcd_goto_XY(0, 0);
				    lcd_send_string("Mode: 2 - Red");
				}

				if(isB2Pressed() == 1){
					time_red = tempRed;
			        lcd_clear_display();
				    lcd_goto_XY(0, 0);
				    lcd_send_string("Confirm!");

				    HAL_Delay(1000);
			        lcd_clear_display();

				    lcd_goto_XY(1, 8);
					sprintf(buffer, "%d", tempRed);
				    lcd_send_string(buffer);

				    lcd_goto_XY(0, 0);
				    lcd_send_string("Mode: 2 - Red");
					time_green = time_red - time_yellow;
				}

				if(isB0Pressed() == 1) {
					status = Y_SET;
				}
				break;

			case Y_SET:
				HAL_Delay(30);

				HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_RESET);

				HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_RESET);

				lcd_clear_display();

			    lcd_goto_XY(1, 8);
				sprintf(buffer, "%d", tempYellow);
			    lcd_send_string(buffer);

			    lcd_goto_XY(0, 0);
			    lcd_send_string("Mode: 2 - Yellow");

				if(isB1Pressed() == 1) {
					tempYellow++;
					if(tempYellow>=100) tempYellow = 0;

			        lcd_clear_display();

				    lcd_goto_XY(1, 8);
					sprintf(buffer, "%d", tempYellow);
				    lcd_send_string(buffer);

				    lcd_goto_XY(0, 0);
				    lcd_send_string("Mode: 2 - Yellow");
				}

				if(isButtonPressed() == 1) {
					tempYellow--;
					if(tempYellow<0) tempYellow = 99;
			        lcd_clear_display();

				    lcd_goto_XY(1, 8);
					sprintf(buffer, "%d", tempYellow);
				    lcd_send_string(buffer);

				    lcd_goto_XY(0, 0);
				    lcd_send_string("Mode: 2 - Yellow");
				}

				if(isB2Pressed() == 1){
					time_yellow = tempYellow;

			        lcd_clear_display();
				    lcd_goto_XY(0, 0);
				    lcd_send_string("Confirm!");

				    HAL_Delay(1000);
			        lcd_clear_display();

				    lcd_goto_XY(1, 8);
					sprintf(buffer, "%d", tempYellow);
				    lcd_send_string(buffer);

				    lcd_goto_XY(0, 0);
				    lcd_send_string("Mode: 2 - Yellow");
					time_red = time_yellow + time_green;
				}

				if(isB0Pressed() == 1) {
					status = G_SET;
				}
				break;

			case G_SET:
				HAL_Delay(30);

				HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_SET);

				HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_SET);


				lcd_clear_display();

			    lcd_goto_XY(1, 8);
				sprintf(buffer, "%d", tempGreen);
			    lcd_send_string(buffer);

			    lcd_goto_XY(0, 0);
			    lcd_send_string("Mode: 2 - Green");

				if(isB1Pressed() == 1) {
					tempGreen++;
					if(tempGreen>=100) tempGreen = 0;
			        lcd_clear_display();

				    lcd_goto_XY(1, 8);
					sprintf(buffer, "%d", tempGreen);
				    lcd_send_string(buffer);

				    lcd_goto_XY(0, 0);
				    lcd_send_string("Mode: 2 - Green");
				}

				if(isButtonPressed() == 1) {
					tempGreen--;
					if(tempGreen<0) tempGreen = 99;
			        lcd_clear_display();

				    lcd_goto_XY(1, 8);
					sprintf(buffer, "%d", tempGreen);
				    lcd_send_string(buffer);

				    lcd_goto_XY(0, 0);
				    lcd_send_string("Mode: 2 - Green");
				}
				if(isB2Pressed() == 1){
					time_green = tempGreen;

			        lcd_clear_display();
				    lcd_goto_XY(3, 0);
				    lcd_send_string("Confirm!");

				    HAL_Delay(1000);
			        lcd_clear_display();

				    lcd_goto_XY(1, 8);
					sprintf(buffer, "%d", tempGreen);
				    lcd_send_string(buffer);

				    lcd_goto_XY(0, 0);
				    lcd_send_string("Mode: 2 - Green");

					time_red = time_green + time_yellow;
				}

				if(isB0Pressed() == 1) {
					status = INIT;
				}
				break;

			default:
				break;

	}
}
