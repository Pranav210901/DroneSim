#ifndef KERNAL_H_
#define KERNAL_H_
//done by said0042: Maryan Said
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "image.h"
/**
 * @copyright said0042:Maryan Said.
 *
 */
 
 
/**
 * @brief The kernal class consist of a float pointer which is considered a metrix width and height
 * The convolutionFilter class uses the kernal class to convole images with kernals
 */

class Kernal {
public:

/**
  * @brief  default constructor

  */
    Kernal();
/**
  * @brief initializes the Kernal member variables

  */
    Kernal(int w,int h);
/**
  * @brief initializes the Kernal using a 2D-float-array

  */
    Kernal(int w, int h, float* input);    
/**
  * @brief destructor to prevent memory leaks

  */
    ~Kernal(){
        delete[] kernal;
    }
/**
  * @brief copies kernals savetly

  */
    Kernal(const Kernal& k){
        kernal=NULL;
        *this=k;
    }
/**
  * @brief an equal operator for the kernal

  */
    Kernal& operator=(const Kernal& k){
        this->width=k.width;
        this->height=k.height;
        delete[] this->kernal;
        this->kernal=new float[(this->width*this->height)];
        for(int i=0;i<(this->width*this->height);i++){
            this->kernal[i]=k.kernal[i];
        }
        return *this;
    }
/**
  * @brief sets the elements in the kernal given an x and y index and then a float value

  */
    void setKernal(int x,int y,float s);
/**
  * @brief gets the kernal value for a specific index

  */
    float getKernal(int x,int y);
/**
  * @brief gets the width of the kernal

  */
    int getWidth();
/**
  * @brief gets the height of the kernal

  */
    int getHeight();
/**
  * @brief sets the width of the kernal

  */
    void  setWidth(int w);
/**
  * @brief sets the height of the kernal

  */
    void  setHeight(int h);
    


        
private:
 float* kernal;
 int width;
 int height;
};

#endif
