#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main() 
{
	//cout << "hello world" << endl;
	//system("pause");
	//return 0;
	//cv::line(img, cv::Point(20, 20),cv::Point(100,100), cv::Scalar(0, 0, 255), 3);
	//cv::rectangle(img,cv::Point(100,100),cv::Point(500,500), cv::Scalar(255, 0, 0), 5);
	
	cv::Mat img(600, 600, CV_8UC3, cv::Scalar(0, 0, 0));
	vector<cv::Point> contour;
	contour.push_back(cv::Point(10,5));
	contour.push_back(cv::Point(50, 10));
	contour.push_back(cv::Point(70, 20));
	contour.push_back(cv::Point(20, 30));
	cv::polylines(img, contour, true, cv::Scalar(0, 255, 0), 3);
	

	cv::imshow("img", img);
	cv::waitKey(0);
	cv::destroyAllWindows();
	/*
	cv::Mat img(600, 600, CV_8U, cv::Scalar(0));
	cv::Point points[2][4];
	//cout << points << endl;
	points[0][0] = cv::Point(100, 115);
	points[0][1] = cv::Point(255, 135);
	points[0][2] = cv::Point(140, 365);
	points[0][3] = cv::Point(100, 300);
	points[1][0] = cv::Point(300, 315);
	points[1][1] = cv::Point(555, 335);
	points[1][2] = cv::Point(340, 565);
	points[1][3] = cv::Point(300, 500);
	//cout << points[1][1] << endl;
	//cout << points[0] << endl;
	//cout << points[1] << endl;
	//cout << points << endl;
	const cv::Point* pts[] = { points[0],points[1] };
	//for (int i = 0; i < 4; i++)
	//{
	//	for (int j = 0; j < 4; j++)
	//	{
	//		cout << *pts[i][j] << endl;
	//	}
	//}
	//cout << **pts << endl;
	//cout << pts[1][1] << endl;
	//cout << pts << endl;
	int npts[] = { 4,4 };
	cv::polylines(img, pts, npts, 2, true, cv::Scalar(255), 5, 8, 0);
	//cv::polylines(img, points[0], true, cv::Scalar(0, 0, 255), 3, cv::LINE_AA);
	cv::namedWindow("Poly");
	cv::imshow("Poly", img);
	cv::waitKey(0);
*/


//»æÖÆ¶à±ßÐÎ
	
	//cv::Mat img = cv::imread("C:/Users/Administrator/Desktop/Beyond.jpg");
	/*
	cv::Mat img(600, 600, CV_8UC3, cv::Scalar(0, 0, 255));
	vector<cv::Point> contour;
	contour.push_back(cv::Point(10, 5));
	contour.push_back(cv::Point(50, 10));
	contour.push_back(cv::Point(70, 20));
	contour.push_back(cv::Point(20, 30));
	cv::polylines(img, contour, true, cv::Scalar(255, 0, 0), 2, cv::LINE_AA);
	cv::imshow("img",img);
	cv::waitKey(0);*/
	return 0;

}