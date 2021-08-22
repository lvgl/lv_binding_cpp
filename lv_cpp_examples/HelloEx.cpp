/*
 * HelloEx.cpp
 *
 *  Created on: Aug 6, 2021
 *      Author: fstuffdev
 */

#include "HelloEx.h"

using namespace std;

namespace lvglpp {

HelloEx::HelloEx() {
}

HelloEx::~HelloEx() {

}

/***************************************************** The Application ******************************************************/
int HelloEx::AppInit() {

	/* Enable Cursor */
	Io->enableCursor();

	/* Tabview */
	view = Make<LvTabview>();
	LvObj& firstTab = view->addTab("Controls");
	view->addTab("Yep");
	view->addTab("Wahooo");

	/* Button */
	HelloButton = Make<LvBtn>(&firstTab);
	HelloButton->setSize(200, 100).
			setX(0).
			align(LV_ALIGN_CENTER,0,0);

	/* Creating a new callback and register to the object */
	Hello = Make<LvEventCb<HelloEx>>(&HelloEx::Hello_cb,this);
	HelloLong = Make<LvEventCb<HelloEx>>(&HelloEx::HelloLong_cb,this);
	HelloButton->setCallback(LV_EVENT_PRESSED, Hello.get());
	HelloButton->setCallback(LV_EVENT_LONG_PRESSED, HelloLong.get());

	/* Button Label */
	HelloLabel = Make<LvLabel>(HelloButton.get());
	HelloLabel->setTextFmt("Hello %s", "fstuff-dev").
			align(LV_ALIGN_CENTER, 0,0);


	return 0;
}

void HelloEx::AppBody() {

}

void HelloEx::AppExit() {

}

/* Callbacks */
void HelloEx::Hello_cb(lv_event_t* e) {

	/* HelloLabel is part of the class so you're able to directly access it */
	HelloLabel->setText("Pressed");
	printf("Pressed Callback !!! \n");
}

/* Callbacks */
void HelloEx::HelloLong_cb(lv_event_t* e) {

	/* HelloLabel is part of the class so you're able to directly access it */
	HelloLabel->setText("LongPressed");
	printf("LongPressed Callback !!! \n");
}

} /* namespace lvglpp */
