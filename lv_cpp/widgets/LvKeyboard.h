/*
 * LvKeyboard.h
 *
 */

#ifndef LVKEYBOARD_H_
#define LVKEYBOARD_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvKeyboard: public LvObj {
public:
	LvKeyboard();
	LvKeyboard(LvObj* Parent);
	virtual ~LvKeyboard() override;
	LvKeyboard& setTextarea(lv_obj_t *ta);
	LvKeyboard& setMode(lv_keyboard_mode_t mode);
	LvKeyboard& setMap(lv_keyboard_mode_t mode, const char *map[], const lv_btnmatrix_ctrl_t ctrl_map[]);
	lv_obj_t *getTextarea() const noexcept ;
	lv_keyboard_mode_t getMode() const noexcept ;
};

} /* namespace lvglpp */

#endif /* LVKEYBOARD_H_ */
