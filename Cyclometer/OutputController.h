/*
 * OutputController.h
 *
 *  Created on: May 9, 2016
 *      Author: Kai
 */

#ifndef OUTPUTCONTROLLER_H_
#define OUTPUTCONTROLLER_H_

#include <string>
#include <pthread.h>
#include <stdint.h>
#include "CyclometerData.h"

using namespace std;

class OutputController {
public:
	OutputController(CyclometerData cd);
	virtual ~OutputController();
	void setData(std::string s);
	void run();

private:
	string displayValue;
	pthread_mutex_t displayValueMutex;
	pthread_mutexattr_t mutexAttr; //Mutex attribute variable
	uintptr_t outputPort1;
	uintptr_t outputPort2;
	const static int DATA_BASE_ADDRESS = 0x280; //Address of the data acquisition bus
	const static int DATA_PORT_B = DATA_BASE_ADDRESS + 0x09; //Address of register for Digital I/O Port B
	const static int DATA_PORT_C = DATA_BASE_ADDRESS + 0x0A; //Address of register for Digital I/O Port C
	void getMutex(pthread_mutex_t* mutex);
	void giveMutex(pthread_mutex_t* mutex);
	string getData();
	CyclometerData data;
};

#endif /* OUTPUTCONTROLLER_H_ */
