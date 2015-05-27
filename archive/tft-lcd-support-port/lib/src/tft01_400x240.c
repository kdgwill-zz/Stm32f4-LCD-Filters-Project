/**
  ******************************************************************************
  * @file    tft01_400x240.c
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    17-April-2015
  * @brief   
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
#include "tft01_400x240.h"

void tft01_400x240_initialise(FSMC16Ref * accessMode){

      // do the startup sequence

	  millisecondTimer_delay(160);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_TEST_MODE_CONTROL,0x02);         // TESTM=1
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_VDDD_CONTROL,0x02);              // VDC_SEL=010.
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_SOURCE_GAMMA_RESISTOR_1,0x00);   // STBA[15:8]=0x00
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_SOURCE_GAMMA_RESISTOR_2,0xB3);   // STBA[7]=1, STBA[5:4]=11, STBA[1:0]=11
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_TEST_MODE_CONTROL,0x00);         // TESTM=0

      // Power Supply Setting

      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_OSC_CONTROL_1,0x91);           // RADJ=0, OSC_EN=1 (100%)
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_DISPLAY_CONTROL_1,0x01);       // TE ON
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_CYCLE_CONTROL_1,0x14);         // N_DCDC=0x14

      millisecondTimer_delay(20);

      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_POWER_CONTROL_3,0x13);        // BT=0001, AP=100
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_POWER_CONTROL_2,0x11);        // VC3=001, VC1=001 (VLCD/DDVDH)=6.45V)
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_POWER_CONTROL_4,0x0);         // gamma x2.8
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_POWER_CONTROL_5,0x08);        // VBGP=1111
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_VCOM_CONTROL,0x3B);           // VCM=011_1011

      millisecondTimer_delay(30);

      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_POWER_CONTROL_1,0x0A);        // GASENB=0, PON=0, DK=1, XDK=0, VLCD_TRI=1, STB=0
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_POWER_CONTROL_1,0x1A);        // GASENB=0, PON=1, DK=1, XDK=0, VLCD_TRI=1, STB=0

      millisecondTimer_delay(50);

      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_POWER_CONTROL_1,0x12);       // GASENB=0, PON=1, DK=0, XDK=0, VLCD_TRI=1, STB=0,

      // VLCD=2XVCI by 2 CAPs

      millisecondTimer_delay(50);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_POWER_CONTROL_6,0x2E);       // VCOMG=1, VDV=0_1110

      //VCOMG NEW LOCATION
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_TEST_MODE_CONTROL,0x02);     // TESTM=1
      fsmc16_writeCommand2(accessMode,0x93,0x10);                           // R93[4]=1, VCOMG=1 ...undocumented!!!
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_TEST_MODE_CONTROL,0x00);

      // DGC Function disabled
      fsmc16_writeCommand2(accessMode,0x5A,0x00);

      // Display ON Setting
     fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_SOURCE_CONTROL_1,0xFF);      // N_SAP=0111 1111
     fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_SOURCE_CONTROL_2,0x0E);      // I_SAP=0000 1110
     fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_CYCLE_CONTROL_10,0x38);      // EQS=1000 0111
     fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_CYCLE_CONTROL_11,0x38);      // EQP=0011 1000
     fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_DISPLAY_CONTROL_2,0x38);     // GON=1, DTE=1, D=10

     millisecondTimer_delay(50);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_DISPLAY_CONTROL_2,0x3C);         // GON=1, DTE=1, D=11
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_DISPLAY_MODE_CONTROL,0x02);      // INVON=0, NORNO=1
}

void tft01_400x240_wake(FSMC16Ref * accessMode){
	tft01_400x240_initialise(accessMode);
}


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/
