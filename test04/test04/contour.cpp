// test04.cpp: 定义应用程序的入口点。
//

#include "contour.h"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;


int main()
{
	
	cv::Mat img = cv::imread("D:/Dep_gram/c++_project/test04/test04/01.png");
	
	cv::Mat gray_img, bin_img;
	cv::cvtColor(img, gray_img, cv::COLOR_BGR2GRAY);
	cv::threshold(gray_img, bin_img, 127, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

	vector<vector<cv::Point>> contours;
	vector<cv::Vec4i> vec_4f;
	cv::findContours(bin_img, contours, vec_4f, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
	cout << contours[4] << endl;
	cout << vec_4f[4] << endl;
	cv::drawContours(img, contours, 4, cv::Scalar(0, 255, 0), 2);

	cv::imshow("img_contour", img);
	cv::waitKey(0);
	return 0;
}
