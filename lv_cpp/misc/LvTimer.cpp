/*
 * LvTimer.cpp
 *
 */

#include "LvTimer.h"

namespace lvglpp {

LvTimer::LvTimer() {
	cObj.reset(lv_timer_create_basic());
	
}

LvTimer::~LvTimer() {
}

lv_timer_t* LvTimer::raw() {
	return cObj.get();
}
LvTimer& LvTimer::setCb(lv_timer_cb_t timer_cb){
	lv_timer_set_cb(cObj.get(),timer_cb);
	return *this;
}
LvTimer& LvTimer::del(){
	lv_timer_del(cObj.get());
	return *this;
}
LvTimer& LvTimer::pause(){
	lv_timer_pause(cObj.get());
	return *this;
}
LvTimer& LvTimer::resume(){
	lv_timer_resume(cObj.get());
	return *this;
}
LvTimer& LvTimer::setPeriod(uint32_t period){
	lv_timer_set_period(cObj.get(),period);
	return *this;
}
LvTimer& LvTimer::ready(){
	lv_timer_ready(cObj.get());
	return *this;
}
LvTimer& LvTimer::setRepeatCount(int32_t repeat_count){
	lv_timer_set_repeat_count(cObj.get(),repeat_count);
	return *this;
}
LvTimer& LvTimer::reset(){
	lv_timer_reset(cObj.get());
	return *this;
}
lv_timer_t *LvTimer::getNext() const noexcept {
	return lv_timer_get_next(cObj.get());
	
}

} /* namespace lvglpp */
