/*
 * CyclometerData.cpp
 *
 *  Created on: May 2, 2016
 *      Author: gmh5970
 */

#include "CyclometerData.h"

CyclometerData::CyclometerData() {
	pthread_mutexattr_init(&mutexAttr); //Initialize mutex attribute variable
	pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_ERRORCHECK); //Set mutex attribute to error-checking type
	pthread_mutex_init(tripSpeed_mutex, &mutexAttr);
	pthread_mutex_init(tripStartTime_mutex, &mutexAttr);
	pthread_mutex_init(unitsMeters_mutex, &mutexAttr);
	pthread_mutex_init(tireSize_mutex, &mutexAttr);
	pthread_mutex_init(lastPulseTime_mutex, &mutexAttr);
}

void CyclometerData::getMutex(pthread_mutex_t mutex) {
	//Get mutex
	int result = pthread_mutex_trylock(mutex);
	while (result != 0) {
		result = pthread_mutex_trylock(mutex);
	 }
}

float CyclometerData::getSpeed() {

}
