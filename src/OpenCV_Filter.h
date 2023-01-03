#ifndef OPENCVFILTER_H_
#define OPENCVFILTER_H_
//done by said0042: Maryan Said
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/types.hpp>
using namespace cv;
#include "filter.h"

/**
 * @copyright said0042:Maryan Said.
 *
 */
 
/**
 * @brief OpenCV_Filter.h is a filter
 * This filter is used by any other filter that will be  using the opencv library
 */
class OpenCVFilter: public Filter{
public:

/**
  * @brief This apply method takes in an original and a filtered image vectors
  *it converts the Image object original into a mat object and then converts the result from ApplyT
  *back into an image object to store the results in filtred[0] 
  */
	void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered){}
	/**
  * @brief This method takes in Two Mat objects and applies the canny edge detector from the opencv library
  *then returns the result as a Mat object.
  */
	 Mat ApplyT(Mat img1, Mat img2){};
};
#endif	
