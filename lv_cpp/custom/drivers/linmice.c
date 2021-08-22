/**
 * @file linmice.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "linmice.h"
#if USE_LINMICE != 0

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#if __linux__
#include <linux/input.h>
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static bool left_button_down = false;
static int16_t last_x = 0;
static int16_t last_y = 0;
static int fd = -1;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Initialize the mouse
 */
void linmice_init(void) {
	const char *pDevice = "/dev/input/mice";

	// Open Mouse
	fd = open(pDevice, O_RDWR | O_NONBLOCK);
	if (fd == -1) {
		printf("ERROR Opening %s\n", pDevice);
	}
}

/**
 * Get the current position and state of the mouse
 * @param indev_drv pointer to the related input device driver
 * @param data store the mouse data here
 * @return false: because the points are not buffered, so no more data to be read
 */
void linmice_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data) {
	(void) indev_drv; /*Unused*/

	int left = 0, middle = 0, right = 0, bytes = 0;
	signed char x, y, aux;

	unsigned char dat[3];

	// Read Mouse
	bytes = read(fd, dat, sizeof(dat));

	if (bytes > 0) {
		left = dat[0] & 0x1;
		right = dat[0] & 0x2;
		middle = dat[0] & 0x4;

		x = dat[1];
		y = dat[2];

		if(right)
		{
			data->point.x = 0;
			data->point.y = 0;
		}else {

//#TODO Have to create some runtime configuration using xml

#if LINMICE_INV_AXES

			aux = x;
			x = y;
			y = aux;

#endif

#if LINMICE_INV_X
			data->point.x -= x;
#else
			data->point.x += x;
#endif

#if LINMICE_INV_Y
			data->point.y -= y;
#else
			data->point.y += y;
#endif

		}


	    if(data->point.x < 0)
	      data->point.x = 0;
	    if(data->point.y < 0)
	      data->point.y = 0;
	    if(data->point.x >= lv_disp_get_hor_res(indev_drv->disp))
	      data->point.x = lv_disp_get_hor_res(indev_drv->disp) - 1;
	    if(data->point.y >= lv_disp_get_ver_res(indev_drv->disp))
	      data->point.y = lv_disp_get_ver_res(indev_drv->disp) - 1;

	    lv_indev_state_t act_state = left ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL;

		if(data->state != act_state)
			data->state = act_state;

		//printf("x=%d, y=%d, left=%d, middle=%d, right=%d\n", data->point.x, data->point.y, left, middle, right);

	}

}

void linmice_close(void) {
	close(fd);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif
