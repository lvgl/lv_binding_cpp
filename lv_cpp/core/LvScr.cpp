/*
 * LvScr.cpp
 *
 */

#include "LvScr.h"

namespace lvglpp {


LvScr::LvScr() : LvScr(NULL) {
}

LvScr::LvScr(LvObj* Parent) : LvObj(Parent) {
	setUserData(this);
}

LvScr::~LvScr() {

}

LvScr& LvScr::Load() {
	lv_scr_load(cObj.get());
	return *this;
}

LvScr& LvScr::LoadAnim(lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool auto_del) {
	lv_scr_load_anim(cObj.get(), anim_type, time, delay, auto_del);
	return *this;
}


} /* namespace lvglpp */
