#include "Events.h"

Events::Events(){

}

Events::Events(std::time_t data, EventSignals type){
	eventType = type;
	eventData = data;
}

EventSignals Events::getType(){
	return eventType;
}

std::time_t Events::getData(){
	return eventData;
}
