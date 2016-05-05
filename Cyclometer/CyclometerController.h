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
	std::string getLastState();
	void accept(Event event);

private:

	std::string currentState; //The state ID of the current state
	std::map<std::string, CyclometerState> states; //Maps state IDs to state objects
	OutputController display;
	CyclometerData data;
	std::string lastState; //The state ID of the previous state
	bool paused;
	std::queue eventQueue; //The queue of "accepted" events waiting to be processed
	//TODO: Add timer object

	void resetTimeout();
	void timeout();

};
#endif /* CYCLOMETERCONTROLLER_H_ */
