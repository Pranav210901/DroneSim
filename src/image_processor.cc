#include "image_processor.h"
#include <limits>

  ImageProcessor::ImageProcessor(Image img1) {
 	std::vector<Image*> inputs;
        std::vector<Image*> outputs;
        std::vector<Image*> extra;
        std::vector<Image*> extra2;
	Image thresh;
	Image canny;
	inputs.push_back(&img1);	   
        outputs.push_back(&thresh);
	std::string filter_type1= "thresh";
	filters[filter_type1]= std::unique_ptr<Filter>(new ColrorThresh());
	filters[filter_type1]->Apply(inputs, outputs);
	thresh.saveAs("t.png");
	extra.push_back(&thresh);
	extra2.push_back(&canny);
	std::string filter_type2= "canny";
	filters[filter_type2]= std::unique_ptr<Filter>(new CannyEdgeAdapter());
	filters[filter_type2]->Apply(extra, extra2);
	canny.saveAs("c.png");
	found=check(thresh,canny);
	//found =ans;
  }
  bool ImageProcessor::check(Image t,Image c){
	int a = std::numeric_limits<int>::max();
	int plob_num=0;
        int edge_num=0;
	for (int x = 0; x< t.getWidth(); x++) {
         	 for (int y = 0; y < t.getHeight(); y++) {
         	 	Color pixel= t.getPixel( x,y);
                     if (pixel.Getred()==255&&pixel.Getgreen()==255&&pixel.Getblue()==255){
         	 		plob_num++;		
         	        }
                }
       }
       for (int x = 0; x< c.getWidth(); x++) {
         	 for (int y = 0; y < c.getHeight(); y++) {
         	 	Color pixel= c.getPixel( x,y);
       	 	if (pixel.Getred()==255&&pixel.Getgreen()==255&&pixel.Getblue()==255){
         	 		edge_num++;		
         	        }
                }
       }
       bool ans=false;
       float div=0;
       //accounting for infinity
	if (edge_num!=0){
      		div= (float(plob_num)/float(edge_num));
      	}       	
       if (div>=5){
       	ans=true;
       }
       else{
       ans=false;
       }
	return ans;
}





















