/*
 * global.h
 *
 *  Created on: Nov 13, 2024
 *      Author: lenovo
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "fsm_auto.h"
#include "fsm_manual.h"
#include "traffic_light.h"
#include "i2c-lcd.h"
//#include "delay.h"
#include "button.h"

extern int status;

#define	INIT		1

#define R1G2		2
#define R1Y2		3
#define G1R2		4
#define Y1R2		5

#define INIT_SET	11
#define R_SET		12
#define Y_SET		13
#define G_SET		14

#endif /* INC_GLOBAL_H_ */
