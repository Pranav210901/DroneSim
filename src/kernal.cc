#include "kernal.h"  
   
  Kernal::Kernal(){
  }
  //initializes the Kernal member variables
  Kernal::Kernal(int w,int h){
        width=w;
        height=h;
        kernal= new float[w*h];

    }
  Kernal::Kernal(int w, int h, float* input){
        width=w;
        height=h;
        kernal= new float[h*w];
        for(int i=0;i<h;i++){
    	    for(int j=0;j<w;j++){
            kernal[i*h+j] = input[i*h+j];
        }
    }
  }
    //sets the elements in the kernal given an x and y index and then a float value
  void Kernal::setKernal(int x,int y,float s){
        kernal[x*width+y]=s;
    }
    //gets the kernal value for a specific index
 float Kernal::getKernal(int x,int y){
        return kernal[x*width+y];
    }
    //gets the width of the kernal
   int Kernal::getWidth(){
 	return width;
 }
 //gets the height value of the kernal
  int Kernal::getHeight(){
  	return height;
  }
  //sets the width of the kernal
  void  Kernal::setWidth(int w){
  	width=w;
  }
  //sets the height of the kernak
  void  Kernal::setHeight(int h){
  	height=h;
  }
    
    
