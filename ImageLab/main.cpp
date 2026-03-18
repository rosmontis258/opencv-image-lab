#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat img = imread("D:/Projects/opencv-image-lab/assets/input/test01.jpg");
    if (img.empty()) {
        cout << "图片读取失败" << endl;
        return -1;
    }

    imshow("test01", img);
    waitKey(0);
    return 0;
}