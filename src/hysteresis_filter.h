/**
 * @file HysteresisFilter.h
 *
 * @copyright holm0715: Jaron Holm.
 */

#pragma once
//done by holm0715: Jaron Holm
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "convolution_filter.h"

 /*******************************************************************************
  * Class Definitions
  ******************************************************************************/
  /**
   * @brief The class for the Hysteresis ConvolutionFilter
   *
   *  The last filter used in canny edge ditection, looks at the weak pixels
   *  from the double threshold and sets them to strong if there is a strong
   *  pixel next to it, otherwise sets it to 0
   */
class HysteresisFilter : public ConvolutionFilter {
public:
    /**
      * @brief This is the hysteresis filter constructor.
      *it needs its own as it must take in the given values for weak and strong
      */
    HysteresisFilter(float weak, float strong);
    /**
      * @brief Applies the Hysteresis filter, taking in the image generated from the double
      *thresh filter and outputting the final image for the edge detection.
      */
    void Apply(std::vector<Image*>& original, std::vector<Image*>& filtered);
private:
    float weak;
    float strong;
};
