/*
 * LvBtn.h
 *
 */

#ifndef LVBTN_H_
#define LVBTN_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvBtn: public LvObj {
public:
	LvBtn();
	LvBtn(LvObj* Parent);
	virtual ~LvBtn() override;
};

} /* namespace lvglpp */

#endif /* LVBTN_H_ */
