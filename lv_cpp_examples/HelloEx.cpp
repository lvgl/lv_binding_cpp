/*
 * HelloEx.cpp
 *
 *  Created on: Aug 30, 2021
 *      Author: fstuffdev
 */

#include "HelloEx.h"
using namespace lvglpp;

namespace HelloEx {

/* Widgets */
LvPPointer<LvBtn> btn;
LvPPointer<LvLabel> label;

/* Callback for button pressed */
void ButtonPressed(lv_event_t* e) {
	printf("Hello\n");
}

/* Create Function */
void Create() {

	/* Button */
	btn = Make<LvBtn>();
	btn->align(LV_ALIGN_CENTER, 0, 0);
	btn->addEventCb(ButtonPressed, LV_EVENT_PRESSED, nullptr);

	/* Label */
	label = Make<LvLabel>(btn.get());
	label->setText("Hello").align(LV_ALIGN_CENTER, 0, 0);
}

}
