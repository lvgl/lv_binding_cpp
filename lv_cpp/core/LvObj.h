/*
 * LvObj.h
 *
 *  Created on:
 *      Author: fstuffdev
 */

#ifndef LVOBJ_H_
#define LVOBJ_H_

#include <list>
#include "lvglpp.h"
#include "LvEvent.h"
#include "../misc/LvStyle.h"


namespace lvglpp {

class LvObj {
protected:
	LvPointer<lv_obj_t, lv_obj_del> cObj;
public:

	/* Creation and deletion */
	LvObj();
	LvObj(LvObj *Parent);
	virtual ~LvObj();

	lv_obj_t* raw();
	LvObj& setCObj(lv_obj_t* _cObj);
	LvObj& setUserData(void *user_data);
	void *getUserData() const noexcept ;
	lv_coord_t dpx(lv_coord_t n);
	LvObj& del();
	LvObj& clean();
	LvObj& delAsync();
	LvObj& setParent(LvObj *parent);
	LvObj& moveForeground();
	LvObj& moveBackground();
	lv_obj_t *getScreen() const noexcept ;
	lv_disp_t *getDisp() const noexcept ;
	lv_obj_t *getParent() const noexcept ;
	lv_obj_t *getChild(int32_t id) const noexcept ;
	uint32_t getChildCnt() const noexcept ;
	uint32_t getChildId() const noexcept ;
	lv_flex_flow_t getStyleFlexFlow(uint32_t part) const noexcept ;
	lv_flex_align_t getStyleFlexMainPlace(uint32_t part) const noexcept ;
	lv_flex_align_t getStyleFlexCrossPlace(uint32_t part) const noexcept ;
	lv_flex_align_t getStyleFlexTrackPlace(uint32_t part) const noexcept ;
	uint8_t getStyleFlexGrow(uint32_t part) const noexcept ;
	const lv_coord_t *getStyleGridRowDscArray(uint32_t part) const noexcept ;
	const lv_coord_t *getStyleGridColumnDscArray(uint32_t part) const noexcept ;
	lv_grid_align_t getStyleGridRowAlign(uint32_t part) const noexcept ;
	lv_grid_align_t getStyleGridColumnAlign(uint32_t part) const noexcept ;
	lv_coord_t getStyleGridCellColumnPos(uint32_t part) const noexcept ;
	lv_coord_t getStyleGridCellColumnSpan(uint32_t part) const noexcept ;
	lv_coord_t getStyleGridCellRowPos(uint32_t part) const noexcept ;
	lv_coord_t getStyleGridCellRowSpan(uint32_t part) const noexcept ;
	lv_coord_t getStyleGridCellXAlign(uint32_t part) const noexcept ;
	lv_coord_t getStyleGridCellYAlign(uint32_t part) const noexcept ;
	struct _lv_event_dsc_t *addEventCb(lv_event_cb_t event_cb, lv_event_code_t filter, void *user_data);
	bool removeEventCb(lv_event_cb_t event_cb);
	bool removeEventDsc(struct _lv_event_dsc_t *event_dsc);
	LvObj& classInitObj();
	LvObj& destruct();
	bool isEditable();
	bool isGroupDef();
	LvObj& addFlag(lv_obj_flag_t f);
	LvObj& clearFlag(lv_obj_flag_t f);
	LvObj& addState(lv_state_t state);
	LvObj& clearState(lv_state_t state);
	bool hasFlag(lv_obj_flag_t f);
	bool hasFlagAny(lv_obj_flag_t f);
	lv_state_t getState() const noexcept ;
	bool hasState(lv_state_t state);
	void *getGroup() const noexcept ;
	LvObj& allocateSpecAttr();
	bool checkType(const lv_obj_class_t *class_p);
	bool hasClass(const lv_obj_class_t *class_p);
	const lv_obj_class_t *getClass() const noexcept ;
	bool isValid();
	LvObj& setScrollbarMode(lv_scrollbar_mode_t mode);
	LvObj& setScrollDir(lv_dir_t dir);
	LvObj& setScrollSnapX(lv_scroll_snap_t align);
	LvObj& setScrollSnapY(lv_scroll_snap_t align);
	lv_scrollbar_mode_t getScrollbarMode() const noexcept ;
	lv_dir_t getScrollDir() const noexcept ;
	lv_scroll_snap_t getScrollSnapX() const noexcept ;
	lv_scroll_snap_t getScrollSnapY() const noexcept ;
	lv_coord_t getScrollX() const noexcept ;
	lv_coord_t getScrollY() const noexcept ;
	lv_coord_t getScrollTop() const noexcept ;
	lv_coord_t getScrollBottom() const noexcept ;
	lv_coord_t getScrollLeft() const noexcept ;
	lv_coord_t getScrollRight() const noexcept ;
	LvObj& scrollBy(lv_coord_t x, lv_coord_t y, lv_anim_enable_t anim_en);
	LvObj& scrollTo(lv_coord_t x, lv_coord_t y, lv_anim_enable_t anim_en);
	LvObj& scrollToX(lv_coord_t x, lv_anim_enable_t anim_en);
	LvObj& scrollToY(lv_coord_t y, lv_anim_enable_t anim_en);
	LvObj& scrollToView(lv_anim_enable_t anim_en);
	LvObj& scrollToViewRecursive(lv_anim_enable_t anim_en);
	bool isScrolling();
	LvObj& updateSnap(lv_anim_enable_t anim_en);
	LvObj& getScrollbarArea(lv_area_t *hor_area, lv_area_t *ver_area);
	LvObj& scrollbarInvalidate();
	LvObj& readjustScroll(lv_anim_enable_t anim_en);
	lv_obj_t *lvIndevSearchObj(lv_point_t *point);
	LvObj& lvGroupRemoveObj();
	LvObj& lvGroupFocusObj();
	LvObj& setPos(lv_coord_t x, lv_coord_t y);
	LvObj& setX(lv_coord_t x);
	LvObj& setY(lv_coord_t y);
	bool refrSize();
	LvObj& setSize(lv_coord_t w, lv_coord_t h);
	LvObj& setWidth(lv_coord_t w);
	LvObj& setHeight(lv_coord_t h);
	LvObj& setContentWidth(lv_coord_t w);
	LvObj& setContentHeight(lv_coord_t h);
	LvObj& setLayout(uint32_t layout);
	bool isLayoutPositioned();
	LvObj& markLayoutAsDirty();
	LvObj& updateLayout();
	LvObj& setAlign(lv_align_t align);
	LvObj& align(lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs);
	LvObj& alignTo(const lv_obj_t *base, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs);
	LvObj& getCoords(lv_area_t *coords);
	lv_coord_t getX() const noexcept ;
	lv_coord_t getX2() const noexcept ;
	lv_coord_t getY() const noexcept ;
	lv_coord_t getY2() const noexcept ;
	lv_coord_t getWidth() const noexcept ;
	lv_coord_t getHeight() const noexcept ;
	lv_coord_t getContentWidth() const noexcept ;
	lv_coord_t getContentHeight() const noexcept ;
	LvObj& getContentCoords(lv_area_t *area);
	lv_coord_t getSelfWidth() const noexcept ;
	lv_coord_t getSelfHeight() const noexcept ;
	bool refreshSelfSize();
	LvObj& refrPos();
	LvObj& moveTo(lv_coord_t x, lv_coord_t y);
	LvObj& moveChildrenBy(lv_coord_t x_diff, lv_coord_t y_diff, bool ignore_floating);
	LvObj& invalidateArea(const lv_area_t *area);
	LvObj& invalidate();
	bool areaIsVisible(lv_area_t *area);
	bool isVisible();
	LvObj& setExtClickArea(lv_coord_t size);
	LvObj& getClickArea(lv_area_t *area);
	bool hitTest(const lv_point_t *point);
	LvObj& addStyle(LvStyle *style, lv_style_selector_t selector);
	LvObj& removeStyle(LvStyle *style, lv_style_selector_t selector);
	LvObj& refreshStyle(lv_style_selector_t selector, lv_style_prop_t prop);
	lv_style_value_t getStyleProp(lv_part_t part, lv_style_prop_t prop) const noexcept ;
	LvObj& setLocalStyleProp(lv_style_prop_t prop, lv_style_value_t value, lv_style_selector_t selector);
	lv_res_t getLocalStyleProp(lv_style_prop_t prop, lv_style_value_t *value, lv_style_selector_t selector) const noexcept ;
	bool removeLocalStyleProp(lv_style_prop_t prop, lv_style_selector_t selector);
	LvObj& styleCreateTransition(lv_part_t part, lv_state_t prev_state, lv_state_t new_state, const _lv_obj_style_transition_dsc_t *tr_dsc);
	_lv_style_state_cmp_t styleStateCompare(lv_state_t state1, lv_state_t state2);
	LvObj& fadeIn(uint32_t time, uint32_t delay);
	LvObj& fadeOut(uint32_t time, uint32_t delay);
	LvObj& initDrawRectDsc(uint32_t part, lv_draw_rect_dsc_t *draw_dsc);
	LvObj& initDrawLabelDsc(uint32_t part, lv_draw_label_dsc_t *draw_dsc);
	LvObj& initDrawImgDsc(uint32_t part, lv_draw_img_dsc_t *draw_dsc);
	LvObj& initDrawLineDsc(uint32_t part, lv_draw_line_dsc_t *draw_dsc);
	LvObj& initDrawArcDsc(uint32_t part, lv_draw_arc_dsc_t *draw_dsc);
	lv_coord_t calculateExtDrawSize(uint32_t part);
	LvObj& refreshExtDrawSize();
	lv_coord_t getExtDrawSize() const noexcept ;

	/* Cpp Event Management*/
	typedef struct {
		lv_event_code_t evCode;
		LvEvent* evCallback;
	}eventBind_t;

	/* List of registered events */
	std::list<eventBind_t> eventRegister;
	static void EventDispatcher(lv_event_t* e);
	LvObj& setCallback(lv_event_code_t code,LvEvent* Cb);

};

} /* namespace lvglpp */

#endif /* LVOBJ_H_ */
