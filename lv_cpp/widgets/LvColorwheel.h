/*
 * LvColorwheel.h
 *
 */

#ifndef LVCOLORWHEEL_H_
#define LVCOLORWHEEL_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvColorwheel: public LvObj {
public:
	LvColorwheel();
	LvColorwheel(LvObj* Parent);
	virtual ~LvColorwheel() override;
	bool setHsv(lv_color_hsv_t hsv);
	bool setRgb(lv_color_t color);
	LvColorwheel& setMode(lv_colorwheel_mode_t mode);
	LvColorwheel& setModeFixed(bool fixed);
	lv_color_hsv_t getHsv() const noexcept ;
	lv_color_t getRgb() const noexcept ;
	lv_colorwheel_mode_t getColorMode() const noexcept ;
	bool getColorModeFixed() const noexcept ;
};

} /* namespace lvglpp */

#endif /* LVCOLORWHEEL_H_ */
