/*
 * LvImg.h
 *
 */

#ifndef LVIMG_H_
#define LVIMG_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvImg: public LvObj {
public:
	LvImg();
	LvImg(LvObj* Parent);
	virtual ~LvImg() override;
	LvImg& setSrc(const void *src);
	LvImg& setOffsetX(lv_coord_t x);
	LvImg& setOffsetY(lv_coord_t y);
	LvImg& setAngle(int16_t angle);
	LvImg& setPivot(lv_coord_t x, lv_coord_t y);
	LvImg& setZoom(uint16_t zoom);
	LvImg& setAntialias(bool antialias);
	const void *getSrc() const noexcept ;
	lv_coord_t getOffsetX() const noexcept ;
	lv_coord_t getOffsetY() const noexcept ;
	uint16_t getAngle() const noexcept ;
	LvImg& getPivot(lv_point_t *pivot);
	uint16_t getZoom() const noexcept ;
	bool getAntialias() const noexcept ;
};

} /* namespace lvglpp */

#endif /* LVIMG_H_ */
