/**
  ******************************************************************************
  * @file    lzgDecompressionStream.h
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    19-April-2015
  * @brief   Class to support a linear I/O buffer.
   * The buffer has a start and an end and
   * does not wrap around like the circular buffer. The reset() call can be used to reset
   * both the input pointer and the resetOutput() call can be used to reset the output pointer.
  ******************************************************************************
  * @attention
  *
  *
  *
  * <h2><center>&copy; COPYLEFT 2011 el6483</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LINEAR_BUFFER_INPUT_STREAM_H
#define __LINEAR_BUFFER_INPUT_STREAM_H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>

typedef struct LinearBuffer {
      uint8_t *_buffer;
      uint32_t _bufferSize;
      volatile uint8_t *_readPtr;
      volatile uint8_t *_writePtr;
      bool _needToFree;
} LinearBuffer;

/**
  * Error codes
  */
enum {
	/// invalid seek size, you probably tried to seek forward beyond the available data
        E_INVALID_SEEK_SIZE=1,
        /// There is not enough space in the buffer for this operation
        E_BUFFER_FULL
};


#ifdef __cplusplus
}
#endif

#endif /*__LINEAR_BUFFER_INPUT_STREAM_H */


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/

