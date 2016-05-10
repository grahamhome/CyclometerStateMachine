#ifndef EVENTS_H_
#define EVENTS_H_

#include "EventSignals.h"
#include <ctime>

class Events{
private:
	EventSignals eventType;
	std::time_t eventData;

public:
	Events();
	Events(std::time_t data, EventSignals type);
	EventSignals getType();
	std::time_t getData();
};

#endif
