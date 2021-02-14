#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur,imgCanny,imgDial,imgErode;
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(9, 9), 5, 0);
	Canny(img, imgCanny, 10, 110);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(2, 2));
	dilate(imgCanny, imgDial, kernel);
	erode(imgDial, imgErode, kernel);
	imshow("image gray", imgGray);
	imshow("Normal image", img);
	imshow("Blurr Image", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image dilate", imgDial);
	imshow("Image Erode", imgErode);
	waitKey(0);
	

}