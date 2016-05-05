/*
 * SpeedDisplayState.cpp
 *
 *  Created on: May 4, 2016
 *      Author: Shannalotte
 */

#include "SpeedDisplayState.h"

SpeedDisplayState::SpeedDisplayState(CyclometerController* c, CyclometerData* d, OutputDisplay* dis) : CyclometerState("SpeedDisplayState", c, d, dis){};

SpeedDisplayState::~SpeedDisplayState() {
	// TODO Auto-generated destructor stub
}

void SpeedDisplayState::accept(Events event){
	//TODO
}

void SpeedDisplayState::onEntry(){
	display->setData("Speed");
}

void SpeedDisplayState::onExit(){
	//do nothing
}

