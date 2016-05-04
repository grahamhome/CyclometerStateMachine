#ifndef EVENTS_H_
#define EVENTS_H_

#include "EventSignals.h"
#include <ctime>

class Events{
private:
	EventSignals eventType;
	float eventData;

public:
	Events(time_t data, EventSignals type);
	EventSignals getType();
	float getData();
}
