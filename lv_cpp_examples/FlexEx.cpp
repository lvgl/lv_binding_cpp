/*
 * FlexEx.cpp
 *
 *  Created on: Aug 30, 2021
 *      Author: fstuffdev
 */

#include "FlexEx.h"
using namespace lvglpp;

namespace FlexEx {

/* Create Function */
void Create() {


	LvBtn* btnPointer = nullptr;
	LvLabel* labelPointer = nullptr;

	/* Main container */
	LvObj* mainCont = new LvObj();
	mainCont->setSize(470, 310).
			align(LV_ALIGN_CENTER, 0, 0).
			setFlexFlow(LV_FLEX_FLOW_COLUMN).
			setFlexAlign(LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

	/* Button Container */
	LvObj* containerRow = new LvObj(mainCont);
	containerRow->
			align(LV_ALIGN_CENTER, 0, 0).
			setWidth(310).
			setScrollbarMode(LV_SCROLLBAR_MODE_OFF).
			setFlexFlow(LV_FLEX_FLOW_ROW).
			setFlexAlign(LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

	/* Button Container */
	LvObj* containerCol = new LvObj(mainCont);
	containerCol->
			align(LV_ALIGN_CENTER, 0, 0).
			setWidth(310).
			setScrollbarMode(LV_SCROLLBAR_MODE_OFF).
			setFlexFlow(LV_FLEX_FLOW_COLUMN).
			setFlexAlign(LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

	/* Generating Button */
	for(int i = 0;i<5;i++) {
		btnPointer = new LvBtn(containerRow);

		labelPointer = new LvLabel(btnPointer);
		labelPointer->align(LV_ALIGN_CENTER, 0, 0);
		labelPointer->setTextFmt("Button: %d", i);

		btnPointer->setHeight(40);
	}


	/* Generating Button */
	for(int i = 0;i<5;i++) {
		btnPointer = new LvBtn(containerCol);

		labelPointer = new LvLabel(btnPointer);
		labelPointer->align(LV_ALIGN_CENTER, 0, 0);
		labelPointer->setTextFmt("Button:%d", i);

		btnPointer->setHeight(40);

	}

	printf("Application created !!!\n");

}

}
