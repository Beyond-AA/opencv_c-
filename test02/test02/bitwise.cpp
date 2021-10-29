#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	cv::Mat img(1024, 1024, CV_8UC3, cv::Scalar(0, 0, 0));
	cv::Mat mask(img.rows,img.cols,CV_8UC3,cv::Scalar(0,0,255));
	cv::Rect r(mask.cols * 0.25, mask.rows * 0.4, 400, 100);
	cv::rectangle(mask,r,cv::Scalar(255,255,255),-1);
	//cout << mask.size() << endl;

	cv::Mat out;
	cv::bitwise_and(img, mask, out);
	cv::namedWindow("img", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("out", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("mask", cv::WINDOW_AUTOSIZE);
	cv::imshow("img", img);
	cv::imshow("mask", mask);
	cv::imshow("out",out);
	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}