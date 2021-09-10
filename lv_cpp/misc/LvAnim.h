/*
 * LvAnim.h
 *
 */

#ifndef LVanim_H_
#define LVanim_H_

#include "../core/lvglpp.h"

namespace lvglpp {

class LvAnim {
private:
	
	LvPointer<lv_anim_t, lv_mem_free> cObj;
public:
	LvAnim();
	virtual ~LvAnim();
	lv_anim_t* raw();
	LvAnim& setVar(void *var);
	LvAnim& setExecCb(lv_anim_exec_xcb_t exec_cb);
	LvAnim& setTime(uint32_t duration);
	LvAnim& setDelay(uint32_t delay);
	LvAnim& setValues(int32_t start, int32_t end);
	LvAnim& setCustomExecCb(lv_anim_custom_exec_cb_t exec_cb);
	LvAnim& setPathCb(lv_anim_path_cb_t path_cb);
	LvAnim& setStartCb(lv_anim_ready_cb_t start_cb);
	LvAnim& setGetValueCb(lv_anim_get_value_cb_t get_value_cb);
	LvAnim& setReadyCb(lv_anim_ready_cb_t ready_cb);
	LvAnim& setPlaybackTime(uint32_t time);
	LvAnim& setPlaybackDelay(uint32_t delay);
	LvAnim& setRepeatCount(uint16_t cnt);
	LvAnim& setRepeatDelay(uint32_t delay);
	LvAnim& setEarlyApply(bool en);
	uint32_t getDelay() const noexcept ;
	bool customDel(lv_anim_custom_exec_cb_t exec_cb);
	LvAnim& init();
	lv_anim_t *start();
	int32_t pathLinear();
	int32_t pathEaseIn();
	int32_t pathEaseOut();
	int32_t pathEaseInOut();
	int32_t pathOvershoot();
	int32_t pathBounce();
	int32_t pathStep();
};

} /* namespace lvglpp */

#endif /* LVanim_H_ */
