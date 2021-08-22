/*
 * LvApp.cpp
 *
 *  Created on: Sep 28, 2020
 *      Author: fstuffdev
 */

#include "LvApp.h"

namespace lvglpp {

/* Default contructor */
LvApp::LvApp() :
		LvApp(200) {
}

LvApp::LvApp(unsigned int frqHz) {
	/* Set milliseconds */
	ms = (((float) 1 / frqHz) * 1000);
}

/* Virtual destructor */
LvApp::~LvApp() {
}

/* Initialize The lvglpp Framework */
int LvApp::Init() {

	/* Initialize lvglpp */
	lvglpp::Init();

	/* LvTick Thread */
	Tick = Make<LvTick>();
	Tick->Go();

	/* Display Creation */
	Disp = Make<LvDisplay>();

	/* Input Creation */
	Io = Make<LvInput>();

	return AppInit();
}

/* Run the application body in thread */
void LvApp::Body() {

	LvSleep(ms);
	lv_timer_handler();

	AppBody();

}

/* Exit the Application */
void LvApp::Exit() {
	AppExit();
}

/* Dummy Application Init */
int LvApp::AppInit() {
	return 0;
}

/* Dummy Application Body */
void LvApp::AppBody() {

}

/* Dummy Application Exit */
void LvApp::AppExit() {

}

} /* namespace lvGL */
