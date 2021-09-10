/*
 * LvInput.h
 *
 *  Created on: Sep 29, 2020
 *      Author: fstuffdev
 */

#ifndef LVINPUT_H_
#define LVINPUT_H_

#include <lv_drv_conf.h>
#include "lvglpp.h"
#include "../widgets/LvImg.h"

namespace lvglpp {

class LvInput {
private:
	lv_indev_drv_t indev_drv;
	LvPointer<lv_indev_t,lv_mem_free> indev;
	LvPointerUnique<LvImg> Cursor;
public:
	LvInput();
	LvInput(lv_indev_drv_t *drv);
	virtual ~LvInput();

	LvInput& setCursor(LvImg& Img);
	LvInput& enableCursor();
};

} /* namespace lvGL */

#endif /* LVINPUT_H_ */
