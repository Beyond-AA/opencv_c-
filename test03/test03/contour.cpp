#include "canny.h"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	/*
	cv::Mat img = cv::imread("D:/Dep_gram/c++_project/test03/test03/1.jpg");
	cv::Mat gray_img, bin_img;
	cv::cvtColor(img, gray_img, cv::COLOR_BGR2GRAY);
	cv::threshold(gray_img, bin_img, 127, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

	vector<vector<cv::Point>> contours;
	vector<cv::Vec4f> vec_4f;
	cv::findContours(bin_img, contours, vec_4f, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
	cv::drawContours(img,contours,-1,cv::Scalar(0,0,255),3);
	cv::imshow("img",img);
	cv::waitKey(0);
	cv::destroyAllWindows();
	*/

	cv::Mat img = cv::imread("D:/Dep_gram/c++_project/test03/test03/1.jpg");
	cv::Mat gray_img, bin_img;
	cv::cvtColor(img, gray_img, cv::COLOR_BGR2GRAY);
	cv::threshold(gray_img, bin_img, 127, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

	vector<vector<cv::Point>> contours;
	vector<cv::Vec4i> vec_4f;
	cv::findContours(bin_img, contours, vec_4f, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

	cv::drawContours(img, contours, -1, cv::Scalar(0, 255, 0), 2);

	cv::imshow("img_contour", img);
	cv::waitKey(0);
	return 0;
}