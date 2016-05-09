/*
 * CyclometerController.h
 *
 *  Created on: May 5, 2016
 *      Author: Graham
 */

#ifndef CYCLOMETERCONTROLLER_H_
#define CYCLOMETERCONTROLLER_H_

#include <map>
#include <queue>

class CyclometerController {
public:
	CyclometerController();

	void run();
	void accept(Event event);
	void transition(std::string stateName);
	CyclometerData testData(); //Method for testing purposes only
	std::string testLastState(); //Method for testing purposes only
	std::string testCurrentState(); //Method for testing purposes only

private:

	std::string currentState; //The state ID of the current state
	std::string lastState; //The state ID of the previous state
	map<std::string, CyclometerState> states; //Maps state IDs to state objects
	OutputController display;
	CyclometerData data;
	queue<Event> eventQueue; //The queue of "accepted" events waiting to be processed
	pthread_mutex_t queueMutex;
	void buildStateMap();
	void getMutex(pthread_mutex_t mutex);
	void giveMutex(pthread_mutex_t mutex);

};
#endif /* CYCLOMETERCONTROLLER_H_ */
