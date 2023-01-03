#include "gausian_blur_filter.h"
#include <iostream>
#include <math.h>


//It applies the gaussian blur by convolving a kernal to the first image in original image and then stores the 
   //new image in the first imgage of filtred image vector    
void GaussianBlur::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) {
  	float sigma=1.0;
  	float  normal = 1 / (2.0 * 3.141592653589793 * sigma*sigma);
	Kernal r(5,5);
	float nValue=0;
	//generates the kernal values
	for(int l=0;l<r.getWidth();l++){
		for(int b=0;b<r.getHeight();b++){
        		float x=pow(l-(r.getWidth()-1)/2,2);
        		float y=pow(b-(r.getHeight()-1)/2,2); 
        		nValue=normal*exp(-((x+y)/ (2.0*sigma*sigma)));
        		r.setKernal(l,b,nValue);
               }
      }

    *filtered[0]=*original[0];
    //gets each pixel of the image and sets it after convolution
    for(int w=0; w<original[0]->getWidth(); w++) {
        for(int h=0;h<original[0]->getHeight();h++){
        	Color pixel(0,0,0,255);
        	pixel= conv(w,h,r,original[0],pixel);
                pixel.clamp(0,255);                                                                 
                filtered[0]->setPixel(w,h,pixel);         
            }
            
        }
    }
