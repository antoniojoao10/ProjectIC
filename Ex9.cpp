#include <iostream>
#include <vector>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

inline uchar reduceVal(const uchar val) {
    if (val < 64) 
        return 0;
    
    if (val < 128) 
        return 64;
    
    return 255;
}

int main(int argc, char* argv[]) {   
    cv::Mat input = cv::imread(argv[1]);

    uchar* pixels = input.data;
    
    for (int i = 0; i < input.rows; i++) {
        for (int j = 0; j < input.cols; j++) {
            const int p = i * input.cols * 3 + j * 3;
    
            pixels[p + 2] = reduceVal(pixels[p + 2]); // Red
            pixels[p + 1] = reduceVal(pixels[p + 1]); // Green
            pixels[p + 0] = reduceVal(pixels[p + 0]); // Blue
        }
    }

    cv::imwrite("new_image.ppm", input);   
    cv::waitKey(0);

    return 0;
}