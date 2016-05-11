/*
 * TireSizeSelectionState.cpp
 *
 *  Created on: May 4, 2016
 *      Author: Kai
 */

#include "TireSizeSelectionState.h"

TireSizeSelectionState::TireSizeSelectionState(CyclometerController* c, CyclometerData* d, OutputController* dis) : CyclometerState("TireSizeSelectionState", c, d, dis){};

TireSizeSelectionState::~TireSizeSelectionState() {
	// TODO Auto-generated destructor stub
}

void TireSizeSelectionState::accept(Event event){
	switch(event.getType()){
		case MBP:
			if (data->getTireSize() < 220){
				data->setTireSize((data->getTireSize())+1);
			} else {
				data->setTireSize(190);
			}
		case FRST:
			data->reset(true);
			controller->transition("DistanceUnitSelectionState");
		case SBP:
			if (controller->testLastState() == "DistanceUnitSelectionState"){
				controller->transition("SpeedDisplayState");
			} else {
				controller->transition("DistanceDisplayState");
			}
		default:
			break;
	}
}

void TireSizeSelectionState::onEntry(){
	display->setData("TireSize");
	data->setTireSize(210);
}

void TireSizeSelectionState::onExit(){
	//do nothing
}
