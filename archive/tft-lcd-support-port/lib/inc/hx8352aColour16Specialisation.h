/**
  ******************************************************************************
  * @file    hx8352aColour16Specialisation.h
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    17-April-2015
  * @brief   Template class holding the specialisation of HX8352AColour for 16-bit colours
  ******************************************************************************
  * @attention
  *
  *
  *
  * <h2><center>&copy; COPYLEFT 2011 el6483</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HX8352A_COLOUR_16_SPECIALISATION_H
#define __HX8352A_COLOUR_16_SPECIALISATION_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "hx8352a_commands.h"
#include "tft01_400x240.h" 
#include "fsmc16BitAccessMode.h"
#include "tft-generic.h"
#include <stdlib.h>//use of calloc this is highly unrecommended in embedded code

typedef uint32_t tCOLOUR;

typedef struct UnpackedColour {//Why use this? consider changing to a struct in tft-generic more useful
	uint16_t packed565;
}UnpackedColour;

//typedef FSMC16Ref * accessMode; // if extend then typedef
//colourdepth moved to impl

/**
  * Unpack the colour from rrggbb to the internal 5-6-5 format
  * 00000000RRRRRRRRGGGGGGGGBBBBBBBB ->
  * 0000000000000000RRRRRGGGGGGBBBBB
  * @param src rrggbb
  * @param dest The unpacked colour structure
  */
void HX8352A16_unpackColour(tCOLOUR src,UnpackedColour* dest);

/**
  * Unpack the colour from components to the internal format
  * @param red
  * @param green
  * @param blue
  * @param dest
  */
void HX8352A16_unpackColour2(uint8_t red,uint8_t green,uint8_t blue,UnpackedColour * dest);

/**
  * Write a single pixel to the current output position.
  * Assumes that the caller has already issued the beginWriting() command.
  * @param cr The pixel to write
  */
void HX8352A16_writePixel(FSMC16Ref * accessMode,const UnpackedColour * cr);

/**
     * Write the same colour pixel that we last wrote. This gives the access mode a chance to
     * optimise sequential pixel writes. The colour is provided for drivers that cannot optimise
     * and must fall back to a full write.
     * @param cr The same pixel to write again
     */
void HX8352A16_writePixelAgain(FSMC16Ref * accessMode,const UnpackedColour * cr);

/**
  * Fill a block of pixels with the same colour. This operation will issue the
  * beginWriting() command for you.
  * @param numPixels how many
  * @param cr The unpacked colour to write
  */
void HX8352A16_fillPixels(FSMC16Ref * accessMode,uint32_t numPixels,const UnpackedColour * cr);

/**
  * Allocate a buffer for pixel data. You supply the number of pixels and this allocates the buffer as a uint8_t[].
  * Allocated buffers should be freed with delete[]
  *
  * @param numPixels The number of pixels to allocate
  * @param buffer The output buffer
  * @param bytesPerPixel Output the number of bytes per pixel
  */
void HX8352A16_allocatePixelBuffer(uint32_t numPixels,uint8_t** buffer,uint32_t* bytesPerPixel);

/**
  * Bulk-copy some pixels from the memory buffer to the LCD. The pixels must already be formatted ready
  * for transfer.
  * @param buffer The memory buffer
  * @param numPixels The number of pixels to transfer from the buffer
  */
void HX8352A16_rawTransfer(FSMC16Ref * accessMode,const void *data,uint32_t numPixels);



#ifdef __cplusplus
}
#endif

#endif /*__HX8352A_COLOUR_16_SPECIALISATION_H */


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/

