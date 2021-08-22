/*
 * LvTable.h
 *
 */

#ifndef LVTABLE_H_
#define LVTABLE_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvTable: public LvObj {
public:
	LvTable();
	LvTable(LvObj* Parent);
	virtual ~LvTable() override;
	LvTable& setCellValue(uint16_t row, uint16_t col, const char *txt);
	
	template <typename... ArgsT>
	LvTable& setCellValueFmt(uint16_t row, uint16_t col, const char *fmt, ArgsT... args){
	lv_table_set_cell_value_fmt(cObj.get(),row,col,fmt,args...);
	return *this;
};
	LvTable& setRowCnt(uint16_t row_cnt);
	LvTable& setColCnt(uint16_t col_cnt);
	LvTable& setColWidth(uint16_t col_id, lv_coord_t w);
	LvTable& addCellCtrl(uint16_t row, uint16_t col, lv_table_cell_ctrl_t ctrl);
	LvTable& clearCellCtrl(uint16_t row, uint16_t col, lv_table_cell_ctrl_t ctrl);
	const char *getCellValue(uint16_t row, uint16_t col) const noexcept ;
	uint16_t getRowCnt() const noexcept ;
	uint16_t getColCnt() const noexcept ;
	lv_coord_t getColWidth(uint16_t col) const noexcept ;
	bool hasCellCtrl(uint16_t row, uint16_t col, lv_table_cell_ctrl_t ctrl);
	LvTable& getSelectedCell(uint16_t *row, uint16_t *col);
};

} /* namespace lvglpp */

#endif /* LVTABLE_H_ */
