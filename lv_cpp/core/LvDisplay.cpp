/*
 * LvDisplay.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: fstuffdev
 */

#include "LvDisplay.h"

#if (USE_MONITOR + USE_FBDEV ) > 1
#error "You cannot specify more than one display driver"
#endif

/* Input */
#if USE_MONITOR
#include <lv_drivers/display/monitor.h>
#include <SDL2/SDL.h>
#endif

#if USE_FBDEV
#include <lv_drivers/display/fbdev.h>
#endif

namespace lvglpp {

LvDisplay::LvDisplay() :
		LvDisplay(NULL) {
}

LvDisplay::LvDisplay(lv_disp_drv_t *drv) :
#if USE_MONITOR
				LvDisplay(drv, MONITOR_HOR_RES, MONITOR_VER_RES)
#endif

#if USE_FBDEV
	LvDisplay(drv, 480, 320)
#endif
{

}

LvDisplay::LvDisplay(lv_disp_drv_t *drv, unsigned int hres, unsigned int vres) {

	disp_drv.reset((lv_disp_drv_t*)lv_mem_alloc(sizeof(lv_disp_drv_t)));
	disp_buf1.reset((lv_disp_draw_buf_t*)lv_mem_alloc(sizeof(lv_disp_draw_buf_t)));

	lv_disp_drv_init(disp_drv.get());
	uint32_t w = 0;
	uint32_t h = 0;

#if USE_MONITOR
	monitor_init();
	disp_drv->flush_cb = monitor_flush;
	w = MONITOR_HOR_RES;
	h = MONITOR_VER_RES;

#if LV_DISP_BUFFER_STATIC
#endif

#endif

#if USE_FBDEV

	fbdev_init();
	fbdev_get_sizes(&w, &h);

	disp_drv->flush_cb = fbdev_flush;

#if LV_DISP_BUFFER_STATIC
#define MONITOR_HOR_RES 640
#endif

#endif

#if !LV_DISP_BUFFER_STATIC
	buf1_1.reset((lv_color_t*)lv_mem_alloc(h * 100));
	buf1_2.reset((lv_color_t*)lv_mem_alloc(h * 100));
	lv_disp_draw_buf_init(disp_buf1.get(), buf1_1.get(), buf1_2.get(), w * 100);
#else
	static lv_color_t buf1_1[MONITOR_HOR_RES * 100];
	static lv_color_t buf1_2[MONITOR_HOR_RES * 100];
	lv_disp_draw_buf_init(disp_buf1.get(), buf1_1, buf1_2, MONITOR_HOR_RES * 100);
#endif

	/* Initialize with basic configuration*/
	if (!drv) {
		/*Create a display*/
		disp_drv->draw_buf = disp_buf1.get();
		disp_drv->antialiasing = 1;
		disp_drv->sw_rotate = 1;
		disp_drv->hor_res = w;
		disp_drv->ver_res = h;
		disp_drv->rotated = LV_DISP_ROT_NONE;
	} else
		memcpy(disp_drv.get(), drv, sizeof(lv_disp_drv_t));
	disp.reset(lv_disp_drv_register(disp_drv.get()));
	void(0);
}


LvDisplay::~LvDisplay() {

}

LvDisplay& LvDisplay::Rotate() {

	lv_disp_rot_t rot = LV_DISP_ROT_NONE;
	lv_disp_rot_t future_rot = LV_DISP_ROT_NONE;
	rot = lv_disp_get_rotation(disp.get());

	switch (rot) {
	case LV_DISP_ROT_NONE:
		future_rot = LV_DISP_ROT_90;
		break;

	case LV_DISP_ROT_90:
		future_rot = LV_DISP_ROT_180;
		break;

	case LV_DISP_ROT_180:
		future_rot = LV_DISP_ROT_270;
		break;

	case LV_DISP_ROT_270:
		future_rot = LV_DISP_ROT_NONE;
		break;
	}

	lv_disp_set_rotation(disp.get(), future_rot);

	return *this;

}

LvDisplay& LvDisplay::Rotate(unsigned int deg) {

	unsigned int rotstep = 1;

	if (deg % 90 == 0) {
		rotstep = deg / 90;
		for (int i = 0; i < rotstep; i++)
			Rotate();
	}

	return *this;

}

unsigned int LvDisplay::getWidth() {
	return disp_drv->hor_res;
}

unsigned int LvDisplay::getHeight() {
	return disp_drv->ver_res;
}



} /* namespace lvGL */
