/*
 * LvTick.cpp
 *
 *  Created on: May 17, 2021
 *      Author: fstuffdev
 */

#include "LvTick.h"

namespace lvglpp {

LvTick::LvTick() : LvTick(5) {

}

LvTick::LvTick(unsigned int _ms) {
	ms = _ms;
}

void LvTick::Body() {
	LvSleep(ms);
	lv_tick_inc(ms);
}

LvTick::~LvTick() {

}

} /* namespace lvGL */
