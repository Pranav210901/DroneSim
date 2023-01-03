/*! \page Image_processing Image Processing
 *
 *  Image_Processing.h
 *
 * @copyright said0042:Maryan Said.
 *
 *
 * A brief description of the image processor subsystem: 
 * 
 * Our image processor subsystem takes in an image and checks if a robot is present in the picture or not; 
 * the Image_processing class is the facade of the image processing subsytem and it uses the opencv library
 *to implement a canny edge detector.
 * A link to the the UML for the image processing subsystem is provided in bottem of this page labeled as Image_Processing UML.
 * As is it shown in the UML, the Image_processing class has a filter class that conducts the actual filtering
 * of images. The filter class is the base class for all filter classes and all filters inherit from it.
 * Our system for now has only one subclass that inherits from filter and that is the simple_filter class. 


 
 * As shown in the image processing uml below, the simple_filter class has two 
 * subclasses that inherit from it, an OpenCV_Filter and a Color_Thresh filter.
 * The Color_Thresh filter is used to detect the presence of orange pixels in an image. 
 * The OpenCV_Filter uses the adapter pattern and is used by any filter that uses the OpenCV library to implement
 * filters. All children classes for this class will have one more apply method that converts Mat Objects into
 * image objects.
 * Lastly, at the end of the filter hierarchy in the UML is the CannyEdge_Adapter filter class that is an 
 * OpenCV_Filter, the CannyEdge_Adapter uses the OpenCV library to implement a canny edge detector filter. 
 
 
 *Extension:
 * For extending the system, a new type of filter other than simple can always be added under the filter class 
 * next to the simple_filter in the uml diagram.
 * Also, more OpenCV filters can be added as children of the OpenCV_Filter class if that was ever necessary.
 
 * Moreover, a filter uses an image class to represent and load images which then uses a color class to represent each pixel of the image
 * as a four float type rgb values. 
 * The relationship that  image processor has with image and color is also shown in the image processing UML below.
 * The Image_processing class uses the results of the Color_Thresh filter and the CannyEdge_Adapter for blob-
 * detection through its check function, which compares the pixel value results from those two filters to 
 * determine  whether a robot is present in the image or not. The image processor sets the result of the check 
 * function to its  member variable found and any new image processor objects with an image passed to can determine 
 * whether a robot is present in the image or not. As shown in the image processer UML, The camere class has an 
 * image processor and the result of the image processor is used there.
 
 *Image_Processing UML:  <a href="https://lucid.app/lucidchart/b22f3cca-380f-48e2-ae0f-b9f865e1190c/edit?viewport_loc=-205%2C-436%2C2198%2C1097%2C0_0&invitationId=inv_b7570875-e0c9-423a-acd8-e10b0ac6e1a3">Image_ProcessingUML </a> 
 */
