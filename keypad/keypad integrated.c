



/*
with the keypad facing you.
PC1 PC2 PC3 PC5 PB0 PB1 PB2 PB10

set the GPIO pins
    PB0 PB1 PB2 PB10
PC1
PC2
PC3
PC5
*/

#include "tm_stm32f4_gpio.h"
#include "tm_stm32f4_keypad.h"

int main (void)
{
  TM_KEYPAD_Button_t Keypad_Button;
  TM_KEYPAD_Init(TM_KEYPAD_Type_Large);

  /*show the waiting screen IMG0 will be a start screen saying press
  any button to continue*/
  //const Point& p, InputStream& source, what do I put in for these?
  drawFilteredJpeg(JpegImg0Pixels, JpegImg0PixelsSize);
  while (1)
  {    
	keypad_button = keypad_read;
    if (keypad_button != keypad_nopress)
    {
      break;
    }
  }
  /*show the waiting screen IMG1 will be a instruction screen saying numbers
  to switch pictures, letters to apply filter. any button to continue*/
  drawFilteredJpeg(JpegImg1Pixels, JpegImg1PixelsSize);
  while (1)
  {
    keypad_button = keypad_read;
    if (keypad_button != keypad_button_nopress)
    {
        switch (keypad_button)
        {
          case keypad_0:
          // draw the first image.
          drawFilteredJpeg(JpegImg2Pixels, JpegImg2PixelsSize);

          case keypad_1:
          drawFilteredJpeg(JpegImg3Pixels, JpegImg3PixelsSize);

          case keypad_2:
          drawFilteredJpeg(JpegImg4Pixels, JpegImg4PixelsSize);

          case keypad_3:
          drawFilteredJpeg(JpegImg5Pixels, JpegImg5PixelsSize);

          case keypad_4:
          drawFilteredJpeg(JpegImg6Pixels, JpegImg6PixelsSize);

          case keypad_5:
          drawFilteredJpeg(JpegImg7Pixels, JpegImg7PixelsSize);

          case keypad_6:
          drawFilteredJpeg(JpegImg8Pixels, JpegImg8PixelsSize);

          case keypad_7:
          drawFilteredJpeg(JpegImg9Pixels, JpegImg9PixelsSize);

          case keypad_8:
          drawFilteredJpeg(JpegImg10Pixels, JpegImg10PixelsSize);

          case keypad_9:
          drawFilteredJpeg(JpegImg11Pixels, JpegImg11PixelsSize);

          case keypad_A:
          break;

          case keypad_B:
          break;

          case keypad_C:
          break;

          case keypad_D:
          break;

          default:
          break;
          }
          TM_KEYPAD_Update();
        }
      }
      while (1)
      {
        keypad_button = keypad_read();
        if (keypad_button != keypad_nopress)
        {
          switch (keypad_button)
          {
            case keypad_0:
            //draw picture 2 function

            case keypad_1:
            //draw picture 3 function

            case keypad_2:
            //draw picture 4 function

            case keypad_3:
            //draw picture 5 function

            case keypad_4:
            //draw picture 6 function

            case keypad_5:
            //draw picture 7 function

            case keypad_6:
            //draw picture 8 function

            case keypad_7:
            //draw picture 9 function

            case keypad_8:
            //draw picture 10 function

            case keypad_9:
            //draw picture 11 function

            case keypad_star:
            //draw picture 12 function

            case keypad_hash:
            //draw picture 13 function

            case keypad_A:
            //apply filter 1 here

            case keypad_B:
            //apply filter 2 here

            case keypad_C:
            //apply filter 3 here

            case keypad_D:
            //apply filter 4 here
          }
          TM_KEYPAD_Update();
        }
      }
    }
  }


}
