/*
 ******************************************************************************
 * @file    os_freertos.h
 * @author  fstuff
 * @date    Mar 11, 2020
 * @brief
 ******************************************************************************
 */

#ifdef CONFIG_OS_FREERTOS

#ifndef OS_FREERTOS_H_
#define OS_FREERTOS_H_

#ifdef __cplusplus
 extern "C" {
#endif 
/* Includes ------------------------------------------------------------------*/

#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>
#include <queue.h>
#include <timers.h>

/* Defines -------------------------------------------------------------------*/
#define portFrequency							configTICK_RATE_HZ
#define portCPUFrequency						configCPU_CLOCK_HZ
#define portThreadLoop(condition)				for(;;)
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */


#ifdef __cplusplus
}
#endif

#endif /* OS_FREERTOS_H_ */

#endif
