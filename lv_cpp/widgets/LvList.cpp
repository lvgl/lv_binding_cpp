/*
 * LvList.cpp
 *
 */

#include "LvList.h"

namespace lvglpp {

LvList::LvList() : LvList(NULL) {
}

LvList::LvList(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_list_create(Parent->raw()));
	else
		cObj.reset(lv_list_create(lv_scr_act()));

	setUserData(this);
}

LvList::~LvList() {
}
lv_obj_t *LvList::addText(const char *txt){
	return lv_list_add_text(cObj.get(),txt);
	
}
lv_obj_t *LvList::addBtn(const char *icon, const char *txt){
	return lv_list_add_btn(cObj.get(),icon,txt);
	
}
const char *LvList::getBtnText(lv_obj_t *btn) const noexcept {
	return lv_list_get_btn_text(cObj.get(),btn);
	
}

} /* namespace lvglpp */
