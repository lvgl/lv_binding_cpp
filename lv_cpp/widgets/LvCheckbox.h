/*
 * LvCheckbox.h
 *
 */

#ifndef LVCHECKBOX_H_
#define LVCHECKBOX_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvCheckbox: public LvObj {
public:
	LvCheckbox();
	LvCheckbox(LvObj* Parent);
	virtual ~LvCheckbox() override;
	LvCheckbox& setText(const char *txt);
	LvCheckbox& setTextStatic(const char *txt);
	const char *getText() const noexcept ;
};

} /* namespace lvglpp */

#endif /* LVCHECKBOX_H_ */
