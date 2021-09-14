/*
 * HelloEx.cpp
 *
 *  Created on: Aug 30, 2021
 *      Author: fstuffdev
 */

#include "HelloEx.h"
using namespace lvglpp;

namespace HelloEx {

/* Widgets */
LvPointerUnique<LvBtn> btn;
LvPointerUnique<LvStyle> btnStyle;
LvPointerUnique<LvLabel> label;
LvPointerUnique<LvTimer> timer;
LvPointerUnique<LvAnim> zoomin;
LvPointerUnique<LvAnim> getout;
LvPointerUnique<LvAnimTimeline> timeline;


/* You can delare it as raw pointers */

// LvBtn* btn;
// LvStyle* btnStyle;
// LvLabel* label;
// LvTimer* timer;

/* Globals */
static int pressed = 0;

/* Callback for button pressed */
void ButtonPressedAdd(lv_event_t *e) {
	pressed++;
	label->setTextFmt("%d", pressed);
}

/* Callback for button pressed */
void ButtonPressedSub(lv_event_t *e) {
	if (pressed > 0)
		pressed--;
	label->setTextFmt("%d", pressed);
}


/* Callback for Timer pressed */
static void TimerCb(lv_timer_t *timer) {
	pressed++;
	label->setTextFmt("%d", pressed);
}



/* Callback for Animation pressed */
static void zoominCb(void * var, int32_t v) {
	LvBtn* _btn = static_cast<LvBtn*>(var);
	_btn->setSize( v, v * 0.5);
}

/* Callback for Animation pressed */
static void getoutCb(void * var, int32_t v) {
	LvBtn* _btn = static_cast<LvBtn*>(var);
	_btn->setX(v);
}


/* Create Function */
void Create() {


	/* Timer */
	timer = Make<LvTimer>(); 				// or timer = new LvTimer();
	timer->setPeriod(1000).
			setCb(TimerCb).
			ready();

	/* Button Style */
	btnStyle = Make<LvStyle>();  			// or btnStyle = new LvStyle();
	btnStyle->init();
	btnStyle->setBgColor(lv_palette_main(LV_PALETTE_RED)).
			setBgGradColor(lv_palette_lighten(LV_PALETTE_RED, 3));

	/* Button */
	btn = Make<LvBtn>();  					// or btn = new LvBtn();
	btn->addStyle(btnStyle.get(), 0);		// or btn->addStyle(btnStyle, 0);  if you are using raw pointers

	btn->addEventCb(ButtonPressedAdd, LV_EVENT_PRESSED, nullptr);
	btn->addEventCb(ButtonPressedSub, LV_EVENT_LONG_PRESSED_REPEAT, nullptr);


	/* Animation */
	zoomin = Make<LvAnim>();
	zoomin->
			setVar(btn.get()).
			setValues(0, 100).
			setTime(1000).
			setRepeatCount(1).
			setPathCb(lv_anim_path_ease_in_out).
			setExecCb(zoominCb);

	getout = Make<LvAnim>();
	getout->
			setVar(btn.get()).
			setValues(0, 500).
			setTime(1000).
			setRepeatCount(1).
			setPathCb(lv_anim_path_ease_in_out).
			setExecCb(getoutCb);

	/* Make a complex animation with timeline */
	timeline = Make<LvAnimTimeline>();
	timeline->add(0, zoomin.get()).
			add(1100,getout.get()).start();



	/* Label */
	label = Make<LvLabel>(btn.get()); 		// or label = new LvLabel(btn);
	label->setTextFmt("%d", pressed);

	/* Alignment */
	btn->align(LV_ALIGN_CENTER, 0, 0);
	label->align(LV_ALIGN_CENTER,0, 0);


	printf("Application created !!!\n");

}

}
