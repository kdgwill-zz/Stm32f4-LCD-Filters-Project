/**
  ******************************************************************************
  * @file    lzgDecompressionStream.h
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    19-April-2015
  * @brief Decompress LZG-compressed bytes
  * LzgDecompressionInputStream acts as a filter, taking LZG-compressed bytes from an
  * input stream that you supply and making them available as an uncompressed stream
  * through this class's own implementation of InputStream.
  ******************************************************************************
  * @attention
  *
  *
  *
  * <h2><center>&copy; COPYLEFT 2011 el6483</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LZG_DECOMPRESSION_STREAM_H
#define __LZG_DECOMPRESSION_STREAM_H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>

typedef struct LzgDecomp {
      union{
	LzgDecomp * _input;//This is if islzgDecompressionStream is true
	LinearBuffer * _input2;//This is if islzgDecompressionStream is false
      }
      
     uint8_t _islzgDecompressionStream;//bool

      uint32_t _compressedSize;
      uint32_t _compressedDataAvailable;
      uint8_t _circbuf[2056];               // note the size of this - ensure you can afford it
      uint8_t *_dst,*_dstEnd;
      char _isMarkerSymbolLUT[256];
      uint8_t _marker1,_marker2,_marker3,_marker4;

      uint8_t *_historyCopyPosition;
      uint32_t _historyCopyDataAvailable;
} LzgDecomp;


  /**
   * Constructor. Initiates the decompression.
   * The error provider should be checked to ensure that nothing went wrong
   * while setting up the decompressor
   *
   * @param input The source of compressed bytes
   * @param compressedSize the number of bytes of compressed data
   */
void LZGDecomp_init(LzgDecomp * lzg, InputStream& * nput,uint32_t compressedSize);


uint8_t LZGDecomp_readNextUncompressedByte(LzgDecomp * lzg, uint8_t * nextByte);
uint8_t LZGDecomp_nextByteFromStream(LzgDecomp * lzg, uint8_t * nextByte);
uint8_t LZGDecomp_getByteFromHistoryCopy(LzgDecomp * lzg);
     
int16_t LZGDecomp_read(LzgDecomp * lzg);
uint8_t LZGDecomp_read(LzgDecomp * lzg, void *buffer,uint32_t size,uint32_t * actuallyRead);
uint8_t LZGDecomp_close(LzgDecomp * lzg);
uint8_t LZGDecomp_skip(LzgDecomp * lzg, uint32_t howMuch);
uint8_t LZGDecomp_available(LzgDecomp * lzg);
uint8_t LZGDecomp_reset(LzgDecomp * lzg);

#ifdef __cplusplus
}
#endif

#endif /*__DEFAULT_H */


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/

