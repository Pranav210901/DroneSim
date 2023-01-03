#ifndef GAUSSIANBLUR_H_
#define GAUSSIANBLUR_H_
//done by said0042: Maryan Said
/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "convolution_filter.h"

/**
 * @copyright said0042:Maryan Said.
 *
 */
 
/**
 * @brief GaussianBlur.h is a ConvolutionFilter 
 * This filter blurs an image by convolving a kernel (Gaussian kernel) with an image 
 */
class GaussianBlur: public ConvolutionFilter {
public:
/**
  * @brief This apply method takes in an original and a filtered image vectors
  *It applies the gaussian blur by convolving a kernal to the first image in original image and then stores the 
  * new image in the first imgage of filtred image vector
  */		
	void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered);
	
	};
	
#endif
