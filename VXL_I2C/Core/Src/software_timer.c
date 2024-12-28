/*
 * software_timer.c
 *
 *  Created on: Sep 28, 2024
 *      Author: lenovo
 */

#include "software_timer.h"

int timer1Counter = 0;
int timer1Flag = 0;

void setTimer1(int duration) {
	timer1Counter = duration;
	timer1Flag = 0;
}

void timerRun() {
	if(timer1Counter > 0) {
		timer1Counter--;
		if (timer1Counter <= 0) {
			timer1Flag = 1;
		}
	}
}
