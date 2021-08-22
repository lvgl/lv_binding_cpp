/*
 * EventEx.cpp
 *
 *  Created on: Aug 6, 2021
 *      Author: fstuffdev
 */

#include "EventEx.h"

namespace lvglpp {

EventEx::EventEx() {
	fakeLvEvent.code = LV_EVENT_ALL;
}

EventEx::~EventEx() {
}

/***************************************************** The Application ******************************************************/
int EventEx::AppInit() {

	/* Create the new event callback */
	Hello = Make<LvEventCb<EventEx>>(&EventEx::Hello_cb,this);

	/* Call using operator() */
	(*Hello.get())(&fakeLvEvent);

	/* Call using Call() method */
	fakeLvEvent.code = LV_EVENT_HIT_TEST;
	Hello->Call(&fakeLvEvent);

	return 0;
}

void EventEx::AppBody() {

}

void EventEx::AppExit() {

}


void EventEx::Hello_cb(lv_event_t* event) {

	if(event) {
		switch(event->code){
		case LV_EVENT_ALL:
			printf("Throw LV_EVENT_ALL\n");
		break;

		case LV_EVENT_HIT_TEST:
			printf("Throw LV_EVENT_HIT_TEST\n");
		break;
		}
	}
}

} /* namespace lvglpp */
