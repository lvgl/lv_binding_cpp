/*
 * example.hpp
 *
 *  Created on: Aug 6, 2021
 *      Author: fstuffdev
 */

#ifndef EXAMPLE_HPP_
#define EXAMPLE_HPP_



#if defined(CONFIG_EXAMPLE_HELLO)
#include "HelloEx.h"
#elif defined(CONFIG_EXAMPLE_EVENT)
#include "EventEx.h"
#elif defined(CONFIG_EXAMPLE_CUSTOMWIDGETS)
#include "CustomWidgetsEx.h"
#elif defined(CONFIG_EXAMPLES)
#endif




#endif /* EXAMPLE_HPP_ */
