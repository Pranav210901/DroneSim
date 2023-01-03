#include "camera.h"


public: 
 
void Camera::TakePicture() {
//setting up the takepicture method in order to take pictures
picojson::object obj;
picojson::value val;
obj["takePicture"] = picojson::value((double)cameraId);
picojson::value v(obj);
sendJSON(v);
   controller->TakePicture(id);



    ICameraResult* Camera::ProcessingImages(int cameraId, double xPos, double yPos, double zPos, const std::vector<RawCameraImage>& images, picojson::object& details) const {
     //   if (cameraId == id || cameraId < 0) {
            // These will output the image to files.  Ultimately this is just for debugging:

            std::ofstream colorFile ("color.jpg", std::ios::out | std::ios::binary);
            colorFile.write (reinterpret_cast<const char*>(images[0].data), images[0].length);
            std::ofstream depthFile ("depth.jpg", std::ios::out | std::ios::binary);
            depthFile.write (reinterpret_cast<const char*>(images[1].data), images[1].length);
            
             int width, height, components;
             unsigned char* colorbuffer = stbi_load_from_memory(images[0].data, images[0].length, &width, &height, &component, 4);
             unsigned char* depthbuffer = stbi_load_from_memory(images[1].data, images[1].length, &width, &height, &component, 4);
             IImage* color = new Image(colorbuffer, &width, &height);
             IImage* depth = new Image(depthbuffer, &width, &height);

            //trying to create objects of type iimage class in order to access the images
            
             ImageProcessor ip;
            // ip.color_threshold(color);
            if(ip.check(color)==true){
                depth.getPixel(x,y)
                vec3 Distance = (1.0 - depth.r) * 50.0;
                vec3 Direction = (<depth.g, depth.b, depth.a> - <0.5, 0.5, 0.5>) * 2.0;
                vec3 Pixel_Location = CameraPosition + (Distance * Direction);
            }
            // robot found?  Good, let's look at the depth
            
            // lookup position in depth
            // okay, now we know where the robot is.  Let's set the value in the result

            ICameraResult* result = new CameraResult();
            result->found = true;
            result->pos[0] = xPos;
            result->pos[1] = yPos;
            result->pos[2] = zPos;
            return result;
        }
        else {

            return NULL;
    }

void Camera::ImageProcessingComplete(ICameraResult* result) {
       // CameraResult& res = *static_cast<CameraResult*>(result);
       // if (res.found) {
       //     std::cout << "The robot was found here: " << res.pos[0] << ", " << res.pos[1] << ", " << res.pos[1] << std::endl;
      //  }
      //  delete result;
    }