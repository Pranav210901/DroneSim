#ifndef IMAGEPROCESSOR_H_
#define IMAGEPROCESSOR_H_
//done by said0042:Maryan Said
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include "sharpen_filter.h"
#include "negative_filter.h"
#include "canny_edge_detect_filter.h"
#include "Color_Thresh.h"
#include "cannyEdge_Adapter.h"
/**
 * @copyright said0042:Maryan Said
 *
 */
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main facade for processing filters and detecting the robot
 *  Takes an image and determines if a robot is present in the image 
 */
class ImageProcessor {
    public:
        /**
         * @brief The constructor for the image processor and applies thresholding filter and the canny
         *detector filter and then passes the result to the check function
         * this constructor sets the found variable to the corresbonding boolean value
         *depending on what the check function return
         */
        ImageProcessor(Image);
        
         /**
         * @brief gets the value of found
         */
        bool get_found(){
        	return found;
        }
        /**
         * @brief sets the value of found
         */
        void set_found(bool x){
        	found=x;}
       /**
         * @brief Compares the pixel values for two images, the color thresholded image and the canny
         *edge result, and determines the final result of blob detection
         */         
        bool check(Image t, Image c);
    private:
    bool found;
    std::map<std::string, std::unique_ptr<Filter>> filters;
        
    
};
#endif

