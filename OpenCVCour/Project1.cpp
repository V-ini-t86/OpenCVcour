#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

Mat img;

vector<vector<int>>myColors{ {0,21,63,72,204,225} };
vector<Scalar> myColorValues{ { 255,255,0 } };
vector<vector<int>> newPoints;
Point getContours(Mat imgDil) {
	
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	Point myPoint(0,0);
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
	vector<vector<Point>> conpoly(contours.size());
	vector<Rect> boundRect(contours.size());
	for (int i = 0; i < contours.size(); i++) {

		int area = contourArea(contours[i]);
		
		string objectType;
		if (area > 1000) {
			cout << area << endl;
			float peri = arcLength(contours[i], true);

			approxPolyDP(contours[i], conpoly[i], 0.02 * peri, true);
			cout << conpoly[i].size() << endl;
			boundRect[i] = boundingRect(conpoly[i]);
			myPoint.x = boundRect[i].x + boundRect[i].width / 2;
			myPoint.y = boundRect[i].y;


			drawContours(img, conpoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			//cout << area << endl;
		}

	}
	return myPoint;
}

vector<vector<int>> findColors(Mat img) {
	
	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	for (int i = 0; i < myColors.size(); i++) {
		Scalar lower(myColors[i][0], myColors[i][1], myColors[i][2]);
		Scalar upper(myColors[i][3], myColors[i][4], myColors[i][5]);
		Mat mask;
		inRange(img, lower, upper, mask);
		Point myPoint = getContours(mask);
		imshow(to_string(i), mask);
		if (myPoint.x != 0 && myPoint.y != 0) {
			newPoints.push_back({ myPoint.x,myPoint.y,i });
		}
	}
	return newPoints;
}

void drawCanvas(vector<vector<int>> newPoints, vector<Scalar> myColorValues) {
	for (int i = 0; i < newPoints.size(); i++) {
		circle(img,Point(newPoints[i][0],newPoints[i][1]), 10, myColorValues[newPoints[i][2]], FILLED);
	}
}


int main() {
	
	VideoCapture cap(0);

	while (true) {
		cap.read(img);
		newPoints= findColors(img);
		drawCanvas(newPoints, myColorValues);
		imshow("image", img);
		waitKey(1);
	}
}