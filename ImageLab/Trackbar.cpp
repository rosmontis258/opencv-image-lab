#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//Canny边缘检测Trackbar工具类
class CannyTrackbarTool
{
public:
    CannyTrackbarTool(const Mat& img, const string& windowName = "CannyTrackbar")
        : src(img.clone()), windowName(windowName), thresholdValue(50) {}

    void run()
    {
        namedWindow(windowName, WINDOW_AUTOSIZE);
        createTrackbar("Threshold", windowName, &thresholdValue, 255, onTrackbar, this);
        update();
        waitKey(0);
    }

private:
    Mat src;
    string windowName;
    int thresholdValue;

    void update()
    {
        Mat gray, cannyOutput;
        cvtColor(src, gray, COLOR_BGR2GRAY);
        Canny(gray, cannyOutput, thresholdValue, thresholdValue * 2);
        imshow(windowName, cannyOutput);
    }

    static void onTrackbar(int, void* userdata)
    {
        CannyTrackbarTool* self = static_cast<CannyTrackbarTool*>(userdata);
        self->update();
    }
};

void cannyTrackbar(const Mat& img)
{
    CannyTrackbarTool tool(img);
    tool.run();
}

//Gaussian高斯滤波Trackbar工具类
class GaussianTrackbarTool
{
public:
    GaussianTrackbarTool(const Mat& img, const string& windowName = "GaussianTrackbar")
        :src(img.clone()), windowName(windowName), value(0), sigmaX(0), sigmaY(0) { }
    void run()
    {
        namedWindow(windowName, WINDOW_AUTOSIZE);
        createTrackbar("kernel size", windowName, &value, 15, onTrackbar, this);
        createTrackbar("sigmaX", windowName, &sigmaX, 50, onTrackbar, this);
        createTrackbar("sigmaY", windowName, &sigmaY, 50, onTrackbar, this);
        update();
        waitKey(0);
    }
private:
    Mat src;
    string windowName;
    int value;
    int sigmaX, sigmaY;

    void update()
    {
        Mat gaussianOutput;
        int ksize = value * 2 + 1;
        double realSigmaX = sigmaX / 10.0;
        double realSigmaY = sigmaY / 10.0;
        GaussianBlur(src, gaussianOutput, Size(ksize, ksize), realSigmaX, realSigmaY);
        imshow(windowName, gaussianOutput);
    }

    static void onTrackbar(int, void* userdata)
    {
        GaussianTrackbarTool* self = static_cast<GaussianTrackbarTool*>(userdata);
        self->update();
    }
};

void gaussianTrackbar(const Mat& img)
{
    GaussianTrackbarTool tool(img);
    tool.run();
}