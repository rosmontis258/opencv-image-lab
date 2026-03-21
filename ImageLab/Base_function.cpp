#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//加载图片
Mat loadImage(const string& path)
{
    string imagePath = path;
    Mat img = imread(imagePath);
    if (img.empty()) {
        cout << "图片读取失败" << endl;
    }
    return img;
}

//灰度转换
Mat toGray(const Mat& img)
{
    Mat imgGray;
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    return imgGray;
}

//高斯滤波
Mat applyGaussian(const Mat& img, int ksize = 7, double sigmaX = 5, double sigmaY = 0)
{
    Mat imgBlur;
    GaussianBlur(img, imgBlur, Size(ksize, ksize)/*高斯核*/, sigmaX/*横向模糊程度*/, sigmaY/*纵向模糊程度*/);
    return imgBlur;
}

//普通二值化
Mat binaryImage(const Mat& img, double thresh = 127, double maxValue = 255)
{
    Mat imgBinary;
    Mat imgGray = toGray(img);
    Mat imgBlur = applyGaussian(imgGray);
    threshold(imgBlur, imgBinary, thresh, maxValue, THRESH_BINARY);
    return imgBinary;
}

//Otsu二值化(全图自动计算最佳阈值)
Mat otsuBinaryImage(const Mat& img)
{
    Mat imgOtsuBinary;
    Mat imgGray = toGray(img);
    Mat imgBlur = applyGaussian(imgGray);
    threshold(imgBlur, imgOtsuBinary, 0, 255, THRESH_BINARY | THRESH_OTSU);
    return imgOtsuBinary;
}

//自适应二值化(局部区域自动计算最佳阈值)
Mat adaptiveBinaryImage(const Mat& img)
{
    Mat imgAdaptiveBinary;
    Mat imgGray = toGray(img);
    Mat imgBlur = applyGaussian(imgGray);
    
    CV_Assert(!img.empty());
    CV_Assert(imgGray.type() == CV_8UC1);
    CV_Assert(imgBlur.type() == CV_8UC1);

    adaptiveThreshold(imgBlur, imgAdaptiveBinary, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 2);
    return imgAdaptiveBinary;
}

//Canny边缘检测
Mat cannyEdge(const Mat& img, double lowThreshold = 50, double highThreshold = 150)
{
    Mat imgCanny;
    Mat imgGray = toGray(img);
    Mat imgBlur = applyGaussian(imgGray);
    Canny(imgBlur, imgCanny, lowThreshold, highThreshold);
    return imgCanny;
}

//腐蚀
Mat erodeImage(const Mat& img, int kernelSize = 3, int iterations = 1)
{
    Mat imgErode;
    erode(img, imgErode, kernelSize, Point(-1, -1), iterations);
    return imgErode;
}

//膨胀
Mat dilateImage(const Mat& img, int kernelSize = 3, int iterations = 1)
{
    Mat imgDilate;
    dilate(img, imgDilate, kernelSize, Point(-1, -1), iterations);
    return imgDilate;
}

//调整图像大小
Mat reSizeImage(const Mat& img, Size newSize, double fx = 0, double fy = 0)
{
    Mat imgResized;
    resize(img, imgResized, newSize, fx, fy);
    return imgResized;
}