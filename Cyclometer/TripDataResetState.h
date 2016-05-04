/*
 * TripDataResetState.h
 *
 *  Created on: May 4, 2016
 *      Author: Kai
 */

#ifndef TRIPDATARESETSTATE_H_
#define TRIPDATARESETSTATE_H_
#include "CyclometerState.h"S

class TripDataResetState {
public:
	TripDataResetState();
	TripDataResetState(CyclometerData* d, OutputController* dis);
	virtual ~TripDataResetState();
	void accept(Events event);
	void onEntry();
	void onExit();
	void updateData();
	void updateDisplay();
};

#endif /* TRIPDATARESETSTATE_H_ */
