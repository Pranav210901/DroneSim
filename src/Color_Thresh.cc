#include "Color_Thresh.h"



  void ColrorThresh::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered){
  	float error= 0.10;
  	Color orange(230.0,110.0,0.0,255.0);
  	int blop_pixels=0;
        Color l=orange-(orange*error);
        Color g=orange+(orange*error);
       *filtered[0]=*original[0];	
	for (int x = 0; x < original[0]->getWidth(); x++) {
         	 for (int y = 0; y < original[0]->getHeight(); y++) {
         	 	Color pixel= original[0]->getPixel( x,y);
         	 if (pixel.Getgreen()<=170.0&&pixel.Getgreen()>=80.0&&pixel.Getred()<=255&&pixel.Getred()>=220){
         	 		filtered[0]->setPixel(x,y, Color(255,255,255,255));
         	 		blop_pixels++;
         	 		}
         	 	else{
         	 		filtered[0]->setPixel(x,y, Color(0,0,0,255));
         	 		
         	 	}
         	 }
         }
  }
 
