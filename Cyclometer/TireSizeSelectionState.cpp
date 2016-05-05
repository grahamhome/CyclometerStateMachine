/*
 * TireSizeSelectionState.cpp
 *
 *  Created on: May 4, 2016
 *      Author: Shannalotte
 */

#include "TireSizeSelectionState.h"

TireSizeSelectionState::TireSizeSelectionState(CyclometerController* c, CyclometerData* d, OutputDisplay* dis) : CyclometerState("TireSizeSelectionState", c, d, dis){};

TireSizeSelectionState::~TireSizeSelectionState() {
	// TODO Auto-generated destructor stub
}

void TireSizeSelectionState::accept(Events event){
	//TODO
}

void TireSizeSelectionState::onEntry(){
	display->setData("TireSize");
}

void TireSizeSelectionState::onExit(){
	//do nothing
}
