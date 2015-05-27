/*
 * This file is a part of the open source stm32plus library.
 * Copyright (c) 2011,2012,2013,2014 Andy Brown <www.andybrown.me.uk>
 * Please see website for licensing terms.
 */

#pragma once

#include "display/graphic/tft/ili9325/ILI9325Colour.h"
#include "display/graphic/tft/ili9325/ILI9325Orientation.h"
#include "display/graphic/tft/ili9325/ILI9325Gamma.h"
#include "display/graphic/tft/ili9325/commands/AllCommands.h"

namespace stm32plus {
namespace display {

/**
 * Graphic terminal modes for the ILI9325C
 */

template<class TDevice> using ILI9325C_Terminal_Portrait = GraphicTerminal<TDevice,true>;
template<class TDevice> using ILI9325C_Terminal_Landscape = GraphicTerminal<TDevice,false>;

/**
 * Generic ILI9325C template. The user can specialise based on the desired colour
 * depth, orientation and access mode.
 */

template<Orientation TOrientation, ColourDepth TColourDepth, class TAccessMode>
class ILI9325C: public ILI9325Colour<TColourDepth, TAccessMode>,
		public ILI9325Orientation<TOrientation, TAccessMode> {

public:
	enum {
		SHORT_SIDE = 240, LONG_SIDE = 320
	};

protected:
	TAccessMode& _accessMode;

public:
	ILI9325C(TAccessMode& accessMode);

	void initialise() const;

	void applyGamma(ILI9325Gamma& gamma) const;
	void sleep() const;
	void wake() const;
	void beginWriting() const;
};

/**
 * Constructor. Pass the access mode reference up the hierarchy where it'll get stored in the
 * common base class for use by all.
 */

template<Orientation TOrientation, ColourDepth TColourDepth, class TAccessMode>
inline ILI9325C<TOrientation, TColourDepth, TAccessMode>::ILI9325C(
		TAccessMode& accessMode) :
		ILI9325Colour<TColourDepth, TAccessMode>(accessMode), ILI9325Orientation<
				TOrientation, TAccessMode>(accessMode), _accessMode(accessMode) {
}

/**
 * Initialise the LCD. Do the reset sequence.
 */
#define LCD_Write_COM_DATA(X,Y) _accessMode.writeCommand(X,Y);
#define delay(X) MillisecondTimer::delay(X)

template<Orientation TOrientation, ColourDepth TColourDepth, class TAccessMode>
inline void ILI9325C<TOrientation, TColourDepth, TAccessMode>::initialise() const {

	// reset the device

	//_accessMode.reset();

	//_accessMode.writeCommand(0x07, 0x0001);
	//MillisecondTimer::MillisecondTimer::delay(200); // Dis-charge capacitor power voltage
	LCD_Write_COM_DATA(0xE5, 0x78F0); // set SRAM internal timing
		LCD_Write_COM_DATA(0x01, 0x0100); // set Driver Output Control
		LCD_Write_COM_DATA(0x02, 0x0700); // set 1 line inversion
		LCD_Write_COM_DATA(0x03, 0x1030); // set GRAM write direction and BGR=1.
		LCD_Write_COM_DATA(0x04, 0x0000); // Resize register
		LCD_Write_COM_DATA(0x08, 0x0207); // set the back porch and front porch
		LCD_Write_COM_DATA(0x09, 0x0000); // set non-display area refresh cycle ISC[3:0]
		LCD_Write_COM_DATA(0x0A, 0x0000); // FMARK function
		LCD_Write_COM_DATA(0x0C, 0x0000); // RGB interface setting
		LCD_Write_COM_DATA(0x0D, 0x0000); // Frame marker Position
		LCD_Write_COM_DATA(0x0F, 0x0000); // RGB interface polarity
		//*************Power On sequence ****************//
		LCD_Write_COM_DATA(0x10, 0x0000); // SAP, BT[3:0], AP, DSTB, SLP, STB
		LCD_Write_COM_DATA(0x11, 0x0007); // DC1[2:0], DC0[2:0], VC[2:0]
		LCD_Write_COM_DATA(0x12, 0x0000); // VREG1OUT voltage
		LCD_Write_COM_DATA(0x13, 0x0000); // VDV[4:0] for VCOM amplitude
		LCD_Write_COM_DATA(0x07, 0x0001);
		delay(200); // Dis-charge capacitor power voltage
		LCD_Write_COM_DATA(0x10, 0x1090); // SAP, BT[3:0], AP, DSTB, SLP, STB
		LCD_Write_COM_DATA(0x11, 0x0227); // Set DC1[2:0], DC0[2:0], VC[2:0]
		delay(50); // Delay 50ms
		LCD_Write_COM_DATA(0x12, 0x001F); // 0012
		delay(50); // Delay 50ms
		LCD_Write_COM_DATA(0x13, 0x1500); // VDV[4:0] for VCOM amplitude
		LCD_Write_COM_DATA(0x29, 0x0027); // 04  VCM[5:0] for VCOMH
		LCD_Write_COM_DATA(0x2B, 0x000D); // Set Frame Rate
		delay(50); // Delay 50ms
		LCD_Write_COM_DATA(0x20, 0x0000); // GRAM horizontal Address
		LCD_Write_COM_DATA(0x21, 0x0000); // GRAM Vertical Address
		// ----------- Adjust the Gamma Curve ----------//
		LCD_Write_COM_DATA(0x30, 0x0000);
		LCD_Write_COM_DATA(0x31, 0x0707);
		LCD_Write_COM_DATA(0x32, 0x0307);
		LCD_Write_COM_DATA(0x35, 0x0200);
		LCD_Write_COM_DATA(0x36, 0x0008);
		LCD_Write_COM_DATA(0x37, 0x0004);
		LCD_Write_COM_DATA(0x38, 0x0000);
		LCD_Write_COM_DATA(0x39, 0x0707);
		LCD_Write_COM_DATA(0x3C, 0x0002);
		LCD_Write_COM_DATA(0x3D, 0x1D04);
		//------------------ Set GRAM area ---------------//
		LCD_Write_COM_DATA(0x50, 0x0000); // Horizontal GRAM Start Address
		LCD_Write_COM_DATA(0x51, 0x00EF); // Horizontal GRAM End Address
		LCD_Write_COM_DATA(0x52, 0x0000); // Vertical GRAM Start Address
		LCD_Write_COM_DATA(0x53, 0x013F); // Vertical GRAM Start Address
		LCD_Write_COM_DATA(0x60, 0xA700); // Gate Scan Line
		LCD_Write_COM_DATA(0x61, 0x0001); // NDL,VLE, REV
		LCD_Write_COM_DATA(0x6A, 0x0000); // set scrolling line
		//-------------- Partial Display Control ---------//
		LCD_Write_COM_DATA(0x80, 0x0000);
		LCD_Write_COM_DATA(0x81, 0x0000);
		LCD_Write_COM_DATA(0x82, 0x0000);
		LCD_Write_COM_DATA(0x83, 0x0000);
		LCD_Write_COM_DATA(0x84, 0x0000);
		LCD_Write_COM_DATA(0x85, 0x0000);
		//-------------- Panel Control -------------------//
		LCD_Write_COM_DATA(0x90, 0x0010);
		LCD_Write_COM_DATA(0x92, 0x0600);
		LCD_Write_COM_DATA(0x07, 0x0133); // 262K color and display ON
}

/**
 * Apply the 10 panel gamma settings
 * @param gamma The collection of gamma values
 */

template<Orientation TOrientation, ColourDepth TColourDepth, class TAccessMode>
inline void ILI9325C<TOrientation, TColourDepth, TAccessMode>::applyGamma(
		ILI9325Gamma& gamma) const {

	_accessMode.writeCommand(ili9325::GammaControlCmd::FirstOpcode + 0,
			gamma[0]);
	_accessMode.writeCommand(ili9325::GammaControlCmd::FirstOpcode + 1,
			gamma[1]);
	_accessMode.writeCommand(ili9325::GammaControlCmd::FirstOpcode + 2,
			gamma[2]);
	_accessMode.writeCommand(ili9325::GammaControlCmd::FirstOpcode + 3,
			gamma[3]);
	_accessMode.writeCommand(ili9325::GammaControlCmd::FirstOpcode + 4,
			gamma[4]);
	_accessMode.writeCommand(ili9325::GammaControlCmd::FirstOpcode + 5,
			gamma[5]);
	_accessMode.writeCommand(ili9325::GammaControlCmd::FirstOpcode + 6,
			gamma[6]);
	_accessMode.writeCommand(ili9325::GammaControlCmd::FirstOpcode + 7,
			gamma[7]);
	_accessMode.writeCommand(ili9325::GammaControlCmd::FirstOpcode + 8,
			gamma[8]);
	_accessMode.writeCommand(ili9325::GammaControlCmd::FirstOpcode + 9,
			gamma[9]);
}

/**
 * Send the panel to sleep
 */

template<Orientation TOrientation, ColourDepth TColourDepth, class TAccessMode>
inline void ILI9325C<TOrientation, TColourDepth, TAccessMode>::sleep() const {
	_accessMode.writeCommand(ili9325::DisplayCtrl1Cmd::Opcode,
			ili9325::DisplayCtrl1Cmd::DISPLAY_HALT);
	_accessMode.writeCommand(ili9325::PowerCtrl1Cmd::Opcode,
			ili9325::PowerCtrl1Cmd::SLEEP);
}

/**
 * Wake the panel up
 */

template<Orientation TOrientation, ColourDepth TColourDepth, class TAccessMode>
inline void ILI9325C<TOrientation, TColourDepth, TAccessMode>::wake() const {
	_accessMode.writeCommand(ili9325::PowerCtrl1Cmd::Opcode,
			ili9325::PowerCtrl1Cmd::APE | ili9325::PowerCtrl1Cmd::AP_1_1
					| ili9325::PowerCtrl1Cmd::STEP_UP_FACTOR(6)
					| ili9325::PowerCtrl1Cmd::SOURCE_DRIVER_ENABLE);
	_accessMode.writeCommand(ili9325::DisplayCtrl1Cmd::Opcode,
			ili9325::DisplayCtrl1Cmd::DISPLAY_ON
					| ili9325::DisplayCtrl1Cmd::GATE_DRIVER_NORMAL
					| ili9325::DisplayCtrl1Cmd::BASE_IMAGE);
}

/**
 * Issue the command that allows graphics ram writing to commence
 */

template<Orientation TOrientation, ColourDepth TColourDepth, class TAccessMode>
inline void ILI9325C<TOrientation, TColourDepth, TAccessMode>::beginWriting() const {
	_accessMode.writeCommand(ili9325::GRAMStartWritingCmd::Opcode);
}

/**
 * ILI9325 interface: 64K, 262K colours, portrait and landscape
 */

template<class TAccessMode> using ILI9325C_Portrait_64K = GraphicsLibrary<ILI9325C<PORTRAIT,COLOURS_16BIT,TAccessMode>,TAccessMode>;
template<class TAccessMode> using ILI9325C_Landscape_64K = GraphicsLibrary<ILI9325C<LANDSCAPE,COLOURS_16BIT,TAccessMode>,TAccessMode>;

template<class TAccessMode> using ILI9325C_Portrait_262K = GraphicsLibrary<ILI9325C<PORTRAIT,COLOURS_18BIT,TAccessMode>,TAccessMode>;
template<class TAccessMode> using ILI9325C_Landscape_262K = GraphicsLibrary<ILI9325C<LANDSCAPE,COLOURS_18BIT,TAccessMode>,TAccessMode>;

}
}
