#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class CannyTrackbarTool
{
public:
    CannyTrackbarTool(const Mat& img, const string& windowName = "CannyTrackbar")
        : src(img.clone()), windowName(windowName), thresholdValue(50) {
    }

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