/**
  ******************************************************************************
  * @file    hx8352a.h
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    11-April-2015
  * @brief   This file contains all the function protoypes for the hx8352a display driver
  ******************************************************************************
  * @attention
  *
  *
  *
  * <h2><center>&copy; COPYLEFT 2011 el6483</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HX8352A_H
#define __HX8352A_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "milliSecondTimer.h"
//BRING IN ALL REQUIRED COMMANDS INTO BASE FILE
#include "hx8352aColour16Specialisation.h" 
#include "hx8352aOrientation.h"
#include "hx8352aBacklight.h"
#include "hx8352a_commands.h"
#include "hx8352a_pinout.h"
#include "tft01_400x240.h"
#include "gamma12.h"
#include "stdint.h"


/**
  * Initialise the LCD. Do the reset sequence.
  */
void hx8352aInit(FSMC16Ref * accessMode);

/**
  * Apply the panel gamma settings
  * @param gamma The gamma class containing the one value
  */
void hx8352aApplyGamma(FSMC16Ref * accessMode, Gamma12 gamma);

/**
  * Send the panel to sleep. This procedure follows the specification
  * in the Himax application note.
  */
void hx8352aSleep(FSMC16Ref * accessMode);

/**
  * Wake the panel up. The wakeup sequence needs to set the power and
  * oscillation parameters which are panel-specific. Hence we defer to
  * the panel traits for the implementation.
  */
void hx8352aWake(FSMC16Ref * accessMode);

/**
  * Issue the command that allows graphics ram writing to commence
  */
void hx8352aBeginWriting(FSMC16Ref * accessMode);

/**
  * Set the scroll area to a full-width rectangle region
  * @param y The y-co-ord of the region
  * @param height The height of the region
  */
void hx8352aSetScrollArea(FSMC16Ref * accessMode, uint16_t y,uint16_t height);



#ifdef __cplusplus
}
#endif

#endif /*__hx8352a_H */


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/
