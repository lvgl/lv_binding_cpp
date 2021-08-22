/*
 * LvBtnmatrix.h
 *
 */

#ifndef LVBTNMATRIX_H_
#define LVBTNMATRIX_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvBtnmatrix: public LvObj {
public:
	LvBtnmatrix();
	LvBtnmatrix(LvObj* Parent);
	virtual ~LvBtnmatrix() override;
	LvBtnmatrix& setMap(const char *map[]);
	LvBtnmatrix& setCtrlMap(const lv_btnmatrix_ctrl_t ctrl_map[]);
	LvBtnmatrix& setSelectedBtn(uint16_t btn_id);
	LvBtnmatrix& setBtnCtrl(uint16_t btn_id, lv_btnmatrix_ctrl_t ctrl);
	LvBtnmatrix& clearBtnCtrl(uint16_t btn_id, lv_btnmatrix_ctrl_t ctrl);
	LvBtnmatrix& setBtnCtrlAll(lv_btnmatrix_ctrl_t ctrl);
	LvBtnmatrix& clearBtnCtrlAll(lv_btnmatrix_ctrl_t ctrl);
	LvBtnmatrix& setBtnWidth(uint16_t btn_id, uint8_t width);
	LvBtnmatrix& setOneChecked(bool en);
	const char **getMap() const noexcept ;
	uint16_t getSelectedBtn() const noexcept ;
	const char *getBtnText(uint16_t btn_id) const noexcept ;
	bool hasBtnCtrl(uint16_t btn_id, lv_btnmatrix_ctrl_t ctrl);
	bool getOneChecked() const noexcept ;
};

} /* namespace lvglpp */

#endif /* LVBTNMATRIX_H_ */
