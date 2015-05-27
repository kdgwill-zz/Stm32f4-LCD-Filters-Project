/**
  ******************************************************************************
  * @file    gpio_helper.h
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    17-April-2015
  * @brief   This file contains helper functions BASIC GPIO FUNCTIONS
  ******************************************************************************
  * @attention
  *
  *
  *
  * <h2><center>&copy; COPYLEFT 2011 el6483</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_HELPER_H
#define __GPIO_HELPER_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

typedef struct GpioPinRef {
	GPIO_TypeDef* port;
	uint32_t pin;
} GpioPinRef;

//SET BITS FROM PORT
void GPIO_Helper_SetBits(GpioPinRef ref);

//CLEAR BITS FROM PORT
void GPIO_Helper_ClearBits(GpioPinRef ref);

//READ BITS FROM PORT
uint8_t GPIO_Helper_ReadBits(GpioPinRef ref);

//Initialize GPIO
void initGPIO(
  GPIO_TypeDef* port,
  uint32_t pins,
  GPIOMode_TypeDef mode,
  GPIOSpeed_TypeDef speed,
  GPIOOType_TypeDef otype,
  GPIOPuPd_TypeDef pupd
  );

//Initialize GPIO with alternate function
void initGPIO_AF(
  GPIO_TypeDef* port,
  uint32_t pins,
  GPIOSpeed_TypeDef speed,
  GPIOOType_TypeDef otype,
  GPIOPuPd_TypeDef pupd,
  uint8_t afSelection);

#ifdef __cplusplus
}
#endif

#endif /*__GPIO_HELPER_H */


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/

