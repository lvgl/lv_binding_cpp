/*
 * examples.cpp
 *
 *  Created on: Jul 18, 2021
 *      Author: fstuffdev
 */

#if defined(CONFIG_EXAMPLES)

#include "examples.hpp"

using namespace lvglpp;

int main (int argc,char** argv) {

#if defined(CONFIG_EXAMPLE_HELLO)
	HelloEx App;
#elif defined(CONFIG_EXAMPLE_EVENT)
	EventEx App;
#elif defined(CONFIG_EXAMPLE_CUSTOMWIDGETS)
	CustomWidgetsEx App;
#endif

	/* Start the App */
	App.Go();
	/* Join the App Thread */
	App.Jo();

	return 0;

}


#endif


