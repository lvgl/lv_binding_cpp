/*
 * LvCalendar.cpp
 *
 */

#include "LvCalendar.h"

namespace lvglpp {

LvCalendar::LvCalendar() : LvCalendar(NULL) {
}

LvCalendar::LvCalendar(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_calendar_create(Parent->raw()));
	else
		cObj.reset(lv_calendar_create(lv_scr_act()));

	setUserData(this);
}

LvCalendar::~LvCalendar() {
}

} /* namespace lvglpp */
