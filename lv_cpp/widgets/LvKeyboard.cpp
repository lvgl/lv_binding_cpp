/*
 * LvKeyboard.cpp
 *
 */

#include "LvKeyboard.h"

namespace lvglpp {

LvKeyboard::LvKeyboard() : LvKeyboard(NULL) {
}

LvKeyboard::LvKeyboard(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_keyboard_create(Parent->raw()));
	else
		cObj.reset(lv_keyboard_create(lv_scr_act()));

	setUserData(this);
}

LvKeyboard::~LvKeyboard() {
}
LvKeyboard& LvKeyboard::setTextarea(lv_obj_t *ta){
	lv_keyboard_set_textarea(cObj.get(),ta);
	return *this;
}
LvKeyboard& LvKeyboard::setMode(lv_keyboard_mode_t mode){
	lv_keyboard_set_mode(cObj.get(),mode);
	return *this;
}
LvKeyboard& LvKeyboard::setMap(lv_keyboard_mode_t mode, const char *map[], const lv_btnmatrix_ctrl_t ctrl_map[]){
	lv_keyboard_set_map(cObj.get(),mode,map,ctrl_map);
	return *this;
}
lv_obj_t *LvKeyboard::getTextarea() const noexcept {
	return lv_keyboard_get_textarea(cObj.get());
	
}
lv_keyboard_mode_t LvKeyboard::getMode() const noexcept {
	return lv_keyboard_get_mode(cObj.get());
	
}

} /* namespace lvglpp */
