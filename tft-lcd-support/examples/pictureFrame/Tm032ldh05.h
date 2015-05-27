/**
 * The class added here was officially contributed to the stm32plus Library
 * hosted on gitbucket @ https://github.com/andysworkshop/stm32plus/issues/113
 *
 * Please make a note in the report.
 * */
///*
// * Tm032ldh05.h
// *
// *  Created on: Apr 22, 2015
// *      Author: Kyle D. Williams
// */
//
//#pragma once
//
//
///*
// * Useful typedefs to ease the pain of typing out template parameters
// */
//
//namespace rteProject {
//  namespace display {
//
//    /**
//     * Panel traits for the Tm032LDH05 display. The panel is 400x240 pixels in size.
//     */
//
//    class Tm032LDH05 {
//
//      public:
//        enum {
//          LONG_SIDE = 400,
//          SHORT_SIDE = 240
//        };
//
//      public:
//        template<class TAccessMode>
//        static void initialise(TAccessMode& accessMode);
//
//        template<class TAccessMode>
//        static void wake(TAccessMode& accessMode);
//    };
//
//
//    /*
//     * Post reset initialisation for the panel
//     */
//
//    template<class TAccessMode>
//    inline void Tm032LDH05::initialise(TAccessMode& accessMode) {
//    		//bad practice but useful in this instance
//    		using namespace stm32plus;
//    		using namespace stm32plus::display;
//
//    		// do the startup sequence
//    		MillisecondTimer::delay(160);
//
//    		accessMode.writeCommand(hx8352a::TEST_MODE_CONTROL,0x02);  //TESTM=1
//
//    		accessMode.writeCommand(hx8352a::VDDD_CONTROL,0x03);  //VDC_SEL=011
//    		accessMode.writeCommand(hx8352a::SOURCE_GAMMA_RESISTOR_1,0x01);
//    		accessMode.writeCommand(hx8352a::SOURCE_GAMMA_RESISTOR_2,0x93); //STBA[7]=1,STBA[5:4]=01,STBA[1:0]=11
//
//    		accessMode.writeCommand(hx8352a::SYNC_FUNCTION,0x01); //DCDC_SYNC=1
//
//    		accessMode.writeCommand(hx8352a::TEST_MODE_CONTROL,0x00);//TESTM=0
//
//    		//Gamma Setting
//    	    accessMode.writeCommand(hx8352a::GAMMA_1+0, 0xB0);
//    	    accessMode.writeCommand(hx8352a::GAMMA_1+1, 0x03);
//    	    accessMode.writeCommand(hx8352a::GAMMA_1+2, 0x10);
//    	    accessMode.writeCommand(hx8352a::GAMMA_1+3, 0x56);
//    	    accessMode.writeCommand(hx8352a::GAMMA_1+4, 0x13);
//    	    accessMode.writeCommand(hx8352a::GAMMA_1+5, 0x46);
//    	    accessMode.writeCommand(hx8352a::GAMMA_1+6, 0x23);
//    	    accessMode.writeCommand(hx8352a::GAMMA_1+7, 0x76);
//    	    accessMode.writeCommand(hx8352a::GAMMA_1+8, 0x00);
//    	    accessMode.writeCommand(hx8352a::GAMMA_1+9, 0x5E);
//    	    accessMode.writeCommand(hx8352a::GAMMA_1+10,0x4F);
//    	    accessMode.writeCommand(hx8352a::GAMMA_1+11,0x40);
//
//    		//**********Power On sequence************
//
//    		accessMode.writeCommand(hx8352a::OSC_CONTROL_1,0x91);
//
//    		accessMode.writeCommand(hx8352a::CYCLE_CONTROL_1,0xF9);
//    		MillisecondTimer::delay(10);
//
//    		accessMode.writeCommand(hx8352a::POWER_CONTROL_3,0x14);
//
//    		accessMode.writeCommand(hx8352a::POWER_CONTROL_2,0x11);
//
//    		accessMode.writeCommand(hx8352a::POWER_CONTROL_4,0x06);
//
//    		accessMode.writeCommand(hx8352a::VCOM_CONTROL,0x42);
//    		MillisecondTimer::delay(20);
//
//    		accessMode.writeCommand(hx8352a::POWER_CONTROL_1 ,0x0A);
//
//    		accessMode.writeCommand(hx8352a::POWER_CONTROL_1 ,0x1A);
//    		MillisecondTimer::delay(40);
//
//
//    		accessMode.writeCommand(hx8352a::POWER_CONTROL_1 ,0x12);
//    		MillisecondTimer::delay(40);
//
//    		accessMode.writeCommand(hx8352a::POWER_CONTROL_6 ,0x27);
//    		MillisecondTimer::delay(100);
//
//
//    		//**********DISPLAY ON SETTING***********
//
//    		accessMode.writeCommand(hx8352a::DISPLAY_CONTROL_2,0x60);
//
//    		accessMode.writeCommand(hx8352a::SOURCE_CONTROL_2,0x40);
//
//    		accessMode.writeCommand(hx8352a::CYCLE_CONTROL_10,0x38);
//
//    		accessMode.writeCommand(hx8352a::CYCLE_CONTROL_11,0x38);
//
//    		accessMode.writeCommand(hx8352a::DISPLAY_CONTROL_2,0x38);
//    		MillisecondTimer::delay(40);
//
//    		accessMode.writeCommand(hx8352a::DISPLAY_CONTROL_2,0x3C);
//
//    		accessMode.writeCommand(hx8352a::MEMORY_ACCESS_CONTROL,0x1C);
//
//    		accessMode.writeCommand(hx8352a::DISPLAY_MODE_CONTROL,0x06);
//
//    		accessMode.writeCommand(hx8352a::PANEL_CONTROL,0x00);
//
//    		accessMode.writeCommand(hx8352a::COLUMN_ADDRESS_START_H,0x00);
//    		accessMode.writeCommand(hx8352a::COLUMN_ADDRESS_START_L,0x00);
//    		accessMode.writeCommand(hx8352a::COLUMN_ADDRESS_END_H,0x00);
//    		accessMode.writeCommand(hx8352a::COLUMN_ADDRESS_END_L,0xef);
//
//    		accessMode.writeCommand(hx8352a::ROW_ADDRESS_START_H,0x00);
//    		accessMode.writeCommand(hx8352a::ROW_ADDRESS_START_L,0x00);
//    		accessMode.writeCommand(hx8352a::ROW_ADDRESS_END_H,0x01);
//    		accessMode.writeCommand(hx8352a::ROW_ADDRESS_END_L,0x8f);
//
//    		//accessMode.writeCommand(hx8352a::MEMORY_WRITE);
//    }
//
//
//    /**
//     * Wake the panel up from standby mode. Only a subset of the initialisation sequence is actually
//     * required but we'll save some code and just call initialise() again to bring it back to life.
//     * @param accessMode The access mode
//     */
//
//    template<class TAccessMode>
//    inline void Tm032LDH05::wake(TAccessMode& accessMode) {
//      initialise(accessMode);
//    }
//
//
//    /**
//      * Specialisations for the tm032ldh05 400x240 panel
//      */
//
//    template<class TAccessMode> using Tm032ldh05_Portrait_64K =  stm32plus::display::HX8352A_Portrait_64K<TAccessMode,Tm032LDH05>;
//    template<class TAccessMode> using Tm032ldh05_Landscape_64K =  stm32plus::display::HX8352A_Landscape_64K<TAccessMode,Tm032LDH05>;
//
//    template<class TAccessMode> using Tm032ldh05_Portrait_262K =  stm32plus::display::HX8352A_Portrait_262K<TAccessMode,Tm032LDH05>;
//    template<class TAccessMode> using Tm032ldh05_Landscape_262K =  stm32plus::display::HX8352A_Landscape_262K<TAccessMode,Tm032LDH05>;
//
//    template<class TDevice> using Tm032ldh05_Terminal_Portrait = stm32plus::display::GraphicTerminal<TDevice,true>;
//    template<class TDevice> using Tm032ldh05_Terminal_Landscape = stm32plus::display::GraphicTerminal<TDevice,false>;
//
//  }
//}
