#ifndef IMAGE_H_
#define IMAGE_H_ 

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "color.h" 
#include <string> 
#include <iostream>
/**
 * @copyright tran0607:Ethan Tran.
 *
 */

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for representing images.
 *
 *  Images defined by this class are represented by a 3-dimensional unsigned-char array consisting of
 *  the pixel width, pixel height, and the number of components representing a pixel.
 */
class Image{  
  public:
    /**
     * @brief The default image constructor.
     *
     *  Image is set to a blank 1 by 1 pixel image. Components default to 4.
     */
    Image();
    /**
     * @brief An image constructor taking width and height inputs.
     *
     *  Image is set to a blank width by height pixel image. Components default to 4.
     */
    Image(int width, int height);
    /**
     * @brief An image constructor taking a filename as input.
     *
     *  Image loads an image, from the path given by the filename string, to the image array.
     *  Width and height are set based on loaded image width and height.
     */
    Image(std::string filename);
    /**
     * @brief An copy constructor for image.
     *
     *  Deletes the old image array, setting this whole image object to the passed in image object.
     */
    Image(const Image& m){
      if (this->image) delete[] this->image;
      image=NULL;
      *this=m;
    }
    /**
     * @brief An assignment operator for image.
     *
     *  Deletes the old image array, setting all private variables of this image object to be equal
     *  to the private variables of the passed in image object.
     */
    void operator=(const Image& m) {
      if (this->image){
        delete[] this->image;
      }
      this->width = m.width;
      this->height = m.height;
      this->image = new unsigned char[width*height*components];
      std::copy(m.image, m.image + width*height*components, this->image);
    }
    /**
     * @brief The deconstructor.
     *
     *  Deletes all dynamically allocated memory.
     */
    ~Image();
    /**
     * @brief Saves the current image array as a real image file.
     *
     *  The image file name and location will be set to the passed in string.
     */
    void saveAs(std::string filename);
    /**
     * @brief Gets the image height.
     *
     * @return A integer for the image height.
     */
    int getHeight();
    /**
     * @brief Gets the image width.
     *
     * @return A integer for the image width.
     */
    int getWidth();
    /**
     * @brief sets the image height.
     *
     *  Sets the image height to the passed in integer value.
     */
    void setHeight(int height);
    /**
     * @brief sets the image width.
     *
     *  Sets the image width to the passed in integer value.
     */
    void setWidth(int width);
    /**
     * @brief Gets the number of components that represent a single pixel.
     *
     * @return A integer for the number of components that represent a single pixel.
     */
    int getComponentNum();
    /**
     * @brief Gets the pixel at a specific position on the image.
     *
     *  Takes in two integers, representing the x and y position for the desired pixel.
     *
     * @return A Color representing the pixel on the image.
     */
    Color getPixel(int x, int y);
    /**
     * @brief Sets the pixel at a specific position on the image.
     *
     *  Takes in two integers and a Color. The integers represent the x and y position for the desired pixel.
     *  While the Color represents the desired color values to set the pixel to.
     */
    void setPixel(int x, int y, Color pixel);
    /**
     * @brief Sets the pixel at a specific position on the image.
     *
     *  Takes in two integers and a float. The integers represent the x and y position for the desired pixel.
     *  While the float represents the desired color values to set the pixel to.
     */
    void setPixelFloat(int x, int y, float value);
    /**
     * @brief Gets the pixel at a specific position on the image.
     *
     *  Takes in two integers, representing the x and y position for the desired pixel.
     *
     * @return A float representing the pixel on the image.
     */
    float getPixelFloat(int x, int y) const;
    
    private:
      /**
       * @brief An unsigned char pointer/array that represents the image as a whole.
       *
       *  The size itself is the product of the width, height, and components of the image.
       */
      unsigned char* image;
      /**
       * @brief An integer representing the width pixel width of the image.
       */
      int width;
      /**
       * @brief An integer representing the width pixel height of the image.
       */
      int height;
      /**
       * @brief An integer for the number of components used to represent a pixel.
       */
      int components=4;
        
 };
 #endif
