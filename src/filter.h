#ifndef FILTER_H_
#define FILTER_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "image.h"
#include <vector>

/**
 * @copyright said0042:Maryan Said.
 *
 */
 
/**
 * @brief filter.h is the base/superclass class for all filters, ConvolutionFilter inherits from this class
 *This class uses the images class
 */
class Filter {
    public:
     /**
       * @brief Apply is a virtual method so all sub classes must implent it
      * The apply method takes in an original and a filtered image vectors  
      * applies a filter to the orginal and stores the change in  stores the filtred image vector
  */
        virtual void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) = 0;
};

#endif
