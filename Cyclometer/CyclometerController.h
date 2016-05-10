/*
 * CyclometerController.h
 *
 *  Created on: May 5, 2016
 *      Author: Graham
 */

#ifndef CYCLOMETERCONTROLLER_H_
#define CYCLOMETERCONTROLLER_H_

#include <string.h>
#include <map>
#include <queue>
#include <pthread.h>
#include "CyclometerData.h"
#include "CyclometerState.h"
#include "Events.h"
#include "OutputController.h"

class CyclometerController {
public:
	CyclometerController();

	void run();
	void accept(Events event);
	void transition(std::string stateName);
	CyclometerData testData(); //Method for testing purposes only
	std::string testLastState(); //Method for testing purposes only
	std::string testCurrentState(); //Method for testing purposes only

private:

	pthread_mutexattr_t *mutexAttr; //Mutex attribute variable
	std::string currentState; //The state ID of the current state
	std::string lastState; //The state ID of the previous state
	std::map<std::string, CyclometerState> states; //Maps state IDs to state objects
	OutputController display;
	CyclometerData data;
	std::queue<Events> eventQueue; //The queue of "accepted" events waiting to be processed
	pthread_mutex_t *queueMutex;
	void buildStateMap();
	void getMutex(pthread_mutex_t mutex);
	void giveMutex(pthread_mutex_t mutex);

};
#endif /* CYCLOMETERCONTROLLER_H_ */
