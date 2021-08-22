/*
 * LvThreads.h
 *
 *  Created on: Dec 16, 2019
 *      Author: fstuff
 */


#ifdef __linux__
#ifndef LVTHREADS_H_
#define LVTHREADS_H_

#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>
#include <list>
#include <memory>

using namespace std;

#include "lvglpp.h"

namespace lvglpp {

class LvThread {

protected:

    std::unique_ptr<std::thread> the_thread_p;
    std::atomic_bool stop_thread;
    std::atomic_bool pause_thread;

    /* Thread Core */
    virtual int Init();
    virtual void Body();
    virtual void Exit();

public:

    LvThread();
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
#endif
