/*
 * LvEvent.h
 *
 *  Created on: Jun 24, 2021
 *      Author: fstuffdev
 */

#ifndef LVEVENT_H_
#define LVEVENT_H_

#include "lvglpp.h"

namespace lvglpp {

/* Base Class */
class LvEvent {

public:
	virtual void operator()(lv_event_t * e)=0;
	virtual void Call(lv_event_t * e)=0;
};


/* Template class for callback */
template <class TCaller> class LvEventCb : public LvEvent {
private:
	void (TCaller::*fPointer)(lv_event_t * e);
	TCaller* fOwner;
public:

	/* Create a empty callback */
	LvEventCb () {
		fOwner = NULL;
		fPointer = NULL;
	}

	/* Creation of function pointers */
	LvEventCb ( void (TCaller::*_fPointer)(lv_event_t * e) ,TCaller* _fOwner ) {
		fOwner = _fOwner;
		fPointer = _fPointer;
	}

	/* Call using operator() */
	void operator() (lv_event_t * e) {
		(*fOwner.*fPointer)(e);
	}

	/* Call using Call */
	void Call(lv_event_t * e) {
		(*fOwner.*fPointer)(e);
	}

};

} /* namespace lvGL */

#endif /* LVCALLBACK_H_ */
