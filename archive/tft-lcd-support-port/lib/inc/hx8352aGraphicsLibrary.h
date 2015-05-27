/**
  ******************************************************************************
  * @file    hx8352aGraphicsLibrary.h
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    19-April-2015
  * @brief   Template implementation of a graphics library. This library inherits from the device implementation
  * 		that provides the methods that the graphics library needs to access the hardware
  ******************************************************************************
  * @attention
  *
  *
  *
  * <h2><center>&copy; COPYLEFT 2011 el6483</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HX8352A_GRAPHICS_LIBRARY_H
#define __HX8352A_GRAPHICS_LIBRARY_H

#ifdef __cplusplus
 extern "C" {
#endif

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define ABS(x) ((x)<0 ? -(x) : (x))

#include <hx8352a.h>
#include <font.h>
#include <fsmc16BitAccessMode.h>


typedef struct GraphLibVar {
      FSMC16Ref * accessMode;

      UnpackedColour _foreground;
      UnpackedColour _background;

      Point _streamSelectedPoint;         // need to keep a copy so rvalue points can be used
      FontBase *_streamSelectedFont;    // can keep a ptr, user should not delete font while selected
      uint8_t _fontFilledBackground;         // true to use filled backgrounds for fonts
} GraphLibVar;

//Fundamentals.c
void initGraphicsLibrary(GraphLibVar * gvar, FSMC16Ref * accessMode2);
//colour choices
void graphLib_setForeground(GraphLibVar * gvar, tCOLOUR cr);
void graphLib_setForeground2(GraphLibVar * gvar, uint8_t r,uint8_t g,uint8_t b);
void graphLib_setBackground(GraphLibVar * gvar, tCOLOUR cr);
void graphLib_setBackground2(GraphLibVar * gvar, uint8_t r,uint8_t g,uint8_t b);
// panel querying
Rectangle graphLib_getFullScreenRectangle();
int16_t graphLib_getXmax();
int16_t graphLib_getYmax();
// drawing primitives
void graphLib_clearScreen(GraphLibVar * gvar);
void graphLib_moveToPoint(GraphLibVar * gvar,const Point * pt);


//Primatives.c
// drawing primitives
void graphLib_plotPoint(GraphLibVar * gvar, const Point * p);
void graphLib_drawLine(GraphLibVar * gvar, const Point * p1,const Point * p2);

//Ellipse.c
// drawing primitives
void graphLib_fillEllipse(GraphLibVar * gvar, const Point * center,const Size * size);
void graphLib_drawEllipse(GraphLibVar * gvar, const Point * center,const Size * size);
void graphLib_plot4EllipsePoints(GraphLibVar * gvar, int16_t cx,int16_t cy,int16_t x,int16_t y);

//Rectangle.c
// drawing primitives
void graphLib_fillRectangle(GraphLibVar * gvar, const Rectangle * rc);
void graphLib_clearRectangle(GraphLibVar * gvar, const Rectangle * rc);
void graphLib_drawRectangle(GraphLibVar * gvar, const Rectangle * rc);
void graphLib_gradientFillRectangle(GraphLibVar * gvar, const Rectangle * rc,Direction dir,tCOLOUR first,tCOLOUR last);

//Text.c
//LzgText.c
//Bitmap.c

// text output methods

//void graphLib_setFontFilledBackground(bool fontFilledBackground);

//Size graphLib_writeString(const Point& p,const Font& font,const char *str);
//void graphLib_writeCharacterFill(const Point& p,const Font& font,const FontChar& fc);
//void graphLib_writeCharacterNoFill(const Point& p,const Font& font,const FontChar& fc);
//Size graphLib_measureString(const Font& font,const char *str) const;
//Font * graphLib_getStreamSelectedFont();

// text output methods - LZG fonts

//Size graphLib_writeString(const Point& p,const LzgFont& font,const char *str);
//void graphLib_writeCharacter(const Point& p,const LzgFont& font,const FontChar& fc);

// can't do these as a template with specialisation because you can't specialise
// members in a template class that isn't also fully specialised

//GraphicsLibrary& operator<<(const char *str);
//GraphicsLibrary& operator<<(char c);
//GraphicsLibrary& operator<<(int32_t val);
//GraphicsLibrary& operator<<(uint32_t val);
//GraphicsLibrary& operator<<(int16_t val);
//GraphicsLibrary& operator<<(uint16_t val);
//GraphicsLibrary& operator<<(const DoublePrecision& val);
//GraphicsLibrary& operator<<(double val);
//GraphicsLibrary& operator<<(const Point& p);
//GraphicsLibrary& operator<<(const Font& f);


// bitmap handling

//template<class TDmaCopierImpl>
//bool graphLib_drawBitmap(const Rectangle& rc,InputStream& source,DmaLcdWriter<TDmaCopierImpl>& dma,uint32_t priority=DMA_Priority_High);
//bool graphLib_drawBitmap(const Rectangle& rc,InputStream& source);

// jpeg handling

//void graphLib_drawJpeg(const Rectangle& rc,InputStream& source);



 

#ifdef __cplusplus
}
#endif

#endif /*__HX8352A_GRAPHICS_LIBRARY_H */


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/

