/*
 * ImagePixels.asm
 *
 *  Created on: Apr 22, 2015
 *      Author: Kyle D. Williams
 */

//JPEG

	.global JpegIntroPixels
	.global JpegIntroPixelsSize

	.global JpegIntro2Pixels
	.global JpegIntro2PixelsSize

	.global JpegTutPixels
	.global JpegTutPixelsSize

	.global JpegImg1Pixels
	.global JpegImg1PixelsSize

	.global JpegImg2Pixels
	.global JpegImg2PixelsSize

	.global JpegImg3Pixels
	.global JpegImg3PixelsSize

	.global JpegImg4Pixels
	.global JpegImg4PixelsSize

	.global JpegImg5Pixels
	.global JpegImg5PixelsSize

	.global JpegImg6Pixels
	.global JpegImg6PixelsSize

	.global JpegImg7Pixels
	.global JpegImg7PixelsSize

	.global JpegImg8Pixels
	.global JpegImg8PixelsSize

	.global JpegImg9Pixels
	.global JpegImg9PixelsSize

	.global JpegImg10Pixels
	.global JpegImg10PixelsSize

JpegIntroPixels:
	.incbin "img/jpeg/intro.jpg"
	JpegIntroPixelsSize=.-JpegIntroPixels

JpegIntro2Pixels:
	.incbin "img/jpeg/intro2.jpg"
	JpegIntro2PixelsSize=.-JpegIntro2Pixels

JpegTutPixels:
	.incbin "img/jpeg/tut.jpg"
	JpegTutPixelsSize=.-JpegTutPixels

JpegImg1Pixels:
	.incbin "img/jpeg/img1.jpg"
	JpegImg1PixelsSize=.-JpegImg1Pixels

JpegImg2Pixels:
	.incbin "img/jpeg/img2.jpg"
	JpegImg2PixelsSize=.-JpegImg2Pixels

JpegImg3Pixels:
	.incbin "img/jpeg/img3.jpg"
	JpegImg3PixelsSize=.-JpegImg3Pixels

JpegImg4Pixels:
	.incbin "img/jpeg/img4.jpg"
	JpegImg4PixelsSize=.-JpegImg4Pixels

JpegImg5Pixels:
	.incbin "img/jpeg/img5.jpg"
	JpegImg5PixelsSize=.-JpegImg5Pixels

JpegImg6Pixels:
	.incbin "img/jpeg/img6.jpg"
	JpegImg6PixelsSize=.-JpegImg6Pixels

JpegImg7Pixels:
	.incbin "img/jpeg/img7.jpg"
	JpegImg7PixelsSize=.-JpegImg7Pixels

JpegImg8Pixels:
	.incbin "img/jpeg/img8.jpg"
	JpegImg8PixelsSize=.-JpegImg8Pixels

JpegImg9Pixels:
	.incbin "img/jpeg/img9.jpg"
	JpegImg9PixelsSize=.-JpegImg9Pixels

JpegImg10Pixels:
	.incbin "img/jpeg/img10.jpg"
	JpegImg10PixelsSize=.-JpegImg10Pixels






















