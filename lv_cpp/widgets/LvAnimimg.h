/*
 * LvAnimimg.h
 *
 */

#ifndef LVANIMIMG_H_
#define LVANIMIMG_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvAnimimg: public LvObj {
public:
	LvAnimimg();
	LvAnimimg(LvObj* Parent);
	virtual ~LvAnimimg() override;
	LvAnimimg& setSrc(lv_img_dsc_t *dsc[], uint8_t num);
	LvAnimimg& start();
	LvAnimimg& setDuration(uint32_t duration);
	LvAnimimg& setRepeatCount(uint16_t count);
};

} /* namespace lvglpp */

#endif /* LVANIMIMG_H_ */
