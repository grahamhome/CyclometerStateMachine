#ifndef EVENTS_H_
#define EVENTS_H_

#include "EventSignals.h"

class Events{
private:
	EventSignals eventType;
	float eventData;

public:
	Events(float data, EventSignals type);
	EventSignals getType();
	float getData();
}