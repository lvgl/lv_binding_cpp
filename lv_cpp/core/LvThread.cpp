/*
 * LvThread.cpp
 *
 *  Created on: Dec 16, 2019
 *      Author: fstuff
 */

#ifdef __linux__
#include "LvThread.h"

namespace lvglpp {

static list<LvThread*> ThreadList;

LvThread::LvThread() {
	stop_thread.store(false);
	pause_thread.store(false);
}

LvThread::~LvThread() {
	Kill();
}

void LvThread::Go() {

	Kill();

	stop_thread.store(false);
	pause_thread.store(false);
	the_thread_p.reset(new std::thread(&LvThread::Run, this));

	void(0);

}

void LvThread::Kill() {
	if (isRunning()) {
		stop_thread.store(true);
		Jo();
	}
}

void LvThread::Pause() {
	pause_thread.store(true);
}

void LvThread::Resume() {
	pause_thread.store(false);
}

void LvThread::Run() {

	if (Init() == 0) {
		bool nstop = !stop_thread.load();
		bool npa = !stop_thread.load();

		for (; nstop;) {

			/* Get stop or pause */
			nstop = !stop_thread.load();
			npa = !pause_thread.load();

			if (npa)
				Body();
		}
		Exit();
	}
}

int LvThread::Init() {
	return 0;
}

void LvThread::Exit() {

}

void LvThread::Body() {

}

bool LvThread::isRunning() {
	return !stop_thread.load();
}

void LvThread::Jo() {
	if (the_thread_p && the_thread_p->joinable())
		the_thread_p->join();
}

}

#endif
