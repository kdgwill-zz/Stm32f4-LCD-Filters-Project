/**
  ******************************************************************************
  * @file    lzgDecompressionStream.c
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
#include "lzgDecompressionStream.h"

static const uint8_t LZG_LENGTH_DECODE_LUT[32]= { 2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,35,48,72,128 };

static void init(LzgDecomp * lzg){

    int i;

    // no error yet

    //errorProvider.clear();

    // initialize the output byte buffer

    lzg->_compressedDataAvailable=lzg->_compressedSize;
    lzg->_historyCopyDataAvailable=0;

    lzg->_dst=_circbuf;
    lzg->_dstEnd=lzg->_circbuf+sizeof(lzg->_circbuf);

    // skip header information

    if(!input.skip(16))
      return;

    // Get marker symbols from the input stream

    lzg->_input >> _marker1;
    lzg->_input >> _marker2;
    lzg->_input >> _marker3;
    lzg->_input >> _marker4;

    _compressedDataAvailable-=20;           // the header and 4 markers

    // Initialize marker symbol LUT

    for(i=0;i<256;++i)
      _isMarkerSymbolLUT[i]=0;

    _isMarkerSymbolLUT[_marker1]=1;
    _isMarkerSymbolLUT[_marker2]=1;
    _isMarkerSymbolLUT[_marker3]=1;
    _isMarkerSymbolLUT[_marker4]=1;
}

void LZGDecomp_init(LzgDecomp * lzg, LzgDecomp * input,uint32_t compressedSize){
	lzg->_input = input;
	lzg->_compressedSize = compressedSize;
	lzg->_islzgDecompressionStream = 1;
	init(lzg);
}

void LZGDecomp_init2(LzgDecomp * lzg, LinearBuffer * input2,uint32_t compressedSize){
	lzg->_input2 = input2;
	lzg->_compressedSize = compressedSize;
	lzg->_islzgDecompressionStream = 0;
	init(lzg);
}


uint8_t LZGDecomp_readNextUncompressedByte(LzgDecomp * lzg, uint8_t * nextByte);
uint8_t LZGDecomp_nextByteFromStream(LzgDecomp * lzg, uint8_t * nextByte);
uint8_t LZGDecomp_getByteFromHistoryCopy(LzgDecomp * lzg);
     
int16_t LZGDecomp_read(LzgDecomp * lzg);
uint8_t LZGDecomp_read(LzgDecomp * lzg, void *buffer,uint32_t size,uint32_t * actuallyRead);
uint8_t LZGDecomp_close(LzgDecomp * lzg);
uint8_t LZGDecomp_skip(LzgDecomp * lzg, uint32_t howMuch);
uint8_t LZGDecomp_available(LzgDecomp * lzg);
uint8_t LZGDecomp_reset(LzgDecomp * lzg);

/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/
