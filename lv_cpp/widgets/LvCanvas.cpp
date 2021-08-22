/*
 * LvCanvas.cpp
 *
 */

#include "LvCanvas.h"

namespace lvglpp {

LvCanvas::LvCanvas() : LvCanvas(NULL) {
}

LvCanvas::LvCanvas(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_canvas_create(Parent->raw()));
	else
		cObj.reset(lv_canvas_create(lv_scr_act()));

	setUserData(this);
}

LvCanvas::~LvCanvas() {
}
LvCanvas& LvCanvas::setBuffer(void *buf, lv_coord_t w, lv_coord_t h, lv_img_cf_t cf){
	lv_canvas_set_buffer(cObj.get(),buf,w,h,cf);
	return *this;
}
LvCanvas& LvCanvas::setPx(lv_coord_t x, lv_coord_t y, lv_color_t c){
	lv_canvas_set_px(cObj.get(),x,y,c);
	return *this;
}
LvCanvas& LvCanvas::setPalette(uint8_t id, lv_color_t c){
	lv_canvas_set_palette(cObj.get(),id,c);
	return *this;
}
lv_color_t LvCanvas::getPx(lv_coord_t x, lv_coord_t y) const noexcept {
	return lv_canvas_get_px(cObj.get(),x,y);
	
}
lv_img_dsc_t *LvCanvas::getImg() const noexcept {
	return lv_canvas_get_img(cObj.get());
	
}
LvCanvas& LvCanvas::copyBuf(const void *to_copy, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h){
	lv_canvas_copy_buf(cObj.get(),to_copy,x,y,w,h);
	return *this;
}
LvCanvas& LvCanvas::transform(lv_img_dsc_t *img, int16_t angle, uint16_t zoom, lv_coord_t offset_x, lv_coord_t offset_y, int32_t pivot_x, int32_t pivot_y, bool antialias){
	lv_canvas_transform(cObj.get(),img,angle,zoom,offset_x,offset_y,pivot_x,pivot_y,antialias);
	return *this;
}
LvCanvas& LvCanvas::blurHor(const lv_area_t *area, uint16_t r){
	lv_canvas_blur_hor(cObj.get(),area,r);
	return *this;
}
LvCanvas& LvCanvas::blurVer(const lv_area_t *area, uint16_t r){
	lv_canvas_blur_ver(cObj.get(),area,r);
	return *this;
}
LvCanvas& LvCanvas::fillBg(lv_color_t color, lv_opa_t opa){
	lv_canvas_fill_bg(cObj.get(),color,opa);
	return *this;
}
LvCanvas& LvCanvas::drawRect(lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h, const lv_draw_rect_dsc_t *draw_dsc){
	lv_canvas_draw_rect(cObj.get(),x,y,w,h,draw_dsc);
	return *this;
}
LvCanvas& LvCanvas::drawText(lv_coord_t x, lv_coord_t y, lv_coord_t max_w, lv_draw_label_dsc_t *draw_dsc, const char *txt){
	lv_canvas_draw_text(cObj.get(),x,y,max_w,draw_dsc,txt);
	return *this;
}
LvCanvas& LvCanvas::drawImg(lv_coord_t x, lv_coord_t y, const void *src, const lv_draw_img_dsc_t *draw_dsc){
	lv_canvas_draw_img(cObj.get(),x,y,src,draw_dsc);
	return *this;
}
LvCanvas& LvCanvas::drawLine(const lv_point_t points[], uint32_t point_cnt, const lv_draw_line_dsc_t *draw_dsc){
	lv_canvas_draw_line(cObj.get(),points,point_cnt,draw_dsc);
	return *this;
}
LvCanvas& LvCanvas::drawPolygon(const lv_point_t points[], uint32_t point_cnt, const lv_draw_rect_dsc_t *draw_dsc){
	lv_canvas_draw_polygon(cObj.get(),points,point_cnt,draw_dsc);
	return *this;
}
LvCanvas& LvCanvas::drawArc(lv_coord_t x, lv_coord_t y, lv_coord_t r, int32_t start_angle, int32_t end_angle, const lv_draw_arc_dsc_t *draw_dsc){
	lv_canvas_draw_arc(cObj.get(),x,y,r,start_angle,end_angle,draw_dsc);
	return *this;
}

} /* namespace lvglpp */
