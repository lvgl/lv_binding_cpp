/*
 * LvMeter.h
 *
 */

#ifndef LVMETER_H_
#define LVMETER_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvMeter: public LvObj {
public:
	LvMeter();
	LvMeter(LvObj* Parent);
	virtual ~LvMeter() override;
	lv_meter_scale_t *addScale();
	LvMeter& setScaleTicks(lv_meter_scale_t *scale, uint16_t cnt, uint16_t width, uint16_t len, lv_color_t color);
	LvMeter& setScaleMajorTicks(lv_meter_scale_t *scale, uint16_t nth, uint16_t width, uint16_t len, lv_color_t color, int16_t label_gap);
	LvMeter& setScaleRange(lv_meter_scale_t *scale, int32_t min, int32_t max, uint32_t angle_range, uint32_t rotation);
	lv_meter_indicator_t *addNeedleLine(lv_meter_scale_t *scale, uint16_t width, lv_color_t color, int16_t r_mod);
	lv_meter_indicator_t *addNeedleImg(lv_meter_scale_t *scale, const void *src, lv_coord_t pivot_x, lv_coord_t pivot_y);
	lv_meter_indicator_t *addArc(lv_meter_scale_t *scale, uint16_t width, lv_color_t color, int16_t r_mod);
	lv_meter_indicator_t *addScaleLines(lv_meter_scale_t *scale, lv_color_t color_start, lv_color_t color_end, bool local, int16_t width_mod);
	LvMeter& setIndicatorValue(lv_meter_indicator_t *indic, int32_t value);
	LvMeter& setIndicatorStartValue(lv_meter_indicator_t *indic, int32_t value);
	LvMeter& setIndicatorEndValue(lv_meter_indicator_t *indic, int32_t value);
};

} /* namespace lvglpp */

#endif /* LVMETER_H_ */
