/*
 * DistanceDisplayState.cpp
 *
 *  Created on: May 4, 2016
 *      Author: Kai
 */

#include "DistanceDisplayState.h"

DistanceDisplayState::DistanceDisplayState(CyclometerController* c, CyclometerData* d, OutputController* dis) : CyclometerState("DistanceDisplayState", c, d, dis){};

DistanceDisplayState::~DistanceDisplayState() {
	// TODO Auto-generated destructor stub
}

void DistanceDisplayState::accept(Events event){
	switch(event.getType()){
		case MBP:
			controller->transition("TimeDisplayState");
		case TRST:
			data->reset(false);
		case FRST:
			data->reset(true);
			controller->transition("DistanceUnitSelectionState");
		case SBP:
			controller->transition("TireSizeSelectionState");
		case SST:
			data->setTrip(!(data->getTrip()));
		default:
			break;
	}
}

void DistanceDisplayState::onEntry(){
	display->setData("Distance");
}

void DistanceDisplayState::onExit(){
	//do nothing
}

