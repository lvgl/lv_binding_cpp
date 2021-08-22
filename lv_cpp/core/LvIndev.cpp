/*
 * LvInput.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: fstuffdev
 */

#include "LvIndev.h"

/* Default cursor for pointer */
extern "C" {
	LV_IMG_DECLARE(mouse_cursor_icon);
}

#if (USE_MOUSE + USE_EVDEV + USE_LINMICE + USE_LIBINPUT) > 1
#error "You cannot specify more than one input driver"
#endif

/* Input */
#if USE_MOUSE
#include <lv_drivers/indev/mouse.h>
#endif

#if USE_EVDEV
#include <lv_drivers/indev/evdev.h>
#endif

#if USE_LINMICE
#include "../custom/drivers/linmice.h"
#endif

#if USE_LIBINPUT
#include <lv_drivers/indev/libinput_drv.h>
#endif


namespace lvglpp {

lv_img_dsc_t idev_cursor_icon;

LvInput::LvInput() :
		LvInput(NULL) {

}

LvInput::LvInput(lv_indev_drv_t *drv) {

	lv_indev_drv_init(&indev_drv); /*Basic initialization*/

	if (!drv) {

#if USE_MOUSE
		mouse_init();
		indev_drv.read_cb = mouse_read;
#endif

#if USE_EVDEV
		evdev_init();
		indev_drv.read_cb = evdev_read;
#endif

#if USE_LIBINPUT
		libinput_init();
		indev_drv.read_cb = libinput_read;
#endif

#if USE_LINMICE
		linmice_init();
		indev_drv.read_cb = linmice_read;
#endif

#if USE_MOUSE | USE_EVDEV | USE_LINMICE | USE_LIBINPUT
		indev_drv.type = LV_INDEV_TYPE_POINTER;
#endif

	} else {
		memcpy(&indev_drv, drv, sizeof(lv_indev_drv_t));
	}

	indev.reset(lv_indev_drv_register(&indev_drv));

}


LvInput& LvInput::setCursor(LvImg& Img) {
	lv_indev_set_cursor(indev.get(), Img.raw());
	return *this;
}

LvInput& LvInput::enableCursor() {

	if(!Cursor.get())
		Cursor = Make<LvImg>();
	Cursor->setSrc(&mouse_cursor_icon);
	setCursor(*Cursor.get());

	return *this;

}





LvInput::~LvInput() {

}

} /* namespace lvGL */
