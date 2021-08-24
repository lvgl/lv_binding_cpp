/*
 * lvglpp.h
 *
 *  Created on: Jun 24, 2021
 *      Author: fstuffdev
 */

#ifndef LVGLPP_H_
#define LVGLPP_H_

#ifdef __linux__
#include <unistd.h>
#endif

#include "../../lvgl/lvgl.h"

#include <memory>
#include <vector>
#include "LvEvent.h"


namespace lvglpp {

/* Template for custom deleter function */
template <auto DeleterFunction>
using CustomDeleter = std::integral_constant<decltype(DeleterFunction), DeleterFunction>;

/* Used for create a smart_pointer with custom deleter */
template <typename ManagedType, auto Functor>
using LvPointer = std::unique_ptr<ManagedType, CustomDeleter<Functor>>;

/* Used for create a smart_pointer with default deleter for cpp object */
template <typename ManagedType>
using LvPPointer = std::unique_ptr<ManagedType>;

/* Declaring Events using smart pointers */
template <typename Class>
using LvEventPointer = LvPPointer<LvEventCb<Class>>;

/* Variadic class contructor */
template <typename Class,typename... ArgsT>
std::unique_ptr<Class> Make(ArgsT... args){
	return std::make_unique<Class>(args...);
};

/* Sleep for milliseconds */
static void LvSleep(unsigned int ms) {
#ifdef __linux__
	usleep(ms * 1000);
#endif
}

/* Initilize the lvglpp library */
void Init();

} /* namespace lvglpp */

#endif /* LVGLPP_H_ */
