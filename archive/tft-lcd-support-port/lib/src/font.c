/**
  ******************************************************************************
  * @file    font.c
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
#include "font.h"
#include <stdlib.h> //NULL


static void initFont(FontBase * font, FontType type,uint8_t firstChar,uint8_t characterCount,uint8_t height,
			int8_t spacing,struct FontChar * characters){
	font->_fontType = type;
        font->_characters = characters;
        font->_characterCount = characterCount;
        font->_firstCharacter = firstChar;
        font->_height = height;
        font->_characterSpacing = spacing;
        font->_lastCharacter = characters[characterCount-1].Code;
}

void font_initFont(FontBase * font,uint8_t firstChar,uint8_t characterCount,uint8_t height,
			int8_t spacing,struct FontChar *characters){
	initFont(font, FONT_BITMAP, firstChar, characterCount,
			height,	spacing, characters);
}

void font_initLZGFont(FontBase * font,uint8_t firstChar,uint8_t characterCount,uint8_t height,
			int8_t spacing,struct FontChar *characters){
	initFont(font, FONT_LZG, firstChar, characterCount,
			height,	spacing, characters);
}

void font_getCharacter(FontBase * font,uint8_t character,const FontChar** fc){

      const FontChar *ptr;
      int16_t i;

      
	uint8_t _firstCharacter = font->_firstCharacter;
	uint8_t _lastCharacter = font->_lastCharacter;	
	uint8_t _characterCount = font->_characterCount;
      // the bulk of the characters are in sequential order, see if we can
      // index directly into the character array to find it

      ptr=NULL;

      if(character >= _firstCharacter && character<_lastCharacter) {

	// the character is in range and indexable, is it in sequential place?

        if((character-_firstCharacter) < _characterCount && 
		font->_characters[character-_firstCharacter].Code==character){
          ptr=&(font->_characters[character-_firstCharacter]);
        }else {

          // did't find it, search for it going backwards because the likelihood is that
          // it's towards the end of the array

          for(i=font->_characterCount-1;i>=0;i--) {

            if(font->_characters[i].Code==character) {
              ptr=&(font->_characters[i]);
              break;
            }
          }
         }
	}

	if(ptr==NULL){
        	ptr=&(font->_characters[0]); // didn't found it, default to first char so user knows something is wrong
	}
      // set up the return data

      (*fc)=ptr;
}

uint8_t font_getHeight(FontBase * font){
	return font->_height;
}

int8_t font_getCharacterSpacing(FontBase * font){
	return font->_characterSpacing;
}

FontType font_getType(FontBase * font){
	return font->_fontType;
}


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/
