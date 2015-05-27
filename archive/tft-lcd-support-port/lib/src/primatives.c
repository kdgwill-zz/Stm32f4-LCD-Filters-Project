/**
  ******************************************************************************
  * @file    primatives.c
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


//static int16_t max(int16_t x,int16_t y){return x>y?x:y;}
static int16_t min(int16_t x,int16_t y){return x<y?x:y;}
//static int16_t abs(int16_t x){return x<0? -x:x;}

/**
  * plot a point in the foreground colour
  */
void graphLib_plotPoint(GraphLibVar * gvar, const Point * p){
	Rectangle r = { p->X,p->Y,1,1};
	hx8352aOrient_moveTo2(gvar->accessMode,&r);
	hx8352aBeginWriting(gvar->accessMode);
	HX8352A16_writePixel(gvar->accessMode,&gvar->_foreground);
}

/**
  * Draw a line between two points. Modified slightly by me (Andy Brown) to include the final point
  * in the line. Therefore drawing from (x,y) to (x,y) will result in a single point being plotted.
  * Freely useable in non-commercial applications as long as credits
  * to Po-Han Lin and link to http://www.edepot.com is provided in
  * source code and can been seen in compiled executable.
  * Commercial applications please inquire about licensing the algorithms.
  */
void graphLib_drawLine(GraphLibVar * gvar, const Point * p1,const Point * p2){

      // optimisation for straight lines. filling rectangles is much more efficient than plotting points

      if(p1->X==p2->X){
	Rectangle r = {p1->X,min(p1->Y,p2->Y),1,abs(p2->Y-p1->Y)+1};
        graphLib_fillRectangle(gvar,&r);
      }else if(p1->Y==p2->Y){
	Rectangle r = {min(p1->X,p2->X),p1->Y,abs(p2->X-p1->X)+1,1};
        graphLib_fillRectangle(gvar,&r);
      }else {
        int16_t x0,x1,y0,y1;

        x0=p1->X;
        y0=p1->Y;
        x1=p2->X;
        y1=p2->Y;

        if(x0>x1) {

          // the optimiser does this swap method faster than
          // the xor-trick

          int16_t t;

          t=x0;
          x0=x1;
          x1=t;

          t=y0;
          y0=y1;
          y1=t;
        }

        // calculate constants up-front

        int16_t dx=x1-x0;
        int16_t dy=abs(y1-y0);
        int16_t sy=y0<y1 ? 1 : -1;
        int16_t mdy=-dy;
        int16_t err=dx-dy;
        int8_t xinc;

        // set the drawing rectangle that we need and plot the first point
	hx8352aOrient_moveTo(gvar->accessMode,x0,y0,graphLib_getXmax(),graphLib_getYmax());
	hx8352aBeginWriting(gvar->accessMode);
	HX8352A16_writePixel(gvar->accessMode,&gvar->_foreground);

        while(x0!=x1 || y0!=y1) {

          int16_t e2=2*err;

          if(e2>mdy) {

            err-=dy;
            x0++;

            // make a note that X has incremented

            xinc=1;//true
          }
          else
            xinc=0;//false       // nothing happened to X

          if(x0==x1 && y0==y1) {

            if(xinc) {

              // plot the pending X increment before returning
	      HX8352A16_writePixelAgain(gvar->accessMode,&gvar->_foreground);
              break;
            }
          }

          if(e2<dx) {
            err+=dx;
            y0+=sy;

            // Y has changed. We're going to have to do a complete
            // pixel write after we've moved the bare minimum of
            // window pointers

            if(xinc)
		hx8352aOrient_moveX(gvar->accessMode,x0,graphLib_getXmax());

            hx8352aOrient_moveX(gvar->accessMode,y0,graphLib_getYmax());

            hx8352aBeginWriting(gvar->accessMode);
	    HX8352A16_writePixel(gvar->accessMode,&gvar->_foreground);
          }
          else {

            // Y has not changed, if X has changed then all we need
            // to do is push out another pixel

            if(xinc)
              HX8352A16_writePixelAgain(gvar->accessMode,&gvar->_foreground);
          }
        }
      }
    }
/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/
