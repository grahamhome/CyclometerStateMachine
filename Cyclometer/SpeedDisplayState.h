/*
 * SpeedDisplayState.h
 *
 *  Created on: May 4, 2016
 *      Author: Shannalotte
 */

#ifndef SPEEDDISPLAYSTATE_H_
#define SPEEDDISPLAYSTATE_H_
#include "CyclometerState.h"

class SpeedDisplayState {
public:
	SpeedDisplayState();
	SpeedDisplayState(CyclometerController* c, CyclometerData* d, OutputController* dis);
	virtual ~SpeedDisplayState();
	void accept(Events event);
	void onEntry();
	void onExit();
};

#endif /* SPEEDDISPLAYSTATE_H_ */
