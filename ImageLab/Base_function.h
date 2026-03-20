#pragma once
#include <opencv2/opencv.hpp>
#include <string>
using namespace cv;
using namespace std;
Mat loadImage(const string& path);
Mat toGray(const Mat& img);
Mat applyGaussian(const Mat& img, int ksize = 7, double sigmaX = 5, double sigmaY = 0);
Mat binaryImage(const Mat& img, double thresh = 127, double maxValue = 255);
Mat cannyEdge(const Mat& img, double lowThreshold = 50, double highThreshold = 150);
Mat erodeImage(const Mat& img, int kernelSize = 3, int iterations = 1);
Mat dilateImage(const Mat& img, int kernelSize = 3, int iterations = 1);
Mat reSizeImage(const Mat& img, Size newSize, double fx = 0, double fy = 0);