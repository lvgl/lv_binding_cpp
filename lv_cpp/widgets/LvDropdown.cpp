/*
 * LvDropdown.cpp
 *
 */

#include "LvDropdown.h"

namespace lvglpp {

LvDropdown::LvDropdown() : LvDropdown(NULL) {
}

LvDropdown::LvDropdown(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_dropdown_create(Parent->raw()));
	else
		cObj.reset(lv_dropdown_create(lv_scr_act()));

	setUserData(this);
}

LvDropdown::~LvDropdown() {
}
LvDropdown& LvDropdown::setText(const char *txt){
	lv_dropdown_set_text(cObj.get(),txt);
	return *this;
}
LvDropdown& LvDropdown::setOptions(const char *options){
	lv_dropdown_set_options(cObj.get(),options);
	return *this;
}
LvDropdown& LvDropdown::setOptionsStatic(const char *options){
	lv_dropdown_set_options_static(cObj.get(),options);
	return *this;
}
LvDropdown& LvDropdown::addOption(const char *option, uint32_t pos){
	lv_dropdown_add_option(cObj.get(),option,pos);
	return *this;
}
LvDropdown& LvDropdown::clearOptions(){
	lv_dropdown_clear_options(cObj.get());
	return *this;
}
LvDropdown& LvDropdown::setSelected(uint16_t sel_opt){
	lv_dropdown_set_selected(cObj.get(),sel_opt);
	return *this;
}
LvDropdown& LvDropdown::setDir(lv_dir_t dir){
	lv_dropdown_set_dir(cObj.get(),dir);
	return *this;
}
LvDropdown& LvDropdown::setSymbol(const void *symbol){
	lv_dropdown_set_symbol(cObj.get(),symbol);
	return *this;
}
LvDropdown& LvDropdown::setSelectedHighlight(bool en){
	lv_dropdown_set_selected_highlight(cObj.get(),en);
	return *this;
}
lv_obj_t *LvDropdown::getList() const noexcept {
	return lv_dropdown_get_list(cObj.get());
	
}
const char *LvDropdown::getText() const noexcept {
	return lv_dropdown_get_text(cObj.get());
	
}
const char *LvDropdown::getOptions() const noexcept {
	return lv_dropdown_get_options(cObj.get());
	
}
uint16_t LvDropdown::getSelected() const noexcept {
	return lv_dropdown_get_selected(cObj.get());
	
}
uint16_t LvDropdown::getOptionCnt() const noexcept {
	return lv_dropdown_get_option_cnt(cObj.get());
	
}
LvDropdown& LvDropdown::getSelectedStr(char *buf, uint32_t buf_size){
	lv_dropdown_get_selected_str(cObj.get(),buf,buf_size);
	return *this;
}
const char *LvDropdown::getSymbol() const noexcept {
	return lv_dropdown_get_symbol(cObj.get());
	
}
bool LvDropdown::getSelectedHighlight() const noexcept {
	return lv_dropdown_get_selected_highlight(cObj.get());
	
}
lv_dir_t LvDropdown::getDir() const noexcept {
	return lv_dropdown_get_dir(cObj.get());
	
}
LvDropdown& LvDropdown::close(){
	lv_dropdown_close(cObj.get());
	return *this;
}

} /* namespace lvglpp */
