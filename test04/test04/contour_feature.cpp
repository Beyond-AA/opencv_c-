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
	cv::threshold(gray_img, bin_img, 125, 155, cv::THRESH_BINARY | cv::THRESH_OTSU);

	vector<vector<cv::Point>>contours;
	vector<cv::Vec4i> vec_4f;
	cv::findContours(bin_img, contours, vec_4f, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
	cout << "contours numbers:" << int(size(vec_4f)) << endl;
	for (int i = 0; i<int(size(vec_4f)); i++)
	{
		
		cv::Moments M = cv::moments(contours[i]);

		//重心
		int cx = M.m10 / M.m00;
		int cy = M.m01 / M.m00;
		cout << "Fcous:" << cx << "" << cy << endl;
		//面积
		double area = cv::contourArea(contours[i]);
		cout << "area:" << area << endl;
		//周长
		double len = cv::arcLength(contours[i], true);
		cout << "len:" << len << endl;

		cv::drawContours(img, contours, i, cv::Scalar(0, 0, 255), 2);
		cv::imshow("img" + i, img);

	}
	cv::waitKey(0);
	/*
	cv::Moments M = cv::moments(contours[0]);

	//重心
	int cx = M.m10 / M.m00;
	int cy = M.m01 / M.m00;
	cout << "Fcous:" << cx << "" << cy << endl;
	//面积
	double area = cv::contourArea(contours[0]);
	cout << "area:" << area << endl;
	//周长
	double len = cv::arcLength(contours[0], true);
	cout << "len:" << len << endl;

	cv::drawContours(img, contours, -1, cv::Scalar(0, 0, 255), 2);

	cv::imshow("img",img);
	cv::waitKey();
	cv::destroyAllWindows();
*/
	return 0;
}