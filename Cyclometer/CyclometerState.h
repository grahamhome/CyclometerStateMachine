/*
 * CyclometerState.h
 *
 *  Created on: May 4, 2016
 *      Author: Kai
 */

#ifndef CYCLOMETERSTATE_H_
#define CYCLOMETERSTATE_H_
#include <string>
#include "Event.h"
#include "CyclometerData.h"
#include "CyclometerController.h"
#include "OutputController.h"

class CyclometerController;

class CyclometerState {
protected:
	std::string stateID;
	CyclometerData* data;
	CyclometerController* controller;
	OutputController* display;

public:
	CyclometerState();
	CyclometerState(std::string stateID, CyclometerController* c, CyclometerData* d, OutputController* dis);
	virtual ~CyclometerState();
	virtual void accept(Event event);
	virtual void onEntry();
	virtual void onExit();
	std::string getID();

};

#endif /* CYCLOMETERSTATE_H_ */
