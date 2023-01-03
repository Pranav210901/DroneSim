#ifndef GREYSCALEFILTER_H_
#define GREYSCALEFILTER_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "simple_filter.h"

/**
 * @copyright said0042:Maryan Said.
 *
 */
 
/**
 * @brief GreyscaleFilter.h is a SimpleFilter 
 * This filter Changes the image into a grey scale image based on image luminance.
 */
class GreyScaleFilter: public SimpleFilter {
    public:
    /**
  * @brief This apply method takes in an original and a filtered image vectors
  * It It takes each pixel, calculates the luminance by aggregrating each component 
  * and sets a new output pixel that uses this luminance value for red, green, and blue.
  */
        void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered);
};

#endif

