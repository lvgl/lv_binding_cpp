/*
 * LvDisplay.h
 *
 *  created on: sep 29, 2020
 *      author: fstuffdev
 */

#ifndef LVDISPLAY_H_
#define LVDISPLAY_H_

#include <lv_drv_conf.h>
#include "lvglpp.h"

#ifndef LV_DISP_BUFFER_STATIC
#define LV_DISP_BUFFER_STATIC 1
#endif

namespace lvglpp {

class LvDisplay {
private:
	LvPointer<lv_disp_draw_buf_t,lv_mem_free> disp_buf1;
	LvPointer<lv_disp_drv_t,lv_mem_free> disp_drv;

#if !LV_DISP_BUFFER_STATIC
	LvPointer<lv_color_t,lv_mem_free> buf1_1;
	LvPointer<lv_color_t,lv_mem_free> buf1_2;
#endif
	LvPointer<lv_disp_t,lv_mem_free> disp;
public:
	LvDisplay();
	LvDisplay(lv_disp_drv_t *drv);
	LvDisplay(lv_disp_drv_t *drv, unsigned int hres, unsigned int vres);

	LvDisplay& Rotate();
	LvDisplay& Rotate(unsigned int deg);
	unsigned int getWidth();
	unsigned int getHeight();

	virtual ~LvDisplay();
};

} /* namespace lvGL */

#endif /* LVDISPLAY_H_ */
