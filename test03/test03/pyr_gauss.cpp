#include "canny.h"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main() {
	cv::Mat img = cv::imread("D:/Dep_gram/c++_project/test03/test03/1.jpg");
	for (int i = 0; i < 3; i++)
	{
	cv::imshow("img" + i, img);
	//cv::pyrDown(img, img);
	cv::pyrUp(img, img);
	}
	cv::waitKey(0);
	return 0;
}