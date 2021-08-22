/*
 * LvBtnmatrix.cpp
 *
 */

#include "LvBtnmatrix.h"

namespace lvglpp {

LvBtnmatrix::LvBtnmatrix() : LvBtnmatrix(NULL) {
}

LvBtnmatrix::LvBtnmatrix(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_btnmatrix_create(Parent->raw()));
	else
		cObj.reset(lv_btnmatrix_create(lv_scr_act()));

	setUserData(this);
}

LvBtnmatrix::~LvBtnmatrix() {
}
LvBtnmatrix& LvBtnmatrix::setMap(const char *map[]){
	lv_btnmatrix_set_map(cObj.get(),map);
	return *this;
}
LvBtnmatrix& LvBtnmatrix::setCtrlMap(const lv_btnmatrix_ctrl_t ctrl_map[]){
	lv_btnmatrix_set_ctrl_map(cObj.get(),ctrl_map);
	return *this;
}
LvBtnmatrix& LvBtnmatrix::setSelectedBtn(uint16_t btn_id){
	lv_btnmatrix_set_selected_btn(cObj.get(),btn_id);
	return *this;
}
LvBtnmatrix& LvBtnmatrix::setBtnCtrl(uint16_t btn_id, lv_btnmatrix_ctrl_t ctrl){
	lv_btnmatrix_set_btn_ctrl(cObj.get(),btn_id,ctrl);
	return *this;
}
LvBtnmatrix& LvBtnmatrix::clearBtnCtrl(uint16_t btn_id, lv_btnmatrix_ctrl_t ctrl){
	lv_btnmatrix_clear_btn_ctrl(cObj.get(),btn_id,ctrl);
	return *this;
}
LvBtnmatrix& LvBtnmatrix::setBtnCtrlAll(lv_btnmatrix_ctrl_t ctrl){
	lv_btnmatrix_set_btn_ctrl_all(cObj.get(),ctrl);
	return *this;
}
LvBtnmatrix& LvBtnmatrix::clearBtnCtrlAll(lv_btnmatrix_ctrl_t ctrl){
	lv_btnmatrix_clear_btn_ctrl_all(cObj.get(),ctrl);
	return *this;
}
LvBtnmatrix& LvBtnmatrix::setBtnWidth(uint16_t btn_id, uint8_t width){
	lv_btnmatrix_set_btn_width(cObj.get(),btn_id,width);
	return *this;
}
LvBtnmatrix& LvBtnmatrix::setOneChecked(bool en){
	lv_btnmatrix_set_one_checked(cObj.get(),en);
	return *this;
}
const char **LvBtnmatrix::getMap() const noexcept {
	return lv_btnmatrix_get_map(cObj.get());
	
}
uint16_t LvBtnmatrix::getSelectedBtn() const noexcept {
	return lv_btnmatrix_get_selected_btn(cObj.get());
	
}
const char *LvBtnmatrix::getBtnText(uint16_t btn_id) const noexcept {
	return lv_btnmatrix_get_btn_text(cObj.get(),btn_id);
	
}
bool LvBtnmatrix::hasBtnCtrl(uint16_t btn_id, lv_btnmatrix_ctrl_t ctrl){
	return lv_btnmatrix_has_btn_ctrl(cObj.get(),btn_id,ctrl);
	
}
bool LvBtnmatrix::getOneChecked() const noexcept {
	return lv_btnmatrix_get_one_checked(cObj.get());
	
}

} /* namespace lvglpp */
