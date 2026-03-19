#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    //读取图片
    string imagePath = "D:/Projects/opencv-image-lab/assets/input/rosmontis1.jpg";
    Mat img = imread(imagePath);
    if (img.empty()) {
        cout << "图片读取失败" << endl;
        return -1;
    }
    imshow("test01", img);
    waitKey(6000);

    //灰度转换
    Mat imgGray;
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    imshow("test02", imgGray);
    waitKey(6000);

    //高斯滤波
    Mat imgBlur;
    GaussianBlur(img, imgBlur, Size(7, 7)/*高斯核*/, 5/*横向模糊程度*/, 0/*纵向模糊程度*/);
    imshow("test03", imgBlur);
    waitKey(6000);

    //普通二值化
    Mat imgBinary;
    threshold(imgGray, imgBinary, 127, 255, THRESH_BINARY);
    imshow("test04", imgBinary);
    waitKey(6000);

    //Canny边缘检测
    Mat imgCanny;
    Canny(imgGray, imgCanny, 50, 150);
    imshow("test05", imgCanny);
    waitKey(6000);
    return 0;
}