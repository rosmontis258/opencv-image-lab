#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//加载图片
Mat loadImage(const string& path)
{
    string imagePath = "D:/Projects/opencv-image-lab/assets/input/rose.jpeg";
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

//二值化
Mat Binary(const Mat& img, double thresh = 127, double maxValue = 255)
{
    Mat imgBinary;
    Mat imgGray = toGray(img);
    Mat imgBlur = applyGaussian(imgGray);
    threshold(imgBlur, imgBinary, thresh, maxValue, THRESH_BINARY);
    return imgBinary;
}

//Canny边缘检测
Mat CannyEdge(const Mat& img, double lowThreshold = 50, double highThreshold = 150)
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
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    erode(img, imgErode, kernelSize, Point(-1, -1), iterations);
    return imgErode;
}

//膨胀
Mat DilateImage(const Mat& img, int kernelSize = 3, int iterations = 1)
{
    Mat imgDilate;
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(img, imgDilate, kernel, Point(-1, -1), iterations);
    return imgDilate;
}