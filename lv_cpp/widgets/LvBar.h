/*
 * LvBar.h
 *
 */

#ifndef LVBAR_H_
#define LVBAR_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvBar: public LvObj {
public:
	LvBar();
	LvBar(LvObj* Parent);
	virtual ~LvBar() override;
	LvBar& setValue(int32_t value, lv_anim_enable_t anim);
	LvBar& setStartValue(int32_t value, lv_anim_enable_t anim);
	LvBar& setRange(int32_t min, int32_t max);
	LvBar& setMode(lv_bar_mode_t mode);
	int32_t getValue() const noexcept ;
	int32_t getStartValue() const noexcept ;
	int32_t getMinValue() const noexcept ;
	int32_t getMaxValue() const noexcept ;
	lv_bar_mode_t getMode() const noexcept ;
};

} /* namespace lvglpp */

#endif /* LVBAR_H_ */
