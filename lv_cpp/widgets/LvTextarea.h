/*
 * LvTextarea.h
 *
 */

#ifndef LVTEXTAREA_H_
#define LVTEXTAREA_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvTextarea: public LvObj {
public:
	LvTextarea();
	LvTextarea(LvObj* Parent);
	virtual ~LvTextarea() override;
	LvTextarea& addChar(uint32_t c);
	LvTextarea& addText(const char *txt);
	LvTextarea& delChar();
	LvTextarea& delCharForward();
	LvTextarea& setText(const char *txt);
	LvTextarea& setPlaceholderText(const char *txt);
	LvTextarea& setCursorPos(int32_t pos);
	LvTextarea& setCursorClickPos(bool en);
	LvTextarea& setPasswordMode(bool en);
	LvTextarea& setOneLine(bool en);
	LvTextarea& setAcceptedChars(const char *list);
	LvTextarea& setMaxLength(uint32_t num);
	LvTextarea& setInsertReplace(const char *txt);
	LvTextarea& setTextSelection(bool en);
	LvTextarea& setPasswordShowTime(uint16_t time);
	LvTextarea& setAlign(lv_text_align_t align);
	const char *getText() const noexcept ;
	const char *getPlaceholderText() const noexcept ;
	lv_obj_t *getLabel() const noexcept ;
	uint32_t getCursorPos() const noexcept ;
	bool getCursorClickPos() const noexcept ;
	bool getPasswordMode() const noexcept ;
	bool getOneLine() const noexcept ;
	const char *getAcceptedChars() const noexcept ;
	uint32_t getMaxLength() const noexcept ;
	bool textIsSelected();
	bool getTextSelection() const noexcept ;
	uint16_t getPasswordShowTime() const noexcept ;
	LvTextarea& clearSelection();
	LvTextarea& cursorRight();
	LvTextarea& cursorLeft();
	LvTextarea& cursorDown();
	LvTextarea& cursorUp();
};

} /* namespace lvglpp */

#endif /* LVTEXTAREA_H_ */
