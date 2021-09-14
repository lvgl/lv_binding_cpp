/*
 * LvStyle.cpp
 *
 */

#include "LvStyle.h"

namespace lvglpp {

LvStyle::LvStyle() {
	cObj.reset((lv_style_t*)lv_mem_alloc(sizeof(lv_style_t)));
	init();
}

LvStyle::~LvStyle() {
}

lv_style_t* LvStyle::raw() {
	return cObj.get();
}
lv_res_t LvStyle::getPropInlined(lv_style_prop_t prop, lv_style_value_t *value) const noexcept {
	return lv_style_get_prop_inlined(cObj.get(),prop,value);
	
}
LvStyle& LvStyle::setPadAll(lv_coord_t value){
	lv_style_set_pad_all(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setPadHor(lv_coord_t value){
	lv_style_set_pad_hor(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setPadVer(lv_coord_t value){
	lv_style_set_pad_ver(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setPadGap(lv_coord_t value){
	lv_style_set_pad_gap(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setSize(lv_coord_t value){
	lv_style_set_size(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::init(){
	lv_style_init(cObj.get());
	return *this;
}
LvStyle& LvStyle::reset(){
	lv_style_reset(cObj.get());
	return *this;
}
bool LvStyle::removeProp(lv_style_prop_t prop){
	return lv_style_remove_prop(cObj.get(),prop);
	
}
LvStyle& LvStyle::setProp(lv_style_prop_t prop, lv_style_value_t value){
	lv_style_set_prop(cObj.get(),prop,value);
	return *this;
}
lv_res_t LvStyle::getProp(lv_style_prop_t prop, lv_style_value_t *value) const noexcept {
	return lv_style_get_prop(cObj.get(),prop,value);
	
}
bool LvStyle::isEmpty(){
	return lv_style_is_empty(cObj.get());
	
}
LvStyle& LvStyle::setWidth(lv_coord_t value){
	lv_style_set_width(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setMinWidth(lv_coord_t value){
	lv_style_set_min_width(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setMaxWidth(lv_coord_t value){
	lv_style_set_max_width(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setHeight(lv_coord_t value){
	lv_style_set_height(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setMinHeight(lv_coord_t value){
	lv_style_set_min_height(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setMaxHeight(lv_coord_t value){
	lv_style_set_max_height(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setX(lv_coord_t value){
	lv_style_set_x(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setY(lv_coord_t value){
	lv_style_set_y(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setAlign(lv_align_t value){
	lv_style_set_align(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setTransformWidth(lv_coord_t value){
	lv_style_set_transform_width(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setTransformHeight(lv_coord_t value){
	lv_style_set_transform_height(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setTranslateX(lv_coord_t value){
	lv_style_set_translate_x(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setTranslateY(lv_coord_t value){
	lv_style_set_translate_y(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setTransformZoom(lv_coord_t value){
	lv_style_set_transform_zoom(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setTransformAngle(lv_coord_t value){
	lv_style_set_transform_angle(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setPadTop(lv_coord_t value){
	lv_style_set_pad_top(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setPadBottom(lv_coord_t value){
	lv_style_set_pad_bottom(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setPadLeft(lv_coord_t value){
	lv_style_set_pad_left(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setPadRight(lv_coord_t value){
	lv_style_set_pad_right(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setPadRow(lv_coord_t value){
	lv_style_set_pad_row(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setPadColumn(lv_coord_t value){
	lv_style_set_pad_column(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setRadius(lv_coord_t value){
	lv_style_set_radius(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setClipCorner(bool value){
	lv_style_set_clip_corner(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setOpa(lv_opa_t value){
	lv_style_set_opa(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setColorFilterDsc(const lv_color_filter_dsc_t *value){
	lv_style_set_color_filter_dsc(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setColorFilterOpa(lv_opa_t value){
	lv_style_set_color_filter_opa(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setAnimTime(uint32_t value){
	lv_style_set_anim_time(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setAnimSpeed(uint32_t value){
	lv_style_set_anim_speed(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setTransition(const lv_style_transition_dsc_t *value){
	lv_style_set_transition(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBlendMode(lv_blend_mode_t value){
	lv_style_set_blend_mode(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setLayout(uint16_t value){
	lv_style_set_layout(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBaseDir(lv_base_dir_t value){
	lv_style_set_base_dir(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBgColor(lv_color_t value){
	lv_style_set_bg_color(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBgColorFiltered(lv_color_t value){
	lv_style_set_bg_color_filtered(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBgOpa(lv_opa_t value){
	lv_style_set_bg_opa(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBgGradColor(lv_color_t value){
	lv_style_set_bg_grad_color(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBgGradColorFiltered(lv_color_t value){
	lv_style_set_bg_grad_color_filtered(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBgGradDir(lv_grad_dir_t value){
	lv_style_set_bg_grad_dir(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBgMainStop(lv_coord_t value){
	lv_style_set_bg_main_stop(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBgGradStop(lv_coord_t value){
	lv_style_set_bg_grad_stop(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBgImgSrc(const void *value){
	lv_style_set_bg_img_src(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBgImgOpa(lv_opa_t value){
	lv_style_set_bg_img_opa(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBgImgRecolor(lv_color_t value){
	lv_style_set_bg_img_recolor(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBgImgRecolorFiltered(lv_color_t value){
	lv_style_set_bg_img_recolor_filtered(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBgImgRecolorOpa(lv_opa_t value){
	lv_style_set_bg_img_recolor_opa(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBgImgTiled(bool value){
	lv_style_set_bg_img_tiled(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBorderColor(lv_color_t value){
	lv_style_set_border_color(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBorderColorFiltered(lv_color_t value){
	lv_style_set_border_color_filtered(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBorderOpa(lv_opa_t value){
	lv_style_set_border_opa(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBorderWidth(lv_coord_t value){
	lv_style_set_border_width(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBorderSide(lv_border_side_t value){
	lv_style_set_border_side(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setBorderPost(bool value){
	lv_style_set_border_post(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setTextColor(lv_color_t value){
	lv_style_set_text_color(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setTextColorFiltered(lv_color_t value){
	lv_style_set_text_color_filtered(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setTextOpa(lv_opa_t value){
	lv_style_set_text_opa(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setTextFont(const lv_font_t *value){
	lv_style_set_text_font(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setTextLetterSpace(lv_coord_t value){
	lv_style_set_text_letter_space(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setTextLineSpace(lv_coord_t value){
	lv_style_set_text_line_space(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setTextDecor(lv_text_decor_t value){
	lv_style_set_text_decor(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setTextAlign(lv_text_align_t value){
	lv_style_set_text_align(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setImgOpa(lv_opa_t value){
	lv_style_set_img_opa(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setImgRecolor(lv_color_t value){
	lv_style_set_img_recolor(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setImgRecolorFiltered(lv_color_t value){
	lv_style_set_img_recolor_filtered(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setImgRecolorOpa(lv_opa_t value){
	lv_style_set_img_recolor_opa(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setOutlineWidth(lv_coord_t value){
	lv_style_set_outline_width(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setOutlineColor(lv_color_t value){
	lv_style_set_outline_color(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setOutlineColorFiltered(lv_color_t value){
	lv_style_set_outline_color_filtered(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setOutlineOpa(lv_opa_t value){
	lv_style_set_outline_opa(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setOutlinePad(lv_coord_t value){
	lv_style_set_outline_pad(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setShadowWidth(lv_coord_t value){
	lv_style_set_shadow_width(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setShadowOfsX(lv_coord_t value){
	lv_style_set_shadow_ofs_x(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setShadowOfsY(lv_coord_t value){
	lv_style_set_shadow_ofs_y(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setShadowSpread(lv_coord_t value){
	lv_style_set_shadow_spread(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setShadowColor(lv_color_t value){
	lv_style_set_shadow_color(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setShadowColorFiltered(lv_color_t value){
	lv_style_set_shadow_color_filtered(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setShadowOpa(lv_opa_t value){
	lv_style_set_shadow_opa(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setLineWidth(lv_coord_t value){
	lv_style_set_line_width(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setLineDashWidth(lv_coord_t value){
	lv_style_set_line_dash_width(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setLineDashGap(lv_coord_t value){
	lv_style_set_line_dash_gap(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setLineRounded(bool value){
	lv_style_set_line_rounded(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setLineColor(lv_color_t value){
	lv_style_set_line_color(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setLineColorFiltered(lv_color_t value){
	lv_style_set_line_color_filtered(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setLineOpa(lv_opa_t value){
	lv_style_set_line_opa(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setArcWidth(lv_coord_t value){
	lv_style_set_arc_width(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setArcRounded(bool value){
	lv_style_set_arc_rounded(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setArcColor(lv_color_t value){
	lv_style_set_arc_color(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setArcColorFiltered(lv_color_t value){
	lv_style_set_arc_color_filtered(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setArcOpa(lv_opa_t value){
	lv_style_set_arc_opa(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setArcImgSrc(const void *value){
	lv_style_set_arc_img_src(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setFlexFlow(lv_flex_flow_t value){
	lv_style_set_flex_flow(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setFlexMainPlace(lv_flex_align_t value){
	lv_style_set_flex_main_place(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setFlexCrossPlace(lv_flex_align_t value){
	lv_style_set_flex_cross_place(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setFlexTrackPlace(lv_flex_align_t value){
	lv_style_set_flex_track_place(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setFlexGrow(uint8_t value){
	lv_style_set_flex_grow(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setGridRowDscArray(const lv_coord_t value[]){
	lv_style_set_grid_row_dsc_array(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setGridColumnDscArray(const lv_coord_t value[]){
	lv_style_set_grid_column_dsc_array(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setGridRowAlign(lv_grid_align_t value){
	lv_style_set_grid_row_align(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setGridColumnAlign(lv_grid_align_t value){
	lv_style_set_grid_column_align(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setGridCellColumnPos(lv_coord_t value){
	lv_style_set_grid_cell_column_pos(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setGridCellColumnSpan(lv_coord_t value){
	lv_style_set_grid_cell_column_span(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setGridCellRowPos(lv_coord_t value){
	lv_style_set_grid_cell_row_pos(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setGridCellRowSpan(lv_coord_t value){
	lv_style_set_grid_cell_row_span(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setGridCellXAlign(lv_coord_t value){
	lv_style_set_grid_cell_x_align(cObj.get(),value);
	return *this;
}
LvStyle& LvStyle::setGridCellYAlign(lv_coord_t value){
	lv_style_set_grid_cell_y_align(cObj.get(),value);
	return *this;
}

} /* namespace lvglpp */
