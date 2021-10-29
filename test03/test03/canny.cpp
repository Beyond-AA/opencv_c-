// canny.cpp: 定义应用程序的入口点。
//

#include "canny.h"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;


int main()
{

	cv::Mat img = cv::imread("C:/Users/Administrator/Desktop/2.jpg",0);
	//vector<cv::Point> contour;
	//cv::Point a;
	//cout << contour << endl;
	//cout << a << endl;
	//contour.push_back();
	//cv::Mat dst;
	cv::GaussianBlur(img,img,cv::Size(3,3),1);
	cv::Canny(img, img, 20, 60);
	cv::imshow("img",img);
	cv::waitKey();
	cv::destroyAllWindows();

	return 0;
}
