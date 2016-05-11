/*
 * SpeedDisplayState.cpp
 *
 *  Created on: May 4, 2016
 *      Author: Kai
 */

#include "SpeedDisplayState.h"

SpeedDisplayState::SpeedDisplayState(CyclometerController* c, CyclometerData* d, OutputController* dis) : CyclometerState("SpeedDisplayState", c, d, dis){};

SpeedDisplayState::~SpeedDisplayState() {
	// TODO Auto-generated destructor stub
}

void SpeedDisplayState::accept(Event event){
	switch(event.getType()){
		case MBP:
			controller->transition("DistanceDisplayState");
		case TRST:
			data->reset(false);
		case FRST:
			data->reset(true);
			controller->transition("DistanceUnitSelectionState");
		case SBP:
			data->setManual(!(data->getManual()));
		case SST:
			if (data->getManual()){
				data->setTrip(!(data->getTrip()));
			}
		default:
			break;
	}
}

void SpeedDisplayState::onEntry(){
	display->setData("Speed");
}

void SpeedDisplayState::onExit(){
	//do nothing
}

