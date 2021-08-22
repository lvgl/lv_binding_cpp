/*
 * LvSlider.cpp
 *
 */

#include "LvSlider.h"

namespace lvglpp {

LvSlider::LvSlider() : LvSlider(NULL) {
}

LvSlider::LvSlider(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_slider_create(Parent->raw()));
	else
		cObj.reset(lv_slider_create(lv_scr_act()));

	setUserData(this);
}

LvSlider::~LvSlider() {
}
LvSlider& LvSlider::setValue(int32_t value, lv_anim_enable_t anim){
	lv_slider_set_value(cObj.get(),value,anim);
	return *this;
}
LvSlider& LvSlider::setLeftValue(int32_t value, lv_anim_enable_t anim){
	lv_slider_set_left_value(cObj.get(),value,anim);
	return *this;
}
LvSlider& LvSlider::setRange(int32_t min, int32_t max){
	lv_slider_set_range(cObj.get(),min,max);
	return *this;
}
LvSlider& LvSlider::setMode(lv_slider_mode_t mode){
	lv_slider_set_mode(cObj.get(),mode);
	return *this;
}
int32_t LvSlider::getValue() const noexcept {
	return lv_slider_get_value(cObj.get());
	
}
int32_t LvSlider::getLeftValue() const noexcept {
	return lv_slider_get_left_value(cObj.get());
	
}
int32_t LvSlider::getMinValue() const noexcept {
	return lv_slider_get_min_value(cObj.get());
	
}
int32_t LvSlider::getMaxValue() const noexcept {
	return lv_slider_get_max_value(cObj.get());
	
}
lv_slider_mode_t LvSlider::getMode() const noexcept {
	return lv_slider_get_mode(cObj.get());
	
}
bool LvSlider::isDragged(){
	return lv_slider_is_dragged(cObj.get());
	
}

} /* namespace lvglpp */
