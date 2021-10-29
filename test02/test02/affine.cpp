#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	cv::Mat img = cv::imread("C:/Users/Administrator/Desktop/1.jpg");

	//cv::Mat M = (cv::Mat_<double>(2, 3) << 1, 0, 50, 0, 1, 50);
	cv::Mat M = cv::getRotationMatrix2D(cv::Point(img.cols / 2, img.rows / 2), 45, 2);
	cv::Mat dst;
	cv::warpAffine(img, dst, M, img.size());
	cv::imshow("img", dst);
	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}