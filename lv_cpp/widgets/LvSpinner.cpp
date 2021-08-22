/*
 * LvSpinner.cpp
 *
 */

#include "LvSpinner.h"

namespace lvglpp {

LvSpinner::LvSpinner() : LvSpinner(NULL) {
}

LvSpinner::LvSpinner(LvObj* Parent) :  LvSpinner(Parent,0,100){
}

LvSpinner::LvSpinner(LvObj* Parent,uint32_t time ,uint32_t arc_length) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_spinner_create(Parent->raw(),time ,arc_length));
	else
		cObj.reset(lv_spinner_create(lv_scr_act(),time ,arc_length));

	setUserData(this);
}

LvSpinner::~LvSpinner() {
}

} /* namespace lvglpp */
