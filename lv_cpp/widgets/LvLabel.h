/*
 * LvLabel.h
 *
 */

#ifndef LVLABEL_H_
#define LVLABEL_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvLabel: public LvObj {
public:
	LvLabel();
	LvLabel(LvObj* Parent);
	virtual ~LvLabel() override;
	LvLabel& setText(const char *text);
	
	template <typename... ArgsT>
	LvLabel& setTextFmt(const char *fmt, ArgsT... args){
	lv_label_set_text_fmt(cObj.get(),fmt,args...);
	return *this;
};
	LvLabel& setTextStatic(const char *text);
	LvLabel& setLongMode(lv_label_long_mode_t long_mode);
	LvLabel& setRecolor(bool en);
	LvLabel& setTextSelStart(uint32_t index);
	LvLabel& setTextSelEnd(uint32_t index);
	char *getText() const noexcept ;
	lv_label_long_mode_t getLongMode() const noexcept ;
	bool getRecolor() const noexcept ;
	LvLabel& getLetterPos(uint32_t char_id, lv_point_t *pos);
	uint32_t getLetterOn(lv_point_t *pos_in) const noexcept ;
	bool isCharUnderPos(lv_point_t *pos);
	uint32_t getTextSelectionStart() const noexcept ;
	uint32_t getTextSelectionEnd() const noexcept ;
	LvLabel& insText(uint32_t pos, const char *txt);
	LvLabel& cutText(uint32_t pos, uint32_t cnt);
};

} /* namespace lvglpp */

#endif /* LVLABEL_H_ */
