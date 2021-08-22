/*
 * LvWin.h
 *
 */

#ifndef LVWIN_H_
#define LVWIN_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvWin: public LvObj {
public:
	LvWin();
	LvWin(LvObj* Parent);
	LvWin(LvObj* Parent,lv_coord_t header_height);
	virtual ~LvWin() override;
	lv_obj_t *addTitle(const char *txt);
	lv_obj_t *addBtn(const void *icon, lv_coord_t btn_w);
	lv_obj_t *getHeader() const noexcept ;
	lv_obj_t *getContent() const noexcept ;
};

} /* namespace lvglpp */

#endif /* LVWIN_H_ */
