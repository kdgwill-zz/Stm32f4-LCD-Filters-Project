/**
  ******************************************************************************
  * @file    hx8352a.c
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    11-April-2015
  * @brief   This file provides firmware functions to manage functionality of the 
  *	     HX8352A
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
#include "hx8352a.h"

void hx8352aInit(FSMC16Ref * accessMode){

      // reset the device

      fsmc16_reset(accessMode);

      // initialise the panel - the HX8352A supports multiple panel types hence the reset sequence
      // is not generic and is moved into the panel traits class

      tft01_400x240_initialise(accessMode);

      // set the orientation and scroll area

      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_MEMORY_ACCESS_CONTROL,hx8352aOrient_getMemoryAccessControl());
      hx8352aSetScrollArea(accessMode,0,tft01_400x240_LONG_SIDE);
}

void hx8352aApplyGamma(FSMC16Ref * accessMode, Gamma12 gamma){
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_GAMMA_1+0, gamma[0]);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_GAMMA_1+1, gamma[1]);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_GAMMA_1+2, gamma[2]);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_GAMMA_1+3, gamma[3]);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_GAMMA_1+4, gamma[4]);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_GAMMA_1+5, gamma[5]);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_GAMMA_1+6, gamma[6]);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_GAMMA_1+7, gamma[7]);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_GAMMA_1+8, gamma[8]);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_GAMMA_1+9, gamma[9]);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_GAMMA_1+10,gamma[10]);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_GAMMA_1+11,gamma[11]);
}
void hx8352aSleep(FSMC16Ref * accessMode){

      // display Off
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_DISPLAY_CONTROL_2,0x38);      //GON=1, DTE=1, D=10
      millisecondTimer_delay(40);

      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_DISPLAY_CONTROL_2,0x28);      //GON=1, DTE=0, D=10
      millisecondTimer_delay(40);

      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_DISPLAY_CONTROL_2,0x00);      //GON=0, DTE=0, D=00

      // power Off
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_POWER_CONTROL_6,0x14);      // VCOMG=0, VDV=1_0100
      millisecondTimer_delay(10);

      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_POWER_CONTROL_1,0x02);    // GASENB=0, PON=0, DK=0, XDK=0, VLCD_TRI=1, STB=0
      millisecondTimer_delay(10);

      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_POWER_CONTROL_1,0x0A);    // GASENB=0, PON=0, DK=1, XDK=0, VLCD_TRI=1, STB=0
      millisecondTimer_delay(10);

      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_POWER_CONTROL_3,0x40);    // AP=000
      millisecondTimer_delay(10);

      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_SOURCE_CONTROL_1,0x00);   // N_SAP=1100 0000
      millisecondTimer_delay(10);

      // into STB mode
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_POWER_CONTROL_1,0x0B);    // GASENB=0, PON=0, DK=0, XDK=0, VLCD_TRI=1, STB=1
      millisecondTimer_delay(10);

      // stop oscillation
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_OSC_CONTROL_1,0x90);      // RADJ=1001, OSC_EN=0
}
void hx8352aWake(FSMC16Ref * accessMode){
	tft01_400x240_wake(accessMode);
}
void hx8352aBeginWriting(FSMC16Ref * accessMode){
	fsmc16_writeCommand(accessMode,HX8352A_COMMAND_MEMORY_WRITE);
}
void hx8352aSetScrollArea(FSMC16Ref * accessMode, uint16_t y,uint16_t height){
	
      uint16_t bfa;

      bfa=tft01_400x240_LONG_SIDE-height-y;

      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_VERTICAL_SCROLL_TOP_FIXED_AREA_H,y >> 8);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_VERTICAL_SCROLL_TOP_FIXED_AREA_L,y & 0xff);

      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_VERTICAL_SCROLL_HEIGHT_H,height >> 8);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_VERTICAL_SCROLL_HEIGHT_L,height & 0xff);

      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_VERTICAL_SCROLL_BOTTOM_FIXED_AREA_H,bfa >> 8);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_VERTICAL_SCROLL_BOTTOM_FIXED_AREA_L,bfa & 0xff);
}
/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/


















