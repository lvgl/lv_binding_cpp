/*
 ******************************************************************************
 * @file    os_freertos.c
 * @author  fstuff
 * @date    Mar 11, 2020
 * @brief
 ******************************************************************************
 */

#ifdef __linux__
/* Includes ------------------------------------------------------------------*/
#include "os.h"
/* Private Variables----------------------------------------------------------*/
osStat_e kStat = osIdle;
/* Constants -----------------------------------------------------------------*/
/* Functions Declaration -----------------------------------------------------*/

/* Scheduler */

/* Critical Section Enter */
void osEnterCritical(void) {
}
/* Critical Section Exit */
void osExitCritical(void) {
}

/* Initialiaze The OS */
osRes_e osInit(void) {
	osRes_e _res = osOk;
	return _res;
}

/* Start the OS Scheduler */
osRes_e osStart(void) {
}

/* Get The status of the OS */
osStat_e osGetStat(void) {
}
/* Threading API */
osRes_e osThreadNew(osThreadInfo_t *tInfo) {
}

/* Get the current thread ID */
osThread osThreadGet(void) {

}

/* Get the thread handle from his Name */
osThread osThreadGetFromName(const char *tName) {
}

/* Delete the thread */
osRes_e osThreadDel(osThread tId) {
}

/* Wait a task for Milliseconds */
void osWait(os_uint32 ms) {
}

void osBlockingWait(os_uint32 cycle) {
	for (int i = 0; i < cycle; i++)
		asm("nop");
}

/* Wait a task for Milliseconds in a periodic manner */
void osPeriodicWait(os_uint32 ms, os_uint32 *LastWake) {
}

void osThreadSuspendAll(void) {
}

void osThreadResumeAll(void) {
}

/* Timers API */
osRes_e osTimerNew(osTimerInfo_t *tInfo) {
}

osRes_e osTimerStart(osTimerInfo_t *tInfo) {
}

osRes_e osTimerStop(osTimerInfo_t *tInfo) {
}

/* Semaphore API */
osSem osSemNew(os_uint count) {

}

osRes_e osSemTake(osSem smph, os_bool rec, os_uint32 msWait) {

}

osRes_e osSemRelease(osSem smph, os_bool rec) {

}

osRes_e osSemDel(osSem smph) {

}

/* Mutex API */
osMutex osMutexNew(void) {

}

osRes_e osMutexTake(osMutex mtx, os_bool rec, os_uint32 msWait) {

}

osRes_e osMutexRelease(osMutex mtx, os_bool rec) {

}

osRes_e osMutexDel(osMutex mtx) {

}

/* Queue API */
osQueue osQueueNew(os_uint32 qSize, os_uint32 eSize) {

}

osRes_e osQueuePush(osQueue que, os_uint32 msWait, void *qInElem) {

}

osRes_e osQueuePop(osQueue que, os_uint32 msWait, void *qOutElem) {

}

osRes_e osQueueDelete(osQueue que) {

}

os_uint32 osQueueSpace(osQueue que) {
}

os_bool osQueueIsFull(osQueue que) {

}

os_bool osQueueIsEmpty(osQueue que) {

}

osRes_e osQueuePeek(osQueue que, os_uint32 msWait, void *qOutElem) {

}

osRes_e osQueueOverwrite(osQueue que, os_uint32 msWait, void *qInElem) {

}

/* Memory API */
void* osMalloc(os_uint32 pSize) {
}

void osFree(void *size) {
}

os_uint32 osGetHeap(void) {

}

#endif
