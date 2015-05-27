/**
  ******************************************************************************
  * @file    milliSecondTimer.h
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    17-April-2015
  * @brief   This file contains timer functions
  ******************************************************************************
  * @attention
  *
  *
  *
  * <h2><center>&copy; COPYLEFT 2011 el6483</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MILLISECONDTIMER_H__
#define __MILLISECONDTIMER_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"
#include <stdint.h>

 /**
   * Delay for given time. Waits for the current value of the systick counter to reach a target.
   * @param millis The amount of time to wait.
   */
//LOOK AT THIS FUNCTION LATER CONSIDER USING SYSTEM AND INTERRUPTS
void millisecondTimer_delay(int millis);


void milliSecTimer_init();
uint32_t milliSecTimer_millis();
void milliSecTimer_delay(uint32_t millis_);
void milliSecTimer_reset();
uint8_t milliSecTimer_hasTimedOut(uint32_t start,uint32_t timeout);
uint32_t milliSecTimer_difference(uint32_t start);

#ifdef __cplusplus
}
#endif

#endif /*__MILLISECONDTIMER_H */


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/

