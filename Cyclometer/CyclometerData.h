/*
 * CyclometerData.h
 *
 *  Created on: May 2, 2016
 *      Author: gmh5970
 */

#ifndef CYCLOMETERDATA_H_
#define CYCLOMETERDATA_H_

#include <pthread.h>
#include <ctime>

class CyclometerData {
public:
	CyclometerData();

	void setTripSpeed();
	float getTripSpeed();
	void resetTripSpeed();
	double getTripTime();
	void startTripTimer();
	float getTripDistance();
	float getCurrentSpeed();
	void setCurrentSpeed(time_t time);
	bool getUnitsMetric();
	void setUnitsMetric(bool units);
	int getTireSize();
	void setTireSize(int size);
	void resetTripData();
	void resetAllData();

private:
	pthread_mutexattr_t mutexAttr; //Mutex attribute variable
	float tripSpeed;
	pthread_mutex_t tripSpeed_mutex;
	float currentSpeed;
	pthread_mutex_t currentSpeed_mutex;
	time_t tripStartTime;
	pthread_mutex_t tripStartTime_mutex;
	bool unitsMetric;
	pthread_mutex_t unitsMetric_mutex;
	int tireSize;
	pthread_mutex_t tireSize_mutex;
	time_t lastPulseTime;
	pthread_mutex_t lastPulseTime_mutex;
	float tripDistance;
	pthread_mutex_t tripDistance_mutex;

	void getMutex(pthread_mutex_t mutex);
	void giveMutex(pthread_mutex_t mutex);

	time_t getTripStartTime();
	void resetCurrentSpeed();
	void resetTripDistance();
	void startTripTimer();
	void incrementTripDistance();
};

#endif /* CYCLOMETERDATA_H_ */
