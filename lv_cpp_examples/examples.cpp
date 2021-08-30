/*
 * examples.cpp
 *
 *  Created on: Jul 18, 2021
 *      Author: fstuffdev
 */

#if defined(CONFIG_EXAMPLES)

#if defined(__linux__)
#include <unistd.h>
#endif

#include "examples.hpp"

using namespace lvglpp;

int main(int argc, char **argv) {

	unsigned int ms = 1;

	lvglpp::Init();
	lvglpp::DefaultPeripheral();

#if defined(CONFIG_EXAMPLE_HELLO)
	HelloEx::Create();
	ms = HelloEx::ms;
#endif

	while (1) {
		lvglpp::Handler(ms);
#if defined(__linux__)
		usleep(1000 * ms);
#endif
	}

}

#endif

