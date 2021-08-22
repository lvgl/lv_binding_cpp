/*
 * LvSpinbox.h
 *
 */

#ifndef LVSPINBOX_H_
#define LVSPINBOX_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvSpinbox: public LvObj {
public:
	LvSpinbox();
	LvSpinbox(LvObj* Parent);
	virtual ~LvSpinbox() override;
	LvSpinbox& setValue(int32_t i);
	LvSpinbox& setRollover(bool b);
	LvSpinbox& setDigitFormat(uint8_t digit_count, uint8_t separator_position);
	LvSpinbox& setStep(uint32_t step);
	LvSpinbox& setRange(int32_t range_min, int32_t range_max);
	int32_t getValue() const noexcept ;
	int32_t getStep() const noexcept ;
	LvSpinbox& stepNext();
	LvSpinbox& stepPrev();
	bool getRollover() const noexcept ;
	LvSpinbox& increment();
	LvSpinbox& decrement();
};

} /* namespace lvglpp */

#endif /* LVSPINBOX_H_ */
