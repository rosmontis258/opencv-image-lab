#include <opencv2/opencv.hpp>
#include <iostream>
#include "Function.h"

using namespace cv;
using namespace std;

//Canny边缘检测Trackbar工具类
class CannyTrackbarTool
{
public:
    CannyTrackbarTool(const Mat& img, const string& windowName = "CannyTrackbar")
        : src(img.clone()), windowName(windowName), lowThresholdValue(0), highThresholdValue(0) {}

    void run()
    {
        namedWindow(windowName, WINDOW_AUTOSIZE);
        createTrackbar("lowThreshold", windowName, &lowThresholdValue, 255, onTrackbar, this);
        createTrackbar("highThreshold", windowName, &highThresholdValue, 255, onTrackbar, this);
        update();
        waitKey(0);
    }

private:
    Mat src;
    string windowName;
    int lowThresholdValue, highThresholdValue;

    void update()
    {
        Mat imgGray = toGray(src), imgBlur = applyGaussian(imgGray), cannyOutput;
        Canny(imgBlur, cannyOutput, lowThresholdValue, highThresholdValue);
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

//Threshold二值化TrackBar工具类
class ThresholdTrackBarTool
{
public:
    ThresholdTrackBarTool(const Mat& img, const string& windowName = "BinaryTrackbar")
        :src(img.clone()), windowName(windowName), thresh(0){
    }
    void run()
    {
        namedWindow(windowName, WINDOW_AUTOSIZE);
        createTrackbar("thresh", windowName, &thresh, 255, onTrackbar, this);
        update();
        waitKey(0);
    }
private:
    Mat src;
    string windowName;
    int thresh;

    void update()
    {
        Mat binaryOutput;
        Mat imgGray = toGray(src);
        threshold(imgGray, binaryOutput, thresh, 255, THRESH_BINARY);
        imshow(windowName, binaryOutput);
    }

    static void onTrackbar(int, void* userdata)
    {
        ThresholdTrackBarTool* self = static_cast<ThresholdTrackBarTool*>(userdata);
        self->update();
    }
};

void binaryTrackbar(const Mat& img)
{
    ThresholdTrackBarTool tool(img);
    tool.run();
}

//Morphology形态学Trackbar工具类
class MorphologyTrackbarTool
{
public:
    MorphologyTrackbarTool(const Mat& img, const string& windowName = "MorphologyTrackbar")
        :src(img.clone()), windowName(windowName), value(0), iterations(0), option(0), srcBinary(otsuBinaryImage(src)) {
    }
    void run()
    {
        namedWindow(windowName, WINDOW_AUTOSIZE);
        createTrackbar("Current Op", windowName, &option, 3, onTrackbar, this);
        createTrackbar("Kernel Size", windowName, &value, 15, onTrackbar, this);
        createTrackbar("Iterations", windowName, &iterations, 10, onTrackbar, this);
        update();
        waitKey(0);
    }
private:
    Mat src;
    Mat srcBinary;
    string windowName;
    int value;
    int iterations;
    int option;

    void update()
    {
        Mat morphologyOutput;
        int kernelSize = value * 2 + 1;
        Mat kernel = getStructuringElement(MORPH_RECT, Size(kernelSize, kernelSize));
        switch (option)
        {
        case 0:
            erode(srcBinary, morphologyOutput, kernel, Point(-1, -1), iterations);
            break;
        case 1:
            dilate(srcBinary, morphologyOutput, kernel, Point(-1, -1), iterations);
            break;
        case 2:
            morphologyEx(srcBinary, morphologyOutput, MORPH_OPEN, kernel, Point(-1, -1), iterations);
            break;
        case 3:
            morphologyEx(srcBinary, morphologyOutput, MORPH_CLOSE, kernel, Point(-1, -1), iterations);
            break;
        }
        imshow(windowName, morphologyOutput);
    }

    static void onTrackbar(int, void* userdata)
    {
        MorphologyTrackbarTool* self = static_cast<MorphologyTrackbarTool*>(userdata);
        self->update();
    }
};

void morphologyTrackbar(const Mat& img)
{
    MorphologyTrackbarTool tool(img);
    tool.run();
}