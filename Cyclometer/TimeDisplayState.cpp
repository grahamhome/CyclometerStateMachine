/*
 * TimeDisplayState.cpp
 *
 *  Created on: May 4, 2016
 *      Author: Shannalotte
 */

#include "TimeDisplayState.h"

TimeDisplayState::TimeDisplayState(CyclometerController* c, CyclometerData* d, OutputDisplay* dis) : CyclometerState("TimeDisplayState", c, d, dis){};

TimeDisplayState::~TimeDisplayState() {
	// TODO Auto-generated destructor stub
}

void TimeDisplayState::accept(Events event){
	//TODO
}

void TimeDisplayState::onEntry(){
	display->setData("Time");
}

void TimeDisplayState::onExit(){
	//do nothing
}


