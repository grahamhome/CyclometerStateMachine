/*
 * CyclometerData.cpp
 *
 *  Created on: May 2, 2016
 *      Author: gmh5970
 */

#include "CyclometerData.h"

CyclometerData::CyclometerData() {
	timeout = 60; //Set timeout delay in seconds

	pthread_mutexattr_init(mutexAttr); //Initialize mutex attribute variable
	pthread_mutexattr_settype(mutexAttr, PTHREAD_MUTEX_ERRORCHECK); //Set mutex attribute variable to error-checking type

	//Initialize mutexes with error-checking attribute
	pthread_mutex_init(tripActive_mutex, mutexAttr);
	pthread_mutex_init(manualMode_mutex, mutexAttr);
	pthread_mutex_init(tripSpeed_mutex, mutexAttr);
	pthread_mutex_init(currentSpeed_mutex, mutexAttr);
	pthread_mutex_init(tripStartTime_mutex, mutexAttr);
	pthread_mutex_init(tripTime_mutex, mutexAttr);
	pthread_mutex_init(tripDistance_mutex, mutexAttr);
	pthread_mutex_init(lastUpdate_mutex, mutexAttr);
	pthread_mutex_init(unitsMetric_mutex, mutexAttr);
	pthread_mutex_init(tireSize_mutex, mutexAttr);

	reset(true); //Initialize all values to defaults
}

/*
 * Locks a mutex.
 */
void CyclometerData::getMutex(pthread_mutex_t *mutex) {
	//Get mutex
	int result = pthread_mutex_trylock(mutex);
	while (result != 0) {
		result = pthread_mutex_trylock(mutex);
	 }
}

/*
 * Unlocks a mutex.
 */
void CyclometerData::giveMutex(pthread_mutex_t *mutex) {
	//Give mutex
	int result = pthread_mutex_unlock(mutex);
	while (result != 0) {
		result = pthread_mutex_unlock(mutex);
	 }
}

/*
 * Toggles trip active/inactive
 */
void CyclometerData::setTrip(bool active) {
	getMutex(tripActive_mutex);
	tripActive = active;
	giveMutex(tripActive_mutex);
}

/*
 * Returns trip active/inactive status
 */
bool CyclometerData::getTrip() {
	getMutex(tripActive_mutex);
	bool active = tripActive;
	giveMutex(tripActive_mutex);
	return active;
}
/*
* Toggles manual mode on/off
*/
void CyclometerData::setManual(bool on) {
	getMutex(manualMode_mutex);
	manualMode = on;
	giveMutex(manualMode_mutex);
}

/*
* Returns manual mode status
*/
bool CyclometerData::getManual() {
	getMutex(manualMode_mutex);
	bool on = manualMode;
	giveMutex(manualMode_mutex);
	return on;
}
/*
 * Returns time of last wheel pulse
 */
time_t CyclometerData::lastUpdateTime() {
	getMutex(lastUpdate_mutex);
	time_t updateTime = lastUpdate;
	giveMutex(lastUpdate_mutex);
	return updateTime;
}

/*
 * Updates current and/or trip values depending on value of tripActive.
 * Takes a time value corresponding to a wheel rotation sensor pulse time
 */
void CyclometerData::update(time_t pulseTime) {

	//If auto mode
	if (! (getManual()) ) {

		//Get time since last wheel sensor pulse received
		double elapsed = difftime(pulseTime, lastUpdateTime());
		//If timeout has not expired
		if (elapsed < timeout) {
		}

		//Update trip distance
		incrementTripDistance();
	}

	//If manual mode
	else {

		//If trip is active
		if (getTrip()) {

			//Update trip distance
			incrementTripDistance();
		}

	}

	//Update last pulse time
	setLastUpdateTime(pulseTime);
}

/*
 * Sets the time of the last received wheel pulse to the given value.
 */
void CyclometerData::setLastUpdateTime(time_t pulseTime) {
	getMutex(lastUpdate_mutex);
	lastUpdate = pulseTime;
	giveMutex(lastUpdate_mutex);
}
/*
 * Returns the current speed in kph or mph depending on the value of unitsMetric.
 */
float CyclometerData::getCurrentSpeed() {
	//Get current speed in kph
	getMutex(currentSpeed_mutex);
	float speed = currentSpeed;
	giveMutex(currentSpeed_mutex);
	//Convert to mph if needed
	if (!getUnitsMetric()) {
		speed *= 0.621371; //Conversion factor for km to mi
	}
	return speed;
}

/*
 * Given a wheel rotation pulse time, sets the current speed in kph and updates the most recent pulse time value.
 */
void CyclometerData::setCurrentSpeed(time_t time) {
	//Use previous wheel pulse time to get time difference between pulses, in hours
	double elapsedTime = difftime(time, lastUpdateTime())/3600;
	//Calculate speed in kph (wheel circumference/time)
	float speed = ((getTireSize()/1000)/elapsedTime);
	//Set current speed
	getMutex(currentSpeed_mutex);
	currentSpeed = speed;
	giveMutex(currentSpeed_mutex);
}

/*
 * Sets current speed to 0 kph.
 */
void CyclometerData::resetCurrentSpeed() {
	//Set current speed
	getMutex(currentSpeed_mutex);
	currentSpeed = 0;
	giveMutex(currentSpeed_mutex);
}

/*
 * Returns the average trip speed in kph or mph depending on the value of unitsMetric.
 */
float CyclometerData::getTripSpeed() {
	//Get trip speed in kph
	getMutex(tripSpeed_mutex);
	float speed = tripSpeed;
	giveMutex(tripSpeed_mutex);
	//Convert to mph if needed
	if (!getUnitsMetric()) {
		speed *= 0.621371; //Conversion factor for km to mi
	}
	return speed;
}

/*
 * Updates the average trip speed in kph using the current speed and updates the trip distance.
 */
void CyclometerData::setTripSpeed() {
	//Get current speed
	getMutex(currentSpeed_mutex);
	float currentSpeed = currentSpeed;
	giveMutex(currentSpeed_mutex);
	//Update trip speed
	getMutex(tripSpeed_mutex);
	tripSpeed = (tripSpeed+currentSpeed)/2;
	giveMutex(tripSpeed_mutex);
	incrementTripDistance();
}

/*
 * Sets the average trip speed to 0.
 */
void CyclometerData::resetTripSpeed() {
	//Reset trip speed
	getMutex(tripSpeed_mutex);
	tripSpeed = 0;
	giveMutex(tripSpeed_mutex);
}

/*
 * Returns True if units are set to kilometers, False if units are set to miles.
 */
bool CyclometerData::getUnitsMetric() {
	//Get units
	getMutex(unitsMetric_mutex);
	bool units = unitsMetric;
	giveMutex(unitsMetric_mutex);
	return units;
}

/*
 * Sets the units to kilometers if the parameter is True, otherwise sets units to miles.
 */
void CyclometerData:: setUnitsMetric(bool metric) {
	//Set units
	getMutex(unitsMetric_mutex);
	unitsMetric = metric;
	giveMutex(unitsMetric_mutex);
}

/*
 * Returns tire size in centimeters.
 */
int CyclometerData::getTireSize() {
	//Get tire size
	getMutex(tireSize_mutex);
	int size = tireSize;
	giveMutex(tireSize_mutex);
	return size;
}

/*
 * Sets tire size to the given value
 */
void CyclometerData::setTireSize(int size) {
	//Set tire size
	getMutex(tireSize_mutex);
	tireSize = size;
	giveMutex(tireSize_mutex);
}

/*
 * Returns trip start time.
 */
time_t CyclometerData::getTripStartTime() {
	//Get trip start time
	getMutex(tripStartTime_mutex);
	time_t startTime = tripStartTime;
	giveMutex(tripStartTime_mutex);
	return startTime;
}

/*
 * Sets trip start time to the current time.
 */
void CyclometerData::setTripStartTime(time_t startTime) {
	//Set trip start time
	getMutex(tripStartTime_mutex);
	tripStartTime = startTime;
	giveMutex(tripStartTime_mutex);
	resetTripDistance(); //Reset trip distance since trip is starting
}

/*
 * Gets elapsed trip time in seconds relative to the current time.
 */
double CyclometerData::getTripTime() {
	//Get trip start time
	if (getManual()) {
		if (getTrip()) {
			return difftime(time(NULL), getTripStartTime());
		} else {
			return difftime(lastUpdateTime(), getTripStartTime());
		}
	} else {
		if (timeout < difftime(time(NULL), lastUpdateTime())) {
			return difftime(time(NULL), getTripStartTime());
		} else {
			return difftime(lastUpdateTime(), getTripStartTime());
		}
	}
}

/*
 * Returns the current trip distance in km or mi depending on the value of unitsMetric.
 */
float CyclometerData::getTripDistance() {
	//Get distance
	getMutex(tripDistance_mutex);
	float distance = tripDistance;
	giveMutex(tripDistance_mutex);
	if (! getUnitsMetric()) {
		distance *= 0.621371;
	}
	return distance;
}

/*
 * Sets current trip distance to 0.
 */
void CyclometerData::resetTripDistance() {
	//Reset distance
	getMutex(tripDistance_mutex);
	tripDistance = 0;
	giveMutex(tripDistance_mutex);
}

/*
 * Increments trip distance by the tire size to account for
 * the distance added by 1 wheel rotation.
 */
void CyclometerData::incrementTripDistance() {
	//Update trip distance
	getMutex(tripDistance_mutex);
	tripDistance += (getTireSize()/1000);
	giveMutex(tripDistance_mutex);
}

/*
 * Resets all trip data (speed, start time distance)
 */
void CyclometerData::resetTripData() {
	resetTripSpeed();
	resetTripDistance();
}

/*
 * Resets all data (trip data, units, tire size,
 */
void CyclometerData::resetAllData() {
	resetTripData();
	setTireSize(210); //Set tire size to default value
	setUnitsMetric(true);
}
