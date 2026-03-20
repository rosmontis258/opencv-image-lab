#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    //读取图片
    string imagePath = "D:/Projects/opencv-image-lab/assets/input/rose.jpeg";
    Mat img = imread(imagePath);
    if (img.empty()) {
        cout << "图片读取失败" << endl;
        return -1;
    }
    imshow("origin", img);
    waitKey(6000);

    //灰度转换
    Mat imgGray;
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    imshow("Gray", imgGray);
    waitKey(6000);

    //高斯滤波
    Mat imgBlur;
    GaussianBlur(img, imgBlur, Size(7, 7)/*高斯核*/, 5/*横向模糊程度*/, 0/*纵向模糊程度*/);
    imshow("Blur", imgBlur);
    waitKey(6000);

    //普通二值化
    Mat imgBinary;
    threshold(imgGray, imgBinary, 127, 255, THRESH_BINARY);
    imshow("Binary", imgBinary);
    waitKey(6000);

    //Canny边缘检测
    Mat imgCanny;
    Canny(imgGray, imgCanny, 50, 150);
    imshow("Canny", imgCanny);
    waitKey(6000);

    //腐蚀和膨胀
    Mat imgErode, imgDilate;
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));//矩形核
    erode(imgBinary, imgErode, kernel, Point(-1, -1), 1);//核中心，迭代次数
    dilate(imgBinary, imgDilate, kernel, Point(-1, -1), 1);
    imshow("Erode", imgErode);
    imshow("Dilate", imgDilate);
    waitKey(6000);
    return 0;
}