#ifndef COLOR_H_
#define COLOR_H_
/**
 * @copyright holm0715: Jaron Holm.
 *
 */
/**
 * @brief The Color class, used to represent pixel colors in images
 * It is a basic class used to store the values for red, green blue and alpha
 */

struct Color {
    /**
      * @brief Color constructor, takes in values as floats for red, green blue and alpha
      */
    Color(float r,float g,float b,float a);
    /**
      * @brief Color deconstructor
      */
    ~Color();
    /**
      * @brief Color assignment overrider, sets RGBA values to same color
      */
    Color operator=(float value);
    /**
      * @return Color addition overider, returns a color plus the RGB values of another color
      */
   	Color operator+(Color c);
   	Color operator-(Color c);
	Color operator*(float c);
    
    /**
      * @return Color Divison overider, returns a color whose RGB valuses are all divided by a float
      */
    Color operator/(float divisor);
    /**
      * @return Color Divison overider, returns a color whose RGB valuses are all multiplied by a float
      */
 
    /**
      * @return float value for red
      */
    float Getred();
    /**
      * @return float value for green 
      */
    float Getgreen();
    /**
      * @return float value for blue 
      */
    float Getblue();
    /**
      * @return float value for alpha 
      */
    float Getalpha();
    /**
      * @brief sets float value of red 
      */
    void SetRed(float New);
    /**
      * @brief sets float value of green 
      */
    void SetGreen(float New);
    /**
      * @brief sets float value of blue 
      */
    void SetBlue(float New);
    /**
      * @brief sets float value of alpha 
      */
    void SetAlpha(float New);
    /**
      * @return new Color that has a min and max value for RGBA, if its value is lower then min it is set to min,
      * if it is higher than max it is set to max
      */
    Color clamp(float min, float max);
    /**
      * @return float the is the Lumiances value, caluculated using given equation 0.2126*red + 0.7152*green + 0.0722*blue
      */
    float getLuminance();

private:
    float red;
    float green;
    float blue;
    float alpha;
};

#endif

