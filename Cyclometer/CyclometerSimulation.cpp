/*
 * CyclometerSimulation.cpp
 *
 *  Created on: May 9, 2016
 *      Author: Kai
 */

#include <stdio.h>
#include <ctype.h>
#include "CyclometerController.h"
#include "Events.h"
#include "EventSignals.h"

int main() {
	//construct the controller
	CyclometerController context();

	//testing for the controller

	//creating all the event signals
	EventSignals wrp = WRP;
	EventSignals sst = SST;
	EventSignals mbp = MBP;
	EventSignals sbp = SBP;
	EventSignals trst = TRST;

	//creating all the events
	Events eWRP(std::time(nullptr), wrp);
	Events eSST(std::time(nullptr), sst);
	Events eSBP(std::time(nullptr), sbp);
	Events eMBP(std::time(nullptr), mbp);
	Events eTRST(std::time(nullptr), trst);

	//changing the states and do the stuff

	//changing distance unit
	context->accept(eMBP);
	//getting to tire size selection
	context->accept(eSBP);
	//increase tire size by 3
	context->accept(eMBP);
	context->accept(eMBP);
	context->accept(eMBP);
	// getting to speed display
	context->accept(eSBP);


}
