/*
 * DistanceUnitSelectionState.h
 *
 *  Created on: May 4, 2016
 *      Author: Kai
 */

#ifndef DISTANCEUNITSELECTIONSTATE_H_
#define DISTANCEUNITSELECTIONSTATE_H_
#include "CyclometerState.h"

class DistanceUnitSelectionState : public CyclometerState {
public:
	DistanceUnitSelectionState();
	DistanceUnitSelectionState(CyclometerController* c, CyclometerData* d, OutputController* dis);
	virtual ~DistanceUnitSelectionState();
	void accept(Event event);
	void onEntry();
	void onExit();
};

#endif /* DISTANCEUNITSELECTIONSTATE_H_ */
