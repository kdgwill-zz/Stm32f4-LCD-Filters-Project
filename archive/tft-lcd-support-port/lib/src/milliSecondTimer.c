/**
  ******************************************************************************
  * @file    milliSecondTimer.c
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    17-April-2015
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
#include "milliSecondTimer.h"


void millisecondTimer_delay(int millis){millis*=25000;while(millis--);}


volatile static uint32_t _counter;


/**
  * Initialise SysTick to tick at 1ms by initialising it with SystemCoreClock/1000.
  */
void milliSecTimer_init() {
    _counter=0;
    SysTick_Config(SystemCoreClock / 1000);
}


/**
 * SysTick interrupt handler
 */

#ifdef __cplusplus
 extern "C" {
#endif
  void __attribute__ ((weak,interrupt("IRQ"))) SysTick_Handler(void) {
    _counter++;
  }

#ifdef __cplusplus
}
#endif

/**
  * Get the current value of the systick counter.
  * @return The current value of the counter.
  */
uint32_t milliSecTimer_millis() {
    return _counter;
}


/**
  * Delay for given time. Waits for the current value of the systick counter to reach a target.
  * @param millis The amount of time to wait.
  */
void milliSecTimer_delay(uint32_t millis_){
    uint32_t target;

    target=_counter + millis_;
    while(_counter<target);
}


/**
  * Reset the counter to zero
  */
void milliSecTimer_reset(){
    _counter=0;
}


/**
  * Check if a timeout has been exceeded. This is designed to cope with wrap around
  * @return true if the timeout has expired
  */
uint8_t milliSecTimer_hasTimedOut(uint32_t start,uint32_t timeout){
    return milliSecTimer_difference(start)>timeout;
}


/**
  * Return the difference between a starting time and now, taking into account
  * wrap around
  * @param start when we started timing
  * @return The difference
  */
uint32_t milliSecTimer_difference(uint32_t start){
    uint32_t now=milliSecTimer_millis();

    if(now > start){
      return now - start;
    }else{
      return now + (UINT32_MAX - start + 1);
    }
}

/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/
