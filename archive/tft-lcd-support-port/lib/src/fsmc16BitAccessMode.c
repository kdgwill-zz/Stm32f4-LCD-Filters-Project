/**
  ******************************************************************************
  * @file    Fsmc16BitAccessMode.c
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    17-April-2015
  * @brief   This file provides functions to manage use of FSMC on STM32F407 it
  * 		should be known that this implementation focuses on FsmcBank1NorSram1
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
#include "fsmc16BitAccessMode.h"
#include "stm32f4xx_dma.h"

    /**
      * Static access to the base address
      */
    static uint32_t * FsmcBank1NorSram1_getBaseAddress() {
    	  return ((uint32_t *)0x60000000);
    }

	static uint32_t FsmcBank1NorSram1_getBank() {

		return ((uint32_t)FSMC_Bank1_NORSRAM1);
    }

	static void FsmcBank1NorSram1_Init(){
		//ClockControl<PERIPHERAL_FSMC>::On();
	     RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FSMC,ENABLE);
	    //
	    initGPIO(GPIOD,
	            GPIO_Pin_7,
				GPIO_Speed_50MHz, //This is a trait for FSMC on f407
				GPIO_PuPd_NOPULL,
				GPIO_OType_PP,
				GPIO_AF_FSMC);
	}
	 /**
	   * Initialise the FSMC timing registers
	   * @param timing The timing constants
	   */
	 static void fsmc16_initialiseTiming(FSMC16Ref * fsmc, const Fsmc8080LcdTiming* readTiming,const Fsmc8080LcdTiming* writeTiming){

		 fsmc16_enable(fsmc,DISABLE);

		 // initialise how the FSMC will work and then enable it

		 fsmc->_var.FSMC_Bank=FsmcBank1NorSram1_getBank();
		 fsmc->_var.FSMC_DataAddressMux=FSMC_DataAddressMux_Disable;
		 fsmc->_var.FSMC_MemoryType=FSMC_MemoryType_SRAM;
		 fsmc->_var.FSMC_MemoryDataWidth=FSMC_MemoryDataWidth_16b;
		 fsmc->_var.FSMC_BurstAccessMode=FSMC_BurstAccessMode_Disable;
		 fsmc->_var.FSMC_WaitSignalPolarity=FSMC_WaitSignalPolarity_Low;
		 fsmc->_var.FSMC_WrapMode=FSMC_WrapMode_Disable;
		 fsmc->_var.FSMC_WaitSignalActive=FSMC_WaitSignalActive_BeforeWaitState;
		 fsmc->_var.FSMC_WriteOperation=FSMC_WriteOperation_Enable;
		 fsmc->_var.FSMC_WaitSignal=FSMC_WaitSignal_Disable;
		 fsmc->_var.FSMC_WriteBurst=FSMC_WriteBurst_Disable;
		 fsmc->_var.FSMC_AsynchronousWait=FSMC_AsynchronousWait_Disable;

		 // extended mode is required only if the user has provided separate
		 // timings for read and write

		 if(readTiming==writeTiming) {
		   fsmc->_var.FSMC_ExtendedMode=FSMC_ExtendedMode_Disable;
		   fsmc->_var.FSMC_ReadWriteTimingStruct=(Fsmc8080LcdTiming *)(writeTiming);
		   fsmc->_var.FSMC_WriteTimingStruct=(void *)0;//NULL;//nullptr;
		 } else {
		   fsmc->_var.FSMC_ExtendedMode=FSMC_ExtendedMode_Enable;
		   fsmc->_var.FSMC_ReadWriteTimingStruct=(Fsmc8080LcdTiming *)(readTiming);
		   fsmc->_var.FSMC_WriteTimingStruct=(Fsmc8080LcdTiming *)(writeTiming);
		 }

		 // initialise the FSMC and then enable it

		 FSMC_NORSRAMInit(&(fsmc->_var));

		 fsmc16_enable(fsmc,ENABLE);
	 }

/**
  * Main initialiser. Initialises the AFIO GPIO pins for the FSMC used to control an 8080 LCD.
  * @param[in] readTiming The timing structure for this LCD panel in read mode
  * @param[in] writeTiming The timing structure for this LCD panel in write mode
  * @param[in] registerAddressLine The address line index used to switch between data and register select. e.g. 16 = A16.
  * @param[in] resetPin The GPIO pin that corresponds to the TFT reset line.
  */
 static void fsmc16_initialise(FSMC16Ref * fsmc, const Fsmc8080LcdTiming* readTiming
		 ,const Fsmc8080LcdTiming*writeTiming,uint16_t registerAddressLine){

	 // initialise the FSMC and the NE line (different for each bank)
	 FsmcBank1NorSram1_Init();

	 // initialise the addressing, data and control lines
	 initGPIO_AF(GPIOD,
	          GPIO_Pin_0 |    // D2
	          GPIO_Pin_1 |    // D3
	          GPIO_Pin_4 |    // NOE
	          GPIO_Pin_5 |    // NWE
	          GPIO_Pin_8 |    // D13
	          GPIO_Pin_9 |    // D14
	          GPIO_Pin_10 |   // D15
	          GPIO_Pin_14 |   // D0
	          GPIO_Pin_15,    // D1
	 		  GPIO_Speed_50MHz, //This is a trait for FSMC on f407
	 		  GPIO_PuPd_NOPULL,
	 		  GPIO_OType_PP,
	 		  GPIO_AF_FSMC);
	 initGPIO(GPIOE,
	          GPIO_Pin_7 |    // D4
	          GPIO_Pin_8 |    // D5
	          GPIO_Pin_9 |    // D6
	          GPIO_Pin_10 |   // D7
	          GPIO_Pin_11 |   // D8
	          GPIO_Pin_12 |   // D9
	          GPIO_Pin_13 |   // D10
	          GPIO_Pin_14 |   // D11
	          GPIO_Pin_15,    // D12
	 		  GPIO_Speed_50MHz, //This is a trait for FSMC on f407
	 		  GPIO_PuPd_NOPULL,
	 		  GPIO_OType_PP,
	 		  GPIO_AF_FSMC);

	 fsmc16_initialiseTiming(fsmc,readTiming,writeTiming);

	 fsmc->_dataAddress     = ((uint16_t *)FsmcBank1NorSram1_getBaseAddress()) +(1<<registerAddressLine);
	 fsmc->_registerAddress = (uint16_t *)FsmcBank1NorSram1_getBaseAddress();
 }

 /**
   * Sets up FSMCD for 8080 LCD timing,
   * for devices that just need address and data setup times
   */
 void initFsmc8080LcdTiming(Fsmc8080LcdTiming * lcd,uint32_t addressSetup,uint32_t dataSetup){

     lcd->FSMC_AddressSetupTime=addressSetup;//One unit == 8.3ns (2units 16.6ns)
     lcd->FSMC_DataSetupTime=dataSetup;
	 	 //We change the access mode to mode B for the 8080 LCD devices.
     lcd->FSMC_AccessMode=FSMC_AccessMode_B;    // doesn't really matter. mode B toggles NADV for mux'd memories with a latch
     //Should be default
     lcd->FSMC_AddressHoldTime = 0;
     //lcd->FSMC_BusTurnAroundDuration = 0;
     //lcd->FSMC_CLKDivision = 0x01;
     //lcd->FSMC_DataLatency = 0;
  }


 void fsmc16_structInit(FSMC16Ref * fsmc, const Fsmc8080LcdTiming* timing,uint16_t registerAddressLine,const GpioPinRef* resetPin){
	 fsmc->_resetPin = *resetPin;
	 fsmc16_initialise(fsmc,timing,timing,registerAddressLine);
 }

 void fsmc16_structInit2(FSMC16Ref * fsmc, const Fsmc8080LcdTiming* readTiming,const Fsmc8080LcdTiming* writeTiming,
		 uint16_t registerAddressLine,const GpioPinRef* resetPin){
	 fsmc->_resetPin = *resetPin;
	 fsmc16_initialise(fsmc,readTiming,writeTiming,registerAddressLine);
 }


 void fsmc16_enable(FSMC16Ref * fsmc, FunctionalState enable){
	 FSMC_NORSRAMCmd(FsmcBank1NorSram1_getBank(),enable ? ENABLE : DISABLE);
 }

 void fsmc16_reset(FSMC16Ref * fsmc){
     // let the power stabilise

	 millisecondTimer_delay(10);

     // reset sequence

     GPIO_Helper_SetBits(fsmc->_resetPin);
     millisecondTimer_delay(5);
     GPIO_Helper_ClearBits(fsmc->_resetPin);
     millisecondTimer_delay(50);
     GPIO_Helper_SetBits(fsmc->_resetPin);
     millisecondTimer_delay(50);
 }

 void fsmc16_writeCommand(FSMC16Ref * fsmc, uint16_t command){
	 *(fsmc->_registerAddress)=command;
 }

 void fsmc16_writeCommand2(FSMC16Ref * fsmc, uint16_t command,uint16_t parameter){
	 *(fsmc->_registerAddress)=command;
	 *(fsmc->_dataAddress)=parameter;
 }

 void fsmc16_writeData(FSMC16Ref * fsmc, uint16_t value){
	 *(fsmc->_dataAddress)=value;
 }

 void fsmc16_writeDataAgain(FSMC16Ref * fsmc, uint16_t value){
	 *(fsmc->_dataAddress)=value;
 }

 void fsmc16_writeMultiData(FSMC16Ref * fsmc, uint32_t howMuch,uint16_t value){
	 while(howMuch--)
		 fsmc16_writeData(fsmc,value);
 }

 uint16_t fsmc16_readData(FSMC16Ref * fsmc){
	 return *(fsmc->_dataAddress);
 }

 volatile uint16_t * fsmc16_getDataAddress(FSMC16Ref * fsmc){
	 return fsmc->_dataAddress;
 }
 void fsmc16_rawTransfer(FSMC16Ref * fsmc, const void *buffer,uint32_t numWords){

     const uint16_t *ptr=((uint16_t *)buffer);

     // shift all the pixels
     while(numWords--)
       *(fsmc->_dataAddress)=*ptr++;
 }

 void fsmc16_getDmaTransferSizes(FSMC16Ref * fsmc, uint32_t * peripheralsize,uint32_t * memsize){
	 *peripheralsize=DMA_PeripheralDataSize_HalfWord;
	 *memsize=DMA_MemoryDataSize_HalfWord;
 }





/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/
