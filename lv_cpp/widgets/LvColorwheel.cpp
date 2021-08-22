/*
 * LvColorwheel.cpp
 *
 */

#include "LvColorwheel.h"

namespace lvglpp {

LvColorwheel::LvColorwheel() : LvColorwheel(NULL) {
}

LvColorwheel::LvColorwheel(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_colorwheel_create(Parent->raw(),true));
	else
		cObj.reset(lv_colorwheel_create(lv_scr_act(),true));

	setUserData(this);
}

LvColorwheel::~LvColorwheel() {
}
bool LvColorwheel::setHsv(lv_color_hsv_t hsv){
	return lv_colorwheel_set_hsv(cObj.get(),hsv);
	
}
bool LvColorwheel::setRgb(lv_color_t color){
	return lv_colorwheel_set_rgb(cObj.get(),color);
	
}
LvColorwheel& LvColorwheel::setMode(lv_colorwheel_mode_t mode){
	lv_colorwheel_set_mode(cObj.get(),mode);
	return *this;
}
LvColorwheel& LvColorwheel::setModeFixed(bool fixed){
	lv_colorwheel_set_mode_fixed(cObj.get(),fixed);
	return *this;
}
lv_color_hsv_t LvColorwheel::getHsv() const noexcept {
	return lv_colorwheel_get_hsv(cObj.get());
	
}
lv_color_t LvColorwheel::getRgb() const noexcept {
	return lv_colorwheel_get_rgb(cObj.get());
	
}
lv_colorwheel_mode_t LvColorwheel::getColorMode() const noexcept {
	return lv_colorwheel_get_color_mode(cObj.get());
	
}
bool LvColorwheel::getColorModeFixed() const noexcept {
	return lv_colorwheel_get_color_mode_fixed(cObj.get());
	
}

} /* namespace lvglpp */
