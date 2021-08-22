/*
 * LvTimeRoller.h
 *
 *  Created on: Aug 15, 2021
 *      Author: fstuffdev
 */

#ifndef LVTIMEROLLER_H_
#define LVTIMEROLLER_H_

#include "../../widgets/LvWidgets.h"

namespace lvglpp {

class LvTimeRoller: public LvObj {
public:

	LvPPointer<LvRoller> hour;
	LvPPointer<LvRoller> minutes;
	LvPPointer<LvRoller> seconds;

	LvTimeRoller();
	LvTimeRoller(LvObj* Parent);
	virtual ~LvTimeRoller();
};

} /* namespace lvglpp */

#endif /* LVTIMEROLLER_H_ */
