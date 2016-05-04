/*
 * DistanceDisplayState.cpp
 *
 *  Created on: May 4, 2016
 *      Author: Shannalotte
 */

#include "DistanceDisplayState.h"

DistanceDisplayState::DistanceDisplayState(CyclometerData* d, OutputDisplay* dis) : CyclometerState("DistanceDisplayState", d, dis){};

DistanceDisplayState::~DistanceDisplayState() {
	// TODO Auto-generated destructor stub
}

void DistanceDisplayState::accept(Events event){
	//TODO
}

void DistanceDisplayState::onEntry(){
	//TODO
}

void DistanceDisplayState::onExit(){
	//TODO
}

void DistanceDisplayState::updateData(){
	//TODO
}

void DistanceDisplayState::updateDisplay(){
	//TODO
}
