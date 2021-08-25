/*
 ******************************************************************************
 * @file    os_linux.h
 * @author  fstuff
 * @date
 * @brief
 ******************************************************************************
 */

#ifdef __linux__

#ifndef OS_FREERTOS_H_
#define OS_FREERTOS_H_

#ifdef __cplusplus
extern "C" {
#endif 
/* Includes ------------------------------------------------------------------*/

/* Defines -------------------------------------------------------------------*/
#define portFrequency							1
#define portCPUFrequency						1
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
