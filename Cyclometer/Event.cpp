#include "Event.h"

Event::Event(){

}

Event::Event(std::time_t data, EventSignals type){
	eventType = type;
	eventData = data;
}

EventSignals Event::getType(){
	return eventType;
}

std::time_t Event::getData(){
	return eventData;
}
