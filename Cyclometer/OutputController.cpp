/*
 * OutputController.cpp
 *
 *  Created on: May 9, 2016
 *      Author: Shannalotte
 */

#include "OutputController.h"
#include <sys/mman.h>
#include <hw/inout.h>
#include <unistd.h>

OutputController::OutputController(CyclometerData cd) {
	data = cd;
	pthread_mutexattr_init(&mutexAttr); //Initialize mutex attribute variable
	pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_ERRORCHECK); //Set mutex attribute variable to error-checking type

	//Initialize mutex with error-checking attribute
	pthread_mutex_init(&displayValueMutex, &mutexAttr);

	//Initialize port B as output port 1
	outputPort1 = mmap_device_io(1, DATA_PORT_B); //MMap port A
	if (outputPort1 == MAP_DEVICE_FAILED) {
		printf("Error: Failed to memory map output port B");
	}

	//Initialize port C as output port 2
	outputPort2 = mmap_device_io(1, DATA_PORT_C); //MMap port A
	if (outputPort2 == MAP_DEVICE_FAILED) {
		printf("Error: Failed to memory map output port B");
	}

}

OutputController::~OutputController() {
	// TODO Auto-generated destructor stub
}

void OutputController::setData(std::string s){
	getMutex(&displayValueMutex);
	displayValue = s;
	giveMutex(&displayValueMutex);
}

string OutputController::getData(){
	getMutex(&displayValueMutex);
	string s = displayValue;
	giveMutex(&displayValueMutex);
	return s;
}
/*
 * Locks a mutex.
 */
void OutputController::getMutex(pthread_mutex_t* mutex) {
	//Get mutex
	int result = pthread_mutex_trylock(mutex);
	while (result != 0) {
		result = pthread_mutex_trylock(mutex);
	 }
}

/*
 * Unlocks a mutex.
 */
void OutputController::giveMutex(pthread_mutex_t* mutex) {
	//Give mutex
	int result = pthread_mutex_unlock(mutex);
	while (result != 0) {
		result = pthread_mutex_unlock(mutex);
	 }
}
void OutputController::run() {

}
