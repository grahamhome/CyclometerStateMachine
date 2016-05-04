/*
 * TimeDisplayState.h
 *
 *  Created on: May 4, 2016
 *      Author: Shannalotte
 */

#ifndef TIMEDISPLAYSTATE_H_
#define TIMEDISPLAYSTATE_H_
#include "CyclometerState.h"

class TimeDisplayState {
public:
	TimeDisplayState();
	TimeDisplayState(CyclometerData* d, OutputController* dis);
	virtual ~TimeDisplayState();
	void accept(Events event);
	void onEntry();
	void onExit();
	void updateData();
	void updateDisplay();
};

#endif /* TIMEDISPLAYSTATE_H_ */
