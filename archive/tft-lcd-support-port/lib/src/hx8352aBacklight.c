/**
  ******************************************************************************
  * @file    hx8352aBacklight.c
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
#include "hx8352aBacklight.h"


void initHx8352aBacklight(uint32_t frequency){
	uint32_t HCLK = 0;
    //Start the clock
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	
    // set the timebase for PWM to user's frequency choice (default 1Mhz)
    TIM_TimeBaseInitTypeDef timerInitStructure;
    timerInitStructure.TIM_Period = 2000; 
    timerInitStructure.TIM_Prescaler = ((HCLK/2)/frequency)-1;
    timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    timerInitStructure.TIM_RepetitionCounter = 0;//default i suppose
    TIM_TimeBaseInit(TIM4, &timerInitStructure);
    TIM_Cmd(TIM4, ENABLE);

      // initialise the timer's comparator (must have been declared with a channel feature)

      //this->initCompareForPwmOutput();

    TIM_OCInitTypeDef outputChannelInit = {0,};
    outputChannelInit.TIM_OCMode = TIM_OCMode_PWM1;
    outputChannelInit.TIM_Pulse = 64;//THIS MAKES IT 80% Duty Cycle since period is 80;
    outputChannelInit.TIM_OutputState = TIM_OutputState_Enable;
    outputChannelInit.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC1Init(TIM4, &outputChannelInit);
    TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
	//    setDutyCycle(initialDutyCycle);

    GPIO_PinAFConfig(HX8352A_LED_A_PIN.port, HX8352A_LED_A_PIN.pin, GPIO_AF_TIM4);
}


void initHx8352aDefaultBacklight(){
	initHx8352aBacklight(1000000);
}


void hx8352aBacklight_fadeTo(uint16_t newPercentage,int msPerStep){
      //int8_t direction;
      //_dutyCycle;

      //if(newPercentage==_dutyCycle)//assume 0
      //  return;

      //direction=newPercentage>_dutyCycle ? 1 : -1;

      //while(newPercentage!=_dutyCycle) {
       // this->setDutyCycle(_dutyCycle+direction);
       // MillisecondTimer::delay(msPerStep);
      //}
}
/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/






















