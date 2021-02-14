#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Mat imgGray, imgBlurr, imgCanny, imgDil;
string objectType;
void getContours(Mat img,Mat imgDil) {
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

	for (int i = 0; i < contours.size(); i++) {

		int area = contourArea(contours[i]);   
		vector<vector<Point>> conpoly(contours.size());
		vector<Rect> boundRect(contours.size());
		
		if (area > 1000) {
			cout << area << endl;
			float peri = arcLength(contours[i], true);
			
			approxPolyDP(contours[i], conpoly[i], 0.02 * peri, true);
			cout << conpoly[i].size() << endl;
			boundRect[i] = boundingRect(conpoly[i]);
			

			int ObjCor = (int)conpoly[i].size();

			if (ObjCor == 3) {
				objectType = "Tri";
			}
			else if (ObjCor == 4) {
				objectType = "Rect";
			}
			else {
				objectType = "Circle";
			}

			drawContours(img, conpoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			putText(img, objectType, { boundRect[i].x,boundRect[i].y - 5 }, FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2);


			//cout << area << endl;
		}
		

	}

}

int main() {
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlurr, Size(3, 3), 0);
	Canny(imgBlurr, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	getContours(img, imgDil);
	//imshow("image canny", imgcanny);
	//imshow("image dilate", imgdil);
	//imshow("image blurr", imgblurr);
	imshow("image", img);
	waitKey(0);
}