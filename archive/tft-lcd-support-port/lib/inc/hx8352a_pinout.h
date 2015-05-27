/**
  ******************************************************************************
  * @file    hx8352a_pinout.h
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    17-April-2015
  * @brief   This file contains information and functions pertaining to pin layout
  * 		for a tft implemented on an FSMC enabled development board
  ******************************************************************************
  * @attention
  *
  *
  *
  * <h2><center>&copy; COPYLEFT 2011 el6483</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HX8352A_PINOUT_H
#define __HX8352A_PINOUT_H

#ifdef __cplusplus
 extern "C" {
#endif
/**
 * This implementation uses the FMSC perhipheral on bank 1 
 * of the STM32f407 discovery board.
 * 
 * This LCD is a 16-bit device supporting 65536 colours
 *
 * TFT TO STM324f07 pin Connection
 *
 * Board <--> PIN  || BOARD <--> PIN
 * NC	 <-->      || NC    <-->		
 * LED_A <--> PD13 || NC    <-->     		
 * NC	 <-->      || SD_CS <-->    		
 * RESET <--> PE1  || SD_DIN<-->     		
 * F_CS	 <-->      || SD_SLK<--> 		
 * CS	 <--> PD7  || SD_OUT<-->		
 * DB15	 <--> PD10 || T_IRQ <-->     		
 * DB14	 <--> PD9  || T_OUT <--> 		
 * DB13	 <--> PD8  || NC    <--> 		
 * DB12	 <--> PE15 || T_DIN <-->  		
 * DB11	 <--> PE14 || T_CS  <-->		
 * DB10	 <--> PE13 || T_CLK <-->  		
 * DB9	 <--> PE12 || DB7   <--> PE10		
 * DB8	 <--> PE11 || DB6   <--> PE9		
 * RD	 <--> PD4  || DB5   <--> PE8		
 * WR	 <--> PD5  || DB4   <--> PE7		
 * RS 	 <--> PD11 || DB3   <--> PD1	
 * NC	 <-->      || DB2   <--> PD0	      
 * VCC	 <--> 3.3V || DB1   <--> PD15	
 * GND   <--> GND  || DB0   <--> PD14 	
 *-------------------------------------------------------------
 *-------------------------------------------------------------
 * LCD signals 		Signal description
 * RS 			LCD Register Select,Instruction/Data, 0 Registers 1 display data(RAM)
 * D0-D15 		Data D0-D15
 * CS 			Chip Select
 * RD 			Read operation: active low write ie 0 to write else 1
 * WR 			Write operation: active low write ie 0 to write else 1
 * LED_A		BACKLIGHT
 * CS			CHIP SELECT	active low 0
 * RESET		Reset the controller chip
*/


#include "gpio_helper.h"

#define HX8352A_LED_A_PIN   (GpioPinRef){GPIOD,GPIO_Pin_13}
#define HX8352A_RESET_PIN   (GpioPinRef){GPIOE,GPIO_Pin_1}
#define HX8352A_CS_PIN 	    (GpioPinRef){GPIOD,GPIO_Pin_7}
#define HX8352A_RD_PIN 	    (GpioPinRef){GPIOD,GPIO_Pin_4}
#define HX8352A_WR_PIN 	    (GpioPinRef){GPIOD,GPIO_Pin_5}
#define HX8352A_RS_PIN 	    (GpioPinRef){GPIOD,GPIO_Pin_11}

#define HX8352A_SET_LED_A   GPIO_Helper_SetBits(HX8352A_LED_A_PIN)
#define HX8352A_SET_RESET   GPIO_Helper_SetBits(HX8352A_RESET_PIN)
#define HX8352A_SET_CS      GPIO_Helper_SetBits(HX8352A_CS_PIN)
#define HX8352A_SET_RD      GPIO_Helper_SetBits(HX8352A_RD_PIN)
#define HX8352A_SET_WR      GPIO_Helper_SetBits(HX8352A_WR_PIN)
#define HX8352A_SET_RS      GPIO_Helper_SetBits(HX8352A_RS_PIN)

#define HX8352A_CLR_LED_A   GPIO_Helper_ClearBits(HX8352A_LED_A_PIN)
#define HX8352A_CLR_RESET   GPIO_Helper_ClearBits(HX8352A_RESET_PIN)
#define HX8352A_CLR_CS      GPIO_Helper_ClearBits(HX8352A_CS_PIN)
#define HX8352A_CLR_RD      GPIO_Helper_ClearBits(HX8352A_RD_PIN)
#define HX8352A_CLR_WR      GPIO_Helper_ClearBits(HX8352A_WR_PIN)
#define HX8352A_CLR_RS      GPIO_Helper_ClearBits(HX8352A_RS_PIN)

#define HX8352A_READ_LED_A  GPIO_Helper_ReadBits(HX8352A_LED_A_PIN)
#define HX8352A_READ_RESET  GPIO_Helper_ReadBits(HX8352A_RESET_PIN)
#define HX8352A_READ_CS     GPIO_Helper_ReadBits(HX8352A_CS_PIN)
#define HX8352A_READ_RD     GPIO_Helper_ReadBits(HX8352A_RD_PIN)
#define HX8352A_READ_WR     GPIO_Helper_ReadBits(HX8352A_WR_PIN)
#define HX8352A_READ_RS     GPIO_Helper_ReadBits(HX8352A_RS_PIN)


#ifdef __cplusplus
}
#endif

#endif /*__HX8352A_PINOUT_H */


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/

