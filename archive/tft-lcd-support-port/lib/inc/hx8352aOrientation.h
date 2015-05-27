/**
  ******************************************************************************
  * @file    hx8352aOrientation.h
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    17-April-2015
  * @brief   Specialisation of HX8352AOrientation for the panel in PORTRAIT mode.
  * 		using the Fsmc16BitAccessMode 
  ******************************************************************************
  * @attention
  *
  *
  *
  * <h2><center>&copy; COPYLEFT 2011 el6483</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HX8352A_ORIENTATION_H
#define __HX8352A_ORIENTATION_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "hx8352a_commands.h"
#include "fsmc16BitAccessMode.h"
#include "tft01_400x240.h" 
#include "tft-generic.h"
#include "drawing.h"

/**
  * Change the local orientation 
  * NOTE: Partial impl only use to set initial orient don't change after
  */
void hx8352aOrient_changeOrientation(enum Orientation orient);

/**
  * Get the register setting for memory access control
  * @return The entry mode register setting for portrait
  */
uint16_t hx8352aOrient_getMemoryAccessControl();

/**
  * Get the width in pixels
  * @return the panel's width
  */
int16_t hx8352aOrient_getWidth();

/**
  * Get the width in pixels
  * @return the panel's height
  */
int16_t hx8352aOrient_getHeight();

/**
  * Move the display output rectangle
  * @param rc The display output rectangle
  */
void hx8352aOrient_moveTo2(FSMC16Ref * accessMode, const Rectangle * rc);

/**
  * Move the display rectangle to the rectangle described by the co-ordinates
  * @param xstart starting X position
  * @param ystart starting Y position
  * @param xend ending X position
  * @param yend ending Y position
  */
void hx8352aOrient_moveTo(FSMC16Ref * accessMode, int16_t xstart,int16_t ystart,int16_t xend,int16_t yend);

/**
  * Move the X position
  * @param xstart The new X start position
  * @param xend The new X end position
  */
void hx8352aOrient_moveX(FSMC16Ref * accessMode, int16_t xstart,int16_t xend);

/**
  * Move the Y position
  * @param ystart The new Y start position
  * @param yend The new Y end position
  */
void hx8352aOrient_moveY(FSMC16Ref * accessMode, int16_t ystart,int16_t yend);

/**
  * Set a vertical scroll position
  * @param scrollPosition The new scroll position
  */
void hx8352aOrient_setScrollPosition(FSMC16Ref * accessMode, int16_t scrollPosition);

#ifdef __cplusplus
}
#endif

#endif /*__DEFAULT_H */


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/
