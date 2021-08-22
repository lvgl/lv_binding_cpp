/*
 * HelloEx.h
 *
 *  Created on: Aug 6, 2021
 *      Author: fstuffdev
 */

#ifndef HELLOEX_H_
#define HELLOEX_H_

#include "../lv_cpp/core/LvApp.h"
#include "../lv_cpp/widgets/LvWidgets.h"


namespace lvglpp {

class HelloEx: public LvApp {
private:

	/* Some Widgets declaration */
	LvPPointer<LvBtn> HelloButton;
	LvPPointer<LvLabel> HelloLabel;
	LvPPointer<LvTabview> view;

	/* Callbacks */
	LvEventPointer<HelloEx> Hello;
	LvEventPointer<HelloEx> HelloLong;

	void Hello_cb(lv_event_t* e);
	void HelloLong_cb(lv_event_t* e);

	/* The Application */
	int AppInit();
	void AppBody();
	void AppExit();

public:
	HelloEx();
	virtual ~HelloEx();
};

} /* namespace lvglpp */

#endif /* HELLOEX_H_ */
