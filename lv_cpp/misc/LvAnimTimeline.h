/*
 * LvAnimTimeline.h
 *
 */

#ifndef LVANIM_TIMELINE_H_
#define LVANIM_TIMELINE_H_

#include "../core/lvglpp.h"
#include "LvAnim.h"

namespace lvglpp {

class LvAnimTimeline {
private:
	
	LvPointer<lv_anim_timeline_t, lv_anim_timeline_del> cObj;
public:
	LvAnimTimeline();
	virtual ~LvAnimTimeline();
	lv_anim_timeline_t* raw();
	LvAnimTimeline& del();
	LvAnimTimeline& add(uint32_t start_time, LvAnim *a);
	uint32_t start();
	LvAnimTimeline& stop();
	LvAnimTimeline& setReverse(bool reverse);
	LvAnimTimeline& setProgress(uint16_t progress);
	uint32_t getPlaytime() const noexcept ;
	bool getReverse() const noexcept ;
};

} /* namespace lvglpp */

#endif /* LVANIM_TIMELINE_H_ */
