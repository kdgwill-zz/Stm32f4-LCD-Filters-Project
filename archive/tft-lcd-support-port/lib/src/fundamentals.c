/**
  ******************************************************************************
  * @file    fundamentals.c
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    19-April-2015
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
#include "hx8352aGraphicsLibrary.h"


/**
  * Constructor
  */
void initGraphicsLibrary(GraphLibVar * gvar, FSMC16Ref * accessMode){

      gvar->accessMode = accessMode;

      gvar->_fontFilledBackground=1;//true;

      // initialise the panel
      hx8352aInit(gvar->accessMode);
}


/**
  * set the foreground
  */
void graphLib_setForeground(GraphLibVar * gvar, tCOLOUR cr){
	HX8352A16_unpackColour(cr,&gvar->_foreground);
}


void graphLib_setForeground2(GraphLibVar * gvar, uint8_t r,uint8_t g,uint8_t b){
	HX8352A16_unpackColour2(r,g,b,&gvar->_foreground);
}

/**
  * set the background
  */

void graphLib_setBackground(GraphLibVar * gvar, tCOLOUR cr){
	HX8352A16_unpackColour(cr,&gvar->_background);
}


void graphLib_setBackground2(GraphLibVar * gvar, uint8_t r,uint8_t g,uint8_t b){
	HX8352A16_unpackColour2(r,g,b,&gvar->_background);
}

/**
  * Get a full-screen rectangle
  */
Rectangle graphLib_getFullScreenRectangle(){
	return (Rectangle){0,0,hx8352aOrient_getWidth(),hx8352aOrient_getHeight()};
}

/**
  * Get the panel maximum x-coord
  */
int16_t graphLib_getXmax(){
	return hx8352aOrient_getWidth()-1;
}

/**
  * Get the panel maximum y-coord
  */
int16_t graphLib_getYmax(){
	return hx8352aOrient_getHeight()-1;
}

/**
  * clear screen to the background colour
  */
void graphLib_clearScreen(GraphLibVar * gvar){
	Rectangle r = {0,0,hx8352aOrient_getWidth(),hx8352aOrient_getHeight()};
	hx8352aOrient_moveTo2(gvar->accessMode,&r);
	HX8352A16_fillPixels(gvar->accessMode,(uint32_t)hx8352aOrient_getWidth()*(uint32_t)hx8352aOrient_getHeight(),&gvar->_background);
}

/**
  * Convenience helper to move to a point extending to the
  * end of the display
  */
void graphLib_moveToPoint(GraphLibVar * gvar,const Point * pt){
	Rectangle r = {pt->X,pt->Y,hx8352aOrient_getWidth()-pt->X,hx8352aOrient_getHeight()-pt->Y};
	hx8352aOrient_moveTo2(gvar->accessMode,&r);
}

/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/
