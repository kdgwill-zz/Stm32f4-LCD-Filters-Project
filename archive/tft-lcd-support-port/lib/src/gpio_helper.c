/**
  ******************************************************************************
  * @file    gpio_helper.c
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    17-April-2015
  * @brief   This file provides functions to manage use of gpio
  *
  *  @verbatim
  *
  *          ===================================================================
  *                                 How to use this driver
  *          ===================================================================
  *          1.
  *
  *  @endverbatim
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYLEFT 2015 el6483 </center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio_helper.h"

//SET BITS FROM PORT
void GPIO_Helper_SetBits(GpioPinRef ref){
	GPIO_SetBits(ref.port,ref.pin);
}

//CLEAR BITS FROM PORT
void GPIO_Helper_ClearBits(GpioPinRef ref){
	GPIO_ResetBits(ref.port,ref.pin);
}

//READ BITS FROM PORT
uint8_t GPIO_Helper_ReadBits(GpioPinRef ref){
	return GPIO_ReadInputDataBit(ref.port,ref.pin);
}

//Initialize GPIO
void initGPIO(
  GPIO_TypeDef* port,
  uint32_t pins,
  GPIOMode_TypeDef mode,
  GPIOSpeed_TypeDef speed,
  GPIOOType_TypeDef otype,
  GPIOPuPd_TypeDef pupd
  ){
	// Declare a gpio as a GPIO_InitTypeDef:
	GPIO_InitTypeDef gpio;

	// Used for pin remapping
    //RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

	// Use RCC_AHB1PeriphClockCmd to enable the clock on RCC_AHB1Periph
 	RCC_AHB1PeriphClockCmd(port==GPIOA ? RCC_AHB1Periph_GPIOA :
            			   port==GPIOB ? RCC_AHB1Periph_GPIOB :
            			   port==GPIOC ? RCC_AHB1Periph_GPIOC :
						   port==GPIOD ? RCC_AHB1Periph_GPIOD :
						   port==GPIOE ? RCC_AHB1Periph_GPIOE :
						   port==GPIOF ? RCC_AHB1Periph_GPIOF :
								   	   	 RCC_AHB1Periph_GPIOG,
						   ENABLE);

 	// Call GPIO_StructInit, passing a pointer to gpio
     	// This resets the GPIO port to its default values
 	GPIO_StructInit(&gpio);
 	//Configure Data port pins
 	gpio.GPIO_Pin = pins;
 	gpio.GPIO_Mode = mode;
 	gpio.GPIO_Speed = speed;
 	gpio.GPIO_OType = otype;
 	gpio.GPIO_PuPd = pupd;
 	GPIO_Init(port, &gpio);
}

//Initialize GPIO with alternate function
void initGPIO_AF(
  GPIO_TypeDef* port,
  uint32_t pins,
  GPIOSpeed_TypeDef speed,
  GPIOOType_TypeDef otype,
  GPIOPuPd_TypeDef pupd,
  uint8_t afSelection){

	initGPIO(port,pins,GPIO_Mode_AF,speed,otype,pupd);

	// need to configure each of the selected pins for AF

      uint32_t bit;
      uint8_t source;

      for(bit=1,source=0;bit<=0x8000;bit<<=1,source++){
	    if((pins & bit)!=0){
	          GPIO_PinAFConfig(port,source,afSelection);
            }
      }

}
/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/
