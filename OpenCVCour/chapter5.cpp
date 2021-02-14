#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
using namespace std;
/// /////////////////////////////// WARP IMAGES ///////////////////////
float w = 250, h = 350;
Mat matrix, imgWarp;
Mat matrix1, imgWarp1;
Mat matrix2, imgWarp2;
int main() {
	string path = "Resources/cards.jpg";
	Mat img = imread(path);
	Point2f src[4] = { {525,140},{770,188},{403,398},{679,456} };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f}, {0.0f,h},{w,h} };
	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));
	
	Point2f src1[4] = { {65,324},{335,276},{90,633},{401,571} };
	Point2f dst1[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };
	matrix1 = getPerspectiveTransform(src1, dst1);
	warpPerspective(img, imgWarp1, matrix1, Point(w, h));

	Point2f src2[4] = { {740,380},{1024,435},{646,707},{967,784} };
	Point2f dst2[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };
	matrix2 = getPerspectiveTransform(src2, dst2);
	warpPerspective(img, imgWarp2, matrix2, Point(w, h));

	imshow("Queen", imgWarp1);
	imshow("diamonds", imgWarp2);
	imshow("Cards",img);
	imshow("King", imgWarp);
	waitKey(0);
}