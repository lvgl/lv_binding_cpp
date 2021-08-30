/*
 * lvglpp.cpp
 *
 *  Created on: Jul 19, 2021
 *      Author: fstuffdev
 */

#include "lvglpp.h"
#include "LvDisplay.h"
#include "LvIndev.h"

namespace lvglpp {

LvPPointer<LvDisplay> Display;
LvPPointer<LvInput> Input;

/* Init lvgl */
void Init() {
	lv_init();
}

void DefaultPeripheral() {

	/* Create Default Display */
	if (Display.get() == nullptr)
		Display = Make<LvDisplay>();

	/* Create Default Input */
	if (Input.get() == nullptr)
		Input = Make<LvInput>();
}

void Handler(unsigned int ms) {
	lv_tick_inc(ms);
	lv_timer_handler();

}

}

