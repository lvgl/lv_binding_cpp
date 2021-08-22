/*
 * LvArc.h
 *
 */

#ifndef LVARC_H_
#define LVARC_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvArc: public LvObj {
public:
	LvArc();
	LvArc(LvObj* Parent);
	virtual ~LvArc() override;
	LvArc& setStartAngle(uint16_t start);
	LvArc& setEndAngle(uint16_t end);
	LvArc& setAngles(uint16_t start, uint16_t end);
	LvArc& setBgStartAngle(uint16_t start);
	LvArc& setBgEndAngle(uint16_t end);
	LvArc& setBgAngles(uint16_t start, uint16_t end);
	LvArc& setRotation(uint16_t rotation);
	LvArc& setMode(lv_arc_mode_t type);
	LvArc& setValue(int16_t value);
	LvArc& setRange(int16_t min, int16_t max);
	LvArc& setChangeRate(uint16_t rate);
	uint16_t getAngleStart() const noexcept ;
	uint16_t getAngleEnd() const noexcept ;
	uint16_t getBgAngleStart() const noexcept ;
	uint16_t getBgAngleEnd() const noexcept ;
	int16_t getValue() const noexcept ;
	int16_t getMinValue() const noexcept ;
	int16_t getMaxValue() const noexcept ;
	lv_arc_mode_t getMode() const noexcept ;
};

} /* namespace lvglpp */

#endif /* LVARC_H_ */
