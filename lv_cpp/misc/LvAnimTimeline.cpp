/*
 * LvAnimTimeline.cpp
 *
 */

#include "LvAnimTimeline.h"

namespace lvglpp {

LvAnimTimeline::LvAnimTimeline() {
	cObj.reset(lv_anim_timeline_create());
	
}

LvAnimTimeline::~LvAnimTimeline() {
}

lv_anim_timeline_t* LvAnimTimeline::raw() {
	return cObj.get();
}
LvAnimTimeline& LvAnimTimeline::del(){
	lv_anim_timeline_del(cObj.get());
	return *this;
}
LvAnimTimeline& LvAnimTimeline::add(uint32_t start_time, LvAnim *a){
	lv_anim_timeline_add(cObj.get(),start_time,a->raw());
	return *this;
}
uint32_t LvAnimTimeline::start(){
	return lv_anim_timeline_start(cObj.get());
	
}
LvAnimTimeline& LvAnimTimeline::stop(){
	lv_anim_timeline_stop(cObj.get());
	return *this;
}
LvAnimTimeline& LvAnimTimeline::setReverse(bool reverse){
	lv_anim_timeline_set_reverse(cObj.get(),reverse);
	return *this;
}
LvAnimTimeline& LvAnimTimeline::setProgress(uint16_t progress){
	lv_anim_timeline_set_progress(cObj.get(),progress);
	return *this;
}
uint32_t LvAnimTimeline::getPlaytime() const noexcept {
	return lv_anim_timeline_get_playtime(cObj.get());
	
}
bool LvAnimTimeline::getReverse() const noexcept {
	return lv_anim_timeline_get_reverse(cObj.get());
	
}

} /* namespace lvglpp */
