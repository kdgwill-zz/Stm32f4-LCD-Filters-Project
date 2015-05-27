#Abstract

> To design a digital picture frame that will apply image filters to your pictures.
---

#TABLE OF CONTENTS

[TOC]

---

## Idea

###Hardware

---

1. [STM32F4 Discovery board][MAT-MainBoard]
2. [LCD Screen][MAT-LCD]
3. [Micro-USB to USB][MAT-USB-Adapter]
4. [Female to Female Jumper cables][MAT-JUMP]

Connection diagram
| Side closer to edge         | Side closer to center|
|-----------------------------|----------------------|
| Board     <--> PIN          | BOARD     <--> PIN   |   
| NC        <-->              | NC        <-->       |
| LED_A     <--> PD13         | NC        <-->       |
| NC        <-->              | SD_CS     <-->       |  
| RESET     <--> PE1          | SD_DIN    <-->       |  
| F_CS      <-->              | SD_SLK    <-->       | 
| CS        <--> PD7          | SD_OUT    <-->       | 
| DB15      <--> PD10         | T_IRQ     <-->       | 
| DB14      <--> PD9          | T_OUT     <-->       | 
| DB13      <--> PD8          | NC        <-->       | 
| DB12      <--> PE15         | T_DIN     <-->       | 
| DB11      <--> PE14         | T_CS      <-->       | 
| DB10      <--> PE13         | T_CLK     <-->       | 
| DB9       <--> PE12         | DB7       <--> PE10  |
| DB8       <--> PE11         | DB6       <--> PE9   |
| RD        <--> PD4          | DB5       <--> PE8   |
| WR        <--> PD5          | DB4       <--> PE7   |
| RS        <--> PD11         | DB3       <--> PD1   |
| NC        <-->              | DB2       <--> PD0     |
| VCC       <--> 3.3V         | DB1       <--> PD15    |
| GND       <--> GND          | DB0       <--> PD14    |
---
1. Open up a terminal.
2. Clone the git repository.
3. Change directory into cloned git repository, el6483-project.
4. Type source projectScripts.sh.
5. Type makeFlashProject.
---

[PROFILE-Williams]:https://bitbucket.org/kdgwill

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
