/*
 * HelloEx.h
 *
 *  Created on: Aug 30, 2021
 *      Author: fstuffdev
 */

#ifndef HELLOEX_H_
#define HELLOEX_H_

#include "../lv_cpp/core/lvglpp.h"
#include "../lv_cpp/core/LvDisplay.h"
#include "../lv_cpp/core/LvIndev.h"
#include "../lv_cpp/core/LvScr.h"
#include "../lv_cpp/misc/LvStyle.h"
#include "../lv_cpp/misc/LvTimer.h"
#include "../lv_cpp/misc/LvAnim.h"
#include "../lv_cpp/misc/LvAnimTimeline.h"

#include "../lv_cpp/widgets/LvWidgets.h"

namespace HelloEx {

/* Milliseconds for application loop */
const unsigned int ms = 5;

/* Init the application */
void Create();

}


#endif /* HELLOEX_H_ */
