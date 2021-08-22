/*
 * LvChart.cpp
 *
 */

#include "LvChart.h"

namespace lvglpp {

LvChart::LvChart() : LvChart(NULL) {
}

LvChart::LvChart(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_chart_create(Parent->raw()));
	else
		cObj.reset(lv_chart_create(lv_scr_act()));

	setUserData(this);
}

LvChart::~LvChart() {
}
LvChart& LvChart::setType(lv_chart_type_t type){
	lv_chart_set_type(cObj.get(),type);
	return *this;
}
LvChart& LvChart::setPointCount(uint16_t cnt){
	lv_chart_set_point_count(cObj.get(),cnt);
	return *this;
}
LvChart& LvChart::setRange(lv_chart_axis_t axis, lv_coord_t min, lv_coord_t max){
	lv_chart_set_range(cObj.get(),axis,min,max);
	return *this;
}
LvChart& LvChart::setUpdateMode(lv_chart_update_mode_t update_mode){
	lv_chart_set_update_mode(cObj.get(),update_mode);
	return *this;
}
LvChart& LvChart::setDivLineCount(uint8_t hdiv, uint8_t vdiv){
	lv_chart_set_div_line_count(cObj.get(),hdiv,vdiv);
	return *this;
}
LvChart& LvChart::setZoomX(uint16_t zoom_x){
	lv_chart_set_zoom_x(cObj.get(),zoom_x);
	return *this;
}
LvChart& LvChart::setZoomY(uint16_t zoom_y){
	lv_chart_set_zoom_y(cObj.get(),zoom_y);
	return *this;
}
uint16_t LvChart::getZoomX() const noexcept {
	return lv_chart_get_zoom_x(cObj.get());
	
}
uint16_t LvChart::getZoomY() const noexcept {
	return lv_chart_get_zoom_y(cObj.get());
	
}
LvChart& LvChart::setAxisTick(lv_chart_axis_t axis, lv_coord_t major_len, lv_coord_t minor_len, lv_coord_t major_cnt, lv_coord_t minor_cnt, bool label_en, lv_coord_t draw_size){
	lv_chart_set_axis_tick(cObj.get(),axis,major_len,minor_len,major_cnt,minor_cnt,label_en,draw_size);
	return *this;
}
lv_chart_type_t LvChart::getType() const noexcept {
	return lv_chart_get_type(cObj.get());
	
}
uint16_t LvChart::getPointCount() const noexcept {
	return lv_chart_get_point_count(cObj.get());
	
}
uint16_t LvChart::getXStartPoint(lv_chart_series_t *ser) const noexcept {
	return lv_chart_get_x_start_point(cObj.get(),ser);
	
}
LvChart& LvChart::getPointPosById(lv_chart_series_t *ser, uint16_t id, lv_point_t *p_out){
	lv_chart_get_point_pos_by_id(cObj.get(),ser,id,p_out);
	return *this;
}
LvChart& LvChart::refresh(){
	lv_chart_refresh(cObj.get());
	return *this;
}
lv_chart_series_t *LvChart::addSeries(lv_color_t color, lv_chart_axis_t axis){
	return lv_chart_add_series(cObj.get(),color,axis);
	
}
LvChart& LvChart::removeSeries(lv_chart_series_t *series){
	lv_chart_remove_series(cObj.get(),series);
	return *this;
}
LvChart& LvChart::hideSeries(lv_chart_series_t *series, bool hide){
	lv_chart_hide_series(cObj.get(),series,hide);
	return *this;
}
LvChart& LvChart::setSeriesColor(lv_chart_series_t *series, lv_color_t color){
	lv_chart_set_series_color(cObj.get(),series,color);
	return *this;
}
LvChart& LvChart::setXStartPoint(lv_chart_series_t *ser, uint16_t id){
	lv_chart_set_x_start_point(cObj.get(),ser,id);
	return *this;
}
lv_chart_series_t *LvChart::getSeriesNext(const lv_chart_series_t *ser) const noexcept {
	return lv_chart_get_series_next(cObj.get(),ser);
	
}
lv_chart_cursor_t *LvChart::addCursor(lv_color_t color, lv_dir_t dir){
	return lv_chart_add_cursor(cObj.get(),color,dir);
	
}
LvChart& LvChart::setCursorPos(lv_chart_cursor_t *cursor, lv_point_t *pos){
	lv_chart_set_cursor_pos(cObj.get(),cursor,pos);
	return *this;
}
LvChart& LvChart::setCursorPoint(lv_chart_cursor_t *cursor, lv_chart_series_t *ser, uint16_t point_id){
	lv_chart_set_cursor_point(cObj.get(),cursor,ser,point_id);
	return *this;
}
lv_point_t LvChart::getCursorPoint(lv_chart_cursor_t *cursor) const noexcept {
	return lv_chart_get_cursor_point(cObj.get(),cursor);
	
}
LvChart& LvChart::setAllValue(lv_chart_series_t *ser, lv_coord_t value){
	lv_chart_set_all_value(cObj.get(),ser,value);
	return *this;
}
LvChart& LvChart::setNextValue(lv_chart_series_t *ser, lv_coord_t value){
	lv_chart_set_next_value(cObj.get(),ser,value);
	return *this;
}
LvChart& LvChart::setNextValue2(lv_chart_series_t *ser, lv_coord_t x_value, lv_coord_t y_value){
	lv_chart_set_next_value2(cObj.get(),ser,x_value,y_value);
	return *this;
}
LvChart& LvChart::setValueById(lv_chart_series_t *ser, uint16_t id, lv_coord_t value){
	lv_chart_set_value_by_id(cObj.get(),ser,id,value);
	return *this;
}
LvChart& LvChart::setValueById2(lv_chart_series_t *ser, uint16_t id, lv_coord_t x_value, lv_coord_t y_value){
	lv_chart_set_value_by_id2(cObj.get(),ser,id,x_value,y_value);
	return *this;
}
LvChart& LvChart::setExtYArray(lv_chart_series_t *ser, lv_coord_t array[]){
	lv_chart_set_ext_y_array(cObj.get(),ser,array);
	return *this;
}
LvChart& LvChart::setExtXArray(lv_chart_series_t *ser, lv_coord_t array[]){
	lv_chart_set_ext_x_array(cObj.get(),ser,array);
	return *this;
}
lv_coord_t *LvChart::getYArray(lv_chart_series_t *ser) const noexcept {
	return lv_chart_get_y_array(cObj.get(),ser);
	
}
lv_coord_t *LvChart::getXArray(lv_chart_series_t *ser) const noexcept {
	return lv_chart_get_x_array(cObj.get(),ser);
	
}
uint32_t LvChart::getPressedPoint() const noexcept {
	return lv_chart_get_pressed_point(cObj.get());
	
}

} /* namespace lvglpp */
