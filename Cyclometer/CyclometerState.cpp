/*
 * CyclometerState.cpp
 *
 *  Created on: May 4, 2016
 *      Author: Kai
 */

#include "CyclometerState.h"

CyclometerState::CyclometerState() {
	// TODO Auto-generated constructor stub

}

CyclometerState::CyclometerState(std::string id, CyclometerController* c, CyclometerData* d, OutputController* dis){
	stateID = id;
	controller = c;
	data = d;
	display = dis;
}

CyclometerState::~CyclometerState() {
	// TODO Auto-generated destructor stub
}

void CyclometerState::accept(Event event){
	//do nothing
}

void CyclometerState::onEntry(){
	//do nothing
}

void CyclometerState::onExit(){
	//do nothing
}

std::string CyclometerState::getID(){
	return stateID;
}
