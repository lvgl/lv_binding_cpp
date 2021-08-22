/*
 * LvMsgbox.cpp
 *
 */

#include "LvMsgbox.h"

namespace lvglpp {

const char * btn_txts_def[] = {"OK"};

LvMsgbox::LvMsgbox() : LvMsgbox(NULL) {
}

LvMsgbox::LvMsgbox(LvObj* Parent) : LvMsgbox(Parent,"Message","Text",btn_txts_def,true)  {
}

LvMsgbox::LvMsgbox(LvObj* Parent,const char * title, const char * txt, const char * btn_txts[], bool add_close_btn) : LvObj(Parent) {

	if(Parent)
		cObj.reset(lv_msgbox_create(Parent->raw(),title, txt, btn_txts, add_close_btn));
	else
		cObj.reset(lv_msgbox_create(lv_scr_act(),title, txt, btn_txts, add_close_btn));

	setUserData(this);
}

LvMsgbox::~LvMsgbox() {
}

} /* namespace lvglpp */
