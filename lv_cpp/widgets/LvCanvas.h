/*
 * LvCanvas.h
 *
 */

#ifndef LVCANVAS_H_
#define LVCANVAS_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvCanvas: public LvObj {
public:
	LvCanvas();
	LvCanvas(LvObj* Parent);
	virtual ~LvCanvas() override;
	LvCanvas& setBuffer(void *buf, lv_coord_t w, lv_coord_t h, lv_img_cf_t cf);
	LvCanvas& setPx(lv_coord_t x, lv_coord_t y, lv_color_t c);
	LvCanvas& setPalette(uint8_t id, lv_color_t c);
	lv_color_t getPx(lv_coord_t x, lv_coord_t y) const noexcept ;
	lv_img_dsc_t *getImg() const noexcept ;
	LvCanvas& copyBuf(const void *to_copy, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h);
	LvCanvas& transform(lv_img_dsc_t *img, int16_t angle, uint16_t zoom, lv_coord_t offset_x, lv_coord_t offset_y, int32_t pivot_x, int32_t pivot_y, bool antialias);
	LvCanvas& blurHor(const lv_area_t *area, uint16_t r);
	LvCanvas& blurVer(const lv_area_t *area, uint16_t r);
	LvCanvas& fillBg(lv_color_t color, lv_opa_t opa);
	LvCanvas& drawRect(lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h, const lv_draw_rect_dsc_t *draw_dsc);
	LvCanvas& drawText(lv_coord_t x, lv_coord_t y, lv_coord_t max_w, lv_draw_label_dsc_t *draw_dsc, const char *txt);
	LvCanvas& drawImg(lv_coord_t x, lv_coord_t y, const void *src, const lv_draw_img_dsc_t *draw_dsc);
	LvCanvas& drawLine(const lv_point_t points[], uint32_t point_cnt, const lv_draw_line_dsc_t *draw_dsc);
	LvCanvas& drawPolygon(const lv_point_t points[], uint32_t point_cnt, const lv_draw_rect_dsc_t *draw_dsc);
	LvCanvas& drawArc(lv_coord_t x, lv_coord_t y, lv_coord_t r, int32_t start_angle, int32_t end_angle, const lv_draw_arc_dsc_t *draw_dsc);
};

} /* namespace lvglpp */

#endif /* LVCANVAS_H_ */
