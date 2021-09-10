/*
 * lvglpp.h
 *
 *  Created on: Jun 24, 2021
 *      Author: fstuffdev
 */

#ifndef LVGLPP_H_
#define LVGLPP_H_

#include "../../lvgl/lvgl.h"

#include <memory>
#include <functional>
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
using LvPointerUnique = std::unique_ptr<ManagedType>;

/* Declaring Events using smart pointers */
template <typename Class>
using LvEventPointer = LvPointerUnique<LvEventCb<Class>>;

/* Variadic class contructor */
template <typename Class,typename... ArgsT>
std::unique_ptr<Class> Make(ArgsT... args){
	return std::make_unique<Class>(args...);
};

/* lvgl iterface functions */
/* Initilize the lvglpp library */
void Init();
void Handler(unsigned int ms);
void DefaultPeripheral();

} /* namespace lvglpp */

#endif /* LVGLPP_H_ */
