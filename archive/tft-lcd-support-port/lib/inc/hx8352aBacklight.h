/**
  ******************************************************************************
  * @file    hx8352aBacklight.h
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    20-April-2015
  * @brief   Create a backlight powered by pwm
  ******************************************************************************
  * @attention
  *
  *
  *
  * <h2><center>&copy; COPYLEFT 2011 el6483</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DEFAULT_H
#define __DEFAULT_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_gpio.h"
#include "hx8352a_pinout.h"

 /**
  * The level of remapping required (none, partial1, partial2, full)
  * Not all remap levels are available for each timer. check the ST reference manual for details
  */

enum TimerGpioRemapLevel {
    TIMER_REMAP_NONE     = 0,
    TIMER_REMAP_PARTIAL1 = 1,
    TIMER_REMAP_PARTIAL2 = 2,
    TIMER_REMAP_FULL     = 3
};

void initHx8352aBacklight(uint32_t frequency);
void initHx8352aDefaultBacklight();
void hx8352aBacklight_fadeTo(uint16_t newPercentage,int msPerStep);

#ifdef __cplusplus
}
#endif

#endif /*__DEFAULT_H */


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/

