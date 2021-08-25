/*
 ******************************************************************************
 * @file    os_types.h
 * @author  fstuff
 * @date
 * @brief
 ******************************************************************************
 */

#ifndef OS_TYPE_H_
#define OS_TYPE_H_

#ifdef __cplusplus
extern "C" {
#endif 
/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
/* Defines -------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/

typedef int os_int;
typedef unsigned int os_uint;

typedef unsigned char os_byte;
typedef char os_char;
typedef bool os_bool;

typedef short os_short;
typedef unsigned short os_word;
typedef unsigned short os_wchar;

typedef long os_long;
typedef unsigned long os_dword;

typedef float os_float;
typedef double os_double;

typedef unsigned long long os_qdword;

typedef uint8_t os_uint8;
typedef uint16_t os_uint16;
typedef uint32_t os_uint32;

/* The thread Function */
typedef void (*osThread_func)(void const *arg);
/* The Timer Callback */
typedef void (*osTimer_cb)(void const *arg);

/* The structure should be declared in RTOS Specific implementation */
typedef struct thread_id *osThread;
typedef struct timer_id *osTimer;
typedef struct smph_id *osSem;
typedef struct mutex_id *osMutex;
typedef struct queue_id *osQueue;

// typedef void*				osThread;
// typedef void*				osTimer;
// typedef void*				osSem;
// typedef osSem				osMutex;
// typedef void*				osQueue;

/* Result of the OS Call*/
typedef enum {

	osOk = 0x01, osNok = 0x00,

} osRes_e;

/* Status of the OS */
typedef enum {

	osIdle = 0xa1, osRunning = 0xa3, osLocked = 0xa4, osError = 0,

} osStat_e;
extern osStat_e kStat;

/* Priority definition */
typedef enum {

	osPriIdle = -3,
	osPriLow = -2,
	osPriBelowNormal = -1,
	osPriNormal = 0,
	osPriAboveNormal = +1,
	osPriHigh = +2,
	osPriRealtime = +3,
	osPriError = 0xff

} osPriority_e;

/* Struct that contains information of the Thread */
typedef struct {

	const char *tName;
	osPriority_e tPri;
	os_uint32 tStack;
	osThread_func tFunc;
	const void *tParam;
	osThread tId;

} osThreadInfo_t;

/* Enum for define the tipe of the timer */
typedef enum {

	osTimerSingleShot = 0x00, osTimerPeriodic = 0x01,

} osTimerType_e;

/* Timer Info */
typedef struct {

	const char *tName;
	osTimerType_e tType;
	os_uint32 tPerMs;
	osTimer_cb *tFunc;
	osTimer tId;
	const void *tParam;

} osTimerInfo_t;

/* osInfo */
typedef struct {
	const char *kVersion;
	char *TaskList;
	char *RuntimeStats;
} osInfo_t;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif /* OS_TYPE_H_ */
