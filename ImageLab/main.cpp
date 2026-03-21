#include <opencv2/opencv.hpp>
#include <iostream>
#include "Base_function.h"

using namespace cv;
using namespace std;

int main() {
    Mat img = loadImage("D:/Projects/opencv-image-lab/assets/input/rose.jpeg");
    Mat imgAdaptive = adaptiveBinaryImage(img);
    Mat imgOtsu = otsuBinaryImage(img);
    double fx = 0.5, fy = 0.5;
    Mat imgResize1 = reSizeImage(imgAdaptive, Size(0, 0), fx, fy);
    Mat imgResize2 = reSizeImage(imgOtsu, Size(0, 0), fx, fy);
    imshow("adaptiveBinaryImage", imgResize1);
    imshow("otsuBinaryImage", imgResize2);
    waitKey(0);
    return 0;
}