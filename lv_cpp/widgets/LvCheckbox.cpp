/*
 * LvCheckbox.cpp
 *
 */

#include "LvCheckbox.h"

namespace lvglpp {

LvCheckbox::LvCheckbox() : LvCheckbox(NULL) {
}

LvCheckbox::LvCheckbox(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_checkbox_create(Parent->raw()));
	else
		cObj.reset(lv_checkbox_create(lv_scr_act()));

	setUserData(this);
}

LvCheckbox::~LvCheckbox() {
}
LvCheckbox& LvCheckbox::setText(const char *txt){
	lv_checkbox_set_text(cObj.get(),txt);
	return *this;
}
LvCheckbox& LvCheckbox::setTextStatic(const char *txt){
	lv_checkbox_set_text_static(cObj.get(),txt);
	return *this;
}
const char *LvCheckbox::getText() const noexcept {
	return lv_checkbox_get_text(cObj.get());
	
}

} /* namespace lvglpp */
