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
#include <ctime>
#include <iostream>

int main() {
	//construct the controller
	CyclometerController context();
	context.run();

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
	printf("Unit Metric: %B\n", context->testData->unitMetric());
	context->accept(eMBP);
	printf("Unit Metric: %B\n", context->testData->unitMetric());
	//getting to tire size selection
	context->accept(eSBP);

	//increase tire size by 3
	context->accept(eMBP);
	context->accept(eMBP);
	context->accept(eMBP);
	// getting to speed display
	context->accept(eSBP);

	//change to manual and then change it back
	context->accept(eSBP);
	context->accept(eSBP);
	//getting to Distance display
	context->accept(eMBP);

	//getting to time display
	context->accept(eMBP);

	//change to manual and then change it back
	context->accept(eSBP);
	context->accept(eSBP);
	//getting to speed display
	context->accept(eMBP);


}
