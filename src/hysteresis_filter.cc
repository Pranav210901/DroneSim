#include "hysteresis_filter.h"


HysteresisFilter::HysteresisFilter(float weak, float strong) {
	this->weak = weak;
	this->strong = strong;
}
void HysteresisFilter::Apply(std::vector<Image*>& original, std::vector<Image*>& filtered) {
	filtered[0]->setWidth(original[0]->getWidth());
	filtered[0]->setHeight(original[0]->getHeight());
	for (int height = 0; height < original[0]->getHeight(); height++) {
		for (int width = 0; width < original[0]->getWidth(); width++) {
			Color pixel = original[0]->getPixel(width, height);
			float luminance = pixel.getLuminance();
			if (luminance == weak) {
				//Flag for if a strong pixel is found next to the weak one
				bool changed = false;
				//Checks all pixels next to it for strong pixels
				for (int y = height - 1; y <= height + 1; y++) {
					for (int x = width - 1; x <= width + 1; x++) {

						//Makes sure no out of bounds pixels are checked, and that the pixel hasn't already been changed
						if (x >= 0 && y >= 0 && x <= original[0]->getWidth() && y <= original[0]->getHeight() && changed == false) {
							Color testPixel = original[0]->getPixel(x, y);
							float testLuminance = testPixel.getLuminance();
							bool test = testLuminance == strong;
							if (testLuminance == strong) {
								pixel = 255;
								filtered[0]->setPixel(width, height, pixel);
								changed == true;
							}
						}
					}
				}
				//Sets the weak pixel to zero if no strong pixels are found next to it
				if (changed == false) {
					pixel = 0;
					pixel.SetAlpha(255);
					filtered[0]->setPixel(width, height, pixel);
				}
			}
			else {
				Color truePixel = original[0]->getPixel(width, height);
				filtered[0]->setPixel(width, height, truePixel);
			}
		}
	}
}
