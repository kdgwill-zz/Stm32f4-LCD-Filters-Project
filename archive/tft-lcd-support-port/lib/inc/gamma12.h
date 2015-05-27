/**
  ******************************************************************************
  * @file    gamma12.h
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    19-April-2015
  * @brief   Gamma values for the HX8352A
  *
  * This device support 4 fixed gamma curves, so we just need a word
  * to hold the index of the current curve
  ******************************************************************************
  * @attention
  *
  *
  *
  * <h2><center>&copy; COPYLEFT 2011 el6483</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HX8352A_GAMMA12_H
#define __HX8352A_GAMMA12_H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>

typedef uint16_t Gamma12[12];

//Gamma12 
void initGamma12(Gamma12 gamma,
	  uint16_t g1,uint16_t g2,uint16_t g3,uint16_t g4, uint16_t g5, uint16_t g6,
          uint16_t g7,uint16_t g8,uint16_t g9,uint16_t g10,uint16_t g11,uint16_t g12);

#ifdef __cplusplus
}
#endif

#endif /*__DEFAULT_H */


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/

