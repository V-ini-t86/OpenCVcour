#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;

/*********************     Resize and Crop        *************************/


void main() {
	string path = "Resources/test.png";

	Mat img = imread(path);
	//cout << img.size() << endl;
	Mat reSize,imgCrop;
	resize(img, reSize, Size(),0.5,0.5);
	Rect roi(100, 100, 300, 450);
	imgCrop = img(roi);
	imshow("image", img);
	imshow("image Resize", reSize);
	imshow("image Crop", imgCrop);
	waitKey(0);

}