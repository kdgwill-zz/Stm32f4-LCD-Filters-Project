/*
 * FilterBase.h
 *
 *  Created on: May 8, 2015
 *      Author: Kyle D. Williams
 */

#pragma once

namespace fraidaFrame {
namespace filters {
/**
 * Template implementation of a Filter Sub Class.
 * This SubClass assumes that a single pixel is 16 bits long 565 packed range
 * It takes the devices wrapped graphics library as generic parameter
 *
 * @tparam TGraphLib graphics library that wraps the the device driver type
 */
template<stm32plus::display::GraphicsLibrary TGraphLib>
class FilterBaseSpecialisation{

public:

protected:
	TGraphLib& _device;

public:
	FilterBaseSpecialisation(TGraphLib& device);
	virtual ~FilterBaseSpecialisation();
	virtual void run() = 0;
};







}
}
