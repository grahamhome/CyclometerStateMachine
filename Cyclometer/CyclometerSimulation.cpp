/*
 * CyclometerSimulation.cpp
 *
 *  Created on: May 9, 2016
 *      Author: Kai
 */

#include <stdio.h>
#include <ctype.h>
#include "CyclometerController.h"
#include "Event.h"
#include "EventSignals.h"
#include <ctime>
#include <iostream>

int main() {
	//construct the controller
	CyclometerController context;
	context.run();

	//testing for the controller

	//creating all the event signals
	EventSignals wrp = WRP;
	EventSignals sst = SST;
	EventSignals mbp = MBP;
	EventSignals sbp = SBP;
	EventSignals trst = TRST;

	//creating all the events
	Event eWRP(std::time(0), wrp);
	Event eSST(std::time(0), sst);
	Event eSBP(std::time(0), sbp);
	Event eMBP(std::time(0), mbp);
	Event eTRST(std::time(0), trst);

	//changing the states and do the stuff

	//changing distance unit
	printf("Unit Metric: %B\n", context.testData().getUnitsMetric());
	context.accept(eMBP);
	printf("Unit Metric: %B\n", context.testData().getUnitsMetric());
	//getting to tire size selection
	context.accept(eSBP);

	//increase tire size by 3
	context.accept(eMBP);
	context.accept(eMBP);
	context.accept(eMBP);
	// getting to speed display
	context.accept(eSBP);

	//change to manual and then change it back
	context.accept(eSBP);
	context.accept(eSBP);
	//getting to Distance display
	context.accept(eMBP);

	//getting to time display
	context.accept(eMBP);

	//change to manual and then change it back
	context.accept(eSBP);
	context.accept(eSBP);
	//getting to speed display
	context.accept(eMBP);


}
