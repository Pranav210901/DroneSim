#ifndef CANNYEDGEADAPTER_H_
#define CANNYEDGEADAPTER_H_

//done by said0042: Maryan Said
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "OpenCV_Filter.h"

/**
 * @copyright said0042:Maryan Said.
 *
 */
 
/**
 * @brief CannyEdge_Adapter.h is an OpenCVFilter  
 * This filter uses the adapter pattern to implement a canny edge detecter using the opencv library 
 */
class CannyEdgeAdapter: public OpenCVFilter{
public:
/**
  * @brief This apply method takes in an original and a filtered image vectors
  *it converts the Image object original into a mat object and then converts the result from ApplyT
  *back into an image object to store the results in filtred[0] 
  */
 void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered);
 /**
  * @brief This method takes in Two Mat objects and applies the canny edge detector from the opencv library
  *then returns the result as a Mat object.
  */
  Mat ApplyT(Mat img1, Mat img2);
};
#endif
  
