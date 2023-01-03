#include "cannyEdge_Adapter.h"
  
  Mat CannyEdgeAdapter::ApplyT(Mat img1, Mat img2){
  	cv::Mat imgGrayscale;        // grayscale of input image
    	cv::Mat imgBlurred;            
    	cv::cvtColor(img1, imgGrayscale, cv::COLOR_BGR2GRAY);        // convert to grayscale
    	cv::GaussianBlur(imgGrayscale,            
        imgBlurred,                           
        cv::Size(5, 5),                        
        1.5);                                
    	cv::Canny(imgBlurred,           
        img2,                   
        25,                        // low threshold
        255);                        // high threshold
        cv::imwrite("openc_canny.png",img2);
        return img2;  
  }

void CannyEdgeAdapter::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered){
	Mat origin(original[0]->getWidth(),original[0]->getHeight(),CV_8UC3);
	for (int width=0; width<origin.rows; width++) {
		cv::Vec3b* ptr=origin.ptr<cv::Vec3b>(width);
             	for (int height=0; height<origin.cols; height++) {
            		Color pixel = original[0]->getPixel(width, height);
            		ptr[height]=cv::Vec3b(pixel.Getred(),pixel.Getgreen(),pixel.Getblue());
              }
       }
       Mat originT;
       cv::transpose(origin,originT);
       *filtered[0]=*original[0];
        Mat filter(originT.rows,originT.cols,CV_8UC3);                    	 	
	filter=ApplyT(originT,filter);
	Mat n=filter.clone();
	for(int w=0; w<n.rows; w++) {
            	cv::Vec3b* ptr1=n.ptr<cv::Vec3b>(w);
       	 for(int h=0;h<n.cols;h++){
       	   filtered[0]->setPixel(h,w, Color((ptr1[h][0]),(ptr1[h][1]),(ptr1[h][2]),255));
       	 }
      }
    
}
  
