/*
 * LvAnimimg.cpp
 *
 */

#include "LvAnimimg.h"

namespace lvglpp {

LvAnimimg::LvAnimimg() : LvAnimimg(NULL) {
}

LvAnimimg::LvAnimimg(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_animimg_create(Parent->raw()));
	else
		cObj.reset(lv_animimg_create(lv_scr_act()));

	setUserData(this);
}

LvAnimimg::~LvAnimimg() {
}
LvAnimimg& LvAnimimg::setSrc(lv_img_dsc_t *dsc[], uint8_t num){
	lv_animimg_set_src(cObj.get(),dsc,num);
	return *this;
}
LvAnimimg& LvAnimimg::start(){
	lv_animimg_start(cObj.get());
	return *this;
}
LvAnimimg& LvAnimimg::setDuration(uint32_t duration){
	lv_animimg_set_duration(cObj.get(),duration);
	return *this;
}
LvAnimimg& LvAnimimg::setRepeatCount(uint16_t count){
	lv_animimg_set_repeat_count(cObj.get(),count);
	return *this;
}

} /* namespace lvglpp */
