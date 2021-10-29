#include "canny.h"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	cv::Mat img = cv::imread("D:/Dep_gram/c++_project/test03/test03/2.jpg");
	cv::Mat dst,dst1;
	cv::Mat m = (cv::Mat_<int>(3, 3) << 1, 1, 0, 1, 0, -1, 0, -1, -1);
	//cv::filter2D(img, dst, -1, m);
	//cout << m << endl;

	//cv::blur(img, dst, cv::Size(3, 3));
	//cv::medianBlur(img, dst, 3);
	//cv::GaussianBlur(img,dst,cv::Size(3,3),0,0);
	//cv::bilateralFilter(img,dst,3,75,75);


	//cv::Laplacian(img,dst,-1,3);
	//cv::Sobel(img,dst,-1,1,0);
	//cv::Sobel(img, dst1, -1, 0, 1);
	cv::Scharr(img, dst, -1, 0, 1);

	//cv::namedWindow("dst", cv::WINDOW_AUTOSIZE);
	//cv::namedWindow("dst1", cv::WINDOW_AUTOSIZE);
	cv::imshow("dst",dst);
	//cv::imshow("dst1", dst1);
	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}