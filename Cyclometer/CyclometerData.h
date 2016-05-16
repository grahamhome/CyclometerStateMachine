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

	void setTrip(bool active); //Toggles trip mode ON iff active == true
	bool getTrip(); //Returns trip toggle value

	void setManual(bool on); //Toggles manual mode ON iff on == true
	bool getManual(); //Returns mode toggle value

	void update(time_t pulseTime); //Method to update speed calculations (called by CyclometerController on wheel pulse event processing)

	float getTripSpeed(); //Returns last updated average trip speed value

	float getCurrentSpeed(); //Returns current speed value

	double getTripTime(); //Returns trip time

	float getTripDistance(); //Returns trip distance in metric or imperial units depending on unitsMetric

	bool getUnitsMetric(); //Gets units mode
	void setUnitsMetric(bool metric); //Sets units mode to metric iff metric == true

	int getTireSize(); //Gets tire size in cm
	void setTireSize(int size); //Sets tire size in cm

	void reset(bool hardReset); //Resets all data if hardReset == true, else resets trip data

private:
	pthread_mutexattr_t mutexAttr; //Mutex attribute variable

	//Trip == active?
	bool tripActive;
	pthread_mutex_t tripActive_mutex;

	//Manual mode == on?
	bool manualMode;
	pthread_mutex_t manualMode_mutex;

	//Current Speed
	float currentSpeed;
	pthread_mutex_t currentSpeed_mutex;

	//Trip Speed
	float tripSpeed;
	pthread_mutex_t tripSpeed_mutex;

	//Trip Start Time
	time_t tripStartTime;
	pthread_mutex_t tripStartTime_mutex;

	//Trip Elapsed Time
	time_t tripTime;
	pthread_mutex_t tripTime_mutex;

	//Trip Distance
	float tripDistance;
	pthread_mutex_t tripDistance_mutex;

	//Time of last wheel sensor pulse
	time_t lastUpdate;
	pthread_mutex_t lastUpdate_mutex;

	//Units == metric?
	bool unitsMetric;
	pthread_mutex_t unitsMetric_mutex;

	//Tire size in cm
	int tireSize;
	pthread_mutex_t tireSize_mutex;

	//Auto mode timeout value in seconds
	int timeout;

	void getMutex(pthread_mutex_t* mutex);
	void giveMutex(pthread_mutex_t* mutex);


	void resetTripSpeed();
	time_t lastUpdateTime();

	time_t getTripStartTime();

	void setTripSpeed();

	void setTripStartTime(time_t startTime);

	void setLastUpdateTime(time_t pulseTime);

	void setCurrentSpeed(time_t pulseTime);

	void resetCurrentSpeed();

	void resetTripData();
	void resetAllData();

	void incrementTripDistance();
	void resetTripDistance();
};

#endif /* CYCLOMETERDATA_H_ */
