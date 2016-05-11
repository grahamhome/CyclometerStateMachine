#ifndef EVENTS_H_
#define EVENTS_H_

#include "EventSignals.h"
#include <ctime>

class Event{
private:
	EventSignals eventType;
	std::time_t eventData;

public:
	Event();
	Event(std::time_t data, EventSignals type);
	EventSignals getType();
	std::time_t getData();
};

#endif
