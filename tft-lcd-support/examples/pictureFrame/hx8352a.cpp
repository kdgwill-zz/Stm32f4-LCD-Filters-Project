/**
 * NOTE PROGRESSIVE JPEG NOT SUPPOixel16RTED
 *
 * This implementation uses the FMSC perhipheral on bank 1
 * of the STM32f407 discovery board.
 *
 * This LCD is a 16-bit device supporting 65536 colours
 *
 * HX8352A TO STM324f07 pin Connection
 *
 * Board <--> PIN  || BOARD <--> PIN
 * NC	 <-->      || NC    <-->
 * LED_A <--> PD13 || NC    <-->
 * NC	 <-->      || SD_CS <-->
 * RESET <--> PE1  || SD_DIN<-->
 * F_CS	 <-->      || SD_SLK<-->
 * CS	 <--> PD7  || SD_OUT<-->
 * DB15	 <--> PD10 || T_IRQ <-->
 * DB14	 <--> PD9  || T_OUT <-->
 * DB13	 <--> PD8  || NC    <-->
 * DB12	 <--> PE15 || T_DIN <-->
 * DB11	 <--> PE14 || T_CS  <-->
 * DB10	 <--> PE13 || T_CLK <-->
 * DB9	 <--> PE12 || DB7   <--> PE10
 * DB8	 <--> PE11 || DB6   <--> PE9
 * RD	 <--> PD4  || DB5   <--> PE8
 * WR	 <--> PD5  || DB4   <--> PE7
 * RS 	 <--> PD11 || DB3   <--> PD1
 * NC	 <-->      || DB2   <--> PD0
 * VCC	 <--> 3.3V || DB1   <--> PD15
 * GND   <--> GND  || DB0   <--> PD14
 *-------------------------------------------------------------
 *-------------------------------------------------------------
 * STM324f07 TO HX8352A pin Connection
 * Board<-->PIN    || Board<-->PIN 	 ||||| Board <--> PIN || Board <--> PIN
 * 				LEFT BANK			 |||||			 RIGHT BANK
 * GND	<-->	   || GND  <-->		 ||||| GND   <--> GND || GND  <-->
 * VDD	<-->	   || VDD  <-->      ||||| 5V    <-->	  || 5V   <-->
 * GND	<-->       || NRST <-->      ||||| 3V    <--> VCC || 3V   <-->
 * PC1	<-->       || PC0  <-->      ||||| PH0   <-->     || PH1  <-->
 * PC3	<-->       || PC2  <-->      ||||| PC14  <-->     || PC15 <-->
 * PA1	<-->       || PA0  <-->      ||||| PE6   <-->     || PC13 <-->
 * PA3	<-->       || PA2  <-->      ||||| PE4   <-->     || PE5  <-->
 * PA5	<-->       || PA4  <-->      ||||| PE2   <-->     || PE3  <-->
 * PA7	<-->       || PA6  <-->      ||||| PE0   <-->     || PE1  <--> RESET
 * PC5	<-->       || PC4  <-->      ||||| PB8   <-->     || PB9  <-->
 * PB1	<-->       || PB0  <-->      ||||| BOOT0 <-->     || VDD  <-->
 * GND	<-->       || PB2  <-->      ||||| PB6	<-->      || PB7  <-->
 * PE7	<--> DB4   || PE8  <--> DB5  ||||| PB4   <-->     || PB5  <-->
 * PE9	<--> DB6   || PE10 <--> DB7  ||||| PD7   <--> CS  || PB3  <-->
 * PE11	<--> DB8   || PE12 <--> DB9  ||||| PD5   <--> WR  || PD6  <-->
 * PE13	<--> DB10  || PE14 <--> DB11 ||||| PD3   <-->     || PD4  <--> RD
 * PE15	<--> DB12  || PB10 <-->   	 ||||| PD1   <--> DB3 || PD2  <-->
 * PB11	<-->       || PB12 <-->   	 ||||| PC12  <-->     || PD0  <--> DB2
 * PB13	<-->       || PB14 <-->   	 ||||| PC10  <-->     || PC11 <-->
 * PB15	<-->       || PD8  <--> DB13 ||||| PA14  <-->     || PA15 <-->
 * PD9	<--> DB14  || PD10 <--> DB15 ||||| PA10  <-->     || PA13 <-->
 * PD11	<--> RS    || PD12 <-->   	 ||||| PA8   <-->     || PA9  <-->
 * PD13	<--> LED_A || PD14 <--> DB0  ||||| PC8   <-->     || PC9  <-->
 * PD15	<--> DB1   || NC   <-->   	 ||||| PC6   <-->     || PC7  <-->
 * GND	<-->       || GND  <-->   	 ||||| GND   <-->     || GND  <-->
 *-------------------------------------------------------------
 *-------------------------------------------------------------
 * LCD signals 		Signal description
 * RS 			LCD Register Select,Instruction/Data, 0 Registers 1 display data(RAM)
 * D0-D15 		Data D0-D15
 * CS 			Chip Select
 * RD 			Read operation: active low write ie 0 to write else 1
 * WR 			Write operation: active low write ie 0 to write else 1
 * LED_A		BACKLIGHT
 * CS			CHIP SELECT	active low 0
 * RESET		Reset the controller chip
 */

#include "config/stm32plus.h"
#include "config/display/tft.h"
//
#include "config/button.h"

#include "tm_stm32f4_gpio.h"
#include "tm_stm32f4_keypad.h"

extern uint32_t JpegIntroPixels, JpegIntroPixelsSize;
extern uint32_t JpegIntro2Pixels, JpegIntro2PixelsSize;
extern uint32_t JpegTutPixels, JpegTutPixelsSize;

extern uint32_t JpegImg1Pixels, JpegImg1PixelsSize;
extern uint32_t JpegImg2Pixels, JpegImg2PixelsSize;
extern uint32_t JpegImg3Pixels, JpegImg3PixelsSize;
extern uint32_t JpegImg4Pixels, JpegImg4PixelsSize;
extern uint32_t JpegImg5Pixels, JpegImg5PixelsSize;
extern uint32_t JpegImg6Pixels, JpegImg6PixelsSize;
extern uint32_t JpegImg7Pixels, JpegImg7PixelsSize;
extern uint32_t JpegImg8Pixels, JpegImg8PixelsSize;
extern uint32_t JpegImg9Pixels, JpegImg9PixelsSize;
extern uint32_t JpegImg10Pixels, JpegImg10PixelsSize;

using namespace stm32plus;
using namespace stm32plus::display;
//using namespace rteProject;
//using namespace rteProject::display;

class HX8352ATest {

protected:
	typedef Fsmc16BitAccessMode<FsmcBank1NorSram1> LcdAccessMode;
	typedef TM032LDH05_Portrait_64K<LcdAccessMode> LcdPanel;

	LcdAccessMode *_accessMode;
	LcdPanel *_gl;
	Font *_font;

	typedef typename LcdPanel::UnpackedColour UnpackedColour; ///< Helper type for the unpacked colour structure
	typedef typename LcdPanel::tCOLOUR tCOLOUR; ///< Helper type for the packed colour type

public:
	void run() {

		// reset is on PE1 and RS (D/CX) is on PD11

		GpioE<DefaultDigitalOutputFeature<1> > pe;
		GpioD<DefaultFsmcAlternateFunctionFeature<11>> pd;

		/*
		 * Set up the FSMC timing. These numbers (particularly the data setup time) are dependent on
		 * both the FSMC bus speed and the panel timing parameters. If you see corrupted graphics then
		 * you may need to adjust these to uit the characteristics of your particular panel.
		 *
		 * This is specifications found for the f4
		 * Fsmc8080LcdTiming fsmcTiming(0,3);//3, 6);
		 *
		 * Calculate the FSMC Timing With the Following Equations
		 * FSMC Access Mode = ModeB
		 * ((ADDSET + 1) + (DATAST + 1)) × HCLK = max(tCYC, tCYC(READ))
		 * DATAST × HCLK = tWRLW
		 * DATAST must verify:
		 * DATAST = (((tACC + tAS ) + (tsu(Data_NE)+ tv(A_NE)))/HCLK) – ADDSET – 4
		 * Where:
		 * tsu(Data_NE): FSMC_NEx low to data valid
		 * tv(A_NE): FSMC_NEx low to FSMC_A
		 * (tsu(Data_NE)+ tv(A_NE)) = 36 ns
		 * The Parameters are
		 * HCLK = 168 MHz = 5.952ns -> 6
		 * tAH 			Address hold time 			10  ns
		 * tAS 			Address setup time 			10  ns
		 * tCYC(WRITE)	System cycle time 			100 ns
		 * tCYC(READ) 	System cycle time (Read) 	250 ns
		 * tWRLW 		Low pulse width for write 	20  ns
		 * tWRLR 		Low pulse width for read 	150 ns
		 * tWRHW 		High pulse width for write 	20  ns
		 * tWRHR		High pulse width for read 	50  ns
		 * tDS 			Data setup time 			20  ns
		 * tDH 			Data hold time 				20  ns
		 * tACC 		Data access time 			100 ns
		 *
		 */
		//Hx8352A
		Fsmc8080LcdTiming fsmcWriteTiming(3, 6);
		//Fsmc8080LcdTiming fsmcReadTiming(15, 25);
		//Fsmc8080LcdTiming fsmcWriteTiming(11, 15);

		//ILI9325

		// set up the FSMC with RS=A16 (PD11)
		//_accessMode = new LcdAccessMode(fsmcReadTiming,fsmcWriteTiming, 16, pe[1]);
		_accessMode = new LcdAccessMode(fsmcWriteTiming, 16, pe[1]);

		// declare a panel
		_gl = new LcdPanel(*_accessMode);

		// clear to black while the lights are out
		_gl->setBackground(ColourNames::BLACK);
		_gl->clearScreen();

		// Note: Default list in "lib/include/display/graphic/fonts"
		//Use FontConv utility to create more
		_font = new Font_ATARIST8X16SYSTEMFONT16;
		*_gl << *_font;
		//pb0 pb1 pb2 pb10
		//pc1 pc2 pc3 pc5
		testing();
		//INITIALSE BUTTONS
		// initialise the ports
		TM_KEYPAD_Button_t keypad_button;
		TM_KEYPAD_Init(TM_KEYPAD_Type_Large);
//////////////////////////////////////////////////////////////////////////////////////
		// create the backlight on timer4, channel2 (PD13)
		DefaultBacklight backlight;
		drawJpg(JpegIntroPixels, JpegIntroPixelsSize);
		// fade up to 100% in 4ms steps
		backlight.fadeTo(100, 4);
		MillisecondTimer::delay(4000);
//		//load startup frame
		drawJpg(JpegIntro2Pixels, JpegIntro2PixelsSize);
		while (TM_KEYPAD_Read() == TM_KEYPAD_Button_NOPRESSED)
			;
		prompt("Welcome");
		prompt("Loading...");
		prompt("Okay Not Really");
		//load Tutorial frame
		drawJpg(JpegTutPixels, JpegTutPixelsSize);
		bool init = false;
		uint32_t * jpgPix = 0;
		uint32_t * jpgSize = 0;
		while (1) {
			keypad_button = TM_KEYPAD_Read();
			if (keypad_button != TM_KEYPAD_Button_NOPRESSED) {
				switch (keypad_button) {
				case TM_KEYPAD_Button_0:
					if (init == false)
						init = true;
					jpgPix = &JpegImg10Pixels;
					jpgSize = &JpegImg10PixelsSize;
					drawJpg(*jpgPix, *jpgSize);
					break;
				case TM_KEYPAD_Button_1:
					if (init == false)
						init = true;
					jpgPix = &JpegImg1Pixels;
					jpgSize = &JpegImg1PixelsSize;
					drawJpg(*jpgPix, *jpgSize);
					break;
				case TM_KEYPAD_Button_2:
					if (init == false)
						init = true;
					jpgPix = &JpegImg2Pixels;
					jpgSize = &JpegImg2PixelsSize;
					drawJpg(*jpgPix, *jpgSize);
					break;
				case TM_KEYPAD_Button_3:
					if (init == false)
						init = true;
					jpgPix = &JpegImg3Pixels;
					jpgSize = &JpegImg3PixelsSize;
					drawJpg(*jpgPix, *jpgSize);
					break;

				case TM_KEYPAD_Button_4:
					if (init == false)
						init = true;
					jpgPix = &JpegImg4Pixels;
					jpgSize = &JpegImg4PixelsSize;
					drawJpg(*jpgPix, *jpgSize);
					break;

				case TM_KEYPAD_Button_5:
					if (init == false)
						init = true;
					jpgPix = &JpegImg5Pixels;
					jpgSize = &JpegImg5PixelsSize;
					drawJpg(*jpgPix, *jpgSize);
					break;

				case TM_KEYPAD_Button_6:
					if (init == false)
						init = true;
					jpgPix = &JpegImg6Pixels;
					jpgSize = &JpegImg6PixelsSize;
					drawJpg(*jpgPix, *jpgSize);
					break;

				case TM_KEYPAD_Button_7:
					if (init == false)
						init = true;
					jpgPix = &JpegImg7Pixels;
					jpgSize = &JpegImg7PixelsSize;
					drawJpg(*jpgPix, *jpgSize);
					break;

				case TM_KEYPAD_Button_8:
					if (init == false)
						init = true;
					jpgPix = &JpegImg8Pixels;
					jpgSize = &JpegImg8PixelsSize;
					drawJpg(*jpgPix, *jpgSize);
					break;

				case TM_KEYPAD_Button_9:
					if (init == false)
						init = true;
					jpgPix = &JpegImg9Pixels;
					jpgSize = &JpegImg9PixelsSize;
					drawJpg(*jpgPix, *jpgSize);
					break;

				case TM_KEYPAD_Button_A:
					if (init == false)
						continue;
					drawJpg(*jpgPix, *jpgSize);
					greyScale();
					break;
				case TM_KEYPAD_Button_B:
					if (init == false)
						continue;
					drawJpg(*jpgPix, *jpgSize);
					sobelEdgeDetection();
					break;
				case TM_KEYPAD_Button_C:
					if (init == false)
						continue;
					drawJpg(*jpgPix, *jpgSize);
					sobelEdgeDetection(false);
					break;
				case TM_KEYPAD_Button_D:
					if (init == false)
						continue;
					drawJpg(*jpgPix, *jpgSize);
					invertColour();
					break;
				case TM_KEYPAD_Button_STAR:
					if (init == false)
						continue;
					drawJpg(*jpgPix, *jpgSize);
					swap();
					break;
				case TM_KEYPAD_Button_HASH:
					if (init == false)
						continue;
					drawJpg(*jpgPix, *jpgSize);
					simplePencilEdgeDetection();
					break;
				default:
					prompt("N/A");
					break;
				}
				TM_KEYPAD_Update();
			}
		}
	}

public:

	void testing() {
		//uint32_t timer = 0;
		DefaultBacklight backlight;
		// fade up to 100% in 4ms steps
		backlight.fadeTo(100, 4);
		//grey
		int grey = MillisecondTimer::millis();
		drawJpg(JpegImg3Pixels, JpegImg3PixelsSize);
		this->greyScale();
		grey = MillisecondTimer::difference(grey);
		//invertColour
		int invertColour = MillisecondTimer::millis();
		drawJpg(JpegImg3Pixels, JpegImg3PixelsSize);
		this->invertColour();
		invertColour = MillisecondTimer::difference(invertColour);
		//simple pencil edge detection
		int spe = MillisecondTimer::millis();
		drawJpg(JpegImg3Pixels, JpegImg3PixelsSize);
		this->simplePencilEdgeDetection();
		spe = MillisecondTimer::difference(spe);
		//sobel edge detection
		int sbe = MillisecondTimer::millis();
		drawJpg(JpegImg3Pixels, JpegImg3PixelsSize);
		this->sobelEdgeDetection();
		sbe = MillisecondTimer::difference(sbe);
		//swap
		int swap = MillisecondTimer::millis();
		drawJpg(JpegImg3Pixels, JpegImg3PixelsSize);
		this->swap();
		swap = MillisecondTimer::difference(swap);
		//xray
		int xray = MillisecondTimer::millis();
		drawJpg(JpegImg3Pixels, JpegImg3PixelsSize);
		this->xray();
		xray = MillisecondTimer::difference(xray);

		_gl->setBackground(ColourNames::BLACK);
		_gl->setForeground(ColourNames::WHITE);
		_gl->clearScreen();
		char str[100];
		sprintf(str, "Filter Timing Report");
		*_gl << Point(0, 0) << str;
		sprintf(str, "%-15s| Time (ms)", "Filter");
		*_gl << Point(0, 25) << str;
		sprintf(str, "%-15s| %d ", "Grey", grey);
		*_gl << Point(0, 50) << str;
		sprintf(str, "%-15s| %d", "Invert", invertColour);
		*_gl << Point(0, 75) << str;
		sprintf(str, "%-15s| %d", "Simple Edge", spe);
		*_gl << Point(0, 100) << str;
		sprintf(str, "%-15s| %d", "Sobel's Edge", sbe);
		*_gl << Point(0, 125) << str;
		sprintf(str, "%-15s| %d", "Swap", swap);
		*_gl << Point(0, 150) << str;
		sprintf(str, "%-15s| %d", "X-ray", xray);
		*_gl << Point(0, 175) << str;

		while (1) {
		};
	}

	void drawJpg(uint32_t & jpgPix, uint32_t & jpgSize) {
		LinearBufferInputOutputStream source((uint8_t *) &jpgPix,
				(uint32_t) &jpgSize);
		_gl->drawJpeg(_gl->getFullScreenRectangle(), source);
	}

	void prompt(const char *prompt) {

		_gl->setBackground(ColourNames::BLACK);
		_gl->clearScreen();

		_gl->setForeground(ColourNames::WHITE);
		*_gl << Point(0, 0) << prompt;

		MillisecondTimer::delay(2000);
		_gl->clearScreen();
	}

//Colored or not colored
	void sobelEdgeDetection(bool isColour = true) {
		int kernelX[3][3];
		int kernelY[3][3];

		int sumX[3];
		int sumY[3];
		int SUM[3];
		int posX = 0;
		int posY = 0;
		//uint8_t R, G, B = 0;
		int I, J = 0;

		//UnpackedColour pixVal;
		// allocate space for even scan lines and odd scan lines
		uint16_t *currentRow = new uint16_t[_gl->getWidth()];
		//buffer for previous line
		// allocate space for even scan lines and odd scan lines
		uint16_t *prevRow = new uint16_t[_gl->getWidth()];
		// Masks //////////////////////////////////////
		//X//
		kernelX[0][0] = -1;
		kernelX[0][1] = 0;
		kernelX[0][2] = 1;
		kernelX[1][0] = -2;
		kernelX[1][1] = 0;
		kernelX[1][2] = 2;
		kernelX[2][0] = -1;
		kernelX[2][1] = 0;
		kernelX[2][2] = 1;
		//Y//
		kernelY[0][0] = 1;
		kernelY[0][1] = 2;
		kernelY[0][2] = 1;
		kernelY[1][0] = 0;
		kernelY[1][1] = 0;
		kernelY[1][2] = 0;
		kernelY[2][0] = -1;
		kernelY[2][1] = -2;
		kernelY[2][2] = -1;

		for (int Y = 0; Y < _gl->getHeight(); Y++) {
			for (int X = 0; X < _gl->getWidth(); X++) {
				sumX[0] = sumX[1] = sumX[2] = 0;
				sumY[0] = sumY[1] = sumY[2] = 0;

				if (Y == 0 || Y == _gl->getHeight() - 1) {
					SUM[0] = SUM[1] = SUM[2] = 0;
				} else if (X == 0 || X == _gl->getWidth() - 1) {
					SUM[0] = SUM[1] = SUM[2] = 0;
				} else {
					for (I = -1; I <= 1; I++) {
						for (J = -1; J <= 1; J++) {
							posX = J + X;
							posY = I + Y;
							pixel16 pix = getPixel(posX, posY);
							if (isColour) {
								uint8_t Red = pix.Red;
								uint8_t Green = pix.Green;
								uint8_t Blue = pix.Blue;

								sumX[0] += (Red) * kernelX[J + 1][I + 1];
								sumX[1] += (Green) * kernelX[J + 1][I + 1];
								sumX[2] += (Blue) * kernelX[J + 1][I + 1];

								sumY[0] += (Red) * kernelY[J + 1][I + 1];
								sumY[1] += (Green) * kernelY[J + 1][I + 1];
								sumY[2] += (Blue) * kernelY[J + 1][I + 1];
							} else {
								int NC = (pix.Red + pix.Red + pix.Red) / 3;
								sumX[0] = sumX[0]
										+ (NC) * kernelX[J + 1][I + 1];
								sumY[0] = sumY[0]
										+ (NC) * kernelY[J + 1][I + 1];
							}

						}
					}

					SUM[0] = abs(sumX[0]) + abs(sumY[0]);
					SUM[1] = abs(sumX[1]) + abs(sumY[1]);//will only waste if not colour
					SUM[2] = abs(sumX[2]) + abs(sumY[2]);//will only waste if not colour
				}
				SUM[0] = min(max(SUM[0], 0), 255);
				SUM[1] = min(max(SUM[1], 0), 255);//will only waste cycles if not colour
				SUM[2] = min(max(SUM[2], 0), 255);//will only waste cycles if not colour

				int newPixel[3];
				newPixel[0] = (255 - ((unsigned char) (SUM[0])));
				newPixel[1] = (255 - ((unsigned char) (SUM[1])));
				newPixel[2] = (255 - ((unsigned char) (SUM[2])));
				if (isColour) {
					currentRow[X] =
							packColour(
									pixel16(newPixel[0], newPixel[1],
											newPixel[2])).packed565;
				} else {
					currentRow[X] = packColour(
							pixel16(newPixel[0], newPixel[0], newPixel[0]), 2,
							2, 2).packed565;
				}
			}
			//Need to move cursor back
			// draw it
			//this->paintRow(Point(0, Y), buffer, _gl->getWidth());

			if (Y > 0) // draw the previous row if this is not the first row:
				this->paintRow(Point(0, Y - 1), prevRow, _gl->getWidth());
			if (Y == _gl->getHeight() - 1) // draw the current row if it is the last:
				this->paintRow(Point(0, Y), currentRow, _gl->getWidth());
			// swap row pointers:
			uint16_t *temp = prevRow;
			prevRow = currentRow;
			currentRow = temp;
		}
		delete[] currentRow;
		delete[] prevRow;
	}

	void simplePencilEdgeDetection(bool greyScaled = false) {

		float kernel[3][3];

		float sumX[3];
		float SUM[3];
		int posX = 0;
		int posY = 0;
		int I, J = 0;

		//UnpackedColour pixVal;
		// allocate space for even scan lines and odd scan lines
		uint16_t *currentRow = new uint16_t[_gl->getWidth()];
		//buffer for previous line
		// allocate space for even scan lines and odd scan lines
		uint16_t *prevRow = new uint16_t[_gl->getWidth()];

		kernel[0][0] = -1;
		kernel[0][1] = -1;
		kernel[0][2] = 0;
		kernel[1][0] = -1;
		kernel[1][1] = 0;
		kernel[1][2] = 1;
		kernel[2][0] = 0;
		kernel[2][1] = 1;
		kernel[2][2] = 1;

		float factor = 1.0;
		float bias = 128.0;

		if (greyScaled) {
			greyScale();

		}
		for (int Y = 0; Y < _gl->getHeight(); Y++) {
			for (int X = 0; X < _gl->getWidth(); X++) {
				sumX[0] = sumX[1] = sumX[2] = 0;

				if (Y == 0 || Y == _gl->getHeight() - 1) {
					SUM[0] = SUM[1] = SUM[2] = 0;
				} else if (X == 0 || X == _gl->getWidth() - 1) {
					SUM[0] = SUM[1] = SUM[2] = 0;
				} else {
					for (I = -1; I <= 1; I++) {
						for (J = -1; J <= 1; J++) {
							posX = J + X;
							posY = I + Y;
							pixel16 pix = getPixel(posX, posY);

							uint8_t Red = pix.Red;
							uint8_t Green = pix.Green;
							uint8_t Blue = pix.Blue;

							sumX[0] += (Red) * kernel[J + 1][I + 1];
							sumX[1] += (Green) * kernel[J + 1][I + 1];
							sumX[2] += (Blue) * kernel[J + 1][I + 1];

						}
					}

					SUM[0] = abs(sumX[0]);
					SUM[1] = abs(sumX[1]);
					SUM[2] = abs(sumX[2]);
				}
				int newPixel[3];
				//truncate values smaller than zero and larger than 255
				newPixel[0] = min(max(int(factor * SUM[0] + bias), 0), 255);
				newPixel[1] = min(max(int(factor * SUM[1] + bias), 0), 255);
				newPixel[2] = min(max(int(factor * SUM[2] + bias), 0), 255);
				currentRow[X] =
						packColour(
								pixel16(newPixel[0], newPixel[1], newPixel[2])).packed565;

			}
			//Need to move cursor back
			// draw it
			//this->paintRow(Point(0, Y), buffer, _gl->getWidth());

			if (Y > 0) // draw the previous row if this is not the first row:
				this->paintRow(Point(0, Y - 1), prevRow, _gl->getWidth());
			if (Y == _gl->getHeight() - 1) // draw the current row if it is the last:
				this->paintRow(Point(0, Y), currentRow, _gl->getWidth());
			// swap row pointers:
			uint16_t *temp = prevRow;
			prevRow = currentRow;
			currentRow = temp;
		}
		delete[] currentRow;
		delete[] prevRow;
	}

	void greyScale(const Point& p = Point::Origin, int level = 0) {
		//Can use use _gl.writePixel(cr); and draw as you go or
		//simply use a buffer and draw after each row lets try buffer for now
		//Lets try a simply getting the pixels and drawing them back on screen
		uint16_t *buffer;
		//UnpackedColour colour;
		// allocate space for even scan lines and odd scan lines
		buffer = new uint16_t[_gl->getWidth()];
		for (uint16_t vpos = p.Y; vpos < _gl->getHeight(); vpos++) {
			//Move Cursor into position for proper reading
			moveTo2D(p.X, vpos);
			for (uint16_t hpos = p.X + 1; hpos < _gl->getWidth(); hpos++) {
				pixel16 pixel(_accessMode->readData());
				float grey;
				if (level == 0) {
					//Best looking grey scale
					grey = (pixel.Red * 0.299 + pixel.Green * 0.587
							+ pixel.Blue * 0.114);			//BT.601
				} else if (level == 1) {
					//This greyscale will be a little darker
					grey = (pixel.Red + pixel.Red + pixel.Red) / 3;
				} else {
					//This grayscale will be traditional and seem washed out
					grey = ((0.2126 * pixel.Red) + (0.7152 * pixel.Green)
							+ (0.0722 * pixel.Blue)) / 3;			//BT.709
				}
				pixel.Red = pixel.Green = pixel.Blue = (uint8_t) grey;
				buffer[hpos] = packColour(pixel, 2, 2, 2).packed565;//packColour(pixel,2,3,2);
			}
			//Need to move cursor back to begining of row for writing
			// draw it
			paintRow(Point(p.X, vpos), buffer, _gl->getWidth());
		}
		delete[] buffer;
	}

	void invertColour(const Point& p = Point::Origin) {
		uint16_t *buffer;
		buffer = new uint16_t[_gl->getWidth()];
		for (uint16_t vpos = p.Y; vpos < _gl->getHeight(); vpos++) {
			//Move Cursor into position for proper reading
			moveTo2D(p.X, vpos);
			for (uint16_t hpos = p.X + 1; hpos < _gl->getWidth(); hpos++) {
				uint16_t colour = ~_accessMode->readData();
				//uint16_t newColour =  0xFFFF - oldColour;
				buffer[hpos] = colour;
			}
			//Need to move cursor back to begining of row for writing
			// draw it
			paintRow(Point(p.X, vpos), buffer, _gl->getWidth());
		}
		delete[] buffer;
	}

	void swap(const Point& p = Point::Origin) {
		uint16_t *buffer;
		buffer = new uint16_t[_gl->getWidth()];
		for (uint16_t vpos = p.Y; vpos < _gl->getHeight(); vpos++) {
			//Move Cursor into position for proper reading
			moveTo2D(p.X, vpos);
			for (uint16_t hpos = p.X + 1; hpos < _gl->getWidth(); hpos++) {
				pixel16 pixel(_accessMode->readData());
				uint8_t t = pixel.Blue;
				pixel.Blue = pixel.Red;
				pixel.Red = t;
				buffer[hpos] = packColour(pixel).packed565;
			}
			//Need to move cursor back to begining of row for writing
			// draw it
			paintRow(Point(p.X, vpos), buffer, _gl->getWidth());
		}
		delete[] buffer;
	}

//Technically this is a broken sobel's edge filter
	void xray() {
		int FilterX[3][3];
		int FilterY[3][3];
		int sumX[3];
		int sumY[3];
		int SUM[3];
		int posX = 0;
		int posY = 0;
		uint8_t R, G, B = 0;
		int I, J = 0;

		UnpackedColour pixVal;
		uint16_t *buffer;
		// allocate space for even scan lines and odd scan lines
		buffer = new uint16_t[_gl->getWidth()];
		// Masks //////////////////////////////////////
		//X//
		FilterX[0][0] = -1;
		FilterX[0][1] = 0;
		FilterX[0][2] = 1;
		FilterX[1][0] = -2;
		FilterX[1][1] = 0;
		FilterX[1][2] = 2;
		FilterX[2][0] = -1;
		FilterX[2][1] = 0;
		FilterX[2][2] = 1;
		//Y//
		FilterY[0][0] = 1;
		FilterY[0][1] = 2;
		FilterY[0][2] = 1;
		FilterY[1][0] = 0;
		FilterY[1][1] = 0;
		FilterY[1][2] = 0;
		FilterY[2][0] = -1;
		FilterY[2][1] = -2;
		FilterY[2][2] = -1;

		for (int Y = 0; Y < _gl->getHeight(); Y++) {
			for (int X = 0; X < _gl->getWidth(); X++) {
				sumX[0] = sumX[1] = sumX[2] = 0;
				sumY[0] = sumY[1] = sumY[2] = 0;

				if (Y == 0 || Y == _gl->getHeight() - 1) {
					SUM[0] = SUM[1] = SUM[2] = 0;
				} else if (X == 0 || X == _gl->getWidth() - 1) {
					SUM[0] = SUM[1] = SUM[2] = 0;
				} else {
					for (I = -1; I <= 1; I++) {
						for (J = -1; J <= 1; J++) {
							posX = J + X;
							posY = I + Y;

							pixel16 pix = getPixel(posX, posY);
							R = pix.Red;
							G = pix.Green;
							B = pix.Blue;

							sumX[0] += (R) * FilterX[J + 1][I + 1];
							sumX[1] += (G) * FilterX[J + 1][I + 1];
							sumX[2] += (B) * FilterX[J + 1][I + 1];

							sumY[0] += (R) * FilterY[J + 1][I + 1];
							sumY[1] += (G) * FilterY[J + 1][I + 1];
							sumY[2] += (B) * FilterY[J + 1][I + 1];
						}
					}

					SUM[0] = abs(sumX[0]) + abs(sumY[0]);
					SUM[1] = abs(sumX[1]) + abs(sumY[1]);
					SUM[2] = abs(sumX[2]) + abs(sumY[2]);
				}
				SUM[0] = min(max(SUM[0], 0), 255);
				SUM[1] = min(max(SUM[1], 0), 255);
				SUM[2] = min(max(SUM[2], 0), 255);

				int newPixel[3];
				newPixel[0] = (255 - ((unsigned char) (SUM[0])));
				newPixel[1] = (255 - ((unsigned char) (SUM[1])));
				newPixel[2] = (255 - ((unsigned char) (SUM[2])));

				_gl->unpackColour(newPixel[0] >> 2, newPixel[1] >> 2,
						newPixel[3] >> 2, pixVal);
				buffer[X] = pixVal.packed565;
			}
			//Need to move cursor back
			// draw it
			this->paintRow(Point(0, Y), buffer, _gl->getWidth());
		}
		delete[] buffer;
	}

private:
	typedef struct pixel16 {
		uint8_t Red;
		uint8_t Green;
		uint8_t Blue;
		uint16_t val;
		pixel16(uint8_t red, uint8_t green, uint8_t blue) :
				Red(red), Green(green), Blue(blue) {
			val = 0;
			val |= (Red << 11);
			val |= (Green << 5);
			val |= (Blue);
		}
		pixel16(UnpackedColour colour) {		//can pass colour
			val = colour.packed565;
			Red = (colour.packed565 >> (11)) & 0x1F;
			Green = (colour.packed565 >> 5) & 0x3F;
			Blue = colour.packed565 & 0x1F;
		}
		pixel16(uint16_t packed565) {	//can also pass read data directly
			val = packed565;
			Red = (packed565 >> (11)) & 0x1F;
			Green = (packed565 >> 5) & 0x3F;
			Blue = packed565 & 0x1F;
		}
	} pixel16;
	UnpackedColour packColour(pixel16 pixel, uint8_t shiftRed = 3,
			uint8_t shiftGreen = 2, uint8_t shiftBlue = 3) {
		UnpackedColour colour;
		_gl->unpackColour(pixel.Red << shiftRed, pixel.Green << shiftGreen,
				pixel.Blue << shiftBlue, colour);
		return colour;
	}
	void paintRow(Point start, const void *buffer, uint32_t numPixels) {
		_gl->moveToPoint(start);
		_gl->beginWriting();
		_gl->rawTransfer(buffer, numPixels);
	}
	void moveTo1D(int i) {
		//later use loop instead of modulus
		int width = _gl->getWidth();
		int x = i % width;
		int y = i / width;
		moveTo2D(x, y);

	}
	void moveTo2D(int x, int y) {
		//Move Cursor into position for proper reading
		_gl->moveToPoint(Point(x, y));
		_gl->beginWriting();
	}
	pixel16 getPixel(int pos) {
		moveTo1D(pos);
		pixel16 pixel(_accessMode->readData());
		return pixel;
	}
	pixel16 getPixel(int x, int y) {
		moveTo2D(x, y);
		pixel16 pixel(_accessMode->readData());
		return pixel;
	}

	void setPixel(int x, int y, pixel16 pixel, uint8_t shiftRed = 3,
			uint8_t shiftGreen = 2, uint8_t shiftBlue = 3) {
		UnpackedColour colour = packColour(pixel, shiftRed, shiftGreen,
				shiftBlue);
		setPixel(x, y, colour);
	}

	void setPixel(int x, int y, UnpackedColour colour) {
		moveTo2D(x, y);
		_gl->writePixel(colour);
	}

	double exp(float x) {
		x = 1.0 + x / 1024;
		x *= x;
		x *= x;
		x *= x;
		x *= x;
		x *= x;
		x *= x;
		x *= x;
		x *= x;
		x *= x;
		x *= x;
		return x;
	}
	float sqrt(float x) {
		unsigned int i = *(unsigned int*) &x;

		// adjust bias
		i += 127 << 23;
		// approximation of square root
		i >>= 1;

		return *(float*) &i;
	}
	int ceil(float num) {
		int inum = (int) num;
		if (num == (float) inum) {
			return inum;
		}
		return inum + 1;
	}
	float floor(float value) {
		if (value < 0) {
			return ((float) (0 - (float) ((int) (0 - value))));
		} else {
			return ((float) ((int) value));
		}
	}

	float round(float d) {
		return floor(d + 0.5);
	}

	float min(float v1, float v2) {
		return v1 < v2 ? v1 : v2;
	}
	float max(float v1, float v2) {
		return v1 > v2 ? v1 : v2;
	}

	const double M_PI = 3.14159265358979323846;

// Convert RGB to gray Level int
	int colorToInt(UnpackedColour & colour) {
		colour.packed565 = _accessMode->readData();
		uint8_t Red = (colour.packed565 >> (11)) & 0x1F;
		uint8_t Green = (colour.packed565 >> 5) & 0x3F;
		uint8_t Blue = colour.packed565 & 0x1F;
		return colorToInt(Red, Green, Blue);
	}

	int colorToInt(pixel16 & pix) {
		return colorToInt(pix.Red, pix.Green, pix.Blue);
	}

	int colorToInt(uint8_t Red, uint8_t Green, uint8_t Blue) {
		return (Red + Green + Blue) / 3;
	}
}
;

/*
 * Main entry point
 */

int main() {

// set up SysTick at 1ms resolution
	MillisecondTimer::initialise();

	HX8352ATest test;
	test.run();

// not reached
	return 0;
}
