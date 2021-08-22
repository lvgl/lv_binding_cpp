/*
 * LvBtn.cpp
 *
 */

#include "LvBtn.h"

namespace lvglpp {

LvBtn::LvBtn() : LvBtn(NULL) {
}

LvBtn::LvBtn(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_btn_create(Parent->raw()));
	else
		cObj.reset(lv_btn_create(lv_scr_act()));

	setUserData(this);
}

LvBtn::~LvBtn() {
}

} /* namespace lvglpp */
