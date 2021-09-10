/*
 * LvObj.cpp
 *
 *  Created on: Jun 24, 2021
 *      Author: fstuffdev
 */

#include "LvObj.h"

namespace lvglpp {

LvObj::LvObj() : LvObj(NULL){

}
LvObj::LvObj(LvObj* Parent) {
	if(Parent)
		cObj.reset(lv_obj_create(Parent->raw()));
	else
		cObj.reset(lv_obj_create(lv_scr_act()));
}
lv_obj_t* LvObj::raw() {
	return cObj.get();
}
LvObj::~LvObj() {

}
LvObj& LvObj::setCObj(lv_obj_t* _cObj) {
	if(_cObj)
		cObj.reset(_cObj);
	return *this;
}
LvObj& LvObj::setUserData(void *user_data){
	lv_obj_set_user_data(cObj.get(),user_data);
	return *this;
}
void *LvObj::getUserData() const noexcept {
	return lv_obj_get_user_data(cObj.get());
	
}
lv_coord_t LvObj::dpx(lv_coord_t n){
	return lv_obj_dpx(cObj.get(),n);
	
}
LvObj& LvObj::del(){
	lv_obj_del(cObj.get());
	return *this;
}
LvObj& LvObj::clean(){
	lv_obj_clean(cObj.get());
	return *this;
}
LvObj& LvObj::delAsync(){
	lv_obj_del_async(cObj.get());
	return *this;
}
LvObj& LvObj::setParent(LvObj *parent){
	lv_obj_set_parent(cObj.get(),parent->raw());
	return *this;
}
LvObj& LvObj::moveForeground(){
	lv_obj_move_foreground(cObj.get());
	return *this;
}
LvObj& LvObj::moveBackground(){
	lv_obj_move_background(cObj.get());
	return *this;
}
lv_obj_t *LvObj::getScreen() const noexcept {
	return lv_obj_get_screen(cObj.get());
	
}
lv_disp_t *LvObj::getDisp() const noexcept {
	return lv_obj_get_disp(cObj.get());
	
}
lv_obj_t *LvObj::getParent() const noexcept {
	return lv_obj_get_parent(cObj.get());
	
}
lv_obj_t *LvObj::getChild(int32_t id) const noexcept {
	return lv_obj_get_child(cObj.get(),id);
	
}
uint32_t LvObj::getChildCnt() const noexcept {
	return lv_obj_get_child_cnt(cObj.get());
	
}
uint32_t LvObj::getChildId() const noexcept {
	return lv_obj_get_child_id(cObj.get());
	
}
lv_flex_flow_t LvObj::getStyleFlexFlow(uint32_t part) const noexcept {
	return lv_obj_get_style_flex_flow(cObj.get(),part);
	
}
lv_flex_align_t LvObj::getStyleFlexMainPlace(uint32_t part) const noexcept {
	return lv_obj_get_style_flex_main_place(cObj.get(),part);
	
}
lv_flex_align_t LvObj::getStyleFlexCrossPlace(uint32_t part) const noexcept {
	return lv_obj_get_style_flex_cross_place(cObj.get(),part);
	
}
lv_flex_align_t LvObj::getStyleFlexTrackPlace(uint32_t part) const noexcept {
	return lv_obj_get_style_flex_track_place(cObj.get(),part);
	
}
uint8_t LvObj::getStyleFlexGrow(uint32_t part) const noexcept {
	return lv_obj_get_style_flex_grow(cObj.get(),part);
	
}
const lv_coord_t *LvObj::getStyleGridRowDscArray(uint32_t part) const noexcept {
	return lv_obj_get_style_grid_row_dsc_array(cObj.get(),part);
	
}
const lv_coord_t *LvObj::getStyleGridColumnDscArray(uint32_t part) const noexcept {
	return lv_obj_get_style_grid_column_dsc_array(cObj.get(),part);
	
}
lv_grid_align_t LvObj::getStyleGridRowAlign(uint32_t part) const noexcept {
	return lv_obj_get_style_grid_row_align(cObj.get(),part);
	
}
lv_grid_align_t LvObj::getStyleGridColumnAlign(uint32_t part) const noexcept {
	return lv_obj_get_style_grid_column_align(cObj.get(),part);
	
}
lv_coord_t LvObj::getStyleGridCellColumnPos(uint32_t part) const noexcept {
	return lv_obj_get_style_grid_cell_column_pos(cObj.get(),part);
	
}
lv_coord_t LvObj::getStyleGridCellColumnSpan(uint32_t part) const noexcept {
	return lv_obj_get_style_grid_cell_column_span(cObj.get(),part);
	
}
lv_coord_t LvObj::getStyleGridCellRowPos(uint32_t part) const noexcept {
	return lv_obj_get_style_grid_cell_row_pos(cObj.get(),part);
	
}
lv_coord_t LvObj::getStyleGridCellRowSpan(uint32_t part) const noexcept {
	return lv_obj_get_style_grid_cell_row_span(cObj.get(),part);
	
}
lv_coord_t LvObj::getStyleGridCellXAlign(uint32_t part) const noexcept {
	return lv_obj_get_style_grid_cell_x_align(cObj.get(),part);
	
}
lv_coord_t LvObj::getStyleGridCellYAlign(uint32_t part) const noexcept {
	return lv_obj_get_style_grid_cell_y_align(cObj.get(),part);
	
}
struct _lv_event_dsc_t *LvObj::addEventCb(lv_event_cb_t event_cb, lv_event_code_t filter, void *user_data){
	return lv_obj_add_event_cb(cObj.get(),event_cb,filter,user_data);
	
}
bool LvObj::removeEventCb(lv_event_cb_t event_cb){
	return lv_obj_remove_event_cb(cObj.get(),event_cb);
	
}
bool LvObj::removeEventDsc(struct _lv_event_dsc_t *event_dsc){
	return lv_obj_remove_event_dsc(cObj.get(),event_dsc);
	
}
LvObj& LvObj::classInitObj(){
	lv_obj_class_init_obj(cObj.get());
	return *this;
}
LvObj& LvObj::destruct(){
	_lv_obj_destruct(cObj.get());
	return *this;
}
bool LvObj::isEditable(){
	return lv_obj_is_editable(cObj.get());
	
}
bool LvObj::isGroupDef(){
	return lv_obj_is_group_def(cObj.get());
	
}
LvObj& LvObj::addFlag(lv_obj_flag_t f){
	lv_obj_add_flag(cObj.get(),f);
	return *this;
}
LvObj& LvObj::clearFlag(lv_obj_flag_t f){
	lv_obj_clear_flag(cObj.get(),f);
	return *this;
}
LvObj& LvObj::addState(lv_state_t state){
	lv_obj_add_state(cObj.get(),state);
	return *this;
}
LvObj& LvObj::clearState(lv_state_t state){
	lv_obj_clear_state(cObj.get(),state);
	return *this;
}
bool LvObj::hasFlag(lv_obj_flag_t f){
	return lv_obj_has_flag(cObj.get(),f);
	
}
bool LvObj::hasFlagAny(lv_obj_flag_t f){
	return lv_obj_has_flag_any(cObj.get(),f);
	
}
lv_state_t LvObj::getState() const noexcept {
	return lv_obj_get_state(cObj.get());
	
}
bool LvObj::hasState(lv_state_t state){
	return lv_obj_has_state(cObj.get(),state);
	
}
void *LvObj::getGroup() const noexcept {
	return lv_obj_get_group(cObj.get());
	
}
LvObj& LvObj::allocateSpecAttr(){
	lv_obj_allocate_spec_attr(cObj.get());
	return *this;
}
bool LvObj::checkType(const lv_obj_class_t *class_p){
	return lv_obj_check_type(cObj.get(),class_p);
	
}
bool LvObj::hasClass(const lv_obj_class_t *class_p){
	return lv_obj_has_class(cObj.get(),class_p);
	
}
const lv_obj_class_t *LvObj::getClass() const noexcept {
	return lv_obj_get_class(cObj.get());
	
}
bool LvObj::isValid(){
	return lv_obj_is_valid(cObj.get());
	
}
LvObj& LvObj::setScrollbarMode(lv_scrollbar_mode_t mode){
	lv_obj_set_scrollbar_mode(cObj.get(),mode);
	return *this;
}
LvObj& LvObj::setScrollDir(lv_dir_t dir){
	lv_obj_set_scroll_dir(cObj.get(),dir);
	return *this;
}
LvObj& LvObj::setScrollSnapX(lv_scroll_snap_t align){
	lv_obj_set_scroll_snap_x(cObj.get(),align);
	return *this;
}
LvObj& LvObj::setScrollSnapY(lv_scroll_snap_t align){
	lv_obj_set_scroll_snap_y(cObj.get(),align);
	return *this;
}
lv_scrollbar_mode_t LvObj::getScrollbarMode() const noexcept {
	return lv_obj_get_scrollbar_mode(cObj.get());
	
}
lv_dir_t LvObj::getScrollDir() const noexcept {
	return lv_obj_get_scroll_dir(cObj.get());
	
}
lv_scroll_snap_t LvObj::getScrollSnapX() const noexcept {
	return lv_obj_get_scroll_snap_x(cObj.get());
	
}
lv_scroll_snap_t LvObj::getScrollSnapY() const noexcept {
	return lv_obj_get_scroll_snap_y(cObj.get());
	
}
lv_coord_t LvObj::getScrollX() const noexcept {
	return lv_obj_get_scroll_x(cObj.get());
	
}
lv_coord_t LvObj::getScrollY() const noexcept {
	return lv_obj_get_scroll_y(cObj.get());
	
}
lv_coord_t LvObj::getScrollTop() const noexcept {
	return lv_obj_get_scroll_top(cObj.get());
	
}
lv_coord_t LvObj::getScrollBottom() const noexcept {
	return lv_obj_get_scroll_bottom(cObj.get());
	
}
lv_coord_t LvObj::getScrollLeft() const noexcept {
	return lv_obj_get_scroll_left(cObj.get());
	
}
lv_coord_t LvObj::getScrollRight() const noexcept {
	return lv_obj_get_scroll_right(cObj.get());
	
}
LvObj& LvObj::scrollBy(lv_coord_t x, lv_coord_t y, lv_anim_enable_t anim_en){
	lv_obj_scroll_by(cObj.get(),x,y,anim_en);
	return *this;
}
LvObj& LvObj::scrollTo(lv_coord_t x, lv_coord_t y, lv_anim_enable_t anim_en){
	lv_obj_scroll_to(cObj.get(),x,y,anim_en);
	return *this;
}
LvObj& LvObj::scrollToX(lv_coord_t x, lv_anim_enable_t anim_en){
	lv_obj_scroll_to_x(cObj.get(),x,anim_en);
	return *this;
}
LvObj& LvObj::scrollToY(lv_coord_t y, lv_anim_enable_t anim_en){
	lv_obj_scroll_to_y(cObj.get(),y,anim_en);
	return *this;
}
LvObj& LvObj::scrollToView(lv_anim_enable_t anim_en){
	lv_obj_scroll_to_view(cObj.get(),anim_en);
	return *this;
}
LvObj& LvObj::scrollToViewRecursive(lv_anim_enable_t anim_en){
	lv_obj_scroll_to_view_recursive(cObj.get(),anim_en);
	return *this;
}
bool LvObj::isScrolling(){
	return lv_obj_is_scrolling(cObj.get());
	
}
LvObj& LvObj::updateSnap(lv_anim_enable_t anim_en){
	lv_obj_update_snap(cObj.get(),anim_en);
	return *this;
}
LvObj& LvObj::getScrollbarArea(lv_area_t *hor_area, lv_area_t *ver_area){
	lv_obj_get_scrollbar_area(cObj.get(),hor_area,ver_area);
	return *this;
}
LvObj& LvObj::scrollbarInvalidate(){
	lv_obj_scrollbar_invalidate(cObj.get());
	return *this;
}
LvObj& LvObj::readjustScroll(lv_anim_enable_t anim_en){
	lv_obj_readjust_scroll(cObj.get(),anim_en);
	return *this;
}
lv_obj_t *LvObj::lvIndevSearchObj(lv_point_t *point){
	return lv_indev_search_obj(cObj.get(),point);
	
}
LvObj& LvObj::lvGroupRemoveObj(){
	lv_group_remove_obj(cObj.get());
	return *this;
}
LvObj& LvObj::lvGroupFocusObj(){
	lv_group_focus_obj(cObj.get());
	return *this;
}
LvObj& LvObj::setPos(lv_coord_t x, lv_coord_t y){
	lv_obj_set_pos(cObj.get(),x,y);
	return *this;
}
LvObj& LvObj::setX(lv_coord_t x){
	lv_obj_set_x(cObj.get(),x);
	return *this;
}
LvObj& LvObj::setY(lv_coord_t y){
	lv_obj_set_y(cObj.get(),y);
	return *this;
}
bool LvObj::refrSize(){
	return lv_obj_refr_size(cObj.get());
	
}
LvObj& LvObj::setSize(lv_coord_t w, lv_coord_t h){
	lv_obj_set_size(cObj.get(),w,h);
	return *this;
}
LvObj& LvObj::setWidth(lv_coord_t w){
	lv_obj_set_width(cObj.get(),w);
	return *this;
}
LvObj& LvObj::setHeight(lv_coord_t h){
	lv_obj_set_height(cObj.get(),h);
	return *this;
}
LvObj& LvObj::setContentWidth(lv_coord_t w){
	lv_obj_set_content_width(cObj.get(),w);
	return *this;
}
LvObj& LvObj::setContentHeight(lv_coord_t h){
	lv_obj_set_content_height(cObj.get(),h);
	return *this;
}
LvObj& LvObj::setLayout(uint32_t layout){
	lv_obj_set_layout(cObj.get(),layout);
	return *this;
}
bool LvObj::isLayoutPositioned(){
	return lv_obj_is_layout_positioned(cObj.get());
	
}
LvObj& LvObj::markLayoutAsDirty(){
	lv_obj_mark_layout_as_dirty(cObj.get());
	return *this;
}
LvObj& LvObj::updateLayout(){
	lv_obj_update_layout(cObj.get());
	return *this;
}
LvObj& LvObj::setAlign(lv_align_t align){
	lv_obj_set_align(cObj.get(),align);
	return *this;
}
LvObj& LvObj::align(lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs){
	lv_obj_align(cObj.get(),align,x_ofs,y_ofs);
	return *this;
}
LvObj& LvObj::alignTo(const lv_obj_t *base, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs){
	lv_obj_align_to(cObj.get(),base,align,x_ofs,y_ofs);
	return *this;
}
LvObj& LvObj::getCoords(lv_area_t *coords){
	lv_obj_get_coords(cObj.get(),coords);
	return *this;
}
lv_coord_t LvObj::getX() const noexcept {
	return lv_obj_get_x(cObj.get());
	
}
lv_coord_t LvObj::getX2() const noexcept {
	return lv_obj_get_x2(cObj.get());
	
}
lv_coord_t LvObj::getY() const noexcept {
	return lv_obj_get_y(cObj.get());
	
}
lv_coord_t LvObj::getY2() const noexcept {
	return lv_obj_get_y2(cObj.get());
	
}
lv_coord_t LvObj::getWidth() const noexcept {
	return lv_obj_get_width(cObj.get());
	
}
lv_coord_t LvObj::getHeight() const noexcept {
	return lv_obj_get_height(cObj.get());
	
}
lv_coord_t LvObj::getContentWidth() const noexcept {
	return lv_obj_get_content_width(cObj.get());
	
}
lv_coord_t LvObj::getContentHeight() const noexcept {
	return lv_obj_get_content_height(cObj.get());
	
}
LvObj& LvObj::getContentCoords(lv_area_t *area){
	lv_obj_get_content_coords(cObj.get(),area);
	return *this;
}
lv_coord_t LvObj::getSelfWidth() const noexcept {
	return lv_obj_get_self_width(cObj.get());
	
}
lv_coord_t LvObj::getSelfHeight() const noexcept {
	return lv_obj_get_self_height(cObj.get());
	
}
bool LvObj::refreshSelfSize(){
	return lv_obj_refresh_self_size(cObj.get());
	
}
LvObj& LvObj::refrPos(){
	lv_obj_refr_pos(cObj.get());
	return *this;
}
LvObj& LvObj::moveTo(lv_coord_t x, lv_coord_t y){
	lv_obj_move_to(cObj.get(),x,y);
	return *this;
}
LvObj& LvObj::moveChildrenBy(lv_coord_t x_diff, lv_coord_t y_diff, bool ignore_floating){
	lv_obj_move_children_by(cObj.get(),x_diff,y_diff,ignore_floating);
	return *this;
}
LvObj& LvObj::invalidateArea(const lv_area_t *area){
	lv_obj_invalidate_area(cObj.get(),area);
	return *this;
}
LvObj& LvObj::invalidate(){
	lv_obj_invalidate(cObj.get());
	return *this;
}
bool LvObj::areaIsVisible(lv_area_t *area){
	return lv_obj_area_is_visible(cObj.get(),area);
	
}
bool LvObj::isVisible(){
	return lv_obj_is_visible(cObj.get());
	
}
LvObj& LvObj::setExtClickArea(lv_coord_t size){
	lv_obj_set_ext_click_area(cObj.get(),size);
	return *this;
}
LvObj& LvObj::getClickArea(lv_area_t *area){
	lv_obj_get_click_area(cObj.get(),area);
	return *this;
}
bool LvObj::hitTest(const lv_point_t *point){
	return lv_obj_hit_test(cObj.get(),point);
	
}
LvObj& LvObj::addStyle(LvStyle *style, lv_style_selector_t selector){
	lv_obj_add_style(cObj.get(),style->raw(),selector);
	return *this;
}
LvObj& LvObj::removeStyle(LvStyle *style, lv_style_selector_t selector){
	lv_obj_remove_style(cObj.get(),style->raw(),selector);
	return *this;
}
LvObj& LvObj::refreshStyle(lv_style_selector_t selector, lv_style_prop_t prop){
	lv_obj_refresh_style(cObj.get(),selector,prop);
	return *this;
}
lv_style_value_t LvObj::getStyleProp(lv_part_t part, lv_style_prop_t prop) const noexcept {
	return lv_obj_get_style_prop(cObj.get(),part,prop);
	
}
LvObj& LvObj::setLocalStyleProp(lv_style_prop_t prop, lv_style_value_t value, lv_style_selector_t selector){
	lv_obj_set_local_style_prop(cObj.get(),prop,value,selector);
	return *this;
}
lv_res_t LvObj::getLocalStyleProp(lv_style_prop_t prop, lv_style_value_t *value, lv_style_selector_t selector) const noexcept {
	return lv_obj_get_local_style_prop(cObj.get(),prop,value,selector);
	
}
bool LvObj::removeLocalStyleProp(lv_style_prop_t prop, lv_style_selector_t selector){
	return lv_obj_remove_local_style_prop(cObj.get(),prop,selector);
	
}
LvObj& LvObj::styleCreateTransition(lv_part_t part, lv_state_t prev_state, lv_state_t new_state, const _lv_obj_style_transition_dsc_t *tr_dsc){
	_lv_obj_style_create_transition(cObj.get(),part,prev_state,new_state,tr_dsc);
	return *this;
}
_lv_style_state_cmp_t LvObj::styleStateCompare(lv_state_t state1, lv_state_t state2){
	return _lv_obj_style_state_compare(cObj.get(),state1,state2);
	
}
LvObj& LvObj::fadeIn(uint32_t time, uint32_t delay){
	lv_obj_fade_in(cObj.get(),time,delay);
	return *this;
}
LvObj& LvObj::fadeOut(uint32_t time, uint32_t delay){
	lv_obj_fade_out(cObj.get(),time,delay);
	return *this;
}
LvObj& LvObj::initDrawRectDsc(uint32_t part, lv_draw_rect_dsc_t *draw_dsc){
	lv_obj_init_draw_rect_dsc(cObj.get(),part,draw_dsc);
	return *this;
}
LvObj& LvObj::initDrawLabelDsc(uint32_t part, lv_draw_label_dsc_t *draw_dsc){
	lv_obj_init_draw_label_dsc(cObj.get(),part,draw_dsc);
	return *this;
}
LvObj& LvObj::initDrawImgDsc(uint32_t part, lv_draw_img_dsc_t *draw_dsc){
	lv_obj_init_draw_img_dsc(cObj.get(),part,draw_dsc);
	return *this;
}
LvObj& LvObj::initDrawLineDsc(uint32_t part, lv_draw_line_dsc_t *draw_dsc){
	lv_obj_init_draw_line_dsc(cObj.get(),part,draw_dsc);
	return *this;
}
LvObj& LvObj::initDrawArcDsc(uint32_t part, lv_draw_arc_dsc_t *draw_dsc){
	lv_obj_init_draw_arc_dsc(cObj.get(),part,draw_dsc);
	return *this;
}
lv_coord_t LvObj::calculateExtDrawSize(uint32_t part){
	return lv_obj_calculate_ext_draw_size(cObj.get(),part);
	
}
LvObj& LvObj::refreshExtDrawSize(){
	lv_obj_refresh_ext_draw_size(cObj.get());
	return *this;
}
lv_coord_t LvObj::getExtDrawSize() const noexcept {
	return _lv_obj_get_ext_draw_size(cObj.get());
	
}

/* The Cpp event dispatcher */
void LvObj::EventDispatcher(lv_event_t *e) {

	LvObj *_Obj = static_cast<LvObj*>(e->user_data);

	std::list<eventBind_t>::iterator eventIter;

	if (_Obj) {
		/* Search in registered events */
		for (eventIter = _Obj->eventRegister.begin();
				eventIter != _Obj->eventRegister.end(); eventIter++) {
			if (eventIter->evCode == e->code) {
				/* Call the event */
				if (eventIter->evCallback)
					(*(eventIter->evCallback))(e);
			}
		}
	}
}

/* Enable the related code Callback */
LvObj& LvObj::setCallback(lv_event_code_t code, LvEvent *Cb) {

	eventBind_t eventToRegister;
	eventToRegister.evCallback = Cb;
	eventToRegister.evCode = code;

	/* Setting Callback to EventDispatcher sacrificing user_data of callback */
	this->addEventCb(LvObj::EventDispatcher, code, (void*) this);

	eventRegister.push_back(eventToRegister);

	return *this;
}

} /* namespace lvglpp */
