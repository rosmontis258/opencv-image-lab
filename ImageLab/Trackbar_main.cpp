#include <opencv2/opencv.hpp>
#include <iostream>
#include "Function.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    string imagePath = "D:/Projects/opencv-image-lab/assets/input/rose.jpeg";
    if (argc >= 2) {
        imagePath = argv[1];
    }
    Mat img = loadImage(imagePath);

    if (img.empty()) {
        cerr << "Failed to load image: " << imagePath << endl;
        return -1;
    }
    int option;
    while (1)
    {
        cout << "0 - Canny Trackbar" << endl;
        cout << "1 - Gaussian Trackbar" << endl;
        cout << "2 - Binary Trackbar" << endl;
        cout << "3 - Morphology Trackbar" << endl;
        cout << "4 - Exit" << endl;
        cin >> option;
        switch (option)
        {
        case 0:
            destroyAllWindows();
            cannyTrackbar(img);
            break;
        case 1:
            destroyAllWindows();
            gaussianTrackbar(img);
            break;
        case 2:
            destroyAllWindows();
            binaryTrackbar(img);
            break;
        case 3:
            destroyAllWindows();
            morphologyTrackbar(img);
            break;
        case 4:
            destroyAllWindows();
            return 0;
        default:
            destroyAllWindows();
            cout << "输入无效，请重新选择" << endl;
            break;
        }
        
    }
	return 0;
}