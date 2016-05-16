/*
 * InputScanner.cpp
 *
 *  Created on: May 16, 2016
 *      Author: Graham
 */

#include "InputScanner.h"
#include "Event.h"
#include "EventSignals.h"
#include <sys/mman.h>
#include <hw/inout.h>
#include <unistd.h>

InputScanner::InputScanner() {
	cyclometer = CyclometerController();
	//Initialize output port controller
	ctrlReg = mmap_device_io(1, DIOCTR); //MMap control register
	if (ctrlReg == MAP_DEVICE_FAILED) {
		printf("Error: Failed to memory map I/O port control register");
	}
	//Set port A to input and ports B and C to output mode.
	out8(ctrlReg, 0x10);
	//Initialize port A as input port
	inputPort = mmap_device_io(1, DATA_PORT_A); //MMap port A
	if (inputPort == MAP_DEVICE_FAILED) {
		printf("Error: Failed to memory map input port A");
	}

}

void InputScanner::run() {
	//create all the event signals
	EventSignals wrp = WRP;
	EventSignals sst = SST;
	EventSignals mbp = MBP;
	EventSignals sbp = SBP;
	EventSignals trst = TRST;
	EventSignals frst = FRST;
	while(1) {
		uint8_t inputValue = in8(inputPort);
		if (inputValue & 0x01) {
			//Wheel pulse
			cyclometer.accept(Event(time(NULL), wrp));
		}
		if ((inputValue & 0x02) & (inputValue & 0x03) & (inputValue & 0x04)) {
			//Start, mode and set button press
			sleep(2);
			if ((inputValue & 0x02) & (inputValue & 0x03) & (inputValue & 0x04)) {
				cyclometer.accept(Event(time(NULL), frst));
			}
		}
		else if ((inputValue & 0x03) & (inputValue & 0x04)) {
			//Mode and set button press
			sleep(2);
			if ((inputValue & 0x03) & (inputValue & 0x04)) {
				cyclometer.accept(Event(time(NULL), trst));
			}
		}
		else if (inputValue & 0x02) {
			//Start/stop button press
			cyclometer.accept(Event(time(NULL), sst));
		}
		else if (inputValue & 0x03) {
			//Mode button press
			cyclometer.accept(Event(time(NULL), mbp));
		}
		else if (inputValue & 0x04) {
			//Set button press
			cyclometer.accept(Event(time(NULL), sbp));
		}
	}

}
