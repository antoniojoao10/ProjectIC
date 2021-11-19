#include <iostream>
#include <vector>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char* argv[]) {   
    cv::Mat input = cv::imread(argv[1]);

    int nl = input.rows;                    
    int nc = input.cols * input.channels(); 

    for (int j = 0; j < nl; j++) {
        uchar* data = input.ptr<uchar>(j);

        for (int i = 0; i < nc; i++) 
            data[i] = data[i] / 64 * 64 + 64 / 2;
    }
 
    cv::imwrite("new_image.jpg", input);   
    cv::waitKey(0);

    return 0;
}