/*
 * LvThreads.h
 *
 *      Author: fstuff
 */

#ifndef LVTHREADS_H_
#define LVTHREADS_H_

#if defined(_GLIBCXX_HAS_GTHREADS)

#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>
#include <list>
#include <memory>

#else
#include "os/os.h"
#endif

#include "lvglpp.h"

namespace lvglpp {

class LvThread {

protected:

#if !defined(_GLIBCXX_HAS_GTHREADS)
	osThreadInfo_t tInfo;
	os_bool stop_thread;
    os_bool pause_thread;
#else
    std::unique_ptr<std::thread> the_thread_p;
    std::atomic_bool stop_thread;
    std::atomic_bool pause_thread;
#endif

    /* Thread Core */
    virtual int Init();
    virtual void Body();
    virtual void Exit();

public:

    LvThread();
#if !defined(_GLIBCXX_HAS_GTHREADS)
    LvThread(const char* name);
    LvThread(const char *name, os_uint32 stackDepth, osPriority_e priority);
#endif
    virtual ~LvThread();

    void Go();
    void Pause();
    void Resume();
    void Jo();
    void Kill();
    void Run();
    bool isRunning();

};

}

#endif /* LVTHREADS_H_ */

