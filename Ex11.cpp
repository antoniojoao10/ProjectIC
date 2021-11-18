#include <iostream>
#include <string>   
#include <iomanip> 
#include <sstream>  

#include <opencv2/core/core.hpp>       
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/highgui/highgui.hpp>  

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    ifstream iFile;
    ofstream oFile;

    Mat s1;
    absdiff(iFile, oFile, s1);    
    s1.convertTo(s1, CV_32F);      
    s1 = s1.mul(s1);               

    Scalar s = sum(s1);     

    double sse = s.val[0] + s.val[1] + s.val[2]; 

    if (sse <= 1e-10)
        return 0;
    else {
        double  mse =sse /(double)(iFile.channels() * iFile.total());
        double psnr = 10.0*log10((255*255)/mse);
        cout << psnr << endl;
    }

    return 0;
}