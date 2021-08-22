/*
 * LvChart.h
 *
 */

#ifndef LVCHART_H_
#define LVCHART_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvChart: public LvObj {
public:
	LvChart();
	LvChart(LvObj* Parent);
	virtual ~LvChart() override;
	LvChart& setType(lv_chart_type_t type);
	LvChart& setPointCount(uint16_t cnt);
	LvChart& setRange(lv_chart_axis_t axis, lv_coord_t min, lv_coord_t max);
	LvChart& setUpdateMode(lv_chart_update_mode_t update_mode);
	LvChart& setDivLineCount(uint8_t hdiv, uint8_t vdiv);
	LvChart& setZoomX(uint16_t zoom_x);
	LvChart& setZoomY(uint16_t zoom_y);
	uint16_t getZoomX() const noexcept ;
	uint16_t getZoomY() const noexcept ;
	LvChart& setAxisTick(lv_chart_axis_t axis, lv_coord_t major_len, lv_coord_t minor_len, lv_coord_t major_cnt, lv_coord_t minor_cnt, bool label_en, lv_coord_t draw_size);
	lv_chart_type_t getType() const noexcept ;
	uint16_t getPointCount() const noexcept ;
	uint16_t getXStartPoint(lv_chart_series_t *ser) const noexcept ;
	LvChart& getPointPosById(lv_chart_series_t *ser, uint16_t id, lv_point_t *p_out);
	LvChart& refresh();
	lv_chart_series_t *addSeries(lv_color_t color, lv_chart_axis_t axis);
	LvChart& removeSeries(lv_chart_series_t *series);
	LvChart& hideSeries(lv_chart_series_t *series, bool hide);
	LvChart& setSeriesColor(lv_chart_series_t *series, lv_color_t color);
	LvChart& setXStartPoint(lv_chart_series_t *ser, uint16_t id);
	lv_chart_series_t *getSeriesNext(const lv_chart_series_t *ser) const noexcept ;
	lv_chart_cursor_t *addCursor(lv_color_t color, lv_dir_t dir);
	LvChart& setCursorPos(lv_chart_cursor_t *cursor, lv_point_t *pos);
	LvChart& setCursorPoint(lv_chart_cursor_t *cursor, lv_chart_series_t *ser, uint16_t point_id);
	lv_point_t getCursorPoint(lv_chart_cursor_t *cursor) const noexcept ;
	LvChart& setAllValue(lv_chart_series_t *ser, lv_coord_t value);
	LvChart& setNextValue(lv_chart_series_t *ser, lv_coord_t value);
	LvChart& setNextValue2(lv_chart_series_t *ser, lv_coord_t x_value, lv_coord_t y_value);
	LvChart& setValueById(lv_chart_series_t *ser, uint16_t id, lv_coord_t value);
	LvChart& setValueById2(lv_chart_series_t *ser, uint16_t id, lv_coord_t x_value, lv_coord_t y_value);
	LvChart& setExtYArray(lv_chart_series_t *ser, lv_coord_t array[]);
	LvChart& setExtXArray(lv_chart_series_t *ser, lv_coord_t array[]);
	lv_coord_t *getYArray(lv_chart_series_t *ser) const noexcept ;
	lv_coord_t *getXArray(lv_chart_series_t *ser) const noexcept ;
	uint32_t getPressedPoint() const noexcept ;
};

} /* namespace lvglpp */

#endif /* LVCHART_H_ */
