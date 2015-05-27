/**
  ******************************************************************************
  * @file    fsmc16BitAccessMode.h
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    17-April-2015
  * @brief   FSMC implementation for TFT LCD panels controlled by an 8080 interface.
  *
  * The 8080 LCD is assumed to be in 16 bit mode connected to the 16 data pins, RW, RD, NE.
  *
  * The RS (register select) operation is achieved by using an additional address line. e.g. A16.
  * A write to an address that keeps A16 low will active RS (usually active low). A write that sets
  * A16 high will set RS high and achieve a data write to the controller.
  ******************************************************************************
  * @attention
  *
  *
  *
  * <h2><center>&copy; COPYLEFT 2011 el6483</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FSMC16BITACCESSMODE_H
#define __FSMC16BITACCESSMODE_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx_fsmc.h"
#include "milliSecondTimer.h" //millisecondTimer_delay
#include "gpio_helper.h"

 typedef struct FSMC16Ref {
	 volatile uint16_t *_dataAddress;
	 volatile uint16_t *_registerAddress;
	 GpioPinRef _resetPin;
	 FSMC_NORSRAMInitTypeDef _var;
 } FSMC16Ref;

typedef FSMC_NORSRAMTimingInitTypeDef Fsmc8080LcdTiming;


 /**
   * Sets up FSMCD for 8080 LCD timing,
   * for devices that just need address and data setup times
   */
 void initFsmc8080LcdTiming(Fsmc8080LcdTiming * lcd,uint32_t addressSetup,uint32_t dataSetup);

 /**
   * Constructor. Initialises the AFIO GPIO pins for the FSMC used to control an 8080 LCD.
   * @param[in] timing The timing structure for this LCD panel in both read and write mode
   * @param[in] registerAddressLine The address line index used to switch between data and register select. e.g. 16 = A16.
   * @param[in] resetPin The GPIO pin that corresponds to the TFT reset line.
   */
 void fsmc16_structInit(FSMC16Ref * fsmc, const Fsmc8080LcdTiming* timing,uint16_t registerAddressLine,const GpioPinRef* resetPin);

 /**
   * Constructor. Initialises the AFIO GPIO pins for the FSMC used to control an 8080 LCD.
   * @param[in] readTiming The timing structure for this LCD panel in read mode
   * @param[in] writeTiming The timing structure for this LCD panel in write mode
   * @param[in] registerAddressLine The address line index used to switch between data and register select. e.g. 16 = A16.
   * @param[in] resetPin The GPIO pin that corresponds to the TFT reset line.
   */
 void fsmc16_structInit2(FSMC16Ref * fsmc, const Fsmc8080LcdTiming* readTiming,const Fsmc8080LcdTiming* writeTiming,
		 uint16_t registerAddressLine,const GpioPinRef* resetPin);
 /**
   * enable or disable the peripheral
   */
 void fsmc16_enable(FSMC16Ref * fsmc, FunctionalState enable);

 /**
  * Hard-reset the panel
  */
 void fsmc16_reset(FSMC16Ref * fsmc);

 /**
   * Write a command to the register address
   * @param command The command to write
   */
 void fsmc16_writeCommand(FSMC16Ref * fsmc, uint16_t command);

 /**
   * Write a command to the panel that takes a parameter
   * @param command The command to write
   * @param parameter The parameter to the command
   */
 void fsmc16_writeCommand2(FSMC16Ref * fsmc, uint16_t command,uint16_t parameter);

 /**
   * Write a data value to the panel
   * @param value The data value to write
   */
 void fsmc16_writeData(FSMC16Ref * fsmc, uint16_t value);

 /**
   * Write the same data again to the panel - no optimisation possible
   * @param value The data value to write
   */
 void fsmc16_writeDataAgain(FSMC16Ref * fsmc, uint16_t value);

 /**
   * Write multiple data. A possible optimisation point that we can't take advantage of
   * in this access mode
   * @param howMuch How many pixels
   * @param value The pixel
   */
 void fsmc16_writeMultiData(FSMC16Ref * fsmc, uint32_t howMuch,uint16_t value);

 /**
   * Read a data value from the panel
   * @return The value read
   */
uint16_t fsmc16_readData(FSMC16Ref * fsmc);

 /**
   * Get the data address
   * @return The data address
   */
volatile uint16_t *fsmc16_getDataAddress(FSMC16Ref * fsmc);

 /**
   * Bulk copy data to the panel
   * @param buffer data source
   * @param numWords number of words to transfer
   */
void fsmc16_rawTransfer(FSMC16Ref * fsmc, const void *buffer,uint32_t numWords);

 /**
   * Get the width of a DMA transfer for this FSMC
   * @return 16 bits
   */
void fsmc16_getDmaTransferSizes(FSMC16Ref * fsmc, uint32_t * peripheralsize,uint32_t * memsize);


#ifdef __cplusplus
}
#endif

#endif /*__FSMC16BITACCESSMODE_H */


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/

