#include <stdio.h>
#include "ppm.h"

void
main()
{
  int    i, xoff;
  Image *image1, *image2;

 // image1 = ImageCreate(200,100);
  
  //ImageClear(image1, 210,180,40); /* mustard color */
  //ImageWrite(image1, "try1.ppm");
  //printf("created try1.ppm\n");

  image2 = ImageRead("try1.ppm");

  /* put a blue-ish stripe in image */
  for (i = 0; i < 100; i++)
    {
      for (xoff = 45; xoff < 85; xoff++)
	{
	  ImageSetPixel(image2, i+xoff, i, 0, 50);  /* red channel */
	  ImageSetPixel(image2, i+xoff, i, 1, 80);  /* green */
	  ImageSetPixel(image2, i+xoff, i, 2, 250); /* blue */
	}
    }

  ImageWrite(image2, "try2.ppm");
  printf("created try2.ppm\n");
}

