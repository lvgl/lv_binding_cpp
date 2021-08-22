/*
 * LvApp.h
 *
 *  Created on: Sep 28, 2020
 *      Author: fstuffdev
 */

#ifndef LVAPP_H_
#define LVAPP_H_

#include "lvglpp.h"

#include "LvThread.h"
#include "LvTick.h"
#include "LvScr.h"
#include "LvDisplay.h"
#include "LvIndev.h"
#include "LvEvent.h"

namespace lvglpp {

class LvApp: public LvThread {
private:
	/* Milliseconds of running application thread */
	unsigned int ms;

	/* Thread */
	int Init() final;
	void Body() final;
	void Exit() final;

protected:
	/* Basic lvglpp object */
	LvPPointer<LvTick> Tick;
	LvPPointer<LvDisplay> Disp;
	LvPPointer<LvInput> Io;

public:
	LvApp();
	LvApp(unsigned int frqHz);

	/* Implemented in Application */
	virtual int AppInit();
	virtual void AppBody();
	virtual void AppExit();

	virtual ~LvApp();
};

} /* namespace lvGL */

#endif /* LVAPP_H_ */
