/*
 * CyclometerState.h
 *
 *  Created on: May 4, 2016
 *      Author: Kai
 */

#ifndef CYCLOMETERSTATE_H_
#define CYCLOMETERSTATE_H_
#include <string>

class CyclometerState {
protected:
	std::string stateID;
	CyclometerData* data;
	OutputController* display;

public:
	CyclometerState();
	CyclometerState(std::string stateID, CyclometerData* d, OutputController* dis);
	virtual ~CyclometerState();
	virtual void accept(Events event);
	virtual void onEntry();
	virtual void onExit();
	std::string getID();

};

#endif /* CYCLOMETERSTATE_H_ */
