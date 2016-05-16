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

void TimeDisplayState::onEntry(){
	display->setData("Time");
}

void TimeDisplayState::onExit(){
	//do nothing
}


