/**
  ******************************************************************************
  * @file    tft01_400x240.h
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    17-April-2015
  * @brief   Panel traits for a generic tft implementaiton of the hx8352a display.
  ******************************************************************************
  * @attention
  *
  *
  *
  * <h2><center>&copy; COPYLEFT 2011 el6483</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TFT01_400_x_240_H
#define __TFT01_400_x_240_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "fsmc16BitAccessMode.h"
#include "milliSecondTimer.h" //millisecondTimer_delay
#include "hx8352a_commands.h"

enum {
	tft01_400x240_LONG_SIDE = 400,
	tft01_400x240_SHORT_SIDE = 240
};

void tft01_400x240_initialise(FSMC16Ref * accessMode);

void tft01_400x240_wake(FSMC16Ref * accessMode);


#ifdef __cplusplus
}
#endif

#endif /*__DEFAULT_H */


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/

