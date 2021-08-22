/*
 * LvSlider.h
 *
 */

#ifndef LVSLIDER_H_
#define LVSLIDER_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvSlider: public LvObj {
public:
	LvSlider();
	LvSlider(LvObj* Parent);
	virtual ~LvSlider() override;
	LvSlider& setValue(int32_t value, lv_anim_enable_t anim);
	LvSlider& setLeftValue(int32_t value, lv_anim_enable_t anim);
	LvSlider& setRange(int32_t min, int32_t max);
	LvSlider& setMode(lv_slider_mode_t mode);
	int32_t getValue() const noexcept ;
	int32_t getLeftValue() const noexcept ;
	int32_t getMinValue() const noexcept ;
	int32_t getMaxValue() const noexcept ;
	lv_slider_mode_t getMode() const noexcept ;
	bool isDragged();
};

} /* namespace lvglpp */

#endif /* LVSLIDER_H_ */
