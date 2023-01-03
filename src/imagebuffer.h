/**
 * @file imagebuffer.h
 * @author Pranav Pokhrel
 * @brief 
 * @version 0.1
 * @date 2021-12-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef IMAGE_BUFFER
#define IMAGE_BUFFER

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <utility>
#include "Color_Thresh.h"
#include "camera_controller.h"
#include "stb_image_write.h"
#include "stb_image.h"
#include "imageio/canny_edge_detect.h"
#include "imageio/composite_filter.h"
#include "imageio/iimage.h"
#include "imageio/image_helper.h"
#include "imageio/image_processor.h"
#include "imageio/color.h"
/**
 * @brief class to create a buffer in order to add a step for conversion (in order to make it easier to use filters)
 * 
 */
class ImageBuffer {

    public:
    /**
     * @brief Construct a new Image Buffer object
     * 
     */
    //    ImageBuffer(){}
    /**
     * @brief Destroy the Image Buffer object
     * 
     */
    //    ~ImageBuffer(){}
    /**
     * @brief technically to use the processimages method and overload it to work according to our color and depth (search and rescue)
     * 
     * @param color 
     * @param depth 
     * @return ICameraResult* 
     */
    //    ICameraResult* ProcessImages(IImage*, IImage*);
    
    private:
    /**
     * @brief additional variables/objects needed for the process images method
     * 
     */
        const std::vector<RawCameraImage> images[2];
        picojson::object details[];

};
#endif