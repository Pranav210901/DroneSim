#ifndef COLRORTHRESH_H_
#define COLRORTHRESH_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "simple_filter.h"

/**
 * @copyright said0042:Maryan Said.
 *
 */
 
/**
 * @brief Colror_Thresh.h is a SimpleFilter 
 * This filter detects the orange pixels in an image
 *It turns the orange pixels into white and the non-orange pixels into dark
 */



class ColrorThresh: public SimpleFilter {
    public:
     /**
  * @brief This apply method takes in an original and a filtered image vectors
  *  It detects the orange pixels in an image
  * and sets a new output image into an image that  
  * has orange pixels in white and the non-orange pixels in dark
  */
        void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered);
};

#endif

