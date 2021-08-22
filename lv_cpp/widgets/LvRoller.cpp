/*
 * LvRoller.cpp
 *
 */

#include "LvRoller.h"

namespace lvglpp {

LvRoller::LvRoller() : LvRoller(NULL) {
}

LvRoller::LvRoller(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_roller_create(Parent->raw()));
	else
		cObj.reset(lv_roller_create(lv_scr_act()));

	setUserData(this);
}

LvRoller::~LvRoller() {
}
LvRoller& LvRoller::setOptions(const char *options, lv_roller_mode_t mode){
	lv_roller_set_options(cObj.get(),options,mode);
	return *this;
}
LvRoller& LvRoller::setSelected(uint16_t sel_opt, lv_anim_enable_t anim){
	lv_roller_set_selected(cObj.get(),sel_opt,anim);
	return *this;
}
LvRoller& LvRoller::setVisibleRowCount(uint8_t row_cnt){
	lv_roller_set_visible_row_count(cObj.get(),row_cnt);
	return *this;
}
uint16_t LvRoller::getSelected() const noexcept {
	return lv_roller_get_selected(cObj.get());
	
}
LvRoller& LvRoller::getSelectedStr(char *buf, uint32_t buf_size){
	lv_roller_get_selected_str(cObj.get(),buf,buf_size);
	return *this;
}
const char *LvRoller::getOptions() const noexcept {
	return lv_roller_get_options(cObj.get());
	
}
uint16_t LvRoller::getOptionCnt() const noexcept {
	return lv_roller_get_option_cnt(cObj.get());
	
}

} /* namespace lvglpp */
