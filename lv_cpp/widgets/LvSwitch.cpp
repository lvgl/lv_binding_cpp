/*
 * LvSwitch.cpp
 *
 */

#include "LvSwitch.h"

namespace lvglpp {

LvSwitch::LvSwitch() : LvSwitch(NULL) {
}

LvSwitch::LvSwitch(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_switch_create(Parent->raw()));
	else
		cObj.reset(lv_switch_create(lv_scr_act()));

	setUserData(this);
}

LvSwitch::~LvSwitch() {
}

} /* namespace lvglpp */
