#include "contour.h"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	cv::Mat img = cv::imread("D:/Dep_gram/c++_project/test04/test04/16.jpg");
	cv::Mat gray_img, bin_img;
	cv::cvtColor(img, gray_img, cv::COLOR_BGR2GRAY);
	cv::threshold(gray_img, bin_img, 127, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

	vector<vector<cv::Point>>contours;
	vector<cv::Vec4i>vec_4f;

	cv::findContours(bin_img, contours, vec_4f, cv::RETR_TREE,cv::CHAIN_APPROX_SIMPLE);
	cout << "contours number:" << int(size(vec_4f)) << endl;
	for (int i = 0; i < (int(size(vec_4f))); i++)
	{
		double epslion = 40;//简化度
		cv::approxPolyDP(contours.at(i), contours.at(i), epslion, true);
		cv::drawContours(img, contours, -1, cv::Scalar(0, 0, 255), 2);

		cv::imshow("img"+i, img);
	}
	/*
	double epslion = 40;//简化度
	cv::approxPolyDP(contours.at(0),contours.at(0),epslion,true);
	cv::drawContours(img, contours, -1, cv::Scalar(0, 0, 255), 2);

	cv::imshow("img", img);
	*/
	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}