/*
 * examples.cpp
 *
 *  Created on: Jul 18, 2021
 *      Author: fstuffdev
 */

#if defined(CONFIG_EXAMPLES)

#if defined(__linux__)
#include <thread>
#endif

#include "examples.hpp"

using namespace lvglpp;
using namespace std;

int main(int argc, char **argv) {

	unsigned int ms = 1;

	lvglpp::Init();
	lvglpp::DefaultPeripheral();

#if defined(CONFIG_EXAMPLE_HELLO)
	HelloEx::Create();
	ms = HelloEx::ms;
#endif

#if defined(CONFIG_EXAMPLE_FLEX)
	FlexEx::Create();
	ms = FlexEx::ms;
#endif

	while (1) {
		lvglpp::Handler(ms);
#if defined(__linux__)
		this_thread::sleep_for(chrono::milliseconds(ms));
#endif
	}

}

#endif

