/*
 * DistanceUnitSelectionState.cpp
 *
 *  Created on: May 4, 2016
 *      Author: Kai
 */

#include "DistanceUnitSelectionState.h"

DistanceUnitSelectionState::DistanceUnitSelectionState(CyclometerController* c, CyclometerData* d, OutputDisplay* dis) : CyclometerState("DistanceUnitSelectionState", c, d, dis){};


DistanceUnitSelectionState::~DistanceUnitSelectionState() {
	// TODO Auto-generated destructor stub
}

void DistanceUnitSelectionState::accept(Events event){
	switch(event->getType()){
		case MBP:
			data->setUnitsMetric(!(data->getUnitsMetric()));
		case FRST:
			data->reset(true);
		case SBP:
			controller->transition("TireSizeSelectionState");
	}
}

void DistanceUnitSelectionState::onEntry(){
	display->setData("UnitSelection");
}

void DistanceUnitSelectionState::onExit(){
	//do nothing
}
