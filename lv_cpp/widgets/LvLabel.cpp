/*
 * LvLabel.cpp
 *
 */

#include "LvLabel.h"

namespace lvglpp {

LvLabel::LvLabel() : LvLabel(NULL) {
}

LvLabel::LvLabel(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_label_create(Parent->raw()));
	else
		cObj.reset(lv_label_create(lv_scr_act()));

	setUserData(this);
}

LvLabel::~LvLabel() {
}
LvLabel& LvLabel::setText(const char *text){
	lv_label_set_text(cObj.get(),text);
	return *this;
}

LvLabel& LvLabel::setTextStatic(const char *text){
	lv_label_set_text_static(cObj.get(),text);
	return *this;
}
LvLabel& LvLabel::setLongMode(lv_label_long_mode_t long_mode){
	lv_label_set_long_mode(cObj.get(),long_mode);
	return *this;
}
LvLabel& LvLabel::setRecolor(bool en){
	lv_label_set_recolor(cObj.get(),en);
	return *this;
}
LvLabel& LvLabel::setTextSelStart(uint32_t index){
	lv_label_set_text_sel_start(cObj.get(),index);
	return *this;
}
LvLabel& LvLabel::setTextSelEnd(uint32_t index){
	lv_label_set_text_sel_end(cObj.get(),index);
	return *this;
}
char *LvLabel::getText() const noexcept {
	return lv_label_get_text(cObj.get());
	
}
lv_label_long_mode_t LvLabel::getLongMode() const noexcept {
	return lv_label_get_long_mode(cObj.get());
	
}
bool LvLabel::getRecolor() const noexcept {
	return lv_label_get_recolor(cObj.get());
	
}
LvLabel& LvLabel::getLetterPos(uint32_t char_id, lv_point_t *pos){
	lv_label_get_letter_pos(cObj.get(),char_id,pos);
	return *this;
}
uint32_t LvLabel::getLetterOn(lv_point_t *pos_in) const noexcept {
	return lv_label_get_letter_on(cObj.get(),pos_in);
	
}
bool LvLabel::isCharUnderPos(lv_point_t *pos){
	return lv_label_is_char_under_pos(cObj.get(),pos);
	
}
uint32_t LvLabel::getTextSelectionStart() const noexcept {
	return lv_label_get_text_selection_start(cObj.get());
	
}
uint32_t LvLabel::getTextSelectionEnd() const noexcept {
	return lv_label_get_text_selection_end(cObj.get());
	
}
LvLabel& LvLabel::insText(uint32_t pos, const char *txt){
	lv_label_ins_text(cObj.get(),pos,txt);
	return *this;
}
LvLabel& LvLabel::cutText(uint32_t pos, uint32_t cnt){
	lv_label_cut_text(cObj.get(),pos,cnt);
	return *this;
}

} /* namespace lvglpp */
