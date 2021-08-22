/*
 * LvImg.cpp
 *
 */

#include "LvImg.h"

namespace lvglpp {

LvImg::LvImg() : LvImg(NULL) {
}

LvImg::LvImg(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_img_create(Parent->raw()));
	else
		cObj.reset(lv_img_create(lv_scr_act()));

	setUserData(this);
}

LvImg::~LvImg() {
}
LvImg& LvImg::setSrc(const void *src){
	lv_img_set_src(cObj.get(),src);
	return *this;
}
LvImg& LvImg::setOffsetX(lv_coord_t x){
	lv_img_set_offset_x(cObj.get(),x);
	return *this;
}
LvImg& LvImg::setOffsetY(lv_coord_t y){
	lv_img_set_offset_y(cObj.get(),y);
	return *this;
}
LvImg& LvImg::setAngle(int16_t angle){
	lv_img_set_angle(cObj.get(),angle);
	return *this;
}
LvImg& LvImg::setPivot(lv_coord_t x, lv_coord_t y){
	lv_img_set_pivot(cObj.get(),x,y);
	return *this;
}
LvImg& LvImg::setZoom(uint16_t zoom){
	lv_img_set_zoom(cObj.get(),zoom);
	return *this;
}
LvImg& LvImg::setAntialias(bool antialias){
	lv_img_set_antialias(cObj.get(),antialias);
	return *this;
}
const void *LvImg::getSrc() const noexcept {
	return lv_img_get_src(cObj.get());
	
}
lv_coord_t LvImg::getOffsetX() const noexcept {
	return lv_img_get_offset_x(cObj.get());
	
}
lv_coord_t LvImg::getOffsetY() const noexcept {
	return lv_img_get_offset_y(cObj.get());
	
}
uint16_t LvImg::getAngle() const noexcept {
	return lv_img_get_angle(cObj.get());
	
}
LvImg& LvImg::getPivot(lv_point_t *pivot){
	lv_img_get_pivot(cObj.get(),pivot);
	return *this;
}
uint16_t LvImg::getZoom() const noexcept {
	return lv_img_get_zoom(cObj.get());
	
}
bool LvImg::getAntialias() const noexcept {
	return lv_img_get_antialias(cObj.get());
	
}

} /* namespace lvglpp */
