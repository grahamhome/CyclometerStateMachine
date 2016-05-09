/*
 * TireSizeSelectionState.h
 *
 *  Created on: May 4, 2016
 *      Author: Kai
 */

#ifndef TIRESIZESELECTIONSTATE_H_
#define TIRESIZESELECTIONSTATE_H_
#include "CyclometerState.h"

class TireSizeSelectionState {
public:
	TireSizeSelectionState();
	TireSizeSelectionState(CyclometerController* c, CyclometerData* d, OutputController* dis);
	virtual ~TireSizeSelectionState();
	void accept(Events event);
	void onEntry();
	void onExit();

};

#endif /* TIRESIZESELECTIONSTATE_H_ */
