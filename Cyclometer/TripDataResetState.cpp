/*
 * TripDataResetState.cpp
 *
 *  Created on: May 4, 2016
 *      Author: Kai
 */

#include "TripDataResetState.h"

TripDataResetState::TripDataResetState(CyclometerData* d, OutputDisplay* dis) : CyclometerState("TripDataResetState", d, dis){};

TripDataResetState::~TripDataResetState() {
	// TODO Auto-generated destructor stub
}

void TripDataResetState::accept(Events event){
	//TODO
}

void TripDataResetState::onEntry(){
	display->setData("Reset");
}

void TripDataResetState::onExit(){
	//TODO
}


