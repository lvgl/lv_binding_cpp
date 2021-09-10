/*
 * LvAnim.cpp
 *
 */

#include "LvAnim.h"

namespace lvglpp {

LvAnim::LvAnim() {
	cObj.reset((lv_anim_t*)lv_mem_alloc(sizeof(lv_anim_t)));
	
}

LvAnim::~LvAnim() {
}

lv_anim_t* LvAnim::raw() {
	return cObj.get();
}
LvAnim& LvAnim::setVar(void *var){
	lv_anim_set_var(cObj.get(),var);
	return *this;
}
LvAnim& LvAnim::setExecCb(lv_anim_exec_xcb_t exec_cb){
	lv_anim_set_exec_cb(cObj.get(),exec_cb);
	return *this;
}
LvAnim& LvAnim::setTime(uint32_t duration){
	lv_anim_set_time(cObj.get(),duration);
	return *this;
}
LvAnim& LvAnim::setDelay(uint32_t delay){
	lv_anim_set_delay(cObj.get(),delay);
	return *this;
}
LvAnim& LvAnim::setValues(int32_t start, int32_t end){
	lv_anim_set_values(cObj.get(),start,end);
	return *this;
}
LvAnim& LvAnim::setCustomExecCb(lv_anim_custom_exec_cb_t exec_cb){
	lv_anim_set_custom_exec_cb(cObj.get(),exec_cb);
	return *this;
}
LvAnim& LvAnim::setPathCb(lv_anim_path_cb_t path_cb){
	lv_anim_set_path_cb(cObj.get(),path_cb);
	return *this;
}
LvAnim& LvAnim::setStartCb(lv_anim_ready_cb_t start_cb){
	lv_anim_set_start_cb(cObj.get(),start_cb);
	return *this;
}
LvAnim& LvAnim::setGetValueCb(lv_anim_get_value_cb_t get_value_cb){
	lv_anim_set_get_value_cb(cObj.get(),get_value_cb);
	return *this;
}
LvAnim& LvAnim::setReadyCb(lv_anim_ready_cb_t ready_cb){
	lv_anim_set_ready_cb(cObj.get(),ready_cb);
	return *this;
}
LvAnim& LvAnim::setPlaybackTime(uint32_t time){
	lv_anim_set_playback_time(cObj.get(),time);
	return *this;
}
LvAnim& LvAnim::setPlaybackDelay(uint32_t delay){
	lv_anim_set_playback_delay(cObj.get(),delay);
	return *this;
}
LvAnim& LvAnim::setRepeatCount(uint16_t cnt){
	lv_anim_set_repeat_count(cObj.get(),cnt);
	return *this;
}
LvAnim& LvAnim::setRepeatDelay(uint32_t delay){
	lv_anim_set_repeat_delay(cObj.get(),delay);
	return *this;
}
LvAnim& LvAnim::setEarlyApply(bool en){
	lv_anim_set_early_apply(cObj.get(),en);
	return *this;
}
uint32_t LvAnim::getDelay() const noexcept {
	return lv_anim_get_delay(cObj.get());
	
}
bool LvAnim::customDel(lv_anim_custom_exec_cb_t exec_cb){
	return lv_anim_custom_del(cObj.get(),exec_cb);
	
}
LvAnim& LvAnim::init(){
	lv_anim_init(cObj.get());
	return *this;
}
lv_anim_t *LvAnim::start(){
	return lv_anim_start(cObj.get());
	
}
int32_t LvAnim::pathLinear(){
	return lv_anim_path_linear(cObj.get());
	
}
int32_t LvAnim::pathEaseIn(){
	return lv_anim_path_ease_in(cObj.get());
	
}
int32_t LvAnim::pathEaseOut(){
	return lv_anim_path_ease_out(cObj.get());
	
}
int32_t LvAnim::pathEaseInOut(){
	return lv_anim_path_ease_in_out(cObj.get());
	
}
int32_t LvAnim::pathOvershoot(){
	return lv_anim_path_overshoot(cObj.get());
	
}
int32_t LvAnim::pathBounce(){
	return lv_anim_path_bounce(cObj.get());
	
}
int32_t LvAnim::pathStep(){
	return lv_anim_path_step(cObj.get());
	
}

} /* namespace lvglpp */
