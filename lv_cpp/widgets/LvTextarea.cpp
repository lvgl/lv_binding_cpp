/*
 * LvTextarea.cpp
 *
 */

#include "LvTextarea.h"

namespace lvglpp {

LvTextarea::LvTextarea() : LvTextarea(NULL) {
}

LvTextarea::LvTextarea(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_textarea_create(Parent->raw()));
	else
		cObj.reset(lv_textarea_create(lv_scr_act()));

	setUserData(this);
}

LvTextarea::~LvTextarea() {
}
LvTextarea& LvTextarea::addChar(uint32_t c){
	lv_textarea_add_char(cObj.get(),c);
	return *this;
}
LvTextarea& LvTextarea::addText(const char *txt){
	lv_textarea_add_text(cObj.get(),txt);
	return *this;
}
LvTextarea& LvTextarea::delChar(){
	lv_textarea_del_char(cObj.get());
	return *this;
}
LvTextarea& LvTextarea::delCharForward(){
	lv_textarea_del_char_forward(cObj.get());
	return *this;
}
LvTextarea& LvTextarea::setText(const char *txt){
	lv_textarea_set_text(cObj.get(),txt);
	return *this;
}
LvTextarea& LvTextarea::setPlaceholderText(const char *txt){
	lv_textarea_set_placeholder_text(cObj.get(),txt);
	return *this;
}
LvTextarea& LvTextarea::setCursorPos(int32_t pos){
	lv_textarea_set_cursor_pos(cObj.get(),pos);
	return *this;
}
LvTextarea& LvTextarea::setCursorClickPos(bool en){
	lv_textarea_set_cursor_click_pos(cObj.get(),en);
	return *this;
}
LvTextarea& LvTextarea::setPasswordMode(bool en){
	lv_textarea_set_password_mode(cObj.get(),en);
	return *this;
}
LvTextarea& LvTextarea::setOneLine(bool en){
	lv_textarea_set_one_line(cObj.get(),en);
	return *this;
}
LvTextarea& LvTextarea::setAcceptedChars(const char *list){
	lv_textarea_set_accepted_chars(cObj.get(),list);
	return *this;
}
LvTextarea& LvTextarea::setMaxLength(uint32_t num){
	lv_textarea_set_max_length(cObj.get(),num);
	return *this;
}
LvTextarea& LvTextarea::setInsertReplace(const char *txt){
	lv_textarea_set_insert_replace(cObj.get(),txt);
	return *this;
}
LvTextarea& LvTextarea::setTextSelection(bool en){
	lv_textarea_set_text_selection(cObj.get(),en);
	return *this;
}
LvTextarea& LvTextarea::setPasswordShowTime(uint16_t time){
	lv_textarea_set_password_show_time(cObj.get(),time);
	return *this;
}
LvTextarea& LvTextarea::setAlign(lv_text_align_t align){
	lv_textarea_set_align(cObj.get(),align);
	return *this;
}
const char *LvTextarea::getText() const noexcept {
	return lv_textarea_get_text(cObj.get());
	
}
const char *LvTextarea::getPlaceholderText() const noexcept {
	return lv_textarea_get_placeholder_text(cObj.get());
	
}
lv_obj_t *LvTextarea::getLabel() const noexcept {
	return lv_textarea_get_label(cObj.get());
	
}
uint32_t LvTextarea::getCursorPos() const noexcept {
	return lv_textarea_get_cursor_pos(cObj.get());
	
}
bool LvTextarea::getCursorClickPos() const noexcept {
	return lv_textarea_get_cursor_click_pos(cObj.get());
	
}
bool LvTextarea::getPasswordMode() const noexcept {
	return lv_textarea_get_password_mode(cObj.get());
	
}
bool LvTextarea::getOneLine() const noexcept {
	return lv_textarea_get_one_line(cObj.get());
	
}
const char *LvTextarea::getAcceptedChars() const noexcept {
	return lv_textarea_get_accepted_chars(cObj.get());
	
}
uint32_t LvTextarea::getMaxLength() const noexcept {
	return lv_textarea_get_max_length(cObj.get());
	
}
bool LvTextarea::textIsSelected(){
	return lv_textarea_text_is_selected(cObj.get());
	
}
bool LvTextarea::getTextSelection() const noexcept {
	return lv_textarea_get_text_selection(cObj.get());
	
}
uint16_t LvTextarea::getPasswordShowTime() const noexcept {
	return lv_textarea_get_password_show_time(cObj.get());
	
}
LvTextarea& LvTextarea::clearSelection(){
	lv_textarea_clear_selection(cObj.get());
	return *this;
}
LvTextarea& LvTextarea::cursorRight(){
	lv_textarea_cursor_right(cObj.get());
	return *this;
}
LvTextarea& LvTextarea::cursorLeft(){
	lv_textarea_cursor_left(cObj.get());
	return *this;
}
LvTextarea& LvTextarea::cursorDown(){
	lv_textarea_cursor_down(cObj.get());
	return *this;
}
LvTextarea& LvTextarea::cursorUp(){
	lv_textarea_cursor_up(cObj.get());
	return *this;
}

} /* namespace lvglpp */
