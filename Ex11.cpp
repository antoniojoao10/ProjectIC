#include <iostream>
 
#include <opencv2/highgui/highgui.hpp>  

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    cv::Mat input = cv::imread(argv[1]);
    cv::Mat output = cv::imread(argv[2]);
    Mat s1;

    absdiff(input, output, s1); 
   
    s1.convertTo(s1, CV_32F);      
    s1 = s1.mul(s1);               

    Scalar s = sum(s1);     

    double sse = s.val[0] + s.val[1] + s.val[2]; 
    double  mse = sse / (double) (input.channels() * input.total());
    double psnr = 10.0 * log10((255*255) / mse);
    cout << psnr << endl;
    
    return 0;
}