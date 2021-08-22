/*
 * CustomWidgetsEx.cpp
 *
 *  Created on: Aug 15, 2021
 *      Author: fstuffdev
 */

#include "CustomWidgetsEx.h"

namespace lvglpp {

CustomWidgetsEx::CustomWidgetsEx() {
}

CustomWidgetsEx::~CustomWidgetsEx() {
}

/***************************************************** The Application ******************************************************/
int CustomWidgetsEx::AppInit() {

	time = Make<LvTimeRoller>();
	time->align(LV_ALIGN_CENTER, 0, 0);

	return 0;
}

void CustomWidgetsEx::AppBody() {
}

void CustomWidgetsEx::AppExit() {

}


} /* namespace lvglpp */
