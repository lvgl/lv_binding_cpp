/*
 * LvScr.h
 *
 */

#ifndef LVSCR_H_
#define LVSCR_H_

#include "LvObj.h"

namespace lvglpp {

class LvScr: public LvObj {
public:
	LvScr();
	LvScr(LvObj* Parent);
	virtual ~LvScr() override;

	LvScr& Load();
	LvScr& LoadAnim(lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool auto_del);
//	static LvScr& Act();
};

} /* namespace lvglpp */

#endif /* LVSCR_H_ */
