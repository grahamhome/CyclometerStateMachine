/*
 * DistanceUnitSelectionState.cpp
 *
 *  Created on: May 4, 2016
 *      Author: Shannalotte
 */

#include "DistanceUnitSelectionState.h"

DistanceUnitSelectionState::DistanceUnitSelectionState(CyclometerData* d, OutputDisplay* dis) : CyclometerState("DistanceUnitSelectionState", d, dis){};


DistanceUnitSelectionState::~DistanceUnitSelectionState() {
	// TODO Auto-generated destructor stub
}

void DistanceUnitSelectionState::accept(Events event){
	//TODO
}

void DistanceUnitSelectionState::onEntry(){
	display->setData("UnitSelection");
}

void DistanceUnitSelectionState::onExit(){
	//do nothing
}
