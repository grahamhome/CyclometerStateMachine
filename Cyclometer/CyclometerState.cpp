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

CyclometerState::CyclometerState(string id, CyclometerData* d, OutputController* dis){
	stateID = id;
	data = d;
	display = dis;
}

CyclometerState::~CyclometerState() {
	// TODO Auto-generated destructor stub
}

void CyclometerState::accept(Events event){
	//do nothing
}

void CyclometerState::onEntry(){
	//do nothing
}

void CyclometerState::onExit(){
	//do nothing
}

void CyclometerState::updateData(){
	//do nothing
}

void CyclometerState::updateDisplay(){
	//do nothing
}

std::string CyclometerState::getID(){
	return stateID;
}
