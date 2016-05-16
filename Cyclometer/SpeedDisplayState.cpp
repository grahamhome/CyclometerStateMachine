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
			break;
		case TRST:
			data->reset(false);
			break;
		case FRST:
			data->reset(true);
			controller->transition("DistanceUnitSelectionState");
			break;
		case SBP:
			data->setManual(!(data->getManual()));
			break;
		case SST:
			if (data->getManual()){
				data->setTrip(!(data->getTrip()));
			}
			break;
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

