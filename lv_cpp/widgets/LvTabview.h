/*
 * LvTabview.h
 *
 */

#ifndef LVTABVIEW_H_
#define LVTABVIEW_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvTabview: public LvObj {
public:
	LvTabview();
	LvTabview(LvObj* Parent);
	LvTabview(LvObj* Parent,lv_dir_t tab_pos,lv_coord_t tab_size);
	virtual ~LvTabview() override;
	LvObj& addTab(const char *name);
	LvTabview& setAct(uint32_t id, lv_anim_enable_t anim_en);
	uint16_t getTabAct() const noexcept ;
};

} /* namespace lvglpp */

#endif /* LVTABVIEW_H_ */
