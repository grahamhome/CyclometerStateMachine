/*
 * DistanceDisplayState.cpp
 *
 *  Created on: May 4, 2016
 *      Author: Shannalotte
 */

#include "DistanceDisplayState.h"

DistanceDisplayState::DistanceDisplayState(CyclometerController* c, CyclometerData* d, OutputDisplay* dis) : CyclometerState("DistanceDisplayState", c, d, dis){};

DistanceDisplayState::~DistanceDisplayState() {
	// TODO Auto-generated destructor stub
}

void DistanceDisplayState::accept(Events event){

}

void DistanceDisplayState::onEntry(){
	display->setData("Distance");
}

void DistanceDisplayState::onExit(){
	//do nothing
}

