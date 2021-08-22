/*
 * LvDropdown.h
 *
 */

#ifndef LVDROPDOWN_H_
#define LVDROPDOWN_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvDropdown: public LvObj {
public:
	LvDropdown();
	LvDropdown(LvObj* Parent);
	virtual ~LvDropdown() override;
	LvDropdown& setText(const char *txt);
	LvDropdown& setOptions(const char *options);
	LvDropdown& setOptionsStatic(const char *options);
	LvDropdown& addOption(const char *option, uint32_t pos);
	LvDropdown& clearOptions();
	LvDropdown& setSelected(uint16_t sel_opt);
	LvDropdown& setDir(lv_dir_t dir);
	LvDropdown& setSymbol(const void *symbol);
	LvDropdown& setSelectedHighlight(bool en);
	lv_obj_t *getList() const noexcept ;
	const char *getText() const noexcept ;
	const char *getOptions() const noexcept ;
	uint16_t getSelected() const noexcept ;
	uint16_t getOptionCnt() const noexcept ;
	LvDropdown& getSelectedStr(char *buf, uint32_t buf_size);
	const char *getSymbol() const noexcept ;
	bool getSelectedHighlight() const noexcept ;
	lv_dir_t getDir() const noexcept ;
	LvDropdown& close();
};

} /* namespace lvglpp */

#endif /* LVDROPDOWN_H_ */
