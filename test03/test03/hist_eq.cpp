#include "canny.h"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;
using namespace cv;

int main()
{
	/*
	cv::Mat img = cv::imread("D:/Dep_gram/c++_project/test03/test03/7.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat dst;
	cv::equalizeHist(img,dst);
	cv::imshow("img", dst);
	cv::waitKey(0);
	cv::destroyAllWindows();
    */
	
	cv::Mat img = cv::imread("D:/Dep_gram/c++_project/test03/test03/2.jpg", 0);

	cv::Mat dst;
	cv::equalizeHist(img,dst);
	cv::imshow("dst", dst);
	cv::waitKey(0);
	
	/*
	Mat m_SrcImg;

	m_SrcImg = imread("D:/Dep_gram/c++_project/test03/test03/7.jpg", -1);

	namedWindow("src", 1);
	imshow("src", m_SrcImg);

	Mat m_ResImg;

	//直方图均衡化
	equalizeHist(m_SrcImg, m_ResImg);

	namedWindow("直方图均衡化", 1);
	imshow("直方图均衡化", m_ResImg);

	waitKey(0);
	*/
	return 0;
}