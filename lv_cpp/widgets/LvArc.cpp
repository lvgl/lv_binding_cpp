/*
 * LvArc.cpp
 *
 */

#include "LvArc.h"

namespace lvglpp {

LvArc::LvArc() : LvArc(NULL) {
}

LvArc::LvArc(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_arc_create(Parent->raw()));
	else
		cObj.reset(lv_arc_create(lv_scr_act()));

	setUserData(this);
}

LvArc::~LvArc() {
}
LvArc& LvArc::setStartAngle(uint16_t start){
	lv_arc_set_start_angle(cObj.get(),start);
	return *this;
}
LvArc& LvArc::setEndAngle(uint16_t end){
	lv_arc_set_end_angle(cObj.get(),end);
	return *this;
}
LvArc& LvArc::setAngles(uint16_t start, uint16_t end){
	lv_arc_set_angles(cObj.get(),start,end);
	return *this;
}
LvArc& LvArc::setBgStartAngle(uint16_t start){
	lv_arc_set_bg_start_angle(cObj.get(),start);
	return *this;
}
LvArc& LvArc::setBgEndAngle(uint16_t end){
	lv_arc_set_bg_end_angle(cObj.get(),end);
	return *this;
}
LvArc& LvArc::setBgAngles(uint16_t start, uint16_t end){
	lv_arc_set_bg_angles(cObj.get(),start,end);
	return *this;
}
LvArc& LvArc::setRotation(uint16_t rotation){
	lv_arc_set_rotation(cObj.get(),rotation);
	return *this;
}
LvArc& LvArc::setMode(lv_arc_mode_t type){
	lv_arc_set_mode(cObj.get(),type);
	return *this;
}
LvArc& LvArc::setValue(int16_t value){
	lv_arc_set_value(cObj.get(),value);
	return *this;
}
LvArc& LvArc::setRange(int16_t min, int16_t max){
	lv_arc_set_range(cObj.get(),min,max);
	return *this;
}
LvArc& LvArc::setChangeRate(uint16_t rate){
	lv_arc_set_change_rate(cObj.get(),rate);
	return *this;
}
uint16_t LvArc::getAngleStart() const noexcept {
	return lv_arc_get_angle_start(cObj.get());
	
}
uint16_t LvArc::getAngleEnd() const noexcept {
	return lv_arc_get_angle_end(cObj.get());
	
}
uint16_t LvArc::getBgAngleStart() const noexcept {
	return lv_arc_get_bg_angle_start(cObj.get());
	
}
uint16_t LvArc::getBgAngleEnd() const noexcept {
	return lv_arc_get_bg_angle_end(cObj.get());
	
}
int16_t LvArc::getValue() const noexcept {
	return lv_arc_get_value(cObj.get());
	
}
int16_t LvArc::getMinValue() const noexcept {
	return lv_arc_get_min_value(cObj.get());
	
}
int16_t LvArc::getMaxValue() const noexcept {
	return lv_arc_get_max_value(cObj.get());
	
}
lv_arc_mode_t LvArc::getMode() const noexcept {
	return lv_arc_get_mode(cObj.get());
	
}

} /* namespace lvglpp */
