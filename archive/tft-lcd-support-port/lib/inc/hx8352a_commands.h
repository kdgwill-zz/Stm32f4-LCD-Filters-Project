/**
  ******************************************************************************
  * @file    hx8352a_commands.h
  * @author  Kyle D. Williams
  * @version V1.0.0
  * @date    11-April-2015
  * @brief  The command set as documented in "version 05 December 2008" of
  * 		the datasheet Only the commands we use are defined
  ******************************************************************************
  * @attention
  *
  *
  *
  * <h2><center>&copy; COPYLEFT 2011 el6483</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HX8325A_COMMANDS_H
#define __HX8325A_COMMANDS_H

#ifdef __cplusplus
 extern "C" {
#endif

 typedef enum HX8352A_COMMAND {
         HX8352A_COMMAND_DISPLAY_MODE_CONTROL                = 0x1,
         HX8352A_COMMAND_COLUMN_ADDRESS_START_H              = 0x2,
         HX8352A_COMMAND_COLUMN_ADDRESS_START_L              = 0x3,
         HX8352A_COMMAND_COLUMN_ADDRESS_END_H                = 0x4,
         HX8352A_COMMAND_COLUMN_ADDRESS_END_L                = 0x5,
         HX8352A_COMMAND_ROW_ADDRESS_START_H                 = 0x6,
         HX8352A_COMMAND_ROW_ADDRESS_START_L                 = 0x7,
         HX8352A_COMMAND_ROW_ADDRESS_END_H                   = 0x8,
         HX8352A_COMMAND_ROW_ADDRESS_END_L                   = 0x9,
         HX8352A_COMMAND_VERTICAL_SCROLL_TOP_FIXED_AREA_H    = 0xE,
         HX8352A_COMMAND_VERTICAL_SCROLL_TOP_FIXED_AREA_L    = 0xF,
         HX8352A_COMMAND_VERTICAL_SCROLL_HEIGHT_H            = 0x10,
         HX8352A_COMMAND_VERTICAL_SCROLL_HEIGHT_L            = 0x11,
         HX8352A_COMMAND_VERTICAL_SCROLL_BOTTOM_FIXED_AREA_H = 0x12,
         HX8352A_COMMAND_VERTICAL_SCROLL_BOTTOM_FIXED_AREA_L = 0x13,
         HX8352A_COMMAND_VERTICAL_SCROLL_START_ADDRESS_H     = 0x14,
         HX8352A_COMMAND_VERTICAL_SCROLL_START_ADDRESS_L     = 0x15,
         HX8352A_COMMAND_MEMORY_ACCESS_CONTROL               = 0x16,
         HX8352A_COMMAND_OSC_CONTROL_1                       = 0x17,
         HX8352A_COMMAND_POWER_CONTROL_1                     = 0x19,
         HX8352A_COMMAND_POWER_CONTROL_2                     = 0x1A,
         HX8352A_COMMAND_POWER_CONTROL_3                     = 0x1B,
         HX8352A_COMMAND_POWER_CONTROL_4                     = 0x1C,
         HX8352A_COMMAND_POWER_CONTROL_5                     = 0x1D,
         HX8352A_COMMAND_POWER_CONTROL_6                     = 0x1E,
         HX8352A_COMMAND_VCOM_CONTROL                        = 0x1F,
         HX8352A_COMMAND_DISPLAY_CONTROL_1                   = 0x23,
         HX8352A_COMMAND_DISPLAY_CONTROL_2                   = 0x24,
         HX8352A_COMMAND_MEMORY_WRITE                        = 0x22,
         HX8352A_COMMAND_CYCLE_CONTROL_1                     = 0x2B,
         HX8352A_COMMAND_CYCLE_CONTROL_10                    = 0x34,
         HX8352A_COMMAND_CYCLE_CONTROL_11                    = 0x35,
         HX8352A_COMMAND_SOURCE_CONTROL_1                    = 0x3C,
         HX8352A_COMMAND_SOURCE_CONTROL_2                    = 0x3D,
         HX8352A_COMMAND_GAMMA_1                             = 0x3E,
         HX8352A_COMMAND_PANEL_CONTROL                       = 0x55,
         HX8352A_COMMAND_IP_CONTROL                          = 0x5A,
         HX8352A_COMMAND_TEST_MODE_CONTROL                   = 0x83,
         HX8352A_COMMAND_VDDD_CONTROL                        = 0x85,
         HX8352A_COMMAND_SOURCE_GAMMA_RESISTOR_1             = 0x8B,
         HX8352A_COMMAND_SOURCE_GAMMA_RESISTOR_2             = 0x8C,
         HX8352A_COMMAND_SYNC_FUNCTION                       = 0x91
 }HX8352A_COMMAND;

#ifdef __cplusplus
}
#endif

#endif /*__HX8325A_COMMANDS_H */


/******************* (C) COPYLEFT 2015 el6483 *****END OF FILE****/

