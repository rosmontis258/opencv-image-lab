#pragma once
#include <opencv2/opencv.hpp>
#include <string>
using namespace cv;
using namespace std;
//加载图像
Mat loadImage(const string& path);

//灰度转换
Mat toGray(const Mat& img);

//高斯滤波
Mat applyGaussian(const Mat& img, int ksize = 7, double sigmaX = 5, double sigmaY = 0);

//普通二值化
Mat binaryImage(const Mat& img, double thresh = 127, double maxValue = 255);

//Otsu二值化(全图自动计算最佳阈值)
Mat otsuBinaryImage(const Mat& img);

//自适应二值化(局部区域自动计算最佳阈值)
Mat adaptiveBinaryImage(const Mat& img);

//Canny边缘检测
Mat cannyEdge(const Mat& img, double lowThreshold = 50, double highThreshold = 150);

//腐蚀
Mat erodeImage(const Mat& img, int kernelSize = 3, int iterations = 1);

//膨胀
Mat dilateImage(const Mat& img, int kernelSize = 3, int iterations = 1);

//调整图像大小
Mat reSizeImage(const Mat& img, Size newSize = Size(), double fx = 0.5, double fy = 0.5);

//开运算(先腐蚀后膨胀，去除小物体)
Mat openImage(const Mat& img, int kernelSize = 3, int iterations = 1);

//闭运算(先膨胀后腐蚀，填充小孔洞)
Mat closeImage(const Mat& img, int kernelSize = 3, int iterations = 1);

//如果图像是单通道灰度图，则转换为3通道BGR图
Mat toBgrIfNeeded(const Mat& img);

//预处理(调整大小、单通道转三通道)
Mat preCompare(const Mat& img, double fx = 0.5, double fy = 0.5);

//Canny边缘检测Trackbar工具
void cannyTrackbar(const Mat& img);