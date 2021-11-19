#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    Mat src = imread(argv[1], IMREAD_COLOR);
    
    if(src.empty())
        return 0;

    vector<Mat> rgb_planes;
    split(src, rgb_planes);
    
    int histogramSize = 256;
    float range[] = {0, 256};
    const float* histogramRange[] = {range};
    bool uniform = true, accumulate = false;
    
    Mat redHistogram, greenHistogram, blueHistogram;
    
    calcHist(&rgb_planes[0], 1, 0, Mat(), blueHistogram, 1, &histogramSize, histogramRange, uniform, accumulate);
    calcHist(&rgb_planes[1], 1, 0, Mat(), greenHistogram, 1, &histogramSize, histogramRange, uniform, accumulate);
    calcHist(&rgb_planes[2], 1, 0, Mat(), redHistogram, 1, &histogramSize, histogramRange, uniform, accumulate);
    
    int histogram_width = 512, histogram_height = 400;
    int bin_w = cvRound((double) histogram_width / histogramSize);
    
    Mat histogramImage(histogram_height, histogram_width, CV_8UC3, Scalar(0,0,0));
    
    normalize(blueHistogram, blueHistogram, 0, histogramImage.rows, NORM_MINMAX, -1, Mat());
    normalize(greenHistogram, greenHistogram, 0, histogramImage.rows, NORM_MINMAX, -1, Mat());
    normalize(redHistogram, redHistogram, 0, histogramImage.rows, NORM_MINMAX, -1, Mat());
    
    for(int i=1; i<histogramSize; i++){
        line(histogramImage, Point(bin_w*(i-1), histogram_height - cvRound(blueHistogram.at<float>(i-1))),
            Point(bin_w*(i), histogram_height - cvRound(blueHistogram.at<float>(i))),
            Scalar(255, 0, 0), 2, 8, 0);
        line(histogramImage, Point( bin_w*(i-1), histogram_height - cvRound(greenHistogram.at<float>(i-1))),
            Point( bin_w*(i), histogram_height - cvRound(greenHistogram.at<float>(i)) ),
            Scalar(0, 255, 0), 2, 8, 0);
        line(histogramImage, Point( bin_w*(i-1), histogram_height - cvRound(redHistogram.at<float>(i-1))),
            Point(bin_w*(i), histogram_height - cvRound(redHistogram.at<float>(i))),
            Scalar(0, 0, 255), 2, 8, 0);
    }
    
    imshow("Histogram", histogramImage );
    waitKey();

    return 0;
}