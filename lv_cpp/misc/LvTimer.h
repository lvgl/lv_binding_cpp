/*
 * LvTimer.h
 *
 */

#ifndef LVTIMER_H_
#define LVTIMER_H_

#include "../core/lvglpp.h"


namespace lvglpp {

class LvTimer {
private:
	
	LvPointer<lv_timer_t, lv_timer_del> cObj;
public:
	LvTimer();
	virtual ~LvTimer();
	lv_timer_t* raw();
	LvTimer& setCb(lv_timer_cb_t timer_cb);
	LvTimer& del();
	LvTimer& pause();
	LvTimer& resume();
	LvTimer& setPeriod(uint32_t period);
	LvTimer& ready();
	LvTimer& setRepeatCount(int32_t repeat_count);
	LvTimer& reset();
	lv_timer_t *getNext() const noexcept ;
};

} /* namespace lvglpp */

#endif /* LVTIMER_H_ */
