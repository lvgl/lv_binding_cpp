/*
 * LvWin.cpp
 *
 */

#include "LvWin.h"

namespace lvglpp {

LvWin::LvWin() : LvWin(NULL) {
}

LvWin::LvWin(LvObj* Parent) : LvWin(Parent,10) {
}

LvWin::LvWin(LvObj* Parent,lv_coord_t header_height) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_win_create(Parent->raw(),header_height ));
	else
		cObj.reset(lv_win_create(lv_scr_act(),header_height));

	setUserData(this);
}

LvWin::~LvWin() {
}
lv_obj_t *LvWin::addTitle(const char *txt){
	return lv_win_add_title(cObj.get(),txt);
	
}
lv_obj_t *LvWin::addBtn(const void *icon, lv_coord_t btn_w){
	return lv_win_add_btn(cObj.get(),icon,btn_w);
	
}
lv_obj_t *LvWin::getHeader() const noexcept {
	return lv_win_get_header(cObj.get());
	
}
lv_obj_t *LvWin::getContent() const noexcept {
	return lv_win_get_content(cObj.get());
	
}

} /* namespace lvglpp */
