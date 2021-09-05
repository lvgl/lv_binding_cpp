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

/* Globals */
static int pressed = 0;

/* Callback for button pressed */
void ButtonPressedAdd(lv_event_t *e) {
	pressed++;
	label->setTextFmt("%d", pressed);
}

/* Callback for button pressed */
void ButtonPressedSub(lv_event_t *e) {
	if (pressed > 0)
		pressed--;
	label->setTextFmt("%d", pressed);
}

/* Create Function */
void Create() {

	/* Button */
	btn = Make<LvBtn>();
	btn->addEventCb(ButtonPressedAdd, LV_EVENT_PRESSED, nullptr);
	btn->addEventCb(ButtonPressedSub, LV_EVENT_LONG_PRESSED_REPEAT, nullptr);

	/* Label */
	label = Make<LvLabel>(btn.get());
	label->setTextFmt("%d", pressed);

	/* Alignment */
	btn->align(LV_ALIGN_CENTER, 0, 0);
	label->align(LV_ALIGN_CENTER,0, 0);



}

}
