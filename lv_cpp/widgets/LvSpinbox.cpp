/*
 * LvSpinbox.cpp
 *
 */

#include "LvSpinbox.h"

namespace lvglpp {

LvSpinbox::LvSpinbox() : LvSpinbox(NULL) {
}

LvSpinbox::LvSpinbox(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_spinbox_create(Parent->raw()));
	else
		cObj.reset(lv_spinbox_create(lv_scr_act()));

	setUserData(this);
}

LvSpinbox::~LvSpinbox() {
}
LvSpinbox& LvSpinbox::setValue(int32_t i){
	lv_spinbox_set_value(cObj.get(),i);
	return *this;
}
LvSpinbox& LvSpinbox::setRollover(bool b){
	lv_spinbox_set_rollover(cObj.get(),b);
	return *this;
}
LvSpinbox& LvSpinbox::setDigitFormat(uint8_t digit_count, uint8_t separator_position){
	lv_spinbox_set_digit_format(cObj.get(),digit_count,separator_position);
	return *this;
}
LvSpinbox& LvSpinbox::setStep(uint32_t step){
	lv_spinbox_set_step(cObj.get(),step);
	return *this;
}
LvSpinbox& LvSpinbox::setRange(int32_t range_min, int32_t range_max){
	lv_spinbox_set_range(cObj.get(),range_min,range_max);
	return *this;
}
int32_t LvSpinbox::getValue() const noexcept {
	return lv_spinbox_get_value(cObj.get());
	
}
int32_t LvSpinbox::getStep() const noexcept {
	return lv_spinbox_get_step(cObj.get());
	
}
LvSpinbox& LvSpinbox::stepNext(){
	lv_spinbox_step_next(cObj.get());
	return *this;
}
LvSpinbox& LvSpinbox::stepPrev(){
	lv_spinbox_step_prev(cObj.get());
	return *this;
}
bool LvSpinbox::getRollover() const noexcept {
	return lv_spinbox_get_rollover(cObj.get());
	
}
LvSpinbox& LvSpinbox::increment(){
	lv_spinbox_increment(cObj.get());
	return *this;
}
LvSpinbox& LvSpinbox::decrement(){
	lv_spinbox_decrement(cObj.get());
	return *this;
}

} /* namespace lvglpp */
