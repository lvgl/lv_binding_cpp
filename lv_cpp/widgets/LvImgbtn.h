/*
 * LvImgbtn.h
 *
 */

#ifndef LVIMGBTN_H_
#define LVIMGBTN_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvImgbtn: public LvObj {
public:
	LvImgbtn();
	LvImgbtn(LvObj* Parent);
	virtual ~LvImgbtn() override;
	LvImgbtn& setSrc(lv_imgbtn_state_t state, const void *src_left, const void *src_mid, const void *src_right);
	const void *getSrcLeft(lv_imgbtn_state_t state) const noexcept ;
	const void *getSrcMiddle(lv_imgbtn_state_t state) const noexcept ;
	const void *getSrcRight(lv_imgbtn_state_t state) const noexcept ;
};

} /* namespace lvglpp */

#endif /* LVIMGBTN_H_ */
