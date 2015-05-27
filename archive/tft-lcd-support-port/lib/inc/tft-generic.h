/**
  ******************************************************************************
  * @file    tft-generic.h
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    11-April-2015
  * @brief   This file contains all the function protoypes for a generic tft screen
  ******************************************************************************
  * @attention
  *
  *
  *
  * <h2><center>&copy; COPYLEFT 2011 el6483</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TFT_GENERIC_H
#define __TFT_GENERIC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h> //uint*_t


/** 
  * @brief  RGB332 -> 8 bbp (Red 3, Green 3, Blue 2)
  *		Organized as a byte in memory as 
  *		(RRR GGG BB)
  */  
typedef union{
	struct RGB_8bbp{
		uint8_t RED    : 3;
		uint8_t GREEN  : 3;
		uint8_t BLUE   : 2;
	} unpacked332;
	uint8_t packed332;
}RGB332;


/** 
  * @brief  RGB555 -> 16 bpp (Red 5, Green 5, Blue 5)
  *		Organized as a half-word in memory 
  *		(U RRRRR GGGGG BBBBB)
  */  
typedef union{
	struct RGB_16bbp{
		uint8_t UNUSED : 1;
		uint8_t RED    : 5;
		uint8_t GREEN  : 5;
		uint8_t BLUE   : 5;
	} unpacked555;
	uint16_t packed555;
}RGB555;

/**
  * @brief RGB565 -> 16 bpp (Red 5, Green 6, Blue 5)
  *		Organized as a half-word in memory 
  *		(RRRRR GGGGGG BBBBB)
  */
typedef union{
	struct RGB_16bbp_2{
		uint8_t RED    : 5;
		uint8_t GREEN  : 6;
		uint8_t BLUE   : 5;
	} unpacked565;
	uint16_t packed565;
}RGB565;

/**
  * @brief RGB888 -> 24 bpp (Red 8, Green 8, Blue 8)
  *		Organized as a word (32-bit) in memory
  *		(UUUUUUUU RRRRRRRR GGGGGGGG BBBBBBBB)
  */
typedef union{
	struct RGB_24bbp{
		uint8_t UNUSED : 8;
		uint8_t RED    : 8;
		uint8_t GREEN  : 8;
		uint8_t BLUE   : 8;
	} unpacked888;
	uint32_t packed888;
}RGB888;



    /*
     * Possible display orientations
     */

    typedef enum Orientation {
      PORTRAIT,               // long side up
      LANDSCAPE               // short side up
    }Orientation;

    /*
     * Possible colour depths. Not every colour depth is guaranteed to be
     * supported by the driver embedded in the panel.
     */

    typedef enum ColourDepth {
      COLOURS_16BIT,          // 64K colours
      COLOURS_18BIT,          // 262K colours
      COLOURS_24BIT           // 16M colours
    }ColourDepth;

    /*
     * Possible memory locations for something
     */

    typedef enum MemoryLocation {
      FLASH_UNCOMPRESSED,     // it's in flash (program) memory
      FLASH_COMPRESSED,       // it's in flash, and it's compressed
      SRAM                    // it's in the SRAM address space
    }MemoryLocation;

    /*
     * Possible directions
     */
    typedef enum Direction {
      HORIZONTAL,
      VERTICAL
    }Direction;

#ifdef __cplusplus
}
#endif

#endif /*__tft-generic_H */


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/
