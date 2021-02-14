#include<iostream>
#include<opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace std;
using namespace cv;
int hmin=0, smin=0, vmin=0;
int hmax = 179, smax = 255, vmax = 255;
int main() {
	string path = "Resources/lambo.png";
	VideoCapture cap(0);
	Mat img;
	Mat mask, imgHSV;

	
	
	namedWindow("Trackers", (600, 500));
	createTrackbar("hue Min","Trackers" ,&hmin, 179);
	createTrackbar("hue Max", "Trackers", &hmax, 179);
	createTrackbar("Sat Min", "Trackers", &smin, 255);
	createTrackbar("Sat Max", "Trackers", &smax, 255);
	createTrackbar("V Min", "Trackers", &vmin, 255);
	createTrackbar("V Max", "Trackers", &vmax, 255);

	while (true) {
		cap.read(img);
		cvtColor(img, imgHSV, COLOR_BGR2HSV);
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);
		cout << hmin << " " << smin << " " << vmin << " " << hmax << " " << smax << " " << vmax << endl;

		imshow("image", img);
		imshow("HSV img", imgHSV);
		imshow("mask img", mask);
		waitKey(1);
	}


	/*imshow("hue sat image", imghsv);
	imshow("image", img);
	*/


	

}