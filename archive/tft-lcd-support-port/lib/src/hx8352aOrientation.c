/**
  ******************************************************************************
  * @file    hx8352aOrientation.c
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    17-April-2015
  * @brief   
  * 
  *  @verbatim
  *
  *          ====================================================================
  *          =======================How to use this driver=======================
  *          ====================================================================       
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
#include "hx8352aOrientation.h"

static enum Orientation orient = LANDSCAPE;

void hx8352aOrient_changeOrientation(enum Orientation orientation){orient = orientation;}

uint16_t hx8352aOrient_getMemoryAccessControl(){
	if(orient==LANDSCAPE){
		return 0xAA;    // MY | MV | BGR | SCROLL
	}else return 0xA;// BGR | SCROLL
}

int16_t hx8352aOrient_getWidth(){if(orient==LANDSCAPE){
		return tft01_400x240_LONG_SIDE; 
	}else return tft01_400x240_SHORT_SIDE;
}

int16_t hx8352aOrient_getHeight(){
	if(orient==LANDSCAPE){
		return tft01_400x240_SHORT_SIDE;
	}else return tft01_400x240_LONG_SIDE;
}

void hx8352aOrient_moveTo2(FSMC16Ref * accessMode, const Rectangle * rc){
	hx8352aOrient_moveTo(accessMode,rc->X,rc->Y,rc->X+rc->Width-1,rc->Y+rc->Height-1);
}

void hx8352aOrient_moveTo(FSMC16Ref * accessMode, int16_t xstart,int16_t ystart,int16_t xend,int16_t yend){
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_COLUMN_ADDRESS_START_H,xstart >> 8);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_COLUMN_ADDRESS_START_L,xstart & 0xff);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_COLUMN_ADDRESS_END_H,xend >> 8);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_COLUMN_ADDRESS_END_L,xend & 0xff);

      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_ROW_ADDRESS_START_H,ystart >> 8);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_ROW_ADDRESS_START_L,ystart & 0xff);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_ROW_ADDRESS_END_H,yend >> 8);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_ROW_ADDRESS_END_L,yend & 0xff);
}


void hx8352aOrient_moveX(FSMC16Ref * accessMode, int16_t xstart,int16_t xend){
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_COLUMN_ADDRESS_START_H,xstart >> 8);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_COLUMN_ADDRESS_START_L,xstart & 0xff);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_COLUMN_ADDRESS_END_H,xend >> 8);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_COLUMN_ADDRESS_END_L,xend & 0xff);
}
void hx8352aOrient_moveY(FSMC16Ref * accessMode, int16_t ystart,int16_t yend){
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_ROW_ADDRESS_START_H,ystart >> 8);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_ROW_ADDRESS_START_L,ystart & 0xff);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_ROW_ADDRESS_END_H,yend >> 8);
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_ROW_ADDRESS_END_L,yend & 0xff);
}

void hx8352aOrient_setScrollPosition(FSMC16Ref * accessMode, int16_t scrollPosition){

      if(scrollPosition<0)
        scrollPosition+=tft01_400x240_LONG_SIDE;
      else if(scrollPosition>tft01_400x240_LONG_SIDE-1)
        scrollPosition-=tft01_400x240_LONG_SIDE;

      // write to the register

      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_VERTICAL_SCROLL_START_ADDRESS_H,(scrollPosition >> 8));
      fsmc16_writeCommand2(accessMode,HX8352A_COMMAND_VERTICAL_SCROLL_START_ADDRESS_L,scrollPosition & 0xff);
}

/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/
