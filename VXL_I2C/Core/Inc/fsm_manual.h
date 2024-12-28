/*
 * fsm_manual.h
 *
 *  Created on: Nov 13, 2024
 *      Author: lenovo
 */

#ifndef INC_FSM_MANUAL_H_
#define INC_FSM_MANUAL_H_

#include "global.h"
#include "main.h"
#include "software_timer.h"
#include "button.h"
#include "fsm_auto.h"

void fsm_manual();

extern int tempRed, tempYellow, tempGreen, tempDisplay;

#endif /* INC_FSM_MANUAL_H_ */
