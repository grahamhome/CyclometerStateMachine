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

	void trip(bool active); //Toggles trip mode ON iff active == true
	bool trip(); //Returns trip toggle value

	void manual(bool on); //Toggles manual mode ON iff on == true
	bool manual(); //Returns mode toggle value

	void update(time_t pulseTime); //Method to update speed calculations (called by CyclometerController on wheel pulse event processing)

	float getTripSpeed(); //Returns last updated average trip speed value

	float getCurrentSpeed(); //Returns current speed value

	double getTime(); //Returns trip time

	float getDistance(); //Returns trip distance in metric or imperial units depending on unitsMetric

	bool unitsMetric(); //Gets units mode
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
	time_t lastUpdateTime;
	pthread_mutex_t lastUpdateTime_mutex;

	//Units == metric?
	bool unitsMetric;
	pthread_mutex_t unitsMetric_mutex;

	//Tire size in cm
	int tireSize;
	pthread_mutex_t tireSize_mutex;

	//Auto mode timeout value in seconds
	static int timeout = 60;

	void getMutex(pthread_mutex_t mutex);
	void giveMutex(pthread_mutex_t mutex);
};

#endif /* CYCLOMETERDATA_H_ */
