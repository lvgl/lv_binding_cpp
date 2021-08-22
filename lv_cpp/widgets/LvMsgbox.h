/*
 * LvMsgbox.h
 *
 */

#ifndef LVMSGBOX_H_
#define LVMSGBOX_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvMsgbox: public LvObj {
public:
	LvMsgbox();
	LvMsgbox(LvObj* Parent);
	LvMsgbox(LvObj* Parent,const char * title, const char * txt, const char * btn_txts[], bool add_close_btn);
	virtual ~LvMsgbox() override;
};

} /* namespace lvglpp */

#endif /* LVMSGBOX_H_ */
