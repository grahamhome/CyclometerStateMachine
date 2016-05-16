/*
 * InputScanner.h
 *
 *  Created on: May 16, 2016
 *      Author: Graham
 */

#ifndef INPUTSCANNER_H_
#define INPUTSCANNER_H_

#include "CyclometerController.h"
#include "Event.h"
#include <stdint.h>

class InputScanner {
public:
	InputScanner();

	void run();

private:
	CyclometerController cyclometer;
	uintptr_t ctrlReg;
	uintptr_t inputPort;
	const static int DATA_BASE_ADDRESS = 0x280; //Address of the data acquisition bus
	const static int DATA_PORT_A = DATA_BASE_ADDRESS + 0x08; //Address of register for Digital I/O Port A
	const static int DIOCTR = DATA_BASE_ADDRESS + 0x0B; //Address of control register for DIO Ports A & B
};

#endif /* INPUTSCANNER_H_ */
