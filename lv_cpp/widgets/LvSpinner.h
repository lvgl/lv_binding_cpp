/*
 * LvSpinner.h
 *
 */

#ifndef LVSPINNER_H_
#define LVSPINNER_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvSpinner: public LvObj {
public:
	LvSpinner();
	LvSpinner(LvObj* Parent);
	LvSpinner(LvObj* Parent,uint32_t time ,uint32_t arc_length);
	virtual ~LvSpinner() override;
};

} /* namespace lvglpp */

#endif /* LVSPINNER_H_ */
