/**
  ******************************************************************************
  * @file    font.h
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    19-April-2015
  * @brief   Implementation of a font compiled into memory
  ******************************************************************************
  * @attention
  *
  *
  *
  * <h2><center>&copy; COPYLEFT 2011 el6483</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FONT_UNIQUE_22_H
#define __FONT_UNIQUE_22_H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>

/**
  * @brief A Single font character definition
  *
  */
typedef struct FontChar {
	// The character code
        uint8_t Code;

        // Pixel width of this char
        uint8_t PixelWidth;

        // Binary data packed left to right, top to bottom
        const uint8_t* Data;
}FontChar;

/**
  * The font type (bitmap of pixels or LZG compressed bitmap)
  */
typedef enum FontType {
	FONT_BITMAP,//!< FONT_BITMAP
        FONT_LZG    //!< FONT_LZG
} FontType;

typedef struct FontBase{
	FontType _fontType;
	FontChar * _characters;
	uint8_t _characterCount;
	uint8_t _firstCharacter;
	uint8_t _height;
	int8_t _characterSpacing;
	uint8_t _lastCharacter;
}FontBase;

/**
  * bitmap fonts - the original font format
  */
void font_initFont(FontBase * font, uint8_t firstChar,uint8_t characterCount,uint8_t height,int8_t spacing,FontChar * characters);

/**
  * lzg fonts - Lzg TrueType fonts
  */
void font_initLZGFont(FontBase * font, uint8_t firstChar,uint8_t characterCount,uint8_t height,int8_t spacing,FontChar * characters);

/**
  * Get the font character definition address
  */
void font_getCharacter(FontBase * font, uint8_t character,const FontChar** fc);

/**
  * Get the font height.
  */
uint8_t font_getHeight(FontBase * font);

/**
  * Get the character spacing
  */
int8_t font_getCharacterSpacing(FontBase * font);

/**
  * Get Font Type
  */
FontType font_getType(FontBase * font);

/**
  * not implemented
  */
//uint16_t font_getId();


#ifdef __cplusplus
}
#endif

#endif /*__FONT_UNIQUE_22_H */


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/

