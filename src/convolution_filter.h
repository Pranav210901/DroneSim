#ifndef CONVOLUTIONFILTER_H_
#define CONVOLUTIONFILTER_H_
//done by said0042: Maryan Said
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "filter.h"
#include "kernal.h"
/**
 * @copyright said0042:Maryan Said.
 *
 */
 
/**
 * @brief ConvolutionFilter.h is a Filter
 * This class is the base filter for convolution filters that use kernals
 */

class ConvolutionFilter : public Filter{
public: 
/**
 * @brief The conv method performs a convolution between a kernal and and image 
 * This conv function specially each MxM image matrix into an KxK kernal
 * Filters that use kernals should use this function to avoid repetition
 */
	Color conv(int w,int h, Kernal k, Image* m, Color pixel){
                for(int i=-k.getWidth()/2;i<k.getWidth()/2+1;i++){
                    for(int j=-k.getHeight()/2;j<k.getHeight()/2+1;j++){                   
                 pixel=pixel+ (m->getPixel(w+i,h+j))*(k.getKernal(i+k.getWidth()/2,j+k.getWidth()/2)); 
                }
        }
        return pixel;

    }
private:
/**
 * @brief Kernal is a member variable of the Convolution class that holds the association relation
 * between kernal and convolution filters
 */
    Kernal k2;
     };


#endif

