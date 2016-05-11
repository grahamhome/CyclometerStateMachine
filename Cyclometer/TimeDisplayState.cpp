/*
 * TimeDisplayState.cpp
 *
 *  Created on: May 4, 2016
 *      Author: Kai
 */

#include "TimeDisplayState.h"

TimeDisplayState::TimeDisplayState(CyclometerController* c, CyclometerData* d, OutputController* dis) : CyclometerState("TimeDisplayState", c, d, dis){};

TimeDisplayState::~TimeDisplayState() {
	// TODO Auto-generated destructor stub
}

void TimeDisplayState::accept(Event event){
	switch(event.getType()){
		case MBP:
			controller->transition("SpeedDisplayState");
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

void TimeDisplayState::onEntry(){
	display->setData("Time");
}

void TimeDisplayState::onExit(){
	//do nothing
}


