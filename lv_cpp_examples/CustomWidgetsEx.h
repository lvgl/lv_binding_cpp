/*
 * CustomWidgetsEx.h
 *
 *  Created on: Aug 15, 2021
 *      Author: fstuffdev
 */

#ifndef CUSTOMWIDGETSEX_H_
#define CUSTOMWIDGETSEX_H_

#include "../lv_cpp/core/LvApp.h"
#include "../lv_cpp/widgets/LvWidgets.h"
#include "../lv_cpp/custom/widgets/LvTimeRoller.h"

namespace lvglpp {

class CustomWidgetsEx: public LvApp {
private:
	/* Timer Roller custom widgets */
	LvPPointer<LvTimeRoller> time;

	/* The Application */
	int AppInit();
	void AppBody();
	void AppExit();
public:
	CustomWidgetsEx();
	virtual ~CustomWidgetsEx();
};

} /* namespace lvglpp */

#endif /* CUSTOMWIDGETSEX_H_ */
