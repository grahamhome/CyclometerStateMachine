/*
 * DistanceUnitSelectionState.h
 *
 *  Created on: May 4, 2016
 *      Author: Shannalotte
 */

#ifndef DISTANCEUNITSELECTIONSTATE_H_
#define DISTANCEUNITSELECTIONSTATE_H_
#include "CyclometerState.h"

class DistanceUnitSelectionState {
public:
	DistanceUnitSelectionState();
	DistanceUnitSelectionState(CyclometerData* d, OutputController* dis);
	virtual ~DistanceUnitSelectionState();
	void accept(Events event);
	void onEntry();
	void onExit();
	void updateData();
	void updateDisplay();
};

#endif /* DISTANCEUNITSELECTIONSTATE_H_ */
