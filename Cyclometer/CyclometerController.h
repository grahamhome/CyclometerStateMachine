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
#include "Event.h"
#include "OutputController.h"

using namespace std;

class CyclometerController {
public:
	CyclometerController();

	void run();
	void accept(Event event);
	void transition(string stateName);
	CyclometerData testData(); //Method for testing purposes only
	string testPreviousState(); //Method for testing purposes only
	std::string testCurrentState(); //Method for testing purposes only

private:

	pthread_mutexattr_t *mutexAttr; //Mutex attribute variable
	string currentState; //The state ID of the current state
	string lastState; //The state ID of the previous state
	//map<string, CyclometerState*> states; //Maps state IDs to state objects
	OutputController display;
	CyclometerData data;
	queue<Event> eventQueue; //The queue of "accepted" events waiting to be processed
	pthread_mutex_t *queueMutex;
	void buildStateMap();
	void getMutex(pthread_mutex_t* mutex);
	void giveMutex(pthread_mutex_t* mutex);

};
#endif /* CYCLOMETERCONTROLLER_H_ */
