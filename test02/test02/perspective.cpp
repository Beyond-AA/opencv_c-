#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;


int main()
{
	//cv::Mat img = cv::imread("C:/Users/Administrator/Desktop/1.jpg");


	cv::Point2f pts1[] = { cv::Point2f(25, 30), cv::Point2f(179, 25), cv::Point2f(12, 188), cv::Point2f(189, 190) };
	cv::Point2f pts2[] = { cv::Point2f(0, 0), cv::Point2f(200, 0), cv::Point2f(0, 200), cv::Point2f(200, 200) };

	cv::Mat M = cv::getPerspectiveTransform(pts1, pts2);
	cout << *pts1 << endl;
	return 0;
}