/*
 * LvTick.h
 *
 *  Created on: May 17, 2021
 *      Author: fstuffdev
 */

#ifndef LVTICK_H_
#define LVTICK_H_


#include "lvglpp.h"
#include "LvThread.h"

namespace lvglpp {

class LvTick : public LvThread  {
private:
	unsigned int ms;
protected:
	void Body();
public:
	LvTick();
	LvTick(unsigned int _ms);
	virtual ~LvTick();
};

} /* namespace lvGL */

#endif /* LVTICK_H_ */
