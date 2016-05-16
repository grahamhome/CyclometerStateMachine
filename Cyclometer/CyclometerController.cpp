/*
 * CyclometerController.cpp
 *
 *  Created on: May 5, 2016
 *      Author: Graham
 */

#include "CyclometerController.h"
#include "CyclometerState.h"
#include "DistanceDisplayState.h"
#include "DistanceUnitSelectionState.h"
#include "SpeedDisplayState.h"
#include "TimeDisplayState.h"
#include "TireSizeSelectionState.h"
#include "OutputController.h"
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

CyclometerController::CyclometerController() {

	pthread_mutexattr_init(&mutexAttr); //Initialize mutex attribute variable
	pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_ERRORCHECK); //Set mutex attribute variable to error-checking type

	//Initialize mutexes with error-checking attribute
	pthread_mutex_init(&queueMutex, &mutexAttr);

	printf("right before assigning\n");
	data = new CyclometerData();

	OutputController *display;
	currentState = "DistanceUnitSelectionState";
	lastState = "DistanceUnitSelectionState";

	DistanceUnitSelectionState *dState = new DistanceUnitSelectionState(this, data, display);
	states["DistanceUnitSelectionState"] = dState;
	DistanceDisplayState *ddState = new DistanceDisplayState(this, data, display);
	states["DistanceDisplayState"] = ddState;
	SpeedDisplayState *sState = new SpeedDisplayState(this, data, display);
	states["SpeedDisplayState"] = sState;
	TimeDisplayState *tState = new TimeDisplayState(this, data, display);
	states["TimeDisplayState"] = tState;
	TireSizeSelectionState *tSState = new TireSizeSelectionState(this, data, display);
	states["TireSizeSelectionState"] = tSState;

	transition("DistanceUnitSelectionState"); //Default start state
}

/*
 * Locks a mutex.
 */
void CyclometerController::getMutex(pthread_mutex_t* mutex) {
	//Get mutex
	int result = pthread_mutex_trylock(mutex);
	while (result != 0) {
		result = pthread_mutex_trylock(mutex);
	 }
}

/*
 * Unlocks a mutex.
 */
void CyclometerController::giveMutex(pthread_mutex_t* mutex) {
	//Give mutex
	int result = pthread_mutex_unlock(mutex);
	while (result != 0) {
		result = pthread_mutex_unlock(mutex);
	 }
}
/*
 * Creates a map of state names to state objects.
 */


void CyclometerController::accept(Event e) {
	getMutex(&queueMutex);
	eventQueue.push(e);
	giveMutex(&queueMutex);
}

void CyclometerController::transition(std::string stateName) {
	states[currentState]->onExit();
	states[stateName]->onEntry();
	lastState = currentState;
	currentState = stateName;
}

void *CyclometerController::run() {
	Event next;
	while(1) {
		getMutex(&queueMutex);
		if (eventQueue.size() > 0) {
			next = eventQueue.front();
			eventQueue.pop();
			giveMutex(&queueMutex);
			states[currentState]->accept(next);
		} else {
			giveMutex(&queueMutex);
		}
	}
}

/*
 * Returns data object for testing purposes.
 */
CyclometerData *CyclometerController::testData() {
	return data;
}

/*
 * Returns previous state name for testing purposes.
 */
std::string CyclometerController::testPreviousState() {
	return lastState;
}

/*
 * Returns current state name for testing purposes.
 */
std::string CyclometerController::testCurrentState() {
	return currentState;
}
