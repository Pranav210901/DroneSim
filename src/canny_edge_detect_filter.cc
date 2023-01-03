#include "canny_edge_detect_filter.h"

void Canny_Edge_Detect_Filter::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) {
    std::map<std::string, std::unique_ptr<Filter>> filters;
    filters["greyscale"] = std::unique_ptr<Filter>(new GreyScaleFilter());
    filters["gaussian"] = std::unique_ptr<Filter>(new GaussianBlur());
    filters["sobal"] = std::unique_ptr<Filter>(new SobalFilter()); 
    //filters["suppression"] = std::unique_ptr<Filter>(new NonMaxSuppression());    //To be added later by Keying
    //filters["double threshold"] = std::unique_ptr<Filter>(new DoubleThreshold()); //To be added later by Keying
    filters["hysteresis"] = std::unique_ptr<Filter>(new HysteresisFilter(25,255));

    std::vector<Image*> intermediary_input;
    std::vector<Image*> intermediary_output;

    // Greyscale
    intermediary_input.insert(intermediary_input.begin(), original[0]);
    Image greyscale;
    intermediary_output.insert(intermediary_output.begin(), &greyscale);
    filters["greyscale"]->Apply(intermediary_input, intermediary_output);

    // Gaussian
    intermediary_input.insert(intermediary_input.begin(), intermediary_output[0]);
    Image gaussian;
    intermediary_output.insert(intermediary_output.begin(), &gaussian);
    filters["gaussian"]->Apply(intermediary_input, intermediary_output);

    // Sobal
    intermediary_input.insert(intermediary_input.begin(), intermediary_output[0]);
    Image sobal;
    intermediary_output.insert(intermediary_output.begin(), &sobal);
    filters["sobal"]->Apply(intermediary_input, intermediary_output);

    /*  //To be added later by Keying
    // Suppression
    intermediary_input.insert(intermediary_input.begin(), intermediary_output[0]);
    Image suppression;
    intermediary_output.insert(intermediary_output.begin(), &suppression);
    filters["suppression"]->Apply(intermediary_input, intermediary_output);

    // Double threshold
    intermediary_input.insert(intermediary_input.begin(), intermediary_output[0]);
    Image double_threshold;
    intermediary_output.insert(intermediary_output.begin(), &double_threshold);
    filters["double threshold"]->Apply(intermediary_input, intermediary_output);
    */

    // Hysteresis
    intermediary_input.insert(intermediary_input.begin(), intermediary_output[0]);
    filters["hysteresis"]->Apply(intermediary_input, filtered);
}
