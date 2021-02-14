#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;
int hmin{ 0 }, smin{ 0 }, vmin{ 0 };
int hmax{ 179 }, smax{ 255 }, vmax{ 255 };
int main() {
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgHSV,mask;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	namedWindow("Trackers", (640, 200));

	createTrackbar("Hue Min", "Trackers", &hmin,179);
	createTrackbar("Hue Max", "Trackers", &hmax, 179);
	createTrackbar("sat Min", "Trackers", &smin, 255);
	createTrackbar("sat Max", "Trackers", &smax, 255);
	createTrackbar("val Min", "Trackers", &vmin, 255);
	createTrackbar("val Max", "Trackers", &vmin, 255);
	while (true) {
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		inRange(imgHSV, lower, upper, mask);

		imshow("Normal Image", img);
		imshow("Image HSV", imgHSV);
		imshow("Image Mask", mask);
		waitKey(1);
	}
	
	return 0;
}