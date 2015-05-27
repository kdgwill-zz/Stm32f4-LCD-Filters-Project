/**
  ******************************************************************************
  * @file    gamma12.c
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
#include "gamma12.h"
//Gamma12
void initGamma12(Gamma12 gamma,
	  uint16_t g1,uint16_t g2,uint16_t g3,uint16_t g4,uint16_t g5,uint16_t g6,
          uint16_t g7,uint16_t g8,uint16_t g9,uint16_t g10,uint16_t g11,uint16_t g12){

	//Gamma12 gamma = (Gamma12)calloc(12,sizeof(uint16_t));

	gamma[0]=g1;
        gamma[1]=g2;
        gamma[2]=g3;
        gamma[3]=g4;
        gamma[4]=g5;
        gamma[5]=g6;
        gamma[6]=g7;
        gamma[7]=g8;
        gamma[8]=g9;
        gamma[9]=g10;
        gamma[10]=g11;
        gamma[11]=g12;	
	
	//return gamma;
}

//void deleteGamma12(Gamma12 gamma){
//	free(gamma);
//}

/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/
