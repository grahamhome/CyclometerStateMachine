#includes "Event.h"

Events::Events(float data, EventSignals type){
	eventType = type;
	eventData = data;
}

EventSignals Events::getType(){
	return eventType;
}

float Events::getData(){
	return eventData;
}