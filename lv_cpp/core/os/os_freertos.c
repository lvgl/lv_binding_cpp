/*
 ******************************************************************************
 * @file    os_freertos.c
 * @author  fstuff
 * @date    Mar 11, 2020
 * @brief
 ******************************************************************************
 */

#ifdef CONFIG_OS_FREERTOS
/* Includes ------------------------------------------------------------------*/
#include "os.h"
/* Private Variables----------------------------------------------------------*/
osStat_e kStat = osIdle;
/* Constants -----------------------------------------------------------------*/
/* Functions Declaration -----------------------------------------------------*/

/* Scheduler */

/* Critical Section Enter */
void osEnterCritical(void) {
	if (osInISR() == osNok)
		taskENTER_CRITICAL();
}
/* Critical Section Exit */
void osExitCritical(void) {
	if (osInISR() == osNok)
		taskEXIT_CRITICAL();
}

/* Initialiaze The OS */
osRes_e osInit(void) {

	osStat_e _kStat = osGetStat();
	osRes_e _res = osNok;

	if (_kStat == osIdle) {
		_res = osTickConfig();

	}

	return _res;
}

/* Start the OS Scheduler */
osRes_e osStart(void) {
	osStat_e _kStat = osGetStat();
	osRes_e _res = osNok;

	if (_kStat == osIdle && osInISR() == osNok) {
		_res = osInit();
		if (_res == osOk)
			vTaskStartScheduler();
	}

	return _res;
}

/* Get The status of the OS */
osStat_e osGetStat(void) {

	BaseType_t _kState = xTaskGetSchedulerState();

	switch (_kState) {
	case taskSCHEDULER_RUNNING:
		kStat = osRunning;
		break;

	case taskSCHEDULER_SUSPENDED:
		kStat = osLocked;
		break;

	case taskSCHEDULER_NOT_STARTED:
		kStat = osIdle;
		break;

	default:
		kStat = osError;
		break;
	}

	return kStat;
}


/* Convert priority from freeRTOS to OS Priority */
UBaseType_t osConvertPriority(osPriority_e ospri) {

	UBaseType_t _pri = 0;
	os_uint32 _rtosPriHalf = 0;

	if (configMAX_PRIORITIES >= 6 && ospri != osPriError) {
		if ((configMAX_PRIORITIES % 2) == 0)
			_rtosPriHalf = configMAX_PRIORITIES / 2;
		else
			_rtosPriHalf = (configMAX_PRIORITIES / 2) + 1;

		_pri = (osPriority_e) ((int) _rtosPriHalf + (int) ospri);
	}

	return _pri;
}
/* Threading API */
osRes_e osThreadNew(osThreadInfo_t *tInfo) {

	osStat_e _kStat = osGetStat();
	osRes_e _res = osNok;
	BaseType_t _restos = pdFAIL;
	UBaseType_t _prirtos = 0;
	TaskHandle_t tHandle = NULL;

	tInfo->tId = NULL;

	if (osInISR() == osNok && (tInfo->tFunc != NULL)) {

		if (_kStat == osRunning || _kStat == osIdle) {

			_prirtos = osConvertPriority(tInfo->tPri);
			_restos = xTaskCreate(tInfo->tFunc, tInfo->tName, tInfo->tStack,
					tInfo->tParam, _prirtos, &tHandle);

			if (_restos == pdPASS) {
				tInfo->tId = (osThread) tHandle;
				_res = osOk;
			}
		}
	}

	return _res;
}

/* Get the current thread ID */
osThread osThreadGet(void) {
	osRes_e _isr = osInISR();
	if (_isr != osOk)
		return (osThread) xTaskGetCurrentTaskHandle();

	return NULL;
}

/* Get the thread handle from his Name */
osThread osThreadGetFromName(const char *tName) {

	osRes_e _isr = osInISR();
	if (_isr != osOk)
		return (osThread) xTaskGetHandle(tName);

	return NULL;
}

/* Delete the thread */
osRes_e osThreadDel(osThread tId) {

	osStat_e _kStat = osGetStat();
	osRes_e _res = osNok;

	if (_kStat == osRunning || _kStat == osIdle) {
		vTaskDelete((TaskHandle_t) tId);
	}

	return _res;
}

/* Wait a task for Milliseconds */
void osWait(os_uint32 ms) {

	TickType_t TicksToWait = ms / portTICK_PERIOD_MS;
	vTaskDelay(TicksToWait ? TicksToWait : 1);

	return;
}

void osBlockingWait ( os_uint32 cycle ) {
	for(int i = 0;i<cycle;i++)
		asm("nop");
}

/* Wait a task for Milliseconds in a periodic manner */
void osPeriodicWait(os_uint32 ms, os_uint32 *LastWake) {

	TickType_t TicksToWait = ms / portTICK_PERIOD_MS;
	if (*LastWake == 0)
		*LastWake = (os_uint32) xTaskGetTickCount();

	vTaskDelayUntil((TickType_t*) LastWake, TicksToWait ? TicksToWait : 1);
}

void osThreadSuspendAll(void) {
	if (osInISR() == osNok)
		vTaskSuspendAll();
}

void osThreadResumeAll(void) {
	if (osInISR() == osNok)
		xTaskResumeAll();
}

/* Timers API */
osRes_e osTimerNew(osTimerInfo_t *tInfo) {

	TickType_t TicksToWait = tInfo->tPerMs / portTICK_PERIOD_MS;
	UBaseType_t _autoreload = pdFALSE;

	if (tInfo->tType == osTimerPeriodic)
		_autoreload = pdTRUE;

	tInfo->tId = (osTimer) xTimerCreate(tInfo->tName, TicksToWait, _autoreload,
			tInfo->tParam, tInfo->tFunc);

	if (!tInfo)
		return osNok;

	return osOk;

}

osRes_e osTimerStart(osTimerInfo_t *tInfo) {

	osRes_e _isr = osInISR();
	BaseType_t _restos = pdFAIL;
	BaseType_t taskWoken = pdFALSE;
	TickType_t TicksToWait = tInfo->tPerMs / portTICK_PERIOD_MS;

	if (tInfo->tId == NULL)
		return osNok;

	if (_isr != osOk) {
		_restos = xTimerStart((TimerHandle_t )tInfo->tId, TicksToWait);
	} else {
		_restos = xTimerStartFromISR((TimerHandle_t )tInfo->tId, &taskWoken);
	}

	if (_restos == pdPASS)
		return osOk;

	return osNok;

}

osRes_e osTimerStop(osTimerInfo_t *tInfo) {

	osRes_e _isr = osInISR();
	BaseType_t _restos = pdFAIL;
	BaseType_t taskWoken = pdFALSE;
	TickType_t TicksToWait = tInfo->tPerMs / portTICK_PERIOD_MS;

	if (tInfo->tId == NULL)
		return osNok;

	if (_isr != osOk) {
		_restos = xTimerStop((TimerHandle_t )tInfo->tId, TicksToWait);
	} else {
		_restos = xTimerStopFromISR((TimerHandle_t )tInfo->tId, &taskWoken);
	}

	if (_restos == pdPASS)
		return osOk;

	return osNok;
}

/* Semaphore API */
osSem osSemNew(os_uint count) {

	osRes_e _isr = osInISR();

	if (_isr != osOk) {

		if (count > 1)
			return (osSem) xSemaphoreCreateBinary();
		else
			return (osSem) xSemaphoreCreateCounting(count, 0);
	}

	return NULL;

}

osRes_e osSemTake(osSem smph, os_bool rec, os_uint32 msWait) {

	osRes_e _isr = osInISR();
	BaseType_t _restos = pdFAIL;
	TickType_t TicksToWait = msWait / portTICK_PERIOD_MS;
	BaseType_t taskWoken = pdFALSE;

	if (_isr != osOk) {
		if (rec)
			_restos = xSemaphoreTakeRecursive((SemaphoreHandle_t )smph,
					TicksToWait);
		else
			_restos = xSemaphoreTake((SemaphoreHandle_t )smph, TicksToWait);
	} else {

		if (!rec)
			_restos = xSemaphoreTakeFromISR((SemaphoreHandle_t )smph,
					&taskWoken);
	}

	if (_restos == pdPASS)
		return osOk;

	return osNok;

}

osRes_e osSemRelease(osSem smph, os_bool rec) {

	osRes_e _isr = osInISR();
	BaseType_t _restos = pdFAIL;
	BaseType_t taskWoken = pdFALSE;

	if (_isr != osOk) {
		if (rec)
			_restos = xSemaphoreGiveRecursive((SemaphoreHandle_t )smph);
		else
			_restos = xSemaphoreGive((SemaphoreHandle_t )smph);
	} else {

		if (!rec)
			_restos = xSemaphoreGiveFromISR((SemaphoreHandle_t )smph,
					&taskWoken);
	}

	if (_restos == pdPASS)
		return osOk;

	return osNok;
}

osRes_e osSemDel(osSem smph) {

	if (smph)
		vSemaphoreDelete((SemaphoreHandle_t )smph);

	return osOk;
}

/* Mutex API */
osMutex osMutexNew(void) {

	osRes_e _isr = osInISR();
	if (_isr != osOk)
		return (osMutex) xSemaphoreCreateMutex();

	return NULL;
}

osRes_e osMutexTake(osMutex mtx, os_bool rec, os_uint32 msWait) {
	return osSemTake((osSem) mtx, rec, msWait);
}

osRes_e osMutexRelease(osMutex mtx, os_bool rec) {
	return osSemRelease((osSem) mtx, rec);
}

osRes_e osMutexDel(osMutex mtx) {
	return osSemDel((osSem) mtx);
}

/* Queue API */
osQueue osQueueNew(os_uint32 qSize, os_uint32 eSize) {

	osRes_e _isr = osInISR();
	if (_isr != osOk)
		return (osQueue) xQueueCreate(qSize, eSize);

	return NULL;
}

osRes_e osQueuePush(osQueue que, os_uint32 msWait, void *qInElem) {

	BaseType_t lastWoken = pdFALSE;
	BaseType_t _restos = pdFAIL;
	TickType_t TicksToWait = msWait / portTICK_PERIOD_MS;
	osRes_e _isr = osInISR();


	if (_isr == osOk)
		_restos = xQueueSendFromISR((QueueHandle_t )que, qInElem, &lastWoken);
	else
		_restos = xQueueSend((QueueHandle_t )que, qInElem, TicksToWait);

	if (_restos == pdPASS)
		return osOk;

	return osNok;
}

osRes_e osQueuePop(osQueue que, os_uint32 msWait, void *qOutElem) {

	BaseType_t lastWoken = pdFALSE;
	BaseType_t _restos = pdFAIL;
	TickType_t TicksToWait = msWait / portTICK_PERIOD_MS;
	osRes_e _isr = osInISR();

	if (_isr == osOk)
		_restos = xQueueReceiveFromISR((QueueHandle_t) que, qOutElem,&lastWoken);
	else
		_restos = xQueueReceive((QueueHandle_t) que, qOutElem, TicksToWait);

	if (_restos == pdPASS)
		return osOk;

	return osNok;

}

osRes_e osQueueDelete(osQueue que) {

	osRes_e _isr = osInISR();
	if (!_isr) {
		vQueueDelete((QueueHandle_t) que);
		return osOk;
	}

	return osNok;
}

os_uint32 osQueueSpace(osQueue que) {
	return (os_uint32) uxQueueSpacesAvailable((QueueHandle_t) que);
}

os_bool osQueueIsFull(osQueue que) {

	osRes_e _isr = osInISR();
	if (_isr) {
		if (xQueueIsQueueFullFromISR((QueueHandle_t) que) == pdTRUE)
			return true;
	} else {
		if (uxQueueSpacesAvailable((QueueHandle_t) que) == 0)
			return true;
	}

	return false;
}

os_bool osQueueIsEmpty(osQueue que) {

	osRes_e _isr = osInISR();
	if (_isr) {
		if (xQueueIsQueueEmptyFromISR((QueueHandle_t) que) == pdTRUE)
			return true;
	} else {
		if (uxQueueMessagesWaiting((QueueHandle_t) que) == 0)
			return true;
	}

	return false;
}

osRes_e osQueuePeek(osQueue que, os_uint32 msWait, void *qOutElem) {

	BaseType_t _restos = pdFAIL;
	TickType_t TicksToWait = msWait / portTICK_PERIOD_MS;
	osRes_e _isr = osInISR();

	if (_isr)
		_restos = xQueuePeekFromISR((QueueHandle_t) que, qOutElem);
	else
		_restos = xQueuePeek((QueueHandle_t) que, qOutElem, TicksToWait);

	if (_restos == pdPASS)
		return osOk;

	return osNok;
}

osRes_e osQueueOverwrite(osQueue que, os_uint32 msWait, void *qInElem) {

	BaseType_t lastWoken = pdFALSE;
	BaseType_t _restos = pdFAIL;
	osRes_e _isr = osInISR();

	if (_isr)
		_restos = xQueueOverwriteFromISR((QueueHandle_t )que, qInElem,
				&lastWoken);
	else
		_restos = xQueueOverwrite((QueueHandle_t )que, qInElem);

	if (_restos == pdPASS)
		return osOk;

	return osNok;
}

/* Memory API */
void* osMalloc(os_uint32 pSize) {
	return pvPortMalloc(pSize);
}

void osFree(void *size) {
	vPortFree(size);
}

os_uint32 osGetHeap(void) {
	return xPortGetFreeHeapSize();
}

#endif
