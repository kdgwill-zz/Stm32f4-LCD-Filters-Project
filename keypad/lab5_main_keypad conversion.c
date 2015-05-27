#include "stm32f4xx.h"
//#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_exti.h"
#include "misc.h"
#include "stm32f4xx_syscfg.h"
#include "tm_stm32f4_gpio.h"
#include "tm_stm32f4_keypad.h"


//const uint16_t LEDS = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
//const uint16_t USER_BUTTON = GPIO_Pin_0;

//uint32_t risingCounter = 0;
//uint32_t fallingCounter = 0;

void init();
//void initLeds();
//void initButton();

int main()
{
  TM_KEYPAD_Button_t Keypad_Button;
  TM_KEYPAD_Init(TM_KEYPAD_Type_Large);
  while (1)
  {
      /* Read keyboard data */
      Keypad_Button = TM_KEYPAD_Read();
      /* Keypad was pressed*/
      if (Keypad_Button != TM_KEYPAD_Button_NOPRESSED
        {
          /* Keypad is pressed */
          switch (Keypad_Button)
          {
              case TM_KEYPAD_Button_0:        /* Button 0 pressed */
                printf ("hit 0");
                for (int i =0;i<3;i++){
                printf("\n%d\n",i);
                }
                break;
              case TM_KEYPAD_Button_1:        /* Button 1 pressed */
                printf ("hit 1");
                for (int i =0;i<3;i++){
                  printf("\n%d\n",i);
                }
                break;
              case TM_KEYPAD_Button_2:        /* Button 2 pressed */
              printf ("hit 2");
              for (int i =0;i<3;i++){
                printf("\n%d\n",i);
              }
                  break;
              case TM_KEYPAD_Button_3:        /* Button 3 pressed */
              printf ("hit 3");
              for (int i =0;i<3;i++){
                printf("\n%d\n",i);
              }
                  break;
              case TM_KEYPAD_Button_4:        /* Button 4 pressed */
              printf ("hit 4");
              for (int i =0;i<3;i++){
                printf("\n%d\n",i);
              }
                  break;
              case TM_KEYPAD_Button_5:        /* Button 5 pressed */
              printf ("hit 5");
              for (int i =0;i<3;i++){
                printf("\n%d\n",i);
              }
                  break;
              case TM_KEYPAD_Button_6:        /* Button 6 pressed */
              printf ("hit 6");
              for (int i =0;i<3;i++){
                printf("\n%d\n",i);
              }
                  break;
              case TM_KEYPAD_Button_7:        /* Button 7 pressed */
              printf ("hit 7");
              for (int i =0;i<3;i++){
                printf("\n%d\n",i);
              }
                  break;
              case TM_KEYPAD_Button_8:        /* Button 8 pressed */
              printf ("hit 8");
              for (int i =0;i<3;i++){
                printf("\n%d\n",i);
              }
                  break;
              case TM_KEYPAD_Button_9:        /* Button 9 pressed */
              printf ("hit 9");
              for (int i =0;i<3;i++){
                printf("\n%d\n",i);
              }
                  /* Do your stuff here */
                  break;
              case TM_KEYPAD_Button_STAR:        /* Button STAR pressed */
              printf ("hit *");
              for (int i =0;i<3;i++){
                printf("\n%d\n",i);
              }
                  break;
              case TM_KEYPAD_Button_HASH:        /* Button HASH pressed */
              printf ("hit #");
              for (int i =0;i<3;i++){
                printf("\n%d\n",i);
              }
                  break;
              case TM_KEYPAD_Button_A:        /* Button A pressed, only on large keyboard */
              printf ("hit A");
              for (int i =0;i<3;i++){
                printf("\n%d\n",i);
              }
                  /* Do your stuff here */
                  break;
              case TM_KEYPAD_Button_B:        /* Button B pressed, only on large keyboard */
              printf ("hit B");
              for (int i =0;i<3;i++){
                printf("\n%d\n",i);
              }
                  /* Do your stuff here */
                  break;
              case TM_KEYPAD_Button_C:        /* Button C pressed, only on large keyboard */
              printf ("hit C");
              for (int i =0;i<3;i++){
                printf("\n%d\n",i);
              }
                  /* Do your stuff here */
                  break;
              case TM_KEYPAD_Button_D:        /* Button D pressed, only on large keyboard */
              printf ("hit D");
              for (int i =0;i<3;i++){
                printf("\n%d\n",i);
              }
                  /* Do your stuff here */
                  break;
                  default:
                  break;
          }

          TM_KEYPAD_Update();
        }
  //  init();
  // main loop does nothing, all the work happens in ISR
  //  while (1);
  }
}
/*
void init() {
    initLeds();
    initButton();
}


void initLeds() {

    // Copy in your initLeds() function from lab2
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    // Enable GPIOD Clock
    GPIOD->MODER |= 0x55 << 24;// Set GPIOD pins 12-15 mode to output
}


void initButton() {
    NVIC_InitTypeDef NVIC_InitStructure;
    EXTI_InitTypeDef EXTI_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    // Enable GPIOA clock for User button peripheral on GPIOA
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    // Enable SYSCFG clock for interrupts
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

    // Configure PA0 pin as input
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // Connect EXTI Line0 (external interrupt line 0) to PA0 pin
    // This is the library function equivalent of running
    // SYSCFG->EXTICR[0] &= SYSCFG_EXTICR1_EXTI0_PA;
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);

    // Configure the interrupt using library functions
    EXTI_InitStructure.EXTI_Line = EXTI_Line0;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);

    // Enable and set priorities for the EXTI0 interrupt in NVIC
    NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}


void EXTI0_IRQHandler(void) {
    // Make sure the interrupt flag is set for EXTI0
    if(EXTI_GetITStatus(EXTI_Line0) != RESET){
        if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)) {
          GPIO_SetBits(GPIOD, LEDS);
        }
        if (!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)) {
          GPIO_ResetBits(GPIOD, LEDS);
        }
    }

// Clear the interrupt flag
 EXTI_ClearITPendingBit(EXTI_Line0);
}
*/
