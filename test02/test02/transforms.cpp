#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main() 
{
	cv::Mat img = cv::imread("C:/Users/Administrator/Desktop/1.jpg");
	cv::Mat dst1, dst2;
	//cv::transpose(img, dst);
	/*cv::flip(img, dst1, -1);
	cv::flip(img, dst2, 1);*/
	//cv::transform(img,dst1);


	cv::namedWindow("dst1", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("dst2", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("dst3", cv::WINDOW_AUTOSIZE);
	cv::imshow("dst1", img);
	cv::imshow("dst2", dst1);
	cv::imshow("dst3", dst2);
	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}