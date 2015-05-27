#ifndef PPM_H
#define PPM_H

#include <sys/types.h>

typedef struct Image
{
  int width;
  int height;
  u_char *data;
} Image;

Image *ImageCreate(int width, int height);
Image *ImageRead(char *filename);
void   ImageWrite(Image *image, char *filename);

int    ImageWidth(Image *image);
int    ImageHeight(Image *image);

void   ImageClear(Image *image, u_char red, u_char green, u_char blue);

void   ImageSetPixel(Image *image, int x, int y, int chan, u_char val);
u_char ImageGetPixel(Image *image, int x, int y, int chan);

#endif /* PPM_H */

