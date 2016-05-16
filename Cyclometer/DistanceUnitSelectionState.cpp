/*
 * DistanceUnitSelectionState.cpp
 *
 *  Created on: May 4, 2016
 *      Author: Kai
 */

#include "DistanceUnitSelectionState.h"

DistanceUnitSelectionState::DistanceUnitSelectionState(CyclometerController* c, CyclometerData* d, OutputController* dis) : CyclometerState("DistanceUnitSelectionState", c, d, dis){};


DistanceUnitSelectionState::~DistanceUnitSelectionState() {
	// TODO Auto-generated destructor stub
}

void DistanceUnitSelectionState::accept(Event event){

	bool setM;
	switch(event.getType()){
		case MBP:
			setM = not (data->getUnitsMetric());
			data->setUnitsMetric(setM);
			break;
		case FRST:
			data->reset(true);
			break;
		case SBP:
			controller->transition("TireSizeSelectionState");
			break;
		default:
			break;
	}
}

void DistanceUnitSelectionState::onEntry(){
	display->setData("UnitSelection");
}

void DistanceUnitSelectionState::onExit(){
	//do nothing
}
