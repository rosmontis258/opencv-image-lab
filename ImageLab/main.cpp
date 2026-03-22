#include <opencv2/opencv.hpp>
#include <iostream>
#include "Base_function.h"

using namespace cv;
using namespace std;

int main() {
    Mat img = loadImage("D:/Projects/opencv-image-lab/assets/input/rose.jpeg");
    Mat imgOrigin = preCompare(img, 0.3, 0.3);
    Mat imgToGray = preCompare(toGray(img), 0.3, 0.3);
    Mat imgGaussian = preCompare(applyGaussian(img), 0.3, 0.3);
    Mat imgBianry = preCompare(binaryImage(img), 0.3, 0.3);
    Mat imgOtsu = preCompare(otsuBinaryImage(img), 0.3, 0.3);
    Mat imgAdaptive = preCompare(adaptiveBinaryImage(img), 0.3, 0.3);
    Mat imgCanny = preCompare(cannyEdge(img), 0.3, 0.3);
    Mat imgOpen = preCompare(openImage(img), 0.3, 0.3);
    Mat imgClose = preCompare(closeImage(img), 0.3, 0.3);
    Mat row1, row2, row3, compareImage;
    hconcat(vector<Mat>{imgToGray, imgGaussian, imgBianry}, row1);
    hconcat(vector<Mat>{imgOtsu, imgAdaptive, imgCanny}, row2);
    hconcat(vector<Mat>{imgOpen, imgClose, imgOrigin}, row3);
    vconcat(vector<Mat>{row1, row2, row3}, compareImage);
    imshow("compare", compareImage);
    waitKey(0);
    return 0;
}