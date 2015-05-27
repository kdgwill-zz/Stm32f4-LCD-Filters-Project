#Abstract

> To design a digital picture frame that will apply image filters to your pictures.
---

#TABLE OF CONTENTS

[TOC]

---

Project Proposal for EL6483
==========================

## Team

1. Kyle D. Williams **([kdw281@nyu.edu][PROFILE-Williams])**

2. Sravani Koppula **([sbk411@nyu.edu][PROFILE-Koppula])**

3. Vikyath Goli **([vg933@nyu.edu][PROFILE-Goli])**

4. Johnny Chu **([jc6875@nyu.edu][PROFILE-Chu])**

---

## Idea

###Proposal

---

Using the STM32F407 Discovery board, create a digital picture frame that can apply a filter to a displayed image onto an LCD screen. The user button can be used to cycle through filters or pictures.

---

###Motivation

---


Back in the day, when you took photos, the whole process was an experience. You try your best to frame the shot, wait a week for them to develop and still, almost all of them would be terrible. But, for those few pictures that turn out perfect; you would frame them and show them off to the world along with your story on how the stars aligned that day or all the little things that almost ruined the shot. These days there are a lot less picture frames around the house and a lot more sharing through photo aggregates. Our group aims bridge digital picture frames with the filters that make sites like instagram a household name, to bring back photo frames. **This project will be considered a proof of concept of such an idea.**

---

###Articles of Interest

---

* https://github.com/andysworkshop/stm32plus/blob/master/examples/hx8352a/hx8352a.cpp
* http://www.emartee.com/product/42093/TFT%203.2%22%20400*240%20With%20SD%20Touch%20Module
* https://hifiduino.wordpress.com/2012/04/13/iteadstudio-tft-display-for-arduino/

---

## Materials

###Hardware

---

1. [STM32F4 Discovery board][MAT-MainBoard]
2. [LCD Screen][MAT-LCD]
3. [Micro-USB to USB][MAT-USB-Adapter]
4. [Female to Female Jumper cables][MAT-JUMP]

Connection diagram
Side closer to edge         | Side closer to center
Board     <--> PIN          | BOARD     <--> PIN
NC        <-->              | NC        <-->
LED_A     <--> PD13         | NC        <-->
NC        <-->              | SD_CS     <-->
RESET     <--> PE1          | SD_DIN    <-->
F_CS      <-->              | SD_SLK    <-->
CS        <--> PD7          | SD_OUT    <-->
DB15      <--> PD10         | T_IRQ     <-->
DB14      <--> PD9          | T_OUT     <-->
DB13      <--> PD8          | NC        <-->
DB12      <--> PE15         | T_DIN     <-->
DB11      <--> PE14         | T_CS      <-->
DB10      <--> PE13         | T_CLK     <-->
DB9       <--> PE12         | DB7       <--> PE10
DB8       <--> PE11         | DB6       <--> PE9
RD        <--> PD4          | DB5       <--> PE8
WR        <--> PD5          | DB4       <--> PE7
RS        <--> PD11         | DB3       <--> PD1
NC        <-->              | DB2       <--> PD0
VCC       <--> 3.3V         | DB1       <--> PD15
GND       <--> GND          | DB0       <--> PD14
---

###Software

---
[Project foundation provided by andy's workshop](LIB-andy)
[CImg Library used for image filters](LIB-img)
---

##Report

###Instructions

---
1. Open up a terminal.
2. Clone the git repository.
3. Change directory into cloned git repository, el6483-project.
4. Type source projectScripts.sh.
5. Type makeFlashProject.
---

###Discusion

---
So one of the downsides of America losing most of its electronics manufacturing is that when looking for a LCD most of your options are going to be located in china. The problem with that is that with regular shipping the delivery time can range from 1 to 3 weeks with the other shipping options being ridiculously expensive. The option we ended up choosing wasn't the screen that we originally wanted but the supplier was located in new york and wasn't too over priced.We also purchased alternate LCD screen which provided driver issues with our microcontroller.

Other problem that we encountered was finding a library that would fulfill the image filter modifications that we wanted while also meeting our size constraints.  

---

###Results

---

---

###Conclusion

---

---




## Milestones

### **16 April 2015**

1.    Complete the physical prototype.
2.    Ability to minimally load information from the board onto the LCD screen.
	a.Load an image

---

### **7 May 2015**


1.    Complete the physical prototype.
2.    Ability to minimally load information from the board onto the LCD screen.
	1. Load an image
	2. Cycle through images
3. Ability to apply filter to pictures on board.
4. Ability to correctly load filtered pictures onto an LCD screen
5. Ability for the pictures to change on the device
	+ Decide to either:
		-  Use the Userbutton to cycle through applying filters to a picture.
		-  Use the Userbutton to traverse through pictures.
		-  Use the Userbutton to switch between picture and filter mode.
6. Impress Professor.

---

## Plan of work

####Responsibilities

 | Members  |        Role        | Additional Role |
 |:---------|:------------------:|:---------------:|
 |Kyle      | Software Overview  | Hardware Support  
 |Sravani   | Software filters   | Software Support  
 |Vikyath   | Software filters   | Hardware Support
 |Johnny    | Hardware Overview  | Software Support

####Timeline

#####Week 1

| Members  |       Responsibility                                            | Hours
|:---------|:---------------------------------------------------------------:|:-----:
|Kyle      | Propose project ideas and finalize project scop                 |   06
|Sravani   | Propose project ideas and finalize project scope.               |   06
|Vikyath   | Propose project ideas and finalize project scope.               |   06
|Johnny    | Propose project ideas and finalize project scope.               |   06
|Total     | 							             |   24
|Note 1    | Other materials can be purchased at any time                    |   00

#####Week 2

| Members  |  Responsibility                                                 | Hours
|:---------|:---------------------------------------------------------------:|:-----:
|Kyle      | LCD Screen and filter Implementation Research.                  |   08
|Sravani   | LCD Screen and filter Implementation Research.                  |   08
|Vikyath   | LCD Screen and filter Implementation Research.                  |   08
|Johnny    | LCD Screen and filter Implementation Research.                  |   08
|Total     | Decide on and purchase LCD          			     |   32


#####Week 3

| Members  |  Responsibility                                                  | Hours
|:---------|:----------------------------------------------------------------:|:-----:
|Kyle      | LCD Screen implementation     		          	      |   08
|Sravani   | LCD Screen implementation                                        |   08
|Vikyath   | LCD Screen implementation                                        |   08
|Johnny    | Hardware acquisition and assembly				      |   08
|Total     | Implementing LCD should be top priority                          |   32
|GROUP WORK| LCD Implementation                                               |   00

#####Week 4

| Members  |  Responsibility  		                                      |Hours
|:---------|:----------------------------------------------------------------------------------------------------:|:-----:
|Kyle      | Getting the microcontroller to load a image on screen    	      |   08
|Sravani   | Getting the microcontroller to load a image on screen            |   08
|Vikyath   | Getting the microcontroller to load a image on screen            |   08
|Johnny    | Getting the microcontroller to load a image on screen            |   08
|Total     |  								      |   32
|Note      | LCD should be somewhat functional able to display a static image onto the screen                     |   00

#####Week 5

| Members  |  Responsibility                 				      | Hours
|:---------|:----------------------------------------------------------------:|:-----:
|Kyle      | reading and cycling through Images                               | ![Infinity][&infin;]
|Sravani   | read and write Photo filters onto images           	      | ![Infinity][&infin;]
|Vikyath   | read and write Photo filters onto images                         | ![Infinity][&infin;]
|Johnny    | Image compression and loading into LCD    		              | ![Infinity][&infin;]
|Total     | Review Final Milestone Checklist     			      | ![LessThanEqualTo][&le;] 672
|Note      | Project should be fully functional   | 00

#####Week 6

| Members  |  Responsibility                                                  | Hours
|:---------|:----------------------------------------------------------------:|:-----:
|Kyle      | finishing up the user interface and testing       	              |   04
|Sravani   | finishing up the user interface and testing                      |   04
|Vikyath   | finishing up the user interface and testing                      |   04
|Johnny    | finishing up the user interface and testing                      |   04
|Total     | Final presentation  					      |   16
|GROUP WORK| All aspects of the project should be reviewed and the report and presentation should be finalized | 00



---

##Initial Resources

---

**Everyone should be more familiar with at least GIT before forking from the repository**
**e.g. rebase, merging, branching**

---

+ Git
	- [Atlassian](https://www.atlassian.com/git/tutorials/setting-up-a-repository/)
	- [TutorialsPoint](http://www.tutorialspoint.com/git/)

+ Makefiles
	- [TutorialsPoint](http://www.tutorialspoint.com/makefile/makefile_example.htm)
	- [MrBook](http://mrbook.org/blog/tutorials/make/)

+ Markdown
	- [Markdown-Demo - BitBucket](https://bitbucket.org/tutorials/markdowndemo)
	- Github's Markdown impl is slightly different from Bitbucket so use first link and this one for quick reference
		* [MasteringMarkdown-Github](https://guides.github.com/features/mastering-markdown/)
		* [Cheat-Sheet-GitHub](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)
	- [Cheatsheet](http://assemble.io/docs/Cheatsheet-Markdown.html)



[PROFILE-Williams]:https://bitbucket.org/kdgwill
[PROFILE-Koppula]:https://bitbucket.org/Sbk411
[PROFILE-Goli]:https://bitbucket.org/golivikyath
[PROFILE-Chu]:https://bitbucket.org/jchu1024

[ABSTRACT-1]:http://en.wikipedia.org/wiki/Ubiquitous_computing

[MOT-1]:http://en.wikipedia.org/wiki/Internet_of_Things
[MOT-2]:http://en.wikipedia.org/wiki/Wearable_technology

[ART-1]:http://www.theverge.com/a/virtual-reality/
[ART-2]:https://www.oculus.com/blog/oculus-mobile-sdk-now-available/
[ART-3]:http://en.wikipedia.org/wiki/Virtual_reality

[MAT-MainBoard]:http://www.st.com/web/catalog/tools/FM116/SC959/SS1532/PF252419
[MAT-LCD]:http://www.st.com/web/catalog/tools/FM146/CL1984/SC720/SS1462/PF255417?sc=stm32f4dis-expansion
[Android]:http://developer.android.com/index.html
[MAT-USB-Adapter]:http://www.amazon.com/gp/product/B005FUNYSA/ref=oh_details_o00_s00_i00
[MAT-Bluetooth]:http://www.st.com/web/en/catalog/sense_power/FM1968/CL1976/SC1324?s_searchtype=keyword
[MAT-FlashDrive]:http://www.flash-drives.com/?campaign=usa1_branded&adgroup=flash_drives&keyword=flash%20drive&matchtype=e&network=g&gclid=Cj0KEQjw_9OoBRChj9vMo5CHrdUBEiQAJ6YRPfe3Wi0OdQ46AZqRWggpQuGuzeBaa_I93RZf1O0_wzUaAnzm8P8HAQ
[MAT-CAM]:http://www.st.com/web/catalog/tools/FM146/CL1984/SC720/SS1462/PF255417?sc=stm32f4dis-expansion
[MAT-JUMP]:http://www.amazon.com/40pcs-Female-2-54mm-Jumper-Wires/dp/B007MRQC1K
[LIB-andy]:https://github.com/andysworkshop/stm32plus/blob/master/examples/hx8352a/hx8352a.cpp
[LIB-img]:http://cimg.sourceforge.net/
[&infin;]:http://i1379.photobucket.com/albums/ah127/kdgwill/infinity_zpsonpphmum.png?t=1427416779

[&le;]:http://i1379.photobucket.com/albums/ah127/kdgwill/lessthanorequal_zpsffwnvqeo.gif
# Stm32f4-LCD-Filters-Project
