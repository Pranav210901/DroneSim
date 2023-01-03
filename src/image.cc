
#include <iostream>
#include <string>
#include "image.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Needed for writing images
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using namespace std;
 Image::Image() {
    width = 1;
    height = 1;
    components = 4;
    image = new unsigned char[width*height*components];
}
Image::Image(int width, int height) {
    this->width = width;
    this->height = height;
    components = 4;

    image = new unsigned char[width*height*components];
}


Color Image::getPixel(int x, int y) {
  if (x < 0) {x =0;}
  if (y < 0) {y =0;}
  if (x > width) {x =width;}
  if (y > height) {y =height;}
    Color temp(image[(y*width + x)*4 + 0],
                image[(y*width + x)*4 + 1],
                image[(y*width + x)*4 + 2],
                image[(y*width + x)*4 + 3]);
    return temp;
}
void Image::setPixel(int x, int y, Color pixel) {
    // Accounting for unsigned char overflow.
    if (pixel.Getred() > 255) image[(y*width + x)*4 + 0] = 255;
    else image[(y*width + x)*4 + 0] = static_cast<unsigned char>(pixel.Getred());

    if (pixel.Getgreen()> 255) image[(y*width + x)*4 + 1] = 255;
    else image[(y*width + x)*4 + 1] = static_cast<unsigned char>(pixel.Getgreen());

    if (pixel.Getblue() > 255) image[(y*width + x)*4 + 2] = 255;
    else image[(y*width + x)*4 + 2] =static_cast<unsigned char>(pixel.Getblue());

    if (pixel.Getalpha() > 255) image[(y*width + x)*4 + 3] = 255;
    else image[(y*width + x)*4 + 3] = static_cast<unsigned char>(pixel.Getalpha());
}
    

 Image::~Image() {
    delete[] image;
}
Image::Image(std::string filename) {
	unsigned char *loadedImage = stbi_load(filename.c_str(), &width, &height, &components, STBI_rgb_alpha);
    components = 4;
    image = new unsigned char[width*height*components];
	std::copy(loadedImage, loadedImage + width*height*components, image);
    stbi_image_free(loadedImage);
}

     void Image::saveAs(std::string fileName) {
    stbi_write_png(fileName.c_str(), width, height, components, image, width*4);
}
 
int Image::getHeight() {return height;}
int Image::getWidth() {return width;}
void Image::setHeight(int height) {
    this->height = height;
    delete[] image;
    image = new unsigned char[width*height*components];
}
void Image::setWidth(int width) {
    this->width = width;
    delete[] image;
    image = new unsigned char[width*height*components];
}
int Image::getComponentNum() {return components;}
 
           
    float Image::getPixelFloat(int x, int y) const {
    if (x < 0) {x =0;}
  if (y < 0) {y =0;}
  if (x > width) {x =width;}
  if (y > height) {y =height;} 
    unsigned char* pixel = &image[(x + width*y)*4]; 
         return *reinterpret_cast<float*>(pixel);
     }

void Image::setPixelFloat(int x, int y, float value){
  unsigned char* pixel = &image[(x + width*y)*4];
    *reinterpret_cast<float*>(pixel) = value; }
    

