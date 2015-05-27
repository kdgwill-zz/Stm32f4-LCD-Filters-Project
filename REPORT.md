#Abstract

> Digital image processing is the use of computer algorithms to perform image processing on digital images. As a subcategory or field of digital signal processing, digital image processing has many advantages over analog image processing. It allows a much wider range of algorithms to be applied to the input data and can avoid problems such as the build-up of noise and signal distortion during processing. Since images are defined over two dimensions (perhaps more) digital image processing may be modeled in the form of multidimensional systems. ~[Wikipedia.com][ABSTRACT-1]


---


#Table of Contents

[TOC]


---

The Fraida Frame: A digital picture filter frame
=================================================

## Team

1. Kyle D. Williams **([kdw281@nyu.edu][PROFILE-Williams])**

2. Sravani Koppula **([sbk411@nyu.edu][PROFILE-Koppula])**

3. Vikyath Goli **([vg933@nyu.edu][PROFILE-Goli])**

4. Johnny Chu **([jc6875@nyu.edu][PROFILE-Chu])**

---

#Introduction

---

Using an embedded platform along with a generic LCD screen a digital picture frame was created that applied basic image filters to a displayed image.

---

#Motivation

---

Back in the day, when you took photos, the whole process was an experience. You try your best to frame your shots, wait a week for them to develop, and still, almost all of them would be terrible. But, for those few pictures that do turn out perfect; you would frame them and the moment someone notices you regale them with the tale of how the stars aligned that day to make everything perfect or all the little things that almost ruined the shot.

Our group aims to return the image sharing experience back to being a conversation starter rather than the complement fishing that it has now become. Our plan to accomplish this task is to update the phtoframe by providing it with the ability to have more than just one image and be able to dynamically filter the images for various effects. We hope that by includeing the filters that have made image aggregate sites like imgr and instagram so popular, we can also bring back the wide spread use of digital picture frames.

For this project we will be using the required STM32f4 microcontroller and trying to achieveing two key functions with it: presenting an image and filtering an image. The filtering an image portion will be done through code and will most likely require the use of a library. For achieveing the presenting an image portion, we will be adding on a LCD screen to the microcontroller. We also have to provide some way of cycling through the various filters and images, which can be done through the on board user button or with a keypad.

---

#Articles of Interest

---

* [Image Filter][AOI-Image-Filter]

* [CgTutor Filtering][AOI-Image-CgTutor-Filtering]

* [Understanding LCD Modules][AOI-LCD-Module]

---

#Hardware

---


## Materials

1. [STM32F4 Discovery board][MAT-MainBoard]
2. [LCD Screen][MAT-LCD]
3. [Female to Female Jumper cables][MAT-JUMP]
4. [4x4 Matrix Keypad][MAT-KEY]
5. [Micro-USB to USB][MAT-USB-Adapter]



### Connection diagram for LCD
```
* HX8352A TO STM324f07 pin Connection
*
* Board <--> PIN  || BOARD  <--> PIN
* NC	  <-->      || NC     <-->
* LED_A <--> PD13 || NC     <-->
* NC	  <-->      || SD_CS  <-->
* RESET <--> PE1  || SD_DIN <-->
* F_CS	<-->      || SD_SLK <-->
* CS	  <--> PD7  || SD_OUT <-->
* DB15	<--> PD10 || T_IRQ  <-->
* DB14	<--> PD9  || T_OUT  <-->
* DB13	<--> PD8  || NC     <-->
* DB12	<--> PE15 || T_DIN  <-->
* DB11	<--> PE14 || T_CS   <-->
* DB10	<--> PE13 || T_CLK  <-->
* DB9	  <--> PE12 || DB7    <--> PE10
* DB8	  <--> PE11 || DB6    <--> PE9
* RD	  <--> PD4  || DB5    <--> PE8
* WR	  <--> PD5  || DB4    <--> PE7
* RS 	  <--> PD11 || DB3    <--> PD1
* NC	  <-->      || DB2    <--> PD0
* VCC	  <--> 3.3V || DB1    <--> PD15
* GND   <--> GND  || DB0    <--> PD14
*-------------------------------------------------------------
*-------------------------------------------------------------
* STM324f07 TO HX8352A pin Connection
* Board<-->PIN  || Board<-->PIN  ||||| Board <--> PIN|| Board <--> PIN
*            LEFT BANK			     |||||			    RIGHT BANK
* GND	<-->	    || GND <-->		   ||||| GND  <--> GND || GND  <-->
* VDD	<-->	    || VDD <-->      ||||| 5V   <-->	   || 5V   <-->
* GND	<-->      || NRST<-->      ||||| 3V   <--> VCC || 3V   <-->
* PC1	<-->      || PC0 <-->      ||||| PH0  <-->     || PH1  <-->
* PC3	<-->      || PC2 <-->      ||||| PC14 <-->     || PC15 <-->
* PA1	<-->      || PA0 <-->      ||||| PE6  <-->     || PC13 <-->
* PA3	<-->      || PA2 <-->      ||||| PE4  <-->     || PE5  <-->
* PA5	<-->      || PA4 <-->      ||||| PE2  <-->     || PE3  <-->
* PA7	<-->      || PA6 <-->      ||||| PE0  <-->     || PE1  <--> RESET
* PC5	<-->      || PC4 <-->      ||||| PB8  <-->     || PB9  <-->
* PB1	<-->      || PB0 <-->      ||||| BOOT0<-->     || VDD  <-->
* GND	<-->      || PB2 <-->      ||||| PB6	<-->     || PB7  <-->
* PE7	<--> DB4  || PE8 <--> DB5  ||||| PB4  <-->     || PB5  <-->
* PE9	<--> DB6  || PE10<--> DB7  ||||| PD7  <--> CS  || PB3  <-->
* PE11<--> DB8  || PE12<--> DB9  ||||| PD5  <--> WR  || PD6  <-->
* PE13<--> DB10 || PE14<--> DB11 ||||| PD3  <-->     || PD4  <--> RD
* PE15<--> DB12 || PB10<-->   	 ||||| PD1  <--> DB3 || PD2  <-->
* PB11<-->      || PB12<-->   	 ||||| PC12 <-->     || PD0  <--> DB2
* PB13<-->      || PB14<-->   	 ||||| PC10 <-->     || PC11 <-->
* PB15<-->      || PD8 <--> DB13 ||||| PA14 <-->     || PA15 <-->
* PD9	<--> DB14 || PD10<--> DB15 ||||| PA10 <-->     || PA13 <-->
* PD11<--> RS   || PD12<-->   	 ||||| PA8  <-->     || PA9  <-->
* PD13<--> LED_A|| PD14<--> DB0  ||||| PC8  <-->     || PC9  <-->
* PD15<--> DB1  || NC  <-->   	 ||||| PC6  <-->     || PC7  <-->
* GND	<-->      || GND <-->   	 ||||| GND  <-->     || GND  <-->
```

### Connection diagram for 4 x 4 Matrix Array Keypad
```
* 4 x 4 Matrix Array 16 Key Membrane Switch Keypad Keyboard To STM32f407 pin Connection
*
* With Keyoad facing up and text in readable position
*:-----------------------------------------
*	PC1 PC2 PC3 PC5 PB0 PB1 PB2 PB10
*:----------------------------------------------
```

##Software

---

Due to the complexity of the project and the time constraints imposed due to the length of the course, the well documented well tested library the [stm32plus][LIB-stm32plus] was used in order to create a working connection between the TFT screen and the development board. References were taken directly from the authors website [http://andybrown.me.uk][LIB-andy] to better understand the library and use it to its capcity for the needed results.

The 3x3 Matrix Keypad is a well known, well documented embedded perhipheral; however, in order to quickly demonstrate the aptitude for the project a commonly used well know library  when dealing with the stm32f4 series of embedded platforms. The [stm32f4-discovery][LIB-stm32f-discovery] library integrates commonly used embedded perhipherals into a single location. It's repository can be found [HERE][LIB-keypad].  

In regards to the filters textbook definitions of each filter where used and cross-corroborated in order to create a set of standard working perhipherals. Care was taken due to the memory constraints of the embedded platform. As such their is no one focal location in which the filters implimentations rely on.

---

# Instructions

---
1. Open up a terminal.
2. Clone the git repository.
3. Change directory into cloned git repository, el6483-project.
4. Type source projectScripts.sh.
5. Type makeFlashProject.
---

#Discusion

---

The project revolved around the use of the [St's][Disc-st] [stm32f407][MAT-MainBoard] discovery board and [Himax's HX8352A][Disc-Himax-hx8352a] LCD display connected using the development board's specialised flexible static memory controller ([FSMC][Disc-FSMC]). Due to timing constraints and lengthy shipping times of more well known screen displays; a New York based supplier was used in order to reduce shipping time and overal costs. Other members purchased more common well known LCD displays such as the ili9325; however, these displays where not the focus of the base development and their were many issues in implementing the screen displays in a generic way.

For this project [Andy][LIB-andy]'s ['stm32plus'][LIB-stm32plus] was used to help with the initial hurdle of connecting the development board with the LCD display. Their were many issues regarding the initial start up code; dispite having the same display the controller panel for the one implemented in the library and the one in our device were dissimilar. Driver's for the [Tianma's TM032LDH05][Disc-Tianma-tm032ldh05] LCD panel were created and contributed into the official stm32plus library, this is referenced [HERE][Disc-Library-Contribution] from the author Andy himself;  

A 3x3 Matrix Keypad was also implimented into the project as a means of user input. The keypad allowed the user to both change the images displayed on screen and select an image filter. The library used for this implimentation was the [stm32f4-discovery][LIB-stm32f-discovery] by Majerle Tilen. specific classes where used to impliment the keypad only; however, it seems as though the library was not as well tested as the previous as errors plagued the source code that crippled the utilization of the given functionalities. Small changes where made throughout the four classes used the re-enabled proper functionality of the perhipheral and made minor changes to properly integrate it into the project. These changes ranged from odd errors in functions and the use of specific GPIO pins that fit the projects needs.  

Once images could be displayed properly onto the device the next hurdle was implementing the filters. This posed two seperate issues; the library was not meant to be extended in such a way that gave user acccess to critical functions. The result was the requirement of more function calls in an unnatural way. Methods were created to ease this issue and grant the user a more natural way to interact with the images. The second issue dealt with memory. The stm32f407 discovery board did not have sufficent memory to perform common image manipulation. Let alone store a single image in working memory. This hampered production as most discussion regarding image manipulation required two seperate pools of memory one for the source and another for the result. After a few failed attempts it was decided that the best way to handle the issue was to take advantage of the display panel's onboard memory by first drawing the image to the screen and then processing the resultant image from what is already displayed.

Convolution was the basis behind the image filtering which allowed for fun and quick to create filters; however, to perform the more advanced image processing algorithms such as edge detection which is a part of standard kernel image processing, more care was taken to properly calculate the resultant. Due to the memory constraints mentioned earlier it was found that roughly 2 rows of portrait width length buffers could be used to store the resultant and the previous. This was useful as kernel image processing filters work on multiple rows from the source image. This worked well for a kernel size of 3x3 however their was not enough memory for larger kernel sizes which hampered production of certain filters such as the Gaussian Blur or Motion Blur Filters in which most referenced implimentations discussed required a 9x9 kernel for optimal results.

##Other Issues

In regards to the physical keypad itself their was a single issue regarding the  was the The only bug with the integrated system that was flashed onto the demo unit is the nonfunctional 0 button. When you press the 0 button, the picture that is mapped to that button does not show up and if the next button press is a filter it will behave bizarrely. It is a bug that is repeatable and can be viewed dramatically by hitting zero after loading up a picture and holding down the swap or inverse filter buttons. Every time it filters it shifts the image 1 column of pixels left creating a side scrolling effect. Currently the team is baffled at why this is happening as the code that is written for the zero button does not look like it could do anything remotely like what we were seeing.

Other miscellaneous hiccups that occurred during the development include not having the bottom portion of the fraida frame introduction image set properly, it is a problem that appeared only on that particular image and demo unit. One team member not being able to upload into bitbucket and the unexplained instance of Johnny somehow messing up his [cursor][Disc-mouse-triger] while moving documents.

---

#Results

---

**Filter Timing Results**

|Filter Name|Time(ms)
|:----------|:-----
|Invert 		 | 1254
|Swap				 | 1383
|Grey				 | 1858
|Xray				 | 8517
|Sobel's Edge| 8789
|Simple Edge | 11037

Physical design evolution

First version of the project.
![version 1][Res-version-1]

After finding it inconvenient to reach the user button, a keypad was added to the design.
![version 2][Res-version-2]

Adjusted the device to be more ergonomic and viewable.
![version 3][Res-version-3]

---

#Conclusion

---

For the final project involving the use of the STM32f4 microcontroller, the team set out to design and create a digital picture frame with onboard filters. After acquiring and assembling the hardware, it was decided that we would use libraries from [andy’s workshop][LIB-andy] to load images from the microcontroller to the LCD panel. After the first mile stone it was discovered that using the user button as the primary method of switching through different pictures and filters a 4x4 matrix keypad was added to the design. For interfacing the keypad with the microcontroller, libraries from [stm32f4-discovery][LIB-stm32f-discovery] were used. From then on the team worked on experimenting and creating different image filters such as grayscale, inversion, and sobel edge detection. Six filters and nine images were then loaded onto the demo unit and presented to the professor.

---


[ABSTRACT-1]:http://en.wikipedia.org/wiki/Digital_image_processing

[PROFILE-Williams]:https://bitbucket.org/kdgwill
[PROFILE-Koppula]:https://bitbucket.org/Sbk411
[PROFILE-Goli]:https://bitbucket.org/golivikyath
[PROFILE-Chu]:https://bitbucket.org/jchu1024


[AOI-Image-Filter]:http://www.pcmag.com/encyclopedia/term/44794/image-filter
[AOI-Image-CgTutor-Filtering]:http://lodev.org/cgtutor/filtering.html
[AOI-LCD-Module]:http://www.nxp.com/wcm_documents/techzones/microcontrollers-techzone/Presentations/graphics.lcd.technologies.pdf

[MAT-MainBoard]:http://www.st.com/web/catalog/tools/FM116/SC959/SS1532/PF252419
[MAT-LCD]:http://www.ebay.com/itm/3-2-Widescreen-400-240-TFT-LCD-Color-Touch-Screen-Module-For-Arduino-AVR/231350163592?_trksid=p2047675.c100009.m1982&_trkparms=aid%3D777000%26algo%3DABA.MBE%26ao%3D1%26asc%3D28790%26meid%3D1b297645762748e4b44f1a6f77eb3906%26pid%3D100009%26rk%3D1%26rkt%3D1%26sd%3D321284405410
[MAT-JUMP]:http://www.amazon.com/40pcs-Female-2-54mm-Jumper-Wires/dp/B007MRQC1K
[MAT-KEY]:http://www.ebay.com/itm/4-x-4-Matrix-Array-16-Key-Membrane-Switch-Keypad-Keyboard-for-Arduino-AVR-PI-C-/310511616357?pt=LH_DefaultDomain_0&hash=item484bef4165
[MAT-USB-Adapter]:http://www.ebay.com/itm/Novel-Black-USB-A-Male-to-Mini-USB-B-5-Pin-Charging-Data-Sync-Cable-Retractable-/281230936321?pt=LH_DefaultDomain_0&hash=item417aab8901

[LIB-andy]:http://andybrown.me.uk/wk/
[LIB-stm32plus]:https://github.com/andysworkshop/stm32plus/
[LIB-keypad]:https://github.com/MaJerle/stm32f429/blob/master/00-STM32F429_LIBRARIES/tm_stm32f4_keypad.h
[LIB-stm32f-discovery]:http://stm32f4-discovery.com/2014/09/library-32-matrix-keypad-stm32f4xx/

[Disc-st]:http://www.st.com/web/en/home.html
[Disc-FSMC]:http://www.st.com/web/en/resource/technical/document/application_note/CD00200423.pdf
[Disc-Himax-hx8352a]:http://www.displayfuture.com/Display/datasheet/controller/HX8352.pdf
[Disc-Tianma-tm032ldh05]:http://tianma-europe.com/downloads/tm032ldh05_p_v1.1.pdf
[Disc-Library-Contribution]:https://github.com/andysworkshop/stm32plus/issues/113  

[Disc-mouse-triger]:http://i.imgur.com/Ncm7xwp.jpg
[Res-version-1]:http://i.imgur.com/h56Jacc.jpg
[Res-version-2]:http://i.imgur.com/kAtod7C.jpg
[Res-alt-version-2]:http://i.imgur.com/kAtod7C.jpg
[Res-version-3]:http://i.imgur.com/0IOjWPt.jpg

[EASTER-EGG-END-OF-PROJECT-LIFE]:http://i.imgur.com/jhgIlHL.jpg
