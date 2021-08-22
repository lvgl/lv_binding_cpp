/*
 * LvMeter.cpp
 *
 */

#include "LvMeter.h"

namespace lvglpp {

LvMeter::LvMeter() : LvMeter(NULL) {
}

LvMeter::LvMeter(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_meter_create(Parent->raw()));
	else
		cObj.reset(lv_meter_create(lv_scr_act()));

	setUserData(this);
}

LvMeter::~LvMeter() {
}
lv_meter_scale_t *LvMeter::addScale(){
	return lv_meter_add_scale(cObj.get());
	
}
LvMeter& LvMeter::setScaleTicks(lv_meter_scale_t *scale, uint16_t cnt, uint16_t width, uint16_t len, lv_color_t color){
	lv_meter_set_scale_ticks(cObj.get(),scale,cnt,width,len,color);
	return *this;
}
LvMeter& LvMeter::setScaleMajorTicks(lv_meter_scale_t *scale, uint16_t nth, uint16_t width, uint16_t len, lv_color_t color, int16_t label_gap){
	lv_meter_set_scale_major_ticks(cObj.get(),scale,nth,width,len,color,label_gap);
	return *this;
}
LvMeter& LvMeter::setScaleRange(lv_meter_scale_t *scale, int32_t min, int32_t max, uint32_t angle_range, uint32_t rotation){
	lv_meter_set_scale_range(cObj.get(),scale,min,max,angle_range,rotation);
	return *this;
}
lv_meter_indicator_t *LvMeter::addNeedleLine(lv_meter_scale_t *scale, uint16_t width, lv_color_t color, int16_t r_mod){
	return lv_meter_add_needle_line(cObj.get(),scale,width,color,r_mod);
	
}
lv_meter_indicator_t *LvMeter::addNeedleImg(lv_meter_scale_t *scale, const void *src, lv_coord_t pivot_x, lv_coord_t pivot_y){
	return lv_meter_add_needle_img(cObj.get(),scale,src,pivot_x,pivot_y);
	
}
lv_meter_indicator_t *LvMeter::addArc(lv_meter_scale_t *scale, uint16_t width, lv_color_t color, int16_t r_mod){
	return lv_meter_add_arc(cObj.get(),scale,width,color,r_mod);
	
}
lv_meter_indicator_t *LvMeter::addScaleLines(lv_meter_scale_t *scale, lv_color_t color_start, lv_color_t color_end, bool local, int16_t width_mod){
	return lv_meter_add_scale_lines(cObj.get(),scale,color_start,color_end,local,width_mod);
	
}
LvMeter& LvMeter::setIndicatorValue(lv_meter_indicator_t *indic, int32_t value){
	lv_meter_set_indicator_value(cObj.get(),indic,value);
	return *this;
}
LvMeter& LvMeter::setIndicatorStartValue(lv_meter_indicator_t *indic, int32_t value){
	lv_meter_set_indicator_start_value(cObj.get(),indic,value);
	return *this;
}
LvMeter& LvMeter::setIndicatorEndValue(lv_meter_indicator_t *indic, int32_t value){
	lv_meter_set_indicator_end_value(cObj.get(),indic,value);
	return *this;
}

} /* namespace lvglpp */
