/*
 * LvCalendar.h
 *
 */

#ifndef LVCALENDAR_H_
#define LVCALENDAR_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvCalendar: public LvObj {
public:
	LvCalendar();
	LvCalendar(LvObj* Parent);
	virtual ~LvCalendar() override;
};

} /* namespace lvglpp */

#endif /* LVCALENDAR_H_ */
