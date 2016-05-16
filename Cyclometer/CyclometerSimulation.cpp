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
#include <sys/neutrino.h>
#include <unistd.h>

void *runContext(void *context){

	(*(CyclometerController*)context).run();

}

int main() {

	int privity_err;
	/* Root permissions to access the hardware */
	privity_err = ThreadCtl(_NTO_TCTL_IO, NULL);
	if (privity_err == -1)
	{
	printf("can't get root permissions\n");
	}


	//construct the controller
	printf("starting\n");
	CyclometerData *data = new CyclometerData();
	CyclometerController context(data);
	printf("created controller\n");

	pthread_t contextThread;
	pthread_create(&contextThread, NULL, runContext, (void *)&context);

	//testing for the controller

	//creating all the event signals
	EventSignals wrp = WRP;
	EventSignals sst = SST;
	EventSignals mbp = MBP;
	EventSignals sbp = SBP;
	EventSignals trst = TRST;

	printf("created the event signals\n");

	//creating all the events
	Event eWRP(std::time(0), wrp);
	Event eSST(std::time(0), sst);
	Event eSBP(std::time(0), sbp);
	Event eMBP(std::time(0), mbp);
	Event eTRST(std::time(0), trst);

	printf("created the events\n");

	//changing the states and do the stuff

	//changing distance unit
	printf("main: 1st time: %d\n",context.testData()->getUnitsMetric());
	context.accept(eMBP);
	sleep(1);
	printf("main: 2nd time: %d\n",context.testData()->getUnitsMetric());

	//getting to tire size selection

	context.accept(eSBP);
	sleep(1);
	std::cout<<"main: current state: "<< context.testCurrentState();
	printf("\n");

	//increase tire size by 3
	context.accept(eMBP);
	context.accept(eMBP);
	context.accept(eMBP);
	sleep(1);
	printf("main: tire size: %d\n",context.testData()->getTireSize());

	// getting to speed display
	context.accept(eSBP);
	sleep(1);
	std::cout<<"main: current state: "<< context.testCurrentState();
	printf("\n");
	//toggle manual on and off
	context.accept(eSST);
	sleep(1);
	printf("main: is trip on: %d\n",context.testData()->getTrip());
	context.accept(eSST);
	sleep(1);
	printf("main: is trip on: %d\n",context.testData()->getTrip());

	//change to manual and then change it back
	context.accept(eSBP);
	sleep(1);
	printf("main: manual mode: %d\n",context.testData()->getManual());
	context.accept(eSBP);
	sleep(1);
	printf("main: manual mode: %d\n",context.testData()->getManual());
	//getting to Distance display
	context.accept(eMBP);
	sleep(1);
	std::cout<<"main: current state: "<< context.testCurrentState();
	printf("\n");
	//toggle manual on and off
	context.accept(eSST);
	sleep(1);
	printf("main: is trip on: %d\n",context.testData()->getTrip());
	context.accept(eSST);
	sleep(1);
	printf("main: is trip on: %d\n",context.testData()->getTrip());

	//getting to time display
	context.accept(eMBP);
	sleep(1);
	std::cout<<"main: current state: "<< context.testCurrentState();
	printf("\n");
	//toggle manual on and off
	context.accept(eSST);
	sleep(1);
	printf("main: is trip on: %d\n",context.testData()->getTrip());
	context.accept(eSST);
	sleep(1);
	printf("main: is trip on: %d\n",context.testData()->getTrip());

	//change to manual and then change it back
	context.accept(eSBP);
	sleep(1);
	printf("main: manual mode: %d\n",context.testData()->getManual());
	context.accept(eSBP);
	sleep(1);
	printf("main: manual mode: %d\n",context.testData()->getManual());
	//getting to speed display
	context.accept(eMBP);
	sleep(1);
	std::cout<<"main: current state: "<< context.testCurrentState();
	printf("\n");
	//getting to distance display
	context.accept(eMBP);
	sleep(1);
	std::cout<<"main: current state: "<< context.testCurrentState();
	printf("\n");
	//getting to tire size selection display
	context.accept(eSBP);
	sleep(1);
	std::cout<<"main: current state: "<< context.testCurrentState();
	printf("\n");
	//getting to distance display
	context.accept(eSBP);
	sleep(1);
	std::cout<<"main: current state: "<< context.testCurrentState();
	printf("\n");


}


