#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;

/************ Draw Shapes and Text****************/

void main() {
	//Blank Image
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));	
	// circle image of radius less wider
	circle(img, Point(256, 256), 100, Scalar(0, 69, 255));
	imshow("Blank image", img);
	// circle image of radius have high width
	/*circle(img, Point(256, 256), 100, Scalar(0, 69, 255),10);
	imshow("Circle image", img);*/
	// circle is filled
	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);
	imshow("Circle image", img);
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), 3);
	imshow("Rectangle", img);
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);
	imshow("Line image", img);
	//text
	putText(img, "Vinit Joshi", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(255, 255, 255), 4);
	imshow("Text", img);
	
	waitKey(0);
}