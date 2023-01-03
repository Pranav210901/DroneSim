#include "negative_filter.h"



void NegativeFilter::Apply(std::vector<Image*>& original, std::vector<Image*>& filtered) {
    filtered[0]->setWidth(original[0]->getWidth());
    filtered[0]->setHeight(original[0]->getHeight());
    for (int height = 0; height < original[0]->getHeight(); height++) {
        for (int width = 0; width < original[0]->getWidth(); width++) {
            Color pixel = original[0]->getPixel(width, height);
            Color inverse = Color(1 - pixel.Getred(), 1 - pixel.Getgreen(), 1 - pixel.Getblue(), pixel.Getalpha());
            filtered[0]->setPixel(width, height, inverse);
        }
    }
}