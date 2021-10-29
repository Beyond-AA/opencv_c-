#include "canny.h"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	cv::Mat img = cv::imread("D:/Dep_gram/c++_project/test03/test03/5.jpg",1);
	cv::Mat dst,dst1;

	cv::GaussianBlur(img, dst, cv::Size(3, 3), 0, 0);
	cv::addWeighted(img, 0.1, dst, 0.9, 0, dst1);
	cv::imshow("img",dst1);
	cv::waitKey(0);
	cv::destroyAllWindows();


	return 0;
}