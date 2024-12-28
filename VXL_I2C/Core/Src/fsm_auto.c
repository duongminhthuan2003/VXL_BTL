/*
 * fsm_auto.c
 *
 *  Created on: 11 Nov 2024
 *      Author: lenovo
 */

#include "global.h"
#include <stdio.h>

int time_red = 6, time_yellow = 3, time_green = 3;
int time1, time2;
char buffer[16];
/*State 0: RED1 GREEN2
 *State 1: RED1 YELLOW2
 *State 2: GREEN1 RED2
 *State 3: YELLOW1 RED2
 */

void updateLCD() {
	lcd_clear_display();

    lcd_goto_XY(1, 5);
	sprintf(buffer, "%d", time1);
    lcd_send_string(buffer);

    lcd_goto_XY(1, 10);
    sprintf(buffer, "%d", time2);
    lcd_send_string(buffer);

    lcd_goto_XY(0, 0);
    lcd_send_string("Mode: 1");
}

void fsm_automatic() {
    switch(status) {
    case INIT:
    	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_RESET);

    	HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_RESET);

        time1 = time_red;
        time2 = time_green;
        status = R1G2;
    	red1_green2();
        setTimer1(1000);

        lcd_clear_display();

        lcd_goto_XY(1, 5);
        lcd_send_string("-");

        lcd_goto_XY(1, 10);
        lcd_send_string("-");

        lcd_goto_XY(0, 0);
        lcd_send_string("Mode: 1");
        break;

    case R1G2:

        if(timer1Flag == 1){
        	time1--;
        	time2--;

        	updateLCD();

        	setTimer1(1000);
        }

        if(time2 <= 0) {
            time2 = time_yellow;
            status = R1Y2;
            red1_yellow2();

        }

        if(isB0Pressed() == 1) {
            status = INIT_SET;
        }
        break;

    case R1Y2:
        if(timer1Flag == 1){
        	time1--;
        	time2--;

        	updateLCD();

        	setTimer1(1000);
        }

        if(time1 <= 0 && time2 <= 0) {
            time1 = time_green;
            time2 = time_red;
            status = G1R2;
            green1_red2();

        }

        if(isB0Pressed() == 1) {
            status = INIT_SET;
        }
        break;

    case G1R2:
        if(timer1Flag == 1){
        	time1--;
        	time2--;

        	updateLCD();

        	setTimer1(1000);
        }

        if(time1 <= 0) {
            time1 = time_yellow;
            status = Y1R2;
    	yellow1_red2();
        }

        if(isB0Pressed() == 1) {
            status = INIT_SET;
        }
        break;

    case Y1R2:
        if(timer1Flag == 1){
        	time1--;
        	time2--;

        	updateLCD();

        	setTimer1(1000);
        }
        if(time1 <= 0 && time2 <= 0) {
        	red1_green2();

            time1 = time_red;
            time2 = time_green;
            status = R1G2;
        }

        if(isB0Pressed() == 1) {
            status = INIT_SET;
        }
        break;

    default:
        break;
    }
}
