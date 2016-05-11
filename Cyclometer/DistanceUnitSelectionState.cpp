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
	switch(event.getType()){
		case MBP:
			data->setUnitsMetric(!(data->unitsMetric()));
		case FRST:
			data->reset(true);
		case SBP:
			controller->transition("TireSizeSelectionState");
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
