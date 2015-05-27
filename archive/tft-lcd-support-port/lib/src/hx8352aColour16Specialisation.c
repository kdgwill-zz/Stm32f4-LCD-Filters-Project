/**
  ******************************************************************************
  * @file    hx8352aColour16Specialisation.c
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
#include "hx8352aColour16Specialisation.h"


const enum ColourDepth colourDepth16 = COLOURS_16BIT;


void HX8352A16_unpackColour(tCOLOUR src,UnpackedColour * dest){
	dest->packed565=(src & 0xf80000) >> 8 | (src & 0xfc00) >> 5 | (src & 0xf8) >> 3;    
}

void HX8352A16_unpackColour2(uint8_t red,uint8_t green,uint8_t blue,UnpackedColour * dest){
      red&=0xf8;
      green&=0xfc;
      blue&=0xf8;

      dest->packed565=(((uint16_t)red) << 8) | (((uint16_t)green) << 3) | (blue >> 3);
}

void HX8352A16_writePixel(FSMC16Ref * accessMode,const UnpackedColour * cr){
	fsmc16_writeData(accessMode, cr->packed565);
}

void HX8352A16_writePixelAgain(FSMC16Ref * accessMode,const UnpackedColour * cr){
	fsmc16_writeDataAgain(accessMode, cr->packed565);
}

void HX8352A16_fillPixels(FSMC16Ref * accessMode,uint32_t numPixels,const UnpackedColour * cr){
	fsmc16_writeCommand(accessMode, HX8352A_COMMAND_MEMORY_WRITE);
	fsmc16_writeMultiData(accessMode,numPixels,cr->packed565);
}

void HX8352A16_allocatePixelBuffer(uint32_t numPixels,uint8_t** buffer,uint32_t* bytesPerPixel){
	//use of dynamic code unrecommended in embedded systems
	(*buffer)=(uint8_t *)calloc(numPixels*2,sizeof(uint8_t));
	if (buffer == NULL) {
		//USE OF DYNAMIC CODE CAN CAUSE ISSUES DOWN THE LINE
	}
	*bytesPerPixel=2;
}

void HX8352A16_rawTransfer(FSMC16Ref * accessMode,const void *buffer,uint32_t numPixels){
	fsmc16_rawTransfer(accessMode,buffer,numPixels);
}


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/
