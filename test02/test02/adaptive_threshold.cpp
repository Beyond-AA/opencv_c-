#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	cv::Mat img = cv::imread("C:/Users/Administrator/Desktop/1.jpg",cv::IMREAD_GRAYSCALE);
	
	cv::Mat dst1, dst2, dst3;
	cv::threshold(img, dst1, 127, 255, cv::THRESH_BINARY);
	cv::adaptiveThreshold(img,dst2,255,cv::ADAPTIVE_THRESH_MEAN_C,cv::THRESH_BINARY,5,0);
	cv::adaptiveThreshold(img, dst3, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 5,20);
	
	cv::namedWindow("dst1", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("dst2", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("dst3", cv::WINDOW_AUTOSIZE);
	cv::imshow("dst1", dst1);
	cv::imshow("dst2", dst2);
	cv::imshow("dst3", dst3);
	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}