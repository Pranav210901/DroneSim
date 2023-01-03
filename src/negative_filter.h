/**
 * @file negative_filter.h
 *
 * @copyright holm0715: Jaron Holm.
 */

#pragma once

//done by holm0715: Jaron Holm
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "simple_filter.h"
 /**
 * @brief Negative Filter is a simple filter
 * The  negative fileter takes the color value at every pixel and sets it to it's inverse in the filtered
 *image. 
 */
class NegativeFilter : public SimpleFilter {
	/**
	  * @brief The apply method for the negative filter. It works taking in the color values as a float from 0 to 1, so for example if a pixel
	  *has the color values of red = 0.8, blue = 0.6 and green = 0.2, the filtered imagie would have
	  *0.2, 0.4 and 0.8 respectively.
	  */
	void Apply(std::vector<Image*>& original, std::vector<Image*>& filtered);
};
