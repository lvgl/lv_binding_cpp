/*
 * LvLine.cpp
 *
 */

#include "LvLine.h"

namespace lvglpp {

LvLine::LvLine() : LvLine(NULL) {
}

LvLine::LvLine(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_line_create(Parent->raw()));
	else
		cObj.reset(lv_line_create(lv_scr_act()));

	setUserData(this);
}

LvLine::~LvLine() {
}
LvLine& LvLine::setPoints(const lv_point_t points[], uint16_t point_num){
	lv_line_set_points(cObj.get(),points,point_num);
	return *this;
}
LvLine& LvLine::setYInvert(bool en){
	lv_line_set_y_invert(cObj.get(),en);
	return *this;
}
bool LvLine::getYInvert() const noexcept {
	return lv_line_get_y_invert(cObj.get());
	
}

} /* namespace lvglpp */
