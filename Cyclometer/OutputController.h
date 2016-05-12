/*
 * OutputController.h
 *
 *  Created on: May 9, 2016
 *      Author: Kai
 */

#ifndef OUTPUTCONTROLLER_H_
#define OUTPUTCONTROLLER_H_

#include <string>

class OutputController {
public:
	OutputController();
	virtual ~OutputController();
	void setData(std::string s);
};

#endif /* OUTPUTCONTROLLER_H_ */
