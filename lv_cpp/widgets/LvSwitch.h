/*
 * LvSwitch.h
 *
 */

#ifndef LVSWITCH_H_
#define LVSWITCH_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvSwitch: public LvObj {
public:
	LvSwitch();
	LvSwitch(LvObj* Parent);
	virtual ~LvSwitch() override;
};

} /* namespace lvglpp */

#endif /* LVSWITCH_H_ */
