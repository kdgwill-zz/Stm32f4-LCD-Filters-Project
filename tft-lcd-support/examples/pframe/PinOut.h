/**
 *
 */
/**
 * NOTE PROGRESSIVE JPEG NOT SUPPORTED
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
 *-------------------------------------------------------------
 *------------------------------------------------------------- *
 * The SPI protocol supported by the XPT2046 is straightforward.
 * Basically you send it an 8-bit command that tells it whether you want to read X or Y,
 * the resolution (8 or 12 bit), whether power-saving mode is to be enabled and a few other
 * flags that affect the conversion. Please Read Touch Screen Controller Tips and XPT2046
 * in Docs/LCD for more detail
 */
