/*
 * LvLed.h
 *
 */

#ifndef LVLED_H_
#define LVLED_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvLed: public LvObj {
public:
	LvLed();
	LvLed(LvObj* Parent);
	virtual ~LvLed() override;
	LvLed& setColor(lv_color_t color);
	LvLed& setBrightness(uint8_t bright);
	LvLed& on();
	LvLed& off();
	LvLed& toggle();
	uint8_t getBrightness() const noexcept ;
};

} /* namespace lvglpp */

#endif /* LVLED_H_ */
