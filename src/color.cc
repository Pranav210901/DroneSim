#include "color.h"

 Color::Color(float r,float g,float b,float a){
    red=r;
    green=g;
    blue=b;
    alpha=a;
 }
Color::~Color() {}

Color Color::operator=(float value) {
    red = value;
    green = value;
    blue = value;
    alpha = value;
    return *this;
}
Color Color:: operator+(Color c){
	return Color( red+c.red,green+c.green, blue+c.blue, alpha+c.alpha);
 }

Color Color:: operator-(Color c){
	return Color( red-c.red,green-c.green, blue-c.blue, alpha-c.alpha);
 }


Color Color::operator/(float divisor) {
    red = red / divisor;
    green = green / divisor;
    blue = blue / divisor;
    alpha = alpha / divisor;
    return *this;
}

Color Color:: operator*(float v){
 	return Color( v*red,v*green, v*blue, v*alpha);
 	}

float Color::getLuminance() {
    return 0.2126*red + 0.7152*green + 0.0722*blue;}
  
 float Color::Getred(){
    return red;
    
 }
  float Color::Getgreen(){
    return green;
    
 }
 
  float Color::Getblue(){
    return blue;
    
 }
  float Color::Getalpha(){
    return alpha;
    
 }
 void Color::SetRed(float New){
    red=New;
 }  
  void Color::SetGreen(float New){
    green=New;
  }
  void Color::SetBlue(float New){
    blue=New;   
  }
 
 void Color::SetAlpha(float New){
    alpha=New;
 }
  Color Color::clamp(float min,float max){
      if(alpha<min){
         alpha=min;
}
if(alpha>max){alpha=max;}
if(red<min){ red=min;}
   if (green<min){green=min;}
   if (blue<min){blue=min;}
   if(red>max){ red=max;}
   if (green>max){green=max;}
   if (blue>max){blue=max;}
      
   }

