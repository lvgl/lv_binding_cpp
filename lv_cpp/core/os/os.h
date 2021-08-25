/*
 ******************************************************************************
 * @file    os.h
 * @author  fstuff
 * @date
 * @brief
 ******************************************************************************
 */

#ifndef OS_H_
#define OS_H_

#ifdef __cplusplus
extern "C" {
#endif 
/* Includes ------------------------------------------------------------------*/

#include "os_types.h"

#if defined(CONFIG_OS_FREERTOS)
	#include "os_freertos.h"
#endif

#if defined(__linux__)
#include "os_linux.h"
#endif

/* Defines -------------------------------------------------------------------*/
#define osFrequency						portFrequency
#define osCPUFrequency					portCPUFrequency
#define osThreadLoop(condition)			portThreadLoop(condition)
#define osASSERT_NULL(ptr)				if(ptr)
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/* Scheduler */
extern osRes_e osTickConfig(void);
extern osRes_e osInISR(void);
void osEnterCritical(void);
void osExitCritical(void);
osRes_e osStart(void);
osStat_e osGetStat(void);
osInfo_t osGetInfoFormatted(void);

/* Threading API */
osRes_e osThreadNew(osThreadInfo_t *tInfo);
osThread osThreadGet(void);
osThread osThreadGetFromName(const char *tName);
osRes_e osThreadDel(osThread tId);
void osWait(os_uint32 ms);
void osBlockingWait(os_uint32 cycle);
void osPeriodicWait(os_uint32 ms, os_uint32 *LastWake);
void osThreadSuspendAll(void);
void osThreadResumeAll(void);

/* Timers API */
osRes_e osTimerNew(osTimerInfo_t *tInfo);
osRes_e osTimerStart(osTimerInfo_t *tInfo);
osRes_e osTimerStop(osTimerInfo_t *tInfo);

/* Semaphore API */
osSem osSemNew(os_uint count);
osRes_e osSemTake(osSem smph, os_bool rec, os_uint32 msWait);
osRes_e osSemRelease(osSem smph, os_bool rec);
osRes_e osSemDel(osSem smph);

/* Mutex API */
osMutex osMutexNew(void);
osRes_e osMutexTake(osMutex mtx, os_bool rec, os_uint32 msWait);
osRes_e osMutexRelease(osMutex mtx, os_bool rec);
osRes_e osMutexDel(osMutex mtx);

/* Queue API */
osQueue osQueueNew(os_uint32 qSize, os_uint32 eSize);
osRes_e osQueuePush(osQueue que, os_uint32 msWait, void *qInElem);
osRes_e osQueuePop(osQueue que, os_uint32 msWait, void *qOutElem);
osRes_e osQueueDelete(osQueue que);
os_uint32 osQueueSpace(osQueue que);
os_bool osQueueIsFull(osQueue que);
os_bool osQueueIsEmpty(osQueue que);
osRes_e osQueuePeek(osQueue que, os_uint32 msWait, void *qOutElem);
osRes_e osQueueOverwrite(osQueue que, os_uint32 msWait, void *qInElem);

/* Memory API */
void* osMalloc(os_uint32 pSize);
void osFree(void *p);
os_uint32 osGetHeap(void);

#ifdef __cplusplus
}
#endif

#endif /* OS_H_ */
