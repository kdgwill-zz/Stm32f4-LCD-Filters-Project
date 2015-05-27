/**
  ******************************************************************************
  * @file    drawing.c
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    19-April-2015
  * @brief   Basic drawing implementation for rectangles points and sizes
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
#include "drawing.h"

uint8_t pointsEqual(const Point * p1, const Point * p2){
	return p1->X==p2->X && 
	       p1->Y==p2->Y; 
}

uint8_t sizesEqual(const Size * s1, const Size * s2){
	return s1->Width  == s2->Width 	&&
               s1->Height == s2->Height; 
}

uint8_t rectanglesEqual(const Rectangle * r1, const Rectangle * r2){
	return r1->X      == r2->X 	&& 
               r1->Y      == r2->Y 	&& 
	       r1->Width  == r2->Width 	&& 
	       r1->Height == r2->Height; 
}
   
Size rectGetSize(const Rectangle * r1){
	Size s;

        s.Width=r1->Width;
        s.Height=r1->Height;

        return s;
}

Point rectGetTopLeft(const Rectangle * r1){
	Point p;

        p.X=r1->X;
        p.Y=r1->Y;

        return p;
}

uint8_t rectContainsPoint(const Rectangle * r, const Point * p) {
	return p->X >= r->X 		&& 
	       p->X <= r->X + r->Width 	&& 
	       p->Y >= r->Y 		&& 
	       p->Y <= r->Y + r->Height;
}

void rectNormalizeRectangle(Rectangle * r){
        if(r->Height<0) {
          r->Y+=(r->Height+1);
          r->Height=-r->Height;
        }

        if(r->Width<0) {
          r->X+=(r->Width+1);
          r->Width=-r->Width;
        }
}
 
/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/
