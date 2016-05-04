/*
 * CyclometerData.h
 *
 *  Created on: May 2, 2016
 *      Author: gmh5970
 */

#ifndef CYCLOMETERDATA_H_
#define CYCLOMETERDATA_H_

#include <pthread.h>

class CyclometerData {
public:
	CyclometerData();

	void setTripSpeed(float time);
	float getTripSpeed();
	float getTripTime();
	void resetTripStartTime();
	float getSpeed();
	void setSpeed(float time);
	bool getUnitsMeters();
	void setUnitsMeters(bool units);
	int getTireSize();
	void setTireSize(int size);

private:
	pthread_mutexattr_t mutexAttr; //Mutex attribute variable
	float tripSpeed;
	pthread_mutex_t tripSpeed_mutex;
	float tripStartTime;
	pthread_mutex_t tripStartTime_mutex;
	bool unitsMeters;
	pthread_mutex_t unitsMeters_mutex;
	int tireSize;
	pthread_mutex_t tireSize_mutex;
	float lastPulseTime;
	pthread_mutex_t lastPulseTime_mutex;

	void getMutex(pthread_mutex_t mutex);
	void giveMutex(pthread_mutex_t mutex);
};

#endif /* CYCLOMETERDATA_H_ */
