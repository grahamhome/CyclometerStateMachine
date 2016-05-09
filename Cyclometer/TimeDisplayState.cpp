/*
 * TimeDisplayState.cpp
 *
 *  Created on: May 4, 2016
 *      Author: Kai
 */

#include "TimeDisplayState.h"

TimeDisplayState::TimeDisplayState(CyclometerController* c, CyclometerData* d, OutputDisplay* dis) : CyclometerState("TimeDisplayState", c, d, dis){};

TimeDisplayState::~TimeDisplayState() {
	// TODO Auto-generated destructor stub
}

void TimeDisplayState::accept(Events event){
	switch(event->getType()){
		case MBP:
			controller->transition("SpeedDisplayState");
		case TRST:
			data->reset(false);
		case FRST:
			data->reset(true);
			controller->transition("DistanceUnitSelectionState");
		case SBP:
			data->manual(!(data->manual()));
		case SST:
			data->trip(!(data->trip()));
	}
}

void TimeDisplayState::onEntry(){
	display->setData("Time");
}

void TimeDisplayState::onExit(){
	//do nothing
}


