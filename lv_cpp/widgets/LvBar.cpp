/*
 * LvBar.cpp
 *
 */

#include "LvBar.h"

namespace lvglpp {

LvBar::LvBar() : LvBar(NULL) {
}

LvBar::LvBar(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_bar_create(Parent->raw()));
	else
		cObj.reset(lv_bar_create(lv_scr_act()));

	setUserData(this);
}

LvBar::~LvBar() {
}
LvBar& LvBar::setValue(int32_t value, lv_anim_enable_t anim){
	lv_bar_set_value(cObj.get(),value,anim);
	return *this;
}
LvBar& LvBar::setStartValue(int32_t value, lv_anim_enable_t anim){
	lv_bar_set_start_value(cObj.get(),value,anim);
	return *this;
}
LvBar& LvBar::setRange(int32_t min, int32_t max){
	lv_bar_set_range(cObj.get(),min,max);
	return *this;
}
LvBar& LvBar::setMode(lv_bar_mode_t mode){
	lv_bar_set_mode(cObj.get(),mode);
	return *this;
}
int32_t LvBar::getValue() const noexcept {
	return lv_bar_get_value(cObj.get());
	
}
int32_t LvBar::getStartValue() const noexcept {
	return lv_bar_get_start_value(cObj.get());
	
}
int32_t LvBar::getMinValue() const noexcept {
	return lv_bar_get_min_value(cObj.get());
	
}
int32_t LvBar::getMaxValue() const noexcept {
	return lv_bar_get_max_value(cObj.get());
	
}
lv_bar_mode_t LvBar::getMode() const noexcept {
	return lv_bar_get_mode(cObj.get());
	
}

} /* namespace lvglpp */
