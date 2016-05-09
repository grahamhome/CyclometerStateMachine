#includes "Events.h"

Events::Events(time_t data, EventSignals type){
	eventType = type;
	time_t = data;
}

EventSignals Events::getType(){
	return eventType;
}

float Events::getData(){
	return eventData;
}
