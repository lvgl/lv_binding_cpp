/*
 * LvList.h
 *
 */

#ifndef LVLIST_H_
#define LVLIST_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvList: public LvObj {
public:
	LvList();
	LvList(LvObj* Parent);
	virtual ~LvList() override;
	lv_obj_t *addText(const char *txt);
	lv_obj_t *addBtn(const char *icon, const char *txt);
	const char *getBtnText(lv_obj_t *btn) const noexcept ;
};

} /* namespace lvglpp */

#endif /* LVLIST_H_ */
