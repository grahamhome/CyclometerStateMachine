/*
 * DistanceDisplayState.h
 *
 *  Created on: May 4, 2016
 *      Author: Shannalotte
 */

#ifndef DISTANCEDISPLAYSTATE_H_
#define DISTANCEDISPLAYSTATE_H_
#include "CyclometerState.h"

class DistanceDisplayState {
public:
	DistanceDisplayState();
	DistanceDisplayState(CyclometerData* d, OutputController* dis);
	virtual ~DistanceDisplayState();
	void accept(Events event);
	void onEntry();
	void onExit();
	void updateData();
	void updateDisplay();
};

#endif /* DISTANCEDISPLAYSTATE_H_ */
