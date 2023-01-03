#include "greyscale_filter.h"

void GreyScaleFilter::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) {
    filtered[0]->setWidth(original[0]->getWidth());
    filtered[0]->setHeight(original[0]->getHeight());
    for (int height=0; height<original[0]->getHeight(); height++) {
        for (int width=0; width<original[0]->getWidth(); width++) {
            Color pixel = original[0]->getPixel(width, height);
            float luminance = pixel.getLuminance();
            filtered[0]->setPixel(width, height, Color(luminance,luminance,luminance,255));
        }
    }
}

