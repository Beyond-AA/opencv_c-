#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main()
{

	cv::Mat img = cv::imread("C:/Users/Administrator/Desktop/1.jpg");
	cv::Mat gray_img;
	cv::cvtColor(img,gray_img,cv::COLOR_BGR2GRAY);

	cv::Mat bin_img;
	cv::threshold(gray_img, bin_img, 0., 255., cv::THRESH_BINARY | cv::THRESH_OTSU);

	cv::Mat bin_img1;
	cv::threshold(gray_img, bin_img1, 127, 255, cv::THRESH_BINARY);

	cv::namedWindow("gray_img",cv::WINDOW_AUTOSIZE);
	cv::namedWindow("gray_img1", cv::WINDOW_AUTOSIZE);
	cv::imshow("gray_img", bin_img);
	cv::imshow("gray_img1", bin_img1);
	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}