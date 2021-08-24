/**
 * @file linmice.h
 *
 */

#ifndef LINMICE_H
#define LINMICE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#ifndef LV_DRV_NO_CONF
#ifdef LV_CONF_INCLUDE_SIMPLE
#include <lv_drv_conf.h>
#else
#include <lv_drv_conf.h>
#endif
#endif

#if USE_LINMICE

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the mouse
 */
void linmice_init(void);

/**
 * Get the current position and state of the mouse/touchpad
 * @param indev_drv pointer to the related input device driver
 * @param data store the mouse data here
 * @return false: because the points are not buffered, so no more data to be read
 */
void linmice_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);


/**********************
 *      MACROS
 **********************/

#endif /* USE_LINMICE */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* LINMICE_H */
