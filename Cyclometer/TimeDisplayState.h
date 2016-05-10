/*
 * TimeDisplayState.h
 *
 *  Created on: May 4, 2016
 *      Author: Kai
 */

#ifndef TIMEDISPLAYSTATE_H_
#define TIMEDISPLAYSTATE_H_
#include "CyclometerState.h"

class TimeDisplayState : public CyclometerState{
public:
	TimeDisplayState();
	TimeDisplayState(CyclometerController* c, CyclometerData* d, OutputController* dis);
	virtual ~TimeDisplayState();
	void accept(Events event);
	void onEntry();
	void onExit();

};

#endif /* TIMEDISPLAYSTATE_H_ */
