/*
 * LvThread.cpp
 *
 *      Author: fstuff
 */

#include "LvThread.h"

namespace lvglpp {

#if defined(_GLIBCXX_HAS_GTHREADS)

LvThread::LvThread() {
	stop_thread.store(false);
	pause_thread.store(false);
}

#else
extern "C" void pvTaskCode(void *pvParameters) {
    (static_cast<Thread*>(pvParameters))->Run();
}

LvThread::LvThread(const char *name) : Thread(name,256,osPriLow) {

}


LvThread::LvThread(const char *name, os_uint32 stackDepth, osPriority_e priority) {

	tInfo.tName = name;
	tInfo.tFunc = (osThread_func)pvTaskCode;
	tInfo.tPri = priority;
	tInfo.tStack = stackDepth;
	tInfo.tParam = (void*) this;

	pause_thread = false;
	stop_thread = false;

	osThreadNew(&tInfo);
}

#endif

LvThread::~LvThread() {
	Kill();
#if !defined(_GLIBCXX_HAS_GTHREADS)
	if(tInfo.tId)
		osThreadDel(tInfo.tId);
#endif
}

void LvThread::Go() {

	Kill();
#if defined(_GLIBCXX_HAS_GTHREADS)
	stop_thread.store(false);
	pause_thread.store(false);
	the_thread_p.reset(new std::thread(&LvThread::Run, this));
#else
	stop_thread = false;
	pause_thread = false;
#endif

	void(0);

}

void LvThread::Kill() {
	if (isRunning()) {
#ifdef defined(_GLIBCXX_HAS_GTHREADS)
		stop_thread.store(true);
#else
		stop_thread = true;
#endif
		Jo();
	}
}

void LvThread::Pause() {
#if defined(_GLIBCXX_HAS_GTHREADS)
	pause_thread.store(true);
#else
	pause_thread = true;
#endif
}

void LvThread::Resume() {
#if defined(_GLIBCXX_HAS_GTHREADS)
	pause_thread.store(false);
#else
	pause_thread = false;
#endif
}

void LvThread::Run() {

	if (Init() == 0) {

#if defined(_GLIBCXX_HAS_GTHREADS)
		bool nstop = !stop_thread.load();
		bool npa = !stop_thread.load();
#else
		bool nstop = !stop_thread;
		bool npa = !pause_thread;
#endif

		for (; nstop;) {

#if defined(_GLIBCXX_HAS_GTHREADS)
			/* Get stop or pause */
			nstop = !stop_thread.load();
			npa = !pause_thread.load();
#else
			nstop = !stop_thread;
			npa = !pause_thread;
#endif

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
#if defined(_GLIBCXX_HAS_GTHREADS)
	return !stop_thread.load();
#else
	return !stop_thread;
#endif
}

void LvThread::Jo() {
#if defined(_GLIBCXX_HAS_GTHREADS)
	if (the_thread_p && the_thread_p->joinable())
		the_thread_p->join();
#endif
}

}

