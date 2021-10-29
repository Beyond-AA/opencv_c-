#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	cv::Mat img1 = cv::imread("D:/Dep_gram/c++_project/test04/test04/16.jpg");
	cv::Mat img2 = cv::imread("D:/Dep_gram/c++_project/test04/test04/17.jpg");
	cv::Mat gray_img1, gray_img2, bin_img1, bin_img2;
	cv::cvtColor(img1, gray_img1, cv::COLOR_BGR2GRAY);
	cv::cvtColor(img2, gray_img2, cv::COLOR_BGR2GRAY);
	cv::threshold(gray_img1, bin_img1, 127, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
	cv::threshold(gray_img2, bin_img2, 127, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

	vector<vector<cv::Point>>contours1, contours2;
	vector<cv::Vec4i>vec_4f1, vec_4f2;
	cv::findContours(bin_img1, contours1, vec_4f1, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
	cv::findContours(bin_img2, contours2, vec_4f2, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

	cv::drawContours(img1,contours1,-1,cv::Scalar(0,0,255),2);
	cv::drawContours(img2, contours2, -1, cv::Scalar(0, 0, 255), 2);

	
	for (int i = 0; i<int(size(contours1)); i++)
	{
		double ret = cv::matchShapes(contours1[i],contours2[i],cv::CONTOURS_MATCH_I2,0.0);
		cout << ret << endl;
	}
	
	cv::namedWindow("img1",cv::WINDOW_AUTOSIZE);
	cv::namedWindow("img2", cv::WINDOW_AUTOSIZE);
	cv::imshow("img1", img1);
	cv::imshow("img2", img2);
	cv::waitKey(0);
	cv::destroyAllWindows();
}