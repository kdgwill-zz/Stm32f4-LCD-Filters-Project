#include <stdio.h>

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "milliSecondTimer.h"
#include "hx8352aGraphicsLibrary.h"
#include "fsmc16BitAccessMode.h"

typedef FSMC16Ref LcdAccessMode;
typedef	GraphLibVar LcdPanel;

LcdAccessMode _accessMode;
LcdPanel _gl;

int main() {
	milliSecTimer_init();

	// reset is on PE1 and RS (D/CX) is on PD11
	GpioPinRef pe = HX8352A_RESET_PIN;RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);//GpioE<DefaultDigitalOutputFeature<1> > pe;
      	GpioPinRef pd = HX8352A_RS_PIN;RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);//GpioD<DefaultFsmcAlternateFunctionFeature<11>> pd;

	// Set up the FSMC timing. These numbers (particularly the data setup time) are dependent on
        // both the FSMC bus speed and the panel timing parameters. If you see corrupted graphics then
        // you may need to adjust these to uit the characteristics of your particular panel.

	Fsmc8080LcdTiming fsmcTiming;initFsmc8080LcdTiming(&fsmcTiming,3,6);


      // set up the FSMC with RS=A16 (PD11)
      fsmc16_structInit(&_accessMode, &fsmcTiming,16,&pe);

      // declare a panel
      initGraphicsLibrary(&_gl, &_accessMode);

      // apply gamma settings
      Gamma12 gamma;initGamma12(gamma,0xA0,0x03,0x00,0x45,0x03,0x47,0x23,0x77,0x01,0x1F,0x0F,0x03);
      hx8352aApplyGamma(&_accessMode, gamma);

      // clear to black while the lights are out
      graphLib_setBackground(&_gl, 0);
      graphLib_clearScreen(&_gl);


      // create the backlight on timer4, channel2 (PD13)
	initHx8352aDefaultBacklight();

}














