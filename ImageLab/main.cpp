#include <opencv2/opencv.hpp>
#include <iostream>
#include "Base_function.h"

using namespace cv;
using namespace std;

int main() {
    Mat img = loadImage("D:/Projects/opencv-image-lab/assets/input/rose.jpeg");
    Mat imgToGray = toGray(img);
    Mat imgGaussian = applyGaussian(img);
    Mat imgBianry = binaryImage(img);
    Mat imgOtsu = otsuBinaryImage(img);
    Mat imgAdaptive = adaptiveBinaryImage(img);
    Mat imgCanny = cannyEdge(img);
    Mat imgOpen = openImage(img);
    Mat imgClose = closeImage(img);
    Mat row1, row2, row3, compareImage;
    hconcat(vector<Mat>{imgToGray, imgGaussian, imgBianry}, row1);
    hconcat(vector<Mat>{imgOtsu, imgAdaptive, imgCanny}, row2);
    hconcat(vector<Mat>{imgOpen, imgClose}, row3);
    vconcat(vector<Mat>{row1, row2, row3}, compareImage);
    imshow("compare", compareImage);
    waitKey(0);
    return 0;
}