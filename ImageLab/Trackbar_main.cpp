#include <opencv2/opencv.hpp>
#include <iostream>
#include "Function.h"

using namespace cv;
using namespace std;

int main()
{
	Mat img = loadImage("D:/Projects/opencv-image-lab/assets/input/rose.jpeg");
	cannyTrackbar(img);
	return 0;
}