/*
 * EventEx.h
 *
 *  Created on: Aug 6, 2021
 *      Author: fstuffdev
 */

#ifndef EVENTEX_H_
#define EVENTEX_H_

#include "../lv_cpp/core/LvApp.h"
#include "../lv_cpp/widgets/LvWidgets.h"


namespace lvglpp {

class EventEx: public LvApp {
private:

	/* Event Callback declatation */
	LvEventPointer<EventEx> Hello;
	void Hello_cb(lv_event_t* event );

	/* Variables */
	lv_event_t fakeLvEvent;

	/* The Application */
	int AppInit();
	void AppBody();
	void AppExit();

public:
	EventEx();
	virtual ~EventEx();
};

} /* namespace lvglpp */

#endif /* EVENTEX_H_ */
