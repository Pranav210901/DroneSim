/**
 * @file camera.h
 * @author Pranav Pokhrel (pokhr013@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2021-12-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * Header Files required
 * 
 */

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <utility>
#include "color_thresh.h"
#include "camera_controller.h"
#include "stb_image_write.h"
#include "stb_image.h"
#include "imageio/canny_edge_detect_filter.h"
#include "imageio/composite_filter.h"
#include "imageio/iimage.h"
#include "imageio/image_helper.h"
#include "imageio/image_processor.h"
#include "imageio/color.h"


/**
 * @brief The Camera class intitializes most of the important functions of the drone's camera abilities like take picture, process images etc.
 *        It inherits from the IcameraObserver class publically
 */
class Camera : public ICameraObserver {

public:
    struct CameraResult : public ICameraResult {
        bool found;
        double pos[3];
    };
/**
 * @brief Construct a new Camera object
 * 
 * @param cameraId 
 * @param controller 
 */
    Camera(int cameraId, ICameraController* controller) : id(id), controller(controller) {
        controller->AddObserver(*this);
    }
/**
 * @brief checks for the image processor object
 * 
 * @param input 
 */
    void resultant(Image input){
         img->get_found();}
/**
 * @brief takes the picture
 * 
 */
    void TakePicture();
/**
 * @brief processes the image accordingly
 * 
 * @param cameraId 
 * @param x 
 * @param y 
 * @param z 
 * @param images 
 * @param details 
 * @return ICameraResult* 
 */
    ICameraResult* ProcessingImages(int cameraId, double x, double y, double z, const std::vector<RawCameraImage>& images, picojson::object& details) const;

/**
 * @brief the method that takes in the result from the processed images function and informs us about the whereabouts of the robot
 * 
 * @param result 
 */
    void ImageProcessingComplete(ICameraResult* result);

private:
/**
 * @brief object for the controller to the camera (takes an id)
 * 
 */
    ICameraController* controller;
/**
 * @brief unique number for the controller
 * 
 */
    int id;
/**
 * @brief image processor object needed for result
 * 
 */
 ImageProcessor* img;
};