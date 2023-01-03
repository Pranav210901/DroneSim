#ifndef CANNY_EDGE_DETECT_H
#define CANNY_EDGE_DETECT_H
//done by tran0607:Ethan Tran 
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <map>
#include <vector>
#include <string>
#include <memory>
#include "greyscale_filter.h"
#include "gausian_blur_filter.h"
#include "sobal_filter.h"
/**
 * @copyright tran0607:Ethan Tran.
 *
 */
//#include "non_max_suppression_filter.h"   //To be added later by Keying
//#include "double_threshold_filter.h"      //To be added later by Keying
#include "hysteresis_filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
 * @brief The class for the Canny Edge Detect Filter
 *
 *  This filter conglomerates a number of other filters inorder to recreate the Canny Edge Detect algorithm.
 */
class Canny_Edge_Detect_Filter: public Filter{
    public:
        /**
         * @brief Applies a set of filters to a set of images.
         *
         *  Takes in two vectors of image pointers, the first being the inputs and the second being the outputs.
         *  The input image is run through the following filters in order before being placed in the filtered vector.
         *  1. Greyscale
         *  2. Gaussian Blur
         *  3. Sobal
         *  4. Non-Max Suppression
         *  5. Double Threshold
         *  6. Hysteresis
         */
        void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered);
};

#endif
