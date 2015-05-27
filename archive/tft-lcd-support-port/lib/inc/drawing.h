/**
  ******************************************************************************
  * @file    drawing.h
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    19-April-2015
  * @brief   Basic drawing implementation for rectangles points and sizes
  ******************************************************************************
  * @attention
  *
  *
  *
  * <h2><center>&copy; COPYLEFT 2011 el6483</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DRAWING_UNIQUE_22_H
#define __DRAWING_UNIQUE_22_H

#ifdef __cplusplus
 extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include <stdint.h> //uint*_t



#define POINT_ORIGIN   (Point){0,0}


typedef struct Point {
	/// X co-ordinate
      	int16_t X;

      	/// Y co-ordinate
      	int16_t Y;
} Point;

typedef struct Size {
      /// The width
      int16_t Width;

      /// The height
      int16_t Height;
} Size;

typedef struct Rectangle {
	/// X co-ordinate
      int16_t X;

      /// Y co-ordinate
      int16_t Y;

      /// Width
      int16_t Width;

      /// Height
      int16_t Height;
} Rectangle;


uint8_t pointsEqual(const Point * p1, const Point * p2);

uint8_t sizesEqual(const Size * s1, const Size * s2);

uint8_t rectanglesEqual(const Rectangle * r1, const Rectangle * r2);
   

/**
  * Get the size of the rectangle
  * @return the size structure
  */
Size rectGetSize(const Rectangle * r1);

/**
  * Get the top-left corner
  * @return the top-left
  */
Point rectGetTopLeft(const Rectangle * r1);

/**
  * Check if the given point is contained in this rectangle
  * @return true if is contained
  */
uint8_t rectContainsPoint(const Rectangle * r, const Point * p);

/**
  * Derivation of rectangle that accepts negative width/height and internally
  * converts them to positive values while keeping the rect at the same position
  */
void rectNormalizeRectangle(Rectangle * r);


#ifdef __cplusplus
}
#endif

#endif /*__DEFAULT_H */


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/

