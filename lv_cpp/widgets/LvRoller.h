/*
 * LvRoller.h
 *
 */

#ifndef LVROLLER_H_
#define LVROLLER_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvRoller: public LvObj {
public:
	LvRoller();
	LvRoller(LvObj* Parent);
	virtual ~LvRoller() override;
	LvRoller& setOptions(const char *options, lv_roller_mode_t mode);
	LvRoller& setSelected(uint16_t sel_opt, lv_anim_enable_t anim);
	LvRoller& setVisibleRowCount(uint8_t row_cnt);
	uint16_t getSelected() const noexcept ;
	LvRoller& getSelectedStr(char *buf, uint32_t buf_size);
	const char *getOptions() const noexcept ;
	uint16_t getOptionCnt() const noexcept ;
};

} /* namespace lvglpp */

#endif /* LVROLLER_H_ */
