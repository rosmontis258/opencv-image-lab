#include <opencv2/opencv.hpp>
#include <iostream>
#include "Base_function.h"

using namespace cv;
using namespace std;

int main() {
    Mat img = loadImage("D:/Projects/opencv-image-lab/assets/input/rose.jpeg");
    Mat imgCanny = cannyEdge(img);
    double fx = 0.5, fy = 0.5;
    Mat imgResize = reSizeImage(imgCanny, Size(0, 0), fx = 0.5, fy = 0.5);
    imshow("Canny", imgResize);
    waitKey(0);
    return 0;
}