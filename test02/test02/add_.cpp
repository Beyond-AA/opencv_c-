#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main() 
{
	cv::Mat x = (cv::Mat_<uchar>(2, 1) << 250, 34);
	cv::Mat y = (cv::Mat_<uchar>(2, 1) << 10, 100);
	//cout << x << endl;
	cv::Mat addrst, subrst;
	cv::add(x, y,addrst);
	cv::subtract(x, y, subrst);
	cout << addrst << endl;
	cout << subrst << endl;
	return 0;

}